/*
RSA Numbers
Canadian Computing Competition: 2005 Stage 1, Junior #2
https://dmoj.ca/problem/ccc05j2
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
int l, r, ans;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> l >> r;
    for(int i = l;i<=r;i++){
        int cnt = 0;
        for(int j = 1;j*j<=i;j++){
            if(i%j==0) cnt+=2;
            if(j*j==i) cnt--;
        }
        if(cnt==4) ans++;
    }
    cout << "The number of RSA numbers between " << l << " and " << r << " is " << ans << nl;
    return 0;
}