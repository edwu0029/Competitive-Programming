/*
Polycarp and Coins
Codeforces Round #734 (Div. 3), Problem A
https://codeforces.com/contest/1551/problem/A
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
    int N; cin >> N;
    int c1, c2;
    c1 = c2 = N/3;
    if(N%3==1) c1++;
    else if(N%3==2) c2++;
    cout << c1 << sp << c2 << nl;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while(T--){
        solve();
    }
    return 0;
}