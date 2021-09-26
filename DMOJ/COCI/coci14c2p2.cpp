/*
Utrka
COCI '14 Contest 2 #2
https://dmoj.ca/problem/coci14c2p2
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
int N; string s;
multiset<string>ms;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> s;
        ms.insert(s);
    }
    for(int i = 0;i<N-1;i++){
        cin >> s;
        ms.erase(ms.find(s));
    }
    for(string i : ms){
        cout << i << nl; 
    }
    return 0;
}