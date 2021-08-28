//Problem: https://dmoj.ca/problem/ccc12s2

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
string s;
map<char, int>m;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    cin >> s;
    int pa = 0, pr = 0, ans = 0;
    for(int i = 0;i<s.size();i+=2){
        int ca = s[i]-'0', cr = m[s[i+1]];
        if(cr>pr) ans-=2*pa*pr;
        ans+=ca*cr;
        pa = ca, pr = cr;
    }
    cout << ans << nl;
    return 0;
}