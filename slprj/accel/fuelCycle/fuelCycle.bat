@echo off
set MATLAB=C:\Program Files\MATLAB\R2022b
"%MATLAB%\bin\win64\gmake" -f fuelCycle.mk  OPTS="-DTID01EQ=0"
