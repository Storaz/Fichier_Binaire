#include <stdio.h>
#include <stdlib.h>
#define MAX 30

//Le programme écrit bien dans le fichier mais crash dès qu'on essaye de lire le nom une fois le programme fermé.

typedef struct ddn{

    int j;
    int m;
    int a;

}ddn;

typedef struct cid{

    int NumCarte;
    char* Nom;
    char* Prenom;
    char Sexe;
    ddn Naissance;
    char* Ville;

}cid;

int main()
{
    int choix=0;
    int test=0;
    FILE* pFile=NULL;    //Descripteur de fichier
    cid Carte;
    Carte.Nom=malloc(sizeof(cid)*MAX);
    Carte.Prenom=malloc(sizeof(cid)*MAX);
    Carte.Ville=malloc(sizeof(cid)*MAX);
    cid buffer;
    long lSize;
    do{
    printf("\nQue voulez faire?\n 1/ Lire le fichier. \n 2/Remplir le fichier \n 3/Quitter le programme\n");
    scanf("%d",&choix);
        switch(choix){

        case 1: pFile = fopen ("myfile.bin","rb");  //Ouverture du fichier de façon à écrire en binaire
                if (pFile!=NULL){
                    fseek (pFile , 0 , SEEK_END);   //Fin du fichier
                    lSize = ftell(pFile);   //Taille du fichier
                    rewind (pFile); //Retour au début du fichier
                    fread (&buffer,sizeof(buffer),lSize,pFile);
                    printf("Numero Carte : %d\n",buffer.NumCarte);
                    printf("Nom : %s\n",buffer.Nom);
                    printf("Prenom : %s\n",buffer.Prenom);
                    printf("Sexe: %c\n",buffer.Sexe);
                    printf("Date de naissance : %d/%d/%d\n",buffer.Naissance.j,buffer.Naissance.m,buffer.Naissance.a);
                    printf("Ville : %s\n",buffer.Ville);
                    fclose(pFile);
                }else{
                    printf("Fichier non existant");
                }
                break;

        case 2: printf("Veuillez entrer le numero de votre carte d'identite\n");
                fflush(stdin);
                scanf("%d",&Carte.NumCarte);
                printf("Veuillez entrer votre nom\n");
                fflush(stdin);
                scanf("%s",Carte.Nom);
                printf("Veuillez entrer votre prenom\n");
                fflush(stdin);
                scanf("%s",Carte.Prenom);
                printf("Veuillez entrer votre sexe\n");
                fflush(stdin);
                scanf("%c",&Carte.Sexe);
                printf("Veuillez entrer le jour de votre naissance\n");
                fflush(stdin);
                scanf("%d",&Carte.Naissance.j);
                printf("Veuillez entrer le mois de  votre naissance\n");
                fflush(stdin);
                scanf("%d",&Carte.Naissance.m);
                printf("Veuillez entre l'annee de naissance\n");
                fflush(stdin);
                scanf("%d",&Carte.Naissance.a);
                printf("Veuillez entrer votre ville\n");
                fflush(stdin);
                scanf("%s",Carte.Ville);
                pFile = fopen ("myfile.bin","ab");
                fwrite(&Carte,sizeof(Carte),1,pFile);   //On écrit les différentes valeurs dans le fichier
                fclose(pFile);
                break;

        case 3: test=1;
                break;
        }
    }while(test==0);
    free(Carte.Nom);
    free(Carte.Prenom);
    free(Carte.Ville);
    return 0;
}
