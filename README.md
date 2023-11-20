# fuel-cycle
Fusion fuel cycle simulator developed on MATLAB Simulink. For the ARC fuel cycle layout refer to Meschini, S. et al. "Modeling and analysis of the tritium fuel cycle for ARC- and STEP-Class D-T fusion power plants" - available [here](https://iopscience.iop.org/article/10.1088/1741-4326/acf3fc/meta).

## Basic usage
* *fuelCycle.slx* contains the Simulink model. You can modify it according to your needs. 
* *arc.slx* contains some convenience blocks for the fuel cycle. Note that most of the blocks in *fuelCycle.slx* are more complex version than the blocks in this library. 
* *fuelCycleSimulator.m* handles all the simulations. You can choose between three simulation modes:
  * *single*: use this if you already know the required TBR and the startup inventory. It returns all the tritium inventories within the fuel cycle subsystems. The doubling time is an *output* of the model in this case.
  * *iteration*: use this if you don't know the required TBR and/or the startup inventory. The model is run iteratively until the target doubling time is met. The doubling time is an *input* of the model in this case.
  * *parametric*: use this to run parametric analysis on a design parameter. It runs one of the scripts for parametric analysis. Must specify the parameter on which the parametric analysis is run. It returns .csv files for each value of the parameter, and (usually) for different values of TBE.
* *inputData.m* contains all the input data for the fuel cycle model. It is called by *fuelCycleSimulator.m* before running the Simulink model


