//Problem: https://dmoj.ca/problem/ccc09s4

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
const int MAXN = 5e3+5;
int N, T, K, D, p[MAXN], dis[MAXN];
bool can_buy[MAXN];
vector<pii>adj[MAXN];
int main(){
    scanf("%d%d", &N, &T);
    for(int i = 0, u, v, c;i<T;i++){
        scanf("%d%d%d", &u, &v, &c);
        adj[u].push_back(mp(v, c));
        adj[v].push_back(mp(u, c));
    }
    scanf("%d", &K);
    for(int i = 0, x, v;i<K;i++){
        scanf("%d%d", &x, &v);
        p[x] = v;
        can_buy[x] = true;
    }
    scanf("%d", &D);
    memset(dis, 0x3f, sizeof(dis));
    priority_queue<pii, vector<pii>, greater<pii>>pq;
    pq.push(mp(0, D));
    dis[D] = 0;
    while(!pq.empty()){
        pii cur = pq.top();
        pq.pop();
        int u = cur.second, d = cur.first;
        if(dis[u]<d) continue;
        for(auto i:adj[u]){
            int v = i.first, C = i.second;
            if(dis[v]>dis[u]+C){
                dis[v] = dis[u]+C;
                pq.push(mp(dis[v], v));
            }
        }
    }
    int ans = inf;
    for(int i = 1;i<=N;i++){
        if(can_buy[i]){
            ans = min(ans, dis[i]+p[i]);
        }
    }
    printf("%d\n", ans);
    return 0;
}