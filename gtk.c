#include "projet.h"

void Gtkquit(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}



GtkWidget* Creer_Boutton(gchar *i)
{
    GtkWidget *button;
    button=gtk_button_new_with_label(i);
    gtk_button_set_relief(GTK_BUTTON(button),GTK_RELIEF_NONE);
    return button;
}



void precedent(GtkWidget *widget,gpointer data)
{
     gtk_widget_destroy(GTK_WIDGET(table));
     int cur,bv=1,jj,k,compt,c=0,i,joures,bvi=0,j;
     gchar ba[2];
     if(lewrou==1)
        {
            year--;
            lewrou=13;
        }
     lewrou--;
     Affiche(lewrou,year,data);
}




void Suivant(GtkWidget *widget,gpointer data)
{
     gtk_widget_destroy(GTK_WIDGET(table));
     int cur,bv=1,jj,k,compt,c=0,i,joures,bvi=0,j;
     gchar ba[2];
     if(lewrou==12)
        {
            year++;
            lewrou=0;
        }
     lewrou++;

     Affiche(lewrou,year,data);

}

void Affiche(int mois,int annee,GtkWidget* Ma_fenetre)
{
  
    Date *rv[60];
    Date *f=(Date*)malloc(sizeof(Date));
    int jj,joures,c=0,bv,bvi=0,j,k,l,m,i,compt,cur,av=0,de=10;
    GtkWidget* entree;
    gchar* tampon;
    Date da;
    GtkWidget *label,*n;
    SYSTEMTIME times;
    GetLocalTime(&times);
    table=gtk_table_new(12,8,TRUE);
    GdkColor col,col1;
    for(j=0;j<60;j++)
        rv[j]=(Date*)malloc(sizeof(Date));
    entree=gtk_entry_new_with_max_length(11);
    gtk_entry_set_text(GTK_ENTRY(entree)," jj-mm-an");
    Creer_Attache(table,entree,5,7,0,1);
    
    gtk_container_add(GTK_CONTAINER(Ma_fenetre),GTK_WIDGET(table));
    label=gtk_label_new(NULL);

    bot[0]=Creer_Boutton("<");
    Creer_Attache(table,bot[0],0,1,0,1);
    bot[52]=Creer_Boutton("Evenement");
    Creer_Attache(table,bot[52],7,8,0,1);
    bot[1]=Creer_Boutton(Month[mois-1]);
    Creer_Attache(table,bot[1],1,2,0,1);
    bot[2]=Creer_Boutton(">");

    Creer_Attache(table,bot[2],3,4,0,1);

    sprintf(annees,"%d",annee);
    bot[3]=Creer_Boutton(annees);
    Creer_Attache(table,bot[3],2,3,0,1);
    labeld=gtk_label_new(NULL);
    Creer_Attache(table,labeld,0,7,1,2);
    bot[4]=Creer_Boutton("Aujourd'hui");
    Creer_Attache(table,bot[4],4,5,0,1);
    for(j=0;j<7;j++)
    {

        if((j!=5) && (j!=6))
             label=gtk_label_new(jour[j]);
        else
        {
                tampon=g_strdup_printf("<span color=\"#FFFFFF\">""%s""</span>",jour[j]);
                label=gtk_label_new(tampon);
                gtk_label_set_markup(GTK_LABEL(label),tampon);
        }

        Creer_Attache(table,label,j,j+1,2,3);

    }
    g_free(tampon);
    l=m=k=5;
    joures=Nombre_De_Jour_Par_Mois(annee,mois);
    printf("\n%d",joures);
    bv=jj=Trouver_Jour(1,mois,annee);
    while(c<joures+1)
    {
        for(j=3;j<=8;j++)
        {

            for(i=0;i<7;i++)
            {
                if(jj==i)
                {
                    jj=-1;
                    c=1;
                }
                if(((c>0)&&(c<=joures)))

                {
                   m=k+1;
                     if((c==times.wDay)&&(mois==times.wMonth)&&(annee==times.wYear))
                    {

                        sprintf(b,"%2d",c);
                        c++;
                         bot[k]=gtk_button_new_with_label(b);
                         gdk_color_parse("dodgerblue",&col);
                        gtk_widget_modify_bg(GTK_WIDGET(bot[k]),GTK_STATE_NORMAL,&col);
                        Creer_Attache(table,bot[k],i,i+1,j,j+1);
                         k++;
                    }
                    else
                        {

                           da.jour_cour=pentecote(annee ,&(da.mois_cour));
                          // printf("\n%d %d",da.jour_cour, da.mois_cour);
                           if((c==da.jour_cour)&&(da.mois_cour==mois))
                           {
                              sprintf(b,"%2d",c);
                              c++;
                              bot[k]=gtk_button_new_with_label(b);
                              gdk_color_parse("steelblue",&col);
                              gtk_widget_modify_bg(GTK_WIDGET(bot[k]),GTK_STATE_NORMAL,&col);
                              Creer_Attache(table,bot[k],i,i+1,j,j+1);
                               if(av>=7)
                              {
                                av=0;
                                de++;
                              }
                              tampon=g_strdup_printf("%d.pentecote",da.jour_cour);
                             // gtk_label_set_text(GTK_LABEL(label),tampon);
                              label=gtk_label_new(tampon);
                               Creer_Attache(table,label,av,av+1,de,de+1);
                               g_free(tampon);
                               av++;
                                k++;
                                continue;
                               //printf("%d\n",av );
                           }
                           //else
                           da.jour_cour=ascension(annee ,&(da.mois_cour));
                           if((c==da.jour_cour)&&(da.mois_cour==mois))
                           {
                              sprintf(b,"%2d",c);
                              c++;
                              bot[k]=gtk_button_new_with_label(b);
                              gdk_color_parse("steelblue",&col);
                              gtk_widget_modify_bg(GTK_WIDGET(bot[k]),GTK_STATE_NORMAL,&col);
                              Creer_Attache(table,bot[k],i,i+1,j,j+1);
                              if(av>=7)
                              {
                                av=0;
                                de++;
                              }
                              tampon=g_strdup_printf("%d.ascension",da.jour_cour);
                              label=gtk_label_new(tampon);
                               Creer_Attache(table,label,av,av+1,de,de+1);
                               g_free(tampon);
                               av++;
                                k++;
                                continue;
                             }
                           //else
                           da.jour_cour=careme(annee ,&(da.mois_cour));
                           if((c==da.jour_cour)&&(da.mois_cour==mois))
                           {
                              sprintf(b,"%2d",c);
                              c++;
                              bot[k]=gtk_button_new_with_label(b);
                              gdk_color_parse("steelblue",&col);
                              gtk_widget_modify_bg(GTK_WIDGET(bot[k]),GTK_STATE_NORMAL,&col);
                              Creer_Attache(table,bot[k],i,i+1,j,j+1);
                               if(av>=7)
                              {
                                av=0;
                                de++;
                              }
                              tampon=g_strdup_printf("%d.careme",da.jour_cour);
                              label=gtk_label_new(tampon);
                               Creer_Attache(table,label,av,av+1,de,de+1);
                               g_free(tampon);
                               av++;
                                k++;
                                continue;
                           }
                           //else
                           da.jour_cour=Tabaski(annee ,&(da.mois_cour));
                           if((c==da.jour_cour)&&(da.mois_cour==mois))
                           {
                              sprintf(b,"%2d",c);
                              c++;
                              bot[k]=gtk_button_new_with_label(b);
                              gdk_color_parse("steelblue",&col);
                              gtk_widget_modify_bg(GTK_WIDGET(bot[k]),GTK_STATE_NORMAL,&col);
                              Creer_Attache(table,bot[k],i,i+1,j,j+1);
                               if(av>=7)
                              {
                                av=0;
                                de++;
                              }
                              tampon=g_strdup_printf("%d.Tabaski",da.jour_cour);
                               label=gtk_label_new(tampon);
                               Creer_Attache(table,label,av,av+1,de,de+1);
                               g_free(tampon);
                               av++;
                                k++;
                                continue;
                           } 
                           //else
                            da.jour_cour=korite(annee ,&(da.mois_cour));
                           if((c==da.jour_cour)&&(da.mois_cour==mois))
                           {
                              sprintf(b,"%2d",c);
                              c++;
                              bot[k]=gtk_button_new_with_label(b);
                              gdk_color_parse("steelblue",&col);
                              gtk_widget_modify_bg(GTK_WIDGET(bot[k]),GTK_STATE_NORMAL,&col);
                              Creer_Attache(table,bot[k],i,i+1,j,j+1);
                               if(av>=7)
                              {
                                av=0;
                                de++;
                              }
                              tampon=g_strdup_printf("%d.korite",da.jour_cour);
                              label=gtk_label_new(tampon);
                               Creer_Attache(table,label,av,av+1,de,de+1);
                               g_free(tampon);
                               av++;
                                k++;
                                continue;
                           }
                            //else
                            da.jour_cour=Ramadan(annee ,&(da.mois_cour));
                           if((c==da.jour_cour)&&(da.mois_cour==mois))
                           {
                              sprintf(b,"%2d",c);
                              c++;
                              bot[k]=gtk_button_new_with_label(b);
                              gdk_color_parse("steelblue",&col);
                              gtk_widget_modify_bg(GTK_WIDGET(bot[k]),GTK_STATE_NORMAL,&col);
                              Creer_Attache(table,bot[k],i,i+1,j,j+1);
                               if(av>=7)
                              {
                                av=0;
                                de++;
                              }
                              tampon=g_strdup_printf("%d.Ramadan",da.jour_cour);
                               label=gtk_label_new(tampon);
                               Creer_Attache(table,label,av,av+1,de,de+1);
                               g_free(tampon);
                               av++;
                                k++;
                                continue;
                           }
                           //else
                            da.jour_cour=paque(annee ,&(da.mois_cour));
                           if((c==da.jour_cour)&&(da.mois_cour==mois))
                           {
                              sprintf(b,"%2d",c);
                              c++;
                              bot[k]=gtk_button_new_with_label(b);
                              gdk_color_parse("steelblue",&col);
                              gtk_widget_modify_bg(GTK_WIDGET(bot[k]),GTK_STATE_NORMAL,&col);
                              Creer_Attache(table,bot[k],i,i+1,j,j+1);
                               if(av>=7)
                              {
                                av=0;
                                de++;
                              }
                              tampon=g_strdup_printf("%d.paque",da.jour_cour);
                               label=gtk_label_new(tampon);
                               Creer_Attache(table,label,av,av+1,de,de+1);
                               g_free(tampon);
                               av++;
                                k++;
                                continue;
                           }
                           //else
                           if((c==25)&&(mois==12))
                           {
                              sprintf(b,"%2d",c);
                              c++;
                              bot[k]=gtk_button_new_with_label(b);
                              gdk_color_parse("steelblue",&col);
                              gtk_widget_modify_bg(GTK_WIDGET(bot[k]),GTK_STATE_NORMAL,&col);
                              Creer_Attache(table,bot[k],i,i+1,j,j+1);
                               if(av>=7)
                              {
                                av=0;
                                de++;
                              }
                              tampon=g_strdup_printf("25.Noel");
                               label=gtk_label_new(tampon);
                               Creer_Attache(table,label,av,av+1,de,de+1);
                               g_free(tampon);
                               av++;
                                k++;
                                continue;
                           }
                           //else
                            if((c==31)&&(mois==12))
                           {
                              sprintf(b,"%2d",c);
                              c++;
                              bot[k]=gtk_button_new_with_label(b);
                              gdk_color_parse("steelblue",&col);
                              gtk_widget_modify_bg(GTK_WIDGET(bot[k]),GTK_STATE_NORMAL,&col);
                              Creer_Attache(table,bot[k],i,i+1,j,j+1);
                               if(av>=7)
                              {
                                av=0;
                                de++;
                              }
                              tampon=g_strdup_printf("31.Fin d'annee");
                              label=gtk_label_new(tampon);
                               Creer_Attache(table,label,av,av+1,de,de+1);
                               g_free(tampon);
                               av++;
                                k++;
                                continue;
                           }
                           //else
                            if((c==1)&&(mois==5))
                           {
                              sprintf(b,"%2d",c);
                              c++;
                              bot[k]=gtk_button_new_with_label(b);
                              gdk_color_parse("steelblue",&col);
                              gtk_widget_modify_bg(GTK_WIDGET(bot[k]),GTK_STATE_NORMAL,&col);
                              Creer_Attache(table,bot[k],i,i+1,j,j+1);
                               if(av>=7)
                              {
                                av=0;
                                de++;
                              }
                              tampon=g_strdup_printf("1.Fete du travail");
                              label=gtk_label_new(tampon);
                               Creer_Attache(table,label,av,av+1,de,de+1);
                               g_free(tampon);
                               av++;
                                k++;
                                continue;
                           }
                           //else
                            if((c==1)&&(mois==1))
                           {
                              sprintf(b,"%2d",c);
                              c++;
                              bot[k]=gtk_button_new_with_label(b);
                              gdk_color_parse("steelblue",&col);
                              gtk_widget_modify_bg(GTK_WIDGET(bot[k]),GTK_STATE_NORMAL,&col);
                              Creer_Attache(table,bot[k],i,i+1,j,j+1);
                               if(av>=7)
                              {
                                av=0;
                                de++;
                              }
                              tampon=g_strdup_printf("1.jour de l'an");
                              label=gtk_label_new(tampon);
                               Creer_Attache(table,label,av,av+1,de,de+1);
                               g_free(tampon);
                               av++;
                                k++;
                                continue;
                           }
                            //else
                            if((c==4)&&(mois==4))
                           {
                              sprintf(b,"%2d",c);
                              c++;
                              bot[k]=gtk_button_new_with_label(b);
                              gdk_color_parse("steelblue",&col);
                              gtk_widget_modify_bg(GTK_WIDGET(bot[k]),GTK_STATE_NORMAL,&col);
                              Creer_Attache(table,bot[k],i,i+1,j,j+1);
                               if(av>=7)
                              {
                                av=0;
                                de++;
                              }
                              tampon=g_strdup_printf("4.Fete National");
                              label=gtk_label_new(tampon);
                               Creer_Attache(table,label,av,av+1,de,de+1);
                               g_free(tampon);
                               av++;
                                k++;
                                continue;
                           }
                           //else{
                            sprintf(b,"%2d",c);
                            c++;
                            bot[k]=Creer_Boutton(b);
                            Creer_Attache(table,bot[k],i,i+1,j,j+1);
                               k++;
                         // }
                        }

                }
               else
                    if(c==0)
                {
                     bv--;
                    compt=Nombre_Jour_Precedent(mois,annee,bv);
                    sprintf(b,"%2d",compt);
                    bot[l]=gtk_button_new_with_label(b);
                    gdk_color_parse("grey",&col1);
                    gtk_widget_modify_fg(GTK_WIDGET(bot[k]),GTK_STATE_NORMAL,&col1);
                    Creer_Attache(table,bot[l],i,i+1,j,j+1);
                    l++;
                    k=l;
                }
                else
                    if(c>joures)
                {
                    bvi++;
                    cur=bvi;
                    sprintf(b,"%2d",cur);
                     bot[m]=gtk_button_new_with_label(b);
                    gdk_color_parse("grey",&col1);
                    gtk_widget_modify_fg(GTK_WIDGET(bot[k]),GTK_STATE_NORMAL,&col1);
                     Creer_Attache(table,bot[m],i,i+1,j,j+1);
                     m++;
                }
                
               
            }

        }
    }
    year=annee;
    lewrou=mois;
    g_signal_connect(G_OBJECT(entree),"activate",G_CALLBACK(Recherche_Date),Ma_fenetre);
    if(annee<32000)
        g_signal_connect(G_OBJECT(bot[2]),"clicked",G_CALLBACK(Suivant),Ma_fenetre);
    if(annee>1)
        g_signal_connect(G_OBJECT(bot[0]),"clicked",G_CALLBACK(precedent),Ma_fenetre);
    g_signal_connect(G_OBJECT(bot[1]),"clicked",G_CALLBACK(Tous_Les_Mois),Ma_fenetre);
    g_signal_connect(G_OBJECT(bot[4]),"clicked",G_CALLBACK(Aujour),Ma_fenetre);
    for(i=5;i<l;i++)
        g_signal_connect(G_OBJECT(bot[i]),"clicked",G_CALLBACK(precedent),Ma_fenetre);
    for(i=k;i<m;i++)
        g_signal_connect(G_OBJECT(bot[i]),"clicked",G_CALLBACK(Suivant),Ma_fenetre);
           
       for(i=l;i<k;i++)
       {
        rv[i-l]->annee_cour=year;
        rv[i-l]->mois_cour=lewrou;
        rv[i-l]->jour_cour=i-l+1;
        rv[i-l]->fenetre=Ma_fenetre;
         g_signal_connect(G_OBJECT(bot[i]),"clicked",G_CALLBACK(Evenement),(gpointer )rv[i-l]);
       }
        f->annee_cour=year;
        f->mois_cour=lewrou;
        f->fenetre=Ma_fenetre;
        f->tab=table;
       g_signal_connect(G_OBJECT(bot[52]),"clicked",G_CALLBACK(Affiche_Eve),(gpointer )f);
        gtk_widget_show_all(Ma_fenetre);
}




