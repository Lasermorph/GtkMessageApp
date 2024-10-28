#pragma once
#include <gtk/gtk.h>

class MtkScrolledWindow
{
	public:
		MtkScrolledWindow();
		~MtkScrolledWindow() = default;

		void SetChild(auto& widget);
		void SetChild(GtkWidget* const& widget);

		GtkWidget* AsGtkWidget();

	private:
		GtkWidget* m_scrolledWindow = 0x0;
};

void MtkScrolledWindow::SetChild(auto& widget)
{
	gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(m_scrolledWindow), widget.AsGtkWidget());
}