//Problem: https://cses.fi/problemset/task/1678/

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
int N, M, vis[MAXN];
vector<int>adj[MAXN], cycle;
stack<int>stk;
bool dfs(int u){
    vis[u] = 1;
    stk.push(u);
    for(int v:adj[u]){
        if(vis[v]==0){
            if(dfs(v)) return true;
        }else if(vis[v]==1){
            cycle.push_back(v);
            while(stk.size()>0&&stk.top()!=v){
                cycle.push_back(stk.top());
                stk.pop();
            }
            cycle.push_back(v);
            return true;
        }
    }
    vis[u] = 2;
    stk.pop();
    return false;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 0, a, b;i<M;i++){
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for(int i = 1;i<=N;i++){
        if(vis[i]==0&&dfs(i)) break;
    }
    if(cycle.size()==0){
        cout << "IMPOSSIBLE" << nl;
    }else{
        reverse(cycle.begin(), cycle.end());
        cout << cycle.size() << nl;
        for(int i:cycle) cout << i << sp;
    }
    return 0;
}