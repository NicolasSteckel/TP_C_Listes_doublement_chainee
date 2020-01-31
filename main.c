#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Element Element;
struct Element
{
	int nombre;
	Element *suivant;
	Element*precedent;
};

typedef struct File File;
struct File
{
    Element *premier;
    Element*dernier;
};


void Init(File *l)
{
   l->premier = NULL;
   l->dernier = NULL;
}



void AjoutBas(File *l, int valeur)
{
   Element *nouv = malloc(sizeof(Element));
   if(!nouv) exit(EXIT_FAILURE);
   nouv->nombre = valeur;
   nouv->precedent = l->dernier;
   nouv->suivant = NULL;
   if(l->dernier) l->dernier->suivant = nouv;
   else l->premier = nouv;
   l->dernier = nouv;
}

void AjoutHaut(File *l, int valeur)
{
   Element *nouv = malloc(sizeof(Element));
   if(!nouv) exit(EXIT_FAILURE);
   nouv->nombre = valeur;
   nouv->suivant = l->premier;
   nouv->precedent = NULL;
   if(l->premier) l->premier->precedent = nouv;
   else l->dernier = nouv;
   l->premier = nouv;
}


int RetirerBas(File *l)
{
   int valeur;
   Element *tmp = l->dernier;
   if(!tmp) return -1;
   valeur = tmp->nombre;
   l->dernier = tmp->precedent;
   if(l->dernier) l->dernier->suivant = NULL;
   else l->premier = NULL;
   free(tmp);
   return valeur;
}


int RetirerHaut(File *l)
{
   int valeur;
   Element *tmp = l->premier;
   if(!tmp) return -1;
   valeur = tmp->nombre;
   l->premier = tmp->suivant;
   if(l->premier)l->premier->precedent = NULL;
   else l->dernier = NULL;
   free(tmp);
   return valeur;
}


void View(File l)
{
   Element *pElement = l.premier;
   while(pElement)
   {
     printf("%d\n",pElement->nombre);
     pElement = pElement->suivant;
   }
}


void Clear(File *l)
{
   Element *tmp;
   Element *pElement = l->premier;
   while(pElement)
   {
     tmp = pElement;
     pElement = pElement->suivant;
     free(tmp);
   }
   l->premier = NULL;
   l->dernier = NULL;
}

int main()
{

    File MaListe;

        Init(&MaListe);

        AjoutHaut(&MaListe,10);
        AjoutBas(&MaListe,20);
        AjoutHaut(&MaListe,40);
        AjoutBas(&MaListe,50);

        View(MaListe);

        Clear(&MaListe);


    return 0;
}
