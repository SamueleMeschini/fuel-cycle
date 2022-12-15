TBE_array = [0.1, 0.5, 1, 2, 3, 4, 5, 10]/100; % TBE [-]
for i=1:numel(TBE_array)
    TBR = 1.06;           
    I_s_0 = 0.8; 
    TBE = TBE_array(i);
    if TBE == 0.001
        TBR = 2.9;
    end 
    t_d_req = 2;
%     TBR = TBR_start;
%     I_s_0 = I_s_0_start;
    I_reserve = N_dot / TBE * q * t_res;
    [out(i), I_startup(i), ~,~,~] = utilities.find_tbr(I_s_0, I_reserve, t_d_req, TBR, model, TBR_accuracy, inventory_accuracy);
end
header = {'TBE [%]','TBR_req','I_startup [kg]'};
writecell(header,strcat('results/TBE/TBE.csv'), "WriteMode","overwrite", 'Delimiter',','); % Use writecell because writematrix does not add the delimiter between strings
writematrix([TBE_array*100',out', I_startup'], strcat('results/TBE/TBE.csv'), "WriteMode","append");