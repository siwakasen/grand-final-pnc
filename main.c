#include "header.h"
int main(int argc, char *argv[]) {
	srand(time(NULL));
	Teater t[2];
	string namaFilm[6]={"Spongebob SquarePants","Angry Birds","One Piece","Boboiboy","Kung Fu Panda 3","The Avengers"};
	int indexFilm=0;
	Index c,temp;
	char move;
	string ukuran;
	string input;
	strcpy(ukuran, "large");
	bool hasData=false;
	int current = 0; //current 0 = standard, current 1 = premiere
	setColor(white,black);
	hide_cur();

	c.y=0;c.x=0;
	initTeater(t,ukuran);
	initFilm(namaFilm,t,indexFilm);
	
	do{
		generateMap(&t[current].dMap);
		hasData=isHasData(t[current].dMap.p,c); //menentukan pd posisi cursor ada data/tidak
		generateCursPosition(c,t[current].dMap.map,hasData); //generate posisi cursor
		showTeater(t[current],ukuran);
		printf("\n\n\n    [Enter] Pesan/Lihat Detail");
		printf("\n    [P] Play Film");
		printf("\n    [F] Find Seat");
		move = getch();
		move = tolower(move);

		if(isValidMovement(move,c,t[current].jenisTeater,ukuran)) CursMovement(&c, move);
		
		if(move != 'w' && move != 'a' && move != 's' && move != 'd' && move != 13 &&
			move != 'p' && move != 'f') continue;
		
		if(current==0 && c.x==COLUMN){
			generateMap(&t[current].dMap);
			showTeater(t[current],ukuran);
			do{
				if(strcmpi(ukuran,"large")==0){
					showPointerMap(t[current].jenisTeater,ROW+1);
				}else{
					showPointerMap(t[current].jenisTeater,ROWSMALL+1);
				}
				move=getch();
			}while(move!='a' && move!='d');

			if(move=='d'){
				clearMap();
				c.x=0;
				current=1;
			} 
			else if(move=='a') {
				clearMap();
				c.x=COLUMN-1;		
			}
			
		}else if(current==1 && c.x==-1){
			generateMap(&t[current].dMap);
			showTeater(t[current],ukuran);
			do{
				if(strcmpi(ukuran,"large")==0){
					showPointerMap(t[current].jenisTeater,ROW+1);
				}else{
					showPointerMap(t[current].jenisTeater,ROWSMALL+1);
				}
				move=getch();
			}while(move!='a' && move!='d');
			
			if(move=='a'){
				clearMap();
				c.x=COLUMN-1;
				current=0;
			}else if(move=='d') {
				clearMap();
				c.x=0;
			}
		}
		if((move =='p'|| move=='P') && strcmpi(ukuran,"large")==0 ){
			play(t[current].jenisTeater);
			strcpy(ukuran,"small");
			initTeater(t,ukuran);
			if(indexFilm!=4) indexFilm+=2;
			else if(indexFilm==4) indexFilm=0;
			initFilm(namaFilm,t,indexFilm);
			c.y=0;c.x=0;
			clearMap();
		}else if((move =='p'||move =='P')  && strcmpi(ukuran,"small")==0){
			play(t[current].jenisTeater);
			strcpy(ukuran,"large");
			initTeater(t,ukuran);
			if(indexFilm!=4) indexFilm+=2;
			else if(indexFilm==4) indexFilm=0;
			initFilm(namaFilm,t,indexFilm);
			c.y=0;c.x=0;
			clearMap();
		}else if(move==13){
			if(strcmp(t[current].dMap.map[c.y][c.x],"**")==0){
				show_cur();
				inputDataPemesan(t[current].dMap.p,c.y,c.x);
				hide_cur();
			}else{
				showDataPemesan(t[current].dMap.p,c.y,c.x); 
				
			}
		}else if(move=='f'){
			show_cur();
				
				gotoxy(3,46); printf("--=== Input Data Pemesan ===--");
				gotoxy(4,46); printf("Masukkan Seat yang dicari : "); fflush(stdin); gets(input);
				temp=findSeat(t[current].dMap.p,input,ukuran);
				if(temp.x==-1){
					gotoxy(5,46); printf("[!] Seat tidak ditemukan"); getch();
					gotoxy(5,46); printf("                        ");
				}else{
					c.y=temp.y;
					c.x=temp.x;
					gotoxy(5,46); printf("[~] Berhasil pindah ke seat [%s]",t[current].dMap.p[temp.y][temp.x].id); getch();
				}
				clearInput();
				hide_cur();
			generateMap(&t[current].dMap);
			generateCursPosition(c,t[current].dMap.map,hasData);
			showTeater(t[current],ukuran);
        	
		}
	}while(move!=27);
	
	return 0;
}
