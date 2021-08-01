
#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <ctype.h>
#include <libpq-fe.h>

typedef struct 
{
	int annee_cour;
	int jour_cour;
	int mois_cour;
	char mes[300];
	GtkWidget *fenetre;
	GtkWidget *tab;
	GtkWidget* bo1;
}Date;
static GtkWidget *vbox,*bot[56],*table=NULL,*labeld;

static int year,lewrou;

static int s;

static gchar *jour[7]={"Lun","Mar","Mer","Jeu","Ven","Sam","Dim"},b[2],annees[4];

static gchar *Month[12]={"Janvier","Fevrier","Mars","Avril","Mai","Juin","Juillet","Aout","Septembre","Octobre","Novembre","Decembre"};

int Bissextile(int );

void Information( Date *);


int Nombre_De_Jour_Par_Mois(int ,int );

int Annee_sup(int ,int ,int );

int Annee_inf(int ,int ,int );

int Trouver_Jour(int ,int ,int );

void Gtkquit(GtkWidget* , gpointer );

void Ajouter_Bouton(GtkWidget* );

GtkWidget* Creer_Boutton(gchar*);

void Suivant(GtkWidget* ,gpointer );

int Nombre_Jour_Precedent(int ,int ,int );

void Affiche(int ,int ,GtkWidget* );

void Creer_Attache(GtkWidget *,GtkWidget* ,gint ,gint ,gint ,gint );

void precedent(GtkWidget *,gpointer );

void Evenement(GtkWidget* ,gpointer );

void Tous_Les_Mois(GtkWidget* ,gpointer );

void Affiche1(GtkWidget* ,gpointer );

void Recherche_Date(GtkWidget* ,gpointer );

int pentecote(int ,int*);

int ascension(int ,int* );

int careme(int ,int*);

int Tabaski_Sup(int ,int *);

int Tabaski_Inf(int ,int *);

int Tabaski(int ,int *);

int korite(int ,int*);

int paque(int ,int *);

void Aujour(GtkWidget* ,gpointer );

int Ramadan(int ,int*);

int toggled_func(GtkWidget* , gpointer );

int insertion_bd(PGconn *,Date*,int ,short ,short ,const char *,const char* ,char *,char *,int ,short ,short ,const char *,int freq );

void reponse_bd(PGconn *,Date*);

void Affiche_Eve(GtkWidget* ,gpointer );

void supprimer_ligne(PGconn *,int );

void Supprimer_bd(GtkWidget* ,gpointer );

void Voir_bd(GtkWidget* boutton,gpointer data);

int Recuperer_Freq (GtkWidget * );

void cb_remove (GtkWidget * , gpointer ); 

void Modifier_bd(GtkWidget* ,gpointer );

void Affiche2(GtkWidget* ,gpointer );