void Aujour(GtkWidget* boutton,gpointer data)
{
    gtk_widget_destroy(GTK_WIDGET(table));
    SYSTEMTIME temps;
    GetLocalTime(&temps);
    Affiche(temps.wMonth,temps.wYear,data);
}

void Creer_Attache(GtkWidget *table,GtkWidget *button,gint x,gint y,gint z,gint k)
{
    gtk_table_attach(GTK_TABLE(table),button,x,y,z,k,GTK_EXPAND,GTK_EXPAND,0,0);
}


void Evenement(GtkWidget* boutton,gpointer data)
{

   GtkWidget* frame,*boite,*entry,*entry1,*entry2,*entry4,*entry3,*separateur,*vboxframe,*label,*label1[10];
    GtkAdjustment *ad;
    int i,c,t[10];
    char even[10][50];
    char bing[3][4];
    Date *rec=data;
    GtkWidget * p_combo     = NULL;  
    c=rec->jour_cour;
    GtkWidget *hbox,*hbox1,*hbox2,*hbox3;
    SYSTEMTIME temps;
    GetLocalTime(&temps);
    boite=gtk_dialog_new_with_buttons("Evenement",GTK_WINDOW(rec->fenetre),GTK_DIALOG_MODAL,GTK_STOCK_OK,GTK_RESPONSE_OK,GTK_STOCK_CANCEL,GTK_RESPONSE_CANCEL,NULL);
    vboxframe=gtk_vbox_new(TRUE,0);
    hbox=gtk_hbox_new(TRUE,0);
    hbox1=gtk_hbox_new(TRUE,0);
    hbox2=gtk_hbox_new(TRUE,0);
    hbox3=gtk_hbox_new(TRUE,0); 
    frame=gtk_frame_new("evenement");
    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(boite)->vbox),frame,TRUE,FALSE,0);
    gtk_container_add(GTK_CONTAINER(frame),vboxframe);
    label=gtk_label_new("Nom Evenement");
    gtk_box_pack_start(GTK_BOX(vboxframe),label,TRUE,FALSE,0);
    entry= gtk_entry_new_with_max_length(25);
    gtk_entry_set_text(GTK_ENTRY(entry)," nom evenement");
    gtk_box_pack_start(GTK_BOX(vboxframe),entry,TRUE,FALSE,0);
    label=gtk_label_new("Date de debut jj-mm-an");
    gtk_box_pack_start(GTK_BOX(vboxframe),label,TRUE,FALSE,0);
    gtk_container_add(GTK_CONTAINER(vboxframe),hbox);
    ad=gtk_adjustment_new(c,1,31,1,1,0);
    label1[0]=gtk_spin_button_new(ad,1,0);     
    gtk_box_pack_start(GTK_BOX(hbox),label1[0],TRUE,FALSE,0);

    ad=gtk_adjustment_new(rec->mois_cour,1,12,1,1,0);
    label1[1]=gtk_spin_button_new(ad,1,0);     
    gtk_box_pack_start(GTK_BOX(hbox),label1[1],TRUE,FALSE,0);

    ad=gtk_adjustment_new(rec->annee_cour,1,32000,1,1,0);
    label1[2]=gtk_spin_button_new(ad,1,0);     
    gtk_box_pack_start(GTK_BOX(hbox),label1[2],TRUE,FALSE,0);


    label=gtk_label_new("heure de debut hh:mm");
    gtk_box_pack_start(GTK_BOX(vboxframe),label,TRUE,FALSE,0);
    gtk_container_add(GTK_CONTAINER(vboxframe),hbox1);
    ad=gtk_adjustment_new(temps.wHour,1,23,1,1,0);
    label1[3]=gtk_spin_button_new(ad,1,0);     
    gtk_box_pack_start(GTK_BOX(hbox1),label1[3],TRUE,FALSE,0);

    ad=gtk_adjustment_new(temps.wMinute,0,59,1,1,0);
    label1[4]=gtk_spin_button_new(ad,1,0);     
    gtk_box_pack_start(GTK_BOX(hbox1),label1[4],TRUE,FALSE,0);
    label=gtk_label_new("Date de Fin jj-mm-an");
    gtk_box_pack_start(GTK_BOX(vboxframe),label,TRUE,FALSE,0);
    gtk_container_add(GTK_CONTAINER(vboxframe),hbox2);
    ad=gtk_adjustment_new(c,1,31,1,1,0);
    label1[5]=gtk_spin_button_new(ad,1,0);     
    gtk_box_pack_start(GTK_BOX(hbox2),label1[5],TRUE,FALSE,0);

    ad=gtk_adjustment_new(rec->mois_cour,1,12,1,1,0);
    label1[6]=gtk_spin_button_new(ad,1,0);     
    gtk_box_pack_start(GTK_BOX(hbox2),label1[6],TRUE,FALSE,0);

    ad=gtk_adjustment_new(rec->annee_cour,1,32000,1,1,0);
    label1[7]=gtk_spin_button_new(ad,1,0);     
    gtk_box_pack_start(GTK_BOX(hbox2),label1[7],TRUE,FALSE,0);
    label=gtk_label_new("heure de Fin hh:mm");
    gtk_box_pack_start(GTK_BOX(vboxframe),label,TRUE,FALSE,0);
    gtk_container_add(GTK_CONTAINER(vboxframe),hbox3);
    ad=gtk_adjustment_new(temps.wHour+1,1,23,1,1,0);
    label1[8]=gtk_spin_button_new(ad,1,0);     
    gtk_box_pack_start(GTK_BOX(hbox3),label1[8],TRUE,FALSE,0);

    ad=gtk_adjustment_new(temps.wMinute,0,59,1,1,0);
    label1[9]=gtk_spin_button_new(ad,1,0);     
    gtk_box_pack_start(GTK_BOX(hbox3),label1[9],TRUE,FALSE,0);
     
        
    label=gtk_label_new("Lieu");
    gtk_box_pack_start(GTK_BOX(vboxframe),label,TRUE,FALSE,0);
    entry3=gtk_entry_new_with_max_length(15);
    gtk_entry_set_text(GTK_ENTRY(entry3),"Lieu");
    gtk_box_pack_start(GTK_BOX(vboxframe),entry3,TRUE,FALSE,0);
    label=gtk_label_new("Description");
    gtk_box_pack_start(GTK_BOX(vboxframe),label,TRUE,FALSE,0);
    entry4=gtk_entry_new_with_max_length(20);
    gtk_entry_set_text(GTK_ENTRY(entry4),"Description");
    gtk_box_pack_start(GTK_BOX(vboxframe),entry4,TRUE,FALSE,0);
    label=gtk_label_new("Frequence");
    gtk_box_pack_start(GTK_BOX(vboxframe),label,TRUE,FALSE,0);
    p_combo = gtk_combo_box_new_text ();
    gtk_box_pack_start(GTK_BOX (vboxframe), p_combo, TRUE, TRUE, 2);        
    gtk_combo_box_append_text  (GTK_COMBO_BOX (p_combo), "Journee entiere");    
    gtk_combo_box_append_text  (GTK_COMBO_BOX (p_combo), "Par semaine");    
    gtk_combo_box_append_text  (GTK_COMBO_BOX (p_combo), "Par mois");    
    gtk_combo_box_prepend_text (GTK_COMBO_BOX (p_combo), "Par annee");    
    gtk_combo_box_set_active (GTK_COMBO_BOX (p_combo), 0);    
    gtk_widget_show_all(GTK_DIALOG(boite)->vbox);
    separateur=gtk_hseparator_new();
    gtk_box_pack_start(GTK_BOX(vboxframe),separateur,TRUE,FALSE,0);
    switch(gtk_dialog_run(GTK_DIALOG(boite)))
    {
        case GTK_RESPONSE_OK: {strcpy(even[0],gtk_entry_get_text(GTK_ENTRY(entry)));
                                strcpy(even[1],gtk_entry_get_text(GTK_ENTRY(entry3)));
                                strcpy(even[2],gtk_entry_get_text(GTK_ENTRY(entry4)));
                                  for(i=0;i<10;i++)
                                    t[i]=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(label1[i]));
                                  if(t[2]>t[7])
                                  {
                                     
                                      strcpy(rec->mes,"ERREUR ANNEE DEBUT SUPERIEUR A ANNEE FIN");
                                      Information( rec);
                                  }
                                   else
                                    if(t[2]==t[7])
                                    if(t[1]>t[6])
                                    {
                                        
                                        strcpy(rec->mes,"ERREUR MOIS DEBUT SUPERIEUR A MOIS FIN");
                                        Information( rec);
                                    }
                                  if(t[1]==t[6])
                                    if(t[0]>t[5])
                                    {
                                        
                                        strcpy(rec->mes,"ERREUR JOUR DEBUT SUPERIEUR A JOUR FIN");
                                        Information( rec);
                                    }
                                      
                                  if(t[3]>t[8])
                                    {
                                        
                                        strcpy(rec->mes,"ERREUR HEURE DEBUT SUPERIEUR A HEURE FIN");
                                        Information( rec);
                                    }
                                  else
                                    if(t[3]==t[8])
                                      if(t[4]>t[9])
                                        {
                                            
                                            strcpy(rec->mes,"ERREUR MINUTE DEBUT SUPERIEUR A MINUTE FIN");
                                            Information( rec);
                                        }
                                         PGconn *dbconn;
                                        dbconn=PQsetdbLogin("localhost","5433","","","projetbd","postgres","kuni");
                                              
                                      if(PQstatus(dbconn)==CONNECTION_BAD)
                                       printf("impossible");
                                          else{
                                              sprintf(even[3],"%d:%d",t[3],t[4]);
                                              sprintf(even[4],"%d:%d",t[8],t[9]);
                                              i=Recuperer_Freq(p_combo);
                                        insertion_bd(dbconn,rec,t[2],t[1],t[0],even[0],even[1],even[3],even[4], t[7],t[6],t[5],even[2],i );
                                        }
                                  
                                break;}
        case GTK_RESPONSE_CANCEL:
        case GTK_RESPONSE_NONE: 
        default: strcpy(rec->mes,"VOUS N'AVEZ RIEN SAISIE");
                                            Information( rec);
        break;

    }
    gtk_widget_destroy(boite);
}


