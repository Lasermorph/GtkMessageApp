#pragma once
#include <gtk/gtk.h>
#include <iostream>

class MtkTextView
{
	public:
		MtkTextView();
		MtkTextView(GtkWidget* const& textView);
		~MtkTextView();

		GtkWidget* AsGtkWidget();
		GtkTextView* AsGtkTextView();
		std::string GetText(bool includeHiddenChars);
		GtkTextBuffer* GetBuffer();
		void SetText(std::string text);
		void Delete();

	private:
		GtkWidget* m_textView = 0x0;
		std::string m_text = "";
		GtkTextBuffer* m_textBuffer = 0x0;
};