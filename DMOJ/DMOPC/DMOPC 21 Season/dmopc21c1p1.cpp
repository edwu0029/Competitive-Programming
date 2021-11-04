/*
Scrambling Swaps
DMOPC '21 Contest 2 P2
https://dmoj.ca/problem/dmopc21c2p2
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
const int MAXN = 305;
int N, Q, val[MAXN], pos[MAXN];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> Q;
    for(int i = 1;i<=N;i++) val[i] = i, pos[i] = i;
    //To get target P, do swaps in opposite order
    for(int i = 0, x, y;i<Q;i++){
        char op; cin >> op;
        if(op=='B'){
            cin >> x >> y;
            int a = val[x], b = val[y];
            swap(val[x], val[y]);
            swap(pos[a], pos[b]);
        }else if(op=='E'){
            cin >> x >> y;
            int a = pos[x], b = pos[y];
            swap(val[a], val[b]);
            swap(pos[x], pos[y]);
        }else{
            vector<int>ans(N+1);
            for(int i = 1;i<=N;i++) cin >> ans[i];
            for(int i = 1;i<=N;i++){
                cout << ans[val[i]];
                if(i!=N) cout << sp;
            }
            cout << nl;
        }
    }
    return 0;
}