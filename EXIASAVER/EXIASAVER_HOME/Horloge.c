#include <stdio.h> //pour fprintf
#include <stdlib.h> //pour constante exit
#include <unistd.h> //pour fork
#include <sys/types.h> //pour type pid_t
#include <time.h> //pour historique
#include <errno.h> // pour code erreur
#include <ncurses.h> //pour quitter le programme
#include <wait.h> // mettre un processus en attente
#include <string.h> // pour la chaine de caractere
#define MAX 2 // maximum du nombre aléatoire
#define MIN 1 // minimum du nombre aléatoire
#define GRANDE_TAILLE 1000 // taille du tableau
#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))
#define TAILLE_MAX 80
#include "fonction.h" // répertoire avec toutes les fonctions

int main()
{

	int RefreshT;
	system("clear");
	gotoxy(10, 20);
	printf("Entrez le temps entre 2 Actualisation : ");
	scanf("%d", &RefreshT);

	srand(time(NULL));
	int Scale = (rand()%2) +1;
	int ctrlc = 0;
	int i;
	int a = 20,b = 15,c = 3,d = 25;
	system("clear");

	while (ctrlc != 1)
	{
		int x = 20;
		int y = 62;
		gotoxy(c,d);
		InitTime(Scale);
		gotoxy(a,b);
		if (RefreshT == 1)
		{
			gotoxy(a,b+10);
			printf("Cet écran est actualisé toutes les secondes \n");
		}
		else

			printf("Cet écran sera actualisé dans quelques secondes \n");

		for (i=0; i<RefreshT; i++)
		{
			sleep(1);
			gotoxy(x,y);
			printf(".\n");
			y++;
		}
		y=y-RefreshT;
		gotoxy(x,y);
		printf("                            ");

	}

	return 0;
}
