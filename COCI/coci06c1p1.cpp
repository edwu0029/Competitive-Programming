//Problem: https://dmoj.ca/problem/coci06c1p1

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
int cnt[43], cur, ans;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    for(int i = 0;i<10;i++){
        cin >> cur;
        cnt[cur%42]++;
    }
    for(int i = 0;i<43;i++){
        if(cnt[i]>0){
            ans++;
        }
    }
    cout << ans << nl;
    return 0;
}