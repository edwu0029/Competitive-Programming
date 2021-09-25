/*
Bridge Transport
Canadian Computing Competition: 2013 Stage 1, Senior #2
https://dmoj.ca/problem/ccc13s2
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
const int MAXN = 1e6+5;
int W, N, F[100001], t1, t2, t3, t4, ans;
bool f = true;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> W >> N;
    for(int i = 1;i<=N;i++){
        cin >> F[i];
        if(i==1){
            t1 = F[i];
        }else if(i==2){
            t2 = F[i];
        }else if(i==3){
            t3 = F[i];
        }else if(i==4){
            t4 = F[i];
        }else{
            t1 = t2; t2 = t3; t3 = t4; t4 = F[i];
        }
        if(!f) continue;
        if(t1+t2+t3+t4>W){
            f = false;
        }else{
            ans++;
        }
    }
    cout << ans << nl;
    return 0;
}