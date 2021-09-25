/*
Cowntagion
USACO 2020 December Contest, Silver, Problem 1
http://usaco.org/index.php?page=viewproblem2&cpid=1062
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
int N, ans;
vector<int>adj[MAXN];
void dfs(int pre, int cur){
    int cnt = 0;
    for(int i:adj[cur]){
        if(i==pre) continue;
        cnt++;
    }
    //Doubling for enough cows to spread to all children
    for(int i = 1;i<cnt+1;i*=2) ans++;
    //Days for one cow to go to each child
    ans+=cnt;
    for(int i:adj[cur]){
        if(i==pre) continue;
        dfs(cur, i);
    }
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 0, a, b;i<N-1;i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(-1, 1);
    cout << ans << nl;
    return 0;
}