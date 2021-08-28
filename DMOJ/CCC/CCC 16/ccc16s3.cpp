//Problem: https://dmoj.ca/problem/ccc16s3

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
int N, M, tot, dis[MAXN];
bool pho[MAXN];
vector<int>adj[MAXN];
vector<int>adj2[MAXN];
bool dfs(int cur, int pre){
    bool ispho = pho[cur];
    bool childispho = false;
    for(int i:adj[cur]){
        if(i==pre) continue;
        if(dfs(i, cur)){
            childispho = true;
            adj2[i].push_back(cur);
            adj2[cur].push_back(i);
            tot++;
        }
    }
    return ispho||childispho;
}
void dfs2(int cur, int pre){
    for(int i: adj2[cur]){
        if(i==pre) continue;
        dis[i] = dis[cur]+1;
        dfs2(i, cur);
    }
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M;
    int randpho = 0;
    for(int i = 1, x;i<=M;i++){
        cin >> x; pho[x] = true;
        randpho = x;
    }
    for(int i = 1, a, b;i<=N-1;i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(randpho, -1);
    memset(dis, inf, sizeof(dis));
    dis[randpho] = 0;
    dfs2(randpho, -1);
    int mx = 0, idx = 0;
    for(int i = 0;i<N;i++){
        if(dis[i]!=inf&&mx<dis[i]){
            mx = dis[i], idx = i;
        }
    }
    memset(dis, inf, sizeof(dis));
    dis[idx] = 0;
    dfs2(idx, -1);
    mx = 0; idx = 0;
    for(int i = 0;i<N;i++){
        if(dis[i]!=inf&&mx<dis[i]){
            mx = dis[i], idx = i;
        }
    }
    cout << 2*tot-mx << nl;
    return 0;
}