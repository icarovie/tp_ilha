// Bibliotecas Padrao
#include <algorithm>
#include <iostream>

// Classe
#include "Viagem.h"

using namespace std;

void Viagem::mergeSort(Ilha *ilhas, int indiceEsq, int indiceDir) {
    // Verifico se um apontador nao ultrapassou o outro, porque se tiver um simplesmente nao faco nada
    if(indiceEsq < indiceDir){
        int tam = indiceDir + indiceEsq;
        int meio = tam/2;
        mergeSort(ilhas,meio + 1, indiceDir);
        mergeSort(ilhas,indiceEsq, meio);   
        merge(ilhas, indiceEsq, meio, indiceDir); // Depois do mergesort dos dois lados, preciso fazer o Merge agora
    }
}

void Viagem::merge( Ilha *ilhas, int indiceEsq, int meio, int indiceDir){
    Ilha vetorEsq[ meio - indiceEsq + 1];
    Ilha vetorDir[indiceDir - meio];
    int countEsq = 0;
    int countDir = 0;
    int aux = indiceEsq;

    // Atribuo os valores para cada vetor separadamente, tanto o esquerdo como o direito
    for(int i = 0 ; i <  meio - indiceEsq + 1 ; i++)
        vetorEsq[i] = ilhas[indiceEsq + i];           
    for(int i = 0; i < indiceDir - meio ;  i++)
        vetorDir[i] = ilhas[meio + 1 + i]; 
    
    // Vou verificar quem tem o melhor custo beneficio, enquanto o vetor nao acaba
    while (countDir < indiceDir - meio && countEsq <  meio - indiceEsq + 1){
        float custoBeneficioEsquerda = vetorEsq[countEsq].relacaoCustoBeneficio;
        float custoBeneficioDireita = vetorDir[countDir].relacaoCustoBeneficio;

        //pego o item do vetor com o melhor custo beneficio
        if(custoBeneficioEsquerda > custoBeneficioDireita){
            ilhas[aux] = vetorEsq[countEsq];
            countEsq++;
        }else{
            ilhas[aux] = vetorDir[countDir];
            countDir++; 
        }
        aux++;
    }

    // Pode ocorrer de uma particao ser maior que a outra, dessa forma precisamos colocar todos os elementos da particao maior no final do vetor, seja ela da esquerda ou da direita
    while(countEsq < meio - indiceEsq + 1)
        ilhas[aux++] = vetorEsq[countEsq++];

    while(countDir < indiceDir - meio)
        ilhas[aux++] = vetorDir[countDir++];
}
    