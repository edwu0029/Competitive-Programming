//Problem: https://dmoj.ca/problem/ccc12s3

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define nl '\n'
#define sp ' '
#define f first
#define s second
#define mp(a, b) make_pair(a, b)
#define EPS 1e-9
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ll MODll = 4000004479;
const int MAXN = 1e5+1;
map<int, int>m;
vector<pair<int, int>>readings;
int N, v1, v2, f1, f2, ans;
bool h1 = true;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 0, r;i<N;i++){
        cin >> r;
        m[r]++;
    }
    for(auto i:m) readings.push_back(mp(i.s, i.f));
    sort(readings.begin(), readings.end());
    v1 = readings[readings.size()-1].second;
    f1 = readings[readings.size()-1].f;
    if(readings[readings.size()-2].f!=f1) h1 = false;
    if(h1){
        for(int i = readings.size()-1;i>=0;i--){
            if(readings[i].f==f1||(readings[i].f==f1&&i==0)){
                v2 = readings[i].s;
            }else break;
        }
        ans = abs(v1-v2);
    }else{
        for(int i = readings.size()-1;i>=0;i--){
            if(readings[i-1].f!=f1&&f2==0){
                f2 = readings[i-1].first;
            }
            if(readings[i].first==f2&&f2!=0){
                v2 = readings[i].s;
                ans = max(ans, abs(v2-v1));
            }
        }
    }
    cout << ans << '\n';
    return 0;
}