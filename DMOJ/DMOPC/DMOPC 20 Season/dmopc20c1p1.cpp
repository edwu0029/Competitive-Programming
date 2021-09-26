/*
Victor Gets Quizzed
DMOPC '20 Contest 1 P1
https://dmoj.ca/problem/dmopc20c1p1
*/

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
const int MAXN = 1e6+5, LOG = 16;
int N;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 0;i<N;i++){
        string s; cin >> s;
        int cnt = 0;
        for(int j = 0;j<s.size();j++){
            if(s[j]=='C'||s[j]=='M') cnt++;
        }
        if(cnt==0){
            cout << "PASS" << nl;
        }else if(cnt==1){
            cout << "FAIL" << nl;
        }else{
            cout << "NEGATIVE MARKS" << nl;
        }
    }
    return 0;
}
