#include <stdio.h>
#include <stdlib.h>
#include "Fonctions.h"
#include "time.h"

/*************************MODELE LLC****************************************************************************************/
maillon* allouer()
{
    return malloc(sizeof(maillon));
}

void aff_adr(maillon *p,maillon *q)
{
    p->suiv = q;
}

maillon* suivant(maillon *p)
{
    return p->suiv;
}
/*************************PROCEDURE DU TP****************************************************************************************/
void affichage(liste *t)//affiche les vehicule present dans le stock
{
    maillon *p=t->tete;


                printf("\n\n  +---------------------------------------------------------------------------------------------------------------------------------+\n");
                printf("  |         Marque          |         Modele         |     Matricule   |         Couleur       |     Annee    |         Prix        |\n");
                printf("  +---------------------------------------------------------------------------------------------------------------------------------+\n");


    while (p!=NULL)
        {
        printf("  |%16s         |%14s          |%14s   |%16s       |%9d     |%15.2lf DA   | \n",p->voiture.marque,p->voiture.modele,p->voiture.numero,p->voiture.couleur,p->voiture.annee,p->voiture.prix);
                printf("  +---------------------------------------------------------------------------------------------------------------------------------+\n");
        p=suivant(p);
        }
}

/********************************************************************************************************************************/
void choixmodele(liste *t,char mar[],char mod[])///choix du modelle
{    ///variable locale
    int tr=0,c=0;
    maillon *p=t->tete;

    while (p!=NULL)
    {
        if ( !strcmp(maj(p->voiture.modele),mod) && !strcmp(maj(p->voiture.marque),mar) )
        {
                if (c==0){
                        textcolor(1);
                printf("\nResultat de la recherche: \n\tMarque:-%s     Modele:-%s\n",mar,mod);
                textcolor(12);
                printf("\t\t+------------------------------------------------------------+\n");
                printf("\t\t|     Annee    |         Couleur       |          Prix       | \n");
                printf("\t\t+------------------------------------------------------------+\n");}
                printf("\t\t|%14d|%23s|%21.2lf| \n",p->voiture.annee,p->voiture.couleur,p->voiture.prix);
                printf("\t\t+------------------------------------------------------------+\n");
                tr = 1;
                c=1;

        }
        p = suivant(p);///faire passer le pointeur au suivant
    }
    textcolor(12);
    if (tr==0) printf("\n\n\n\n\t\t\t\tDesole!! Ce vehicule n'existe pas\n\n\n\n");
    textcolor(0);
}
/********************************************************************************************************************************/
void choixprix(liste *t,double prixinf,double prixsup) ///choix des vehicule compris entre prix inf et prix sup
{
    int tr=0,c=0;maillon *p=t->tete;
    while (p!=NULL)
    {
        if ( p->voiture.prix>=prixinf && p->voiture.prix<=prixsup )

        {   if (c==0)//pour affiche le titre une seul fois
        {
            printf("\nResultat de la recherche: Prix entre %.2f DA et %.2f DA\n",prixinf,prixsup);
            textcolor(0);
            printf("\t\t+------------------------------------------------------------------------------------+\n");
            printf("\t\t|         marque       |         modele        |     annee     |         prix        |\n");
            printf("\t\t+------------------------------------------------------------------------------------+\n");
        }
            textcolor(0);
            printf("\t\t|%15s       |%17s      |%10d     |%16.2lf     | \n",p->voiture.marque,p->voiture.modele,p->voiture.annee,p->voiture.prix);
            printf("\t\t+------------------------------------------------------------------------------------+\n");
            tr = 1;
            c=1;
        }
        p = suivant(p);
    }
        textcolor(12);
    if (tr==0) printf("\n\n\nLes vehicules dont le prix est entre %.2f DA et %.2f DA n'existent pas",prixinf,prixsup);
    textcolor(0);
}

