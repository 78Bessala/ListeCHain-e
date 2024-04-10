#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct chaine {
    int val;
    struct chaine* suiv;
    struct chaine* pred;
} chaine;

chaine* create(int valeur) {
    chaine* nouveau = (chaine*)malloc(sizeof(chaine));
    nouveau->val = valeur;
    nouveau->pred = NULL;
    nouveau->suiv = NULL;
    return nouveau;
}

void afficherListe(chaine* ma_liste) {
    chaine* current = ma_liste;
    printf("Liste : ");
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->suiv;
    }
    printf("NULL");
    printf("\n");
}

void affinverse(chaine* ma_liste) {
    chaine* current = ma_liste;
    printf("La liste dans le sens inverse :");
    while (current->suiv != NULL) {
        current = current->suiv;
    }

    while (current != NULL) {
        printf("%d->", current->val);
        current = current->pred;
    }
    printf("NULL");
     printf("\n");
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
        nouveau->pred = current;
    }
}

int main() {
    chaine* ma_liste = NULL;
    int valeur;

    printf("Entrez les éléments de la chaîne (0 pour terminer) : \n");
    while (true) {
        printf("Élément : ");
        scanf("%d", &valeur);
        if (valeur == 0) {
            break;
        }
        ajouterElement(&ma_liste, valeur);
    }

    afficherListe(ma_liste);
    affinverse(ma_liste);

    return 0;
}