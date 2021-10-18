/*
Round Trip
https://cses.fi/problemset/task/1669/
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
int N, M;
vector<int>adj[MAXN], ans;
bool vis[MAXN];
stack<int>s;
bool dfs(int pre, int cur){
    vis[cur] = true;
    s.push(cur);
    for(int i:adj[cur]){
        if(i==pre) continue;
        if(vis[i]){
            ans.push_back(i);
            while(s.size()>=1&&s.top()!=i){
                ans.push_back(s.top());
                s.pop();
            }
            ans.push_back(i);
            return true;
        }
        if(dfs(cur, i)){
            return true;
        }
    }
    s.pop();
    return false;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 1, a, b;i<=M;i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool possible = false;
    for(int i = 1;i<=N;i++){
        if(!vis[i]){
            if(dfs(-1, i)){
                possible = true;
                break;
            }
        }
    }
    if(possible){
        cout << ans.size() << nl;
        for(int i:ans){
            cout << i << sp;
        }
        cout << nl;
    }else{
        cout << "IMPOSSIBLE" << nl;
    }
    return 0;
}