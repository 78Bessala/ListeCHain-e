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
    printf("NULL");
    printf("\n");
}

void supprimerOccurrences(chaine** ma_liste, int valeur) {
    chaine* current = *ma_liste;
    chaine* previous = NULL;

    while (current != NULL) {
        if (current->val == valeur) {
            if (previous == NULL) {
                // Cas où la première occurrence est à supprimer
                *ma_liste = current->suiv;
                free(current);
                current = *ma_liste;
            } else {
                // Cas où une occurrence en milieu ou fin de liste est à supprimer
                previous->suiv = current->suiv;
                free(current);
                current = previous->suiv;
            }
        } else {
            // Passer à l'élément suivant
            previous = current;
            current = current->suiv;
        }
    }
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

    printf("Entrez la valeur à supprimer de la liste : ");
    scanf("%d", &valeur);

    printf("Liste avant la suppression : \n");
    afficherListe(ma_liste);

    supprimerOccurrences(&ma_liste, valeur);

    printf("Liste après la suppression : \n");
    afficherListe(ma_liste);

    return 0;
}