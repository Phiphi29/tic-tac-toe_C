#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Initialisation.h"
#include "Fonctions.h"
#define M 3

int main()
{
    int replay = 0;
    do
    {
        int tab[M][M] = {0};
        int pions[M][M] = {0};
        int tour = 0, correcteur = 0;

        init_plateau(tab);
        aff_plateau(tab);
        aff_pions(tab,pions);
        for(tour = 0; tour < 9; tour++)
        {
            system("cls");
            aff_plateau(tab);
            aff_pions(tab,pions);
            dpt(tab, pions, tour, &correcteur);
            aff_pions(tab,pions);
            tour = tour - correcteur;
            correcteur = 0;
        }

        gotoligcol(14, 25);
        color(15, 0);
        printf("Saisir 1 pour recommencer une partie, saisir 0 pour quitter : ");
        scanf("%d", &replay);

    }while(replay == 1);

    gotoligcol(15, 0);
    color(0, 0);
    return 0;
}
