// Icaro Henrique Vieira Pinheiro
// 2018046556
#include <iostream>
#include <fstream>

//Classes
#include "ilha.cpp"

using namespace std;

int main(int argc, char** argv){
    int custoMaximo;
    int numeroIlhas;

    //Pega o nome do arquivo para ser aberto e fazer a leitura dos dados
    char* file = argv[1];

    ifstream dados(file);

    dados >> custoMaximo;
    dados >> numeroIlhas;

    Ilha ilhas[numeroIlhas];

    //Para preencher o vetor de ilhas usamos esse laço de repetição de custo N(nº de ilhas)

     for (int i = 0; i <numeroIlhas; i++){
        float custo;
        float pontuacao;
        float relacaoCustoBeneficio;

        dados >> custo >> pontuacao;
        ilhas[i].custo = custo;
        ilhas[i].pontuacao = pontuacao;

        relacaoCustoBeneficio = custo / pontuacao;
        ilhas[i].relacaoCustoBeneficio = relacaoCustoBeneficio;

        cout << "Ilha "<< i<<": Custo-> "<<ilhas[i].custo<<" Pontuacao-> "<<ilhas[i].pontuacao<<" CustoBeneficio-> "<<  ilhas[i].relacaoCustoBeneficio<<endl;
     }


    return 0;
}