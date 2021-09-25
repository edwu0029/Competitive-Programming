/*
High SCcore
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
const ll MODll = 4000004479;
const int MAXN = 2505;
int N, M, vis[MAXN];
ll dis[MAXN];
bool possible_looping = false, possible[MAXN];
vector<int>adj[MAXN];
vector<pii>adj2[MAXN];
void dfs(int u){
    possible[u] = true;
    for(int v:adj[u]){
        if(!possible[v]) dfs(v);
    }
}
void dfs2(int u){
    vis[u]++;
    if(possible_looping) return;
    for(auto i:adj2[u]){
        int v = i.first, d = i.second;
        if(vis[v]&&(dis[u]+d)-dis[v]>0&&possible[v]){
            possible_looping = true;
            return;
        }
        if(!vis[v]&&dis[v]<dis[u]+d){
            dis[v] = dis[u]+d;
            dfs2(v);
        }
    }
    vis[u]--;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 0, a, b, c;i<M;i++){
        cin >> a >> b >> c;
        adj[b].push_back(a);
        adj2[a].push_back({b, c});
    }
    dfs(N);
    memset(dis, 0xc0, sizeof(dis));
    dis[1] = 0;
    dfs2(1);
    if(possible_looping) cout << -1 << nl;
    else cout << dis[N] << nl;
    return 0;
}