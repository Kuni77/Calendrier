#include "projet.h"

int main (int argc, char *argv[])
{
    const gchar* titre;

    GError **errrrr=NULL;
    GdkColor couleur;
    GtkWidget* Ma_fenetre;
    SYSTEMTIME temps;
    GetLocalTime(&temps);
    gtk_init(&argc,&argv);
    Ma_fenetre=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(Ma_fenetre),"calendrier");
    gtk_window_set_default_size(GTK_WINDOW(Ma_fenetre),100,100);
    gtk_window_set_position(GTK_WINDOW(Ma_fenetre),GTK_WIN_POS_MOUSE);
    gtk_window_set_icon_from_file(GTK_WINDOW(Ma_fenetre),"cal1.jpg",errrrr);
    g_signal_connect(G_OBJECT(Ma_fenetre),"destroy",G_CALLBACK(Gtkquit),NULL);

    couleur.pixel=40;
    couleur.green=30000;
    couleur.red=30000;
    couleur.blue=30000;
      //gdk_color_parse("indigo",&couleur);
                  
    gtk_widget_modify_bg(GTK_WIDGET(Ma_fenetre),GTK_STATE_NORMAL,&couleur);

    Affiche(temps.wMonth,temps.wYear,Ma_fenetre);


    gtk_widget_show_all(Ma_fenetre);
    gtk_main();
    return 0;
}

