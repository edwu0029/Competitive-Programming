/*
Cell-Phone Messaging
Canadian Computing Competition: 2006 Stage 1, Junior #3
https://dmoj.ca/problem/ccc06j3
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
map<char, string>m;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    m['a'] = "2";
    m['b'] = "22";
    m['c'] = "222";
    m['d'] = "3";
    m['e'] = "33";
    m['f'] = "333";
    m['g'] = "4";
    m['h'] = "44";
    m['i'] = "444";
    m['j'] = "5";
    m['k'] = "55";
    m['l'] = "555";
    m['m'] = "6";
    m['n'] = "66";
    m['o'] = "666";
    m['p'] = "7";
    m['q'] = "77";
    m['r'] = "777";
    m['s'] = "7777";
    m['t'] = "8";
    m['u'] = "88";
    m['v'] = "888";
    m['w'] = "9";
    m['x'] = "99";
    m['y'] = "999";
    m['z'] = "9999";
    while(true){
        string s; cin >> s;
        if(s=="halt") break;
        string pre = "0";
        int cnt = 0;
        for(int i = 0;i<s.size();i++){
            string p = m[s[i]];
            if(pre[0]==p[0]) cnt+=2;
            cnt+=p.size();
            pre = p;
        }
        cout << cnt << nl;
    }
    return 0;
}