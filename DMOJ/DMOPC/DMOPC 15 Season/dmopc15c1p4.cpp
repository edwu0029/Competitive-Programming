/*
Itami and Candy
DMOPC '15 Contest 1 P4
https://dmoj.ca/problem/dmopc15c1p4
*/

#include <bits/stdc++.h>
using namespace std;
bool sieve[148735];
vector<int>primes;
int N, X, ans, tmp;
int main(){
    scanf("%d%d",&N,&X);
    for(int i = 2;i<148735;i++){
        if(!sieve[i]){
            primes.push_back(i);
            for(int j = i;j<148735;j+=i)sieve[j]=true;
        }
    }
    for(size_t i = 0;i<primes.size();i++){
        if(primes.at(i)>N)break;
        if(N-primes.at(i)>=0){
            ans+=((N-primes.at(i))/X)+1;
        }
        if(N-primes.at(i)-1>=0){
            ans+=((N-primes.at(i)-1)/X)+1;
        }
    }
    printf("%d",ans);
}