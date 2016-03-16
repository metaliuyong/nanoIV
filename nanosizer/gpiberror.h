#ifndef GPIBERROR
#define GPIBERROR

#include "C:\Program Files\IVI Foundation\VISA\Win64\Include\visa.h"
#include <string>
#include <iostream>

bool CheckDisplayError(const ViStatus& vistatus, std::string errormessage);

bool CheckError(const ViStatus& vistaus);


#endif // GPIBERROR

