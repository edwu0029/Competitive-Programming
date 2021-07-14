//Problem: https://cses.fi/problemset/task/1667/

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
int N, M, dis[MAXN], pre[MAXN];
vector<int>adj[MAXN];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 1, a, b;i<=M;i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    queue<int>q;
    q.push(1);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        if(cur==N) break;
        for(int i:adj[cur]){
            if(dis[i]>dis[cur]+1){
                dis[i] = dis[cur]+1;
                q.push(i);
                pre[i] = cur;
            }
        }
    }
    if(dis[N]==inf){
        cout << "IMPOSSIBLE" << nl;
        return 0;
    }
    cout << dis[N]+1 << nl;
    int p = N;
    vector<int>ans;
    while(true){
        ans.push_back(p);
        if(p==1) break;
        p = pre[p];
    }
    reverse(ans.begin(), ans.end());
    for(int i:ans){
        cout << i << sp;
    }
    return 0;
}