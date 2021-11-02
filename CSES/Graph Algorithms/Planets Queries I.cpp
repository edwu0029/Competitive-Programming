/*
Planets Queries I
https://cses.fi/problemset/task/1750/
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
const int MAXN = 2e5+5, LOG = 30;
int N, Q, nxt[MAXN][LOG];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> Q;
    for(int i = 1;i<=N;i++) cin >> nxt[i][0];
    for(int i = 1;i<LOG;i++){
        for(int j = 1;j<=N;j++){
            nxt[j][i] = nxt[nxt[j][i-1]][i-1];
        }
    }
    for(int i = 0, x, k;i<Q;i++){
        cin >> x >> k;
        for(int j = 0;j<LOG;j++){
            if((1<<j)&k) x = nxt[x][j];
        }
        cout << x << nl;
    }
    return 0;
}