/* 
 * File:   Utils.h
 * Author: jujulejaffa
 *
 * Created on 17 février 2016, 14:49
 */
#include <openssl/md5.h>
#include <openssl/sha.h>
#include <cstdint>
#include <string>

#ifndef UTILS_H
#define	UTILS_H

using namespace std;

void HashMD5(unsigned char* pPlain, int nPlainLen, unsigned char* &pHash);
void HashSHA1(unsigned char* pPlain, int nPlainLen, unsigned char* pHash);


struct Chaine {
  uint64_t idx1;    // premier indice de la chaine
  uint64_t idxT;    // dernier indice de la chaine
};


#endif	/* UTILS_H */

