//Problem: https://cses.fi/problemset/task/1085/

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
const int MAXN = 2e5+5;
int N, K, x[MAXN];
ll ans;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> K;
    for(int i = 0;i<N;i++) cin >> x[i];
    ll lo = 1, hi = 2e14;
    while(lo<=hi){
        ll mid = (lo+hi)/2, sum = 0;
        int g = 0;
        bool flag = true;
        for(int i = 0;i<N;i++){
            if(x[i]>mid) flag = false;
            sum+=x[i];
            if(sum>mid){
                g++;
                sum = x[i];
            }
        }
        if(sum>0) g++;
        if(g<=K&&flag){
            ans = mid;
            hi = mid-1;
        }else{
            lo = mid+1;
        }
    }
    cout << ans << nl;
    return 0;
}