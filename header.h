#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>
#define ESC 27

typedef char string[100];

#define ROW 10   
#define ROWSMALL 5
#define COLUMN 6


#define white 15
#define gray 8
#define green 10
#define blue 9
#define purple 13
#define red 12
#define sky 11
#define yellow 14

#define grayX 7
#define black 0
#define purpleX 5
#define blueX 1
#define redX 4
#define skyX 3
#define greenX 2
#define yellowX 6

typedef struct{
    int y,x;
}Index;

typedef struct DataPemesan{
    string id;
    string nama;
    string tglPesan;
}DataPemesan;

typedef struct{
    string map[ROW][COLUMN];
    DataPemesan p[ROW][COLUMN];
}DetailMap;

typedef struct{
    string namaFilm; //bebas
    string jenisTeater; //standard/premiere (small/standard)
    DetailMap dMap;
}Teater;

void initFilm(string namaFilm[], Teater t[], int indexFilm);
void initTeater(Teater t[], string ukuranMap);
void generateMap(DetailMap *dMap);
void showTeater(Teater t,string ukuran);
void showMap(DetailMap dMap, string ukuran, int y, int x, int space1, int space2);
void showPointerMap(string jenis, int row);
void clearMap();
void clearFindSeat(string teaterInput, string seatInput);
void clearInputData(string nama, string tgl);
void clearShow(string nama, string tgl);
void play(string jenis);

void generateCursPosition(Index c, string map[ROW][COLUMN], bool hasData);
void CursMovement(Index *c, char move);
bool isValidMovement(char move, Index c, string jenisMap, string ukuran);
bool isHasData(DataPemesan p[ROW][COLUMN], Index c);

void initDataPemesan( DataPemesan p[ROW][COLUMN],string ukuran);
void randomPemesan(int row, int col, Index r[]);
bool isRandomPemesanLarge(int i, int j, Index r[]);
bool isRandomPemesanSmall(int y, int x, Index r[]);
void inputDataPemesan(DataPemesan p[ROW][COLUMN], int y, int x);
void showDataPemesan(DataPemesan p[ROW][COLUMN], int y, int x);
bool isValidTanggal(string tanggal, int hari,int bln,int thn);
bool cekDigit(string s);
bool cekSpasi(string s);
bool cekHuruf(string s);
bool cekAwalanSpasi(string s);

void border(int y, int x, int row, int column, string jenis);
void hide_cur();
void show_cur();
void gotoxy(int y, int x);
void setColor(char text,char bg);
Index findSeat(DataPemesan p[ROW][COLUMN], string input, string ukuran);
