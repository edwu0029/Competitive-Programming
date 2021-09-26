/*
What is this Roman Numeral
DWITE Online Computer Programming Contest, October 2008, Problem 4
https://dmoj.ca/problem/dwite08c1p4
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
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    map<char, int>m;
    m[' '] = 0;
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    for(int i = 0;i<5;i++){
        string s; cin >> s;
        char pre = ' ';
        int val = 0;
        for(int j = 0;j<s.size();j++){
            if(m[pre]<m[s[j]]){
                val+=m[s[j]];
                val-=2*m[pre];
            }else{
                val+=m[s[j]];
            }
            pre = s[j];
        }
        cout << val << nl;
    }
}