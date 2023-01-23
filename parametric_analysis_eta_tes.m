eta_tes_array = [0.4,0.6,0.8,0.9,0.95]; % Tritium extraction efficiency
TBE_array = [0.5,1,2,5]/100; % TBE [-]
for j=1:numel(TBE_array)
    TBE = TBE_array(j);
    I_reserve = N_dot / TBE * q * t_res;
    for i=1:numel(eta_tes_array)
        if TBE == 0.005
            TBR = 1.2;
        elseif TBE == 0.01
            TBR = 1.12;
        elseif TBE == 0.02
            TBR = 1.05;
        else
            TBR = 1.0;           
        end
        I_s_0 = 0.8; 
        eta2 = eta_tes_array(i);
        [out(i,j), I_startup(i,j), ~,~,I_tes(i,j), ~] = utilities.find_tbr(I_s_0, I_reserve, t_d, TBR, model, TBR_accuracy, inventory_accuracy);
        close_system(model); 
        Simulink.sdi.clear;
    end
    header = {parametric_variable,'TBR_req','I_startup [kg]', 'I_tes [g]' };
    writecell(header,strcat('results/',parametric_variable,'/','TBE=',string(TBE*100),'%.csv'), "WriteMode","overwrite", 'Delimiter',','); % Use writecell because writematrix does not add the delimiter between strings 
    writematrix([(eta_tes_array)',out(:,j), I_startup(:,j), I_tes(:,j)*1000], strcat('results/',parametric_variable,'/','TBE=',string(TBE*100),'%.csv'), "WriteMode","append");
end