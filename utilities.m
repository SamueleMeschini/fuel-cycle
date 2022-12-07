classdef utilities
    %UNTITLED Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        Property1
    end
    
    methods
        function obj = untitled(inputArg1,inputArg2)
            %UNTITLED Construct an instance of this class
            %   Detailed explanation goes here
            obj.Property1 = inputArg1 + inputArg2;
        end

    end
    methods(Static)
        function [TBR, I_s_0, margin, blanket_inventory, tes_inventory, HX_inventory] = find_tbr(I_s_0, I_reserve, t_d_req, TBR_start, model, accuracy, inventory_accuracy)
            TBR = TBR_start;
            assignin("base", "TBR", TBR) % save the value of TBR in the workspace, otherwise Simulink does not read the value computed in the function!
            iteration = 0;
            inner_iteration = 0;
            out = sim(model);
            I_storage = out.I_11;
            td = 10; % Initial value to enter the loop
                while(any(I_storage - I_reserve < 0) || iteration == 0 || t_d >  t_d_req)
                        assignin("base", "TBR", TBR) % save the value of TBR in the workspace, otherwise Simulink does not read the value computed in the function!
                        assignin("base", "I_s_0", I_s_0)
                        out = sim(model);
                        I_storage = out.I_11;
                        I_bz = out.I_1;
                        I_tes = out.I_2;
                        I_hx = out.I_5;
                        iteration = iteration + 1;
                        TBR = TBR + accuracy
                        disp(iteration)
                        t_d = doublingTime(I_s_0, out);
                        margin = min(I_storage - I_reserve);
                        blanket_inventory = (max(I_bz)); % kg
                        tes_inventory = (max(I_tes)); % kg
                        HX_inventory = (max(I_hx)); % kg
                        if isempty(t_d)
                            t_d = 20;
                        end 
                            % can be done in one line but this is more
                            % clear: Increase or decrease the startup
                            % inventory according to the margin
                            if margin < 0
                                I_s_0 = I_s_0 + abs(margin) + inventory_accuracy; % add 0.05 to avoid numerical issues
                            else
                                I_s_0 = I_s_0 - abs(margin) + inventory_accuracy;  % add 0.05 to avoid numerical issues
                            end
                        disp("Doubling time = " + t_d)
                        disp("I_s_0 = " + I_s_0)
                        disp("Minimum difference between storage and reserve " + min(I_storage - I_reserve))
                        disp("Blanket inventory: " + round(max(I_bz)*1000, 2) + " g")
                        disp("TES inventory: " + round(max(I_tes)*1000, 2)  + " g")
                        disp("HX inventory: " + round(max(HX_inventory)*1000, 2)  + " g")

                        if iteration == 1000            
                            iteration = 0;
                            TBR = TBR_start;
                            
                            inner_iteration = inner_iteration + 1;
                            disp(inner_iteration)
                        end 
                end
        end

