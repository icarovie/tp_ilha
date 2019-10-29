
#ifndef VIAGEM_HPP
#define VIAGEM_HPP

// Bibliotecas padrao da linguagem
#include <iostream>
#include <algorithm>

// Classes
#include "Ilha.h"

using namespace std;

class Viagem{
    private:
        int numeroDias = 0;
        int custoMaximo;
        int pontuacao = 0;

    public:
        // Mergesort para ordenar as ilhas
        void merge(Ilha *ilhas ,int indiceEsq, int meio, int indiceDir);
        void mergeSort(Ilha *ilhas, int indiceEsq, int indiceDir);

        // Funcoes para as viagens
        void reset();
        void viagemRepeticao(Ilha* ilhas, int custoMaximo, int numeroIlhas);
        void viagemSemRepeticao(Ilha* ilhas, int custoMaximo, int numeroIlhas);
};

#endif