/*
Where Am I?
USACO 2019 December Contest, Bronze, Problem 2
http://usaco.org/index.php?page=viewproblem2&cpid=964
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
int N;
string farms;
map<string, int>m;
int main(){
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> farms;
    for(int k = 1;k<=N;k++){
        m.clear();
        bool f = true;
        for(int i = 0;i<N-k+1;i++){
            string t = farms.substr(i, k);
            if(m[t]++>=1) f = false;
        }
        if(f){
            cout << k << nl;
            return 0;
        }
    }
    return 0;
}