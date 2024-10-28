#include "../include/MtkTextView.h"

MtkTextView::MtkTextView()
{
	m_textView = gtk_text_view_new();
	m_textBuffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(m_textView));
}

MtkTextView::MtkTextView(GtkWidget* const& textView)
{
	m_textView = textView;
	m_textBuffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(m_textView));
}

MtkTextView::~MtkTextView() = default;

GtkWidget* MtkTextView::AsGtkWidget()
{
	return m_textView;
}

GtkTextView* MtkTextView::AsGtkTextView()
{
	return GTK_TEXT_VIEW(m_textView);
}

std::string MtkTextView::GetText(bool includeHiddenChars)
{
	// if (m_textBuffer == 0x0)
	// {
	// 	m_textBuffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(m_textView));
	// }
	GtkTextIter start, end;
	gtk_text_buffer_get_bounds(m_textBuffer, &start, &end);
	m_text = gtk_text_buffer_get_text(m_textBuffer, &start, &end, includeHiddenChars);
	return m_text;
}

GtkTextBuffer* MtkTextView::GetBuffer()
{
	return m_textBuffer;
}

void MtkTextView::SetText(std::string text)
{
	// if (m_textBuffer == 0x0)
	// {
	// 	m_textBuffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(m_textView));
	// }
	gtk_text_buffer_set_text(m_textBuffer, text.c_str(), text.size());
}

void MtkTextView::Delete()
{
	GtkTextIter start, end;
	gtk_text_buffer_get_bounds(m_textBuffer, &start, &end);
	gtk_text_buffer_delete(m_textBuffer, &start, &end);
}