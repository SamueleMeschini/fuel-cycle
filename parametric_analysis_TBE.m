TBR_start = 1.08; % TBR - If runMode = "single" this is fixed
            %       If runMode = "iteration" this is the initial guess
I_s_0_start = 1.5; % startup inventory [kg] - If runMode = "single" this is fixed
             %                          If runMode = "iteration" this is the initial guess          
TBE_array = [0.1, 0.5, 1, 2, 3, 4, 5, 10]/100; % TBE [-]
for i=1:numel(TBE_array)
    t_d_req = 2;
    TBR = TBR_start;
    I_s_0 = I_s_0_start;
    f_b = TBE_array(i);
    I_reserve = N_dot / f_b * q * t_res;
    [out(i), I_startup(i), dummy, blanket_inventory(i), tes_inventory(i)] = utilities.find_tbr(I_s_0, I_reserve, t_d_req, TBR_start, model, TBR_accuracy, inventory_accuracy);
end
header = {'TBE [%]','TBR_req','I_startup [kg]'};
writecell(header,strcat('results/TBE/TBE.csv'), "WriteMode","overwrite", 'Delimiter',','); % Use writecell because writematrix does not add the delimiter between strings
writematrix([TBE_array*100',out', I_startup'], strcat('results/TBE/TBE.csv'), "WriteMode","append");