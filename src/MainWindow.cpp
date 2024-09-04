#include "MainWindow.h"

void MainWindow::Create(GtkApplication* app)
{
	// Create a new window
	window = gtk_application_window_new(app);
	gtk_window_set_default_size(GTK_WINDOW(window), 500, 300);
	gtk_window_set_title(GTK_WINDOW(window), "We made an app");

	//Containers for the widget placements
	friendsAndMessages = gtk_box_new(GtkOrientation::GTK_ORIENTATION_HORIZONTAL, 0);
	messagesAndTypingFiled = gtk_box_new(GtkOrientation::GTK_ORIENTATION_VERTICAL, 0);
	tmp = gtk_button_new_with_label("we are doing som testing");

	TopMenuBar::globalInstance = new TopMenuBar();

	gtk_button_set_label(tmp2, "gaming")	;
	// // When the button is clicked, close the window passed as an argument
	// g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_window_close), window);

	gtk_application_set_menubar(app, G_MENU_MODEL(TopMenuBar::globalInstance->Create(app, window)));
	gtk_application_window_set_show_menubar(GTK_APPLICATION_WINDOW(window), true);

	gtk_box_append(GTK_BOX(messagesAndTypingFiled), messageField->Create());
	gtk_box_append(GTK_BOX(messagesAndTypingFiled), tmp);
	gtk_box_append(GTK_BOX(messagesAndTypingFiled), GTK_WIDGET(tmp2));
	gtk_box_append(GTK_BOX(friendsAndMessages), typingField->Create());
	gtk_box_append(GTK_BOX(friendsAndMessages), messagesAndTypingFiled);
	// gtk_box_append(GTK_BOX(messagesAndTypingFiled), button2);

	gtk_window_set_child(GTK_WINDOW(window), friendsAndMessages);
	// gtk_widget_set_size_request(window, 1000, 200);
	gtk_window_present(GTK_WINDOW(window));
}

MainWindow::~MainWindow()
{
	if (window != 0x0)
	{
		gtk_window_destroy(GTK_WINDOW(window));
	}
	
	if (messageField != 0x0)
	{
		delete messageField;
		messageField = 0x0;
	}

	if (topMenuBar != 0x0)
	{
		delete topMenuBar;
		topMenuBar = 0x0;
	}

	if (typingField != 0x0)
	{
		delete typingField;
		typingField = 0x0;
	}

	if (TopMenuBar::globalInstance != 0x0)
	{
		delete TopMenuBar::globalInstance;
		TopMenuBar::globalInstance = 0x0;
	}
}

MainWindow::MainWindow()
{
	window = nullptr;
	messageField = new MessageField();
	topMenuBar = new TopMenuBar();
	typingField = new TypingField();
}