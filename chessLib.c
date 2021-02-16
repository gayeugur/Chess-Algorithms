#include <stdio.h>
#include <stdlib.h>
#include "chessLib.h"
#define M 8

int sayac = 0;
      
int IndexBul(char tas){

    if(tas == 'P'){
        return 0;
    }
    else if(tas == 'S'){
        return 1;
    }
    else if(tas == 'V'){
        return 2;
    }
    else if(tas == 'F'){
        return 3;
    }
    else if(tas == 'A'){
        return 4;
    }
    else if(tas=='K'){
        return 5;
    }else{
       printf("Error");
    }
}

int duseyPozisyonBul(char dusey){ 

    switch (dusey){
        case 'A':
            return 0;
            break;
           
        case 'B':
            return 1;
            break;

        case 'C':
            return 2;
            break;

        case 'D':
            return 3;
            break;

        case 'E':
            return 4;
            break;

        case 'F':
            return 5;
            break;

        case 'G':
            return 6;
            break;
        
        case 'H':
            return 7;
            break;
       
    }
}


char PozisyonaGoreDusey(int position){  

    switch (position){
        case 0:
            return 'A';
            break;
           
        case 1:
            return 'B';
            break;

        case 2:
            return 'C';
            break;

        case 3:
            return 'D';
            break;

        case 4:
            return 'E';
            break;

        case 5:
            return 'F';
            break;

        case 6:
            return 'G';
            break;
        
        case 7:
            return 'H';
            break;
    }
}

