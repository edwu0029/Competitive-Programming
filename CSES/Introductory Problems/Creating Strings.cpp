/*
Creating Strings
https://cses.fi/problemset/task/1622/
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
const int MAXN = 2e5+5;
string s;
int N, c;
set<string>ans;
void solve(int check, string a){
    if(check==(1<<N)-1){
        ans.insert(a);
        return;
    }
    for(int i = 0;i<N;i++){
        if(check&(1<<i)) continue;
        solve(check|(1<<i), a+s[i]);
    }
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> s;
    N = s.size();
    solve(0, "");
    cout << ans.size() << nl;
    for(auto i:ans){
        cout << i << nl;
    }
    return 0;
}