clear all
% Input data required for fuel cycle
% Residence times [s]
tau1 = 1*1200; % Blanket
tau2 = 1*24*3600; % TES
tau3 = 1000; % FW
tau4 = 1000; % Divertor
tau5 = 1000; % HX
tau6 = 3600; % Detritiation system
tau7 = 600; % Vacuum pump 
tau8 = 0.9*3600; % Fuel clean-up - tau8+tau9 = 4h from Abdou's paper
tau9 = 3.1*3600; % ISS -  tau8+tau9 = 4h from Abdou's paper
tau10 = 1*3600;
% Decay constant
lambda = 1.73e-9; %12.33 y half-life
% Non-radioactive losses fraction
epsi = 1e-4;
% Effective residence time
T1 = 1/((1 + epsi)/tau1 + lambda); % Blanket
T2 = 1/((1 + epsi)/tau2 + lambda); % TES
T3 = 1/((1 + 0)/tau3 + lambda); % FW
T4 = 1/((1 + 0)/tau4 + lambda); % Divertor
T5 = 1/((1 + epsi)/tau5 + lambda); % HX
T6 = 1/((1 + epsi)/tau6 + lambda); % Detritiation system
T7 = 1/((1 + epsi)/tau7 + lambda); % Vacuum pump
T8 = 1/((1 + epsi)/tau8 + lambda); % Fuel clean-up
T9 = 1/((1 + epsi)/tau9 + lambda); % ISS
% Flow rate fractions


% From plasma to components
fp3 = 1e-4;
fp4 = 1e-4;

%From component to component

% The relative fractions from HX to components are preserved wrt Abdou's model: 60% to FW, 39% to
% divertors, 1% to blanket and 0.01% to DS.

f13 = 0.6;
f1_4 = 0.39; % use the underscore for f14 to avoid shadowing
f56 = 1e-4; % HX to DS
f96 = 0.1; % ISS to DS
f_dir = 0.3; % DIR fraction

% Components' efficiency
eta2 = 0.95; % TES
eta6 = 0.95; % DS

% General parameters
N_dot = 8.99e-7; % Tritium burnt [kg/s]
f_b = 0.02; % burnup fraction
TBR = 1.08;
I_s_0 = 1.5; %  startup inventory [kg]

% Reserve inventory
q = 0.25; % fraction of FC failing
t_res = 3600 * 24; % reserve time
AF = 70; % for AF_model, use 0-100, for non AF_models, use 0-1;
I_reserve = N_dot / f_b * q * t_res; %  reserve inventory [kg]
t_d = 2;

% Define model to be run
model = "fuelCycle.slx";
accuracy = 0.01; % accuracy when computing the required TBR 
sim_time = 3 * 8760 * 3600; % simulation time [s]
runMode = "single" % single or iteration
TBR = 1.06; % TBR - If runMode = "single" this is fixed
            %       If runMode = "iteration" this is the initial guess
I_s_0 = 1.5; % startup inventory [kg] - If runMode = "single" this is fixed
             %                          If runMode = "iteration" this is the initial guess


% If you know the required TBR and the start-up inventory, run in "single"
% mode. If you don't know them, run in "iteration" mode, find the required
% TBR and the start-up inventory for a given configuration, and then run a
% "single" simulation to extract the inventories (and wathever variable you
% want) from the model. 


if strcmp(runMode,"single")
    %Single simulation with fixed TBR and start-up inventory
    out = sim(model); 
    % Checking that I_st > 0 for every t once the 
    % simulation is done is a good idea!
    header = ['time[s]', 'blanket inventory[kg]', 'TES inventory [kg]', 'ISS inventory [kg]', 'storage inventory [kg]'];
    writematrix(header,'results/results.csv');
    writematrix([out.tout, out.I_1, out.I_2, out.I_9, out.I_11], 'results.csv', "WriteMode","append");
elseif strcmp(runMode,"iteration")
    %Iterative search for the required TBR and start-up inventory
    utilities_fc.find_tbr(I_s_0, I_reserve, t_d, TBR, model, accuracy)
else 
    fprintf("Enter a valid run mode \n")
end
