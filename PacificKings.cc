#include<iostream>
#include<vector>
using namespace std;


typedef vector<int> VE;
typedef vector<VE>
VVE;


int n;
VVE V;


bool lliure(int x, int
y) {
  if (y > 0
and V[x][y-1]) return false;
  if (x == 0) return true;
  for (int j =
-1; j <=
1; ++j)
{
      int y2 = y +
j;
      if (y2 >= 0 and y2 < n and V[x-1][y2]) return false;
    }
  return true;
}


void reis(int x, int
y, int r)
{
  if (x == n) {
    if (r) return;

    for (int i = 0;
i < n; ++i)
{
      for (int j = 0;
j < n; ++j)
cout << (V[i][j]
? 'K' : '.');
      cout << endl;
    }
    cout << "----------" << endl;
    return;
  }

  if (y == n) return
reis(x + 1, 0, r);

  if (r and lliure(x, y)) {
    V[x][y] =
true;
    reis(x, y
+ 1, r -
1);
    V[x][y] =
false;
  }

  reis(x, y
+ 1, r);
}


int main() {
  int r;
  cin >> n >> r;
  V = VVE(n, VE(n, false));
  reis(0, 0, r);
}