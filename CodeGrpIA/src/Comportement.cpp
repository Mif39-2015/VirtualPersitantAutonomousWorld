#include "Comportement.hpp"

Comportement::Comportement(vector<Noeud*> vN, Noeud * nD, vector<Noeud*> nFs) : noeuds(vN), noeudDepart (nD), noeudsFin(nFs) {}

void Comportement::AjouterNoeud(Noeud * n){
    noeuds.push_back(n);
}

void Comportement::SupprimerNoeud(Noeud * n){
    for (std::vector<Noeud *>::iterator it = noeuds.begin() ; it != noeuds.end(); ++it){
        if(*it == n) noeuds.erase(it);
    }
}

