#include "Utils.h"

void HashMD5(unsigned char* pPlain, int nPlainLen, unsigned char* &pHash)
{
  MD5(pPlain, nPlainLen, pHash);
}
void HashSHA1(unsigned char* pPlain, int nPlainLen, unsigned char* pHash)
{
  SHA1(pPlain, nPlainLen, pHash);
}
