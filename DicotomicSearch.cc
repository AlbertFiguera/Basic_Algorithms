#include <iostream>
#include <vector>
using namespace std;



int posicio(double x, const vector<double>& v, int esq, int dre){
 
  int mid=(dre+esq)/2;
  
  if (esq > dre) return -1;
  else if (v[mid] == x) return mid;  
  else if (v[mid] > x) return posicio(x, v, esq, mid - 1);
  else if (v[mid] < x) return posicio(x, v, mid + 1, dre);
  
  
  
}


int main(){

  vector<double> v(5);
  for (int i = 0; i < v.size(); ++i){
    cin >> v[i];
  }
  
  int x;
  
  cin >> x;
  
  int pos = posicio(x , v, 0, v.size() - 1);
  
  cout << pos << endl;
  
  
  
  
}