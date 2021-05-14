//Problem: https://dmoj.ca/problem/cco07p6

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
const int MAXN = 1002, LOG = 16;
int N, R, cnt, tp = -1, bcc, dfn[MAXN], low[MAXN], stk[MAXN], bccs[MAXN], ans;
bool instk[MAXN], vis[MAXN];
vector<int>adj[MAXN], adj2[MAXN];
void dfs(int cur, int pa){
    dfn[cur] = low[cur] = ++cnt;
    stk[++tp] = cur;
    instk[cur] = true;
    for(int i:adj[cur]){
        if(i==pa) continue;
        if(!dfn[i]){
            dfs(i, cur);
            low[cur] = min(low[cur], low[i]);
        }else if(instk[i]){
            low[cur] = min(low[cur], dfn[i]);
        }
    }
    if(dfn[cur]==low[cur]){
        bcc++;
        int x = 0;
        do{
            x = stk[tp--];
            instk[x] = false;
            bccs[x] = bcc;
        }while(x!=cur);
    }
}
void dfs2(int cur, int pa){
    vis[cur] = true;
    for(int i:adj[cur]){
    if(i==pa||vis[i]) continue;
        if(bccs[cur]!=bccs[i]){
            adj2[bccs[cur]].push_back(bccs[i]);
            adj2[bccs[i]].push_back(bccs[cur]);
        }
        dfs2(i, cur);
    }
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> R;
    for(int i = 1, v, w;i<=R;i++){
        cin >> v >> w;
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
    dfs(1, -1);
    dfs2(1, -1);
    for(int i = 1;i<=bcc;i++){
        int x = adj2[i].size();
        if(x==1) ans++;
    }
    if(ans==0){
        cout << 0 << nl;
        return 0;
    }
    if(ans%2) ans = (ans+1)/2;
    else ans/=2;
    cout << ans << nl;
    return 0;
}