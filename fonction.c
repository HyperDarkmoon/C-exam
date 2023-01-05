#include "prototype.h"


void sasirRandonnee(randonnee *pr) {
    printf("Donner la destination\n");
    scanf("%s",pr->destination);
    pr->nbrp=0;
    printf("donner la date\n");
    fflush(stdin);
    do {
        printf("Donner la jour\n");
        scanf("%d",&pr->d.jj);
    } while ((pr->d.jj<1) || (pr->d.jj>31));
    do {
        printf("Donner le mois\n");
        scanf("%d",&pr->d.mm);
    } while ((pr->d.mm<1) || (pr->d.mm>12));
}

int chercherRandonnee(randonnee T[], int n, date d) {
    int i,save;
    save=-1;
    for (i=0;i<n;i++) {
        if ((T[i].d.jj==d.jj)&&(T[i].d.mm==d.mm)) {
            save=i;
        }
    }
    return(save);
}


void ajouterRandonnee(randonnee T[], int *pn, randonnee r) {
    int pos;
    pos = chercherRandonnee(T,*pn,r.d);
    if (pos==-1) {
        T[*pn]=r;
        *pn=*pn+1;
    } else {
        printf("Erreur, la date deja existe!\n");
    }
}

void saisirParticipant(participant *pr) {
    printf("donner la CIN du participant\n");
    scanf("%d",&pr->cinn);
    printf("donner le nom du participant\n");
    scanf("%s",pr->nom);
    printf("Donner la sexe du participant, h pour homme et f pour femme\n");
    fflush(stdin);
    do {
        scanf("%c",&pr->sexe);
        fflush(stdin);
    } while ((pr->sexe!='f') && (pr->sexe!='h'));
}

void ajouterParticipant(randonnee T[],int n, date d) {
    participant pr;
    saisirParticipant(&pr);
    int pos;
    pos = chercherRandonnee(T,n,d);
    if (pos!=-1) {
        T[pos].TP[T[pos].nbrp]=pr;
        T[pos].nbrp=T[pos].nbrp+1;
    } else {
        printf("Erreur, La date n'existe pas!\n");
    }
}

void afficher(randonnee T[],int n) {
    int i,j;
    printf("n = %d\n",n);
    printf("On affiche tout les randonnees\n");
    for (i=0;i<n;i++) {
        printf("La destination: %s\n",T[i].destination);
        printf("Le nombre de participants: %d\n",T[i].nbrp);
        printf("Les participants:\n");
        for (j=0;j<T[i].nbrp;j++) {
            randonnee x=T[i];
            printf("Participant n°%d: \nson CIN: %d\nSon nom: %s\nSa sexe: %c\n",j+1,x.TP[j].cinn,x.TP[j].nom,x.TP[j].sexe);
        }
        printf("La date: %d/%d\n",T[i].d.jj,T[i].d.mm);
    }
}

void taux(randonnee T[],int n,float *pF,float *pH) {
    int i,j;
    int nbrh=0,nbrf=0;
    int nbrParticipantsTotal=0;
    for(i=0;i<n;i++) {
        randonnee x=T[i];
        for (j=0;j<x.nbrp;j++) {
            if (x.TP[j].sexe=='f') {
                nbrf++;
            }
            if (x.TP[j].sexe=='h') {
                nbrh++;
            }
        }
        nbrParticipantsTotal = nbrParticipantsTotal + x.nbrp;
    }
    *pF = nbrf/nbrParticipantsTotal;
    *pH = nbrh/nbrParticipantsTotal;
}


void trier(randonnee T[],int n) {
    int i,j;
    randonnee aux;
    for (i=0;i<n;i++) {
        for(j=0;j<n-1;j++) {
            if (strcmp(T[j].destination,T[j+1].destination)>0) {
                aux=T[j];
                T[j]=T[j+1];
                T[j+1]=aux;
            }
        }
    }
}

void participation(randonnee T[],int n, int tmois[]) {
    int i;
    for (i=0;i<n;i++) {
        int mois = T[i].d.mm;
        tmois[mois-1]=tmois[mois-1]+T[i].nbrp;
    }
}

int hauteSaison(randonnee T[], int n) {
    int tmois[12];
    int i=0;
    for (i=0;i<12;i++) {
        tmois[i]=0;
    }
    participation(T,n,tmois);
    int saison[4];
    saison[0]=tmois[11]+tmois[0]+tmois[1];
    saison[1]=tmois[2]+tmois[3]+tmois[4];
    saison[2]=tmois[5]+tmois[6]+tmois[7];
    saison[3]=tmois[8]+tmois[9]+tmois[10];
    int nbrmaxSaison = 0;
    int posmaxSaison = 0;
    for(i=0;i<4;i++) {
        if (saison[i]>nbrmaxSaison) {
            nbrmaxSaison=saison[i];
            posmaxSaison=i;
        }
    }
    return(posmaxSaison);
}
