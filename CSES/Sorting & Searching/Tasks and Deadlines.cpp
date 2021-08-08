//Problem: https://cses.fi/problemset/task/1630

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
int N;
pii a[MAXN];
ll ans;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 0, dur, d;i<N;i++){
        cin >> dur >> d;
        a[i] = mp(dur, d);
    }
    sort(a, a+N);
    ll t = 0;
    for(int i = 0;i<N;i++){
        t+=a[i].first;
        ans+=1LL*a[i].second-t;
    }
    cout << ans << nl;
    return 0;
}