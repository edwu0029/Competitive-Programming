/*
Gray Code
https://cses.fi/problemset/task/2205/
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
const int MAXN = 20;
int N;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 0;i<(1<<N);i++){
        vector<int>v;
        for(int j = 0;j<N;j++){
            if((1<<j)&i) v.push_back(1);
            else v.push_back(0);
        }
        reverse(v.begin(), v.end());
        cout << v[0];
        int pre = v[0];
        for(int i = 1;i<N;i++){
            if(v[i]==pre) cout << 0;
            else cout << 1;
            pre = v[i];
        }
        cout << nl;
    }
    return 0;
}