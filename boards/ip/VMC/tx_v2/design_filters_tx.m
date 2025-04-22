%% Script to design interpolating filter chain and equivalent decimator in transmitter

clear all;
close all;

%% System parameters

Rb = 1000;      % Bit rate is 1kbps (low rate for visualisation purposes)
Rs = Rb/2;      % QPSK, so 2 bits per symbol

R_RRC = 4;      % Rate change undertaken by RRC filter
R_HB = 2;       % Rate change undertaken by Halfband filter(s)
R_CICcomp = 2;  % Rate change undertaken by CIC compensator
R_CIC = 3200;      % Rate change undertaken by CIC filter
R_OV = R_RRC * R_HB * R_CICcomp * R_CIC;

R_IPI = 5;
R_IPI2 = 4;
R_RFDAC = 8;    % Rate change to be undertaken by RF-DAC (after output)

R_spec = 2^3;

% sampling rates at OUTPUTs of the filter sections

fRRC = Rs * R_RRC;
fHB  = fRRC * R_HB;
fCICcomp = fHB * R_CICcomp;
fCIC = fCICcomp * R_CIC;
fIPI = fCIC * R_IPI;
fSPEC = fIPI/R_spec;
fIPI2 = fIPI * R_IPI2;
fRFDAC = fIPI2 * R_RFDAC;

fprintf(['Output sampling frequency (post-CIC) = ', num2str(fCIC/1e6), 'MHz. \r\n']);
fprintf(['Output sampling frequency (post-RF-DAC) = ', num2str(fRFDAC/1e6), 'MHz. \r\n']);
fprintf(['Output sampling frequency (post-spec-HB-chain) = ', num2str(fSPEC/1e6), 'MHz. \r\n']);

%% Design Pulse shaping filter (Root Raised Cosine)
% This filter will interpolate by factor R_RRC (defined above).

RRC_rolloff     = 0.25;                 % RRC rolloff factor
RRC_span        = 12;                   % Span in symbol periods

% Create an object containing the filter specs for the RRC... 
%dRRC = fdesign.pulseshaping(R_RRC,'Square Root Raised Cosine','N,Beta',RRC_order,RRC_rolloff);

hRRC = comm.RaisedCosineTransmitFilter(...
    'Shape',                  'Square root', ...
    'RolloffFactor',          RRC_rolloff, ...
    'FilterSpanInSymbols',    RRC_span, ...
    'OutputSamplesPerSymbol', R_RRC);

% Extract the weights from the filter object 
% (can then refer to as WRRC.Numerator in System Generator).
WRRC = coeffs(hRRC);

% create a DSP system toolbox version to permit cascading of responses
hdRRC = dsp.FIRInterpolator(R_RRC,WRRC.Numerator);

% Use a scaling factor to compensate for WRRC gain - allows filter response
% to be seen in FVTool with 0dB gain at 0Hz (removes scaling effect of interpolation). 
% Create an FIR with one weight equal to the scaling factor
K_RRC = dsp.FIRFilter('Numerator', 1/sqrt(R_RRC));      % 1 weight filter

% Visualise response
RRC_Tx = cascade(K_RRC,hdRRC);
fvRRC = fvtool(RRC_Tx);

%% Design a Halfband filter
% Halfband interpolates by factor of 2 (always). 

HB_Tw = 0.2;    % Normalised transition bandwidth
HB_Ast = 80;    % Attenuation in the stopband

% design a halfband filter response with parameters specified above
dHB = fdesign.halfband('Tw,Ast', HB_Tw, HB_Ast);
hHB = design(dHB,'equiripple');

HB = dsp.FIRInterpolator(R_HB, hHB.numerator);

%fv(4) = 
fvtool(HB);


%% CIC interpolator - final stage (CIC compensator comes first - see next)

% These parameters must be altered to match CIC filter being compensated - 
% need to check against the parameters set in the System Generator block. 

N_CIC = 5;      % Number of CIC stages
D_CIC = 1;      % Differential delay

CIC = dsp.CICInterpolator(R_CIC, D_CIC, N_CIC, 'FixedPointDataType', 'Full precision');

% Use a scaling factor to compensate for CIC gain - create an FIR with one
% weight equal to the scaling factor
K = 1/(R_CIC^N_CIC);                        % gain compensation value
K_CIC = dsp.FIRFilter('Numerator', K);      % 1 weight filter (gain K)

% Visualise as scaled filter response
CICsc = cascade(K_CIC,CIC);                 % casade scaling and CIC
fvtool(CICsc);

% For System Generator design... scale by arithmetic shift and fine gain if
% not a power of 2 interpolation / decimation ratio
CIC_right_shift = log2(R_CIC^N_CIC);
CIC_left_shift = log2(R_CIC);

CIC_shift_Tx = floor(CIC_right_shift - CIC_left_shift);
CIC_shift_Rx = floor(CIC_right_shift);

CIC_fine_Tx = 2^-(CIC_right_shift - CIC_left_shift - CIC_shift_Tx);
CIC_fine_Rx = 2^(-(CIC_right_shift-CIC_shift_Rx));

