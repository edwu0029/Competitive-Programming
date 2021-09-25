/*
Roll the Dice
Canadian Computing Competition: 2006 Stage 1, Junior #2
https://dmoj.ca/problem/ccc06j2
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
int M, N, ans;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> M >> N;
    for(int i = 1;i<=M;i++){
        for(int j = 1;j<=N;j++){
            if(i+j==10){
                ans++;
            }
        }
    }
    if(ans==1) cout << "There is 1 way to get the sum 10." << nl;
    else cout << "There are " << ans << " ways to get the sum 10." << nl;
    return 0;
}