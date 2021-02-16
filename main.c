#include <stdio.h>
#include <stdlib.h>
#include "chessLib.h"


int main(int argc, char *argv[]) {
	
    struct poz p;
    short yatay;
    char dusey; 
    
    printf("Dusey char elemani yaziniz\n");
    scanf("%c",&dusey);
    printf("Yatay int elemani yaziniz\n");
    scanf("%d",&yatay);
    
    p.dusey=dusey;
    p.yatay=yatay;
    puts("");
      
    hareketYazdir('P', p);    
    hareketYazdir('S', p);  
    hareketYazdir('V', p); 
    hareketYazdir('F', p);    
    hareketYazdir('A', p);    
    hareketYazdir('K', p);      
  
   return 0;
}
