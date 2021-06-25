//Problem: https://dmoj.ca/problem/coci14c3p5

#include <bits/stdc++.h>
using namespace std;
#define nl '\n'
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int MAXN = 3e5+2, LOG = 19;
int N, dep[MAXN], anc[LOG][MAXN], node[MAXN];
int lca(int u, int v){
    if(dep[u]<dep[v])swap(u, v);
    int diff = dep[u]-dep[v];
    for(int i = 0;i<LOG;i++){
        if((1<<i)&diff)u = anc[i][u];
    }
    if(u==v) return u;
    for(int i = LOG-1;i>=0;i--){
        if(anc[i][u]!=anc[i][v]){
            u = anc[i][u]; v = anc[i][v];
        }
    }
    return anc[0][u];
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 1, v, w, tmp;i<=N;i++){
        char op;
        cin >> op >> v;
        if(op=='a'){
            tmp = node[v];
            node[i] = i;
            dep[i] = dep[tmp]+1;
            anc[0][i] = node[tmp];
            for(int j = 1;j<LOG;j++){
                anc[j][i] = anc[j-1][anc[j-1][i]];
            }
        }else if(op=='b'){
            tmp = node[v];
            cout << node[tmp] << nl;
            node[i] = anc[0][tmp];
            dep[i] = dep[tmp]-1;
        }else{
            cin >> w;
            node[i] = node[v];
            dep[i] = dep[v];
            cout << dep[lca(node[i], node[w])] << nl;
        }
    }
    return 0;
}