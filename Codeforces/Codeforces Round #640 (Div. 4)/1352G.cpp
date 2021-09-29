/*
Special Permutation
Codeforces Round #640 (Div. 4), Problem G
https://codeforces.com/contest/1352/problem/G
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
    int N; cin >> N;
    if(N<=3){
        cout << -1 << nl;
        return;
    }
    vector<int>evens, odds;
    for(int i = 1;i<=N;i++){
        if(i%2==0) evens.push_back(i);
        else odds.push_back(i);
    }
    for(int i = odds.size()-1;i>=0;i--){
        cout << odds[i] << sp;
    }
    cout << 4 << sp << 2 << sp;
    for(int i = 2;i<evens.size();i++){
        cout << evens[i] << sp;
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