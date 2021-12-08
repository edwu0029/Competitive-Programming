/*
Increasing Subsequence
https://cses.fi/problemset/task/1145/
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
int N;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    vector<int>lis;
    for(int i = 0, x;i<N;i++){
        cin >> x;
        auto p = lower_bound(lis.begin(), lis.end(), x);
        if(p==lis.end()) lis.push_back(x);
        else lis[p-lis.begin()] = x;
    }
    cout << lis.size() << nl;
    return 0;
}