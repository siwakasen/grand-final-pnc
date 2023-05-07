#include "header.h"

void init(DataPemesan bangku[WIDTH_SEAT][LENGTH_SEAT]){
    int i,j;
    for(i=0;i<WIDTH_SEAT;i++){
        for(j=0;j<LENGTH_SEAT;j++){
            strcpy(bangku[i][j].nama,"");
            strcpy(bangku[i][j].noTelp,"");
            strcpy(bangku[i][j].tglPesan,"");
            bangku[i][j].umur=0;
        }
    }

}


