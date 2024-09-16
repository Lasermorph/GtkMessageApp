#include "./include/MainWindow.h"
#include "./include/SuperHandler.h"
#include "./include/Actions.h"

#ifndef __CPU_SIZE
#define __CPU_SIZE sizeof (void*)
#endif


static void WhenReady(unsigned char* doublePointer)
{
  GtkApplication** app = 0x0;
  MainWindow*** mwReturn = 0x0;
  // for(int i = 0; i < __CPU_SIZE; i++)
  // {
  //   int i2 = __CPU_SIZE + i;
  //   ((unsigned char*)(&mwReturn))[i] = doublePointer[i];
  //   ((unsigned char*)(&app))[i] = doublePointer[i2];
  // }

  app = (GtkApplication**)(&doublePointer[__CPU_SIZE]);
  mwReturn = ((MainWindow***)(doublePointer));
  **mwReturn = new MainWindow();
  (**mwReturn)->Create(*app);
}

int main (int argc, char *argv[]) 
{
  // Create a new application
  GtkApplication* app = gtk_application_new("com.example.GtkApplication", G_APPLICATION_DEFAULT_FLAGS);
  
  MainWindow* mainwindow = 0x0;

  SuperHandlerData* data = new SuperHandlerData();
  data->ClassHandler = 0x0;
  data->AppFunction = (void*)WhenReady;

  unsigned char* doublePointer = new unsigned char[__CPU_SIZE*2];

  *((MainWindow***)(doublePointer)) = &mainwindow;
  *((GtkApplication**)(doublePointer + __CPU_SIZE)) = app;
  // for(int i = 0; i < __CPU_SIZE; i++)
  // {
  //   int i2 = __CPU_SIZE + i;
  //   doublePointer[i] = ((unsigned char*)((&mainwindow)))[i];
  //   doublePointer[i2] = ((unsigned char*)(&app))[i]; 
  // }
  data->FunctionData = doublePointer;

  g_signal_connect(app, "activate", G_CALLBACK (ClasslessSuperHandler), data);

  int status = g_application_run(G_APPLICATION (app), argc, argv);

  g_object_unref(app);

  delete[] doublePointer;
  delete data;
  delete mainwindow;

  return status;
}
