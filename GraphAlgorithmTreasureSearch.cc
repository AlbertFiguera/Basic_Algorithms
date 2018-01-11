#include <vector>
#include <iostream>
using namespace std;


typedef vector<char> Fila;
typedef vector<Fila> Matriu;

typedef vector<bool> Filab;
typedef vector<Filab> Matriub;


void ompliMatriu (int x,int y,Matriu& m){
  for (int i = 0; i < x; ++i){
    for (int j = 0; j < y; ++j){
      cin >> m[i][j];
    }    
  }
}

bool validPosition(const Matriu& m, int x, int y){
  return not(x < 0 or x >= m.size() or y < 0 or y >= m[0].size());
}


bool tresor ( const Matriu& m, Matriub& b  , int x, int y, int xi, int yi){
  
  if(b[xi][yi]) return false;
  
  else b[xi][yi] = true;
  
  if ( m[xi][yi] == 't') return true;
  if ( m[xi][yi] == 'X') return false;
  
 
  if(validPosition(m, xi+1, yi) and tresor( m, b, x, y, xi + 1, yi )) return true;

  if(validPosition(m, xi-1, yi) and tresor (m, b, x, y, xi - 1, yi) ) return true;
  
  if(validPosition(m, xi, yi+1) and tresor ( m, b, x, y, xi, yi + 1) ) return true;
  
  if(validPosition(m, xi, yi-1) and tresor ( m, b, x, y, xi, yi - 1) ) return true;

  return false;
  
}



int main(){
  
  int x, y;
  cin >> x >> y;
  
  Matriu m(x,Fila(y));
  
  Matriub b(x,Filab(y,false));
  
  ompliMatriu( x, y, m);
  
  int xi, yi;
  cin >> xi >> yi;
  
  if ( tresor (m, b, x, y, xi - 1, yi - 1 ) ) cout << "yes" << endl;
  else cout << "no" << endl;
  
  
}