#include "projet.h"


int insertion_bd(PGconn *dbconn,Date *rec,int and,short moisd,short jourd,const char *titre,const char* lieu,char *hd,char *hf,int anf,short moisf,short jourf ,const char *des,int freq )
{
    char chaine[200];
    char dated[10];
    char datef[10];
    int i=1,j=0;
    PGresult   *res,*res1;
    sprintf(dated,"%d-%d-%d",and,moisd,jourd);
      sprintf(datef,"%d-%d-%d",and,moisd,jourd);
      res=PQexec(dbconn,
                      "select * from rendez_vous_bis");
       int nligne = PQntuples(res);
  int ncols = PQnfields(res);
   //if(nligne!=0){
      sprintf(chaine,"select * from rendez_vous_bis where date_rv='%s' and  ('%s'between heure_debut and heure_fin or  '%s'between heure_debut and heure_fin)",dated,hf,hd);
       res1 = PQexec(dbconn,chaine);   
       printf("          %d\n",PQntuples(res1));
      if (PQntuples(res1)!=0)
      {
        strcpy(rec->mes,"heure comprise entre deux rv");
        Information(rec);
        return 0;
      }//}
    else{
      if((freq==1)||(freq==2))
      {
        sprintf(chaine,"insert into rendez_vous_bis(date_rv ,heure_debut,date_fin,heure_fin ,nom_rv ,lieu_rv,description,frequence)values('%s','%s','%s','%s','%s','%s','%s','%d')",dated,hd,datef,hf,titre,lieu,des,freq);
        res = PQexec(dbconn,chaine);
        if (PQresultStatus(res) != PGRES_COMMAND_OK)
      {
        strcpy(rec->mes,"ERREUR !!! INSERTION FAILED");
        Information(rec);
        return 0;
      }
      }
      j=moisd;
    if(freq==3)
    while(j<13)
    {  
        sprintf(dated,"%d-%d-%d",and,moisd,jourd);
        sprintf(datef,"%d-%d-%d",and,moisd,jourd);
        sprintf(chaine,"insert into rendez_vous_bis(date_rv ,heure_debut,date_fin,heure_fin ,nom_rv ,lieu_rv,description,frequence)values('%s','%s','%s','%s','%s','%s','%s','%d')",dated,hd,datef,hf,titre,lieu,des,freq);
        res = PQexec(dbconn,chaine);
        moisd++;
        j++;
        if (PQresultStatus(res) != PGRES_COMMAND_OK)
      {
        strcpy(rec->mes,"ERREUR !!! INSERTION FAILED");
        Information(rec);
        return 0;
      }
    }         
    j=and;
    if(freq==0)
    while(j<2100)
    {  
        sprintf(dated,"%d-%d-%d",and,moisd,jourd);
        sprintf(datef,"%d-%d-%d",and,moisd,jourd);
        sprintf(chaine,"insert into rendez_vous_bis(date_rv ,heure_debut,date_fin,heure_fin ,nom_rv ,lieu_rv,description,frequence)values('%s','%s','%s','%s','%s','%s','%s','%d')",dated,hd,datef,hf,titre,lieu,des,freq);
        res = PQexec(dbconn,chaine);
        and++;
        j++;
        if (PQresultStatus(res) != PGRES_COMMAND_OK)
      {
        strcpy(rec->mes,"ERREUR !!! INSERTION FAILED");
        Information(rec);
        return 0;
      }
    }         
    
}
return i;
}



