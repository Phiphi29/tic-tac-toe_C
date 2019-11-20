#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Fonctions.h"
#define M 3

void color (int t, int f)
{
    ///Fonction couleur
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, f * 16 +t);
}

void gotoligcol(int lig, int col)
{
    ///Manipulation curseur sur écran
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

void init_plateau(int tab[M][M])
{
    int x = 0, y = 0;

    for(x = 0; x < M; x++)
    {
        for(y = 0; y < M; y++)
        {
            if((x + y) % 2 == 0)
                tab[x][y] = 1; // Couleur n°1 du damier
            else
                tab[x][y] = 2; // Couleur n°2 du damier
        }
    }
}
