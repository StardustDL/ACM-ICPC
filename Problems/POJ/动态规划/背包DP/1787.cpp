/*
Charlie's Change
题意：有四种硬币，1分，5分，10分，25分，分别有a,b,c,d种，给出一个n分钱，要求你求出组成n分钱最多需要的硬币数量，并且输出组成它的各种硬币的数量
分析：由于是求数量，即每个物品的价值是相同的（都是1），所以可以不用多重背包，用完全背包加计数器即可，类似于可行性判断，注意不能套可行性判断的代码，必须维护个数大小才可以保证最优 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<bitset>
using namespace std;
const int MAXN=10000;
int ans[26],num[MAXN+3],path[MAXN+3],opt[MAXN+3];
int p,c[5]={0,1,5,10,25},t[5];
int main(){
    while(scanf("%d %d %d %d %d",&p,&t[1],&t[2],&t[3],&t[4])>0,(p+t[1]+t[2]+t[3]+t[4])){
        memset(opt,0,sizeof(opt));
        memset(ans,0,sizeof(ans));
        memset(path,0,sizeof(path));
        opt[0]=1;
        for(int i=1;i<=4;i++){
            memset(num,0,sizeof(num));
            for(int j=c[i];j<=p;j++)
	           	if(opt[j-c[i]]&&opt[j-c[i]]+1>opt[j]&&num[j-c[i]]<t[i]){   //一般来说，完全背包的硬币是没有限制的，后一个数必然可以由前面的某个数组成，所以也就不需要dp[j-c[i]]>0，但是，这次用到的完全背包其硬币数受到了限制，也就导致有些数根本不可能组成，所以要把这些数排除
	            	opt[j]=opt[j-c[i]]+1;
	                num[j]=num[j-c[i]]+1;
	                path[j]=j-c[i];
	            }
        }
        int i=p;
        if(opt[p]){
            while(i!=0){
                ans[i-path[i]]++;
                i=path[i];
            }
            printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n",ans[1],ans[5],ans[10],ans[25]);
        }
        else  printf("Charlie cannot buy coffee.\n");
    }
    return 0;
}
