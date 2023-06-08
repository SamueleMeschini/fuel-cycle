f_dir_array = linspace(0.1,0.9,9); % DIR fraction [s]
TBE_array = [0.5,1,2,5]/100; % TBE [-]

for j=1:numel(TBE_array)
    TBE = TBE_array(j);
    I_reserve = N_dot / TBE * q * t_res;
    for i=1:numel(f_dir_array)
        if TBE == 0.005
            TBR = 1.15;
        elseif TBE == 0.01
            TBR = 1.07;
        elseif TBE == 0.02
            TBR = 1.02;
        else
            TBR = 1.0;           
        end
        I_s_0 = 0.8; 
        f_dir = f_dir_array(i);
        [out(i,j), I_startup(i,j), ~,~,~,~] = utilities.find_tbr(I_s_0, I_reserve, t_d, TBR, model, TBR_accuracy, inventory_accuracy);
        close_system(model); 
        Simulink.sdi.clear;

    end
    header = {parametric_variable,'TBR_req','I_startup [kg]'};
    writecell(header,strcat('results/',parametric_variable,'/','TBE=',string(sprintf("%1.1f",TBE*100)),'%.csv'), "WriteMode","overwrite", 'Delimiter',','); % Use writecell because writematrix does not add the delimiter between strings 
    writematrix([(f_dir_array)',out(:,j), I_startup(:,j)], strcat('results/',parametric_variable,'/','TBE=',string(sprintf("%1.1f",TBE*100)),'%.csv'), "WriteMode","append");
    
end
