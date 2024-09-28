#include "MainWindow.h"
#include <adwaita.h>

MainWindow::MainWindow(GtkApplication* app)
{
	// Create a new window
	window = gtk_application_window_new(app);
	headerBar = gtk_header_bar_new();
	GtkWidget* headerBarTest = adw_header_bar_new();
	gtk_window_set_default_size(GTK_WINDOW(window), 500, 300);
	gtk_window_set_title(GTK_WINDOW(window), "We made an app");
	gtk_window_set_titlebar(GTK_WINDOW(window),headerBar);

	TopMenu::globalInstance = new TopMenu(app);
	TypingField::globalInstance = new TypingField();
	MessageField::globalInstance = new MessageField();
	FriendsList::globalInstance = new FriendsList();
	Hotkeys::globalInstance = new Hotkeys(window, app);

	GtkWidget* testingSplitView = adw_navigation_split_view_new();

	//Containers for the widget placements
	messagesAndTypingFiled = gtk_box_new(GtkOrientation::GTK_ORIENTATION_VERTICAL, 0);

	// // When the button is clicked, close the window passed as an argument
	// g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_window_close), window);

		// Fix
			// GtkCssProvider* cssProvider = gtk_css_provider_new();

			// gtk_css_provider_load_from_string(cssProvider, ".test { color: #A52A2A; }");

			// gtk_style_context_add_provider_for_display(gtk_widget_get_display(window), /*GTK_STYLE_PROVIDER(cssProvider)*/(GtkStyleProvider *)cssProvider, GTK_STYLE_PROVIDER_PRIORITY_USER);

			// gtk_widget_add_css_class(TypingField::globalInstance->Create(), "test");

	// gtk_style_context_set_display()

	gtk_header_bar_pack_start(GTK_HEADER_BAR(headerBar), TopMenu::globalInstance->Create());

	gtk_application_set_menubar(app, G_MENU_MODEL(TopMenu::globalInstance->TopMenuBarCreate(app)));
	gtk_application_window_set_show_menubar(GTK_APPLICATION_WINDOW(window), true);

	gtk_box_append(GTK_BOX(messagesAndTypingFiled), MessageField::globalInstance->Create());
	gtk_box_append(GTK_BOX(messagesAndTypingFiled), TypingField::globalInstance->Create());

	AdwNavigationPage* testingNavigationPage = adw_navigation_page_new(FriendsList::globalInstance->Create(), "MainSideMenu");
	AdwNavigationPage* testingNavigationContent = adw_navigation_page_new(messagesAndTypingFiled, "MainContent");
	adw_navigation_split_view_set_sidebar(ADW_NAVIGATION_SPLIT_VIEW(testingSplitView), testingNavigationPage);
	adw_navigation_split_view_set_content(ADW_NAVIGATION_SPLIT_VIEW(testingSplitView), testingNavigationContent);

	gtk_window_set_child(GTK_WINDOW(window), testingSplitView);
	// gtk_widget_set_size_request(window, 1000, 200);
	gtk_window_present(GTK_WINDOW(window));
}

MainWindow::~MainWindow()
{
	if (TopMenu::globalInstance != 0x0)
	{
		delete TopMenu::globalInstance;
		TopMenu::globalInstance = 0x0;
	}	

	// if (window != 0x0)
	// {
	// 	gtk_window_destroy(GTK_WINDOW(window));
	// }
	
	if (TypingField::globalInstance != 0x0)
	{
		delete TypingField::globalInstance;
		TypingField::globalInstance = 0x0;
	}

	if (MessageField::globalInstance != 0x0)
	{
		delete MessageField::globalInstance;
		MessageField::globalInstance = 0x0;
	}

	if (Hotkeys::globalInstance != 0x0)
	{
		delete Hotkeys::globalInstance;
		Hotkeys::globalInstance = 0x0;
	}

	if (FriendsList::globalInstance != 0x0)
	{
		delete FriendsList::globalInstance;
		FriendsList::globalInstance = 0x0;
	}
}