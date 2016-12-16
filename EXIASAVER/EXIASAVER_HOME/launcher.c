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

        char* asctime (const struct tm* instant);

	char recup[TAILLE_MAX][40];
	int q = 0, compteurDyn = 0, compteurSta = 0, totalTypes = 0;
	char testS[] = "S";
	char testD[] = "D";
	int affichage = 0, saisie = 0;
        char parametre[] = "-stats";
        time_t temps;

        FILE* fichier = NULL;
        struct tm date;

        time(&temps);
        date=*localtime(&temps);
        printf("%s\n", asctime(&date));

        char *arguments[] = {"hello", NULL};
        int choix = 0, i = 0, status = 0;
        choix = choixAlea();

        system("clear"); //clean la console

 if (argc <= 1)
  {
        pid_t pid = create_process();
        if (choix == 1)
        {
            switch (pid)
            {
                case -1:
                    // perror("fork");
                    return EXIT_FAILURE;
                break;

                case 0:

		        fichier = fopen("historique.txt", "a"); //ouverture du fichier

		        if (fichier != NULL)
		        {

			fprintf(fichier, "%sStatique\n", asctime(&date));
			fclose(fichier);
		        }
		        else
		        {
		        //Fichier pas ouvert
		        printf("impossible d'ouvrir le fichier souhaite\n");
		        }
              /*      char* variable = malloc(512);
                    if(getenv("Hello")==NULL){
                      strcpy(variable,"Hello");
                    } else
                    {
                      strcpy(variable, getenv("Hello"));
                    }*/
                    int r = nmbraleatoir();
                    char* nmbral = malloc(512);
                    sprintf (nmbral, "%d", r);
                execl("statique", nmbral, (char*)NULL);
                break;

                default:
                    wait(&status);
                    printf("process has ended\n");
                break;
            }
        }

        if (choix == 2)
        {
            switch (pid)
            {
                case -1:
                  //  perror("fork");
                    return EXIT_FAILURE;
                break;

                case 0:

		        fichier = fopen("historique.txt", "a"); //ouverture du fichier

		        if (fichier != NULL)
		        {
		        // on peut lire/écrire
			fprintf(fichier, "%s, Dynamique\n", asctime(&date));
			fclose(fichier);
		        }
		        else
		        {
		        //Fichier pas ouvert
		        printf("impossible d'ouvrir le fichier souhaite\n");
            }
            execv("Horloge", arguments);

                break;

                default:
                    wait(&status);
                    printf("process has ended\n");
                break;

            }
        }
    }

        /*if (choix == 3)
        {
            switch (pid)
            {
                case -1:
                    perror("fork");
                    return EXIT_FAILURE;
                break;

                case 0:
                    if(execv("XXX", arg3) == -1)
                    {
                        perror("execv");
                        exit(EXIT_FAILURE);
                    }
                break;

                default:
                    wait(&status);
                    printf("process has ended\n");
                break;
            }
        } */
else {
	int choixmenu = 0;

	if (strcmp(argv[1], parametre) == 0)
	{
	FILE* fichier = NULL;

        fichier = fopen("historique.txt", "r"); //ouverture du fichier

	   	if (fichier != NULL)
    		{
	char chainehisto[TAILLE_MAX];

	printf("quel type d'affichage désirez vous?\n1.Historique 2. Statistiques\n");
	scanf("%d", &choixmenu);

	switch (choixmenu)
	{
	case 1:
          fseek(fichier, 0, SEEK_SET);
        	while (fgets(chainehisto, TAILLE_MAX, fichier) != NULL) // On lit le fichier
        	{
            	printf("%s\n", chainehisto); // On affiche la chaîne
        	}

        	fclose(fichier);
 	break;
	case 2:

	FILE* fichier = NULL;

   	fichier = fopen("historique.txt", "r");

    if (fichier != NULL)
    {
		while (q < TAILLE_MAX)
		{
		fgets(recup[i][TAILLE_MAX], TAILLE_MAX, fichier); // On lit maximum TAILLE_MAX caractères du fichier, on stocke le tout dans "chaine"
        	}
        	fclose(fichier);
    }
	for (q = 0; q < TAILLE_MAX; q++)
		{
		if (recup[q][1] == testS)
			{
			compteurSta ++;
			}
		else if (recup[i][1] == testD)
			{
			compteurDyn ++;
			}
		}
	totalTypes = compteurSta + compteurDyn;
	printf("%d% de statiques\n%d% de Dynamiques\n", compteurSta/totalTypes, compteurDyn/totalTypes);

		break;
	default:
		printf("saisie incorrecte");
		break;
	}
}
}
}
    return 0;

}