%% CIC compensator - precedes final stage CIC filter (derives some parameters from it so appears last).

% CIC compensator is generated as system object 'CICcomp' for analysis / 
% FVtool plotting using 'dsp.CICCompensationInterpolator'

CICcomp = dsp.CICCompensationInterpolator(CIC,'InterpolationFactor',2, ...
    'PassbandFrequency',0.3*fCICcomp, 'StopbandFrequency',0.4*fCICcomp, ...
    'StopbandAttenuation',80, 'PassbandRipple',0.1, 'SampleRate',fCICcomp);

% Use a scaling factor to compensate for CIC compensator gain - create an FIR with one
% weight equal to the scaling factor

V = 1/R_CICcomp;                                % gain compensation value
K_CICcomp = dsp.FIRFilter('Numerator', V);      % 1 weight filter (gain V)

CICcompsc = cascade(K_CICcomp,CICcomp);         % casade scaling and CICcomp

% Access coefficient values for use in System Generator.
WComp = coeffs(CICcomp);
%hdCICcomp = design(fdesign.ciccomp(D_CIC, N_CIC,0.3*fCICcomp/2,0.4*fCICcomp/2,0.1,80,fCICcomp),'SystemObject',true);

% Visualise response
fvc = fvtool(CICcompsc);%, WComp.Numerator);
%% Design additional IP interpolator
% the original x5 IPI interpolator extracted from Vivado

Ap = 2;                                 
Ast = 40;                               
Rp = (10^(Ap/20) - 1)/(10^(Ap/20) + 1); 
Rst = 10^(-Ast/20);                     

IPItx = dsp.FIRFilter([-0.022406403381708004,-0.04601348505451235,-0.04571148260226924,-0.00894199371574465,0.030576596828620555,0.026616656511643785,-0.01525599274205929,-0.03372569851901567,0.006989917525156605,0.05391609472090984,0.025731835161325215,-0.061194110212675575,-0.07627482901512517,0.0759512321930129,0.31171064206024807,0.426500837477317,0.31171064206024807,0.0759512321930129,-0.07627482901512517,-0.061194110212675575,0.025731835161325215,0.05391609472090984,0.006989917525156605,-0.03372569851901567,-0.01525599274205929,0.026616656511643785,0.030576596828620555,-0.00894199371574465,-0.04571148260226924,-0.04601348505451235,-0.022406403381708004]);
IPI2txw = firgr('minorder', [0 (fIPI/(fIPI2)) (fIPI/(fIPI2))*1.15 1], [1 1 0 0], [Rp Rst]);
IPI2tx = dsp.FIRFilter(IPI2txw);

fvtool(IPItx,"Fs", fIPI)
fvtool(IPI2tx,"Fs",fIPI2)

%% Design additional IP Decimator
% the original x5 IPI decimator extracted from Vivado

Ap = 0.1;
Ast = 60;
Rp = (10^(Ap/20) - 1)/(10^(Ap/20) + 1);
Rst = 10^(-Ast/20);

IPI2rxw = firgr('minorder', [0 (fIPI/(fIPI2)) (fIPI/(fIPI2))*1.2 1], [1 1 0 0], [Rp Rst]);
IPI2rx = dsp.FIRFilter(IPI2rxw);

