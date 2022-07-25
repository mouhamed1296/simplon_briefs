#include<stdio.h>
#include "est_entier.h"
#include<stdlib.h>
#include<string.h>
#define n 5
//Déclarartion des tableaux utilisateurs et mot de passe
enum Usernames {USER1, USER2, USER3, USER4, USER5};
int passwords[n] = {1231, 1232, 1234, 1235, 1236};
int usernames[n] = {USER1, USER2, USER3, USER4, USER5};

//Déclaration d'une structure représentant un utilisateur
typedef struct Utilisateur
{
    int password;
    int username;
} Utilisateur;

//Déclaration d'une structure représentant le résultat de la vérification du type code secret
typedef struct Result
{
    int compteur;
    char code_secret[50];
} Result;

//prototype des fonctions utilisés dans le programme
Result verifier_code_entier(char code_secret[50], int cpt);


int main(){
    //Déclaration des variables nécessaires au programme
    Utilisateur tab[n];
    int j = 0;
    char code_secret[50];
    int compteur = 1;
    Result res;

    //création d'un tableau contenant (n) utilisateurs
    for (int i = 0; i < n; i++)
    {
        tab[i].password = passwords[i];
        tab[i].username = usernames[i];
    }

    //Demander à l'utilisateur de saisir son code secret
    printf("Vous disposez de 3 tentatives\n");
    printf("Veuillez saisir votre code secret\n");
    scanf("%50s", code_secret);
    
    //Vérifier si le code entré est un entier et stocke le résultat dans la variable res
    res = verifier_code_entier(code_secret, compteur);

    /*affecte la valeur du compteur et du code_secret
    aprés avoir tester si la valeur saisie par
    l'utilisateur est un entier*/
    compteur = res.compteur;
    strcpy(code_secret, res.code_secret);
    
    //Vérifier si le code secret se trouve dans le tableau
    while (tab[j].password != atoi(code_secret))
    {
        //Vérifier si on est à la fin du tableau
        if (j < n)
        {
            j++;
        }
        else
        {
            //Vérifier si l'utilisateur a épuisé ses tentatives
            if (compteur == 3)
            {
                printf("Vous avez epuise vos tentatives\n");
                return 0;
            }
            //vérifier si l'utilisateur a déjà effectué 2 essais
            if (compteur == 2) {
                printf("Il vous reste un seul essai\n");
            }
            else
            {
                printf("Code incorrect veuillez reessayer\n");
            }
            //incrémenter le compteur
            compteur++;
            //réinitialiser la variable j qui parcourt le tableau
            j = 0;
            scanf("%50s", code_secret);
            //Vérifier si le code entré est un entier et stocke le résultat dans la variable res
            res = verifier_code_entier(code_secret, compteur);

            /*écrase la valeur du compteur et du code_secret
            aprés avoir tester si la valeur saisie par
            l'utilisateur est un entier*/
            strcpy(code_secret, res.code_secret);
            compteur = res.compteur;
        }
    }
    //Message à afficher lorsque le code saisi est correct
    printf("Code secret correct\n\n");
    
    return 0;
}

/*
Fonction permettant de vérifier si le code saisi est un entier
et de tenter 3 fois de saisir un entier si aprés les 3 tentatives
l'utilisateur n'as pas saisie un entier le programme s'arrête
*/
Result verifier_code_entier(char cs[50], int cpt){
    //Déclaration et initialisation du résultat
    Result result;
    strcpy(result.code_secret, cs);
    result.compteur = cpt;
    
    //Vérification du code secret
    while (est_entier(result.code_secret) == 0)
    {
        //Vérifier si l'utilisateur a épuisé ses tentatives
        if (result.compteur == 3) {
            return result;
        }

        //vérifier si l'utilisateur a déjà effectué 2 essais
        if (result.compteur == 2) {
            printf("il vous reste un seul essai\n");
        } else {
            printf("Veuillez saisir un nombre entier\n");
        }
        result.compteur++;
        scanf("%50s", result.code_secret);
    }
    return result;
}
