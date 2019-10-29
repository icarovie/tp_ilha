// Biblioteca Padrao
#include <algorithm>
#include <iostream>

// Classe
#include "Viagem.h"

using namespace std;

// Apos uma viagem, vou precisar resetar os atributos
void Viagem::reset(){
    this->pontuacao = 0;
    this->numeroDias = 0;
}

/*
* GREEDY ALGORITMH
*/
void Viagem::viagemRepeticao(Ilha* ilhas, int numeroIlhas, int custoMaximo){
    // reseto a pontuacao e os dias de viagem
    this->reset();

    // Vou comecar pelo ultimo item do vetor, porque devido ao mergesort ter ordenado, esse e o indice com menor custo por ponto
    int i = numeroIlhas - 1;
    this->custoMaximo = custoMaximo;
    // Enquanto eu nao tiver visitado todas as ilhas e nao tiver gastado
    while( custoMaximo > 0 && i >= 0){
        int custo = custoMaximo - ilhas[i].custo;
        // checo se o custo dessa ilha menos o custo maximo ainda e positivo
        if(custo >= 0){
            // Se for vou adicionar essa ilha na minha viagem, deduzindo o custo da ilha, somando na minha pontuacao e aumentando os dias de viagem
            custoMaximo = custoMaximo - ilhas[i].custo;
            pontuacao = pontuacao + ilhas[i].pontuacao;
            numeroDias++;
        }else
            i--;
    }
    // Imprimo a Pontuacao e os dias que as amigas ficaram na viagem
    cout<<pontuacao<<" "<< numeroDias<< endl;
}

/*
* DYNAMIC
*/
void Viagem::viagemSemRepeticao(Ilha* ilhas, int numeroIlhas, int custoMaximo){
        this->custoMaximo = custoMaximo + 1;
        // reinicio os dias e a pontuacao
        this->reset();
        // Conforme o algoritmo de programacao dinamica, vou precisar usar uma matriz pra ir armazenando os valores
        int matriz[numeroIlhas+1][custoMaximo];

        // Para conseguir a pontuacao maxima, vamos ter que montar a matriz de probabilidades inteira e pegar o ultimo valor
        for(int i = 0 ; i <= numeroIlhas; i++){
            for(int j = 0; j <= custoMaximo ; j++){
                // Caso base, porque nao posso viajar sem ilhas, ou sem dinheiro :(
                if(i == 0 || j == 0)
                    matriz[i][j] = 0;
                else if(ilhas[i-1].custo > j)
                    // Se o custo for maior, vou repetir o valor anterior
                    matriz[i][j] = matriz[i-1][j];
                else{
                    int max1 = ilhas[i -1].pontuacao + matriz[i-1][j - ilhas[i-1].custo];
                    int max2 = matriz[i-1][j];
                    // Comparo os dois pra ver quem tem o melhor resultado
                    matriz[i][j] = max(max1, max2);
                }
            }
        }

        // A maior pontuacao vai estar na ultima posicao
        int maiorPontuacao = matriz[numeroIlhas][custoMaximo];
        this->pontuacao = maiorPontuacao;

        //Como vou usar pra acumular, mas nao quero perder o custo maximo
        int custoMaximoAux = custoMaximo;
        int i = numeroIlhas;
        
        // Preciso achar o numero de dias
        while(pontuacao > 0  &&  i > 0){
             if( matriz[i-1][custoMaximoAux] != pontuacao){
                // Vou precisar decrementar o custo e a pontuacao ...
                custoMaximoAux = custoMaximoAux - ilhas[i- 1].custo;
                pontuacao = pontuacao - ilhas[i- 1].pontuacao;   
                numeroDias++; // e aumento 1 dia nessa viagem
            }
            i--;
        }
        // Imprimo a Pontuacao e os dias que as amigas ficaram na viagem
        int pontuacaoTotal = matriz[numeroIlhas][custoMaximo];
        cout<<pontuacaoTotal<<" "<<this->numeroDias;
    }

 