/*
Wonderful Coloring - 2
Codeforces Round #734 (Div. 3), Problem B2
https://codeforces.com/contest/1551/problem/B2
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
    int N, K; cin >> N >> K;
    vector<int>a(N), colour(N);
    vector<bool>F(N);
    vector<vector<int>>vals(N+1, vector<int>());
    map<int, int>m;
    int cnt = 0;
    for(int i = 0;i<N;i++){
        cin >> a[i];
        if(!m[a[i]]) m[a[i]] = ++cnt;
        vals[m[a[i]]].push_back(i);
    }
    int t = 0;
    for(int i = 1;i<=cnt;i++){
        if(vals[i].size()<K) t+=vals[i].size();
    }
    t-=t%K;
    int cur_colour = 1;
    for(int i = 1;i<=cnt;i++){
        if(vals[i].size()>=K){
            for(int j = 0;j<vals[i].size();j++){
                if(j<K) colour[vals[i][j]] = j+1;
                else colour[vals[i][j]] = 0;
            }
        }else{
            for(int j = 0;j<vals[i].size();j++){
                if(t>0){
                    colour[vals[i][j]] = cur_colour;
                    cur_colour++;
                    if(cur_colour>K) cur_colour = 1;
                    t--;
                }else colour[vals[i][j]] = 0;
            }
        }
    }
    for(int i = 0;i<N;i++){
        cout << colour[i] << sp;
    }
    cout << nl;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while(T--){
        solve();
    }
    return 0;
}