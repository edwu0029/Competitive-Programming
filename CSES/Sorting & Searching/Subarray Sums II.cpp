/*
Subarray Sums II
https://cses.fi/problemset/task/1661
*/

//Same code as Subarray Sums I
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
ll x, ans;
map<ll, int>m;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> x;
    ll sum = 0;
    m[0]++;
    for(int i = 0, a;i<N;i++){
        cin >> a;
        sum+=a;
        ans+=m[sum-x];
        m[sum]++;
    }
    cout << ans << nl;
    return 0;
}