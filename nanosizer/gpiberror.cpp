#include "gpiberror.h"


bool CheckDisplayError(const ViStatus& vistatus, std::string errormessage = "ERROR!\n")
{
    bool success;

    if(vistatus < VI_SUCCESS)
    {
        std::cerr << errormessage << "\n";
        success = false;
    }

    else
    {
        success = true;
    }

    return success;

}

bool CheckError(const ViStatus& vistatus)
{
    bool success;

    if(vistatus < VI_SUCCESS)
    {
        success = false;
    }

    else
    {
        success = true;
    }

    return success;

}
