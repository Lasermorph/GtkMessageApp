#pragma once
#include <iostream>
// #include "gtk/gtk.h"
#include "TopMenuBar.h"
#include "MessageField.h"
#include "TypingField.h"

class MainWindow
{
  public:
    MainWindow();
    ~MainWindow();

  public:
    void Create(GtkApplication *app);
    GtkWidget* window = 0x0;

  private:
    MessageField* messageField = 0x0;
    TopMenuBar* topMenuBar = 0x0;
    TypingField* typingField = 0x0;
    GtkWidget* friendsAndMessages = 0x0;
    GtkWidget* messagesAndTypingFiled = 0x0;
    GtkWidget* tmp = 0x0;
    GtkButton* tmp2 = 0x0;
};