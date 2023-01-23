t_d_array = [1,2,5]; % Doubling time [y]
TBE_array = [0.1, 0.5, 1, 2, 3, 4, 5, 10]/100; % TBE [-]
for j=1:numel(t_d_array)
    for i=1:numel(TBE_array)
        TBE = TBE_array(i);
        I_reserve = N_dot / TBE * q * t_res;
            if TBE == 0.005
                TBR = 1.15;
            elseif TBE == 0.01
                TBR = 1.08;
            elseif TBE == 0.02
                TBR = 1.03;
            else
                TBR = 1.0;           
            end
        I_s_0 = 0.8; 
        t_d = t_d_array(j);
        sim_time = (t_d+1)*8760*3600; % update the simulation time
        [out(i,j), I_startup(i,j), ~,~,~, ~] = utilities.find_tbr(I_s_0, I_reserve, t_d, TBR, model, TBR_accuracy, inventory_accuracy);
        close_system(model); 
        Simulink.sdi.clear;
    end

    header = {'TBE','TBR_req','I_startup [kg]'};
    writecell(header,strcat('results/',parametric_variable,'/','t_d =',string(t_d),'y','.csv'), "WriteMode","overwrite", 'Delimiter',','); % Use writecell because writematrix does not add the delimiter between strings 
    writematrix([(TBE_array)',out(:,j), I_startup(:,j)], strcat('results/',parametric_variable,'/','t_d =',string(t_d),'y','.csv'), "WriteMode","append");
end