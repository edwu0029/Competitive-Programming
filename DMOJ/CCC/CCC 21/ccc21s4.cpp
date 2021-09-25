/*
Daily Commute
Canadian Computing Competition: 2021 Stage 1, Senior #4
https://dmoj.ca/problem/ccc21s4
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define nl '\n'
#define sp ' '
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define EPS 1e-9
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ll MODll = 4000004479;
const int MAXN = 2e5+5, LOG = 16;
int N, W, D, dis[MAXN], idx[MAXN], subway[MAXN];
vector<int>adj[MAXN];
set<pii>check;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> W >> D;
    for(int i = 1;i<=W;i++){
        int a, b; cin >> a >> b;
        adj[b].push_back(a);
    }
    for(int i = 1;i<=N;i++){
        cin >> subway[i];
        idx[subway[i]] = i;
    }
    queue<int>q;
    memset(dis, 0x3f, sizeof(dis));
    dis[N] = 0; q.push(N);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int i:adj[cur]){
            if(dis[i]>dis[cur]+1){
                dis[i] = dis[cur]+1;
                q.push(i);
            }
        }
    }
    for(int i = 1;i<=N;i++) check.insert(mp(dis[subway[i]]+idx[subway[i]]-1, subway[i]));
    for(int i = 1, a, b;i<=D;i++){
        cin >> a >> b;
        int v1 = subway[a], v2 = subway[b];
        check.erase(mp(dis[v1]+idx[v1]-1, v1));
        check.erase(mp(dis[v2]+idx[v2]-1, v2));
        swap(idx[v1], idx[v2]); swap(subway[a], subway[b]); swap(v1, v2);
        check.insert(mp(dis[v1]+idx[v1]-1, v1));
        check.insert(mp(dis[v2]+idx[v2]-1, v2));
        pii cur = *check.begin();
        cout << cur.first << nl;
    }
    return 0;
}