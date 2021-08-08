//Problem: https://cses.fi/problemset/task/1680/

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
int N, M, dp[MAXN], pa[MAXN];
bool vis[MAXN];
vector<int>adj[MAXN];
void dfs(int u){
    vis[u] = true;
    if(u==N) dp[u] = 1;
    for(int v:adj[u]){
        if(!vis[v]){
            pa[v] = u;
            dfs(v);
        }
        if(dp[v]+1>dp[u]){
            pa[u] = v;
            dp[u] = dp[v]+1;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 0, a, b;i<M;i++){
        cin >> a >> b;
        adj[a].push_back(b);
    }
    memset(dp, 0xc0, sizeof(dp));
    dfs(1);
    if(dp[1]<=0){
        cout << "IMPOSSIBLE" << nl;
    }else{
        cout << dp[1] << nl;
        vector<int>path;
        for(int x = 1;;x = pa[x]){
            path.push_back(x);
            if(x==N&&path.size()>1){
                break;
            }
        }
        for(int i:path) cout << i << sp;
    }
    return 0;
}