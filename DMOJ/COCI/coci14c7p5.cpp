//Problem: https://dmoj.ca/problem/coci14c7p5

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
const int MAXN = 3e5+2;
int N, K, ans;
ll a[MAXN], pre[MAXN];
bool check(int x){
    long long m = LONG_LONG_MAX;
    for(int i = 1;i<=N;i++){
        pre[i]=pre[i-1]+a[i]-x;
        if(i>=K){m = min(pre[i-K], m);}
        if(pre[i]>=m)return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> K;
    for(int i = 1;i<=N;i++){
        cin >> a[i]; a[i]*=1000;
    }
    int lo = 1, hi = 1e9+1;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(check(mid)){
            lo = mid+1;
            ans = mid;
        }else{
            hi = mid-1;
        }
    }
    cout << fixed << setprecision(4) << (ans/1000.0) << nl;
    return 0;
}