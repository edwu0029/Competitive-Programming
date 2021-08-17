//Problem: http://usaco.org/index.php?page=viewproblem2&cpid=1086

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
int N, K, F[MAXN], g[MAXN], g_cnt;
bool vis[MAXN];
vector<int>adj[MAXN];
set<int>pos[MAXN], g_pos[MAXN];
void dfs(int cur, int g_num){
    vis[cur] = true;
    g[cur] = g_num;
    g_pos[g_num].insert(pos[cur].begin(), pos[cur].end());
    for(int i:adj[cur]){
        if(vis[i]) continue;
        dfs(i, g_num);
    }
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> K;
    for(int i = 1;i<=N;i++){
        F[i] = i;
        pos[i].insert(i);
    }
    for(int i = 0, a, b;i<K;i++){
        cin >> a >> b;
        int cura = F[a], curb = F[b];
        pos[cura].insert(b);
        pos[curb].insert(a);
        swap(F[a], F[b]);
    }
    for(int i = 1;i<=N;i++){
        adj[F[i]].push_back(i);
        adj[i].push_back(F[i]);
    }
    for(int i = 1;i<=N;i++){
        if(!vis[i]) dfs(i, ++g_cnt);
    }
    for(int i = 1;i<=N;i++){
        cout << g_pos[g[i]].size() << nl;
    }
    return 0;
}