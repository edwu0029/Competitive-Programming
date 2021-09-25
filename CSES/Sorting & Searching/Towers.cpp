/*
Towers
https://cses.fi/problemset/task/1073/
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
int N;
multiset<int>s;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    int ans = 0;
    for(int i = 0, k;i<N;i++){
        cin >> k;
        auto pos = s.upper_bound(k);
        if(pos==s.end()){
            ans++;
            s.insert(k);
        }else{
            s.erase(pos);
            s.insert(k);
        }
    }
    cout << ans << nl;
    return 0;
}