# Fuel cycles
Fusion fuel cycle simulator developed on MATLAB Simulink. For the ARC fuel cycle layout refer to Meschini, S. et al. "Modeling and analysis of the tritium fuel cycle for ARC- and STEP-Class D-T fusion power plants" - available [here](https://iopscience.iop.org/article/10.1088/1741-4326/acf3fc/meta).

# Usage
The main script is *fuel_cycle_simulator.m*. You can run in different modes:

- *Single*: run a single simulation, with fixed TBR. Use this if you already know the TBR of your system and want to estimate tritium inventories and tritium flows.
- *Iteration*: run multiple simulations until the required TBR to achieve tritium self-suffuiciency and meet the prescribed doubling time.
- *Parametric*: run parametric analyses on the main fuel cycle design parameters. Based on the parameter, the script runs one of the parametric analysis script.

The input data are defined in a separate file: *inputData.m*. There are additional input data files to reproduce the results for the different scenarios presented in the paper (fuel cycle improvements, plasma operations improvement, and both improvements - plus a worst case scenario). 
