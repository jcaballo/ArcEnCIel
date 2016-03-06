/* 
 * File:   ArcEnCiel.h
 * Author: jujulejaffa
 *
 * Created on 17 février 2016, 14:44
 */
#include "Utils.h"
#include "Contexte.h"
#include <iostream>
#include <fstream>

#ifndef ARCENCIEL_H
#define	ARCENCIEL_H

class ArcEnCiel {
public:
    ArcEnCiel();
    ArcEnCiel(const ArcEnCiel& orig);
    virtual ~ArcEnCiel();
    // Charge en mémoire la table à partir du disque.
    void load( string name );
    // Creer les M chaînes de taille T, dans le contexte ctxt
    void creer( Contexte &ctxt);
    void creer( Contexte &ctxt, int num, int M, int T );
    // Tri _X suivant idxT.
    void trier();
    void trier(int debut, int fin);
    //Pour echanger deux éléments lors du tri rapide
    void echanger(int a, int b);
    // Sauvegarde la table sur disque.
    void save( string name );
    bool VerifieAlerte( Contexte &ctxt, unsigned char* y,
                         int t, int m, 
                         string &c );

  // Recherche dichotomique dans la table
  // ( p et q sont le premier/dernier trouvé )
  bool recherche(Contexte &ctxt, uint64_t idx, uint & p, uint & q );

    uint getM() const {
        return _M;
    }

    void setM(uint _M) {
        this->_M = _M;
    }

    uint getT() const {
        return _T;
    }

    void setT(uint _T) {
        this->_T = _T;
    }

    Chaine* getX() const {
        return _X;
    }

    void setX(Chaine* _X) {
        this->_X = _X;
    }

    uint getNumero() const {
        return _numero;
    }

    void setNumero(uint _numero) {
        this->_numero = _numero;
    }

    
private:
  uint _numero;   // numero de la table (ici 0, mais voir "Moult tables")
  uint _M;        // nombre de chaines dans la table
  uint _T;        // taille de chaque chaine
  Chaine* _X;     // la table elle-meme
  
  
  

};

#endif	/* ARCENCIEL_H */

