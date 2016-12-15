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

/*
Fonction permettant de générer un nombre
aléatoire entre 1 et 5.
Ce nombre permettera de choisir l'image
*/
int nmbraleatoir()
{
int a=1;
int b=5;
srand(time(NULL)); // utilisation de time, pour un nombre réellement aléatoire
int c = (rand()%(b-a+1) + a); // 'c' est le nombre aléatoire
return c;
}

/*
Fonction permettant d'afficher une ligne
centré horizontalement
*/
void printf_center (int a, const char* str)
{
	for (int i = 0; i<((80-a)/2); i++)
	{
		putchar(' '); // boucle qui ajoute un espace pour arriver au milieu.
	}
	printf ("%s", str); // affichage centré
}
/*
Fonction permettant d'afficher l'image
centré verticalement
*/
void center_picture (int b)
{
	for (int i = 0; i<((24-b)/2); i++)
{
	putchar('\n'); // boucle qui ajoute un retour a la ligne pour mettre l'image au milieu
}
}
/*
Fonction permettant de traiter la récupération
de 0 et 1 (PBM) en ' ' et 'X'
*/
void traitement(int a, int b, char chaine[GRANDE_TAILLE],FILE* fichier)
{
	for(int i=0; i<b; i++) // boucle qui va parcourir les lignes
	{
		fgets(chaine, GRANDE_TAILLE, fichier); // recuperation de la ligne
		for(int j=0;j<a;j++) // boucle qui parcourt la ligne
		{
			if (chaine[j] == '0')
				chaine[j] = ' '; // changement des 0 en espace
			else if (chaine[j] == '1')
				chaine[j] = 'X'; // changement des 1 en X
		}

		printf_center(a, chaine); // affichage de la ligne modifié

	}
}
char quitter(char q) // fonction permettant de quitter le programme quand on appuie sur une touche
{
	initscr(); // On initialise Ncurses dans ce terminal
	cbreak(); // Pas besoin d'appuyer sur une entrée pour envoyer un caractère
	noecho(); // On masque les entrée pour envoyer un caractère
	q = getchar(); // détecte une interaction de l'utilisateur
	if (q != '\0') // Si le caractere est different de vide  (ici \0) donc si une touche a été appuyée alors
		{
			system ("clear");
			echo(); // On affiche de nouveau les entrées clavier
			nocbreak(); // On redemande à ce que l'entrée d'un caractere soit validee par entree
			endwin(); // On quitte la fenetre Ncurses dans ce termial
			return 0;
		}
}

int choixAlea() //fonction de génération de nbr aléatoire
{
        int mysteryNumber = 0;

        srand(time(NULL));
        mysteryNumber = (rand() % (MAX - MIN + 1)) + MIN;

        return mysteryNumber;
}

