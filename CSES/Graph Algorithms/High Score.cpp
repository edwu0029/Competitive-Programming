/*
High Score
https://cses.fi/problemset/task/1673
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
const int MAXN = 2505;
int N, M, vis[MAXN], visr[MAXN];
ll dis[MAXN];
vector<array<int, 3>>edges;
vector<int>adj[MAXN], adjr[MAXN];
void dfs(int u){
    vis[u] = true;
    for(int v:adj[u]){
        if(vis[v]) continue;
        dfs(v);
    }
}
void dfsr(int u){
    visr[u] = true;
    for(int v:adjr[u]){
        if(visr[v]) continue;
        dfsr(v);
    }
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 0, a, b, c;i<M;i++){
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
        adj[a].push_back(b);
        adjr[b].push_back(a);
    }
    dfs(1);
    dfsr(N);
    memset(dis, 0xc0, sizeof(dis));
    dis[1] = 0;
    bool infans = false;
    for(int i = 0;i<N;i++){
        for(auto [u, v, d]:edges){
            if(dis[v]<dis[u]+d){
                dis[v] = dis[u]+d;
                if(i==N-1&&vis[v]&&visr[v]) infans = true; 
            }
        }
    }
    if(infans) cout << -1 << nl;
    else cout << dis[N] << nl;
    return 0;
}