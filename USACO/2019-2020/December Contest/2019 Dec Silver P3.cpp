/*
Milk Visits
USACO 2019 December Contest, Silver, Problem 3
http://usaco.org/index.php?page=viewproblem2&cpid=968
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
const int MAXN = 1e5+5, LOG = 17;
int N, M, dis[MAXN], dep[MAXN], anc[MAXN][LOG];
string cows;
vector<int>adj[MAXN];
void dfs(int pre, int cur){
    dep[cur] = dep[pre]+1;
    dis[cur] = dis[pre]+(cows[cur-1]=='H');
    anc[cur][0] = pre;
    for(int i = 1;i<LOG;i++) anc[cur][i] = anc[anc[cur][i-1]][i-1];
    for(int i:adj[cur]){
        if(i==pre) continue;
        dfs(cur, i);
    }
}
int lca(int u, int v){
    if(dep[u]<dep[v]) swap(u, v);
    int diff = dep[u]-dep[v];
    for(int i = 0;i<LOG;i++){
        if(diff&(1<<i)) u = anc[u][i];
    }
    if(u==v) return u;
    for(int i = LOG-1;i>=0;i--){
        if(anc[u][i]!=anc[v][i]){
            u = anc[u][i], v = anc[v][i];
        }
    }
    return anc[u][0];
}
int main(){
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M >> cows;
    for(int i = 0, x, y;i<N-1;i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(0, 1);
    for(int i = 0, a, b;i<M;i++){
        char c; cin >> a >> b >> c;
        if(a==b){
            if(c==cows[a-1]) cout << 1;
            else cout << 0;
            continue;
        }
        int lowca = lca(a, b);
        int tot = dis[a]+dis[b]-2*dis[lowca]+(cows[lowca-1]=='H');
        if(c=='H'){
            if(tot>0) cout << 1;
            else cout << 0;
        }else{
            int len = dep[a]+dep[b]-2*dep[lowca]+1;
            if(len>tot) cout << 1;
            else cout << 0;
        }
    }
    cout << nl;
    return 0;
}