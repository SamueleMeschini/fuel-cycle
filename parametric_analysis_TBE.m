TBE_array = [0.1, 0.5, 1, 2, 3, 4, 5, 10]/100; % TBE [-]
t_p_array = [1,4,12]*3600; % Tritium processing time [s]
mkdir('results/TBEtd2y')

for j=1:numel(t_p_array)
    t_p = t_p_array(j);
   % Update the processing times
    tau8 = t_p*0.1; % Fuel clean-up - tau8+tau9 = 4h from Abdou's paper
    tau9 = t_p*0.9; % ISS -  tau8+tau9 = 4h from Abdou's paper
    T8 = 1/((1 + epsi)/tau8 + lambda); % Fuel clean-up
    T9 = 1/((1 + epsi)/tau9 + lambda); % ISS
    for i=1:numel(TBE_array) 
        TBE = TBE_array(i);
        if t_d == 2
            if TBE == 0.001 & t_p == 12*3600
                TBR = 3.5;
            elseif TBE == 0.001
                TBR = 2.0
            elseif TBE == 0.01
                TBR = 1.05;
            elseif TBE == 0.02
                TBR = 1.02;
            else
                TBR = 1.0;            
            end 
        else
            if TBE == 0.001 & t_p == 12*3600
                TBR = 2.;
            elseif TBE == 0.001
                TBR = 1.5
            elseif TBE == 0.01
                TBR = 1.05;
            elseif TBE == 0.02
                TBR = 1.02;
            else
                TBR = 1.0;            
            end 
        end
        I_reserve = N_dot / TBE * q * t_res;
        [out(i,j), I_startup(i,j), ~,~,~,~] = utilities.find_tbr(I_s_0, I_reserve, t_d, TBR, model, TBR_accuracy, inventory_accuracy);
        close_system(model); 
        Simulink.sdi.clear;
    end
    header = {'TBE [%]','TBR_req','I_startup [kg]'};
    writecell(header,strcat('results/',parametric_variable,'td',string(t_d),'y','/','t_p =',string(t_p/3600),'h','.csv'), "WriteMode","overwrite", 'Delimiter',','); % Use writecell because writematrix does not add the delimiter between strings 
    writematrix([(TBE_array)',out(:,j), I_startup(:,j)], strcat('results/',parametric_variable,'td',string(t_d),'y','/','t_p =',string(t_p/3600),'h','.csv'), "WriteMode","append");
end 