/*
Modern Art
Canadian Computing Competition: 2021 Stage 1, Junior #5, Senior #2
https://dmoj.ca/problem/ccc21s2
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
const int MAXN = 1e6+5, LOG = 16;
int M, N, K;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> M >> N >> K;
    vector<vector<int>>F(M+1, vector<int>(N+1));
    for(int i = 1;i<=K;i++){
        char op; int x; cin >> op >> x;
        if(op=='R') F[x][0]++;
        else if(op=='C') F[0][x]++;
    }
    int ans = 0;
    for(int i = 1;i<=M;i++){
        for(int j = 1;j<=N;j++){
            F[i][j]+=F[i-1][j]+F[i][j-1]-F[i-1][j-1];
            if(F[i][j]%2==1) ans++;
        }
    }
    cout << ans << nl;
    return 0;
}