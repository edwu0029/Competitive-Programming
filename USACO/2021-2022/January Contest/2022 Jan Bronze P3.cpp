/*
Drought
USACO 2022 January Contest, Bronze, Problem 3
http://usaco.org/index.php?page=viewproblem2&cpid=1181
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
int N;
void solve(){
    cin >> N;
    vector<int>h(N);
    for(int i = 0;i<N;i++) cin >> h[i];
    if(N==1){
        cout << 0 << nl;
        return;
    }
    ll ans = 0;
    for(int i  = 1;i<N-1;i++){
        if(h[i]>h[i-1]){
            ll diff = h[i]-h[i-1];
            ans+=2*diff;
            h[i+1]-=diff;
            h[i]-=diff;
        }
    }
    if(h[N-1]>h[N-2]){
        cout << -1 << nl;
        return;
    }
    for(int i = N-2;i>0;i--){
        if(h[i]>h[i+1]){
            ll diff = h[i]-h[i+1];
            ans+=2*diff;
            h[i-1]-=diff;
            h[i]-=diff;
        }
    }
    for(int i = 1;i<N;i++){
        if(h[i]!=h[i-1]||h[i]<0){
            cout << -1 << nl;
            return;
        }
    }
    cout << ans << nl;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while(T--){
        solve();
    }
    return 0;
}