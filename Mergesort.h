#ifndef MERGESORT_H
#define MERGESORT_H

#include "Ilha.h"

class Mergesort{
    void mergeSort(int esquerda, int direita, Ilha *ilhas);
    void merge(int esquerda, int meio, int direita, Ilha *ilhas);
};


#endif