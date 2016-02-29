/* 
 * File:   ArcEnCiel.cpp
 * Author: jujulejaffa
 * 
 * Created on 17 février 2016, 14:44
 */

#include "ArcEnCiel.h"

ArcEnCiel::ArcEnCiel() {
    _numero = 0;
    _T = 5000;
    _M = 100;
    Contexte ctx;
    creer(ctx, _numero, _M, _T);
    
}

void ArcEnCiel::creer(Contexte ctxt, int num, int M, int T) {
    for(int i=0; i<ctxt.getN(); i+=M)
    {
        for(int j=0; j<M; j++)
        {
            //Il faut creer les chaines (id de debut, id de fin)
        }
        
    }
}

ArcEnCiel::ArcEnCiel(const ArcEnCiel& orig) {
}

ArcEnCiel::~ArcEnCiel() {
}

