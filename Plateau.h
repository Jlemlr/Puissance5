#ifndef PLATEAU_H
#define PLATEAU_H

#include <iostream>
#include <vector>
#include "windows.h"

class Plateau {

// Definition des attributs
private:
    int lignes;
    int cols;
    std::vector<std::vector<char>> grille;

public:

    // Definition des accesseurs
    char getJeton(int row, int col) const {
        return grille[row][col];
    }

    int getLignes() const {
        return lignes;
    }

    int getCols() const {
        return cols;
    }

    // Definition d'un constructeur
    Plateau(int l, int c) : lignes(l), cols(c) {
        grille = std::vector<std::vector<char>>(lignes, std::vector<char>(cols, ' '));
    }

    // Definition des méthodes
    void afficherPlateau() const;

    bool jouerJeton(int col, char jeton);

    bool estPlein() const;

    bool checkGagnant(char jeton) const;

    bool estValide(int col) const;
};

#endif
