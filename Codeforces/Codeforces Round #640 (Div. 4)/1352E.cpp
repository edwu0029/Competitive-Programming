/*
Special Elements
Codeforces Round #640 (Div. 4), Problem E
https://codeforces.com/contest/1352/problem/E
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
void solve(){
    int N; cin >> N;
    vector<int>a(N), freq(N+1);
    for(int i = 0;i<N;i++){
        cin >> a[i];
        freq[a[i]]++;
    }
    int ans = 0;
    for(int l = 0;l<N;l++){
        int sum = a[l];
        for(int r = l+1;r<N;r++){
            sum+=a[r];
            if(sum<=N){
                ans+=freq[sum];
                freq[sum] = 0; //Don't overcount
            }
        }
    }
    cout << ans << nl;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while(T--){
        solve();
    }
    return 0;
}