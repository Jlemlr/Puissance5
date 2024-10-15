#include "Plateau.h"
#include "windows.h"


// Affiche les jetons contenus dans la grille (vecteur de char representant les jetons) de manière lisible
void Plateau::afficherPlateau() const {
    for (int i = 0; i < lignes; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "|" << grille[i][j];
        }
        std::cout << "|" << std::endl;
    }
    for (int j = 0; j < cols; ++j) {
        std::cout << "+-";
    }
    std::cout << "+" << std::endl;
    for (int j = 0; j < cols; ++j) {
        std::cout << " " << j + 1;
    }
    std::cout << std::endl;
}

// Ajoute un jeton dans la colonne col de la grille
bool Plateau::jouerJeton(int col, char jeton) {
    if (col < 0 || col >= cols) return false; //Pour ne pas être out of range
    for (int i = lignes - 1; i >= 0; --i) {
        if (grille[i][col] == ' ') {
            grille[i][col] = jeton;
            return true;
        }
    }
    return false;
}

// Return true si le plateau est plein
bool Plateau::estPlein() const {
    for (int i = 0; i < lignes; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grille[i][j] == ' ') {
                return false; // il reste de la place
            }
        }
    }
    return true; // le plateau est plein
}

// Return true si il y a 6 mêmes jetons à la suite (h, dd, dg, v) dans la grille
bool Plateau::checkGagnant(char jeton) const {
    // horizontal
    for (int i = 0; i < lignes; ++i) {
        for (int j = 0; j <= cols - 5; ++j) {
            if (grille[i][j] == jeton && grille[i][j+1] == jeton && grille[i][j+2] == jeton && grille[i][j+3] == jeton && grille[i][j+4] == jeton) {
                return true;
            }
        }
    }
    // vertical
    for (int i = 0; i <= lignes - 5; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grille[i][j] == jeton && grille[i+1][j] == jeton && grille[i+2][j] == jeton && grille[i+3][j] == jeton && grille[i+4][j] == jeton) {
                return true;
            }
        }
    }
    // diagonal
    for (int i = 0; i <= lignes - 5; ++i) {
        for (int j = 0; j <= cols - 5; ++j) {
            if (grille[i][j] == jeton && grille[i+1][j+1] == jeton && grille[i+2][j+2] == jeton && grille[i+3][j+3] == jeton && grille[i+4][j+4] == jeton) {
                return true;
            }
        }
    }
    // diagonal
    for (int i = 0; i <= lignes - 5; ++i) {
        for (int j = 5; j < cols; ++j) {
            if (grille[i][j] == jeton && grille[i+1][j-1] == jeton && grille[i+2][j-2] == jeton && grille[i+3][j-3] == jeton && grille[i+4][j-4] == jeton) {
                return true;
            }
        }
    }
    return false; // pas encore de gagnant
}

bool Plateau::estValide(int col) const {
    return col >= 0 && col < cols && grille[0][col] == ' ';
}
