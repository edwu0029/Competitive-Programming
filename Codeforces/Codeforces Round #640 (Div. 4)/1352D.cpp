/*
Alice, Bob and Candies
Codeforces Round #640 (Div. 4), Problem D
https://codeforces.com/contest/1352/problem/D
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
    int N; cin >> N;
    vector<int>candies(N);
    for(int i = 0;i<N;i++) cin >> candies[i];
    int l = 0, r = N-1, moves = 0, a = 0, b = 0, pre = 0;
    while(true){
        bool done = false;
        int sum = 0;
        if(moves%2==0){ //Alice
            for(;l<=r;l++){
                sum+=candies[l];
                if(sum>pre) break;
            }
            if(sum<=pre) done = true;
            a+=sum;
            l++;
        }else{ //Bob
            for(;r>=l;r--){
                sum+=candies[r];
                if(sum>pre) break;
            }
            if(sum<=pre) done = true;
            b+=sum;
            r--;
        }
        moves++;
        if(l>r||done) break;
        pre = sum;
    }
    cout << moves << sp << a << sp << b << nl;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while(T--){
        solve();
    }
    return 0;
}