pid_t create_process(void) //création nouveau processus
{
        pid_t pid; //nouvelle valeur de pid

        do {
            pid = fork(); //on crée un processus tant que sa création échoue
        } while((pid == -1) && (errno == EAGAIN));

        return pid; //on retourne le pid du processus créé
}
int InitTime()
{
	time_t secondes;
	struct tm instant;
	time(&secondes);
	instant=*localtime(&secondes);
	int TimeS1 = (instant.tm_sec)/10;
	int TimeS2 = (instant.tm_sec)-(TimeS1*10);
	int TimeM1 = (instant.tm_min)/10;
	int TimeM2 = (instant.tm_min)-(TimeM1*10);
	int TimeH1 = (instant.tm_hour)/10;
	int TimeH2 = (instant.tm_hour)-(TimeH1*10);

	int Time[8];
	Time[0] = TimeH1;
	Time[1] = TimeH2;
	Time[2] = 15;
	Time[3] = TimeM1;
	Time[4] = TimeM2;
	Time[5] = 15;
	Time[6] = TimeS1;
	Time[7] = TimeS2;

	int z = 0;
	int TailleFich = 1;

	//printf("Horloge --> %u%u : %u%u : %u%u\n",TimeH1 ,TimeH2,TimeM1 ,TimeM2,TimeS1 ,TimeS2);

	//system("clear"); // fonction qui nettoie la console.

		int y=40-((4+TailleFich*2)*3+5), x=6;
	    	int i = 0, j = 0; // declaration de deux variable pour les boucles.
	    	FILE* fichier = NULL; //initialisation du pointeur a NULL
	    	char chaine[TAILLE_MAX];
	    	int chaine2[2];
	    	//fichier = fopen("6.pbm", "r"); // ouverture de l'image
	     	int a,b;

	for (z=0; z<8; z++)
	{
		switch(Time[z])
		{
			case 0:
				fichier = fopen("/home/nathan/Desktop/EXIASAVER/EXIASAVER2_PBM/0.pbm", "r");
				break;
			case 1:
				fichier = fopen("/home/nathan/Desktop/EXIASAVER/EXIASAVER2_PBM/1.pbm", "r");
				break;
			case 2:
				fichier = fopen("/home/nathan/Desktop/EXIASAVER/EXIASAVER2_PBM/2.pbm", "r");
				break;
			case 3:
				fichier = fopen("/home/nathan/Desktop/EXIASAVER/EXIASAVER2_PBM/3.pbm", "r");
				break;
			case 4:
				fichier = fopen("/home/nathan/Desktop/EXIASAVER/EXIASAVER2_PBM/4.pbm", "r");
				break;
			case 5:
				fichier = fopen("/home/nathan/Desktop/EXIASAVER/EXIASAVER2_PBM/5.pbm", "r");
				break;
			case 6:
				fichier = fopen("/home/nathan/Desktop/EXIASAVER/EXIASAVER2_PBM/6.pbm", "r");
				break;
			case 7:
				fichier = fopen("/home/nathan/Desktop/EXIASAVER/EXIASAVER2_PBM/7.pbm", "r");
				break;
			case 8:
				fichier = fopen("/home/nathan/Desktop/EXIASAVER/EXIASAVER2_PBM/8.pbm", "r");
				break;
			case 9:
				fichier = fopen("/home/nathan/Desktop/EXIASAVER/EXIASAVER2_PBM/9.pbm", "r");
				break;
			case 15:
				fichier = fopen("/home/nathan/Desktop/EXIASAVER/EXIASAVER2_PBM/:.pbm", "r");
				break;
		}

	    	if (fichier != NULL) // vérification de l'ouverture du fichier
	    	{
			fseek(fichier, 3, SEEK_SET);
			fscanf(fichier, "%d %d", &chaine2[0], &chaine2[1]);
			a = chaine2[0]-1 + TailleFich;
			b = chaine2[1]-2 + TailleFich*2;
			a = (a*2)-1;
			//printf("%d",a);
			char P = 'X';


			fseek(fichier, 1, SEEK_CUR);


			for(i=0; i<b; i++) // boucle qui va parcourir les lignes
			{
				gotoxy(x,y);
		    		fgets(chaine, TAILLE_MAX, fichier); // recuperation de la ligne



					// Boucle pour convertir les 0 et 1 en espaces et X
					for (j = 0; j < a; j++) {
						if (chaine[j] == '0') {
							chaine[j] = ' ';
						} else if (chaine[j] == '1') {
							chaine[j] = P;
						}
					}

		    		for(j=0;j<a;j++) // boucle qui parcourt la ligne
		    		{
					gotoxy(x,y);

						if (TailleFich == 2 && Time[z] == 15)
						{
							chaine[3] = chaine[2];
						}
						else if (TailleFich == 2 && Time[z] != 15)
						{
							chaine[6] = chaine[4];
							chaine[5] = chaine[2];

							chaine[4] = chaine[2];
							chaine[3] = chaine[2];
						}

						/*if (chaine[j] == '0')
				    			chaine[j] = ' '; // changement des 0 en espace
						else if (chaine[j] == '1')
				    			chaine[j] = P; // changement des 1 en X
						else*/ if (chaine[j] == ' ')
						{
							if (chaine[j-1] == P && chaine[j+1] == '1')
								chaine[j] = P;

							if (chaine[j-1] == P && chaine[j+1] == P)
								chaine[j] = P;
						}
		   		}
				x=x+1;
		    		printf("%s", chaine); // affichage de la ligne modifié

			}
			fclose(fichier); // fermeture du fichier
			fichier = NULL;
	    	}
		x = x-(3+TailleFich*2);
		y = y+(5+TailleFich*2);

	}
}
