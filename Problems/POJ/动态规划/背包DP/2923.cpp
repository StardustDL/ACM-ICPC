/*
Relocation
题意： 有 n 个货物，并且知道了每个货物的重量，每次用载重量分别为c1,c2的火车装载，问最少需要运送多少次可以将货物运完。
分析: 不错的一道题，先状态压缩得到所有“物品”，然后转成背包DP，有没有优化的余地呢？ 
		找出所有状态（1.....(1<<n)-1）中选出可以用两辆车一次运完的状态
        把每个状态都看作一个物品，重量为该状态的总重量，价值为 1
        求解 01 背包，dp[(1<<n)-1]为最优解
        转移方程： dp[stat|j]=min(dp[stat|j],dp[j]+1)  注意 stat 和 j 不能有交集
*/
#include<cstdio>
#include<cstring>
#include<bitset>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=10,INF=0x3f3f3f3f;
int opt[1<<MAXN+1];
vector<int> thing;
bitset<(1<<MAXN+1)> has;
int n,c1,c2,w[MAXN+3],T;
int check(int stat){
    int s=0;has=0;has[0]=1;
    for(int i=0;i<n;i++)
        if((1<<i)&stat){
            s+=w[i];
            if(s>c1+c2)return 0;
            for(int j=c1;j>=w[i];j--)
            	has[j]=has[j]|has[j-w[i]];
        }
    for(int i=0;i<=c1;i++)
        if(s-i<=c2&&has[i])return 1;
    return 0;
}
int main(){
    scanf("%d",&T);
    for(int k=1;k<=T;k++){
        scanf("%d%d%d",&n,&c1,&c2);
        for(int i=0;i<n;i++)scanf("%d",&w[i]);
        thing.clear();
        memset(opt,INF,sizeof(opt));
        opt[0]=0;
        int st=(1<<n)-1;
        for(int i=1;i<=st;i++)
            if(check(i))thing.push_back(i);
        for(int i=0;i<thing.size();i++)
            for(int j=st;j>=0;j--)
                if(opt[j]!=INF&&(!(j&thing[i])))//两个状态不能有交集
                    opt[thing[i]|j]=min(opt[thing[i]|j],opt[j]+1);
        printf("Scenario #%d:\n%d\n\n",k,opt[st]);
    }
    return 0;
}
