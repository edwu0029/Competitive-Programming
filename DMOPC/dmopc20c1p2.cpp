//Problem: https://dmoj.ca/problem/dmopc20c1p2

#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <complex>
#include <iomanip>
#include <cassert>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <cstring>
#include <climits>
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
const ll MOD = 1e9+7;
const ll MODll = 4000004479;
const int MAXN = 1e6+5;
int N, D, F[MAXN];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> D;
    for(int i = 1;i<=N;i++){
        cin >> F[i];
        F[i]+=F[i-1];
    }
    int l = 1, r = N;
    for(int i = 0, n;i<D;i++){
        cin >> n;
        int sum1 = F[l+n-1]-F[l-1], sum2 = F[r]-F[l+n-1];
        if(sum1>=sum2){
            cout << sum1 << nl;
            l = l+n;
        }else{
            cout << sum2 << nl;
            r = l+n-1;
        }
    }
    return 0;
}