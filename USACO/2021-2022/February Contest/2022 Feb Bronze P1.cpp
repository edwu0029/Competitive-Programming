/*
Sleeping in Class
USACO 2022 February Contest, Bronze, Problem 1
http://usaco.org/index.php?page=viewproblem2&cpid=1203
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
int N, A[MAXN], prefix[MAXN];
void solve(){
    cin >> N;
    int sum = 0;
    bool allthesame = true;
    for(int i = 1;i<=N;i++){
        cin >> A[i];
        if(i>1&&A[i]!=A[i-1]) allthesame = false;
        sum+=A[i];
    }
    if(allthesame){
        cout << 0 << nl;
        return;
    }
    //Find factors of sum
    vector<int>factors;
    for(int i = 1;i*i<=sum;i++){
        if(sum%i==0){
            factors.push_back(i);
            factors.push_back(sum/i);
        }
    }
    sort(factors.begin(), factors.end());
    //Answer will always be the smallest factor that works
    for(int f:factors){
        bool check = true;
        int cursum = A[1], cnt = 0;
        for(int i = 2;i<=N;i++){
            if(cursum+A[i]>f){
                if(cursum==f){
                    cursum = A[i];
                }else{
                    check = false;
                    break;
                }
            }else{
                cnt++;
                cursum+=A[i];
            }
        }
        if(cursum!=0&&cursum!=f) check = false;
        if(check){
            cout << cnt << nl;
            return;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while(T--){
        solve();
    }
    return 0;
}