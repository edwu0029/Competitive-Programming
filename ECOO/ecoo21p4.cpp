//Problem: https://dmoj.ca/problem/ecoo21p4

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
const int MAXN = 1e6+5;
ll K, tot;
bool sieve[MAXN];
vector<ll>primes, factors;
void primesieve(){
    for(ll i = 2;i<1LL*MAXN;i++){
        if(sieve[i]) continue;
        primes.push_back(1LL*i);
        for(ll j = i*i;j<1LL*MAXN;j+=i) sieve[j] = true;
    }
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    primesieve();
    cin >> K;
    K++;
    for(ll i:primes){
        if(K==1||i>K) break;
        if(K%i!=0) continue;
        while(K%i==0){
            factors.push_back(i);
            tot+=i-1;
            K/=i;
        }
    }
    if(tot>1LL*100000||K!=1){
        cout << "Sad Chris" << nl;
        return 0;
    }
    int cnt = 0;
    cout << tot << nl;
    for(ll i:factors){
        cnt++;
        for(ll j = 1;j<=i-1;j++){
            cout << cnt << sp;
        }
    }
    cout << nl;
    return 0;
}