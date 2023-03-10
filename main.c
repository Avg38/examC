#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// 1 - creer une fonction qui prend la variable solution, et la variable tableauJoueur (par exemple) : un tableau rempli de 0, cette fonction doit copier certaines valeurs (grace au rand() % N) 
// de solution dans tableauJoueur afin d'initialiser une grille jouable ( car solution est bel est bien la solution, donc pas jouable par définition. ).
// un parametre doit permettre de verifier la condition de victoire en un seul coup (proposer votre façon de faire :) ) 

void copyArray(int tab[8][8], int copy[8][8] ){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            copy[i][j] = tab[i][j];
        }
    }
}


void afficher(int tab[8][8]){
    // printf("|X,Y");
    printf("\n");
    for(int i = 0; i < 8; i++){
        printf("-----");
    }
    printf("\n| Y\\X  ");
    for(int i = 0; i < 8; i++){
        printf("| %d ", i);
    }
        printf("|\n");

    for(int i = 0; i < 8; i++){
        printf("-----");
    }

    for(int i = 0; i < 8; i++){
        printf("\n");
        printf("| %d >  ", i);
        for(int j = 0; j < 8; j++){
            printf("| %d ", tab[i][j]);
        }
        printf("|\n");
    }
        printf("\n");

}


void generer(int tab[8][8], int copyTableau[8][8]){
    
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if((rand() % 100) < 97){
                copyTableau[i][j] = tab[i][j];
            }
        }
    }

}

// 2- une fonction saisir qui demande au joueur de saisir 3 informations: i, j , et v qui permettront de placer la valeur v aux coordonnées (i,j)

int saisir(int tab[8][8], int soluce[8][8]){
    int result = 0;

    while (result == 0){
        int tableauTest[8][8] = {
            {2,2,2,2, 2,2,2,2},
            {2,2,2,2, 2,2,2,2},
            {2,2,2,2, 2,2,2,2},
            {2,2,2,2, 2,2,2,2},

            {2,2,2,2, 2,2,2,2},
            {2,2,2,2, 2,2,2,2},
            {2,2,2,2, 2,2,2,2},
            {2,2,2,2, 2,2,2,2}
        };
        copyArray(tab, tableauTest);
        int saisie = 0;

        printf("Veuillez saisir un Y\n");
        scanf("%d", &saisie);
        int saisieX = saisie;
        printf("Veuillez saisir un X\n");
        scanf("%d", &saisie);
        int saisieY = saisie;

        printf("Quelle valeur souhaitez vous inserer ?\n");
        scanf("%d", &saisie);
        int valeur = saisie;
        tableauTest[saisieX][saisieY] = valeur;
    
        result = verifierGrille(tableauTest, soluce);
        if(result == 1 ){
            tab[saisieX][saisieY] = valeur;
        }
    }
    return result;
} 

// 3- apres chaque coordonnées il faut verifier les regles du sudoku sur le tableauJoueur donc : 

    // - la fonction verifierLigneColonne ( qui verifie les lignes et les colonnes  sur lesquelles sont la nouvelle valeur)
    // - la fonction verifierGrille (qui fait ceci pour toute la grille et permet de definir la condition de victoire)

int verifierLigneColonne(int tab[8][8], int ligne, int ligneOrCol ){

    int choices[8] = {2,2,2,2, 2,2,2,2};
    int result = 1;

    
    if(ligneOrCol){
        for(int i = 0; i < 8; i++){
            int numero = tab[i][ligne];
            if(tab[i][ligne] != 2){
                choices[numero - 1] = choices[numero - 1] + 1 ;
            }
        }
    } else {
        for(int i = 0; i < 8; i++){
            if(tab[ligne][i]){
                int numero = tab[ligne][i];
                choices[numero - 1] = choices[numero- 1] + 1 ;
            }
        }
    }
    for(int i = 0; i < 8; i++){
        if(choices[i] > 4){
            result = 0; 
        } 
    }

return result;
}


int verifierGrille(int tab[8][8], int soluce[8][8]){

    int isCorrect = 1, verifCol, verifLigne, i,j, fini;
    for(int i = 0; i < 8; i++ ){
        int verifLigne = verifierLigneColonne(tab, i, 1);
        int verifCol = verifierLigneColonne(tab, i, 0);
        if(verifCol || verifLigne){
            printf("\n\nRate, reessayes !\n\n");
            isCorrect = 0;
            break;
        }
    }
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(tab[i][j] == soluce[i][j]){
                fini++;
            }
        }
    }
    if(fini == 64){
        printf("Vous avez réussi le Takuzu !");
    }
    return isCorrect;
}



// 4 - Ecrire le code principal qui permet de jouer au joueur :  le programme prend fin quand on gagne 

int main(){
    // Ne pas toucher le code entre les commentaires
    srand( time( NULL ) );


    int i, j, k;
    printf("SOLUTION");  
    printf("\n---------------------------------\n");  

    int solution[8][8] = {
        {1,1,0,1, 0,1,0,0},
        {0,0,1,0, 1,0,1,1},
        {0,1,0,0, 1,1,0,1},
        {1,0,1,1, 0,0,1,0},
    
        {1,0,1,0, 0,1,1,0},
        {0,1,0,1, 1,0,0,1},
        {1,1,0,0, 1,0,1,0},
        {0,0,1,1, 0,1,0,1}
    };


    for(i=0;i<8; ++i){
        for(j=0; j<8; ++j){
            printf("%d ", solution[i][j]);
        }   
        printf("\n");  
    }
    //toucher le code entre les commentaires 
    int tableauJoueur[8][8] = {
        {2,2,2,2, 2,2,2,2},
        {2,2,2,2, 2,2,2,2},
        {2,2,2,2, 2,2,2,2},
        {2,2,2,2, 2,2,2,2},

        {2,2,2,2, 2,2,2,2},
        {2,2,2,2, 2,2,2,2},
        {2,2,2,2, 2,2,2,2},
        {2,2,2,2, 2,2,2,2},
    };

    int isTurning = 0;
    generer(solution, tableauJoueur);
    do{
        afficher(tableauJoueur);
        saisir(tableauJoueur, solution);
        isTurning = verifierGrille(tableauJoueur, solution);
        if(tableauJoueur == solution){
            printf("Bravo, vous avez reussi l'epreuve du Takuzu");
            system("pause");
        }
    } while(isTurning);
    


    //Ne pas toucher au code ci dessous
    system("pause");
    return 0;
}