/********************************************************************************************************************************/
void rech_seq(liste *t,char num[],int *existe,maillon **pre,maillon **posit)//recherche des matricule d'une facon sequentiel
{
    maillon *p=t->tete;
    *posit = NULL;
    *existe = 0;
    *pre = NULL;
    if (p!=NULL){
    if ( !strcmp(p->voiture.numero,num) )
    {
        *existe = 1;
        *posit = p;
    }
    else
    {
      while (p!=NULL && !(*existe) )
      {
          *pre = p;
          p = suivant(p);
          if (p!=NULL)
          {
            if ( !strcmp(p->voiture.numero,num) )
            {
                *existe = 1;
                *posit = p;
            }
          }
      }
    }
    }
}
/********************************************************************************************************************************/
void newauto(liste *t,automobile vehicule,int *new)//procedure de nouvelle voiture
{
 int tr;
 maillon *p,*q;
 rech_seq(t,vehicule.numero,&tr,&q,&p);
 *new = 0;
 if (!tr)
 {
        p = allouer();
        p->voiture=vehicule;
        if (t->tete==NULL)
         aff_adr(p,NULL);
        else aff_adr(p,t->tete);
        t->tete = p;
        t->nb++;
        *new = 1;
 }
}
/********************************************************************************************************************************/
void casse(liste *t,char num[],int *old,int *nef)//supprimer un vehicule
{
    maillon *p,*q;int trouv;
    int choix2 ;
    chaine tab2[] ={"Oui","Non"};
    *old = 0;
    rech_seq(t,num,&trouv,&q,&p);
    if (trouv)
    {
         printf("\a Etes-vous sur de vouloir supprimer ce vehicule?\n ");
        choix2=menu(tab2,2);
        switch(choix2)
        {
          case 1:
           if (p==t->tete)
                t->tete = suivant(p);
            else
                aff_adr(q,suivant(p));
            free(p);
            *old = 1;
            t->nb--;
            *nef=1;
            break;
          case 2 :
            *nef=1;
              break;
        }

}}
/********************************************************************************************************************************/
void permut(maillon *p, maillon *q) ///permute le contenue de deux maillons
{
    char a[13],b[10],c[10],d[10];int e;double f;
    strcpy(a,p->voiture.numero);
    strcpy(b,p->voiture.marque);
    strcpy(c,p->voiture.modele);
    strcpy(d,p->voiture.couleur);
    e = p->voiture.annee;
    f = p->voiture.prix;

    strcpy(p->voiture.numero,q->voiture.numero);
    strcpy(p->voiture.marque,q->voiture.marque);
    strcpy(p->voiture.modele,q->voiture.modele);
    strcpy(p->voiture.couleur,q->voiture.couleur);
    p->voiture.annee = q->voiture.annee;
    p->voiture.prix = q->voiture.prix;

    strcpy(q->voiture.numero,a);
    strcpy(q->voiture.marque,b);
    strcpy(q->voiture.modele,c);
    strcpy(q->voiture.couleur,d);
    q->voiture.annee = e;
    q->voiture.prix = f;
}
/********************************************************************************************************************************/
void tri_bul_llc(liste *t) //tri a bulle d'une llc
{
    int i,v,tai;
    maillon *p;
    tai = t->nb;
    if (t->tete!=NULL)
    {

       do
       {
           v = 1;
           tai = tai - 1;
           p = t->tete;
           for (i=1;i<=tai;i++)
           {
               if ( matoint(p->voiture.numero) > matoint(suivant(p)->voiture.numero) )
               {
                  permut(p,suivant(p));
                  v = 0;
               }
               p = suivant(p);
           }

       }
       while (tai>1 && v==0);
    }
}
/********************************************************************************************************************************/
void retrier(liste *t)
{
    int i,v,tai;
    maillon *p;
    char cur[100]={},pre[100]={};
    tai = t->nb;
    do
    {
        v = 1;
        tai = tai - 1;
        p = t->tete;
        for (i=1;i<=tai;i++)
        {
            cur[0]='\0';
            pre[0]='\0';
            strcpy(cur,maj(p->voiture.marque));
            strcpy(pre,maj(suivant(p)->voiture.marque));
            if ( cur[0] > pre[0] )
            {
               permut(p,suivant(p));
               v = 0;
            }
            p = suivant(p);
        }

    }
    while (tai>1 && v==0);
    tai = t->nb;
    do
    {
        v = 1;
        tai = tai - 1;
        p = t->tete;
        for (i=1;i<=tai;i++)
        {
            cur[0]='\0';
            pre[0]='\0';
            strcpy(cur,maj(p->voiture.modele));
            strcpy(pre,maj(suivant(p)->voiture.modele));
            if ( !strcmp((cur),(pre)) && suivant(p)->voiture.prix > p->voiture.prix )
            {
               permut(p,suivant(p));
               v = 0;
            }
            p = suivant(p);
        }

    }
    while (tai>1 && v==0);
}
/********************************************************************************************************************************/
maillon* rech_pos(liste *t,int pos) //retourne l'@ d'une position
{
    maillon *p=t->tete;int cpt=1;
    while (p!=NULL && cpt!=pos)
        {
        p = suivant(p);
        cpt = cpt + 1;
        }
    return p;
}


