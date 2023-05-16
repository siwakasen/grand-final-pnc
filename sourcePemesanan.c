#include "header.h"
void initDataPemesan( DataPemesan p[ROW][COLUMN], string ukuran){
    int i,j;
    char huruf='A';
    string temp="";
    string num="";

    if(strcmpi(ukuran,"large")==0){
        Index pemesanX[30];
        randomPemesan(ROW,COLUMN,pemesanX);
        for(i=0;i<ROW;i++){
            for(j=0;j<COLUMN;j++){
                if(isRandomPemesanLarge(i,j,pemesanX)){
                    strcpy(p[i][j].nama,"(Unknown Customer)");
                    strcpy(p[i][j].tglPesan,"-");
                }else{
                    strcpy(p[i][j].nama,"");
                    strcpy(p[i][j].tglPesan,"");
                }
                strncat(temp,&huruf,1); sprintf(num,"%d",j+1); strcat(temp,num);
                strcpy(p[i][j].id,temp);
                strcpy(temp,"");
                
            }
            huruf++;
        }
    }else{
        Index pemesanY[15];
        randomPemesan(ROWSMALL,COLUMN,pemesanY);
        for(i=0;i<ROWSMALL;i++){
            for(j=0;j<COLUMN;j++){
                if(isRandomPemesanSmall(i,j,pemesanY)){
                    strcpy(p[i][j].nama,"(Unknown Customer)");
                    strcpy(p[i][j].tglPesan,"-");
                }else{
                    strcpy(p[i][j].nama,"");
                    strcpy(p[i][j].tglPesan,"");
                }
                strncat(temp,&huruf,1); sprintf(num,"%d",j+1); strcat(temp,num);
                strcpy(p[i][j].id,temp);
                strcpy(temp,"");
            }
            huruf++;
        }
    }
}
void randomPemesan(int row, int col, Index r[]){
    int k,l;
    int i,j;

    if(row==ROW) l=30;
    else l=15;

    for(i=0;i<l;i++){
        r[i].x=-1;
        r[i].y=-1;
    }

    if(row==ROW){
        for(k=0;k<l;k++){
            do{
                i= (rand() % (row));
                j= (rand() % (col));
            }while(isRandomPemesanLarge(i,j,r));
            r[k].y=i;
            r[k].x=j;
        }
    }else{
        for(k=0;k<l;k++){
            do{
                i= (rand() % row);
                j= (rand() % col);
            }while(isRandomPemesanSmall(i,j,r));
            r[k].y=i;
            r[k].x=j;
        }
    }
}
bool isRandomPemesanLarge(int y, int x, Index r[]){
    int i;
    for(i=0;i<30;i++){
        if(r[i].x==x && r[i].y==y) return true;
    }
    return false;
}
bool isRandomPemesanSmall(int y, int x, Index r[]){
    int i;
    for(i=0;i<15;i++){
        if(r[i].x==x && r[i].y==y) return true;
    }
    return false;
}

void inputDataPemesan(DataPemesan p[ROW][COLUMN], int y, int x){
    string nama;
    string tanggal;
    int hari,bln,thn;
    int i;
    gotoxy(3,46); printf("--=== Input Data Pemesan ===--");
    do{
        gotoxy(4,46); printf("Masukkan nama pemesan : "); fflush(stdin); gets(nama);
        if(strlen(nama)==0){
            gotoxy(5,46); printf("[!] Nama pemesan harus diisi"); getch();
            gotoxy(5,46); printf("                            ");
        }
    }while(strlen(nama)==0);
    do{
        gotoxy(5,46); printf("Masukkan tanggal pemesanan : "); fflush(stdin);gets(tanggal);
        sscanf(tanggal,"%d-%d-%d", &hari,&bln,&thn);
        if(!isValidTanggal(tanggal,hari,bln,thn)){
            gotoxy(6,46); printf("[!] Tanggal tidak valid");getch();
            gotoxy(6,46); printf("                        ");
            gotoxy(5,75); for(i=0;i<=strlen(tanggal);i++) printf(" "); // fix harusnya y = 75
        }else{
            sprintf(tanggal,"%02d-%02d-%04d",hari,bln,thn);
            if(strlen(tanggal)!=10){
                gotoxy(6,46); printf("[!] Tanggal tidak valid");getch();
                gotoxy(6,46); printf("                        ");
                gotoxy(5,75); for(i=0;i<strlen(tanggal);i++) printf(" ");
            }
        }   
    }while(!isValidTanggal(tanggal,hari,bln,thn) || strlen(tanggal)!=10);
    strcpy(p[y][x].nama,nama);
    strcpy(p[y][x].tglPesan,tanggal);
    gotoxy(7,46); printf("[+] Pemesanan Berhasil !"); getch();
    clearInput();
}
void showDataPemesan(DataPemesan p[ROW][COLUMN], int y, int x){
   gotoxy(3,46); printf("   --=== Data Pemesan ===--");
   gotoxy(4,46); printf("Nama Pemesan  : %s",p[y][x].nama);
   gotoxy(5,46); printf("Tanggal Pesan : %s",p[y][x].tglPesan);
   getch();
   clearInput();
}
bool isValidTanggal(string tanggal, int hari,int bln,int thn){
    if(thn<1) return false;
    if(bln<1 || bln>12) return false;
    if(hari<1) return false;
    if(thn%4==0){
        if(bln==1 || bln==3 || bln==5 || bln==7 || bln==8 || bln==10 || bln==12){
            if(hari>31) return false;
        }else if(bln == 4 || bln==6 || bln==9 || bln==11){
            if(hari>30) return false;
        }else if(bln==2){
            if(hari>29) return false;
        }
    }else{
        if(bln==1 || bln==3 || bln==5 || bln==7 || bln==8 || bln==10 || bln==12){
            if(hari>31) return false;
        }else if(bln == 4 || bln==6 || bln==9 || bln==11){
            if(hari>30) return false;
        }else if(bln==2){
            if(hari>28) return false;
        }
    }
    return true;
}
Index findSeat(DataPemesan p[ROW][COLUMN], string input, string ukuran){
    Index idx;
    idx.x=-1;
    idx.y=-1;
    int i,j;
    
    if(strcmpi(ukuran,"large")==0){
        for(i=0;i<ROW;i++){
            for(j=0;j<COLUMN;j++){
                if(strcmpi(p[i][j].id,input)==0){
                    idx.y=i;
                    idx.x=j;
                }
            }
        }
    }else{
        for(i=0;i<ROWSMALL;i++){
            for(j=0;j<COLUMN;j++){
                if(strcmpi(p[i][j].id,input)==0){
                    idx.y=i;
                    idx.x=j;
                }
            }
        }
    }

    return idx;
}
