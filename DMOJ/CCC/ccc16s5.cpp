//Problem: https://dmoj.ca/problem/ccc16s5

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
const int MAXN = 1e5+5, LOG = 16;
int N, A[MAXN], B[MAXN];
ll T;
string g;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> T >> g;
    for(int i = 0;i<N;i++){
        A[i]=g[i]-'0';
    }
    for(int i = 60, p1, p2;i>=0;i--){
        if(T&((1LL)<<i)){
            p1 = ((1LL)<<i)%N;
            p2 = N-p1;
            for(int j = 0, p3, p4;j<N;j++){
                p3 = (j+p1)%N, p4 = (j+p2)%N;
                B[j]=A[p3]^A[p4];
            }
            swap(A, B);
        }
    }
    for(int i = 0;i<N;i++){
        cout << A[i];
    }
    cout << noboolalpha;
    return;
}