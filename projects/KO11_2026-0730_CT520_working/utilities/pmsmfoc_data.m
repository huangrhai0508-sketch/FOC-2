%% Data Dictionary for Permanent Magnet Synchronous Machine Controller 
% Contains data used by both the motor and controller.
% struct pmsm  include the parameter struct of motor
% struct sensors include the onboard sensors' hardware info
% struct ctrlConst include the simulation constants

%% Create constants which will not change during simulation or code generation
% Sample times of high and low rate controller operations
ctrlConst = struct;
% ctrlConst.TsHi = 40e-6;
% ctrlConst.TsLo =  5e-3;
ctrlConst.TsSimP = 1e-6; %from 1us to 0.2us, 20180701, need to change theta0
ctrlConst.TsSim = ctrlConst.TsSimP;
ctrlConst.TsSwitch = 100e-6;
ctrlConst.Ts100ms = 100e-3;
ctrlConst.Ts10ms = 10e-3;
ctrlConst.Ts2ms = 2e-3;
ctrlConst.Ts1ms = 1e-3;

%% sample periond definition in controller
Tsw = ctrlConst.TsSwitch; % for model compatibility
Ts_1ms = ctrlConst.Ts1ms;
Ts_2ms = ctrlConst.Ts2ms;
Ts_10ms = ctrlConst.Ts10ms;
Ts_100ms = ctrlConst.Ts100ms;
% Maximum value for PWM counter (100% Duty Cycle)
ctrlConst.PwmCountsPerRevolution = 3000;

%% Create structure of motor attributes
pmsm = struct;
pmsm.Ld = 0.132e-3;
pmsm.Lq = 0.4031e-3;
pmsm.Rs = 0;
pmsm.RsA = 6.9e-3; %25degC
pmsm.RsB = 6.9e-3; %25degC
pmsm.RsC = 6.9e-3; %25degC
pmsm.PolePairs =5;
pmsm.FluxLinkage = 0.04138*1.414*1;  % flux at 25degC,0.044*1.414*1
pmsm.flux = pmsm.FluxLinkage/1.414;
pmsm.Offset = 0; %pi/12;
pmsm.Harm5 = 0; %0.05
pmsm.Harm7 = 0; %-0.05
pmsm.Harm11 = 0;
pmsm.Harm13 = 0;
pmsm.Udc = 336;
pmsm.RslvrPolePairs = 1;  %for small motor:1,Need change the 0 offset(-16383)!!!!!!!!!!!!!!!!!!!!!!!
pmsm.RslvrRatio = 0.177;
pmsm.J = 0.076;  %just motor rotor: 0.076, for PosnCtrl,7.6
pmsm.Tf = 4;
pmsm.F = 0.05;
%% to eliminate the mask parameters. PSMCtl subsystem

nb_p = pmsm.PolePairs;              %Motor pairs of poles
Ld = pmsm.Ld ;                      %Inductance Ld(H)
Lq = pmsm.Lq;                       %Inductance Lq(H)
flux = pmsm.FluxLinkage/1.414;      %machine flux(Wb)  rms value
Rss = (pmsm.RsA+pmsm.RsB+pmsm.RsC)/3;   %Stator phase resistance (Ohm)
Rc = 77;                            % Iron loss resistance
%Imax = 500;                         %Max Current, 
%max_m = 1.03;                       %maximum modulation rate
%FW_m = 1.03;                        %Flux weakening modulation rate
Ts_1ms = 1e-3;                      %sample time 1ms
Ts_10ms = 10e-3;                    %sample time 10ms

%% to eliminate the mask parameters.
Rs = pmsm.Rs;
theta0 = pmsm.Offset; %0.2us:+pi/8.33;
Np = pmsm.PolePairs;
fluxPk = pmsm.FluxLinkage;
hm5 = pmsm.Harm5;
hm7 = pmsm.Harm7;
hm11 = pmsm.Harm11;
hm13 = pmsm.Harm13;
SpdSetTest = 0; %for auto test, not use
TrqSetTest = 0; %for auto test, not use

%% Sensor attributes
% Hardware ADC sensor measures negative current then goes through an
% inverting amplifier
sensors = struct;
sensors.ADC.Vref = 5;
sensors.ADC.Bits = 12;
sensors.ADC.MaxDriverUnits = (2^sensors.ADC.Bits -1);
sensors.ADC.VoltsToDriverUnits = (sensors.ADC.MaxDriverUnits)/(sensors.ADC.Vref);
sensors.ADC.NoiseEnable = true;
sensors.ADC.NoiseLevelDriverUnits = 4;
sensors.ADC.NoiseOffsetDriverUnits = 0;

% current sensor
sensors.Current.BiasVolts = 2.5;
sensors.Current.MeasureRange = 900;
sensors.Current.AmpsToVolts = -2/sensors.Current.MeasureRange;

% on board resistor-divider
sensors.Dclink.VoltToVolt = 0.003905; %500K/2K
sensors.VddH.VoltToVolt = 0.5;
sensors.Vdd16.VoltToVolt = 0.2492; %100K/33.2K
sensors.Vdd5g1.VoltToVolt = 0.5;
sensors.Vdd5g2.VoltToVolt = 0.5; 
sensors.Vdd5g3.VoltToVolt = 0.5; 
sensors.Vdd5com.VoltToVolt = 0.5;
sensors.Vdd3v3.VoltToVolt = 1; 
sensors.ubr.VoltToVolt = 0.2492;  %100K/33.2K
sensors.Vdd15FB.VoltToVolt = 0.2492;  
sensors.ubr2.VoltToVolt = 0.0904;  %33.2K/3.3K
% sensors.ADC.AmpsToVolts = (-1) * (-3/20);
% sensors.ADC.BiasVolts = 1.65;


% sensors.Encoder.InitialAngleRads = 0;
% sensors.Encoder.MechanicalToEncoderZeroOffsetRads = 0;
% sensors.Encoder.PositionValidAtStartup = false;

%Resolver

% DC bus voltage supplied to inverter
ctrlConst.BusVoltage = 24;
ctrlConst.VoltageLimit = ctrlConst.BusVoltage/2; % Volts
ctrlConst.CurrentLimit = 2; % Amps

% Encoder attributes
ctrlConst.EncoderCountsPerRevolution = 8000;

clear DBG_STRUCT
DBG_STRUCT.TrqAct = single(0);
DBG_STRUCT.TrqMax      = single(0);

tmp_BusName = Simulink.Bus.createObject(DBG_STRUCT);
tmp_Bus = evalin('base',tmp_BusName.busName);
evalin('base',['clear ' tmp_BusName.busName]);
assignin('base','DBG_STRUCT',tmp_Bus);
DBG_STRUCT.DataScope = 'Auto';


for i=1:1:length(DBG_STRUCT.Elements)
    tmpmsg = DBG_STRUCT.Elements(i).Name;
    eval([tmpmsg,'.DataScope = ''Auto'';']);
    
end

clear tmp_BusName tmp_Bus






