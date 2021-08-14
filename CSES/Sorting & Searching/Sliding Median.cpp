//Problem: https://cses.fi/problemset/task/1076/

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
const ll MODll = 4000004479;
const int MAXN = 2e5+5;
int N, K, x[MAXN], len_bot, len_top;
multiset<int>bot, top;
void add(int v){
    if(*(--bot.end())<v) top.insert(v);
    else bot.insert(v);
    while(top.size()>len_top){
        bot.insert(*top.begin());
        auto t = top.find(*top.begin());
        top.erase(t);
    }
    while(bot.size()>len_bot){
        top.insert(*(--bot.end()));
        auto t = bot.find(*(--bot.end()));
        bot.erase(t);
    }
}
void del(int v){
    if(top.find(v)!=top.end()) top.erase(top.find(v));
    else bot.erase(bot.find(v));
    if(bot.empty()){
        bot.insert(*top.begin());
        auto t = top.find(*(top.begin()));
        top.erase(t);
    }
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N >> K;
    len_bot = (K+1)/2, len_top = K/2;
    vector<int>t;
    for(int i = 0;i<N;i++){
        cin >> x[i];
        if(i<K) t.push_back(x[i]);
    }
    if(K==1){
        for(int i = 0;i<N;i++) cout << x[i] << sp;
        return 0;
    }
    sort(t.begin(), t.end());
    for(int i = 0;i<K;i++){
        if(i<len_bot) bot.insert(t[i]);
        else top.insert(t[i]);
    }
    cout << *(--bot.end()) << sp;
    for(int i = K;i<N;i++){
        del(x[i-K]);
        add(x[i]);
        cout << *(--bot.end()) << sp;
    }
    return 0;
}