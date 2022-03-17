/*
Good Groups
Canadian Computing Competition: 2022 Stage 1, Junior #4, Senior #2
https://dmoj.ca/problem/ccc22s2
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
#define nl '\n'
#define sp ' '
const int MAXN = 3e5+5;
int X, Y, G, group[MAXN];
pii must[MAXN];
pii mustnot[MAXN];
map<string, int>m;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> X;
    int cnt = 0;
    for(int i = 0;i<X;i++){
        string a, b; cin >> a >> b;
        if(m[a]==0) m[a] = ++cnt;
        if(m[b]==0) m[b] = ++cnt;
        must[i] = make_pair(m[a], m[b]);
    }
    cin >> Y;
    for(int i = 0;i<Y;i++){
        string a, b; cin >> a >> b;
        if(m[a]==0) m[a] = ++cnt;
        if(m[b]==0) m[b] = ++cnt;
        mustnot[i] = make_pair(m[a], m[b]);
    }
    cin >> G;
    for(int i = 1;i<=G;i++){
        for(int j = 0;j<3;j++){
            string a; cin >> a;
            if(m[a]==0) m[a] = ++cnt;
            group[m[a]] = i;
        }
    }
    int ans = 0;
    for(int i = 0;i<X;i++){
        if(group[must[i].first]!=group[must[i].second]) ans++;
    }
    for(int i = 0;i<Y;i++){
        if(group[mustnot[i].first]==group[mustnot[i].second]) ans++;
    }
    cout << ans << nl;
    return 0;
}