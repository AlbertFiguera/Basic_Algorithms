#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

typedef pair<double, int> WArc;
typedef vector< vector<WArc> > Graf;

int dijksta(const Graf& adj, int inici, int desti){
    int n = adj.size();
    vector<int> distancies(n, -1);
    distancies[inici] = 0;
    vector<bool> visitats(n, false);
    priority_queue < WArc, vector<WArc>, greater <WArc> > pendents;
    pendents.push(WArc(0, inici));
    while(not pendents.empty()){
        int u = pendents.top().second;
        pendents.pop();
        if(not visitats[u]){
            visitats[u] = true;
            for(WArc a : adj[u]){
                int v = a.second;
                double c = a.first;
                if( distancies[v] > distancies[u] + c or
                    distancies[v] == -1){
                    distancies[v] = distancies[u] + c;
                    pendents.push(WArc(distancies[v], v));
                }
            
            }
        }
    }return distancies[desti];
}

int main(){
    int n, m;
    while( cin >> n >> m){
        Graf adj(n);
        int u, v;
        double c;
        for(int i = 0; i < m; ++i){
            cin >> u >> v >> c;
            adj[u].push_back(make_pair(c,v));
        }
        int inici, desti;
        cin >> inici >> desti;
        int resultat = dijksta(adj, inici, desti);
        if(resultat == -1) cout << "no path from " << inici <<" to " << desti << endl;
        else cout << resultat << endl;
    }
}