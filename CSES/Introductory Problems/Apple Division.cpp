/*
Apple Division
https://cses.fi/problemset/task/1623/
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
const int MAXN = 25;
int N, p[MAXN];
ll sum, ans = infll;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> p[i];
        sum+=1LL*p[i];
    }
    for(int mask = 0;mask<(1<<N);mask++){
        ll tsum = 0;
        for(int i = 0;i<N;i++){
            if((1<<i)&mask) continue;
            tsum+=1LL*p[i];
        }
        ans = min(ans, abs(sum-2*tsum));
    }
    cout << ans << nl;
    return 0;
}