#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
using namespace std;

int LerArray(string nome_arquivo) {
    fstream arquivo(nome_arquivo)
    if(!arquivo.is_open()) {
      cerr << "Erro na leitura do arquivo" << endl;
      return 1;
    }

    vector<double> arr;
    double valor;
    while(cin >> valor)
        arr.push_back(valor)

    arquivo.close();
}

vector<double> Dijkstra(vector<double> array) {
    int i = 0;
    int j = 0;
    int k = array.size()-1;

    while(j <= k) {
        if(array[j] < 0) {
            swap(array[i], array[j]);
            i++;
            j++;
        } else if(array[j] > 0) {
            swap(array[j], array[k]);
            k--;
        } else 
            j++;
    }

    return array;
}

vector<double> NossoMetodo(vector<double> array) {
    vector<double> initial = vector<double>(0.0, array.size());
    int beg = 0;
    int end = array.size()-1;

    for(double num : array) {
        if(num < 0) {
            initial[beg] = num;
            beg++;
        } else if(num > 0) {
            initial[end] = num;
            end--;
        }
    }

    return initial;
}

int main() {
    
    vector<double> array_uniforme = LerArray("");
    vector<double> array_nao_uniforme = LerArray("");
    vector<double> array_uniforme_quase_ordenado = LerArray("");
    vector<double> array_nao_uniforme_quase_ordenado = LerArray("");

    cout << "Nosso metodo com array uniforme e dados aleatorios" << endl;
    auto tempo_inicial = chrono::high_resolution_clock::now();
    NossoMetodo(array_uniforme);
    auto tempo_final = chrono::high_resolution_clock::now();
    auto tempo = chrono::duration_cast<chrono::seconds>(tempo_final - tempo_inicial);
    cout << "Tempo: " << tempo.count() << " segundos" << endl << endl;

    cout << "Metodo de Dijkstra com array uniforme e dados aleatorios" << endl;
    tempo_inicial = chrono::high_resolution_clock::now();
    Dijkstra(array_uniforme);
    tempo_final = chrono::high_resolution_clock::now();
    tempo = chrono::duration_cast<chrono::seconds>(tempo_final - tempo_inicial);
    cout << "Tempo: " << tempo.count() << " segundos" << endl << endl;

    cout << "Nosso metodo com array nao uniforme e dados aleatorios" << endl;
    tempo_inicial = chrono::high_resolution_clock::now();
    NossoMetodo(array_nao_uniforme);
    tempo_final = chrono::high_resolution_clock::now();
    tempo = chrono::duration_cast<chrono::seconds>(tempo_final - tempo_inicial);
    cout << "Tempo: " << tempo.count() << " segundos" << endl << endl;

    cout << "Metodo de Dijkstra com array nao uniforme e dados aleatorios" << endl;
    tempo_inicial = chrono::high_resolution_clock::now();
    Dijkstra(array_nao_uniforme);
    tempo_final = chrono::high_resolution_clock::now();
    tempo = chrono::duration_cast<chrono::seconds>(tempo_final - tempo_inicial);
    cout << "Tempo: " << tempo.count() << " segundos" << endl << endl;

    cout << "Nosso metodo com array uniforme e dados quase ordenados" << endl;
    tempo_inicial = chrono::high_resolution_clock::now();
    NossoMetodo(array_uniforme_quase_ordenado);
    tempo_final = chrono::high_resolution_clock::now();
    tempo = chrono::duration_cast<chrono::seconds>(tempo_final - tempo_inicial);
    cout << "Tempo: " << tempo.count() << " segundos" << endl << endl;

    cout << "Metodo de Dijkstra com array uniforme e dados quase ordenados" << endl;
    tempo_inicial = chrono::high_resolution_clock::now();
    Dijkstra(array_uniforme_quase_ordenado);
    tempo_final = chrono::high_resolution_clock::now();
    tempo = chrono::duration_cast<chrono::seconds>(tempo_final - tempo_inicial);
    cout << "Tempo: " << tempo.count() << " segundos" << endl << endl;
    
    cout << "Nosso metodo com array nao uniforme e dados quase ordenados" << endl;
    tempo_inicial = chrono::high_resolution_clock::now();
    NossoMetodo(array_nao_uniforme_quase_ordenado);
    tempo_final = chrono::high_resolution_clock::now();
    tempo = chrono::duration_cast<chrono::seconds>(tempo_final - tempo_inicial);
    cout << "Tempo: " << tempo.count() << " segundos" << endl << endl;

    cout << "Metodo de Dijkstra com array nao uniforme e dados quase ordenados" << endl;
    tempo_inicial = chrono::high_resolution_clock::now();
    Dijkstra(array_nao_uniforme_quase_ordenado);
    tempo_final = chrono::high_resolution_clock::now();
    tempo = chrono::duration_cast<chrono::seconds>(tempo_final - tempo_inicial);
    cout << "Tempo: " << tempo.count() << " segundos" << endl << endl;

    return 0;
}