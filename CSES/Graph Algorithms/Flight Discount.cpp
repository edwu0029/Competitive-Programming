//Problem: https://cses.fi/problemset/task/1195/

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
ll dis[MAXN][2];
vector<pii>adj[MAXN];
struct Node{
    ll d;
    int v, used;
    friend bool operator<(const Node &a, const Node &b){
        return a.d>b.d;
    }
};
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 0, a, b, c;i<M;i++){
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[1][1] = dis[1][0] = 0;
    priority_queue<Node>pq;
    pq.push({0, 1, 1});
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        int u = cur.v, used = cur.used;
        for(pii i:adj[u]){
            int v = i.first, d = i.second;
            if(used&&dis[v][0]>dis[u][1]+d/2){
                dis[v][0] = dis[u][1]+d/2;
                pq.push({dis[v][0], v, 0});
            }
            if(dis[v][used]>dis[u][used]+d){
                dis[v][used] = dis[u][used]+d;
                pq.push({dis[v][used], v, used});
            }
        }
    }
    cout << min(dis[N][0], dis[N][1]) << nl;
    return 0;
}