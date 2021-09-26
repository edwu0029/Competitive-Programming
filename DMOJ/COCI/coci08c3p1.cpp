/*
Pet
COCI '08 Contest 3 #1
https://dmoj.ca/problem/coci08c3p1
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
int F[5], maxp, ind, total, x;
int main(){
    for(int i = 0;i<5;i++){
        total = 0;
        for(int j = 0;j<4;j++){
            scanf("%d",&x); total+=x;
        }
        F[i]=total;
    }
    for(int i = 0;i<5;i++){
        if(maxp<F[i]){maxp=F[i]; ind = i;}
    }
    cout << ind+1 << " " << maxp << nl;
    return 0;
}