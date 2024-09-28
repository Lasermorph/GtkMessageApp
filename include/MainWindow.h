#pragma once
#include <iostream>
#include "TopMenu.h"
#include "MessageField.h"
#include "TypingField.h"
#include "Hotkeys.h"
#include "FriendsList.h"

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