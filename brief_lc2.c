#include <stdio.h>
#include "est_entier.h"
#include <stdlib.h>
#include <ctype.h>
#define n 4
//Enumération des coefficients des différentes matières
enum coefficients {ALGO = 6, ELEC = 4, C = 3, JS = 2};
//remplissage du tableau contenant les coefficients
int tab_coef[4] = {ALGO, ELEC, C, JS};

/*Déclaration d'une matière sous forme 
de structure composé de la note et du coefficient*/
typedef struct Matiere
{
    int note[2];
    int coef;
} Matiere;

/*Déclaration d'un apprenant sous forme 
de structure composé de son nom et de sa moyenne*/
typedef struct Apprenant
{
    char nom[50];
    double moyenne;
    char mention[15];
} Apprenant;

int verifier_note(char note[2]);


int main()
{
    //Déclaration du tableau des matières
    Matiere tab_matiere[n];

    //Déclaration d'un apprenant
    Apprenant apprenant;

    //index pour parcourrir le tableau des matieres
    int i = 0;

    //Déclaration de la note que doit saisir l'utilisateur
    char note[2];

    //Déclaration d'une variable pour stocker le total des coefficients
    int total_coef = 0;
    
    //Déclaration d'une variable pour stocker le total des points
    int total_point = 0;

    for (int i = 0; i < n; i++)
    {
        //Association de chaque matiere avec son coefficient
        tab_matiere[i].coef = tab_coef[i];

        //On écrase la valeur de total_coef avec la valeur total_coef + tab_coef[i]
        total_coef += tab_coef[i];
    }

    printf("Veuillez entrer le nom de l apprenant\n");
    scanf("%s", apprenant.nom);

    //initialisation de la moyenne
    apprenant.moyenne = 0.00;

    while (i < n)
    {
        int j = 0;
        while (j < 2)
        {   
            //Affichage des messages pour guider l'utilisateur dans la saisie
            switch (i)
            {
                case 0:
                    printf("Entrez la note obtenu au devoir numero %d en Algo\n", j+1);
                    break;
                case 1:
                    printf("Entrez la note obtenu au devoir numero %d en Elec\n", j+1);
                    break;
                case 2:
                    printf("Entrez la note obtenu au devoir numero %d en C\n", j+1);
                    break;
                case 3:
                    printf("Entrez la note obtenu au devoir numero %d en JS\n", j+1);
                    break;
                default:
                    break;
            }
            //saisie
            scanf("%s", note);

            //Vérification et Enregistrement de la note saisie dans le tableau des note de la matière correspondante
            tab_matiere[i].note[j] = verifier_note(note);

            //incrémente le compteur pour le tableau des notes
            j++;
        }
        //incrémente le compteur pour le tableau des matière
        i++;
    }
    
    //Calculer le nombre total de points
    for (int i = 0; i < n; i++)
    {
        int points_matiere;
        //on prend la note 1 plus la note 2 divisé par deux et multiplié par le coefficient de la matière
        points_matiere = ((tab_matiere[i].note[0] + tab_matiere[i].note[1])/2)*tab_coef[i];
        //on écrase la valeur de total_point avec total_point + points_matiere
        total_point += points_matiere;
    }
    //calcul de la moyenne
    apprenant.moyenne = total_point/total_coef;

    //Determination de la mention
    if (apprenant.moyenne < 10)
    {
        strcpy(apprenant.mention, "mediocre");
    }
    if (apprenant.moyenne == 10)
    {
        strcpy(apprenant.mention, "passable");
    }
    if (apprenant.moyenne >= 12 && apprenant.moyenne <= 14)
    {
        strcpy(apprenant.mention, "Tres Bien");
    }
    if (apprenant.moyenne > 14)
    {
        strcpy(apprenant.mention, "Excellent");
    }
    
    //Affichage de la moyenne et de la mention
    printf("%s votre moyenne est: %.2lf, %s\n", apprenant.nom, apprenant.moyenne, apprenant.mention);

    return 0;
}



/*fonction permettant de verifier si la note ne contient pas 
de caractere et la transforme en entier si c'est le cas*/
int verifier_note(char note[2]) {

    while (est_entier(note) == 0 || (atoi(note) < 0 || atoi(note) > 20))
    {
        printf("Vous devez saisir un entier compris entre 0 et 20 pour la note\n");
        scanf("%s", note);
    }
    
    return atoi(note);
}
