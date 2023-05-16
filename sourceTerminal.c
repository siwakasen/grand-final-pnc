#include "header.h"
void hide_cur()	//MENGHILANGKAN VISUAL KURSOR
{
	CONSOLE_CURSOR_INFO ConCurInf;
	ConCurInf.dwSize=18;
	ConCurInf.bVisible=FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&ConCurInf);
}

void gotoxy(int y, int x) 		//UNTUK MENENTUKAN KOORDINAT X dan Y
{
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void setColor(char text,char bg)  //UNTUK SET WARNA BORDER DAN TEXT
{
	unsigned short color=bg*16+text;
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleOutput,color);
}
void show_cur(){
	CONSOLE_CURSOR_INFO ConCurInf;
	ConCurInf.dwSize=20;
	ConCurInf.bVisible=TRUE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&ConCurInf);
}
