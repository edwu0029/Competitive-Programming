/*
Red and Blue Tree
AtCoder Beginner Contest 222, Problem E
https://atcoder.jp/contests/abc222/tasks/abc222_e
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
const ll MODll = 998244353;
const int MAXN = 1005;
int N, M, K, A[MAXN], edge_cnt[MAXN];
bool vis[MAXN];
vector<pii>adj[MAXN];
bool dfs(int u, int ed){
    if(u==ed) return true;
    vis[u] = true;
    for(pii i:adj[u]){
        int v = i.first, idx = i.second;
        if(vis[v]) continue;
        edge_cnt[idx]++;
        if(dfs(v, ed)) return true;
        edge_cnt[idx]--;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M >> K;
    for(int i = 0;i<M;i++) cin >> A[i];
    for(int i = 0, a, b;i<N-1;i++){
        cin >> a >> b;
        adj[a].push_back(mp(b, i));
        adj[b].push_back(mp(a, i));
    }
    for(int i = 1;i<M;i++){
        memset(vis, 0, sizeof(vis));
        dfs(A[i-1], A[i]);
    }
    int sum  = 0;
    for(int i = 0;i<N-1;i++) sum+=edge_cnt[i];
    if((sum+K)%2!=0||sum+K<0){
        cout << 0 << nl;
        return 0;
    }
    vector<ll>dp(100005);
    dp[0] = 1;
    for(int i = 0;i<N-1;i++){
        for(int j = 100000;j>=edge_cnt[i];j--){
            dp[j] = (dp[j]+dp[j-edge_cnt[i]])%MODll;
        }
    }
    cout << dp[(sum+K)/2] << nl;
    return 0;
}