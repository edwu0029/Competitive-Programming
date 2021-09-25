/*
Friends
Canadian Computing Competition: 2007 Stage 1, Senior #3
https://dmoj.ca/problem/ccc07s3
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
const int MAXN = 1e4+5;
int N, adj[MAXN];
bool vis[MAXN];
int dfs(int ed, int cur, int dis){
    vis[cur] = true;
    if(cur==ed) return dis;
    else if(vis[adj[cur]]) return -1;
    return dfs(ed, adj[cur], dis+1);
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 0, x, y;i<N;i++){
        cin >> x >> y;
        adj[x] = y;
    }
    while(true){
        int x, y; cin >> x >> y;
        if(x==0&&y==0) break;
        memset(vis, 0, sizeof(vis));
        int d = dfs(y, x, 0);
        if(d==-1) cout << "No" << nl;
        else cout << "Yes" << sp << d-1 << nl;
    }
    return 0;
}