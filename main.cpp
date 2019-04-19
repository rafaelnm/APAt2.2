#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

const static string PATH = "instancias_mochila/";

int max(int a, int b) {
  return (a > b)? a : b;
}
int mochila(int W, int wt[], int val[], int n){

  int K[n+1][W+1];

  for (size_t i = 0; i <= n; i++) {
    K[i][0] = 0;
  }
  for (size_t i = 0; i <= W; i++) {
    K[0][i] = 0;
  }

  for (size_t i = 1; i <= n; i++) {
    for (size_t x = 1; x <= W; x++) {
      if(wt[i-1] <= x){
        K[i][x] = max(val[i-1] + K[i-1][x-wt[i-1]],  K[i-1][x]);
      }
      else{
          K[i][x] = K[i-1][x];
      }
    }
  }
  //Tabela
  for(size_t i = 0; i <= n; i++) {
    for(size_t j = 0; j <= W; j++) {
        cout << "|" << K[i][j] <<"|";
    }
    cout << endl;
  }
  
  int peso = W;
  int size = n;
  std::vector<int> v;

  cout << endl;
  cout << "Peso dos itens: ";

  for (size_t i = size; i > 0; i--) {
    if(K[i][peso] != K[i-1][peso]){
      v.push_back(val[i-1]);
      peso = peso - wt[i-1] ;
      cout << wt[i-1] << " ";
    }
  }

  cout << endl;
  cout << "Peso maximo da mochia: " << W << endl;
  cout << "Valor dos itens: ";

  for (size_t i = 0; i < v.size(); i++) {
    cout << v.at(i) << " ";
  }
  cout << endl;

  return K[n][W];
}

int main(int argc, char const *argv[]) {

  string line;
  std::vector<int> vFile;

  for (size_t i = 0; i < 2; i++) {

    int number = i+1;

    //Abrindo diretorio do arquivo das instancias
    ifstream file(PATH + "mochila0"+ to_string(number) + ".txt");

    //Transferindo linhas do .txt pro vetor
    while(std::getline(file, line)){
      int n;
      istringstream iss(line);
      while (iss >> n) {
        vFile.push_back(n);
      }
    }

    int size = vFile.at(0);
    int W = vFile.at(1);
    int wt[] = {};
    int val[] = {};
    size_t vFile_half = (vFile.size()-2)/2;

    //Populando os vetores de peso[wt] e valor[val]
    for (size_t i = 0; i < vFile_half; i++) {
      wt[i] = vFile.at(i+2);
    }
    for (size_t i = 0; i < vFile_half; i++) {
      val[i] = vFile.at(vFile_half+2+i);
    }

    cout << endl;
    cout << "Valor maximo da mochila: "<< mochila(W, wt, val, size) << endl;

    vFile.clear();

  }

  cout << endl;

  return 0;
}