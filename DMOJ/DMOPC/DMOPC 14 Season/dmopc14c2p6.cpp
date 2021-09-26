/*
Selective Cutting
DMOPC '14 Contest 2 P6
https://dmoj.ca/problem/dmopc14c2p6
*/

#include <bits/stdc++.h>
using namespace std;
int N, Q, curlen;
long long qans[100001], bit1[100001];
vector<pair<int, int>>trees;
vector<pair<pair<int, int>, pair<int, int>>>queries;
pair<pair<int, int>, pair<int, int>>curq;
void update(int index, int val){
    for(int i = index;i<100001;i+=(i&-i)){
        bit1[i]+=val;
    }
}
long long sum(int index){
    long long r = 0;
    for(int i = index;i>0;i-=(i&-i)){
        r+=bit1[i];
    }
    return r;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 1;i<=N;i++){
        int tmp; cin >> tmp;
        trees.push_back(make_pair(tmp, i));
    }
    cin >> Q;
    for(int i = 1;i<=Q;i++){
        int a, b, q; cin >> a >> b >> q;
        queries.push_back(make_pair(make_pair(q, a), make_pair(b, i)));
    }
    sort(trees.begin(), trees.end());
    sort(queries.begin(), queries.end());
    for(int q = 0;q<Q;q++){
        curq = queries.back(); queries.pop_back();
        curlen = trees.size();
        for(int i = 0;i<curlen;i++){
            if(trees.back().first<curq.first.first){
                break;
            }else{
                update(trees.back().second, trees.back().first);
                trees.pop_back();
            }
        }
        qans[curq.second.second]=sum(curq.second.first+1)-sum(curq.first.second);
    }
    for(int i = 1;i<=Q;i++){
        cout << qans[i] << '\n';
    }
}