maillon* ptr_petitnum(liste *t,int b1,int b2)
{
    int i;char petit[13];maillon *p=rech_pos(t,b1),*adr=p;
    strcpy(petit,p->voiture.numero);
    for (i=1;i<=b2-b1;i++)
       {
          p = suivant(p);
          if ( matoint(p->voiture.numero)<matoint(petit) )
          {
             strcpy(petit,p->voiture.numero);
             adr = p;
          }
       }
    return adr;
}
/********************************************************************************************************************************/
void tri_sel_llc(liste *t)//tri par selection d'une llc
{
    int i,tai=t->nb;maillon *p=t->tete,*adr;
    for (i=1;i<=tai-1;i++)
        {
           adr = ptr_petitnum(t,i,tai);
           permut(p,adr);
           p = suivant(p);
        }
}
/********************************************************************************************************************************/
void Tri1t (liste l,int n)
{
 int i,cpt,k;
 i = 1;
 while (i<n)
 {
   cpt = NBEP(i,l,n);
   if ((cpt+1) <= i)
   i=i+1;
   else
   {
    k = 1;
    while ( matoint(rech_pos(&l,i)->voiture.numero) ==matoint(rech_pos(&l,cpt+k)->voiture.numero) )
     if (n=0)
    k = k+1;
                                                                                                                                        //permut(&rech_pos(&l,i)->voiture,rech_pos(&l,cpt+k));
   }
 }
}
/********************************************************************************************************************************/
int NBEP (int i,liste l,int ti)
{
 int k,cpt;

 cpt = 0;
 for (k=1;k<=ti;k++)
  if (matoint(rech_pos(&l,i)->voiture.numero)<matoint(rech_pos(&l,cpt+k)->voiture.numero))
    cpt = cpt+1;
 return cpt;
}

void tri_insertion_lst(liste *t) //trie par insertion d'une llc
    {
/*position testée, précédent,dernier plus petit*/
        maillon *pt,*prec,*dpp;
        for(prec=t->tete,pt=(t->tete)->suiv;pt!=NULL;prec=pt,pt=pt->suiv)
                if(matoint(prec->voiture.numero)>matoint(pt->voiture.numero)) /*inutile de chercher si en bonne position */
                    {
                            prec->suiv=pt->suiv;
                            if(matoint(t->tete->voiture.numero) > matoint(pt->voiture.numero)) /*cas particulier du premier*/
                                {
                                    pt->suiv=t->tete;
                                    t->tete=pt;
                                }
                            else
                                {
                                    dpp=t->tete;
                                    while(matoint(dpp->suiv->voiture.numero) <= matoint(pt->voiture.numero))dpp=dpp->suiv;
                        /* on est sur d'en trouver un, vu les tests effectués plus haut */
                                    pt->suiv=dpp->suiv;
                                    dpp->suiv=pt;
                                    }
                    }
    }
