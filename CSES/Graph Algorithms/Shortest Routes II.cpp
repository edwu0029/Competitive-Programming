//Problem: https://cses.fi/problemset/task/1672/

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
const int MAXN = 505;
int N, M, Q, adj[MAXN][MAXN];
bool done[MAXN];
ll dis[MAXN][MAXN];
struct E{
    int u;
    ll dist;
    friend bool operator<(const E &a, const E &b){
        return a.dist>b.dist;
    }
};
priority_queue<E>pq;
void dijkstra(int src){
    dis[src][src] = 0;
    pq.push({src, 0LL});
    while(!pq.empty()){
        E cur = pq.top(); pq.pop();
        int u = cur.u;
        if(dis[src][u]<cur.dist) continue;
        for(int v = 1;v<=N;v++){
            if(adj[u][v]==inf) continue;
            if(dis[src][v]>dis[src][u]+1LL*adj[u][v]){
                dis[src][v] = dis[src][u]+1LL*adj[u][v];
                pq.push({v, dis[src][v]});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M >> Q;
    memset(adj, 0x3f, sizeof(adj));
    for(int i = 0, a, b, c;i<M;i++){
        cin >> a >> b >> c;
        adj[a][b] = min(adj[a][b], c);
        adj[b][a] = min(adj[b][a], c);
    }
    memset(dis, 0x3f, sizeof(dis));
    for(int i = 0, a, b;i<Q;i++){
        cin >> a >> b;
        if(!done[a]){
            dijkstra(a);
            done[a] = true;
        }
        if(!done[b]){
            dijkstra(b);
            done[b] = true;
        }
        if(dis[a][b]==infll){
            cout << -1 << nl;
        }else{
            cout << dis[a][b] << nl;
        }
    }
    return 0;
}