void Information( Date *info)
{
  GtkWidget* var;
  var=gtk_message_dialog_new(GTK_WINDOW(info->fenetre),
    GTK_DIALOG_MODAL,
    GTK_MESSAGE_INFO,
    GTK_BUTTONS_OK,
    info->mes);
  gtk_dialog_run(GTK_DIALOG(var));
  gtk_widget_destroy(var);

}



void Recherche_Date(GtkWidget* entry,gpointer data)
{
 
  int i,mois,annee,jours,k,r=0;
       char even[12],*p;
       gchar *tamp;
       Date *rec=(Date*)malloc(sizeof(Date));
      char bing[3][4];
     strcpy(even,gtk_entry_get_text(GTK_ENTRY(entry)));
      puts(even);
      rec->fenetre=data;
      if((even[2]=='-')||(even[1]=='-'))
      {     
        p=strtok(even,"-");
        for(i=0;p!=NULL;i++)
        {
          strcpy(bing[i],p);
          p=strtok(NULL,"-");
        }
      }
      else
        if((even[2]=='/')||(even[1]=='/'))
        {     
            p=strtok(even,"/");
            for(i=0;p!=NULL;i++)
          {
            strcpy(bing[i],p);
            p=strtok(NULL,"/");
          }
        }
      else
        r=-1;
      
      jours=atoi(bing[0]);
      //printf("%d\n",jours);
      mois=atoi(bing[1]);
    // printf("%d\n",mois);
  
    annee=atoi(bing[2]);
     //printf("%d\n",annee);
 
    k=Trouver_Jour(jours,mois,annee);
    if((k==-1)||(r==-1))
    {       
       strcpy(rec->mes,"ERREUR FORMAT jj-mm-an");
        Information( rec);
    }
     else{
       gtk_widget_destroy(GTK_WIDGET(table));
      tamp=g_strdup_printf("le jour est un %s",jour[k]);
      strcpy(rec->mes,tamp);
     
    Affiche(mois,annee,data);
     Information( rec);
   // gtk_label_set_text(GTK_LABEL(labeld),tamp);
   }
}


