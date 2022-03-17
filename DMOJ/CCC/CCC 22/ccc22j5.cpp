/*
Square Pool
Canadian Computing Competition: 2022 Stage 1, Junior #5
https://dmoj.ca/problem/ccc22j5
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
const int MAXT = 105;
int N, T, tr[MAXT], tc[MAXT];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> T;
    for(int i = 0;i<T;i++){
        cin >> tr[i] >> tc[i];
    }
    tr[T] = tc[T] = 0;
    int ans = 0;
    for(int r:tr){
        for(int c:tc){
            int sz = min(N-r, N-c);
            for(int k = 0;k<T+1;k++){
                if(r<tr[k]&&c<tc[k]){
                    sz = min(sz, max(tr[k]-r, tc[k]-c)-1);
                }
            }
            ans = max(ans, sz);
        }
    }
    cout << ans << nl;
    return 0;
}