/*
Air Cownditioning
USACO 2021 December Contest, Bronze, Problem 2
http://usaco.org/index.php?page=viewproblem2&cpid=1156
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
const int MAXN = 1e5+5;
int N, p[MAXN], t[MAXN], diff[MAXN];
ll ans;
void solve(vector<int>&interval, int pos){
    if(interval.size()==0) return;
    ll cnt = abs(interval[0]);
    for(int i = 1;i<interval.size();i++){
        if(pos==1){
            if(interval[i-1]<interval[i]){
                cnt+=interval[i]-interval[i-1];
            }
        }else{
            if(interval[i-1]>interval[i]){
                cnt+=interval[i-1]-interval[i];
            }
        }
    }
    ans+=cnt;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 1;i<=N;i++) cin >> p[i];
    vector<int>interval;
    int pos = inf;
    for(int i = 1;i<=N;i++){
        cin >> t[i];
        diff[i] = p[i]-t[i];
        if(pos==inf) pos = (diff[i]>0)?1:-1;
        if(diff[i]==0||(pos==-1&&diff[i]>0)||(pos==1&&diff[i]<0)){
            solve(interval, pos);
            pos = inf;
            interval.clear();
            if(diff[i]!=0){
                pos = (diff[i]>0)?1:-1;
                interval.push_back(diff[i]);
            }
        }else{
            interval.push_back(diff[i]);
        }
    }
    solve(interval, pos);
    cout << ans << nl;
    return 0;
}