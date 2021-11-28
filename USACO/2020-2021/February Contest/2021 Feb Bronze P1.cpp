/*
Year of the Cow
USACO 2021 February Contest, Bronze, Problem 1
http://usaco.org/index.php?page=viewproblem2&cpid=1107
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
const int MAXN = 105;
int N, cnt, rel_yr[MAXN];
string b_yr[MAXN];
map<string, int>order, m;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    //Ox, Tiger, Rabbit, Dragon, Snake, Horse, Goat, Monkey, Rooster, Dog, Pig, Rat
    order["Ox"] = 0;
    order["Tiger"] = 1;
    order["Rabbit"] = 2;
    order["Dragon"] = 3;
    order["Snake"] = 4;
    order["Horse"] = 5;
    order["Goat"] = 6;
    order["Monkey"] = 7;
    order["Rooster"] = 8;
    order["Dog"] = 9;
    order["Pig"] = 10;
    order["Rat"] = 11;
    m["Bessie"] = ++cnt;
    b_yr[1] = "Ox";
    cin >> N;
    for(int i = 0;i<N;i++){
        string n1, n2, dir, yr;
        cin >> n1;
        cin >> dir >> dir >> dir;
        cin >> yr;
        cin >> n2 >> n2 >> n2;
        if(!m[n1]) m[n1] = ++cnt;
        b_yr[m[n1]] = yr;
        int a = order[yr], b = order[b_yr[m[n2]]];
        if(dir=="previous"){
            if(a==b){
                rel_yr[m[n1]] = rel_yr[m[n2]]-12;
            }else if(a<b){
                rel_yr[m[n1]] = rel_yr[m[n2]]-(b-a);
            }else{
                rel_yr[m[n1]] = rel_yr[m[n2]]-12+(a-b);
            }
        }else{
            if(a==b){
                rel_yr[m[n1]] = rel_yr[m[n2]]+12;
            }else if(a<b){
                rel_yr[m[n1]] = rel_yr[m[n2]]+12-(b-a);
            }else{
                rel_yr[m[n1]] = rel_yr[m[n2]]+(a-b);
            }
        }
    }
    cout << abs(rel_yr[m["Elsie"]]) << nl;
    return 0;
}