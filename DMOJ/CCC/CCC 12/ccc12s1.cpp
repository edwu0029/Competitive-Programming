/*
Don't pass me the ball!
Canadian Computing Competition: 2012 Stage 1, Senior #1
https://dmoj.ca/problem/ccc12s1
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
int J;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> J;
    int ans = 0;
    for(int i = J-1;i>=3;i--)
        for(int j = i-1;j>=2;j--)
            for(int k = j-1;k>=1;k--)
                ans++;
    cout << ans << nl;
    return 0;
}