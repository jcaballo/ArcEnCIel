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
    trier(0, _M-1);
    save("table.txt");
    
}

void ArcEnCiel::creer(Contexte ctxt, int num, int M, int T) 
{
    _X = new Chaine[M];
    for(int i=0; i<M; i++)
    {
        Chaine chaine;
        chaine.idx1 = ctxt.randIndex();
        uint64_t idx = chaine.idx1;
        for(int j=1; j<T; j++)
        {
            idx = ctxt.i2i(idx);
        }
        chaine.idxT = idx;
        _X[i] = chaine;
    }
}
void ArcEnCiel::echanger(int a, int b)
{
    Chaine temp = _X[a];
    _X[a] = _X[b];
    _X[b] = temp;
}

void ArcEnCiel::trier(int debut, int fin) {

    int gauche = debut-1;
    int droite = fin+1;
    const uint64_t pivot = _X[debut].idxT;

    if(debut >= fin)
        return;


    /* On parcourt le tableau, une fois de droite à gauche, et une
       autre de gauche à droite, à la recherche d'éléments mal placés,
       que l'on permute. Si les deux parcours se croisent, on arrête. */
    while(1)
    {
        do droite--; while(_X[droite].idxT > pivot);
        do gauche++; while(_X[gauche].idxT < pivot);

        if(gauche < droite)
            echanger(gauche, droite);
        else break;
    }

    /* Maintenant, tous les éléments inférieurs au pivot sont avant ceux
       supérieurs au pivot. On a donc deux groupes de cases à trier. On utilise
       pour cela... la méthode quickSort elle-même ! */
    trier(debut, droite);
    trier(droite+1, fin);

}

void ArcEnCiel::save(string name) {
    ofstream fichier(name, ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
 
    if(fichier)
    {
        for(int i = 0 ; i < _M ; i++){

             fichier << _X[i].idx1 << " " << _X[i].idxT << endl; 


        }


         fichier.close();
    }
    else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    
}

void ArcEnCiel::load(string name) {

}

ArcEnCiel::ArcEnCiel(const ArcEnCiel& orig) {
}

ArcEnCiel::~ArcEnCiel() {
}

