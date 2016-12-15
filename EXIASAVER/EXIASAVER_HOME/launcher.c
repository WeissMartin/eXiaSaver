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
        struct Sauv {
            char termSaver[20];
            int dateLancement[6];
        };

        struct Sauv sauv;
        time_t temps;

        struct tm date;

        time(&temps);
        date=*localtime(&temps);
        printf("%s\n", asctime(&date));

        char *arg1[] = {"XXX", argv[1], NULL};
        char *arg2[] = {"XXX", argv[2], NULL};
        char *arg3[] = {"XXX", argv[3], NULL};
        int choix = 0, i = 0, status = 0;
        choix = choixAlea();

        printf("running eXiaSaver ...\n");
        system("clear"); //clean la console
        pid_t pid = create_process();


        /*sauv.dateLancement[0] = tm_hour;
        sauv.dateLancement[1] = tm_min;
        sauv.dateLancement[2] = tm_sec;
        sauv.dateLancement[3] = tm_mday;
        sauv.dateLancement[4] = tm_mom + 1;
        sauv.dateLancement[5] = tm_year + 1900;*/

        FILE* fichier = NULL;

        fichier = fopen("historique.txt", "a"); //ouverture du fichier

        if (fichier != NULL)
        {
            // on peut lire/écrire
            for (i = 0 ; i <= 5 ; i ++)
            {
                fprintf(fichier, "%d", sauv.dateLancement[i]);
            }
            fprintf(fichier, "/n");
            fclose(fichier);
        }
        else
        {
        //Fichier pas ouvert
        printf("impossible d'ouvrir le fichier souhaite\n");
        }


        if (choix == 1)
        {
            switch (pid)
            {
                case -1:
                    perror("fork");
                    return EXIT_FAILURE;
                break;

                case 0:
                    if(execv("recuperation", arg1) == -1)
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
        }

        if (choix == 2)
        {
            switch (pid)
            {
                case -1:
                    perror("fork");
                    return EXIT_FAILURE;
                break;

                case 0:
                    if(execv("Horloge", arg2) == -1)
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
        else
        {

        }

    return 0;
}
