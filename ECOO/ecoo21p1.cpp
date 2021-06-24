//Problem: https://dmoj.ca/problem/ecoo21p1

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
#define pb push_back
#define EPS 1e-9
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7, MODll = 4000004479, SEED = 131;
const int MAXN = 1e5+2, LOG = 16;
int H, I, M;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> H >> I >> M;
    if(M<=H+I){
        cout << H+I << nl;
    }else if(M<=H+I+I){
        cout << H+I+I << nl;
    }else if(M<=H+I+I+I){
        cout << H+I+I+I << nl;
    }else{
        cout << "Who knows..." << nl;
    }
    return 0;
}
