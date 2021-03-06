/*
Who is in the Middle?
Canadian Computing Competition: 2007 Stage 1, Junior #1
https://dmoj.ca/problem/ccc07j1
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
vector<int>F;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    for(int i = 0, x;i<3;i++){
        cin >> x;
        F.push_back(x);
    }
    sort(F.begin(), F.end());
    cout << F[1] << nl;
    return 0;
}