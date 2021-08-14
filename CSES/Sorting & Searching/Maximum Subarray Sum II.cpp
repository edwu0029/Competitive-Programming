//Problem: https://cses.fi/problemset/task/1644

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
int N, a, b, x[MAXN];
ll sum[MAXN];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> a >> b;
    ll ans = -infll;
    for(int i = 1;i<=N;i++){
        cin >> x[i];
        sum[i]+=sum[i-1]+x[i];
        if(a<=i&&i<=b) ans = max(ans, sum[i]);
    }
    multiset<ll>s;
    s.insert(sum[0]);
    for(int i = 0;i<=N;i++){
        if(i<a){
            continue;
        }
        ans = max(ans, sum[i]-*s.begin());
        if(i-b>=0) s.erase(s.find(sum[i-b]));
        s.insert(sum[i-a+1]);
    }
    cout << ans << nl;
    return 0;
}