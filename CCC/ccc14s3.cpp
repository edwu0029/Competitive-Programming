//Problem: https://dmoj.ca/problem/ccc14s3

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
int T, N, cur;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> T;
	for(int cnt = 0;cnt<T;cnt++){
		cin >> N;
		cur = 1;
		stack<int>t, b;
		for(int i = 0;i<N;i++){
			int tmp; cin >> tmp;
			t.push(tmp);
		}
		for(int i = 0;i<2*N;i++){
			if(cur==N+1)break;
			if(!t.empty()&&t.top()==cur){
				t.pop(); cur++;
			}else if(!b.empty()&&b.top()==cur){
				b.pop(); cur++;
			}else if(t.empty()&&b.top()!=cur){
				break;
			}else{
				b.push(t.top()); t.pop();
			}
		}
		if(cur==N+1){
            cout << "Y" << nl;
        }else{
            cout << "N" << nl;
        }
	}
    return 0;
}