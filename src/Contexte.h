/* 
 * File:   Contexte.h
 * Author: jujulejaffa
 *
 * Created on 17 février 2016, 14:08
 */

#ifndef CONTEXTE_H
#define	CONTEXTE_H

#include "Utils.h"
#include <string>
#include <vector>
#include <math.h>
#include <iostream>


using namespace std;
class Contexte {
public:
    Contexte();
    Contexte(const Contexte& orig);
    ~Contexte();
    // fonction de hachage 
    // In: Clair c ----> Out: Empreinte
    void h( string c, unsigned char* &d ); //deuxième string, le haché md5
    // In: position t, empreinte d ---> Retourne index
    uint64_t h2i( uint64_t t, unsigned char* d );

    uint64_t getN() const {
        return _N;
    }

    void setN(uint64_t _N) {
        this->_N = _N;
    }

    int getNb_lettres() const {
        return _nb_lettres;
    }

    void setNb_lettres(int _nb_lettres) {
        this->_nb_lettres = _nb_lettres;
    }
    
     // In: index idx ----> Out: Clair c
    void i2c( uint64_t idx, string & c );
    // In: index idx ----> retourne index (la composée des précédentes)
    uint64_t i2i( uint64_t idx );
    // Retourne un indice aléatoire valide.
    uint64_t randIndex();


      
private:
    uint64_t _N;            // nombre de mots
    int _mot_taille_min;  // nombre de lettres min d'un mot
    int _mot_taille_max;  // nombre de lettres max d'un mot
    vector<uint64_t> _N_taille;   // tableau, nombre de mots d'une taille donnée
    vector<uint64_t> _paliers;   // tableau, nombre de mots pour un nombre de lettres données

    int _nb_lettres;     // nombre de lettres possibles pour un caractère
    char* _lettres;      // tableau des lettres, de taille _nb_lettres
    

   
  

};


#endif	/* CONTEXTE_H */

