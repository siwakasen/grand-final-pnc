#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#define ESC 27

typedef char string[100];

#define MAP 2
#define ROW 8       
#define COLUMN 7  
#define WIDTH_SEAT 5
#define LENGTH_SEAT 5


typedef struct{
    int x,y;
}CursorPosition;

typedef struct{
    string nama;
    int noTelp;
}DataPemesan;

typedef struct{
    string viewMap[ROW][COLUMN];
    DataPemesan bangku[WIDTH_SEAT][LENGTH_SEAT];
}Map;

void init();


void generateMap(string map[ROW][COLUMN], DataPemesan bangku[WIDTH_SEAT][LENGTH_SEAT]);
void showMap(string map[ROW][COLUMN]);

void generateCursPosition(CursorPosition c, string map[ROW][COLUMN]);
void CursMovement(CursMovement *c);
