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


}

void ArcEnCiel::creer(Contexte &ctxt) {
    creer(ctxt, _numero, _M, _T);
}

void ArcEnCiel::creer(Contexte &ctxt, int num, int M, int T) {
    _X = new Chaine[M];
    cout << ctxt.getN() << endl;

    for (int i = 0; i < M; i++) {
        Chaine chaine;
        chaine.idx1 = ctxt.randIndex();
        uint64_t idx = chaine.idx1;
        for (int j = 1; j < T; j++) {
            idx = ctxt.i2i(idx);
        }
        chaine.idxT = idx;
        _X[i] = chaine;
    }
}

void ArcEnCiel::echanger(int a, int b) {
    Chaine temp = _X[a];
    _X[a] = _X[b];
    _X[b] = temp;
}

void ArcEnCiel::trier() {
    trier(0, _M - 1);
}

void ArcEnCiel::trier(int debut, int fin) {

    int gauche = debut - 1;
    int droite = fin + 1;
    const uint64_t pivot = _X[debut].idxT;

    if (debut >= fin)
        return;


    /* On parcourt le tableau, une fois de droite à gauche, et une
       autre de gauche à droite, à la recherche d'éléments mal placés,
       que l'on permute. Si les deux parcours se croisent, on arrête. */
    while (1) {
        do droite--; while (_X[droite].idxT > pivot);
        do gauche++; while (_X[gauche].idxT < pivot);

        if (gauche < droite)
            echanger(gauche, droite);
        else break;
    }

    /* Maintenant, tous les éléments inférieurs au pivot sont avant ceux
       supérieurs au pivot. On a donc deux groupes de cases à trier. On utilise
       pour cela... la méthode quickSort elle-même ! */
    trier(debut, droite);
    trier(droite + 1, fin);

}

void ArcEnCiel::save(string name) {
    ofstream fichier(name, ios::out | ios::trunc); // ouverture en écriture avec effacement du fichier ouvert

    if (fichier) {
        for (int i = 0; i < _M; i++) {

            fichier << _X[i].idx1;
            fichier << " ";
            fichier << _X[i].idxT;
            fichier << endl;
        
        }


        fichier.close();
    } else
        cerr << "Impossible d'ouvrir le fichier !" << endl;

}

void ArcEnCiel::load(string name) {
    ifstream fichier(name, ios::in);

    if (fichier) {
        int i = 0;
        _X = new Chaine[_M];
        while (!fichier.eof()) {
            fichier >> _X[i].idx1 >> _X[i].idxT; /*on lit jusqu'à l'espace et on stocke ce qui est lu dans la variable indiquée */
            i++;

        }
        fichier.close();

    } else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
}

bool ArcEnCiel::recherche(Contexte &ctxt, uint64_t idx, uint& p, uint& q) {

    int debut = p;
    int fin = q;
    int milieu;
    int indice;
    while (fin - debut > 1) {
        milieu = (debut + fin) / 2;

        if (idx == _X[milieu].idxT) {

            string c;
            ctxt.i2c(idx, c);
            return true;
        }

        indice = _X[milieu].idx1;

        for (int j = 0; j < _T; j++) {
            if (idx == indice) {
                string c;
                ctxt.i2c(idx, c);
                return true;
            }

            indice = ctxt.i2i(indice);
        }

        if (_X[milieu].idxT > idx) {
            fin = milieu;
        } else {
            debut = milieu;
        }


    }

    return false;
}

// Retourne vrai si l'alerte était bonne, c est alors le texte clair 
 // correspondant à l'empreinte y.
 bool ArcEnCiel::VerifieAlerte( Contexte &ctxt, unsigned char* y,
                         int t, int m, 
                         string &c )
 {
    // X[ m ] est le couple ( i_m1, i_mT )
    // c : texte clair si trouvé
    unsigned char* hach = new unsigned char[16];
    // On parcourt à partir du début de la chaîne
    uint64_t idx = _X[m].idx1;   // i_m1
    for(int k = 1 ; k<t; k++){
      idx = ctxt.i2i( idx );  // h2i( k, h( i2c( idx ) ) )
    }
    ctxt.i2c( idx, c );
    ctxt.h(c, hach);
    return y == hach;
 }
 
ArcEnCiel::ArcEnCiel(const ArcEnCiel& orig) {
}

ArcEnCiel::~ArcEnCiel() {
}

