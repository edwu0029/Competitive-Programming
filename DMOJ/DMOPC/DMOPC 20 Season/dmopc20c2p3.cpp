/*
Roadrollification
DMOPC '20 Contest 2 P3
https://dmoj.ca/problem/dmopc20c2p3
*/

#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <complex>
#include <iomanip>
#include <cassert>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define nl '\n'
#define sp ' '
#define f first
#define s second
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define EPS 1e-9
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ll MODll = 4000004479;
const int MAXN = 2e5+5;
int N, F[MAXN];
ll cnt, ans, inv[MAXN], outv[MAXN];
vector<int>adj[MAXN];
priority_queue<pii>pq;
bool vis[MAXN];
vector<int>ord;
void topsort(int v){
    vis[v] = true;
    for(int i:adj[v]){
        if(!vis[i]) topsort(i);
    }
    ord.pb(v);
}
void dfs(int v){
    vis[v] = true;
    for(int i:adj[v]){
        if(!vis[i]){
            dfs(i);
        }
        outv[v]+=outv[i];
    }
    cnt+=(1LL)*F[v]*outv[v];
    outv[v]+=F[v];
    cnt+=(1LL)*F[v]*(F[v]-1);
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 1;i<=N;i++) cin >> F[i];
    for(int i = 1, a, b;i<=N-1;i++){
        cin >> a >> b;
        adj[a].pb(b);
    }
    for(int i = 1;i<=N;i++){
        if(!vis[i]) topsort(i);
    }
    reverse(ord.begin(), ord.end());
    memset(vis, false, sizeof(vis));
    for(int i:ord){
        if(!vis[i]) dfs(i);
    }
    for(int i:ord){
        inv[i]+=F[i];
        for(int j:adj[i]){
            inv[j]+=inv[i];
        }
    }
    for(int i = 1;i<=N;i++){
        for(int j:adj[i]){
            ll t = (inv[j]-inv[i])*(outv[i]-outv[j]);
            ans = max(ans, t);
        }
    }
    cout << cnt+ans << nl;
    return 0;
}