#include "Joueur.h"

int Humain::jouerTour(const Plateau& plateau) const {
    int col;
    do {
        std::cout << "Joueur " << jeton << ", choisissez votre colonne (1-" << plateau.getCols() << "): ";
        std::cin >> col;
        col--; // Le joueur entre une valeur de colonne à partir de 1 et non 0 comme le premier index de la grille, on enlève donc 1 à col
    } while (!plateau.estValide(col)); // Tant que le joueur n'entre pas de colonne qui appartient à la grille 
    return col;
}

int IA::jouerTour(const Plateau& plateau) const {
    int meilleurCoup = -1;
    int meilleurScore = std::numeric_limits<int>::min();
    for (int col = 0; col < plateau.getCols(); ++col) {
        if (plateau.estValide(col)) {
            Plateau nPlateau = plateau;
            nPlateau.jouerJeton(col, 'O');
            int score = minimax(nPlateau, 5, false); // Arbitrary profondeur
            if (score > meilleurScore) {
                meilleurScore = score;
                meilleurCoup = col;
            }
        }
    }
    return meilleurCoup;
}

int IA::minimax(Plateau plateau, int profondeur, bool maxJoueur) const {
    if (profondeur == 0 || plateau.estPlein() || plateau.checkGagnant('X') || plateau.checkGagnant('O')) {
        return evaluer(plateau);
    }

    if (maxJoueur) {
        int maxEval = std::numeric_limits<int>::min();
        for (int col = 0; col < plateau.getCols(); ++col) {
            if (plateau.estValide(col)) {
                Plateau nPlateau = plateau;
                nPlateau.jouerJeton(col, 'O');
                int eval = minimax(nPlateau, profondeur - 1, false);
                maxEval = std::max(maxEval, eval);
            }
        }
        return maxEval;
    } else {
        int minEval = std::numeric_limits<int>::max();
        for (int col = 0; col < plateau.getCols(); ++col) {
            if (plateau.estValide(col)) {
                Plateau nPlateau = plateau;
                nPlateau.jouerJeton(col, 'X');
                int eval = minimax(nPlateau, profondeur - 1, true);
                minEval = std::min(minEval, eval);
            }
        }
        return minEval;
    }
}

int IA::evaluer(const Plateau& plateau) const {
    int score = 0;
    if (plateau.checkGagnant('O')) {
        score = 100;
    } else if (plateau.checkGagnant('X')) {
        score = -100;
    }
    return score;
}