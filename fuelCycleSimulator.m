clear all

% Load input data
run('inputData.m')

% Define model to be run
model = "fuelCycle.slx";
TBR_accuracy = 0.005; % accuracy when computing the required TBR 
inventory_accuracy = 0.01;
sim_time = 3 * 8760 * 3600; % simulation time [s]
runMode = "iteration" % single, iteration or parametric analysis
parametric_variable = 'TBE';

TBR = 1.08; % TBR - If runMode = "single" this is fixed
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
    writematrix(header,'results/results.csv', "WriteMode","overwrite");
    writematrix([out.tout, out.I_1, out.I_2, out.I_9, out.I_11], 'results/results.csv', "WriteMode","append");
elseif strcmp(runMode,"iteration")
    %Iterative search for the required TBR and start-up inventory
    utilities.find_tbr(I_s_0, I_reserve, t_d, TBR, model, TBR_accuracy, inventory_accuracy)
elseif strcmp(runMode,'parametric')
    run(strcat('parametric_analysis_',parametric_variable,'.m'))
else
    fprintf("Enter a valid run mode \n")
end
