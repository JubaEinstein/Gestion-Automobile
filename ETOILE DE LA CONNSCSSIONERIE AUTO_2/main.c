#include "Fonctions.h"
#include "conio.c"
#include"conio2.h"
#include"time.h"
#define scanf fflush(stdin);scanf
///programme de gestion de stock pour concessionaire automobile.
///realise par :*Agoun Juba & *Kherfellah Redha
int back=15;
int select_back=1;
int color=1;
int select_color=15;


int main ()
{   //declaration des variable du programme
    int choix=0;

    liste repere_llc;
    repere_llc.tete=NULL;
    repere_llc.nb=0;
    chaine tab[] = {"1.Indexe le repertoire. ","2.Actualise le reprertoire.","3.Afficher la table d'indexation","4.Ajouter des fichiers au repertoire","5.Rechercher un mot dans le repertoire.","6.Rechercher 2 mot dans la meme ligne dans le repertoire.","7.Quitter le programme."};
    chaine tab2[] ={"Oui","Non"};
     system("color F0");
    //Affichage des renseigement naicessaire au programme
      //le menu du programme et cela on utilisons le switch
      debut();

    do
      {
       system("cls");
       textbackground(3);
       textcolor(14);        ///le menu
       printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t    \n");
       printf("\t\t\t\t\t       ***\tINDEX-PRO\t***\t\t\t\t\t\t\t\t\t\t\t ");
       textbackground(15);
       textcolor(0);
       choix = menuprin(tab,6,repere_llc.nb);//le menu principale
           switch(choix)
           {
         case 1:

                system("cls");
                textbackground(3);
                textcolor(14);
                printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t    \n");
                printf("\t\t\t\t\t\t   INDEXATION DU REPERTOIRE  \t\t\t\t\t\t\t\t\t\t\n ");
                textbackground(15);
                textcolor(0);

            system("pause");


          break;
        case 2:


            system("cls");
           textbackground(3);
       textcolor(14);
       printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t    \n");
       printf("\t\t\t\t\t\t    ACTUALISE LE REPERTOIRE \t\t\t\t\t\t\t\t\t\t\t ");
       textbackground(15);
       textcolor(0);

            system("pause");

          break;
        case 3://AFFICHAGE de la table apartir du fichier index
            system("cls");

            textbackground(3);
       textcolor(14);
       printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t    \n");
       printf("\t\t\t\t\t\t AFFICHAGE DE LA TABLE D'INDEXATION \t\t\t\t\t\t\t ");
       textbackground(15);
       textcolor(0);

        system("pause");


            break;
        case 4://Rechchercher un mot dans le fichier d'index
            system("cls");
           textbackground(3);
       textcolor(14);
       printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t    \n");
       printf("\t\t\t\t\t RECHERCHE DE LA PREMIER OCCURRANCE DANS LE REPERTOIRE \t\t\t\t\t\t\t ");
       textbackground(15);
       textcolor(9);

            printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            system("pause");

            break;
        case 5://Afficher toutes les voiture.
            system("cls");
            textbackground(3);
             textcolor(14);
             printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t    \n");
            printf("\t\t\t\t\t\t RECHERCHE DE DEUX MOTS DANS LE REPERTOIRE \t\t\t\t\t\t\t\t ");
           textbackground(15);
             printf("\n\n\t\t\t\t\t\t");
            system("pause");

            break;

        case 9://modification des information sur les vehicules

            break;



        case 7://Supprimer une voiture
             system("cls");


        case 8:///aide et renseignement
               clrscr();

            break;
        case 6:///pour quitter notre programme
            textbackground(3);
       textcolor(14);
       printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t    \n");
       printf("\t\t\t\t\t\t ETOILE DE LA CONCESSION AUTOMOBILE\t\t\t\t\t\t\t\t ");
       textbackground(15);
       textcolor(0);
       int choix2;
          printf("\t\t\n\nVoulez-vous vraiment quitter le programme?");//confirmation pour quitter
          choix2=menu(tab2,2);
          switch (choix2)
          {
        case 1:
             textbackground(3);
            textcolor(14);
             printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t    \n");
             printf("\t\t\t\t\t\t INDEX-PRO \t\t\t\t\t\t\t\t ");
             textbackground(15);
             textcolor(1);


    printf("\n\n\n\t\t\t\t\t\t        MERCI D'AVOIR UTILISER NOTRE PROGRAMME.\n\n\n\n      ");
    textcolor(9);
    printf("\t\t\t ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²                  ²²²²²²²²²²        ²²      ²²²²²²²²²²²²²²\n");
    printf("\t\t\t ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²             ²²²²²²²²²²²²²²²²²²   ²²²      ²²²²²²²²²²²²²²\n");
    printf("\t\t\t     ²²²²²²²²²²²²²²²²²²²²²²²²²²²           ²²²²²²²        ²²²²²²²²²²²          ²²²²²²\n");
    printf("\t\t\t     ²²²²²²                 ²²²²²         ²²²²²               ²²²²²²²          ²²²²²²\n");
    printf("\t\t\t     ²²²²²²                   ²²²²       ²²²²                  ²²²²²²          ²²²²²²\n");
    printf("\t\t\t     ²²²²²²                    ²²²       ²²²²²                  ²²²²²          ²²²²²²\n");
    printf("\t\t\t     ²²²²²²          ²²²        ²²       ²²²²²²                   ²²²          ²²²²²²\n");
    printf("\t\t\t     ²²²²²²          ²²²         ²        ²²²²²²²²                 ²²          ²²²²²²\n");
    printf("\t\t\t     ²²²²²²         ²²²²                  ²²²²²²²²²²²                          ²²²²²²\n");
    printf("\t\t\t     ²²²²²²        ²²²²²                    ²²²²²²²²²²²²²²²                    ²²²²²²\n");
    printf("\t\t\t     ²²²²²²²²²²²²²²²²²²²                      ²²²²²²²²²²²²²²²²²                ²²²²²²\n");
    printf("\t\t\t     ²²²²²²²²²²²²²²²²²²²                         ²²²²²²²²²²²²²²²²²²            ²²²²²²\n");
    printf("\t\t\t     ²²²²²²        ²²²²²                               ²²²²²²²²²²²²²²          ²²²²²²\n");
    printf("\t\t\t     ²²²²²²         ²²²²                                     ²²²²²²²²²         ²²²²²²\n");
    printf("\t\t\t     ²²²²²²          ²²²          ²       ²²²²                    ²²²²²        ²²²²²²\n");
    printf("\t\t\t     ²²²²²²          ²²²         ²²       ²²²²                     ²²²²        ²²²²²²\n");
    printf("\t\t\t     ²²²²²²                     ²²²       ²²²²                     ²²²²        ²²²²²²\n");
    printf("\t\t\t     ²²²²²²                    ²²²        ²²²²²²                   ²²²²        ²²²²²²\n");
    printf("\t\t\t     ²²²²²²                  ²²²²²        ²²²²²²                 ²²²²²         ²²²²²²\n");
    printf("\t\t\t     ²²²²²²                ²²²²²²²        ²²²²²²²²²            ²²²²²²          ²²²²²²\n");
    printf("\t\t\t ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²         ²²²² ²²²²²²²²²²²²²²²²²²²²²       ²²²²²²²²²²²²²²\n");
    printf("\t\t\t ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²         ²²²    ²²²²²²²²²²²²²²²²          ²²²²²²²²²²²²²²\n\n\n\n\n ");

                choix=9;
            break;
        case 2:
        choix=0;
            break;
          }
   }
}
    while (choix!=9);



    return 0;
}
int menuprin(chaine* t ,int n,int r)
{

    gotoxy(5,20);
    printf("  Deplacez-vous dans le menu avec les touches Bas-Haut.\n");
    gotoxy(1,40);
    textbackground(3);
     printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\n");
      textcolor(0);
     time_t Nbr=time(NULL);
     struct tm pTime;
     pTime=*(localtime(&Nbr));
     printf("La Date : %d /",pTime.tm_mday);
     printf("%d/",pTime.tm_mon+1);
     printf("%d",pTime.tm_year+1900);
     printf("\t\t\t\t\t\t\t\t\tNombre de fichier indexe:%d\t",r);
     textcolor(15);
    gotoxy(1,4);
    textbackground(15);
    int i;

    char c,c2 ;
    int cste = wherey()-1;
    printf(" \t\t\t Menu Du Programme \n\n\t");

    textcolor(select_color);textbackground(select_back);
    for( i = 0 ; i< n ;i++)
    {
        printf(" - %s \n",t[i]);
        textcolor(color);textbackground(back);
        if ( i  != n-1) printf("\t");
    }
    i=1;
    while(1)
    {
         c = getch();
          if (c == -32 ) c2 = getch();

         if( c == 13 ) goto fin;
         else if( c == -32 )
         {
             if(c2 == 72 && i > 1)
             {
                     gotoxy(1,i+1+cste);
                     textcolor(color);textbackground(back);
                     printf("\t");
                     textcolor(select_color);textbackground(select_back);
                     printf(" - %s \n",t[i-2]);
                     textcolor(color);textbackground(back);
                     printf("\t");
                     printf(" - %s ",t[i-1]);
                     i--;
             }
             else if (c2==72 && i==1)
             {
                    gotoxy(1,cste+2+n);
                     textcolor(color);textbackground(back);
                     printf("\t");
                     textcolor(select_color);textbackground(select_back);
                     printf(" - %s \n",t[n-1]);
                     gotoxy(1,cste+2+i);
                     textcolor(color);textbackground(back);
                     printf("\t");
                     printf(" - %s ",t[0]);
                     i=n;
             }
             else if( c2 == 80 && i < n)
             {
                     gotoxy(1,i+2+cste);
                     textcolor(color);textbackground(back);
                     printf("\t");
                     printf(" - %s \n",t[i-1]);
                     printf("\t");
                     textcolor(select_color);textbackground(select_back);
                     printf(" - %s ",t[i]);
                     i++;
             }
             else if ( c2 == 80 && i==n)
             {
                     gotoxy(1,i+2+cste);
                     textcolor(color);textbackground(back);
                     printf("\t");
                     printf(" - %s \n",t[n-1]);
                     i=1;
                     gotoxy(1,cste+2+i);
                     printf("\t");
                     textcolor(select_color);textbackground(select_back);
                     printf(" - %s ",t[i-1]);
             }
         }
    }
    fin:
    textcolor(color);textbackground(back);
    clrscr();
    return i;
}
int menu(chaine* t ,int n)
{

    int i;

    char c,c2 ;
    int cste = wherey()-1;

    printf(" \t\t\t  \n\n\t");

    textcolor(select_color);
    textbackground(select_back);
    for( i = 0 ; i< n ;i++)
    {
        printf(" - %s \n",t[i]);
        textcolor(color);textbackground(back);
        if ( i  != n-1) printf("\t");
    }
    i=1;
    while(1)
    {
         c = getch();
          if (c == -32 ) c2 = getch();

         if( c == 13 ) goto fin;
         else if( c == -32 )
         {
             if(c2 == 72 && i > 1)
             {
                     gotoxy(1,i+1+cste);
                     textcolor(color);textbackground(back);
                     printf("\t");
                     textcolor(select_color);textbackground(select_back);
                     printf(" - %s \n",t[i-2]);
                     textcolor(color);textbackground(back);
                     printf("\t");
                     printf(" - %s ",t[i-1]);
                     i--;
             }
             else if (c2==72 && i==1)
             {
                    gotoxy(1,cste+2+n);
                     textcolor(color);textbackground(back);
                     printf("\t");
                     textcolor(select_color);textbackground(select_back);
                     printf(" - %s \n",t[n-1]);
                     gotoxy(1,cste+2+i);
                     textcolor(color);textbackground(back);
                     printf("\t");
                     printf(" - %s ",t[0]);
                     i=n;
             }
             else if( c2 == 80 && i < n)
             {
                     gotoxy(1,i+2+cste);
                     textcolor(color);textbackground(back);
                     printf("\t");
                     printf(" - %s \n",t[i-1]);
                     printf("\t");
                     textcolor(select_color);textbackground(select_back);
                     printf(" - %s ",t[i]);
                     i++;
             }
             else if ( c2 == 80 && i==n)
             {
                     gotoxy(1,i+2+cste);
                     textcolor(color);textbackground(back);
                     printf("\t");
                     printf(" - %s \n",t[n-1]);
                     i=1;
                     gotoxy(1,cste+2+i);
                     printf("\t");
                     textcolor(select_color);textbackground(select_back);
                     printf(" - %s ",t[i-1]);
             }
         }
    }
    fin:
    textcolor(color);textbackground(back);
    clrscr();
    return i;
}






