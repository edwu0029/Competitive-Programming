/*
Josh's Double Bacon Deluxe
Canadian Computing Competition: 2020 Stage 1, Senior #5
https://dmoj.ca/problem/ccc20s5
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
const int MAXN = 1e6+5, MAXB = 5e5+5;
int N, item[MAXN], last[MAXB];
double dp[MAXN], suf;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >>N;
    for(int i = 1;i<=N;i++){
        cin >> item[i];
        last[item[i]]=i;
    }
    if(item[N]==item[1]) dp[N] = 1.0;
    suf = dp[N];
    for(int i = N-1;i>=1;i--){
        if(item[i]==item[1]){
            dp[i] = 1.0;
        }else if(last[item[i]]!=i){
            dp[i] = dp[last[item[i]]];
        }else if(last[item[i]]==i){
            dp[i] = (1+suf)/(N-i+1);
        }
        suf+=dp[i];
    }
    cout << fixed << setprecision(8) << (double)(suf/N) << nl;
    return 0;
}