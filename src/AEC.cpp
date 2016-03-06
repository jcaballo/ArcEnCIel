/* 
 * File:   Crack.cpp
 * Author: jujulejaffa
 *
 * Created on 17 février 2016, 13:53
 */
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include "Contexte.h"
#include "ArcEnCiel.h"
using namespace std;


bool cracker( unsigned char* y, ArcEnCiel &aec, Contexte &ctxt,
                string & clair ) {
    int nb_fausses_alertes = 0;
    for ( uint t = aec.getT() - 1; t > 0; --t ) {
       // fabrication du bon indice
       uint64_t idx = ctxt.h2i( t, y );
       for ( int k = t + 1; k <= aec.getT() - 1; ++k ) {
         idx = ctxt.i2i( idx );
       }
       // Recherche dans la table.
       uint id = 0;
       uint M = aec.getM();
       if ( aec.recherche(ctxt, idx, id, M ) ) {
         // On vérifie chacune des alertes
         for ( int m = 0; m <= aec.getM(); ++m ) {
           if ( aec.VerifieAlerte( ctxt, y, t, m, clair ) )
             return true;
           nb_fausses_alertes++;
         }
       }
    }
    cout << "Non trouve, fausses alertes = " << nb_fausses_alertes <<endl;
    return false;
  }

/*
 * 
 */
int main(int argc, char** argv) {
    ArcEnCiel arc;
    Contexte ctx;
    string clair="";
    if (argc < 4) {
        cerr << "Usage : ./AEC <Load|Create> <Filename> <MD5Hach>";
        exit(1);
    }
    
    if(strcmp(argv[1],"Create") == 0){
        arc.creer(ctx);
        arc.save(argv[2]);

    } else if(strcmp(argv[1],"Load") == 0){
        arc.load(argv[2]);
    }
    else {
        cerr << "Usage : ./AEC <Load|Create> <Filename> <MD5Hach>";
        exit(1);

    }
    
    
    cracker((unsigned char*)argv[3], arc, ctx, clair);
    cout << clair;
    
    
}

