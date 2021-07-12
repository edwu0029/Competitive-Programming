//Problem: https://cses.fi/problemset/result/2465891/

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
int N, F[MAXN];
ll ans;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> F[i];
    }
    int pre = F[0];
    for(int i = 1;i<N;i++){
        if(F[i]<pre){
            ans+=1LL*(pre-F[i]);
            F[i] = pre;
        }
        pre = F[i];
    }
    cout << ans << nl;
    return 0;
}