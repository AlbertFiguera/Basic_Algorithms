#include<vector>
#include<queue>
#include<iostream>
using namespace std;

typedef vector<char> Fila;
typedef vector<Fila> Matriu;

typedef vector<bool> Filab;
typedef vector<Filab> Matriub;

struct Pos{
    int i;
    int j;    
};

void Omplir_matriu(Matriu& m, Matriub& visitades, int& xo, int& yo){
    for(int i = 0; i < m.size(); ++i){
        for(int j = 0; j < m[0].size(); ++j){
            cin >> m[i][j];
            if(m[i][j] == 'P'){
                xo = i;
                yo = j;
            }
            else if(m[i][j] == 'X') visitades[i][j] = true;
            else if(m[i][j] == 'F'){
                visitades[i+1][j-1] = true;
                visitades[i+1][j] = true;
                visitades[i+1][j+1] = true;
                visitades[i][j+1] = true;
                visitades[i][j-1] = true;
                visitades[i-1][j+1] = true;
                visitades[i-1][j] = true;
                visitades[i-1][j-1] = true;
            }
            
        }
    }
}

bool trobat_bolet(const Matriu& m, int i, int j){
    if(m[i][j] == 'B') return true;
    return false;
}

void pushqueue(queue<Pos>& pendents, int i, int j){
    Pos aux;
    aux.i = i;
    aux.j = j;
    pendents.push(aux);
}

bool bfs_pacman(const Matriu& m, Matriub& visitats, int xo, int yo){
    queue<Pos> pendents;
    Pos aux;
    aux.i = xo;
    aux.j = yo;
    pendents.push(aux);
    while(!pendents.empty()){
        aux = pendents.front();
        pendents.pop();
        if(not visitats[aux.i][aux.j]){
            visitats[aux.i][aux.j] = true;
            if(trobat_bolet(m, aux.i, aux.j)) return true;
            else{
                pushqueue(pendents, aux.i + 1, aux.j);
                pushqueue(pendents, aux.i, aux.j + 1);
                pushqueue(pendents, aux.i - 1, aux.j);
                pushqueue(pendents, aux.i, aux.j - 1);
            }
        }
    }return false;
}

int main(){
    int x;
    while(cin >> x){
        int y;
        cin >> y;
        Matriu mapa(x, Fila(y));
        Matriub visitats(x, Filab(y, false));
        int xo, yo;
        xo = 0; yo = 0;
        Omplir_matriu(mapa, visitats, xo, yo);
        if(bfs_pacman(mapa, visitats, xo, yo)) cout <<"si" << endl;
        else cout << "no" << endl;
    }

}