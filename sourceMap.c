#include "header.h"
//generate border map, screen & bangku yg terbooking/belum
void generateMapA(string map[ROW][COLUMN], DataPemesan bangku[WIDTH_SEAT][LENGTH_SEAT]){
    int i,j;

    for(i=0;i<ROW;i++){
        for(j=0;j<COLUMN;j++){
            strcpy(map[i][j],"[%s]",bangku[i][j].id);
        }
    }
}

//menampilkan map
void showMap(string map[ROW][COLUMN]); 
