//Problem: https://dmoj.ca/problem/dmopc19c3p3

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 150001;
int N, pre[MAXN], bit[3*MAXN];
long long sum = 0;
void update(int index, int val){
    for(int i = index;i<3*MAXN;i+=(i&-i)){
        bit[i]+=val;
    }
}
long long query(int index){
    long long sum = 0;
    for(int i = index;i>0;i-=(i&-i)){
        sum+=bit[i];
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    cin >> N;
    for(int i = 1, a;i<=N;i++){
        cin >> a;
        pre[i]+=pre[i-1];
        if(a==2){
            pre[i]--;
        }else{
            pre[i]++;
        }
    }
    update(N, 1);
    for(int i = 1;i<=N;i++){
        update(N+pre[i], 1);
        sum+=query(N+pre[i]-1);
    }
    cout << sum << '\n';
}
