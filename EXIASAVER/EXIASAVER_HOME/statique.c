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


int main(int argc, char *argv[])
{
	char q = '\0'; // initialisation de q utilisé dans quitter()
	pid_t fils; // création d'un processus fils
	fils = fork();
	int father;
	father = getppid(); // récupération du PPID du père
	if (fils == 0) // vérification de la création
{
	FILE* fichier = NULL; //initialisation du pointeur a NULL
	/* définition de différentes chaines */
	char chaine[GRANDE_TAILLE];
	int chaine2[2];
	char chaine3[100];
	int a,b;
	// int nombre = nmbraleatoir(); // fonction donnant un nombre aléatoire
	sprintf(chaine3,"/home/nathan/Desktop/EXIASAVER/EXIASAVER1_PBM/image%d.pbm", atoi(argv[0])); // définition du chemin
	fichier = fopen(chaine3, "r"); // ouverture de l'image en mode lecture
		fseek(fichier, 3, SEEK_SET); // déplacement du curseur vers les dimensions
		fscanf(fichier, "%d %d", &chaine2[0], &chaine2[1]); // lecture des dimensions
		a = chaine2[0]; // nombre de colones
		b = chaine2[1]; // nombre de ligne
		a = (a*2)-1; // nombre de colone x2(espaces) -1 car pas d'espaces sur le dernier
		center_picture(b); // centre l'image verticalement
		fseek(fichier, 1, SEEK_CUR);//déplacement du curseur au début des lignes
		traitement(a, b, chaine, fichier); // remplacement des 0 en ' ' et des 1 en 'X'
		fclose(fichier); // fermeture du fichiers
		quitter(q); // quitte le programme quand on appuit sur une touche
}
		else
		{
		father = wait(NULL); // pour faire attendre le processus père
		return 0;
		}
}
