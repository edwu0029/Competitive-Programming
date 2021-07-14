//Problem: https://cses.fi/problemset/task/1090

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
int N, X;
deque<int>dq;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> X;
    for(int i = 0, p;i<N;i++){
        cin >> p;
        dq.push_back(p);
    }
    sort(dq.begin(), dq.end());
    int ans = 0;
    while(dq.size()&&dq.back()==X){
        ans++;
        dq.pop_back();
    }
    while(dq.size()){
        int cur = dq.front();
        dq.pop_front();
        while(dq.size()&&dq.back()+cur>X){
            ans++;
            dq.pop_back();
        }
        if(dq.size()&&dq.back()+cur<=X){
            dq.pop_back();
        }
        ans++;
    }
    cout << ans << nl;
    return 0;
}