//Problem: https://dmoj.ca/problem/ccc13s1

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
int Y;
bool check(int year){
    vector<bool>digits(10);
    string y = to_string(year);
    for(int i = 0, x;i<y.size();i++){
        x = y[i]-'0';
        if(digits[x]) return false;
        digits[x] = true;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> Y;
    int year = Y+1;
    while(!check(year)){
        year++;
    }
    cout << year << nl;
    return 0;
}