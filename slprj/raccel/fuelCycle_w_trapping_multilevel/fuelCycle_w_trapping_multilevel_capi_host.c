#include "fuelCycle_w_trapping_multilevel_capi_host.h"
static fuelCycle_w_trapping_multilevel_host_DataMapInfo_T root;
static int initialized = 0;
rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        fuelCycle_w_trapping_multilevel_host_InitializeDataMapInfo(&(root), "fuelCycle_w_trapping_multilevel");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction(){return(getRootMappingInfo());}
