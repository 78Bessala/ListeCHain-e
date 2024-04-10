#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct NumberListe{
    int val;
    struct NumberListe *suivant;
}NumberListe;

int main(){
    NumberListe *ma_liste=NULL,*tete=NULL,*new;
    tete=malloc(sizeof(NumberListe));
     if (tete == NULL) {
        printf("Erreur lors de l'allocation de mémoire\n");
        return 1;
    }
    
    printf("Veuillez entrer l'élément de tête : ");
    scanf("%d", &(tete->val));
    tete->suivant = NULL;
    ma_liste = tete;

     //les autres elements
     int continuer=1;

     while(continuer !=0){
        int valeur;
        printf("Veuillez entrer la valeur suivante\n");
        scanf("%d",&valeur);
        printf("\t pour sortir de la boucle entrer -1 au prochain tour\n");
        if(valeur==-1){
            continuer=0;
        }else{
            new=malloc(sizeof(NumberListe));
            if(new==NULL){
                printf("Erreur de segmentation !!\n");
                return 1;
            }
            new->val=valeur;
            new->suivant=NULL;
            ma_liste->suivant=new;
            ma_liste=new;
        }
     }

    
    // Afficher la liste chaînée

    printf("Liste chaînée : ");
    ma_liste=tete;
    while (ma_liste != NULL) {
        printf("%d -> ", ma_liste->val);
        ma_liste = ma_liste->suivant;
    }
    printf("NULL\n");
    
    // Libérer la mémoire
    
   free(tete);
    return 0;
}