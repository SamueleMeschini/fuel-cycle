t_res_array = [1,2,4,8,16,24,48]*3600; % Availability factor [s]
TBE_array = [0.5,1,2,5]/100; % TBE [-]
for j=1:numel(TBE_array)
    TBE = TBE_array(j);
    for i=1:numel(t_res_array)
        if TBE == 0.005
            TBR = 1.15;
        elseif TBE == 0.01
            TBR = 1.07;
        elseif TBE == 0.02
            TBR = 1.03;
        else
            TBR = 1.0;           
        end
        I_s_0 = 0.8; 
        t_res = t_res_array(i);
        I_reserve = N_dot / TBE * q * t_res;
        [out(i,j), I_startup(i,j), ~,~,~, ~] = utilities.find_tbr(I_s_0, I_reserve, t_d, TBR, model, TBR_accuracy, inventory_accuracy);
        I_res(i,j) = I_reserve;
        close_system(model); 
        Simulink.sdi.clear;
    end
    header = {parametric_variable,'TBR_req','I_startup [kg]', 'I_res [kg]' };
    writecell(header,strcat('results/',parametric_variable,'/','TBE=',string(TBE*100),'%.csv'), "WriteMode","overwrite", 'Delimiter',','); % Use writecell because writematrix does not add the delimiter between strings 
    writematrix([(t_res_array/3600)',out(:,j), I_startup(:,j), I_res(:,j)], strcat('results/',parametric_variable,'/','TBE=',string(TBE*100),'%.csv'), "WriteMode","append");
end