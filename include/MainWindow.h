#pragma once
#include <gtk/gtk.h>

class MainWindow
{
  public:
    MainWindow(GtkApplication* app);
    ~MainWindow();

  public:
    GtkWidget* window = 0x0;

  private:
    GtkWidget* messagesAndTypingFiled = 0x0;

    GtkWidget* headerBar = 0x0;
};