#include "header.h"
void initTeater(Teater t[], string ukuranMap){
    int i;
    DataPemesan p[ROW][COLUMN];
    strcpy(t[0].jenisTeater,"Standard");
    strcpy(t[1].jenisTeater,"Premiere");
    
    for(i=0;i<2;i++){
        initDataPemesan(t[i].dMap.p,ukuranMap);
        generateMap(&t[i].dMap);
    }
}
void initFilm(string namaFilm[], Teater t[], int indexFilm){
    strcpy(t[0].namaFilm,namaFilm[indexFilm]);
    strcpy(t[1].namaFilm,namaFilm[indexFilm+1]);
}

void generateMap(DetailMap *dMap){
    int i,j;
    for(i=0;i<ROW;i++){
        for(j=0;j<COLUMN;j++){
            strcpy(dMap->map[i][j],dMap->p[i][j].id);
        }
    }
}

void showMap(DetailMap dMap,string ukuran, int y, int x, int space1, int space2){
    int i,j;
    if(strcmpi(ukuran,"large")==0){
        for(i=0;i<ROW;i++){
            for(j=0;j<COLUMN;j++){
                if(j==space1 || j==space2)printf("    ");
                printf("[");
                    if(strcmp(dMap.map[i][j],"##")==0){
                        setColor(red,black);
                    }else if(strcmp(dMap.map[i][j],"**")==0){
                        setColor(green,black);
                    }
                   printf("%s", dMap.map[i][j]);
                setColor(white,black);
                printf("]");
            }
            gotoxy(y+i+1,x);
        }
    }else{
        for(i=0;i<ROWSMALL;i++){
            for(j=0;j<COLUMN;j++){
                if(j==space1 || j==space2)printf("    ");
                printf("[");
                    if(strcmp(dMap.map[i][j],"##")==0){
                        setColor(red,black);
                    }else if(strcmp(dMap.map[i][j],"**")==0){
                        setColor(green,black);
                    }
                    printf("%s", dMap.map[i][j]);
                setColor(white,black);
                printf("]");
            }
            gotoxy(y+i+1,x);
        }
    }
}

void generateCursPosition(Index c,string map[ROW][COLUMN], bool hasData){
    if(hasData){
        strcpy(map[c.y][c.x],"##");
    }else{
        strcpy(map[c.y][c.x],"**");
    }
}
void showTeater(Teater t,string ukuran){
    gotoxy(1,4); printf("====[ %s ]====", t.namaFilm);
    if(strcmpi(t.jenisTeater,"Standard")==0){
    	gotoxy(5,8); showMap(t.dMap,ukuran,5,8,-1,3);
        if(strcmpi(ukuran,"large")==0) border(3,4,13,9,t.jenisTeater);
        else border(3,4,8,9,t.jenisTeater);
    }else{
    	gotoxy(5,8); showMap(t.dMap,ukuran,5,8,2,4);
        if(strcmpi(ukuran,"large")==0) border(3,4,13,10,t.jenisTeater);
        else border(3,4,8,10,t.jenisTeater);
    }
}
void border(int y, int x, int row, int column, string jenis){
    int i,j;
	gotoxy(y,x);
    setColor(yellow,black);
	for(i=1;i<=row;i++)
	{
		for(j=1;j<= column;j++)
		{
			if(i==1 || i==row){
                printf("[][]");
            }else if(j==1){
                printf("[][]");
            }else if(j == column){
            	if(strcmpi(jenis,"Standard")==0){
            		gotoxy(i+2, 36); printf("[][]");	
				}
				else{
					gotoxy(i+2, 40); printf("[][]");
				}
			}else if(i==2){
                setColor(white,black);
				printf("====");
                setColor(yellow,black);
            }
		}
		gotoxy(y+i,x);	
	}
    setColor(white,black);
}

void showPointerMap(string jenis, int row){
    int i,j;
    if(strcmpi(jenis,"standard")==0){
        for(i=0;i<row;i++){
            gotoxy(4+i,37); printf(">>");
        }
    }else{
        for(i=0;i<row;i++){
            gotoxy(4+i,5); printf("<<");
        }
    }
}

void clearMap(){
	int i;
	gotoxy(1,4); printf("                                                        ");
    for(i = 3 ; i <= 25 ; i++){
    	gotoxy(i, 4); printf("                                                   ");
	}
}

void clearInput(){
	gotoxy(3,46); printf("                                     ");
	gotoxy(4,46); printf("                                                               ");
	gotoxy(5,46); printf("                                                               ");
	gotoxy(7,46); printf("                                     ");
}

//============================
void play(string jenis){
    int i;
    gotoxy(4,8);
    if(strcmpi(jenis,"standard")==0){
        for(i=0;i<28;i++){
            printf("%c", 177);
        }
    }else{
        for(i=0;i<32;i++){
            printf("%c", 177);
        }
    }
    Sleep(1000);
}
