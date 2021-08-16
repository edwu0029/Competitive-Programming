//Problem: http://usaco.org/index.php?page=viewproblem2&cpid=1059

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
    vector<int>F(7);
    for(int i = 0;i<7;i++) cin >> F[i];
    sort(F.begin(), F.end());
    if(F[0]+F[1]==F[2]){
        cout << F[0] << sp << F[1] << sp << F[3] << nl;
    }else{
        cout << F[0] << sp << F[1] << sp << F[2] << nl;
    }
    return 0;
}