#include "projet.h"


int Nombre_Jour_Precedent(int mois,int annee,int j)
{
    int mois_prec,n;
    if(mois==1)
    {
        mois_prec=12;
        annee--;
    }
    else
        mois_prec=mois-1;
    n=Nombre_De_Jour_Par_Mois(annee,mois_prec);
    return (n-j);
}

int Bissextile(int annee)
{
    if (annee%400==0)
        return 1;
    if ((annee%4==0)&&(annee%100!=0))
        return 1;
   return 0;
}


int Nombre_De_Jour_Par_Mois(int annee,int mois)
{
    if(mois==2)
    {
         if(Bissextile(annee))
            return 29;
         return 28;
    }
    if(mois==4||mois==6||mois==9||mois==11)
        return 30;
    return 31;
}


int Annee_sup(int jour,int mois,int an)
{

    int annee=2018;
    int m=1;
    int s=0;
while(annee<an)
    {

        if(Bissextile(annee)==0)
            s=s+365;
        else
            s=s+366;
        annee++;
    }
    while(m!=mois)
    {
        s=s+Nombre_De_Jour_Par_Mois(annee,m);
        m++;
    }
return (s+jour-1)%7;
}


int Annee_inf(int jour,int mois,int an)
{

    int annee=2018;
    int m=1;
    int j=1;
    int s=0;
    while(annee!=an)
        {
            annee--;
            if(Bissextile(annee)==0)
                s+=365;
            else
                s+=366;
        }
    while(m!=mois)
    {
        s-=Nombre_De_Jour_Par_Mois(annee,m);
        m++;
    }
    return (7-((s-jour+1)%7))%7;//groupe
}

int Trouver_Jour(int jour,int mois,int an)
{
    if((jour<1)||(jour>Nombre_De_Jour_Par_Mois(an,mois)))
        return -1;
    else
        if((mois<1)||(mois>12))
            return -1;
        else
            if(an<1)
                return -1;
    else
        if((an<1)||(an>32000))
            return -1;
    else
    {
    int p;
    int annee=2018;
    if(annee<=an)
    {
        p=Annee_sup(jour,mois,an);
        return p;
    }

    else
        {
            p=Annee_inf(jour,mois,an);
            return p;
        }
    }
}
