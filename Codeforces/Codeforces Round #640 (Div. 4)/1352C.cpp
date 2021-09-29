/*
K-th Not Divisible by n
Codeforces Round #640 (Div. 4), Problem C
https://codeforces.com/contest/1352/problem/C
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
void solve(){
    int N, K; cin >> N >> K;
    int cycles = K/(N-1), rem = K%(N-1);
    ll ans = 1LL*cycles*N+rem;
    if(rem==0){
        ans--;
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