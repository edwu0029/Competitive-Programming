//Problem: https://dmoj.ca/problem/ccc07j2

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
map<string, string>m;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    m["CU"] = "see you";
    m[":-)"] = "I'm happy";
    m[":-("] = "I'm unhappy";
    m[";-)"] = "wink";
    m[":-P"] = "stick out my tongue";
    m["(~.~)"] = "sleepy";
    m["TA"] = "totally awesome";
    m["CCC"] = "Canadian Computing Competition";
    m["CUZ"] = "because";
    m["YW"] = "you're welcome";
    m["TTYL"] = "talk to you later";
    while(true){
        string s; cin >> s;
        if(m[s]=="") cout << s << nl;
        else cout << m[s] << nl;
        if(s=="TTYL") break;
    }
    return 0;
}