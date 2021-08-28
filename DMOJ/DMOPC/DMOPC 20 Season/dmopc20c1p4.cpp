//Problem: https://dmoj.ca/problem/dmopc20c1p4

#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <complex>
#include <iomanip>
#include <cassert>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <cstring>
#include <climits>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;
#define nl '\n'
#define sp ' '
#define f first
#define s second
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define EPS 1e-9
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ll MODll = 4000004479;
const int MAXN = 105, LOG = 16;
ll N, K, C, ans;
int T;
matrix id, a;
matrix mult(matrix a, matrix b){
    matrix ret(T+1, vector<ll>(T+1, 0));
    for(int i = 0;i<=T;i++){
        for(int j = 0;j<=T;j++){
            for(int k = 0;k<=T;k++){
                ret[i][j] = (ret[i][j]+a[i][k]*b[k][j])%MOD;
            }
        }
    }
    return ret;
}
matrix bin_pow(matrix x, ll exp){
    if(exp==0) return id;
    matrix t = bin_pow(x, exp/2);
    t = mult(t, t);
    if(exp%2==0) return t;
    else return mult(t, x);
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> K >> T >> C;
    a.resize(T+1, vector<ll>(T+1, 0));
    id.resize(T+1, vector<ll>(T+1, 0));
    for(int i = 0;i<=T;i++) id[i][i] = 1;
    for(int i = 0;i<T;i++) a[i+1][i] = 1;
    a[0][T] = K; a[T][T] = 1;
    a = bin_pow(a, N-1);
    ans = (2*C*a[T][T])%MOD;
    for(int i = 0;i<T;i++) ans = (ans+(C*a[i][T])%MOD)%MOD;
    cout << ans << nl;
    return 0;
}