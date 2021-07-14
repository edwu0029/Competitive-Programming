//Problem: https://cses.fi/problemset/task/1671/

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
ll dis[MAXN];
vector<pii>adj[MAXN];
struct E{
    int u;
    ll dist;
    friend bool operator<(const E &a, const E &b){
        return a.dist>b.dist;
    }
};
priority_queue<E>pq;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 0, a, b, c;i<M;i++){
        cin >> a >> b >> c;
        adj[a].push_back(mp(b, c));
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    pq.push({1, 0LL});
    while(!pq.empty()){
        E cur = pq.top(); pq.pop();
        int u = cur.u;
        if(dis[u]<cur.dist) continue;
        for(pii i:adj[u]){
            int v = i.first; 
            if(dis[v]>dis[u]+1LL*i.second){
                dis[v] = dis[u]+1LL*i.second;
                pq.push({v, dis[v]});
            }
        }
    }
    for(int i = 1;i<=N;i++){
        cout << dis[i] << sp;
    }
    return 0;
}