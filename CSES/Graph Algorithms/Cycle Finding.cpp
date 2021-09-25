/*
Cycle Finding
https://cses.fi/problemset/task/1197/
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
int N, M, pa[2505];
ll dis[5005];
struct edge{
    int u, v, d;
};
vector<edge>edges;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 0, a, b, c;i<M;i++){
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    //Bellman-ford
    int x = -1;
    for(int i = 0;i<N;i++){
        x = -1;
        for(edge j:edges){
            if(dis[j.v]>dis[j.u]+j.d){
                dis[j.v] = dis[j.u]+j.d;
                pa[j.v] = j.u;
                x = j.v;
            }
        }
    }
    if(x==-1){
        cout << "NO" << nl;
        return 0;
    }
    for(int i = 0;i<N;i++) x = pa[x];
    vector<int>neg_cycle;
    for(int y = x;;y = pa[y]){
        neg_cycle.push_back(y);
        if(neg_cycle.size()>1&&y==x) break;
    }
    reverse(neg_cycle.begin(), neg_cycle.end());
    cout << "YES" << nl;
    for(int i:neg_cycle) cout << i << sp;
    return 0;
}