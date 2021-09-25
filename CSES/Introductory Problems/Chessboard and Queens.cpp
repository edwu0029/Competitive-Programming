/*
Chessboard and Queens
https://cses.fi/problemset/task/1624/
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define nl '\n'
#define sp ' '
#define mp(a, b) make_pair(a, b)
#define EPS 1e-9
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ll MODll = 4000004479;
int ans;
char m[10][10];
bool col[10], diag1[10], diag2[10];
void rec(int r){
    if(r==8){
        ans++;
        return;
    }
    for(int i = 0;i<8;i++){
        if(m[r][i]!='*'&&!col[i]&&!diag1[r+i]&&!diag2[r-i+7]){
            col[i] = diag1[r+i] = diag2[r-i+7] = true;
            rec(r+1);
            col[i] = diag1[r+i] = diag2[r-i+7] = false;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    for(int i = 0;i<8;i++){
        string s; cin >> s;
        for(int j = 0;j<8;j++){
            m[i][j] = s[j];
        }
    }
    rec(0);
    cout << ans << nl;
    return 0;
}