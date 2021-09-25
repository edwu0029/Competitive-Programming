/*
Deal or No Deal Calculator
Canadian Computing Competition: 2007 Stage 1, Junior #3
https://dmoj.ca/problem/ccc07j3
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
int N, sum = 1691600, offer;
vector<int>cases = {0, 100 , 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000, 1000000};
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 0, x;i<N;i++){
        cin >> x;
        sum-=cases[x];
    }
    cin >> offer;
    if(N==10||(double)offer-(double)(sum/(10-N))<=EPS) cout << "no deal" << nl;
    else cout << "deal" << nl;
    return 0;
}