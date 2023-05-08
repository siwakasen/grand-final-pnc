#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#define ESC 27

typedef char string[100];

#define ROW 8   
#define COLUMN 8  
#define WIDTH_SEAT 10
#define LENGTH_SEAT 6


typedef struct{
    int y,x;
}CursorPosition;

//Detail transaksi
//nama film
//teater (standard/premire) (small/larga)

typedef struct DataPemesan{
    string id;
    string nama;
    string tglPesan;
}DataPemesan;

typedef struct{
    string namaFilm;
    string jenisTeater;
    DataPemesan p[WIDTH_SEAT][LENGTH_SEAT];
}DetailTeater;


// 1 (0,0) 2 3 4 5 
//3

DetailTeater d[4];

//============================
//|[A1][A2][A3]  [A4][A5][A6] |
//|[B1][B2][B3]  [B4][B5][B6] |
//|
//|
//|

void init(DataPemesan bangku[WIDTH_SEAT][LENGTH_SEAT]);

void generateMapA(string patternMap[ROW][COLUMN], DataPemesan bangku[WIDTH_SEAT][LENGTH_SEAT]);
void showMap(string patternMap[ROW][COLUMN]);

void generateCursPosition(CursorPosition c, string map[ROW][COLUMN]);
void CursMovement(CursorPosition *C);
