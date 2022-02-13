/*
Closest Cow Wins
USACO 2021 December Contest, Silver, Problem 1
http://usaco.org/index.php?page=viewproblem2&cpid=1158
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
int K, M, N;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> K >> M >> N;
    vector<pii>pos;
    for(int i = 0, x, y;i<K;i++){
        cin >> x >> y;
        pos.push_back(mp(x, y));
    }
    for(int i = 0, x;i<M;i++){
        cin >> x;
        pos.push_back(mp(x, -1));
    }
    sort(pos.begin(), pos.end());
    vector<ll> vals;
    int last_cow = -1;
    ll sum_range = 0;
    int li = 0;
    for(;li<pos.size();li++){
        if(pos[li].second==-1) break;
        sum_range+=pos[li].second;
    }
    vals.push_back(sum_range);
    sum_range = 0;
    for(int i = li;i<pos.size();i++) {
        if(pos[i].second!=-1){
            sum_range+=pos[i].second;
            continue;
        }
        ll window_sum = 0;
        ll best = 0;
        int r = last_cow;
        for (int j = last_cow+1;j<i;j++) {
            while (r+1<i&&2*(pos[r+1].first-pos[j].first)<pos[i].first-pos[last_cow].first){
                r++;
                window_sum += pos[r].second;
            }
            best = max(best, window_sum);
            window_sum-=pos[j].second;
        }
        vals.push_back(best);
        vals.push_back(sum_range-best);
        last_cow = i;
        sum_range = 0;
    }
    vals.push_back(sum_range);
    sort(vals.begin(), vals.end(), greater<ll>());
    ll ans = 0;
    for(int i = 0;i<min(N, (int)vals.size());i++) ans+=vals[i];
    cout << ans << nl;
    return 0;
}