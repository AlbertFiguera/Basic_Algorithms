#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>  su;
vector<vector<bool>>  r_mkd, c_mkd;
vector<vector<vector<bool>>> s_mkd;

void write() {
  cout << endl;
  for (int i = 0; i < 9; ++i) {
    cout << su[i][0] + 1;
    for (int j = 1; j < 9; ++j)
      cout << ' ' << su[i][j] + 1;
    cout << endl;
  }
}

bool fill(int i, int j) {
  if (i == 9)        return true;
  if (j == 9)        return fill(i+1, 0);
  if (su[i][j] != -1) return fill(i, j+1);
  for (int v = 0; v < 9; ++v)
    if (not r_mkd[i][v] and not c_mkd[j][v] and not s_mkd[i/3][j/3][v]) {
      r_mkd[i][v] = c_mkd[j][v] = s_mkd[i/3][j/3][v] = true;
      su[i][j] = v;
      if (fill(i, j+1)) return true;
      r_mkd[i][v] = c_mkd[j][v] = s_mkd[i/3][j/3][v] = false;
    }
  su[i][j] = -1;  
  return false;
}

int main() {
  su = vector<vector<int>>(9, vector<int>(9));
  int n;
  cin >> n;
  cout << n << endl;
  while (n--) {
    r_mkd = c_mkd = vector<vector<bool>>(9, vector<bool>(9, false));
    s_mkd = vector<vector<vector<bool>>>(3, vector<vector<bool>>(3, vector<bool>(9, false)));
    for (int i = 0; i < 9; ++i)
      for (int j = 0; j < 9; ++j) {
	char c;
	cin >> c;
	if (c == '.') su[i][j] = -1;
	else {
	  int v =  c - '1';
	  r_mkd[i][v] = c_mkd[j][v] = s_mkd[i/3][j/3][v] = true;
	  su[i][j] = v;
	}
      }
    if (fill(0, 0)) write();
  }
}
