relaxation_coefficient = 1e12; % increase the characteristic time of 
% trapping/detrapping to avoid stiffness. NOTE: this affects the transient
% evolution, but not the magnitude of the trapped inventory. The timescale
% is still so quick that it does not have any effects on the results.

% Define trapping input data
N_a = 6.022e23;
PM_tungsten = 183.8;
PM_tritium = 3;
nu_0 = 1e13;
E_trap = 0.87; % eV
k_B = 8.6e-5; % ev/K 

% Tungsten
rho_tungsten = 19.3; %g/cm3
V_tungsten = 0.35e6; % cm3
T_tungsten = 1100; % K
nu_detrap = nu_0 * exp(-E_trap/(k_B * T_tungsten)); % detrapping rate
tau_detrap = 1 / nu_detrap* relaxation_coefficient;
D = 4.1e-7/sqrt(3) * exp(-0.39/(k_B * T_tungsten)) % Diffusion coefficient in tungsten - Dividide by sqrt(Isotope mass)
a_tungsten = 316e-12; % m - lattice constant
lambda = a_tungsten/2/sqrt(2);
nu_trap = D / lambda^2;
tau_trap = 1/nu_trap * relaxation_coefficient;
n_tungsten = rho_tungsten * V_tungsten / PM_tungsten * N_a;
n_solute = 6; % Available site for mobile tritium
n_trap = 1e-4;
f_permanent_trap = 0;
m_u = 1.6e-27; 
tau_permanent = 100 * 24 *3600;
M_tungsten = V_tungsten * rho_tungsten/1e3; % kg

% V-Cr-Ti 
rho_vcrti = 6.1; % V-Cr-Ti alloy g/cm3 - REF: D.L. Smith, et al., 
% Vanadium-base alloys for fusion reactor applications — a review, 
% Journal of Nuclear Materials, vol. 135, pp. 125-139, 1985
PM_structural = 47*0.15+50*.7+52*0.15 % VCrTi
% NOTE: the trapping energy is unknown, use the same as W for now

V_structural = 3.5e6; % cm3 - REF: D. Pettinari
T_structural = 950; % K 
nu_detrap_structural = nu_0 * exp(-E_trap/(k_B * T_structural)); % detrapping rate
tau_detrap_structural = 1 / nu_detrap_structural* relaxation_coefficient;
D_structural = 7.5e-8/sqrt(3) * exp(-0.13/(k_B * T_structural)) % Diffusion coefficient in VCrTi
a_structural = 30.3e-9; % m - lattice constant. REF: I Kurzina et al 2019 J. Phys.: Conf. Ser. 1145 012051
lambda = a_structural/2/sqrt(2);
nu_trap_structural = D / lambda^2;
tau_trap_structural = 1/nu_trap_structural * relaxation_coefficient;
n_structural = rho_vcrti * V_structural / PM_structural * N_a;
n_solute = 6; % Available site for mobile tritium - Assume that V-Cr-TI is BCC
n_trap_structural= 1e-4;
f_permanent_trap_structural = 0;
tau_permanent_structural = 100 * 24 *3600;
M_structural = V_structural * rho_vcrti/1e3; % kg