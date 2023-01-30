tau1_array = [1,2,8,24,72,240]*3600; % Blanket residence time [s]
TBE_array = [0.5,1,2,5]/100; % TBE [-]
for j=1:numel(TBE_array)
    TBE = TBE_array(j);
    I_reserve = N_dot / TBE * q * t_res;
    for i=1:numel(tau1_array)
        if TBE == 0.005
            TBR = 1.23;
        elseif TBE == 0.01
            TBR = 1.12;
        elseif TBE == 0.02
            TBR = 1.05;
        else
            TBR = 1.02;           
        end
        I_s_0 = 0.8; 
        tau1 = tau1_array(i);
        T1 = 1/((1 + epsi)/tau1 + lambda); % Blanket
        [out(i,j), I_startup(i,j), ~,blanket_inventory(i,j),~, ~] = utilities.find_tbr(I_s_0, I_reserve, t_d, TBR, model, TBR_accuracy, inventory_accuracy);
        close_system(model); 
        Simulink.sdi.clear;
    end
    header = {'t_blanket [h]','TBR_req','I_startup [kg]','Blanket_inventory [g]'};
    writecell(header,strcat('results/t_blanket/','TBE=',string(sprintf("%1.1f",TBE*100)),'%.csv'), "WriteMode","overwrite", 'Delimiter',','); % Use writecell because writematrix does not add the delimiter between strings 
    writematrix([(tau1_array/3600)',out(:,j), I_startup(:,j), blanket_inventory(:,j)*1000], strcat('results/t_blanket/','TBE=',string(sprintf("%1.1f",TBE*100)),'%.csv'), "WriteMode","append");  
end
