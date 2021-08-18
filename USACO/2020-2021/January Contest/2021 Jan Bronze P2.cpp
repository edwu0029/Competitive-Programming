//Problem: http://usaco.org/index.php?page=viewproblem2&cpid=1084

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
int N, even, odd, ans;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 0, x;i<N;i++){
        cin >> x;
        if(x%2==0) even++;
        else odd++;
    }
    if(N==1&&odd==1){
        cout << 0 << nl;
        return 0;
    }
    int t = 0;
    while(true){
        if(!t){ //Even
            if(even) even--;
            else if(!even&&odd>=2) odd-=2;
            else break;
        }else{ //Odd
            if(odd) odd--;
            else break;
        }
        ans++;
        t^=1;
    }
    if(!t&&odd) ans--;
    cout << ans << nl;
    return 0;
}