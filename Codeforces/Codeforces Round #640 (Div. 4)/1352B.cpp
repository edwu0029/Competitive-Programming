/*
Same Parity Summands
Codeforces Round #640 (Div. 4), Problem B
https://codeforces.com/contest/1352/problem/B
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
    if(N<K){
        cout << "NO" << nl;
        return;
    }
    if(N%2==0){
        if(K%2==0){
            //Fill with 1s with last element being N-K+1
            cout << "YES" << nl;
            for(int i = 0;i<K-1;i++){
                cout << 1 << sp; 
            }
            cout << N-K+1 << nl;
        }else{
            //If possible, fill with 2s with last element being N-2*(K-1)
            //N-2*(K-1) = N-2K+2
            if(2*K>N){
                cout << "NO" << nl;
            }else{
                cout << "YES" << nl;
                for(int i = 0;i<K-1;i++){
                    cout << 2 << sp;
                }
                cout << N-2*K+2 << nl;
            }
        }
    }else{
        if(K%2==0){
            //Not possible when N is even and K is odd
            cout << "NO" << nl;
        }else{
            //Fill with 1s with last element being N-K+1
            cout << "YES" << nl;
            for(int i = 0;i<K-1;i++){
                cout << 1 << sp; 
            }
            cout << N-K+1 << nl;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int T; cin >> T;
    while(T--){
        solve();
    }
    return 0;
}