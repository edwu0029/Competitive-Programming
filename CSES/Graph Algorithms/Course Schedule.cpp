//Problem: https://cses.fi/problemset/task/1679

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
bool done[MAXN], cycles;
vector<int>adj[MAXN], ord;
bool find_cycle(int u){
    vis[u] = 1;
    for(int i:adj[u]){
        if(vis[i]==0){
            if(find_cycle(i)) return true;
        }else if(vis[i]==1){
            return true;
        }
    }
    vis[u] = 2;
    return false;
}
void top_sort(int u){
    done[u] = true;
    for(int i:adj[u]){
        if(!done[i]) top_sort(i);
    }
    ord.push_back(u);
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 0, a, b;i<M;i++){
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for(int i = 1;i<=N;i++){
        if(find_cycle(i)){
            cycles = true;
            break;
        }
    }
    if(cycles){
        cout << "IMPOSSIBLE" << nl;
        return 0;
    }
    for(int i = 1;i<=N;i++){
        if(!done[i]) top_sort(i);
    }
    reverse(ord.begin(), ord.end());
    for(int i:ord) cout << i << sp;
    return 0;
}