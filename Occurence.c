#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct bess{
    int val;
    struct bess *suiv;
}bess;

void rechercheDerniereOccurrence(bess* liste, int element) {
    int positionDerniereOccurrence = -1;

    bess* courant = liste;
    int index = 0;

    while (courant != NULL) {
        if (courant->val == element) {
            positionDerniereOccurrence = index;
        }

        courant = courant->suiv;
        index++;
    }

    if (positionDerniereOccurrence != -1) {
        printf("La valeur %d est présente dans la liste à la position %d .\n", element, positionDerniereOccurrence);
    } else {
        printf("La valeur %d n'est pas présente dans la liste.\n", element);
    }
}

int main(){
     bess *ma_liste=NULL,*tete=NULL,*new;
    tete=malloc(sizeof(bess));
     if (tete == NULL) {
        printf("Erreur lors de l'allocation de mémoire\n");
        return 1;
    }
    
    printf("Veuillez entrer l'élément de tête : ");
    scanf("%d", &(tete->val));
    tete->suiv = NULL;
    ma_liste=tete;

     //les autres elements
    int continuer=1;

    while(continuer !=0){
        int valeur;
        printf("Veuillez entrer la valeur suivante\n");
        scanf("%d",&valeur);
        
        if(valeur==-1){
            continuer=0;
        }else{
            new=malloc(sizeof(bess));
            
            if(new==NULL){
                printf("Erreur de segmentation !!\n");
                return 1;
            }
            printf("\t pour sortir de la boucle entrer -1 au prochain tour\n");

            new->val=valeur;
            new->suiv=NULL;
            ma_liste->suiv=new;
            ma_liste=new;
        }
    }
    printf("\t LA LISTE REMPLIT  AVEC SUCCESS!! \n");
    //recherche
    int element;
    printf("Veuillez l'element à rechercher\n");
    scanf("%d",&element);
    rechercheDerniereOccurrence(ma_liste,element);

//liberation de la memoire
    
    free(tete);

    return 0;

}