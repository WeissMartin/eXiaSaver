#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <wait.h>
#include <ncurses.h>
#include <time.h>
#define MAX 2
#define MIN 1
#define GRANDE_TAILLE 1000
#define gotoxy(x,y) printf("\033[%d;%dH", (x), (y))
#define TAILLE_MAX 80
#include "fonction.h"


int main(int argc, char *argv[])
{
	char q = '\0';
	pid_t fils;
	fils = fork();
	int father;
	father = getppid();
	if (fils == 0)
{
	FILE* fichier = NULL; //initialisation du pointeur a NULL
	char chaine[GRANDE_TAILLE];
	int chaine2[2];
	int a,b;
	char chaine3[100];
	int nombre = nmbraleatoir();
	sprintf(chaine3,"/home/nathan/Desktop/EXIASAVER/EXIASAVER1_PBM/image%d.pbm", nombre);
	fichier = fopen(chaine3, "r"); // ouverture de l'image en mode lecture
		fseek(fichier, 3, SEEK_SET);
		fscanf(fichier, "%d %d", &chaine2[0], &chaine2[1]);
		a = chaine2[0];
		b = chaine2[1];
		a = (a*2)-1;
		center_picture(b);
		fseek(fichier, 1, SEEK_CUR);
		traitement(a, b, chaine, fichier);
		fclose(fichier); // fermeture du fichiers
		quitter(q);
}
		else
		{
		father = wait(NULL);
		return 0;
		}
}
