/*
Room Allocation
https://cses.fi/problemset/task/1164/
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
const int MAXN = 2e5+5;
int N, ans[MAXN], tot;
vector<tuple<int, int, int>>intervals;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 0, a, b;i<N;i++){
        cin >> a >> b;
        intervals.push_back({a, b, i});
    }
    sort(intervals.begin(), intervals.end());
    set<tuple<int, int, int>>s;
    int cnt = 0;
    for(int i = 0;i<N;i++){
        int a = get<0>(intervals[i]), b = get<1>(intervals[i]), idx = get<2>(intervals[i]);
        auto p = s.begin();
        if(s.size()==0||get<0>(*p)>=a){
            tot = ++cnt;
            s.insert({b, a, cnt});
            ans[idx] = cnt;
        }else{
            s.insert({b, a, get<2>(*p)});
            ans[idx] = get<2>(*p);
            s.erase(p);
        }
    }
    cout << tot << nl;
    for(int i = 0;i<N;i++) cout << ans[i] << sp;
    return 0;
}