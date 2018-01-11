#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

typedef vector<char> Fila;
typedef vector<Fila> Matriu;

bool es_valid(vector<int>& v, int etapa){
  for(int i = 0; i < etapa; ++i){
    if( v[i] == v[etapa] ) return false;
  }return true;
}

void escriure_matriu(vector<int>& v, Matriu m){
  for(int i = 0; i < v.size(); ++i){
    m[i][v[i]]='R';
  }
  for(int i = 0; i < m.size(); ++i){
     for(int j = 0; j < m[0].size(); ++j){
       cout << m[i][j];
    }cout << endl;
  }cout << endl;
}


void back_tracking(vector<int>& v, Matriu m, int etapa){
  int n = v.size();
  if(etapa != n){
    for(int i = 0; i < m[0].size(); ++i){
      v[etapa] = i;
      if(es_valid(v,etapa)){
	if(etapa == v.size() - 1) escriure_matriu(v, m);
	else back_tracking(v, m, etapa + 1);
      }
    }
  }
}

int main(){
  int n;
  int m;
  cin >> n >> m;
  Matriu mat(n, Fila(m, '.'));
  vector <int> v(n);
  back_tracking(v, mat, 0); 
  
  
}