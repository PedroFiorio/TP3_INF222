#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

vector<double> LerArray(string nome_arquivo) {
    cout << "Li" << endl;
    fstream arquivo(nome_arquivo);
    if(!arquivo.is_open()) {
      cerr << "Erro na leitura do arquivo" << endl;
    }

    vector<double> arr;
    double valor;
    while(arquivo >> valor)
        arr.push_back(valor);

    arquivo.close();
    return arr;
}

int EscreverArray(string nome_arquivo, vector<double> &array) {
    cout << "abri para escrever" << endl;
    ofstream arquivo(nome_arquivo);
    if(!arquivo.is_open()) {
      cerr << "Erro na leitura do arquivo" << endl;
      return 1;
    }

    for(double num : array)
        arquivo << num << endl;

    arquivo.close();
    return 0;
}

void SemiSort(vector<double> &array) {
    cout << "SemiSort" << endl;
    int n = array.size();
    bool swapped = true;

    while(swapped) {
        swapped = false;
        for(int i=0; i<n-1; i++) {
            if(rand()%2) 
                continue;
            
            if(array[i] > array[i+1]) {
                swap(array[i], array[i+1]);
                swapped = true;
            }
        }
    }
}

int main() {

    srand(time(nullptr));

    // vector<double> array_uniforme_quase_ordenado = LerArray("./teste.txt");
    // for(double valor : array_uniforme_quase_ordenado)
    //     cout << valor << " ";
    // cout << endl;
    // SemiSort(array_uniforme_quase_ordenado);
    // EscreverArray("./output_teste.txt", array_uniforme_quase_ordenado);
    // for(double valor : array_uniforme_quase_ordenado)
    //     cout << valor << " ";

    vector<double> array_uniforme_quase_ordenado = LerArray("./array_uniforme.txt");
    SemiSort(array_uniforme_quase_ordenado);
    EscreverArray("array_uniforme_quase_ordenado.txt", array_uniforme_quase_ordenado);

    vector<double> array_nao_uniforme_quase_ordenado = LerArray("./array_nao_uniforme.txt");
    SemiSort(array_nao_uniforme_quase_ordenado);
    EscreverArray("array_nao_uniforme_quase_ordenado.txt", array_uniforme_quase_ordenado);

    return 0;
}