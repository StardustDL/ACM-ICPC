/*
[SCOI2005]互不侵犯King
分析： 状压DP，预处理下状态转移，减小状态数 
*/
#include <iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
const int MAXN=9+1;
using namespace std;
int num,n,m;
int zt[1<<MAXN],gs[1<<MAXN];
long long dp[MAXN+1][1<<MAXN+1][MAXN*MAXN+3];
bool map[1<<MAXN][1<<MAXN];
bool check(int x,int y){
    if(x&(y<<1))return false;
    if(x&(y>>1))return false;
    if(x&y)return false;
    return true;
}
bool judge(int x){
    if(x&(x<<1))return false;
    if(x&(x>>1))return false;
    return true;
}
int count(int x){
    int res=0;
    while(x){
        if(x&1) res++;
        x>>=1;
    }
    return res;
}
long long solve(){
    dp[0][1][0]=1LL;
    for(int i=0;i<n;i++)
        for(int j=1;j<=num;j++)
            for(int k=0;k<=m;k++)
                if(dp[i][j][k])
                    for(int p=1;p<=num;p++)
                        if(map[j][p]&&k+gs[p]<=m)
                            dp[i+1][p][k+gs[p]]+=dp[i][j][k];
    long long sum=0;
    for(int i=1;i<=num;i++)
        sum+=dp[n][i][m];
    return sum;
}
int main(){
    scanf("%d%d",&n,&m);
    int sum=(1<<n)-1;
    for(int i=0;i<=sum;i++)
        if(judge(i)){
            zt[++num]=i;
            gs[num]=count(i);
        }
    for(int i=1;i<=num;i++)
        for(int j=i;j<=num;j++)
            if(check(zt[i],zt[j]))
                map[j][i]=map[i][j]=true;
    printf("%lld\n",solve());
    return 0;
}
