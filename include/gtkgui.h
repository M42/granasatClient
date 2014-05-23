/**
 * gtkgui.h
 * granaSAT.Client
 *
 *  Created on: May 17, 2014
 *      Author: Mario Román
 */

// Avoids redefinition
#ifndef GTKGUI_H
#define GTKGUI_H

#include <gtk/gtk.h>
#include "gtkwidgets.h"

#define FILEGLADE "glade/design.glade"

static GtkBuilder* builder;

/**
 * Initializes GTK-GUI.
 * @param argc Number of arguments.
 * @param argv Arguments.
 */
void gtk_initialize (int argc, char* argv[]);

/**
 * Initializes GTK builder.
 */
 void gtk_builder_initialize ();

#endif
