clear all

% Load input data
run('inputData.m')

% Do not store data from inspector - avoid memory issues 
Simulink.sdi.setAutoArchiveMode(false);
Simulink.sdi.setArchiveRunLimit(0);

% Define model to be run
model = "fuelCycle.slx";
TBR_accuracy = 0.005; % accuracy when computing the required TBR 
inventory_accuracy = 0.01; % accuracy when computing start-up inventory [kg]
sim_time = 3 * 8760 * 3600; % simulation time [s]
runMode = "iteration" % single, iteration or parametric analysis
parametric_variable = 'epsi'; % name of the variable if performing parametric analysis

TBR = 1.07; % TBR - If runMode = "single" this is fixed
            %       If runMode = "iteration" this is the initial guess
I_s_0 = 1.4; % startup inventory [kg] - If runMode = "single" this is fixed
             %                          If runMode = "iteration" this is the initial guess
             
% If you know the required TBR and the start-up inventory, run in "single"
% mode. If you don't know them, run in "iteration" mode, find the required
% TBR and the start-up inventory for a given configuration, and then run a
% "single" simulation to extract the inventories (and wathever variable required) from the model. 

if strcmp(runMode,"single")
    %Single simulation with fixed TBR and start-up inventory
    out = sim(model); 
%     in this case we save the tritium inventories from some of the FC
%     components and store them in a matrix. Each inventory is accessible
%     by out.I_N, where N is the component number as described in the
%     paper. 
    header = {'time [s]', 'blanket inventory [kg]', 'TES inventory [kg]', 'ISS inventory [kg]', 'storage inventory [kg]'};
    writecell(header,'results/inventories.csv', "WriteMode","overwrite", "Delimiter",",");
    writematrix([out.tout, out.I_1, out.I_2, out.I_9, out.I_11], 'results/inventories.csv', "WriteMode","append", "Delimiter",",");

%     In this other case we set the reserve time to 0 and run a simulation
%     to track the storage inventory without a reserve inventory
%     header = {'time [s]', 'storage inventory [kg]'};
%     writecell(header,'results/inflection_w_o_reserve.csv', "WriteMode","overwrite", "Delimiter",",");
%     writematrix([out.tout, out.I_11], 'results/inflection_w_o_reserve.csv', "WriteMode","append", "Delimiter",",");

elseif strcmp(runMode,"iteration")
    %Iterative search for the required TBR and start-up inventory
    utilities.find_tbr(I_s_0, I_reserve, t_d, TBR, model, TBR_accuracy, inventory_accuracy)

elseif strcmp(runMode,'parametric')
    if strcmp(parametric_variable,'TBE')
        mkdir(strcat('results/', parametric_variable,'td',string(t_d),'y'))
    else
        mkdir(strcat('results/', parametric_variable))
    end
    run(strcat('parametric_analysis_',parametric_variable,'.m'))
else
    fprintf("Enter a valid run mode \n")
end
