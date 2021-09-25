/*
Zero That Out
Canadian Computing Competition: 2015 Stage 1, Senior #1
https://dmoj.ca/problem/ccc15s1
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
const int MAXN = 1e6+5;
int K;
deque<int>dq;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> K;
    for(int i = 0, x;i<K;i++){
        cin >> x;
        if(x==0) dq.pop_back();
        else dq.push_back(x);
    }
    int sum = 0;
    while(!dq.empty()){
        sum+=dq.front();
        dq.pop_front();
    }
    cout << sum << nl;
    return 0;
}