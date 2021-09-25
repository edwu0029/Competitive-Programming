/*
Game Routes
https://cses.fi/problemset/task/1681/
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
const int MAXN = 1e5+5;
int N, M, dp[MAXN];
bool vis[MAXN];
vector<int>adj[MAXN], ord;
void top_sort(int u){
    vis[u] = true;
    for(int v:adj[u]){
        if(!vis[v]) top_sort(v);
    }
    ord.push_back(u);
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 0, a, b;i<M;i++){
        cin >> a >> b;
        adj[a].push_back(b);
    }
    top_sort(1);
    reverse(ord.begin(), ord.end());
    dp[1] = 1;
    for(int i:ord){
        for(int j:adj[i]){
            dp[j] = (dp[j]+dp[i])%MOD;
        }
    }
    cout << dp[N] << nl;
    return 0;
}