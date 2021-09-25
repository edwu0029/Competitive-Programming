/*
Digit Queries
https://cses.fi/problemset/task/2431/
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
int Q;
ll k;
ll pow10(int exp){
    ll res = 1;
    for(int i = 0;i<exp;i++) res*=1LL*10;
    return res;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> Q;
    while(Q--){
        cin >> k;
        if(k<=9){
            cout << k << nl;
            continue;
        }
        k--;
        int len = 0;
        for(;;len++){
            ll t = 1LL*9*pow10(len-1)*1LL*len;
            if(t<=k){
                k-=t;
            }else{
                break;
            }
        }
        ll a = k/len, b = k%len;
        string s = to_string(pow10(len-1)+a);
        cout << s[b] << nl;
    }
    return 0;
}