/*
Savez
COCI '15 Contest 2 #4
https://dmoj.ca/problem/coci15c2p4
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
int N, ans, mod = 1e9;
map<ll, int>m;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 1;i<=N;i++){
        string s; cin >> s;
        ll pre = 0, suf = 0;
        int best = 0;
        for(int j = 0;j<s.length();j++){
            pre = pre*131+s[j];
            suf = suf*131+s[s.length()-j-1];
            if(pre==suf)best = max(best, m[pre*mod+suf]);
        }
        ans = max(ans, best+1);
        m[pre*mod+suf]=best+1;
    }
    cout << ans << '\n';
    return 0;
}