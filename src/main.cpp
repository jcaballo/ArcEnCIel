/* 
 * File:   main.cpp
 * Author: jujulejaffa
 *
 * Created on 17 février 2016, 13:53
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "Contexte.h"
#include "ArcEnCiel.h"
using namespace std;

bool cracker( unsigned char* y, ArcEnCiel aec, Contexte ctxt,
                string & clair ) {
    int nb_fausses_alertes = 0;
    for ( int t = aec.getT() - 1; t > 0; --t ) {
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
    /*arc.creer(ctx);
    arc.save("table.txt");*/
    arc.load("table.txt");
    unsigned char* hache=new unsigned char[16];
    string toto = "xznyx";
    ctx.h(toto, hache);
    cracker(hache, arc, ctx, clair);
    cout << clair;
    
    
}

