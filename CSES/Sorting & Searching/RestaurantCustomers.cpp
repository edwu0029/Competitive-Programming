//Problem: https://cses.fi/problemset/task/1619/

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
int N, F[2*MAXN];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    vector<int>starts(N), ends(N), points;
    for(int i = 0;i<N;i++){
        cin >> starts[i] >> ends[i];
        points.push_back(starts[i]);
        points.push_back(ends[i]);
    }
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());
    sort(points.begin(), points.end());
    for(int i = 0;i<2*N;i++){
        auto pos = lower_bound(starts.begin(), starts.end(), points[i]);
        if(pos!=starts.end()&&(*pos)==points[i]){
            F[i]++;
        }else{
            F[i]--;
        }
    }
    int ans = F[0];
    for(int i = 1;i<2*N;i++){
        F[i]+=F[i-1];
        ans = max(ans, F[i]);
    }
    cout << ans << nl;
    return 0;
}