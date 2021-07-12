//Problem: https://cses.fi/problemset/task/1666/

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
int N, M;
vector<int>adj[MAXN];
bool vis[MAXN];
void dfs(int pre, int cur){
    vis[cur] = true;
    for(int i:adj[cur]){
        if(i==pre||vis[i]) continue;
        dfs(cur, i);
    }
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 1, a, b;i<=M;i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int>groups;
    for(int i = 1;i<=N;i++){
        if(!vis[i]){
            groups.push_back(i);
            dfs(-1, i);
        }
    }
    cout << groups.size()-1 << nl;
    for(int i = 1;i<groups.size();i++){
        cout << groups[i-1] << sp << groups[i] << nl;
    }
    return 0;
}