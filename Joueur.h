#ifndef JOUEUR_H
#define JOUEUR_H

#include <iostream>
#include <vector>
#include <limits>
#include "Plateau.h"

// Classe joueur qui sera la classe mère des sous classes 'Humain' et 'IA'
class Joueur {
public:
    virtual int jouerTour(const Plateau& plateau) const = 0; // Méthode virtuelle pure,
    virtual char getJeton() const = 0;                      // un tour ne se déroule pas de la même manière pour un humain ou une IA
};                                                          // de même on a besoin d'un get dans chacune des sous classes

// Sous classe de 'Joueur'
class Humain : public Joueur {
private:
    char jeton;

public:
    char getJeton() const override {
    return jeton;
    }

    Humain(char p) : jeton(p) {}

    int jouerTour(const Plateau& plateau) const override; // Definition de la méthode 'jouerTour' pour l'humain
};

// Sous classe 'IA'
class IA : public Joueur {
private:
    char jeton;

public:

    char getJeton() const override {
        return jeton;
    }

    IA(char p) : jeton(p) {};

    int jouerTour(const Plateau& plateau) const override; // Definition de la méthode 'jouerTour' pour l'IA

    // Méthodes necessaires à l'algorithme minimax
    int minimax(Plateau plateau, int profondeur, bool maxJoueur) const;
    int evaluer(const Plateau& plateau) const;
};


#endif