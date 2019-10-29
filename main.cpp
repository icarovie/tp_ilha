// Icaro Henrique Vieira Pinheiro
// 2018046556
#include <iostream>
#include <fstream>

//Classes
#include "Ilha.h"
#include "Viagem.h"

using namespace std;

int main(int argc, char** argv){
    int custoMaximo;
    int numeroIlhas;
    
    char* file = argv[1];

    // Entrada de dados do arquivo
    ifstream dados(file);

    dados >> custoMaximo;
    dados >> numeroIlhas;

    Ilha ilhas[numeroIlhas];

    for (int i = 0; i <numeroIlhas; i++){
        float custo;
        float pontuacao;
        float relacaoCustoBeneficio;

        // Atribuo  para cada ilha, o custo, a sua pontuacao e o custo beneficio dela ( pra facilitar posteriormente o meu Greedy)
        dados >> custo >> pontuacao;
        ilhas[i].custo = custo;
        ilhas[i].pontuacao = pontuacao;

        relacaoCustoBeneficio = custo / pontuacao;
        ilhas[i].relacaoCustoBeneficio = relacaoCustoBeneficio;

        // debug
        //cout << "Ilha "<< i<<": Custo-> "<<ilhas[i].custo<<" Pontuacao-> "<<ilhas[i].pontuacao<<" CustoBeneficio-> "<<  ilhas[i].relacaoCustoBeneficio<<endl;
    }

    Viagem viagem;
    int indiceFinalVetor = numeroIlhas - 1;

    // Ordeno as ilhas por melhor custo beneficio ( ou seja, aquela que tiver o menor custo por ponto)
    viagem.mergeSort(ilhas,0, indiceFinalVetor);

    //Calculo as viagens
    viagem.viagemRepeticao(ilhas, numeroIlhas, custoMaximo);
    viagem.viagemSemRepeticao(ilhas, numeroIlhas, custoMaximo);

    return 0;
}