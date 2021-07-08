//Problem: https://cses.fi/problemset/task/1070/

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
#define mp(a, b) make_pair(a, b)
#define EPS 1e-9
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ll MODll = 4000004479;
const int MAXN = 2e5+5;
int N;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    if(1<N&&N<=3){
        cout << "NO SOLUTION" << nl;
        return 0;
    }
    vector<int>even, odd;
    for(int i = 1;i<=N;i++){
        if(i%2==0){
            even.push_back(i);
        }else{
            odd.push_back(i);
        }
    }
    for(int i:even){
        cout << i << sp;
    }
    for(int i:odd){
        cout << i << sp;
    }
    cout << nl;
    return 0;
}