IPIrx = dsp.FIRFilter([0.000000000000000,0.000334572125978,0.000544017123724,0.000522441431073,0.000240278267880,-0.000223779650047,-0.000685041173635,-0.000907841223530,-0.000709286416705,-0.000073807958764,0.000784067110132,0.001464985642156,0.001549220097694,0.000823458902944,-0.000541928350420,-0.001981104094791,-0.002738848576995,-0.002235766176576,-0.000428470470073,0.002036616111696,0.004009353651230,0.004337629320872,0.002482009521849,-0.001064117021164,-0.004814975617696,-0.006866276702417,-0.005805770430360,-0.001547801659521,0.004358928855801,0.009210184803343,0.010311512524452,0.006359034341166,-0.001628754335595,-0.010381454784459,-0.015594720754498,-0.013893872246607,-0.004704947021658,0.008900610930255,0.020980773482568,0.025035778148769,0.017043212478671,-0.002058969751056,-0.025653057844456,-0.043081361482323,-0.043287941093966,-0.019203945040852,0.028832362915462,0.092097819935811,0.155559990649596,0.202442440345737,0.219705082318609,0.202442440345737,0.155559990649596,0.092097819935811,0.028832362915462,-0.019203945040852,-0.043287941093966,-0.043081361482323,-0.025653057844456,-0.002058969751056,0.017043212478671,0.025035778148769,0.020980773482568,0.008900610930255,-0.004704947021658,-0.013893872246607,-0.015594720754498,-0.010381454784459,-0.001628754335595,0.006359034341166,0.010311512524452,0.009210184803343,0.004358928855801,-0.001547801659521,-0.005805770430360,-0.006866276702417,-0.004814975617696,-0.001064117021164,0.002482009521849,0.004337629320872,0.004009353651230,0.002036616111696,-0.000428470470073,-0.002235766176576,-0.002738848576995,-0.001981104094791,-0.000541928350420,0.000823458902944,0.001549220097694,0.001464985642156,0.000784067110132,-0.000073807958764,-0.000709286416705,-0.000907841223530,-0.000685041173635,-0.000223779650047,0.000240278267880,0.000522441431073,0.000544017123724,0.000334572125978,0.000000000000000]);
%IPIrx1 = dsp.FIRFilter([0.000000000000000,0.000334572125978,0.000544017123724,0.000522441431073,0.000240278267880,-0.000223779650047,-0.000685041173635,-0.000907841223530,-0.000709286416705,-0.000073807958764,0.000784067110132,0.001464985642156,0.001549220097694,0.000823458902944,-0.000541928350420,-0.001981104094791,-0.002738848576995,-0.002235766176576,-0.000428470470073,0.002036616111696,0.004009353651230,0.004337629320872,0.002482009521849,-0.001064117021164,-0.004814975617696,-0.006866276702417,-0.005805770430360,-0.001547801659521,0.004358928855801,0.009210184803343,0.010311512524452,0.006359034341166,-0.001628754335595,-0.010381454784459,-0.015594720754498,-0.013893872246607,-0.004704947021658,0.008900610930255,0.020980773482568,0.025035778148769,0.017043212478671,-0.002058969751056,-0.025653057844456,-0.043081361482323,-0.043287941093966,-0.019203945040852,0.028832362915462,0.092097819935811,0.155559990649596,0.202442440345737,0.219705082318609,0.202442440345737,0.155559990649596,0.092097819935811,0.028832362915462,-0.019203945040852,-0.043287941093966,-0.043081361482323,-0.025653057844456,-0.002058969751056,0.017043212478671,0.025035778148769,0.020980773482568,0.008900610930255,-0.004704947021658,-0.013893872246607,-0.015594720754498,-0.010381454784459,-0.001628754335595,0.006359034341166,0.010311512524452,0.009210184803343,0.004358928855801,-0.001547801659521,-0.005805770430360,-0.006866276702417,-0.004814975617696,-0.001064117021164,0.002482009521849,0.004337629320872,0.004009353651230,0.002036616111696,-0.000428470470073,-0.002235766176576,-0.002738848576995,-0.001981104094791,-0.000541928350420,0.000823458902944,0.001549220097694,0.001464985642156,0.000784067110132,-0.000073807958764,-0.000709286416705,-0.000907841223530,-0.000685041173635,-0.000223779650047,0.000240278267880,0.000522441431073,0.000544017123724,0.000334572125978,0.000000000000000]);
fvtool(IPIrx,"Fs", fIPI)
%sum((IPIrx.Numerator-IPIrx1.Numerator).^2)
fvtool(IPI2rx,"Fs",fIPI2)
%% Cascaded response

cascALL = cascade(RRC_Tx,HB,CICcompsc,K_CIC,CIC);

fvtool(cascALL);

%% Plotting of cascaded and individual responses

% plot a superposition of the responses using the filter visualisation tool
fv_all = fvtool(RRC_Tx,'Fs',fRRC,'ShowReference','off');
hold on
addfilter(fv_all, HB,'Fs',fHB,'ShowReference','off');
addfilter(fv_all, CICcompsc,'Fs',fCICcomp,'ShowReference','off');
addfilter(fv_all, CICsc,'Fs',fCIC,'ShowReference','off');
addfilter(fv_all, cascALL, 'Fs', fCIC,'ShowReference','off');
hold off
grid on
title('Cascaded Responses for a Chain of Interpolating Filters');
legend(fv_all,'RRC','HB','CICcomp (scaled)','CIC (scaled)','RRC-HB-CICcomp-CIC Cascade','Location','SouthEast');

%% Design Receiver Matched Filter (Root Raised Cosine)
% This filter will filter by the same filter response as in the transmitter
% but will not decimate (to facilitate synch).

hRRC2 = comm.RaisedCosineReceiveFilter(...
'Shape',                  'Square root', ...
'RolloffFactor',          RRC_rolloff, ...
'FilterSpanInSymbols',    RRC_span, ...
'InputSamplesPerSymbol',  R_RRC * R_HB, ...
'DecimationFactor',       1);

% Extract the weights from the filter object 
% (can then refer to as WRRC.Numerator in System Generator).
WRRC2 = coeffs(hRRC2);

% create a DSP system toolbox version to permit cascading of responses
RRC2 = dsp.FIRDecimator(1,WRRC2.Numerator);

% Use a scaling factor to compensate for filter gain 
% Create an FIR with one weight equal to the scaling factor
K_RRC2 = dsp.FIRFilter('Numerator', 1/sqrt(R_RRC*R_HB));      % 1 weight filter

% Visualise response
RRC_Rx = cascade(K_RRC2,RRC2);

% Visualise response
fvRRC2 = fvtool(RRC_Rx);