void hareketYazdir(char tas, poz ilkPozisyon){ 
                                                
    int** board = (int **) calloc(M, sizeof(int*));   
    int index = IndexBul(tas);        

    poz* (*satrancFonksiyonlari[6]) (poz ilkPoz); 
    satrancFonksiyonlari[0] = hareketPiyon;
    satrancFonksiyonlari[1] = hareketSah;
    satrancFonksiyonlari[2] = hareketVezir;
    satrancFonksiyonlari[3] = hareketFil;
    satrancFonksiyonlari[4] = hareketAt;
    satrancFonksiyonlari[5] = hareketKale;

     poz* hareket = (*satrancFonksiyonlari[index])(ilkPozisyon); 
     int i,j;
   
    for(i=0; i<M; i++){ 
        board[i] = (int*)calloc(M, sizeof(int)); 
        for(j=0; j<M; j++){ 
            board[i][j] = 0;  
        }
    }
    
    board[ilkPozisyon.yatay-1][duseyPozisyonBul(ilkPozisyon.dusey)] = 2;  
    
    for(i=0; i<sayac; i++){   
        board[hareket[i].yatay][duseyPozisyonBul(hareket[i].dusey)] = 1;       
    }

    for(i=M-1; i>=0; i--){
        for(j=0; j<M; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
     sayac = 0;
    puts("");
    
}
 poz *hareketPiyon( poz ilkPoz){
	puts("PIYON");
     poz* hareket = (poz*) malloc(2*sizeof(poz));  
     poz tasKonum;

    int yatay = ilkPoz.yatay-1;
    int dusey = duseyPozisyonBul(ilkPoz.dusey);


    if(yatay+1 != M){ 
        tasKonum.yatay = yatay+1;
        tasKonum.dusey = ilkPoz.dusey;
        hareket[sayac++] = tasKonum;
    }
    if(tasKonum.yatay==2){
	if(yatay+2 != M){
    		tasKonum.yatay = yatay+2;
        		tasKonum.dusey = ilkPoz.dusey;
        		hareket[sayac++] = tasKonum;	
	    }
    }

    return hareket;
}



 poz *hareketSah(poz ilkPoz){  
	puts("SAH");
     poz* hareket = (poz*) malloc(M*sizeof(poz)); 
     poz tasKonum;

    int yatay = ilkPoz.yatay-1;
    int dusey = duseyPozisyonBul(ilkPoz.dusey);   
                                                  

     if(yatay-1 != -1){
        tasKonum.yatay = yatay-1;
        tasKonum.dusey = ilkPoz.dusey;
        hareket[sayac++] = tasKonum;
    }
    
    if(yatay+1 != M){
        tasKonum.yatay = yatay+1;
        tasKonum.dusey = ilkPoz.dusey;
        hareket[sayac++] = tasKonum;
    }



    if(dusey-1 != -1){
        tasKonum.yatay = yatay;
        tasKonum.dusey = PozisyonaGoreDusey(dusey-1);
        hareket[sayac++] = tasKonum;
    }
    if(dusey+1 != M){
        tasKonum.yatay = yatay;
        tasKonum.dusey = PozisyonaGoreDusey(dusey+1);  
        hareket[sayac++] = tasKonum;
    }


    if(dusey-1 != -1 && yatay+1 != M ){ 
        tasKonum.yatay = yatay+1;
        tasKonum.dusey = PozisyonaGoreDusey(dusey-1);
        hareket[sayac++] = tasKonum;
    }

    if(dusey-1 != -1 && yatay-1 != -1){ 
        tasKonum.yatay = yatay-1;
        tasKonum.dusey = PozisyonaGoreDusey(dusey-1);
        hareket[sayac++] = tasKonum;
    }

    if(dusey+1 != M && yatay-1 != -1){ 
        tasKonum.yatay = yatay-1;
        tasKonum.dusey = PozisyonaGoreDusey(dusey+1);
        hareket[sayac++] = tasKonum;
    }

    if(dusey+1 != M && yatay+1 != M){ 
        tasKonum.yatay = yatay+1;
        tasKonum.dusey = PozisyonaGoreDusey(dusey+1);
        hareket[sayac++] = tasKonum;
    }

    return hareket;
}


 poz *hareketVezir( poz ilkPoz){    
	puts("VEZIR");
     poz tasKonum;
     poz* hareket = ( poz*) malloc((M*M)*sizeof( poz)); 
          
    int yatay = ilkPoz.yatay-1;
    int dusey = duseyPozisyonBul(ilkPoz.dusey);


    
    while(yatay-1 != -1){
        tasKonum.yatay = --yatay;
        tasKonum.dusey = ilkPoz.dusey;
        hareket[sayac++] = tasKonum;
    }

    yatay = ilkPoz.yatay-1;
    dusey = duseyPozisyonBul(ilkPoz.dusey);
    
      while(yatay+1 != M){
        tasKonum.yatay = ++yatay;
        tasKonum.dusey = ilkPoz.dusey;
        hareket[sayac++] = tasKonum;
    }

    yatay = ilkPoz.yatay-1;
    dusey = duseyPozisyonBul(ilkPoz.dusey);


    while(dusey-1 != -1){
        tasKonum.yatay = yatay;
        tasKonum.dusey = PozisyonaGoreDusey(--dusey);
        hareket[sayac++] = tasKonum;
    }

    yatay = ilkPoz.yatay-1;
    dusey = duseyPozisyonBul(ilkPoz.dusey);
    
    while(dusey+1 != M){
        tasKonum.yatay = yatay;
        tasKonum.dusey = PozisyonaGoreDusey(++dusey);
        hareket[sayac++] = tasKonum;
    }

    yatay = ilkPoz.yatay-1;
    dusey = duseyPozisyonBul(ilkPoz.dusey);

     while(dusey-1 != -1 && yatay-1 != -1){ 
        tasKonum.yatay = --yatay;
        tasKonum.dusey = PozisyonaGoreDusey(--dusey);
        hareket[sayac++] = tasKonum;
    }

    yatay = ilkPoz.yatay-1;
    dusey = duseyPozisyonBul(ilkPoz.dusey);
    
    while(dusey-1 != -1 && yatay+1 != 8 ){  
        tasKonum.yatay = ++yatay;
        tasKonum.dusey = PozisyonaGoreDusey(--dusey);
        hareket[sayac++] = tasKonum;
    }

    yatay = ilkPoz.yatay-1;
    dusey = duseyPozisyonBul(ilkPoz.dusey);

    while(dusey+1 != M && yatay-1 != -1){
        tasKonum.yatay = --yatay;
        tasKonum.dusey = PozisyonaGoreDusey(++dusey);
        hareket[sayac++] = tasKonum;
    }

    yatay = ilkPoz.yatay-1;
    dusey = duseyPozisyonBul(ilkPoz.dusey);

    while(dusey+1 != M && yatay+1 != M){ 
        tasKonum.yatay = ++yatay;
        tasKonum.dusey = PozisyonaGoreDusey(++dusey);
        hareket[sayac++] = tasKonum;
    }

    return hareket;
}

 poz *hareketFil(poz ilkPoz){
	puts("FIL");
     poz* hareket = (poz*) malloc((M*2)*sizeof(poz)); 
     poz tasKonum;

    int yatay = ilkPoz.yatay-1;
    int dusey = duseyPozisyonBul(ilkPoz.dusey);

    
    while(dusey-1 != -1 && yatay-1 != -1){  
     
        tasKonum.yatay = --yatay;
        tasKonum.dusey = PozisyonaGoreDusey(--dusey);
        hareket[sayac++] = tasKonum;
    }

    yatay = ilkPoz.yatay-1;
    dusey = duseyPozisyonBul(ilkPoz.dusey);

    while(dusey-1 != -1 && yatay+1 != M){
        
        tasKonum.yatay = ++yatay;
        tasKonum.dusey = PozisyonaGoreDusey(--dusey);
        hareket[sayac++] = tasKonum;
     
    }

    yatay = ilkPoz.yatay-1;
    dusey = duseyPozisyonBul(ilkPoz.dusey);

   
    while(dusey+1 != M && yatay-1 != -1){
      
        tasKonum.yatay = --yatay;
        tasKonum.dusey = PozisyonaGoreDusey(++dusey);
        hareket[sayac++] = tasKonum;
    }

    yatay = ilkPoz.yatay-1;
    dusey = duseyPozisyonBul(ilkPoz.dusey);

    while(dusey+1 != M && yatay+1 != M){ 
       
        tasKonum.yatay = ++yatay;
        tasKonum.dusey = PozisyonaGoreDusey(++dusey);
        hareket[sayac++] = tasKonum;
    }

    return hareket;
}


 poz *hareketAt( poz ilkPoz){
   	puts("AT");
     poz* hareket = (poz*) malloc(M*sizeof( poz));  
     poz tasKonum;

    int yatay = ilkPoz.yatay-1;
    int dusey = duseyPozisyonBul(ilkPoz.dusey);

    
    
    if(dusey-1 != -1 && yatay+2 < M ){ 
        tasKonum.yatay = yatay+2;
        tasKonum.dusey = PozisyonaGoreDusey(dusey-1);
        hareket[sayac++] = tasKonum;
        
    }

    if(dusey-1 != -1 && yatay-2 > -1 ){  
        tasKonum.yatay = yatay-2;       
        tasKonum.dusey = PozisyonaGoreDusey(dusey-1);
        hareket[sayac++] = tasKonum;
        
    }

    if(dusey+1 != M && yatay-2 > -1 ){  
        tasKonum.yatay = yatay-2;
        tasKonum.dusey = PozisyonaGoreDusey(dusey+1);
        hareket[sayac++] = tasKonum;
       
    }

    if(dusey+1 != M && yatay+2 < M ){ 
        tasKonum.yatay = yatay+2;
        tasKonum.dusey = PozisyonaGoreDusey(dusey+1);
        hareket[sayac++] = tasKonum;
       
    }
     if(dusey-2 > -1 && yatay-1 != -1){ 
        tasKonum.yatay = yatay-1;
        tasKonum.dusey = PozisyonaGoreDusey(dusey-2);
        hareket[sayac++] = tasKonum;
       
    }

    if(dusey-2 > -1 && yatay+1 != M ){
        tasKonum.yatay = yatay+1;
        tasKonum.dusey = PozisyonaGoreDusey(dusey-2);
        hareket[sayac++] = tasKonum;
       
    } 
     if(dusey+2 < M && yatay+1 != M){ 
        tasKonum.yatay = yatay+1;
        tasKonum.dusey = PozisyonaGoreDusey(dusey+2);
        hareket[sayac++] = tasKonum;
    }
   
    if(dusey+2 < M && yatay-1 != -1){
        tasKonum.yatay = yatay-1;
        tasKonum.dusey = PozisyonaGoreDusey(dusey+2);
        hareket[sayac++] = tasKonum;
       
    }
  
    return hareket;
}

 poz *hareketKale(poz ilkPoz){
   	puts("KALE");
     poz tasKonum;
     poz* hareket = (poz*) malloc((M*M)*sizeof( poz)); 
   
    int yatay = ilkPoz.yatay-1;
    int dusey = duseyPozisyonBul(ilkPoz.dusey);

    
      while(yatay-1 != -1){ 
        tasKonum.yatay = --yatay;
        tasKonum.dusey = ilkPoz.dusey;
        hareket[sayac++] = tasKonum;

    }

    yatay = ilkPoz.yatay-1;
    dusey = duseyPozisyonBul(ilkPoz.dusey);
    while(yatay+1 != M){    
    
        tasKonum.yatay = ++yatay;
        tasKonum.dusey = ilkPoz.dusey;
        hareket[sayac++] = tasKonum;
    }

    yatay = ilkPoz.yatay-1;
    dusey = duseyPozisyonBul(ilkPoz.dusey);



    while(dusey+1 != M){    
        tasKonum.yatay = yatay;
        tasKonum.dusey = PozisyonaGoreDusey(++dusey);
        hareket[sayac++] = tasKonum;
    }

    yatay = ilkPoz.yatay-1;
    dusey = duseyPozisyonBul(ilkPoz.dusey);

    while(dusey-1 != -1){   
        tasKonum.yatay = yatay;
        tasKonum.dusey = PozisyonaGoreDusey(--dusey);
        hareket[sayac++] = tasKonum;
     
    }

    return hareket;
}
