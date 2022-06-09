#include <cstdlib>
#include <iostream>
#include<ctime>
#include <string.h>
using namespace std;

int pecas_o = 5;
int pecas_x = 5;
char tab[30] = {'o','x','o','x','o','x','o','x','o','x',' ',
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '
    ,' ',' ',' ',' ',' ' };

    void imprime(){
        int i;
        i =0;
        while( i < 10){
            cout << " " << i <<" ";
            i++;
        } 
        for( i=10;i < 30;i++){
            cout << i <<" ";
        } 
        cout << endl;
        for(i=0; i <10;i++){
            cout << "[" << tab[i]<<"]";
        }

        for(i=10;i<30;i++){
            cout << "[" << tab[i] << "]";
        }
        cout << endl;
    }
    int sorteio(){
        return (rand()%6) +1;

    }

    char muda_jogador(char atual){
        char aux;

        if((atual == 'x') | (atual != 'o') ){
            return 'o';
        }else if((atual == 'o') | (atual !='x')) {
            return 'x';
        }


    }
    int movimenta(char jogador, int origem, int num){
        int destino, aux;
        destino = origem +num;
        if (0< origem <29 ){ 
            if(tab[origem] == jogador){
                if ( 0 < destino < 30){ 
                    if(tab[destino] == ' '){
                        aux = tab[destino];
                        tab[destino] = tab[origem];
                        tab[origem] =aux;   
  
                    }else cout << "Destino cheio" << endl; 
                }else cout << "Fora do limite" << endl;
            }else cout << "Origem diferente/vazia" <<  endl;
        }else cout << "Origem fora" << endl;

        if(destino == 29){
            tab[29] = ' ';
            if(jogador == 'o' ){
                pecas_o = pecas_o -1;

            }else{
                pecas_x =pecas_x -1;
            }

        }
        imprime();
        return 1;  
    }


    int main(){
        int pos, sucesso,dado, repetir;
        char vez = 'o';
        char passar_vez;
        passar_vez =' ';
        srand(time(NULL));
        while(pecas_o> 0 || pecas_x > 0){
            //dado = sorteio();
            imprime();
            repetir = 1;
            while(repetir = 1){
                dado = sorteio(); // posicao trocada
                cout << "dado = " << dado << endl;
                
                cout << "[jogador " << vez << "] Deseja passar a vez?[s/n]";
                cin >> passar_vez;
                getchar();
                if(passar_vez == 's'){
                    vez = muda_jogador(vez);
                    cout << "vez:" << vez << endl; //testa se mudou o jogador
                    repetir = 0;
                }else if(passar_vez == 'n'){
                    cout << "[Jogador "<< vez <<"] Escolha posicao:";
                    cin >> pos;
                    getchar();
                    cout << endl;
                    sucesso = movimenta(vez, pos, dado);
                    if(sucesso == 1){
                        if((dado == 2) || (dado == 5) || (dado == 3)){
                            vez = muda_jogador(vez);
                        }
                        repetir = 0;
                    }
                }
            }
        
            if (pecas_o=0){
                cout << "[jogador_x] Vencedor " << endl;
            }else if(pecas_x = 0){
                cout << "[Jogador_o] Vencedor!" << endl;
            } 
        }
        return 0;
    }