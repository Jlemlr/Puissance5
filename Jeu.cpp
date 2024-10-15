#include "Jeu.h"

void Jeu::jouer() {
    plateau.afficherPlateau(); // On affiche la plateau

    bool tourJoueur1 = true; // Permet d'alterner entre les joueurs
    while (true) { // Tant que la partie n'est pas finie

        Joueur* joueurActuel = tourJoueur1 ? joueur1 : joueur2; // Permet d'alterner entre les joueurs
        // equivalent à
        /*Joueur* joueurActuel;
        if (tourJoueur1) {
            joueurActuel = joueur1;
        } else {
            joueurActuel = joueur2;
        }*/

        // On récupère la position du jeton entrée par le joueur 1 ou 2 en fonction du tour
        int position;
        if (joueurActuel == joueur1) {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            position = joueur1->jouerTour(plateau); // On utilise -> car Joueur* joueur1;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
        } else {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
            position = joueur2->jouerTour(plateau);
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
        }

        // On ajoute le jeton dans la colonne 'position' de la grille
        plateau.jouerJeton(position, joueurActuel->getJeton());
        // On affiche le jeton joué dans le plateau
        plateau.afficherPlateau();

        // On regarde si le jeu est fini, cad
        if (plateau.checkGagnant(joueurActuel->getJeton())) { // Si on a un gagnant
            std::cout << "Joueur " << (tourJoueur1 ? "1" : "2") << " wins!" << std::endl;
            break;
        } else if (plateau.estPlein()) { // Si le plateau est plein
            std::cout << "It's a draw!" << std::endl;
            break;
        }

        tourJoueur1 = !tourJoueur1; // On passe au joueur suivant
    }
}
