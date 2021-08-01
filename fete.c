#include "projet.h"

int pentecote(int annee,int*mois)
{
  int k;
  k=paque(annee,mois);
  k+=49;
  while(k>Nombre_De_Jour_Par_Mois(annee,*mois))
  {
      k-=Nombre_De_Jour_Par_Mois(annee,*mois);
       if(*mois==12)
            *mois=1;
        else
           (*mois)++;
  }
return k;
}


int ascension(int annee,int* mois)
{
  int k;
  k=paque(annee,mois);
  k+=39;
  while(k>Nombre_De_Jour_Par_Mois(annee,*mois))
  {
        k-=Nombre_De_Jour_Par_Mois(annee,*mois);
         if(*mois==12)
            *mois=1;
        else
          (*mois)++;
  }
return k;
}

int careme(int annee,int*mois)
{
  int k;
  k=paque(annee,mois);
   if(*mois==1)
            *mois=12;
          else
           (*mois)--;
  k+=Nombre_De_Jour_Par_Mois(annee,*mois);
  if(k>46)
           k=k-46;
      else{
           if(*mois==1)
            *mois=12;
          else
           (*mois)--;
           k+=Nombre_De_Jour_Par_Mois(annee,*mois);
           k=k-46;
      }
return k;
}



int Tabaski_Sup(int annee,int *mois)
{
    int anref=2019,moisref=8,jref=11;
    while(anref!=annee)
    {
      anref++ ;
      jref-=11;
      if(jref<=0)
      {
          if(moisref==1)
            moisref=12;
          else
            moisref--;
        jref+=Nombre_De_Jour_Par_Mois(anref,moisref);
      }
    }
    *mois=moisref;
    return jref;
}
int Tabaski_Inf(int annee,int *mois)
{
    int anref=2019,moisref=8,jref=11;
    while(anref!=annee)
    {
      anref-- ;
      jref+=11;
      if(jref>Nombre_De_Jour_Par_Mois(anref,moisref))
      {

        jref-=Nombre_De_Jour_Par_Mois(anref,moisref);
        if(moisref==12)
            moisref=1;
        else
            moisref++;
      }
    }
    *mois=moisref;
    return jref;
}
int Tabaski(int annee,int *mois)
{
    if(annee<2019)
        return Tabaski_Inf(annee,mois);
    else
        return Tabaski_Sup(annee,mois);
}

int korite(int annee,int*mois)
{
int k;
  k=Tabaski(annee,mois);
   if(*mois==1)
            *mois=12;
          else
           (*mois)--;
  k+=Nombre_De_Jour_Par_Mois(annee,*mois);
   if(*mois==1)
            *mois=12;
          else
             (*mois)--;
  k+=Nombre_De_Jour_Par_Mois(annee,*mois);
  if(k>68)
      k=k-68;
  else
  {
       if(*mois==1)
            *mois=12;
          else
             (*mois)--;
      k+=Nombre_De_Jour_Par_Mois(annee,*mois);
      k=k-68;
  }
return k;
}


int paque(int annee,int *mois)
{
  int A,B,C,D,G,E,F;
  int res;
  A=annee %19+1;
  B=annee/100+1;
  C=(3*B)/4-12;
  D=(8*B+5)/25-5;
  E=(annee*5)/4-10-C;
  F=((11*A+20+D-C)%30+30)%30;
    if((F==24)||(F==25&& A>11))
        F=F+1;
  G=44-F;
    if (G<21)
        G=G+30;
 res=(G+7-(E+G)%7);
    if(res>31) 
    {
        res=res-31;
        *mois=4;
    }
      else
        *mois=3;

return res;
}



int Ramadan(int annee,int*mois)
{
int k;
  k=korite(annee,mois);
  if(k<29)
  {
    k=29-k;
     if(*mois==1)
            *mois=12;
          else
            (*mois)--;
    k=Nombre_De_Jour_Par_Mois(annee,*mois)-k;
  }
  else
  {
    k=k-29;
    if(k==0)
    {
       if(*mois==1)
            *mois=12;
          else
            (*mois)--;
     k=Nombre_De_Jour_Par_Mois(annee,*mois);
    }
  }
  
return k;
}