/*
Uddered but not Herd
USACO 2021 January Contest, Bronze, Problem 1
http://usaco.org/index.php?page=viewproblem2&cpid=1083
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
int ans;
string alpha, msg;
map<char, int>m;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> alpha >> msg;
    for(int i = 0;i<26;i++){
        m[alpha[i]] = i;
    }
    int pre = 26;
    for(int i = 0;i<msg.size();i++){
        if(pre>=m[msg[i]]) ans++;
        pre = m[msg[i]];
    }
    cout << ans << nl;
    return 0;
}