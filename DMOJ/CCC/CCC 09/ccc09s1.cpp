/*
Cool Numbers
Canadian Computing Competition: 2009 Stage 1, Senior #1
https://dmoj.ca/problem/ccc09s1
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
int a, b;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> a >> b;
    int ans = 0;
    for(int i = 0;i*i*i<=b;i++){
        int cube = i*i*i;
        if(cube<a) continue;
        int sq = (int)sqrt(cube);
        if(sq*sq==cube){
            ans++;
        }
    }
    cout << ans << nl;
    return 0;
}