void reponse_bd(PGconn *dbconn,Date *f_bd)
{
       gtk_widget_destroy(GTK_WIDGET(f_bd->tab));
       
int moni=0,i,j,k=0,az=1;
PGresult   *res;
GtkWidget* label_bd,*bott[60],*table_bd,*vbox;
Date *func_bd[30];
char even[20],bing[10][6],*p;
char chaine[200],*t[7]={"Date_debut","Heure_debut","Date_fin","Heure_fin","nom_evenement","Lieu","Description"};
     
res=PQexec(dbconn,
                      "select * from rendez_vous_bis");
 
 

  vbox=gtk_vbox_new(TRUE,0);
    int nligne = PQntuples(res);
  int ncols = PQnfields(res);
   if(nligne==0)
  {
      bott[0]=Creer_Boutton("RETOUR");
      label_bd=gtk_label_new("aucun element");
      gtk_container_add(GTK_CONTAINER(f_bd->fenetre),vbox);
      gtk_box_pack_start(GTK_BOX(vbox),bott[0],TRUE,FALSE,0);
      gtk_box_pack_start(GTK_BOX(vbox),label_bd,TRUE,FALSE,0);
      f_bd->tab=vbox;
       g_signal_connect(G_OBJECT(bott[0]),"clicked",G_CALLBACK(Affiche1),f_bd);
                    gtk_widget_show_all(f_bd->fenetre);
  }
  else{
  table_bd=gtk_table_new(4,10,TRUE);
  gtk_container_add(GTK_CONTAINER(f_bd->fenetre),table_bd);
   bott[moni]=Creer_Boutton("RETOUR");
               Creer_Attache(table_bd,bott[moni],0,ncols,k,k+1);
               moni++;
               f_bd->tab=table_bd;
for(i=0;i<nligne;i++) 
{
  int b;
  res = PQexec(dbconn,
                       "SELECT * FROM rendez_vous_bis");
  strcpy(even,PQgetvalue(res,i,0));
 
   if((even[2]=='-')||(even[1]=='-')||(even[3]=='-')||(even[4]=='-'))
      {     
        p=strtok(even,"-");
        for(b=0;p!=NULL;b++)
        {
          strcpy(bing[b],p);
        
          p=strtok(NULL,"-");
        }
      }
  if((f_bd->annee_cour==atoi(bing[0]))&&(f_bd->mois_cour==atoi(bing[1]))){
  sprintf(chaine,"%s  ",PQgetvalue(res,i,4));
  label_bd=gtk_label_new(chaine);
  Creer_Attache(table_bd,label_bd,0,1,k+1,k+2);
  bott[moni]=Creer_Boutton("Voir");
  Creer_Attache(table_bd,bott[moni],1,2,k+1,k+2);
  moni++;
  bott[moni]=Creer_Boutton("Modifier");
  Creer_Attache(table_bd,bott[moni],2,3,k+1,k+2);
  moni++;
  bott[moni]=Creer_Boutton("Supprimer");
  Creer_Attache(table_bd,bott[moni],3,4,k+1,k+2);
  moni++;
  func_bd[i]=(Date*)malloc(sizeof(Date));
  func_bd[i]->jour_cour=i;
  func_bd[i]->fenetre=f_bd->fenetre;
  func_bd[i]->tab=table_bd; 
  func_bd[i]->annee_cour=f_bd->annee_cour;
  func_bd[i]->mois_cour=f_bd->mois_cour;
  g_signal_connect(G_OBJECT(bott[az]),"clicked",G_CALLBACK(Voir_bd),func_bd[i]);
  g_signal_connect(G_OBJECT(bott[az+1]),"clicked",G_CALLBACK(Modifier_bd),func_bd[i]);
  g_signal_connect(G_OBJECT(bott[az+2]),"clicked",G_CALLBACK(Supprimer_bd),func_bd[i]);
  az+=3;
  k+=1;  
  }
  }
  g_signal_connect(G_OBJECT(bott[0]),"clicked",G_CALLBACK(Affiche1),f_bd);
  gtk_widget_show_all(f_bd->fenetre);  
  }
}
                     


void supprimer_ligne(PGconn *dbconn,int i)
{
  char chaine[300];
  PGresult   *res;

  res=PQexec(dbconn,
                      "select * from rendez_vous_bis");
  
  sprintf(chaine, "delete  FROM rendez_vous_bis where nom_rv='%s' and date_rv='%s' and heure_debut='%s'",PQgetvalue(res,i,4),PQgetvalue(res,i,0),PQgetvalue(res,i,1));
  res=PQexec(dbconn,
                      chaine);

}


void Supprimer_bd(GtkWidget* boutton,gpointer data)
{
  PGconn *dbconn;
      dbconn=PQsetdbLogin("localhost","5433","","","projetbd","postgres","kuni");
    Date *r=data;
    supprimer_ligne(dbconn,r->jour_cour);
    
    reponse_bd(dbconn,r);
}

void Voir_bd(GtkWidget* boutton,gpointer data)
{
      Date *s=(Date*)malloc(sizeof(Date));
      s=data;
       char chaine[300];
  PGresult   *res;
    PGconn *dbconn;
      dbconn=PQsetdbLogin("localhost","5433","","","projetbd","postgres","kuni");
  res=PQexec(dbconn,
                      "select * from rendez_vous_bis");
  
  sprintf(chaine, "\t EVENEMENT\n Nom:\t %s \nDate_De_Debut:\t %s\nHeure_Debut:\t%s\n Date_Fin:\t%s\nHeure_Fin:\t %s\nLieu:\t%s\nDescription:\t %s\n Frequence \t %s",PQgetvalue(res,s->jour_cour,4)
                                       ,PQgetvalue(res,s->jour_cour,0)
                                       ,PQgetvalue(res,s->jour_cour,1)
                                       ,PQgetvalue(res,s->jour_cour,2)
                                       ,PQgetvalue(res,s->jour_cour,3)
                                       ,PQgetvalue(res,s->jour_cour,5)
                                       ,PQgetvalue(res,s->jour_cour,6)
                                       ,PQgetvalue(res,s->jour_cour,7));
  strcpy(s->mes,chaine);
  Information(s);
}




