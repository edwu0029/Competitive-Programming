//Problem: http://usaco.org/index.php?page=viewproblem2&cpid=966

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
vector<int>F = {1, 2, 4, 7, 8, 11, 13, 14};
int main(){
    freopen("moobuzz.in", "r", stdin);
    freopen("moobuzz.out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    int rem = N%8;
    if(rem==0) rem = 8;
    rem--;
    cout << F[rem]+(N-1)/8*15 << nl;
    return 0;
}