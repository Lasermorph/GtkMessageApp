#include "../include/MtkScrolledWindow.h"

MtkScrolledWindow::MtkScrolledWindow()
{
	m_scrolledWindow = gtk_scrolled_window_new();
}

void MtkScrolledWindow::SetChild(GtkWidget* const& widget)
{
	gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(m_scrolledWindow), widget);
}

GtkWidget* MtkScrolledWindow::AsGtkWidget()
{
	return m_scrolledWindow;
}