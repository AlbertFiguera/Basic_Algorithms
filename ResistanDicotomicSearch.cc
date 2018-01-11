#include <vector>
#include <iostream>
using namespace std;

bool i_resistant_search(double x, const vector<double>& v, int esq, int dre){
    if( esq > dre ) return false;
    int mid = (esq + dre)/2;
    if ( v[mid] == x or v[mid + 1] == x or v[mid - 1] == x ) return true;
    else if ( v[mid] > x ) return i_resistant_search(x, v, esq, mid - 2);
    else return i_resistant_search(x, v, mid + 2, dre);
}

bool resistant_search(double x, const vector<double>& v){
    return i_resistant_search(x, v, 0, v.size() - 1);
}



int main(){
    int n;
    cin >> n;
    vector <double> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    double x;
    cin >> x;
    if ( resistant_search(x, v) ) cout << "Sí que está" << endl;
    else cout << "no hi és" << endl;
    
}