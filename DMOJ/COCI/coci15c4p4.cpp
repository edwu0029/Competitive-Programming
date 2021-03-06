/*
Chewbacca
COCI '15 Contest 4 #4
https://dmoj.ca/problem/coci15c4p4
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
ll N, K, Q;
ll solve(ll x, ll y){
    ll cnt = 0;
    while(x!=y){
        if(x>y){
            x = (x-1)/K;
        }else{
            y = (y-1)/K;
        }
        cnt++;
    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> K >> Q;
    for(int i = 1;i<=Q;i++){
        ll x, y;
        cin >> x >> y; x--; y--;
        cout << solve(x, y) << nl;
    }
    return 0;
}