void Modifier_bd(GtkWidget* boutton,gpointer data)
{
    PGresult   *res;
   GtkWidget* frame,*boite,*entry,*entry1,*entry2,*entry4,*entry3,*separateur,*vboxframe,*label,*label1[10];
    GtkAdjustment *ad;
    int i,c,t[10];
    char even[10][50];
    char bing[7][5];
    char *p;
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
     PGconn *dbconn;
      dbconn=PQsetdbLogin("localhost","5433","","","projetbd","postgres","kuni");
     int b;
   res = PQexec(dbconn,
                       "SELECT * FROM rendez_vous_bis");
   
    frame=gtk_frame_new("evenement");
    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(boite)->vbox),frame,TRUE,FALSE,0);
    gtk_container_add(GTK_CONTAINER(frame),vboxframe);
    label=gtk_label_new("Nom Evenement");
    gtk_box_pack_start(GTK_BOX(vboxframe),label,TRUE,FALSE,0);
    entry= gtk_entry_new_with_max_length(25);
    gtk_entry_set_text(GTK_ENTRY(entry),PQgetvalue(res,rec->jour_cour,4));
    gtk_box_pack_start(GTK_BOX(vboxframe),entry,TRUE,FALSE,0);
     strcpy(even[8],PQgetvalue(res,rec->jour_cour,0));
 
   if((even[8][2]=='-')||(even[8][1]=='-')||(even[8][3]=='-')||(even[8][4]=='-'))
      {     
        p=strtok(even[8],"-");
        for(b=0;p!=NULL;b++)
        {
          strcpy(bing[b],p);
          
          p=strtok(NULL,"-");
        }
      }
    label=gtk_label_new("Date de debut jj-mm-an");
    gtk_box_pack_start(GTK_BOX(vboxframe),label,TRUE,FALSE,0);
    gtk_container_add(GTK_CONTAINER(vboxframe),hbox);
    ad=gtk_adjustment_new(atoi(bing[2]),1,31,1,1,0);
    label1[0]=gtk_spin_button_new(ad,1,0);     
    gtk_box_pack_start(GTK_BOX(hbox),label1[0],TRUE,FALSE,0);

    ad=gtk_adjustment_new(atoi(bing[1]),1,12,1,1,0);
    label1[1]=gtk_spin_button_new(ad,1,0);     
    gtk_box_pack_start(GTK_BOX(hbox),label1[1],TRUE,FALSE,0);

    ad=gtk_adjustment_new(atoi(bing[0]),1,32000,1,1,0);
    label1[2]=gtk_spin_button_new(ad,1,0);     
    gtk_box_pack_start(GTK_BOX(hbox),label1[2],TRUE,FALSE,0);

      strcpy(even[5],PQgetvalue(res,rec->jour_cour,1));
 
   if((even[5][2]==':')||(even[5][1]==':'))
      {     
        p=strtok(even[5],":");
        for(b=0;p!=NULL;b++)
        {
          strcpy(bing[b],p);
          
          p=strtok(NULL,":");
        }
      }
    label=gtk_label_new("heure de debut hh:mm");
    gtk_box_pack_start(GTK_BOX(vboxframe),label,TRUE,FALSE,0);
    gtk_container_add(GTK_CONTAINER(vboxframe),hbox1);
    ad=gtk_adjustment_new(atoi(bing[0]),1,23,1,1,0);
    label1[3]=gtk_spin_button_new(ad,1,0);     
    gtk_box_pack_start(GTK_BOX(hbox1),label1[3],TRUE,FALSE,0);

    ad=gtk_adjustment_new(atoi(bing[1]),0,59,1,1,0);
    label1[4]=gtk_spin_button_new(ad,1,0);     
    gtk_box_pack_start(GTK_BOX(hbox1),label1[4],TRUE,FALSE,0);

     strcpy(even[6],PQgetvalue(res,rec->jour_cour,2));
 
   if((even[6][2]=='-')||(even[6][1]=='-')||(even[6][3]=='-')||(even[6][4]=='-'))
      {     
        p=strtok(even[6],"-");
        for(b=0;p!=NULL;b++)
        {
          strcpy(bing[b],p);
        
          p=strtok(NULL,"-");
        }
      }
    label=gtk_label_new("Date de Fin jj-mm-an");
    gtk_box_pack_start(GTK_BOX(vboxframe),label,TRUE,FALSE,0);
    gtk_container_add(GTK_CONTAINER(vboxframe),hbox2);
    ad=gtk_adjustment_new(atoi(bing[2]),1,31,1,1,0);
    label1[5]=gtk_spin_button_new(ad,1,0);     
    gtk_box_pack_start(GTK_BOX(hbox2),label1[5],TRUE,FALSE,0);

    ad=gtk_adjustment_new(atoi(bing[1]),1,12,1,1,0);
    label1[6]=gtk_spin_button_new(ad,1,0);     
    gtk_box_pack_start(GTK_BOX(hbox2),label1[6],TRUE,FALSE,0);

    ad=gtk_adjustment_new(atoi(bing[0]),1,32000,1,1,0);
    label1[7]=gtk_spin_button_new(ad,1,0);     
    gtk_box_pack_start(GTK_BOX(hbox2),label1[7],TRUE,FALSE,0);

      strcpy(even[7],PQgetvalue(res,rec->jour_cour,3));
 
   if((even[7][2]==':')||(even[7][1]==':'))
      {     
        p=strtok(even[7],":");
        for(b=0;p!=NULL;b++)
        {
          strcpy(bing[b],p);
          
          p=strtok(NULL,":");
        }
      }
    label=gtk_label_new("heure de Fin hh:mm");
    gtk_box_pack_start(GTK_BOX(vboxframe),label,TRUE,FALSE,0);
    gtk_container_add(GTK_CONTAINER(vboxframe),hbox3);
    ad=gtk_adjustment_new(atoi(bing[0]),1,23,1,1,0);
    label1[8]=gtk_spin_button_new(ad,1,0);     
    gtk_box_pack_start(GTK_BOX(hbox3),label1[8],TRUE,FALSE,0);

    ad=gtk_adjustment_new(atoi(bing[1]),0,59,1,1,0);
    label1[9]=gtk_spin_button_new(ad,1,0);     
    gtk_box_pack_start(GTK_BOX(hbox3),label1[9],TRUE,FALSE,0);
     
        
    label=gtk_label_new("Lieu");
    gtk_box_pack_start(GTK_BOX(vboxframe),label,TRUE,FALSE,0);
    entry3=gtk_entry_new_with_max_length(15);
    gtk_entry_set_text(GTK_ENTRY(entry3),PQgetvalue(res,rec->jour_cour,5));
    gtk_box_pack_start(GTK_BOX(vboxframe),entry3,TRUE,FALSE,0);
    label=gtk_label_new("Description");
    gtk_box_pack_start(GTK_BOX(vboxframe),label,TRUE,FALSE,0);
    entry4=gtk_entry_new_with_max_length(100);
    gtk_entry_set_text(GTK_ENTRY(entry4),PQgetvalue(res,rec->jour_cour,6));
    gtk_box_pack_start(GTK_BOX(vboxframe),entry4,TRUE,FALSE,0);
    label=gtk_label_new("Frequence");
    gtk_box_pack_start(GTK_BOX(vboxframe),label,TRUE,FALSE,0);
    p_combo = gtk_combo_box_new_text ();
    gtk_box_pack_start(GTK_BOX (vboxframe), p_combo, TRUE, TRUE, 2);        
    gtk_combo_box_append_text  (GTK_COMBO_BOX (p_combo), "Journee entiere");    
    gtk_combo_box_append_text  (GTK_COMBO_BOX (p_combo), "Par semaine");    
    gtk_combo_box_append_text  (GTK_COMBO_BOX (p_combo), "Par mois");    
    gtk_combo_box_prepend_text (GTK_COMBO_BOX (p_combo), "Par annee");  
    i=atoi(PQgetvalue(res,rec->jour_cour,7));  
    printf("***%d***",i);
    gtk_combo_box_set_active (GTK_COMBO_BOX (p_combo), i);    
    gtk_widget_show_all(GTK_DIALOG(boite)->vbox);
    separateur=gtk_hseparator_new();
    gtk_box_pack_start(GTK_BOX(vboxframe),separateur,TRUE,FALSE,0);
    switch(gtk_dialog_run(GTK_DIALOG(boite)))
    {
        case GTK_RESPONSE_OK: {
                                strcpy(even[0],gtk_entry_get_text(GTK_ENTRY(entry)));
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
                                        i=insertion_bd(dbconn,rec,t[2],t[1],t[0],even[0],even[1],even[3],even[4], t[7],t[6],t[5],even[2],i );
                                        if(i==1)
                                        {
                                          supprimer_ligne(dbconn,rec->jour_cour);
                                          reponse_bd(dbconn,rec);
                                        }
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
