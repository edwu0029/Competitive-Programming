//Problem: https://cses.fi/problemset/task/1141/

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
int N, k[MAXN];
map<int, int>m;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 1;i<=N;i++){
        cin >> k[i];
    }
    int cnt  = 0, ans = 0;
    int l = 1, r = 1;
    for(;r<=N;r++){
        if(m[k[r]]==0){
            cnt++;
            m[k[r]] = r;
        }else{
            int pre = m[k[r]];
            for(;l<=pre;l++){
                m[k[l]] = 0;
                cnt--;
            }
            cnt++;
            m[k[r]] = r;
        }
        ans = max(ans, cnt);
    }
    cout << ans << nl;
    return 0;
}