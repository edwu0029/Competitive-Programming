/*
Binary String Reconstruction
Codeforces Round #640 (Div. 4), Problem F
https://codeforces.com/contest/1352/problem/F
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
    int n0, n1, n2; cin >> n0 >> n1 >> n2;
    vector<int>left, middle, right;
    int pre = 0;
    if(n0>0){
        for(int i = 0;i<n0+1;i++) left.push_back(0);
        pre = 0;
    }
    if(n2>0){
        for(int i = 0;i<n2+1;i++) middle.push_back(1);
        pre = 1;
    }
    if(left.size()>0&&middle.size()>0) n1--;
    if(n1>=1){
        pre^=1;
        right.push_back(pre);
        if(left.size()>0||middle.size()>0) n1--;
        pre^=1;
        for(int i = 0;i<n1;i++){
            right.push_back(pre);
            pre^=1;
        }
    }
    for(int i:left) cout << i;
    for(int i:middle) cout << i;
    for(int i:right) cout << i;
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