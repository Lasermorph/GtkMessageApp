#pragma once
#include <gtk/gtk.h>
#include <iostream>
#include <map>
#include <vector>

class MtkBox
{
	public:
		MtkBox(GtkOrientation orientation, int spacing);
		~MtkBox();

		void Add(auto& widget, const int sequenceNumber);
		void Add(GtkWidget* const& widget, const int sequenceNumber);

		void Append(auto& widget);
		void Append(GtkWidget* const& widget);

		void Prepend(auto& widget);
		void Prepend(GtkWidget* const& widget);
		GtkWidget* AsGtkWidget();
		GtkBox* AsGtkBox();

	private:
		GtkWidget* m_box = 0x0;
		std::map<const int, GtkWidget*> m_map;
};

void MtkBox::Add(auto& widget, const int sequenceNumber)
{
	std::vector<int> gamer = std::vector<int>(2,2);
	for (size_t i = 0; i < gamer.size(); i++) 
	{
		
	}
	int prevKey = 0;
	GtkWidget* prevWidget = 0x0;

	int maxKey = 0;

	for (auto const& [key, val] : m_map)
	{
		maxKey = key;
	}

	if (sequenceNumber < 1)
	{
		std::string error = "MtkBox::Add sequenceNumber must be at least 1: given sequenceNumber: " + std::to_string(sequenceNumber) + \
		(std::string)" Button label: " + gtk_button_get_label(GTK_BUTTON(widget.AsGtkWidget()));
		throw std::invalid_argument(error);
	}

	if (m_map.end()->first != 0)
	{
		for (auto const& [key, currentWidget] : m_map)
		{
			if (sequenceNumber > maxKey)
			{
				gtk_box_append(GTK_BOX(m_box), widget.AsGtkWidget());
				break;
			}
			if (sequenceNumber > prevKey && sequenceNumber < key)
			{
				gtk_box_insert_child_after(GTK_BOX(m_box), widget.AsGtkWidget(), prevWidget);
				break;
			}
			if (sequenceNumber == key)
			{
				gtk_box_insert_child_after(GTK_BOX(m_box), widget.AsGtkWidget(), currentWidget);
				break;
			}

			prevKey = key;
			prevWidget = currentWidget;
		}
	}
	else
	{
		gtk_box_append(GTK_BOX(m_box), widget.AsGtkWidget());
	}

	m_map[sequenceNumber] = widget.AsGtkWidget();

}

void MtkBox::Append(auto& widget)
{
	gtk_box_append(GTK_BOX(m_box), widget.AsGtkWidget());
}

void MtkBox::Prepend(auto& widget)
{
	gtk_box_prepend(GTK_BOX(m_box), widget.AsGtkWidget());
}
