//Problem: https://dmoj.ca/problem/ccc14s4

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
const int MAXN = 1e3+5, LOG = 16;
int N, T, in[5][MAXN], diff[2*MAXN][2*MAXN];
vector<int> xf2, yf2;
ll ans;
map<int, int>xs, ys;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    for(int i = 0, x1, x2, y1, y2, t;i<N;i++){
        cin >> x1 >> y1 >> x2 >> y2 >> t;
        in[0][i]=x1; in[1][i]=y1; in[2][i]=x2; in[3][i]=y2; in[4][i]=t;
        xs[x1]=1; xs[x2]=1;
        ys[y1]=1; ys[y2]=1;
    }
    int tmpx = 1;
    for(auto &i:xs){
        i.second = tmpx++;
        xf2.push_back(i.first);
    }
    int tmpy = 1;
    for(auto &i:ys){
        i.second = tmpy++;
        yf2.push_back(i.first);
    }
    for(int i = 0, x1, y1, x2, y2, t;i<N;i++){
        x1=in[0][i]; y1=in[1][i]; x2=in[2][i]; y2=in[3][i]; t=in[4][i];
        x1 = xs[x1]; y1 = ys[y1]; x2 = xs[x2]; y2 = ys[y2];
        diff[x1][y1]+=t;
        diff[x1][y2]-=t;
        diff[x2][y1]-=t;
        diff[x2][y2]+=t;
    }
    for(int i = 1;i<tmpx;i++){
        for(int j = 1;j<tmpy;j++){
            diff[i][j]+=diff[i-1][j] + diff[i][j-1] - diff[i-1][j-1];
            if(diff[i][j]>=T){
                ans+=1LL*(xf2[i]-xf2[i-1])*(yf2[j]-yf2[j-1]);
            }
        }
    }
    cout << ans << nl;
    return 0;
}