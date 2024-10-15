#ifndef JEU_H
#define JEU_H

#include <iostream>
#include "Joueur.h"


class Jeu {
private:
    Plateau plateau;
    Joueur* joueur1; // Humain ou IA
    Joueur* joueur2;

public:
    Jeu(Plateau p, Joueur* j1, Joueur* j2) : plateau(p), joueur1(j1), joueur2(j2) {}

    void jouer();
};

#endif