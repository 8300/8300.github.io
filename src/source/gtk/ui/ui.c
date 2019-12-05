#include <gtk/gtk.h>
static void print_hello(GtkWidget *widget, gpointer data)
{
	g_print("Hello Work\n");
}
int main(int argc, char *argv[])
{
	GtkBuilder *builder;
	GtkWidget *window;
	GtkWidget *box;
	GError *error = NULL;

	gtk_init(&argc, &argv);
	builder = gtk_builder_new();
	if (gtk_builder_add_from_file (builder, "builder.ui", &error) == 0) {
		g_printerr ("Error loading file: %s\n", error->message);
		g_clear_error (&error);
		return 1;
	}

	box = GTK_WIDGET(gtk_builder_get_object(builder, "box_sub"));
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_container_add (GTK_CONTAINER (window), box);

	gtk_widget_show_all(window);
	gtk_main();

	return 0;
}
