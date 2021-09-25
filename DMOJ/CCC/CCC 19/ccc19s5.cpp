/*
Triangle: The Data Structure
Canadian Computing Competition: 2019 Stage 1, Senior #5
https://dmoj.ca/problem/ccc19s5
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
const int MAXN = 3002;
int N, K, F[MAXN][MAXN], bit[MAXN][MAXN];
ll ans;
void update(int x, int y, int v){
    for(int i = x;i<MAXN;i+=(i&(-i))){
        for(int j = y;j<MAXN;j+=(j&(-j))){
            bit[i][j] = max(bit[i][j], v);
        }
    }
}
int query(int x, int y){
    int r = 0;
    for(int i = x;i>0;i-=(i&(-i))){
        for(int j = y;j>0;j-=(j&(-j))){
            r = max(r, bit[i][j]);
        }
    }
    return r;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> K;
    for(int i = 1;i<=N;i++){
        for(int j = N;j>N-i;j--){
            cin >> F[i][j];
        }
    }
    for(int i = 1;i<=N;i++){
        for(int j = 0;j<i;j++){
            update(N-i+1+j, N-j, F[N-i+1+j][N-j]);
            if(j>=K-1){
                ans+=(1LL)*query(N-i+1+j, N-j+K-1);
            }
        }
    }
    cout << ans << nl;
}