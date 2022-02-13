/*
Connecting Two Barns
USACO 2021 December Contest, Silver, Problem 2
http://usaco.org/index.php?page=viewproblem2&cpid=1159
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
int N, M, g[MAXN], cnt;
ll dis1[MAXN], disN[MAXN];
bool vis[MAXN];
vector<int>adj[MAXN], groups[MAXN];
void dfs(int prev, int src){
    if(prev!=-1) g[src] = g[prev];
    groups[g[src]].push_back(src);
    vis[src] = true;
    for(int i:adj[src]){
        if(i==prev||vis[i]) continue;
        dfs(src, i);
    }
}
void solve(){
    cin >> N >> M;
    for(int i = 0;i<MAXN;i++){ //Reset
        adj[i].clear();
        groups[i].clear();
    }
    for(int i = 0, a, b;i<M;i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cnt = 0;
    memset(vis, 0, sizeof(vis));
    for(int i = 1;i<=N;i++){
        if(!vis[i]){
            g[i] = ++cnt;
            dfs(-1, i);
            sort(groups[g[i]].begin(), groups[g[i]].end());
        }
    }
    memset(dis1, 0x3f, sizeof(dis1));
    memset(disN, 0x3f, sizeof(disN));
    int g1 = g[1], gN = g[N];
    for(int i = 1;i<=N;i++){
        //Starting from 1
        ll diff = infll;
        auto pos = lower_bound(groups[g1].begin(), groups[g1].end(), i);
        if(pos!=groups[g1].end()){
            diff = min(diff, 1LL*abs(i-*pos));
        }
        if((--pos)>=groups[g1].begin()){
            diff = min(diff, 1LL*abs(i-*pos));
        }
        dis1[g[i]] = min(dis1[g[i]], diff*diff);
        //Starting from N
        diff = infll;
        pos = lower_bound(groups[gN].begin(), groups[gN].end(), i);
        if(pos!=groups[gN].end()){
            diff = min(diff, 1LL*abs(i-*pos));
        }
        if((--pos)>=groups[gN].begin()){
            diff = min(diff, 1LL*abs(i-*pos));
        }
        disN[g[i]] = min(disN[g[i]], diff*diff);
    }
    ll ans = infll;
    for(int i = 1;i<=cnt;i++){
        ans = min(ans, dis1[i]+disN[i]);
    }
    cout << ans << nl;
    return;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while(T--){
        solve();
    }
    return 0;
}