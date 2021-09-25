/*
Keep on Truckin'
Canadian Computing Competition: 2007 Stage 1, Junior #5
https://dmoj.ca/problem/ccc07j5
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
int A, B, N, len;
vector<int>motels = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
ll dp[7005];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> A >> B >> N;
    for(int i = 0, m;i<N;i++){
        cin >> m;
        motels.push_back(m);
    }
    sort(motels.begin(), motels.end());
    len = motels.size();
    dp[0] = 1;
    for(int i = 0;i<len;i++){
        if(dp[i]==0) continue;
        for(int j = i+1;j<len;j++){
            int dis = motels[j]-motels[i];
            if(A<=dis&&dis<=B){
                dp[j]+=dp[i];
            }
        }
    }
    cout << dp[len-1] << nl;
    return 0;
}