/*
Meetings
USACO 2019 December Contest, Silver, Problem 2
http://usaco.org/index.php?page=viewproblem2&cpid=967
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
struct cow{
    int w, x, d;
};
bool cmp(const cow a, const cow b){
    return a.x<b.x;
}
int N, L, tot, cnt, t;
vector<cow>cows;
deque<int>lft, rit, wt;
ll ans = 0;
int main(){
    freopen("meetings.in", "r", stdin);
    freopen("meetings.out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> L;
    for(int i = 0, w, x, d;i<N;i++){
        cin >> w >> x >> d;
        cows.push_back({w, x, d});
        tot+=w;
    }
    sort(cows.begin(), cows.end(), cmp);
    for(int i=0; i<cows.size(); i++){
        if(cows[i].d<0) lft.push_back(cows[i].x);
        else rit.push_back(cows[i].x);
        wt.push_back(cows[i].w);
    }
    while(cnt*2<tot) {
        int tl = 1e9, tr = 1e9;
        if(!lft.empty()) tl = lft.front();
        if(!rit.empty()) tr = L-rit.back();
        if(tl<tr){
            cnt += wt.front();
            t = tl;
            if(!rit.empty()) ans+=upper_bound(rit.begin(), rit.end(), lft.front())-rit.begin();
            wt.pop_front();
            lft.pop_front();
        }else{
            cnt += wt.back();
            t = tr;
            if(!lft.empty()){
                int pos = lower_bound(lft.begin(), lft.end(), rit.back())-lft.begin();
                ans +=((int)lft.size()-pos);
            }
            wt.pop_back();
            rit.pop_back();
        }
    }
    for(int i:lft){
        ans+=upper_bound(rit.begin(), rit.end(), i)-lower_bound(rit.begin(), rit.end(), i-2*t);
    }
    cout << ans << nl;
    return 0;
}