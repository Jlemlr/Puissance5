#include <iostream>
#include "plateau.h"
#include "joueur.h"
#include "jeu.h"

int main() {

    std::cout <<  "     _                            _ \n"
                  "    |_)    . _  _  _  _  _  _    (_ \n"
                  "    |  |_| |_> _> (_|| |(_ (/_    _)\n"
    << std::endl;

    int lignes, cols;
    do{
        std::cout << "Dimensions du plateau: " << std::endl;
        std::cin >> lignes >> cols;
    }while(lignes < 5 || cols < 5);

    /* // Le progrmme est tel que si on choisit le jeton, l'IA ne fonctonnera pas
    char jeton1, jeton2;
    std::cout << "Jeton joueur 1: ";
    std::cin >> jeton1;
    std::cout << "Jeton joueur 2: ";
    std::cin >> jeton2;
    */

    char jeton1 = 'O';
    char jeton2 = 'X';

    Plateau plateau(lignes, cols);

    Joueur* joueur1 = new Humain(jeton1);
    Joueur* joueur2;
    char choice;
    do{
        std::cout << "Voulez vous jouer contre une (i)a ou bien un autre (j)oueur? ";
        std::cin >> choice;
    }while(choice != 'i' && choice != 'j');
    if (choice == 'j') {
        joueur2 = new Humain(jeton2);
    } else if (choice == 'i') {
        joueur2 = new IA(jeton2);
    } else {
        std::cout << "Mmmh réessayez..." << std::endl;
        return 1;
    }

    Jeu jeu(plateau, joueur1, joueur2);
    jeu.jouer();

    delete joueur1;
    delete joueur2;

    int fin;
    std::cin >> fin;
    return 0;
}

// main main.cpp plateau.cpp joueur.cpp jeu.cpp
