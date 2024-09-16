#pragma once
#include <iostream>
// #include "gtk/gtk.h"
#include "TopMenuBar.h"
#include "MessageField.h"
#include "TypingField.h"
#include "Hotkeys.h"
#include "FriendsList.h"
#include "adwaita.h"

class MainWindow
{
  public:
    MainWindow();
    ~MainWindow();

  public:
    void Create(GtkApplication* app);
    GtkWidget* window = 0x0;

  private:
    TopMenuBar* topMenuBar = 0x0;
    TypingField* typingField = 0x0;
    GtkWidget* friendsAndMessages = 0x0;
    GtkWidget* messagesAndTypingFiled = 0x0;
};