/********************************************************************************************************************************/
int matoint (char num[])
{
    int i;char ch[100];
    strcpy(ch,num);
    for (i=5;i<=11;i++)
     ch[i] = ch[i+1];
    for (i=8;i<=11;i++)
     ch[i] = ch[i+1];
    return strtol(ch,NULL,10);
}
/********************************************************************************************************************************/
maillon* rechdict(liste *l,char num[])
{

    int m,bi=1,bs=l->nb;
    if ( l->tete==NULL || bs<bi)  return NULL;
    m = (bi+bs)/2;
    do
    {

        if ( matoint(num)==matoint( rech_pos(l,m)->voiture.numero )  ) return rech_pos(l,m);
        else if ( matoint(num)<matoint( rech_pos(l,m)->voiture.numero )  )
        {
            bs = m-1;
            m = (bi+bs)/2;
        }
        else
        {
            bi = m+1;
            m = (bi+bs)/2;
        }
    }
    while ( bs>bi && matoint(num)!=matoint( rech_pos(l,m)->voiture.numero ) );

    if ( matoint(num)==matoint( rech_pos(l,m)->voiture.numero ) )
           return rech_pos(l,m);
    else
        return NULL;
}
/********************************************************************************************************************************/
void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
/********************************************************************************************************************************/
void aide()
{
  int choix,c=0;
  chaine tab[]={ "1.Utilisation du programme.","2.Nous contacter . ", "3.Quitter le support." };

    do{ if (c==1){
      textbackground(3);
       textcolor(14);
       printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t    \n");
       printf("\t\t\t\t\t\t   AIDE ET RENSEIGNEMENT \t\t\t\t\t\t\t\t\t\t");
       printf("\n\n");
       textbackground(15);
       textcolor(0);}
       choix=menu(tab,3);
    switch(choix)
    {
     case 1:
     system("cls");
     textbackground(3);
       textcolor(14);
       printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t    \n");
       printf("\t\t\t\t\t\t   AIDE ET RENSEIGNEMENT \t\t\t\t\t\t\t\t\t ");
       textbackground(15);
       textcolor(0);
     Color(12,15);
     printf("\n\n\t 1.Utilisation du programme:                               \n\n\n");
     Color(0,15);
     printf("  Avant de commencer ce tutoriel, nous vous rappelons la structure globale du");
     printf(" programme.Ce dernier est inaugure par un generique \n\n");
     printf(" qui a son tour contient les noms des realisateurs,le Charge des Travaux Diriges et Pratiques: < Dr. KERMI Adel > qui est maitre,\n\n");
     printf(" de conferences a l'ESI < ECOLE SUPERIEURE D'INFORMATIQUE >.\n\n");
     printf("  Apres tous ce qui suit n'est rien d'autre qu'une interface entre le programme ");
     printf("et l'utilisateur,c'est pour cela qu'il est imperatif\n\n");
     printf(" de bien la manipuler.\n\n");
     printf("  A l'affichage du menu principal,vous devriez selectionner votre choix qui est");
     printf(" entre 1 et 8 en utilisant les touches Bas-Haut. \n\n\n");
     Color(12,15);
     printf("\t Conseils:\n\n ");
     Color(0,15);
     printf("* Au debut,la liste est vide alors il est inutile de rechercher ,afficher ,modifier ou supprimer des vehicules.\n\n");
     printf(" * Suivez les instructions suivant votre gre en respectant les conditions donnees sinon des messages d'erreurs apparetrons pour\n");
     printf(" vous guider.\n\n");
     printf(" * Pour la saisie de la plaque d'immatriculation ,c'est un peu particulier.En effet, il faut passer par trois etapes pour eviter\n");
     printf(" des erreurs mais aussi pour que ca soit moins dense et plus rapide et pour imaginer un peu la signification de chaque situation\n");
     printf(" qui est representee par des caracteres rouges dont il faut remplir .C'est 3 phases sont:\n\n");
     printf("\t+");Color(2,15);
     printf(" Remplissage du code departemental ou wilaya qui est sur deux chiffres entre 1 et 48 :");
     Color(0,15);
     printf("XXXXX-");
     Color(0,15);
     printf("XXX-");
     Color(12,15);
     printf("XX.\n\n");
     Color(0,15);
     printf("\t+");Color(2,15);
     printf(" Remplissage du nombre compose du type de vehicule");Color(0,15);
     printf(" < 1: vehicule de tourisme, 2: camion, 3: vehicule utilitaire, 4: transport\n\n");
     printf("\t en commun, 5: tracteur de semi-remorque, 6: tracteur agricole , 7: vehicules speciaux, 8: remorque >");
     Color(2,15);
     printf(" suivi des deux\n\n");
     printf("\t derniers chiffres de l'annee de mise en circulation:");
     Color(0,15);
     printf(" XXXXX-");
     Color(12,15);
     printf("XXX");
     Color(0,15);
     printf("-XX.\n\n");
     Color(0,15);
     printf("\t+");Color(2,15);
     printf(" Remplissage du numero de serie d'enregistrement:");
     Color(12,15);
     printf(" XXXXX");
     Color(0,15);
     printf("-XXX");
     Color(0,15);
     printf("-XX.\n\n");
     Color(9,15);
     c=1;
     system("pause");
     system("cls");
     break;
     case 2:
     system("cls");
     c=1;
     textbackground(3);
       textcolor(14);
       printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t    \n");
       printf("\t\t\t\t\t\t   AIDE ET RENSEIGNEMENT \t\t\t\t\t\t\t\t\t ");
       textbackground(15);
       textcolor(0);
     Color(0,15)  ;
     printf("\n\n \t+------------------------------------------------+\n");
     printf(" \t|Dr. KERMI Adel, Maitre de conferences a l'ESI.  |\n");
     printf(" \t+------------------------------------------------+\n");
     printf(" \t|Emplacement: OUED SMAR,Alger,Algerie.           |\n");
     printf(" \t+------------------------------------------------+\n");
     printf(" \t|Telephone: 022561419 / 0662144630.              |\n");
     printf(" \t+------------------------------------------------+\n");
     printf(" \t|Fax: 023456794                                  |\n");
     printf(" \t+------------------------------------------------+\n");
     printf(" \t|Site web: www.esi.dz                            |\n");
     printf(" \t+------------------------------------------------+\n");
     printf(" \t|Boite e_mail: esi@yahoo.fr                      |\n");
     printf(" \t+------------------------------------------------+\n\n");
     Color(0,15);
     system("pause");
     case 3:
     system("cls");
     break;

  }

  }while(choix!=3);

}
/********************************************************************************************************************************/
void modifier(liste *t,char matricule[])
{
    maillon *pos,*prec;
    chaine tab[]={"1.Marque","2.Modele","3.prix","4.Couleur","5.Ne rien modifier"};
    int c=0,choix,existe;
     //pos=rechdict(t,matricule);
     rech_seq(t,matricule,&existe,&prec,&pos);
     if (existe==1)
    {
        printf("\n\n\tQue voulez-vous modifier?");
        choix=menu(tab,5);
        switch (choix)
        {
        case 1:
            textbackground(3);
       textcolor(14);
       printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t    \n");
       printf("\t\t\t\t\t\t  MODIFIER LA MARQUE \t\t\t\t\t\t\t\t\t\t ");
       textbackground(15);
       textcolor(0);
            printf("\n\nVeuillez introduire la nouvelle marque du vehicule :");
            scans(pos->voiture.marque,10);
            break;
        case 2:
            textbackground(3);
       textcolor(14);
       printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t    \n");
       printf("\t\t\t\t\t\t  MODIFIER LE MODELE\t\t\t\t\t\t\t\t\t\t ");
       textbackground(15);
       textcolor(0);
            printf("\n\nVeuillez introduire le nouveau modele du vehicule :");
            scans(pos->voiture.modele,10);
            break;
        case 3:
            textbackground(3);
       textcolor(14);
       printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t    \n");
       printf("\t\t\t\t\t\t   MODIFIER LE PRIX \t\t\t\t\t\t\t\t\t\t ");
       textbackground(15);
       textcolor(0);
            printf("\n\nVeuillez introduire le nouveau prix du vehicule :");
            scanf("%lf",&pos->voiture.prix);
             while(pos->voiture.prix<200000 || pos->voiture.prix>50000000 )
            { Color(15,12);
              printf("  Attention!");Color(0,15);
              printf(" les prix sont limites entre 250000.00 DA et 50000000.00 DA\n ");Color(9,15);
              printf("Veuillez reintroduire le prix en dinar: \n");
              scanf("%lf",&pos->voiture.prix);
            }

            break;

        case 4:
            textbackground(3);
       textcolor(14);
       printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t    \n");
       printf("\t\t\t\t\t\t   MODIFIER LA COULEUR \t\t\t\t\t\t\t\t\t\t ");
       textbackground(15);
       textcolor(0);
            printf("\n Veuillez introduire la nouvelle couleur du vehicule : ");
            scans(pos->voiture.couleur,10);
            while((strlen(pos->voiture.couleur))<4)
            {  printf("\n");
               Color(15,12);
               printf("\a  Attention!");Color(0,15);
               printf(" La couleur doit contenir au moins 4 caracteres\n\n");
               Color(9,15);
               printf("Veuillez reintroduire une autre couleur: ");
               scans(pos->voiture.couleur,10);
            }
           break;
        case 5:
            c=2;
            break;
        }

        if (c!=2)
            {
            textcolor(12);
        printf("\n\n\n La modification a ete faite avec succes.\n\n\n");
        textcolor(0);
        system("pause");}
    }
      else
        {
            textcolor(12);
            printf("\n\n\tLe vehicule que vous souhaitez modifier n'est pas disponible dans le stock.\n\n\n");
            textcolor(0);
            system("pause");
        }
}
/********************************************************************************************************************************/
void debut()
{
    textcolor(0);
      gotoxy(48,10);
      printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
      gotoxy(67,10);
      printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
      gotoxy(86,10);
      textcolor(9);
      printf("%c%c%c",219,219,219);
      textcolor(0);

      gotoxy(48,11);
      printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
      gotoxy(67,11);
      printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
      gotoxy(86,11);
      textcolor(9);
      printf("%c%c%c",219,219,219);
      textcolor(0);

      gotoxy(48,12);
      printf("%c%c%c",219,219,219);
      gotoxy(67,12);
      printf("%c%c%c",219,219,219);
      gotoxy(86,12);
      printf("%c%c%c",220,220,220);

      gotoxy(48,13);
      printf("%c%c%c",219,219,219);
      gotoxy(67,13);
      printf("%c%c%c",219,219,219);
      gotoxy(86,13);
      printf("%c%c%c",219,219,219);

      gotoxy(48,14);
      printf("%c%c%c",219,219,219);
      gotoxy(67,14);
      printf("%c%c%c",219,219,219);
      gotoxy(86,14);
      printf("%c%c%c",219,219,219);

      gotoxy(48,15);
      printf("%c%c%c",219,219,219);
      gotoxy(67,15);
      printf("%c%c%c",219,219,219);
      gotoxy(86,15);
      printf("%c%c%c",219,219,219);

      gotoxy(48,16);
      printf("%c%c%c",219,219,219);
      gotoxy(67,16);
      printf("%c%c%c",219,219,219);
      gotoxy(86,16);
      printf("%c%c%c",219,219,219);

      gotoxy(48,17);
      printf("%c%c%c",219,219,219);
      gotoxy(67,17);
      printf("%c%c%c",219,219,219);
      gotoxy(86,17);
      printf("%c%c%c",219,219,219);


      gotoxy(48,18);
      printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
      gotoxy(67,18);
      printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
      gotoxy(86,18);
      printf("%c%c%c",219,219,219);

      gotoxy(48,19);
      printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
      gotoxy(67,19);
      printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
      gotoxy(86,19);
      printf("%c%c%c",219,219,219);

      gotoxy(48,20);
      printf("%c%c%c",219,219,219);
      gotoxy(79,20);
      printf("%c%c%c",219,219,219);
      gotoxy(86,20);
      printf("%c%c%c",219,219,219);

      gotoxy(48,21);
      printf("%c%c%c",219,219,219);
      gotoxy(79,21);
      printf("%c%c%c",219,219,219);
      gotoxy(86,21);
      printf("%c%c%c",219,219,219);

      gotoxy(48,22);
      printf("%c%c%c",219,219,219);
      gotoxy(79,22);
      printf("%c%c%c",219,219,219);
      gotoxy(86,22);
      printf("%c%c%c",219,219,219);

      gotoxy(48,23);
      printf("%c%c%c",219,219,219);
      gotoxy(79,23);
      printf("%c%c%c",219,219,219);
      gotoxy(86,23);
      printf("%c%c%c",219,219,219);

      gotoxy(48,24);
      printf("%c%c%c",219,219,219);
      gotoxy(79,24);
      printf("%c%c%c",219,219,219);
      gotoxy(86,24);
      printf("%c%c%c",219,219,219);

      gotoxy(48,25);
      printf("%c%c%c",219,219,219);
      gotoxy(79,25);
      printf("%c%c%c",219,219,219);
      gotoxy(86,25);
      printf("%c%c%c",219,219,219);

      gotoxy(48,26);
      printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
      gotoxy(67,26);
      printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
      gotoxy(86,26);
      printf("%c%c%c",219,219,219);

      gotoxy(48,27);
      printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
      gotoxy(67,27);
      printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
      gotoxy(86,27);
      printf("%c%c%c\n",219,219,219);
      textbackground(15);
      textcolor(5);
    printf("\n\n\t\t\t\t            Bienvenue au Programme d'indexation des fichiers \n");
    textcolor(0);
    printf("\t\t_________________________________________________________________________________________________\n\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("\t\t|");
    textcolor(12);
    printf("  Charge des Travaux Diriges et Pratiques:\t\t\t\t\t\t\t");
    textcolor(0);
    printf("|\n\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n\t\t|               \t\t Dr. BOULAKRADECHE\t\t\t\t\t\t\t|\n\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("\t\t|");
    textcolor(12);
    printf( "  Realise par :");
    textcolor(0);
    printf("\t\t\t\t\t\t\t\t\t\t|\n\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n\t\t|\t\t Agoun Juba.\t\t\t\t\t\t\t\t\t\t|\n\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n\t\t|\t\t Kherfellah Redha.\t\t\t\t\t\t\t\t\t|\n\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("\t\t|");
    textcolor(12);
    printf( "  Annee-Groupe:");
    textcolor(0);
    printf("       2 eme annee classes preparatoires integrees-Groupe7.\t\t\t|\n\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n");
    printf("\t\t|_______________________________________________________________________________________________|\n");

    system("pause");
    system("cls");
}
/********************************************************************************************************************************/
