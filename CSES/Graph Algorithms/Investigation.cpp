/*
Investigation
https://cses.fi/problemset/task/1202
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
const int MAXN = 1e5+5;
int N, M, minflights[MAXN], maxflights[MAXN];
vector<pii>adj[MAXN];
ll dis[MAXN], cnt[MAXN];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 0, a, b, c;i<M;i++){
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    memset(dis, 0x3f, sizeof(dis));
    memset(minflights, 0x3f, sizeof(minflights));
    dis[1] = minflights[1] = 0;
    cnt[1] = 1;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>pq;
    pq.push({0, 1});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        int u = cur.second;
        if(cur.first>dis[u]) continue;
        for(auto [v, d]:adj[u]){
            if(dis[v]>dis[u]+d){
                dis[v] = dis[u]+d;
                cnt[v] = cnt[u];
                minflights[v] = minflights[u]+1;
                maxflights[v] = maxflights[u]+1;
                pq.push({dis[v], v});
            }else if(dis[v]==dis[u]+d){
                cnt[v] = (cnt[v]+cnt[u])%MOD;
                minflights[v] = min(minflights[v], minflights[u]+1);
                maxflights[v] = max(maxflights[v], maxflights[u]+1);
            }
        }
    }
    cout << dis[N] << sp << cnt[N] << sp << minflights[N] << sp << maxflights[N] << nl;
    return 0;
}