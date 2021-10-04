/*
Stamp
AtCoder Beginner Contest 185, Problem D
https://atcoder.jp/contests/abc185/tasks/abc185_d
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
int N, M, ans;
vector<int>blues, dis;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> M;
    for(int i = 0, a;i<M;i++){
        cin >> a;
        blues.push_back(a);
    }
    sort(blues.begin(), blues.end());
    if(blues.size()==0){
        cout << 1 << nl;
        return 0;
    }
    blues.push_back(0);
    blues.push_back(N+1);
    sort(blues.begin(), blues.end());
    int minn = inf;
    for(int i = 1;i<blues.size();i++){
        int t = blues[i]-blues[i-1]-1;
        if(t>0){
            dis.push_back(t);
            minn = min(minn, t);
        }
    }
    sort(dis.begin(), dis.end());
    for(int i = 0;i<dis.size();i++){
        ans+=ceil((double)dis[i]/minn);
    }
    cout << ans << nl;
    return 0;
} 