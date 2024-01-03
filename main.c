#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int identifiantBus;
    char destination[50];
    int placesDisponibles;
} Bus;

typedef struct {
    int identifiantReservation;
    char nomVoyageur[50];
    int identifiantBus;
} Reservation;

typedef struct {
    int identifiantVoyageur;
    char nomVoyageur[50];
} Voyageur;

Bus autobus[10];
Reservation reservations[100];
Voyageur voyageurs[100];

int nbAutobus = 0;
int nbReservations = 0;
int nbVoyageurs = 0;

void creerAutobus() {
    printf("\nEntrez les détails de l'autobus :\n");
    printf("Identifiant de l'autobus : ");
    scanf("%d", &autobus[nbAutobus].identifiantBus);
    printf("Destination : ");
    scanf("%s", autobus[nbAutobus].destination);
    printf("Places disponibles : ");
    scanf("%d", &autobus[nbAutobus].placesDisponibles);
    nbAutobus++;
    printf("Autobus créé avec succès.\n");
}

void creerVoyageur() {
    printf("\nEntrez les détails du voyageur :\n");
    printf("Identifiant du voyageur : ");
    scanf("%d", &voyageurs[nbVoyageurs].identifiantVoyageur);
    printf("Nom : ");
    scanf("%s", voyageurs[nbVoyageurs].nomVoyageur);
    nbVoyageurs++;
    printf("Compte voyageur créé avec succès.\n");
}

void creerReservation() {
    printf("\nEntrez les détails de la réservation :\n");
    printf("Identifiant de la réservation : ");
    scanf("%d", &reservations[nbReservations].identifiantReservation);
    printf("Nom du voyageur : ");
    scanf("%s", reservations[nbReservations].nomVoyageur);
    printf("Identifiant de l'autobus : ");
    scanf("%d", &reservations[nbReservations].identifiantBus);
    nbReservations++;
    printf("Réservation créée avec succès.\n");
}

void afficherDetailsAutobus() {
    printf("\nDétails de l'autobus :\n");
    for (int i = 0; i < nbAutobus; i++) {
        printf("Identifiant de l'autobus : %d, Destination : %s, Places disponibles : %d\n",
               autobus[i].identifiantBus, autobus[i].destination, autobus[i].placesDisponibles);
    }
}

void afficherDetailsReservation() {
    printf("\nDétails de la réservation :\n");
    for (int i = 0; i < nbReservations; i++) {
        printf("Identifiant de la réservation : %d, Nom du voyageur : %s, Identifiant de l'autobus : %d\n",
               reservations[i].identifiantReservation, reservations[i].nomVoyageur, reservations[i].identifiantBus);
    }
}

void modifierDetailsReservation() {
    int identifiantReservation;
    printf("\nEntrez l'identifiant de la réservation à modifier : ");
    scanf("%d", &identifiantReservation);

    for (int i = 0; i < nbReservations; i++) {
        if (reservations[i].identifiantReservation == identifiantReservation) {
            printf("Modifier les détails de la réservation :\n");
            printf("Nom du voyageur : ");
            scanf("%s", reservations[i].nomVoyageur);
            printf("Identifiant de l'autobus : ");
            scanf("%d", &reservations[i].identifiantBus);
            printf("Réservation modifiée avec succès.\n");
            return;
        }
    }

    printf("Identifiant de la réservation introuvable.\n");
}

int main() {
    int choix;

    do {
        printf("\nMenu E-Bus :\n");
        printf("1. Créer un nouveau compte voyageur\n");
        printf("2. Créer une nouvelle réservation\n");
        printf("3. Afficher les détails des autobus\n");
        printf("4. Afficher et modifier les détails d'une réservation\n");
        printf("0. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                creerVoyageur();
                break;
            case 2:
                creerReservation();
                break;
            case 3:
                afficherDetailsAutobus();
                break;
            case 4:
                afficherDetailsReservation();
                modifierDetailsReservation();
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 0);

    return 0;
}
