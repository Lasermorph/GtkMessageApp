#pragma once
#include "gtk/gtk.h"
struct SuperHandlerData
{
  void* ClassHandler;
	void* AppFunction;
  void* FunctionData;
};

extern void SuperHandler(void* _gtkSender, SuperHandlerData* data);
extern void ClasslessSuperHandler(void* _gtkSender, SuperHandlerData* data);
