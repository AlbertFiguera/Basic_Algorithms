#include <iostream>
#include <vector>
using namespace std;

int posicio(double x, const vector<double>& v, int esq, int dre){
  if (esq > dre) return -1;
  int mid=(dre+esq)/2;
  if (v[mid] == x and (mid == 0 or v[mid-1] != x)) return mid;  
  if (v[mid] < x) return posicio(x, v, mid + 1, dre);
  else return posicio(x, v, esq, mid - 1);
}


int first_occurrence(double x, const vector<double>& v){
  return posicio(x, v, 0, v.size() -1);
}



int main(){
  
  int n;  
  cin >> n;  
  vector<double> v(n);  
  for (int i = 0; i < v.size(); ++i){    
    cin >> v[i];    
  }  
  int x;  
  cin >> x;
  int pos = first_occurrence(x, v);  
  cout << pos << endl;
  
  
}