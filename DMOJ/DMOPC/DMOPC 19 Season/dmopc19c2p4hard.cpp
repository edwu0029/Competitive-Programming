/*
A Greedy Problem
DMOPC '19 Contest 2 P4
https://dmoj.ca/problem/dmopc19c2p4hard
*/

#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <complex>
#include <iomanip>
#include <cassert>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define nl '\n'
#define sp ' '
#define f first
#define s second
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define EPS 1e-9
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ll MODll = 4000004479;
const int MAXN = 2005, LOG = 16;
int N, T, Q, t[MAXN], dp[MAXN], temp[MAXN];
ll ans;
int add(int a, int b){
    int F = a+b;
    if(F<0)F+=MOD;
    if(F>=MOD)F-=MOD;
    return F;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> T >> Q;
    dp[0] = 1;
    for(int i = 1;i<=N;i++){
        cin >> t[i];
        for(int j = T;j>=t[i];j--){
            dp[j] = add(dp[j], dp[j-t[i]]);
        }
    }
    for(int i = 1, a, b, q;i<=Q;i++){
        cin >> a >> b >> q;
        ans = 0;
        a = t[a]; b = t[b];
        q-=a+b;
        if(q<0){
            cout << "0" << nl;
            continue;
        }
        memcpy(temp, dp, sizeof(dp));
        for(int j = a;j<=T;j++) temp[j] = add(temp[j], -temp[j-a]);
        for(int j = b;j<=T;j++) temp[j] = add(temp[j], -temp[j-b]);
        for(int j = 0;j<=q;j++) ans+=temp[j];
        cout << ans%MOD << '\n';
    }
    return 0;
}