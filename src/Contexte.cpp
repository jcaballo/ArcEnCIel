/* 
 * File:   Contexte.cpp
 * Author: jujulejaffa
 * 
 * Created on 17 février 2016, 14:08
 */

#include "Contexte.h"

void Contexte::h(string c, unsigned char* &d) {
    HashMD5((unsigned char*)c.c_str(), c.size(), d);
}

uint64_t Contexte::h2i(uint64_t t, unsigned char* d) {
    uint64_t* ptr = (uint64_t *)d;
    
    return ((*ptr+t) % _N);
}

void Contexte::i2c(uint64_t idx, string& c) {
    int i;
    for(i=0 ; i < _paliers.size(); i++)
    {
        if(idx <= _paliers[i]){
            break;
        }
    }
    
    for(int j=0; j<i+_mot_taille_min; j++)
    {
        c.push_back(_lettres[idx%_nb_lettres]);
        idx = idx/_nb_lettres;
    }
    
}

uint64_t Contexte::i2i(uint64_t idx) {
    string toto;
    unsigned char* totoHash;
    totoHash = new unsigned char[MD5_DIGEST_LENGTH];
    Contexte cont;
    cont.i2c(idx, toto);
    cont.h(toto, totoHash);
    return cont.h2i(1, totoHash);
}

uint64_t Contexte::randIndex(){
    unsigned long n1 = random();
    unsigned long n2 = random();
    uint64_t n = ( (uint64_t) n2 ) 
           + ( ( (uint64_t) n1 ) << 8 );
    return n%_N;
}
Contexte::Contexte() {
     _N = 0;
    _lettres="abcdefghijklmnopqrstuvwxyz"; 
    _nb_lettres = 26; 
    _mot_taille_min = 5;
    _mot_taille_max = 5;
    for(int i=_mot_taille_min ; i<=_mot_taille_max; i++){
        uint64_t var = pow(_nb_lettres,i);
        _N += var;
        _N_taille.push_back(var);
        i ==_mot_taille_min ? _paliers.push_back(pow(_nb_lettres, i)) : _paliers.push_back(_paliers[i-1]+pow(_nb_lettres, i));
    } 
    
}

Contexte::Contexte(const Contexte& orig) {
}

Contexte::~Contexte() {
}

