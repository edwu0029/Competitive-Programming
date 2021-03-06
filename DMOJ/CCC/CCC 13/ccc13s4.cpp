/*
Who is Taller?
Canadian Computing Competition: 2013 Stage 1, Senior #4
https://dmoj.ca/problem/ccc13s4
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
const int MAXN = 1e6+5;
int N, M, p, q;
vector<int>F[MAXN];
bool vis[MAXN];
void bfs(int p, int q){
    for(int i = 0;i<MAXN;i++) vis[i]=false;
    queue<int>que;
    que.push(p);
    vis[p]=true;
    while(!que.empty()){
        int cur = que.front(); que.pop();
        for(int i = 0, tmp;i<F[cur].size();i++){
            tmp = F[cur].at(i);
            if(!vis[tmp]){
                vis[tmp]=true;
                que.push(tmp);
            }
        }
    }
}
int main(){
    scanf("%d%d",&N,&M);
    for(int i = 0;i<M;i++){
        int a, b; scanf("%d%d",&a,&b);
        F[a].push_back(b);
    }
    scanf("%d%d",&p,&q);
    bfs(p,q); bool pgq = vis[q];
    bfs(q,p); bool qgp = vis[p];
    if(pgq){
        cout << "yes" << nl;
    }else if(qgp){
        cout << "no" << nl;
    }else{
        cout << "unknown" << nl;
    }
    return 0;
}