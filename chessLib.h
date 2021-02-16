#ifndef chessLib
#define chessLib

typedef struct poz{
    short yatay; 
    char dusey; 
}poz;

int duseyPozisyonBul(char);
int IndexBul(char);
char PozisyonaGoreDusey(int);

void hareketYazdir(char,poz);

 poz *hareketSah(poz);
 poz *hareketVezir(poz);
 poz *hareketFil(poz);
 poz *hareketAt(poz);
 poz *hareketKale(poz);
 poz *hareketPiyon(poz);

#endif
