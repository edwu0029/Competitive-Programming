//Problem: https://dmoj.ca/problem/ccc08s2

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
    while(true){
        int R; cin >> R;
        if(R==0) break;
        int cnt = 0;
        for(int i = 0, y;i<R;i++){
            y = (int)sqrt(R*R-i*i);
            cnt+=y;
        }
        cout << cnt*4+1 << nl;
    }
    return 0;
}