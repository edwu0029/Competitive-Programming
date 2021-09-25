/*
Daisy Chains
USACO 2020 December Contest, Bronze, Problem 2
http://usaco.org/index.php?page=viewproblem2&cpid=1060
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
int N, p[1005], ans;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 1;i<=N;i++) cin >> p[i];
    for(int i = 1;i<=N;i++){
        for(int j = i;j<=N;j++){
            int sum = 0;
            for(int k = i;k<=j;k++) sum+=p[k];
            if(sum%(j-i+1)) continue;
            int avg = sum/(j-i+1);
            for(int k = i;k<=j;k++){
                if(p[k]==avg){
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans << nl;
    return 0;
}
