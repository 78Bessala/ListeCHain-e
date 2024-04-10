#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct chaine {
    int val;
    struct chaine* suiv;
} chaine;

chaine* create(int valeur) {
    chaine* nouveau = (chaine*)malloc(sizeof(chaine));
    nouveau->val = valeur;
    nouveau->suiv = NULL;
    return nouveau;
}

void ajouterElement(chaine** ma_liste, int valeur) {
    chaine* nouveau = create(valeur);

    if (*ma_liste == NULL) {
        *ma_liste = nouveau;
    } else {
        chaine* current = *ma_liste;
        while (current->suiv != NULL) {
            current = current->suiv;
        }
        current->suiv = nouveau;
    }
}

void afficherListe(chaine* ma_liste) {
    chaine* current = ma_liste;
    printf("Liste : ");
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->suiv;
    }
    printf("\n");
}

void afficherDernierePosition(chaine* ma_liste, int valeur) {
    int position = -1;
    int indice = 0;
    chaine* current = ma_liste;

    while (current != NULL) {
        if (current->val == valeur) {
            position = indice;
        }
        current = current->suiv;
        indice++;
    }

    printf("Dernière position de la valeur %d : %d\n", valeur, position);
}

int main() {
    chaine* ma_liste = NULL;
    int valeur, element;

    printf("Entrez les éléments de la liste chaînée (-1 pour terminer) : \n");
    while (true) {
        printf("Élément : ");
        scanf("%d", &element);
        if (element == -1) {
            break;
        }
        ajouterElement(&ma_liste, element);
    }

    printf("Entrez la valeur dont vous souhaitez trouver la dernière position : ");
    scanf("%d", &valeur);

    printf("Liste : \n");
    afficherListe(ma_liste);

    afficherDernierePosition(ma_liste, valeur);

    return 0;
}