#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#define ESC 27

typedef char string[100];

#define ROW 8   
#define COLUMN 8  
#define WIDTH_SEAT 5
#define LENGTH_SEAT 6


typedef struct{
    int y,x;
}CursorPosition;

typedef struct DataPemesan{
    string nama;
    string noTelp;
    string tglPesan;
    int umur;
}DataPemesan;

typedef struct{
    DataPemesan bangku[WIDTH_SEAT][LENGTH_SEAT];
    string pattern[ROW][COLUMN];
}ClassMap;

void init(DataPemesan bangku[WIDTH_SEAT][LENGTH_SEAT]);


void generateMapA(string patternMap[ROW][COLUMN], DataPemesan bangku[WIDTH_SEAT][LENGTH_SEAT]);
void showMap(string patternMap[ROW][COLUMN]);

void generateCursPosition(CursorPosition c, string map[ROW][COLUMN]);
void CursMovement(CursorPosition *C);
