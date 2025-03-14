#include <stdio.h>

int main(){
    
    int tabuleiro [10][10]={0};
    int LinhaHorizontal=3,ColunaHorizontal=2;
    int LinhaVertical=5,ColunaVertical=6;
    //Navio 1
    for(int x=0;x<3;x++){
        tabuleiro[LinhaHorizontal][ColunaHorizontal + x] =3;
    }
    //Navio 2
    for(int y=0;y<3;y++){
        tabuleiro[LinhaVertical + y][ColunaVertical]=3;
    }
    printf("Tabuleiro batalha naval\n");
    printf("    A  B  C  D  E  F  G  H  I  J\n");
    //Numeros do lado esquerdo
    for(int x=0;x<10;x++){
        printf("%2d ",x+1);
    for(int y=0;y<10;y++){
           printf(" %d ",tabuleiro[x][y]);
       } 
        printf("\n");
    }
    return 0;
}