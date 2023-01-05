#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int jj;
    int mm;
}date;

typedef struct {
    int cinn;
    char nom[50];
    char sexe;
}participant;

typedef struct {
    char destination[50];
    int nbrp;
    participant TP[50];
    date d;
}randonnee;

void sasirRandonnee(randonnee *pr);
int chercherRandonnee(randonnee T[], int n, date d);
void ajouterRandonnee(randonnee T[],int *pn, randonnee r);
void ajouterParticipant (randonnee T[], int n, date d);
void afficher(randonnee T[], int n);
void taux(randonnee T[], int n, float *pF, float *pH);
void trier(randonnee T[],int n);
void participation (randonnee T[], int n, int tmois[]);
int hauteSaison(randonnee T[], int n);
