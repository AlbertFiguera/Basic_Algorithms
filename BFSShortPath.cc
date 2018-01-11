#include<iostream>
#include<vector>
#include<queue>
#include <list>
#include <set>
using namespace std;

void cami_mes_curt(vector< set<int> > &graf, vector<int>& camino){
    int n = graf.size();
    vector<int> distancia(n, -1);
    distancia[0] = 0;
    queue<int> pendents;
    pendents.push(0);
    bool trobat = false;
    while(not trobat and not pendents.empty()){
        int act = pendents.front();
        pendents.pop();
        if(act == -1)trobat = true;
        int m = graf[act].size();
        set<int>::const_iterator it;
        for (it = graf[act].begin(); it != graf[act].end(); it++) {
            int v = *it;
            if (distancia[v] == -1) {
                distancia[v] = distancia[act] + 1;
                camino[v] = act;
                pendents.push(v);
            }
        }
        
    }
}
void escribir_camino(const vector<int> &camino, int i) {
    int n = camino.size();
    if (i != -1) {
        escribir_camino(camino, camino[i]);
        if (i == 0) cout << i;
        else cout << ' ' << i;
    }
}

int main(){
    int n, m;
    while(cin >> n >> m){
        vector< set<int> > graf(n);
        for(int i = 0; i < m; ++i){
            int u, v;
            cin >> u >> v;
            graf[u].insert(v);
        }
        vector<int> camino(n, -1);
        cami_mes_curt(graf, camino);
        escribir_camino(camino, n - 1);
        cout << endl;
        
    }
    
    
}