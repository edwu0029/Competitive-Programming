//Problem: https://dmoj.ca/problem/ccc06s2

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
map<char, char>m;
string org, encr, msg;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    getline(cin, org);
    getline(cin, encr);
    getline(cin, msg);
    for(int i = 0;i<org.size();i++){
        m[encr[i]] = org[i];
    }
    string ans = "";
    for(int i = 0;i<msg.size();i++){
        if(m[msg[i]]==0) ans+=".";
        else ans+=m[msg[i]];
    }
    cout << ans << nl;
    return 0;
}