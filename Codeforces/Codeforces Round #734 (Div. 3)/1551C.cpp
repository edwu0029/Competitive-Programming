/*
Interesting Story
Codeforces Round #734 (Div. 3), Problem C
https://codeforces.com/contest/1551/problem/C
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
    vector<string>S(N);
    for(int i = 0;i<N;i++) cin >> S[i];
    int ans = 0;
    for(int i = 0;i<26;i++){
        vector<int>F(N);
        for(int j = 0;j<N;j++){
            int cnt = 0;
            for(int k = 0;k<S[j].size();k++){
                if(S[j][k]-'a'==i) cnt++;
                else cnt--;
            }
            F[j] = cnt;
        }
        sort(F.begin(), F.end(), greater<int>());
        int sum = 0;
        for(int j = 0;j<N;j++){
            sum+=F[j];
            if(sum>0) ans = max(ans, j+1);
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