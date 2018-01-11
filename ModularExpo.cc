#include<iostream>
#include<vector>
#include <math.h>
using namespace std;






int quick_exp(int x, int n,  int m){
  if (n == 0) return 1;
  else{
    int y = quick_exp(x, n/2, m) % m;
    if ( n % 2 == 0) return (y*y)%m;
    else return (((y*y)%m)*x)%m;
  }
}




int main(){
  //n^k modm
  int n;
  while (cin >> n){
    int k, m;
    cin >> k >> m;    
    cout << quick_exp(n, k, m) << endl;
  }
}