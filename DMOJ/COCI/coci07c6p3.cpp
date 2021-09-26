/*
Granica
COCI '07 Contest 6 #3
https://dmoj.ca/problem/coci07c6p3
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
int N, F[105], g;
vector<int>v;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> F[i];
    }
    sort(F, F+N);
    g = F[1]-F[0];
    for(int i = 1;i<N;i++){
        g=__gcd(g, F[i]-F[i-1]);
    }
    v.push_back(g);
    for(int i = 2;i*i<=g;i++){
        if(g%i==0){
            v.push_back(i);
            if((g/i)!=i){
                v.push_back(g/i);
            }
        }
    }
    for(int i = 0;i<v.size();i++){
        if(i==v.size()-1) cout << v[i] << '\n';
        else cout << v[i] << " ";
    }
    return 0;
}