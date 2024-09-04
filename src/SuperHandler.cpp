#include "../include/SuperHandler.h"

void SuperHandler(void* _gtkSender, SuperHandlerData* data)
{
  ((void (*)(void*, void*)) data->AppFunction)(data->ClassHandler, data->FunctionData);
}

void ClasslessSuperHandler(void* _gtkSender, SuperHandlerData* data)
{
  ((void (*)(void*))data->AppFunction)(data->FunctionData);
}