#include <stdio.h>
//função das habilidade
void Habilidade(int tabuleiro[10][10],int matriz[5][5],int origemLinha,int OrigemColuna){
    int tamanho=5;// tamanho das habilidades
    for(int x=0 ;x<tamanho; x++){
        for(int y=0 ;y<tamanho;y++){
            int linhaTabuleiro = origemLinha-tamanho / 2+x;
            int colunaTabuleiro = OrigemColuna- tamanho / 2+y;
            
            //Garantia de limite do tabuleiro
            if (linhaTabuleiro >=0 && linhaTabuleiro <10 &&
                colunaTabuleiro >=0 && colunaTabuleiro <10) {
                if(matriz[x][y]==1){ //Apenas se aplica se for area afetada
                    tabuleiro[linhaTabuleiro][colunaTabuleiro]=5;//Marca da Habilidade na área
                }    
            }
        }
    }
}


int main(){
    
    int tabuleiro [10][10]={0};// inicializa o tabuleiro com água
    int LinhaHorizontal=0,ColunaHorizontal=4;
    int LinhaVertical=3,ColunaVertical=9;
    // D = direita E= esquerdo
    int LinhaDiagonalED=3,ColunaED=0;
    int LinhaDiagonalDE=0,ColunaDE=9;
    //Navio 1
    for(int x=0;x<3;x++){
        tabuleiro[LinhaHorizontal][ColunaHorizontal + x]=3 ;
    }
    //Navio 2
    for(int y=0;y<3;y++){
        tabuleiro[LinhaVertical + y][ColunaVertical]=3;
    }
    //Navio 3
    for(int x=0;x<3;x++){
        tabuleiro[LinhaDiagonalED  +x][ColunaED+x ]=3;
    }
    //Navio 4
    for(int x=0;x<3;x++){
        tabuleiro[LinhaDiagonalDE +x ][ColunaDE-x]=3;
    }
    //Matriz de habilidade
    int cone[5][5]={
        {0,0,1,0,0},
        {0,1,1,1,0},    
        {1,1,1,1,1},  
        {0,0,0,0,0},
        {0,0,0,0,0}
    };
    int cruz[5][5]={
        {0,0,1,0,0},    
        {0,0,1,0,0},   
        {1,1,1,1,1},    
        {0,0,1,0,0},    
        {0,0,1,0,0}    
    };
    int octaendro[5][5]={
        {0,0,1,0,0},    
        {0,1,1,1,0},    
        {1,1,1,1,1},
        {0,1,1,1,0},
        {0,0,1,0,0}
    };
    Habilidade(tabuleiro,cone, 9, 2);//Posição do cone    
    Habilidade(tabuleiro,cruz, 4, 4);//Posição da cruz
    Habilidade(tabuleiro,octaendro, 7, 7);//Posição do octaendro   
    
    printf("-----Tabuleiro batalha naval-----\n");
    printf("    A  B  C  D  E  F  G  H  I  J\n");
   
    for(int x=0;x<10;x++){
        printf("%2d ",x+1);//Numeros do lado esquerdo
    for(int y=0;y<10;y++){
           if(tabuleiro[x][y]==0) printf(" 0 ");//Água
           else if (tabuleiro[x][y]==3) printf(" 3 ");//Navio
           else if (tabuleiro[x][y]==5) printf(" X ");//Habilidade
           
       } 
        printf("\n");
    }
    return 0;
}