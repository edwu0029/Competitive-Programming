//Problem: https://dmoj.ca/problem/dmopc20c2p1

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
const int MAXN = 2005;
int N, curr, curc, minr, maxr, minc, maxc;
string n;
char gr[MAXN][MAXN];
void upd(){
    minr = min(minr, curr); maxr = max(maxr, curr);
    minc = min(minc, curc); maxc = max(maxc, curc);
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> n;
    curr = curc = 1001;
    minr = minc = 0x3f3f3f3f;
    maxr = maxc = 0;
    for(int i = 0;i<N;i++){
        if(n[i]=='>'){
            gr[curr][curc] = '_';
            upd();
            curc++;
        }else if(n[i]=='^'){
            gr[curr][curc] = (char)(47);
            upd();
            curc++;
            curr--;
        }else{
            curr++;
            gr[curr][curc] = (char)(92);
            upd();
            curc++;
        }
    }
    for(int i = minr;i<=maxr;i++){
        for(int j = minc;j<=maxc;j++){
            if(gr[i][j]==0) cout << '.';
            else cout << gr[i][j];
        }
        cout << nl;
    }
    return 0;
}