//Problem: https://cses.fi/problemset/task/2217/

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
const int MAXN = 2e5+5;
int N, M, x[MAXN], idx[MAXN], cnt;
bool in_seq[MAXN];
void ch(int v){
    if(!in_seq[v]) cnt--;
    in_seq[v] = false;
    if(idx[v]<idx[v-1]) cnt++;
    else in_seq[v] = true;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 1;i<=N;i++){
        cin >> x[i];
        idx[x[i]] = i;
    }
    idx[0] = inf;
    for(int i = 1;i<=N;i++){
        if(idx[i]<idx[i-1]) cnt++;
        else in_seq[i] = true;
    }
    for(int i = 0, a, b;i<M;i++){
        cin >> a >> b;
        int c = min(x[a], x[b]), d = max(x[a], x[b]);
        swap(x[a], x[b]);
        swap(idx[c], idx[d]);
        ch(c);
        ch(c+1);
        ch(d);
        if(d+1<=N) ch(d+1);
        cout << cnt << nl;
    }
    return 0;
}