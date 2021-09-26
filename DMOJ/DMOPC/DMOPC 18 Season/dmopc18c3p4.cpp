/*
Bob and English Class
DMOPC '18 Contest 3 P4
https://dmoj.ca/problem/dmopc18c3p4
*/

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
const int MAXN = 2e5+5, LOG = 16;
int K, N, sz[MAXN], dis[MAXN], cent;
ll ans;
int student[MAXN];
vector<pii>adj[MAXN];
void calc(int cur, int pre){
    sz[cur] = student[cur];
    for(pii i:adj[cur]){
        if(i.first!=pre){ calc(i.first, cur); sz[cur]+=sz[i.first];}
    }
}
int getcent(int cur, int pre, int total){
    for(pii i:adj[cur]){
        if(i.first!=pre&&2*sz[i.first]>total) return getcent(i.first, cur, total);
    }
    return cur;
}
void dfs(int cur, int pre){
    ans+=(1LL)*dis[cur]*student[cur];
    for(pii i:adj[cur]){
        if(i.first!=pre){dis[i.first] = dis[cur]+i.second; dfs(i.first, cur);}
    }
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> K >> N;
    for(int i = 1, x;i<=K;i++){cin >> x; student[x]++;}
    for(int i = 1, a, b, d;i<=N-1;i++){
        cin >> a >> b >> d;
        adj[a].push_back({b, d});
        adj[b].push_back({a, d});
    }
    calc(1, 0); cent = getcent(1, 0, K);
    dfs(cent, 0);
    cout << ans << '\n';
    return 0;
}