/*
Wonderful Coloring - 1
Codeforces Round #734 (Div. 3), Problem B1
https://codeforces.com/contest/1551/problem/B1
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
    string S; cin >> S;
    vector<int>freq(26);
    for(int i = 0;i<S.size();i++){
        freq[S[i]-'a']++;
    }
    int cnt = 0, K = 0;
    for(int i = 0;i<26;i++){
        if(freq[i]>=2) K++;
        else cnt+=freq[i];
    }
    K+=cnt/2;
    cout << K << nl;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while(T--){
        solve();
    }
    return 0;
}