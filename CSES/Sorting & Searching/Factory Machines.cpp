/*
Factory Machines
https://cses.fi/problemset/task/1620
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
const int MAXN = 2e5+5;
int N, t, k[MAXN];
ll ans;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> t;
    for(int i = 0;i<N;i++) cin >> k[i];
    ll lo = 0, hi = 1e18;
    while(lo<=hi){
        ll mid = (lo+hi)/2, cnt = 0;
        for(int i = 0;i<N;i++){
            cnt+=mid/(1LL*k[i]);
            if(cnt>=t) break;
        }
        if(cnt>=t){
            ans = mid;
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    cout << ans << nl;
    return 0;
}