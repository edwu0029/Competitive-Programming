/*
Sum of Round Numbers
Codeforces Round #640 (Div. 4), Problem A
https://codeforces.com/contest/1352/problem/A
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
void solve(){
    string N; cin >> N;
    vector<string>ans;
    for(int i = N.size()-1;i>=0;i--){
        if(N[i]=='0') continue;
        string t = "";
        t.push_back(N[i]);
        for(int j = 0;j<N.size()-1-i;j++){
            t+="0";
        }
        ans.push_back(t);
    }
    cout << ans.size() << nl;
    for(auto i:ans){
        cout << i << sp;
    }
    cout << nl;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while(T--){
        solve();
    }
    return 0;
}