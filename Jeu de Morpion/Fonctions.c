#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Initialisation.h"
#define M 3

void aff_plateau(int tab[M][M])
{
    int x = 0, y = 0, z = 0;

    gotoligcol(1, 40);
    color(15, 0);
    printf("Jeu de Morpion");

    for(x = 0; x < M; x++)
    {
        for(y = 0; y < M; y++)
        {
            gotoligcol(5 + x, 20 + (y * 3));
            if(tab[x][y] == 1)
            {
                color(0, 7);
                printf("   ");
                color(0, 0);
            }
            if(tab[x][y] == 2)
            {
                color(0, 8);
                printf("   ");
                color(0, 0);
            }
        }
    }

    gotoligcol(8, 21);
    color(15, 0);
    printf("1  2  3");
    for(z = 1; z < M + 1; z++)
    {
        gotoligcol(4 + z, 30);
        printf("%d", z);
    }
    color(0, 0);
}

void aff_pions(int tab[M][M], int pions[M][M])
{
    int x = 0, y = 0;

    for(x = 0; x < M; x++)
    {
        for(y = 0; y < M; y++)
        {
            gotoligcol(5 + x, 20 + (y * 3));
            if(tab[x][y] == 1)
                color(0, 7); // Case pair
            else if(tab[x][y] == 2)
                color(0, 8); // Case impair

            if(pions[x][y] == 0)
                printf("   "); // Pas de pion
            else if(pions[x][y] == 1)
                printf(" X "); // Pion du joueur n°1
            else if(pions[x][y] == 2)
                printf(" O "); // Pion du joueur n°2
        }
    }
    color(0, 0);
}

void dpt(int tab[M][M], int pions[M][M], int tour, int *correcteur)
{
    int posx = 0, posy = 0, k = 0;

    k = tour % 2 + 1;
    color(15, 0);

    if(k == 1)
    {
        gotoligcol(4, 40);
        printf("Tour du joueur 1");
    }
    else if(k == 2)
    {
        gotoligcol(4, 40);
        printf("Tour du joueur 2");
    } // Indique le tour des joueurs

    gotoligcol(8, 40);
    printf("Saisir les coordonnees de la case : ");
    gotoligcol(9, 40);
    printf(" - Ligne : ");
    scanf("%d", &posx);
    gotoligcol(10, 40);
    printf(" - Colonne : ");
    scanf("%d", &posy); // Demande des coordonnees a l'utilisateur

    posx = posx - 1;
    posy = posy - 1; // Passage du repere de l'utilisateur a celui du tableau

    if(pions[posx][posy] != 0 || posx > M || posx < 0 || posy > M || posy < 0) // Blindage (case occupee ou coordonnees pas dans le tableau)
        *correcteur = 1;
    else
        pions[posx][posy] = k;

    if((pions[0][0] == 1 && pions[0][1] == 1 && pions[0][2] == 1) //ligne
    || (pions[1][0] == 1 && pions[1][1] == 1 && pions[1][2] == 1)
    || (pions[2][0] == 1 && pions[2][1] == 1 && pions[2][2] == 1)
    || (pions[0][0] == 1 && pions[1][0] == 1 && pions[2][0] == 1) //colone
    || (pions[0][1] == 1 && pions[1][1] == 1 && pions[2][1] == 1)
    || (pions[0][2] == 1 && pions[1][2] == 1 && pions[2][2] == 1)
    || (pions[0][0] == 1 && pions[1][1] == 1 && pions[2][2] == 1) //diagnoale
    || (pions[0][2] == 1 && pions[1][1] == 1 && pions[2][0] == 1))
    {
        gotoligcol(12, 25);
        printf("Victoire du joueur 1");
        *correcteur = - (9 - tour);
    }
    else if((pions[0][0] == 2 && pions[0][1] == 2 && pions[0][2] == 2) //ligne
         || (pions[1][0] == 2 && pions[1][1] == 2 && pions[1][2] == 2)
         || (pions[2][0] == 2 && pions[2][1] == 2 && pions[2][2] == 2)
         || (pions[0][0] == 2 && pions[1][0] == 2 && pions[2][0] == 2) //colone
         || (pions[0][1] == 2 && pions[1][1] == 2 && pions[2][1] == 2)
         || (pions[0][2] == 2 && pions[1][2] == 2 && pions[2][2] == 2)
         || (pions[0][0] == 2 && pions[1][1] == 2 && pions[2][2] == 2) //diagnoale
         || (pions[0][2] == 2 && pions[1][1] == 2 && pions[2][0] == 2))
    {
        gotoligcol(12, 25);
        printf("Victoire du joueur 2");
        *correcteur = - (9 - tour);
    }
    else if(tour == 8)
    {
    gotoligcol(12, 25);
    printf("Match nul");
    }
    color(0, 0);
}
