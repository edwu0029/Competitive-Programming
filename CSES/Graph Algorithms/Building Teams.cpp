/*
Building Teams
https://cses.fi/problemset/task/1668/
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
int N, M, team[MAXN];
bool vis[MAXN], possible = true;
vector<int>adj[MAXN];
int nxt_team(int t){
    return t==1?2:1;
}
void dfs(int pre, int cur){
    vis[cur] = true;
    for(int i:adj[cur]){
        if(i==pre) continue;
        if(vis[i]){
            if(team[i]==team[cur]) possible = false;
        }else{
            team[i] = nxt_team(team[cur]);
            dfs(cur, i);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 0, a, b;i<M;i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1;i<=N;i++){
        if(!vis[i]){
            team[i] = 1;
            dfs(-1, i);
        }
    }
    if(possible){
        for(int i = 1;i<=N;i++){
            cout << team[i] << sp;
        }
    }else{
        cout << "IMPOSSIBLE" << nl;
    }
    return 0;
}