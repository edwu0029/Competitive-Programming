//Problem: https://dmoj.ca/problem/ccc15s4

#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <complex>
#include <iomanip>
#include <cassert>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define nl '\n'
#define sp ' '
#define f first
#define s second
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define EPS 1e-9
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ll MODll = 4000004479;
const int MAXN = 1e6+5, LOG = 16;
struct route{
    int v, t, h;
    friend bool operator<(const route &a, const route &b){
        return a.t>b.t;
    }
};
int K, N, M, A, B, dis[201][2001], ans = inf;
vector<route>adj[2001];
priority_queue<route>pq;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> K >> N >> M;
    for(int i = 0, a, b, t, h;i<M;i++){
        cin >> a >> b >> t >> h;
        adj[a].push_back({b, t, h});
        adj[b].push_back({a, t, h});
    }
    cin >> A >> B;
    memset(dis, 0x3f, sizeof(dis));
    pq.push({A, 0, 0});
    dis[0][A]=0;
    while(!pq.empty()){
        int v = pq.top().v, t = pq.top().t, h = pq.top().h;
        if(v==B) break;
        pq.pop();
        for(auto i: adj[v]) {
            if(i.h+h<K&&dis[h][v]+i.t<dis[i.h+h][i.v]) {
                dis[i.h+h][i.v] = dis[h][v]+i.t;
                pq.push({i.v, dis[i.h+h][i.v], i.h+h});
            }
        }
    }
    for(int i = 0;i<=K;i++) ans = min(dis[i][B], ans);
    if(ans==inf) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}