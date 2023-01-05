#include "prototype.h"

int main() {
    int choix;
    randonnee pr;
    randonnee T[50];
    date d;
    float pF,pH;
    int pn;
    randonnee r;
    int saison;
    do {
        printf("Saisir votre choix \n");
        printf("1-Ajouter une randonnee dans le tableau\n");
        printf("2-Ajouter un participant a une randonne\n");
        printf("3-Afficher les randonnees\n");
        printf("4-Afficher le taux de participation des hommes et des femmes\n");
        printf("5-Trier les randonnees selon l'ordre croissant des destinations\n");
        printf("6-Afficher la plus haute saison\n");
        printf("0-Quitter\n");
        printf("donner votre choix \n");
        scanf("%d",&choix);
        switch(choix) {
            case 1:
                sasirRandonnee(&pr);
                ajouterRandonnee(T,&pn,pr);
                break;
            case 2:
                printf("donner la date de participation\n");
                do {
                    printf("Donner la jour\n");
                    scanf("%d",&d.jj);
                } while ((d.jj<1) || (d.jj>31));
                do {
                    printf("Donner le mois\n");
                    scanf("%d",&d.mm);
                } while ((d.mm<1) || (d.mm>12));
                ajouterParticipant(T,pn,d);
                break;
            case 3:
                afficher(T,pn);
                break;
            case 4:
                taux(T,pn,&pF,&pH);
                printf("Le taux da participation des femmes = %f\nLe taux de participation des hommes = %f",pF,pH);
                break;
            case 5:
                trier(T,pn);
                break;
            case 6:
                saison=hauteSaison(T,pn);
                switch(saison) {
                    case 0:
                        printf("La saison ayant le maximum de participants est l'Hiver");
                        break;
                    case 1:
                        printf("La saison ayant le maximum de participants est le Printems");
                        break;
                    case 2:
                        printf("La saison ayant le maximum de participants est l'Ete");
                        break;
                    case 3:
                        printf("La saison ayant le maximum de participants est l'Autonme");
                        break;
                }
                break;
            case 0:
                printf("Program termine\n");
                break;
            default :
                printf("choix invalid\n");
                break;
        }
    } while (choix!=0);
    return 0;
}
