/*
Svada
COCI '08 Contest 2 #4
https://dmoj.ca/problem/coci08c2p4
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define nl '\n'
#define sp ' '
#define f first
#define s second
#define mp(a, b) make_pair(a, b)
#define EPS 1e-9
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ll MODll = 4000004479;
const int MAXN = 102;
int T, N, M, ans;
pii t1[MAXN], t2[MAXN];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> T >> N;
    for(int i = 0;i<N;i++){
        cin >> t1[i].f >> t1[i].s;
    }
    cin >> M;
    for(int i = 0;i<M;i++){
        cin >> t2[i].f >> t2[i].s;
    }
    int l = 1, r = T;
    while(l<=r){
        int mid = l+(r-l)/2, cnt = 0;
        for(int i = 0;i<N;i++){
            if(t1[i].f>mid) continue;
            cnt++;
            cnt+=(mid-t1[i].f)/t1[i].s;
        }
        int cnt2 = 0, tl = T-mid;
        for(int i = 0;i<M;i++){
            if(t2[i].f>tl) continue;
            cnt2++;
            cnt2+=(tl-t2[i].f)/t2[i].s;
        }
        if(cnt<=cnt2){
            ans = mid; l = mid+1;
        }else if(cnt>cnt2){
            r = mid-1;
        }
    }
    cout << ans << nl;
    return 0;
}