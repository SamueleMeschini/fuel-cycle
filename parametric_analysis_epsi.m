epsi_array = [1e-2, 1e-3, 5e-4, 1e-4, 1e-5, 1e-6, 1e-7]; % Non radioactive loss fraction [-]
TBE_array = [0.5,1,2,5]/100;  % TBE [-]
for j=1:numel(TBE_array)
    TBE = TBE_array(j);
    I_reserve = N_dot / TBE * q * t_res;
    for i=5:numel(epsi_array)
        % Need some babysitting here, the range of TBR is too large
        if TBE == 0.005
            if i == 1
                TBR = 6.4;
            elseif i == 2
                TBR = 2.5;
            else
                TBR = 2;
            end
        else
            if i<=5
                if TBE == 0.01 && i == 1
                    TBR = 3.7;
                elseif TBE == 0.02 && i == 1
                    TBR = 2.;
                elseif TBE == 0.05 && i == 1
                    TBE = 2.3;
                elseif TBE == 0.01 && i == 2
                    TBR = 2;
                elseif TBE == 0.02 && i == 2
                    TBE = 1.5;
                elseif TBE == 0.01 
                    TBR = 1.5;
                elseif TBE == 0.02 
                    TBR = 1.05;
                else
                    TBR = 1.0;           
                end
            else
                if TBE == 0.01
                    TBR = 1.05;
                elseif TBE == 0.02
                    TBR = 1.03;
                else
                    TBR = 1.0;           
                end
            end
        end
        I_s_0 = 0.8; 
        epsi = epsi_array(i);
        T1 = 1/((1 + epsi)/tau1 + lambda); % Blanket
        T2 = 1/((1 + epsi)/tau2 + lambda); % TES
        T3 = 1/((1 + 0)/tau3 + lambda); % FW
        T4 = 1/((1 + 0)/tau4 + lambda); % Divertor
        T5 = 1/((1 + epsi)/tau5 + lambda); % HX
        T6 = 1/((1 + epsi)/tau6 + lambda); % Detritiation system
        T7 = 1/((1 + epsi)/tau7 + lambda); % Vacuum pump
        T8 = 1/((1 + epsi)/tau8 + lambda); % Fuel clean-up
        T9 = 1/((1 + epsi)/tau9 + lambda); % ISS
        T12 = 1/((1 + epsi)/tau12 + lambda);
        [out(i,j), I_startup(i,j), ~,~,~, ~] = utilities.find_tbr(I_s_0, I_reserve, t_d, TBR, model, TBR_accuracy, inventory_accuracy);
        close_system(model); 
        Simulink.sdi.clear;
    end
    header = {parametric_variable,'TBR_req','I_startup [kg]'};
    writecell(header,strcat('results/',parametric_variable,'/','TBE=',string(sprintf("%1.1f",TBE*100)),'%.csv'), "WriteMode","overwrite", 'Delimiter',','); % Use writecell because writematrix does not add the delimiter between strings 
    writematrix([(epsi_array)',out(:,j), I_startup(:,j)], strcat('results/',parametric_variable,'/','TBE=',string(sprintf("%1.1f",TBE*100)),'%.csv'), "WriteMode","append");
end