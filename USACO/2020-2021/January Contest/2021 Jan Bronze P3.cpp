/*
Just Stalling
USACO 2021 January Contest, Bronze, Problem 3
http://usaco.org/index.php?page=viewproblem2&cpid=1085
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
int N, a[25], b[25];
ll ans;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 1;i<=N;i++) cin >> a[i];
    for(int i = 1;i<=N;i++) cin >> b[i];
    sort(a+1, a+N+1);
    sort(b+1, b+N+1);
    ans = 1;
    for(int i = N;i>=1;i--){
        int cnt = 0;
        for(int j = N;j>=1;j--){
            if(b[j]>=a[i]) cnt++;
            else break;
        }
        if(cnt<N-i+1){
            ans = 0;
            break;
        }else{
            ans*=1LL*(cnt-(N-i));
        }
    }
    cout << ans << nl;
    return 0;
}