%% For basic simulations
        function [TBR, I_s_0, margin, blanket_inventory, tes_inventory, out] = find_tbr_basic(I_s_0, I_reserve, t_d_req, TBR_start, model, accuracy)
            TBR = TBR_start;
            assignin("base", "TBR", TBR) % save the value of TBR in the workspace, otherwise Simulink does not read the value computed in the function!
            iteration = 0;
            inner_iteration = 0;
            out = sim(model);
            I_storage = out.I_11;
            td = 10; % Initial value to enter the loop
                while(any(I_storage - I_reserve < 0) || iteration == 0 || t_d >  t_d_req)
                        assignin("base", "TBR", TBR) % save the value of TBR in the workspace, otherwise Simulink does not read the value computed in the function!
                        assignin("base", "I_s_0", I_s_0)
                        out = sim(model);
                        I_storage = out.I_11;
                        iteration = iteration + 1;
                        TBR = TBR + accuracy
                        disp(iteration)
                        t_d = doublingTime(I_s_0, out);
                        margin = min(I_storage - I_reserve);
                        if isempty(t_d)
                            t_d = 20;
                        end 
                            % can be done in one line but this is more
                            % clear: Increase or decrease the startup
                            % inventory according to the margin
                            if margin < 0
                                I_s_0 = I_s_0 + abs(margin) + 0.1;
                            else
                                I_s_0 = I_s_0 - abs(margin) + 0.1;
                            end
                        disp("Doubling time = " + t_d)
                        disp("I_s_0 = " + I_s_0)
                        disp("Minimum difference between storage and reserve " + min(I_storage - I_reserve))
                        if iteration == 1000            
                            iteration = 0;
                            TBR = TBR_start;
                            
                            inner_iteration = inner_iteration + 1;
                            disp(inner_iteration)
                        end 
                end
        end

        function dummy = plot_startup_vs_reserve(I_st, I_res)
            % Startup vs reserve inventory
            x = 0:3000;
            trendline =  0.0424 * x + 0.0543;
            t = tiledlayout(1,1)
            ax1 = axes(t)
            plot(ax1,I_st, I_res, 'or')
            xlim([0 230])
            ylim([0 230])
            xlabel('Start-up inventory (kg)')
            ylabel('Reserve inventory (kg)')
            ax1.Box = 'off'
            ax2 = axes(t)
            plot(ax2, x, trendline, 'k')
            ax2.XAxisLocation = 'top';
            ax2.YAxisLocation = 'right';
            ax2.Color = 'none';
            xlabel('Fusion power (MW_t_h)')
            ax2.Box = 'off';
            xlim([0 3000])
            ylim([0 230])
        end

        function [epsi,f_b, f_dir, AF, t_p, tau8,tau9,T8,T9,eta2,t_d] = sampleDesignSpace(num_sim)
            lambda = 1.73e-9; %12.33 y half-life
            epsi = rand(num_sim)*9e-4 + 1e-4;
            f_b = (rand(num_sim)*4.5+0.5)/100; % from 0.5% to 5%
            f_dir = rand(num_sim); % 0-1
            AF = rand(num_sim)*30 + 69.99; % from 30% to 99.99%
            t_p = (rand(num_sim)*11 + 1)*3600; % 1-12h
            tau8 = 0.25*t_p; % Fuel clean-up - tau8+tau9 = 4h from Abdou's paper
            tau9 = 0.75*t_p; % ISS -  tau8+tau9 = 4h from Abdou's paper
            T8 = 1./((1 + epsi)./tau8 + lambda); % Fuel clean-up
            T9 = 1./((1 + epsi)./tau9 + lambda); % ISS
            eta2 = rand(num_sim)*0.8 + 0.2; % 0.2-0.99
            t_d = rand(num_sim)*9 + 1; % 1-10y
            
        end

        function parallelCoordsPlot(filename)
%             M = readmatrix(filename);
%             labels = M(1,:);
%             AF = M(:,1);
%             epsi = M(:,2);
%             eta_tes = M(:,3);
%             f_b = M(:,4);
%             f_dir = M(:,5);
%             t_d = M(:,6);
%             t_p = M(:,7)/3600;
%             TBR_req = M(:,10);
%             I_st = M(:,10);
%             x = [ AF,epsi,eta_tes,f_b,f_dir,t_d,t_p,TBR_req,];
            opts = detectImportOptions(filename);
            opts = setvartype(opts,{'AF','epsi','eta_tes','f_b','f_dir','t_d','t_p','TBR_req'},'double');
            opts.SelectedVariableNames = {'AF','epsi','eta_tes','f_b','f_dir','t_d','t_p','TBR_req'};
            T = readtable(filename,opts);
            T.t_p = T.t_p/3600; % convert in hours
            p = parallelplot(T);

            % divide the TBR in bins for better visualization
            binEdges = [1	1.05000000000000	1.10000000000000	1.15000000000000	1.20000000000000	1.25000000000000	1.30000000000000 1.35];
            bins = {'1 - 1.05', '1.05 - 1.10', '1.10 - 1.15', '1.15 - 1.20', '1.20 - 1.25', '1.25 - 1.30', '> 1.30'};
            groupTBR = discretize(p.SourceTable.TBR_req, binEdges,'categorical',bins);
            p.SourceTable.GroupTBR = groupTBR;
            p.GroupVariable = 'GroupTBR';
            p.CoordinateVariables = linspace(1,8,8);
            
        end
    function [TBE, P_f_ratio] = PfRatio_vs_TBE(f_he_div, eta_he, Sigma)
        % f_he_div(float) : helium fraction in the divertor
        % eta_he(float) : helium enrichment (eta_he = f_he_div/f_he_core)
        % Sigma(float) : relative pumping speed of the divertor pump
        TBE = 1 ./ (1./(2*f_he_div*Sigma) + 1);
        P_f_ratio = (1 - (2*f_he_div/eta_he)./(1 + 2 * f_he_div / eta_he)).^2;              
    end

    function [f_he, P_f_ratio] = PfRatio_vs_fhe(TBE,eta_he,Sigma)
        f_he = TBE./(2*Sigma*(1-TBE));
        P_f_ratio = (1 - (2*f_he_div/eta_he)./(1 + 2 * f_he_div / eta_he)).^2;
    end
    end
end


