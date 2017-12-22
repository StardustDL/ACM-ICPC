#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=500,MAXM=100000;
int N,M;
int v[MAXN+3],w[MAXN+3];
int dp[MAXM+3];
int main(){
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>v[i]>>w[i];
    }
    for(int i=1;i<=N;i++)
        for(int j=M;j>=v[i];j--)
            dp[j]=max(dp[j-v[i]]+w[i],dp[j]);
    cout<<dp[M]<<endl;
    return 0;
}