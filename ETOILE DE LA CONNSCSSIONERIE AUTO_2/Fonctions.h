#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
/********************************************************************************************************************************/
typedef char chaine[60];
typedef struct maillon maillon;
typedef struct automobile automobile;
typedef struct liste liste;
/************************STRUCTURE DU TP****************************************************************************************/
struct automobile
{
    char numero[15];
    int annee;
    char marque[10];
    char modele[10];
    char couleur[10];
    double prix;
};

struct maillon
{
    automobile voiture;
    maillon *suiv;
};

struct liste
{
    maillon *tete;
    int nb;
};
/***************************** PROCEDURE DU TP********************************************************************************/
maillon* allouer();

void aff_adr(maillon *p,maillon *q);

maillon* suivant(maillon *p);
/***************************** MODELE LLC ********************************************************************************/

void affichage(liste *t);//affichage du stck

void tri_insertion_lst(liste *t);//trie par insertion

void choixmodele(liste *t,char mar[],char mod[]);//affichage de l’année et du prix de chacune des voitures de la marque et du modèle

void choixprix(liste *t,double prixinf,double prixsup);//recherche par fourchette de prix

void rech_seq(liste *t,char num[],int *existe,maillon **pre,maillon **posit); //rechere d'un vehicule dans une llc sequentiellement

void newauto(liste *t,automobile vehicule,int *new);// ajout d'un vehicule dans une llc

void casse(liste *t,char num[],int *old,int *nef);//suprime un vehicule par son immatriculation

void permut(maillon *p, maillon *q);// permut le deux entre deux pointeur les champs pointe

void tri_bul_llc(liste *t); //trie une llc par trie a bulle

void retrier(liste *t);//triée sur les marques dans l’ordre alphabétique, et à marque égale, sur les prix décroissant

maillon* rech_pos(liste *t,int pos);//fonction qui retourne @ d'une position

maillon* ptr_petitnum(liste *t,int b1,int b2);//fonction qui retourne le @ de la petite imatriculation

void tri_sel_llc(liste *t);//tri par selection

maillon* rechdict(liste *l,char num[]);//recherche decotomique


void Color(int couleurDuTexte,int couleurDeFond);

void aide();//aide et renseignement

void modifier(liste *t,char matricule[]);//fonction qui permet de modifier les information du vehicule

int menu(chaine* t ,int n);//fonction du menu simple(secondaire)

int menuprin(chaine* t ,int n,int r);// fonction du menu principale

void debut(); //entete

void Tri1t (liste l,int n);//comptage a une seul table
/**********************************FONCTION CHANINE.C********************************************************************/
int scans(char s[],int a);// pour lire une chaine

int matoint (char num[]); //rend la matricule en un entier

void clearbuff(); // Vider le buffer

int strtoint (char s[]);//transforme les chiffre de type char vers int

char *maj(char *str);//trnasform une chaine en majiscule

void textbackground (int color);

void gotoxy(int x,int y);

int NBEP (int i,liste l,int ti);

void textcolor (int color);