void Affiche1(GtkWidget* boutton,gpointer data)
{
    Date *s=(Date*)malloc(sizeof(Date));
    s=data;
   if(s->tab!=NULL)
    {
      gtk_widget_destroy(GTK_WIDGET(s->tab));
      s->tab=NULL;
    }
    Affiche(s->mois_cour,s->annee_cour,s->fenetre);
      gtk_widget_show_all(s->fenetre);
}


void Affiche2(GtkWidget* boutton,gpointer data)
{
    Date *s=(Date*)malloc(sizeof(Date));
    s=data;
    if(s->bo1!=NULL)
    {
      gtk_widget_destroy(s->bo1);
      s->bo1=NULL;
    }
    Affiche(s->mois_cour,s->annee_cour,s->fenetre);
      gtk_widget_show_all(s->fenetre);
}
void Tous_Les_Mois(GtkWidget* boutton,gpointer data)
{
    int i;
     GtkWidget *b[12],*fenetre;
     GdkColor couleur;
     vbox=gtk_vbox_new(TRUE,0);
     gtk_widget_destroy(GTK_WIDGET(table));
      Date *date[12];
      for(i=0;i<12;i++)
      {
        date[i]=(Date*)malloc(sizeof(Date));
         date[i]->bo1=vbox;
        date[i]->fenetre=data;
      }
     gtk_container_add(GTK_CONTAINER(date[0]->fenetre),vbox);
    couleur.pixel=40;
    couleur.green=30000;
    couleur.red=30000;
    couleur.blue=30000;
    gtk_widget_modify_bg(GTK_WIDGET(date[0]->fenetre),GTK_STATE_NORMAL,&couleur);
    for(i=0;i<12;i++)
    {
        b[i]=Creer_Boutton(Month[i]);
        gtk_box_pack_start(GTK_BOX(vbox),b[i],TRUE,FALSE,0);
    }
   for(i=0;i<12;i++)
    {
        date[i]->annee_cour=year;
      date[i]->mois_cour=i+1;
      
         g_signal_connect(G_OBJECT(b[i]),"clicked",G_CALLBACK(Affiche2),date[i]);
    }
   gtk_widget_show_all(date[0]->fenetre);

}


void Affiche_Eve(GtkWidget* boutton,gpointer data)
{
    Date *sur=(Date*)malloc(sizeof(Date));
    sur=data;
  //  printf("\n%d",sur->annee_cour);
      PGconn *dbconn;
      dbconn=PQsetdbLogin("localhost","5433","","","projetbd","postgres","kuni");
    reponse_bd(dbconn,sur);
    gtk_widget_show_all(sur->fenetre);
} 


int Recuperer_Freq (GtkWidget * p_combo) 
{    //GtkComboBox * p_combo   = p_data;
       int i;
       gchar * p_text    = NULL;
        p_text = gtk_combo_box_get_active_text (GTK_COMBO_BOX (p_combo));
        if(strcmp(p_text,"Journee entiere")==0)
          i=1;
        if(strcmp(p_text,"Par semaine")==0)
          i=2;
        if(strcmp(p_text,"Par mois")==0)
          i=3;
        if(strcmp(p_text,"Par annee")==0)
          i=0;
        printf ("%d***********\n", i);
        g_free   (p_text);
        return i;
        //(void) p_wid;
}   

 