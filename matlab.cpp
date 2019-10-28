#include <iostream>
#include <string>
#include <vector>
#include "matlab.h"

using namespace std;

Matriz::Matriz():Matriz(0,0,0){}

Matriz::Matriz(const int linhas, const int colunas, const double &valor){
   for(int i =0; i < linhas;++i){
       vector<double> aux;
       for(int j =0; j < colunas; ++j ){
           aux.push_back(valor);
       }
       matriz.push_back(aux);
   }
}

Matriz::~Matriz(){
    
}

void Matriz::zeros(){
    for(int i =0;i < matriz.size();i++){
       for(int j=0;j < matriz[i].size();j++){
           matriz[i][j] = 0;
       }
    }
}

Matriz Matriz::operator +(const Matriz& m){
    int tamlinha = matriz.size();
    int tamcol = matriz[0].size();
    if (tamlinha < m.matriz.size()) tamlinha = m.matriz.size();
    if (tamcol < m.matriz[0].size()) tamcol = m.matriz[0].size();
 
    Matriz r;
    for(int i =0;i < tamlinha ;i++){
        vector<double> aux;
        for(int j=0;j < tamcol ;j++){
            if (matriz[i][j] == ) cout<<"ACHEI"<<endl;
            cout<<"aqui";
            aux.push_back(matriz[i][j] + m.matriz[i][j]); 
            cout<<"aali"<<endl;    
        }
        r.matriz.push_back(aux);
    }
    printM(r.getMatriz());
    return r;
}

    // int tamlinha, tamlinhaa = matriz.size(), tamlinhab = m.matriz.size();
    // int tamcol, tamcola = matriz[0].size(), tamcolb = m.matriz[0].size();
    // if (tamlinhaa >= tamlinhab) tamlinha = tamlinhaa;
    //     else tamlinha = tamlinhab;
    // if (tamcola >= tamcolb) tamcol = tamcola;
    //     else tamcol = tamcolb;

//**************** printar matriz ****************
void printM(vector<vector<double>> M){
   for(int i =0;i < M.size();i++){
       for(int j=0;j < M[i].size();j++){
           cout << M[i][j] << " ";
       }
       cout << endl;
   }
}   
ostream& operator << (ostream& out, Matriz& M){
    for(int i =0;i < M.matriz.size();i++){
       for(int j=0;j < M.matriz[i].size();j++){
           out << M.matriz[i][j] << " ";
       }
       out << endl;
   }
}
istream& operator >> (istream& in, Matriz&M){
    int linha, coluna;
    double valor;
    cout <<"linhas: ";
    in >> linha;
    cout << "colunas: ";
    in >> coluna;
 for(int i =0; i < linha;++i){
       vector<double> aux;
       for(int j =0; j < coluna; ++j ){
           cout<< "m[" << i <<"][" << j << "] = ";
           in>> valor;
           aux.push_back(valor);
           
       }
       M.matriz.push_back(aux);
   }
}