#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int busID;
    char destination[50];
    int seatsAvailable;
} Bus;

typedef struct {
    int reservationID;
    char travelerName[50];
    int busID;
} Reservation;

typedef struct {
    int travelerID;
    char travelerName[50];
} Traveler;

Bus buses[10];
Reservation reservations[100];
Traveler travelers[100];

int numBuses = 0;
int numReservations = 0;
int numTravelers = 0;

void createBus() {
    printf("\nEnter Bus Details:\n");
    printf("Bus ID: ");
    scanf("%d", &buses[numBuses].busID);
    printf("Destination: ");
    scanf("%s", buses[numBuses].destination);
    printf("Seats Available: ");
    scanf("%d", &buses[numBuses].seatsAvailable);
    numBuses++;
    printf("Bus created successfully.\n");
}

void createTraveler() {
    printf("\nEnter Traveler Details:\n");
    printf("Traveler ID: ");
    scanf("%d", &travelers[numTravelers].travelerID);
    printf("Name: ");
    scanf("%s", travelers[numTravelers].travelerName);
    numTravelers++;
    printf("Traveler account created successfully.\n");
}

void createReservation() {
    printf("\nEnter Reservation Details:\n");
    printf("Reservation ID: ");
    scanf("%d", &reservations[numReservations].reservationID);
    printf("Traveler Name: ");
    scanf("%s", reservations[numReservations].travelerName);
    printf("Bus ID: ");
    scanf("%d", &reservations[numReservations].busID);
    numReservations++;
    printf("Reservation created successfully.\n");
}

void displayBusDetails() {
    printf("\nBus Details:\n");
    for (int i = 0; i < numBuses; i++) {
        printf("Bus ID: %d, Destination: %s, Seats Available: %d\n",
               buses[i].busID, buses[i].destination, buses[i].seatsAvailable);
    }
}

void displayReservationDetails() {
    printf("\nReservation Details:\n");
    for (int i = 0; i < numReservations; i++) {
        printf("Reservation ID: %d, Traveler Name: %s, Bus ID: %d\n",
               reservations[i].reservationID, reservations[i].travelerName, reservations[i].busID);
    }
}

void modifyReservationDetails() {
    int reservationID;
    printf("\nEnter Reservation ID to modify: ");
    scanf("%d", &reservationID);

    for (int i = 0; i < numReservations; i++) {
        if (reservations[i].reservationID == reservationID) {
            printf("Modify Reservation Details:\n");
            printf("Traveler Name: ");
            scanf("%s", reservations[i].travelerName);
            printf("Bus ID: ");
            scanf("%d", &reservations[i].busID);
            printf("Reservation modified successfully.\n");
            return;
        }
    }

    printf("Reservation ID not found.\n");
}

int main() {
    int choice;

    do {
        printf("\nE-Bus Menu:\n");
        printf("1. Create a new traveler account\n");
        printf("2. Create a new reservation\n");
        printf("3. Display bus details\n");
        printf("4. Display and modify reservation details\n");
        printf("0. Quit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createTraveler();
                break;
            case 2:
                createReservation();
                break;
            case 3:
                displayBusDetails();
                break;
            case 4:
                displayReservationDetails();
                modifyReservationDetails();
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
