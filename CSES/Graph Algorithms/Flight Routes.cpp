/*
Flight Routes
https://cses.fi/problemset/task/1196/
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
int N, M, K;
vector<pii>adj[MAXN];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M >> K;
    for(int i = 0, a, b, c;i<M;i++){
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    vector<vector<ll>>dis(MAXN, vector<ll>(K, infll));
    dis[1][0] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>pq;
    pq.push({0, 1});
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        ll ud = cur.first;
        int u = cur.second;
        auto p = lower_bound(dis[u].begin(), dis[u].end(), ud);
        if(p==dis[u].end()||(*p)!=cur.first) continue;
        for(pii i:adj[u]){
            int v = i.first, d = i.second;
            for(int j = K-1;j>=0;j--){
                if(dis[v][j]>ud+d){
                    dis[v][j] = ud+d;
                    pq.push({ud+d, v});
                    break;
                }
            }
            sort(dis[v].begin(), dis[v].end());
        }
    }
    for(int i = 0;i<K;i++) cout << dis[N][i] << sp;
    return 0;
}