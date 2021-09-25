/*
Alice Through the Looking Glass
Canadian Computing Competition: 2011 Stage 1, Senior #3
https://dmoj.ca/problem/ccc11s3
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
int T, me;
ll x, y, newY;
ll powerLL(int m){
    ll p = 1;
    for(int i = 0;i<m;i++) p*=5;
    return p;
}
ll calc(int m, long long x){
    if(m==0) return 0;
    ll p = powerLL(m-1); int r = x/p;
    if(r==0||r==4){
        return 0;
    }else if(r==1||r==3){
        return p+calc(m-1,x-r*p);
    }else if(r==2){
        return 2*p+calc(m-1,x-r*p);
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> T;
    for(int i = 0;i<T;i++){
        cin >> me >> x >> y;
        newY = calc(me, x);
        if(y>=newY){
            cout << "empty" << nl;
        }else{
            cout << "crystal" << nl;
        }
    }
    return 0;
}