/*
Duty Free Shop
题意：两种物品，放到n个盒子，要求所有盒子放满，且每个盒子只有一种物品，物品可以有剩余
分析：将盒子视为物品，第一种物品为背包大小，进行DP并且记录路径，回溯可得放第一种物品的最优方案（目的是为了是放第二种物品的盒子总容积尽可能小），最后在判断一下就行了。 
*/
#include<iostream>
using namespace std;
int M,L,c[1010],dp[1010],n,pre[1010],sum,ans;
bool v[1010];
void dfs(int j){
     if(j==0)return;
     v[pre[j]]=0;
     dfs(j-c[pre[j]]);
}
int main(){
    while(scanf("%d%d",&M,&L)){
		if(M==0&&L==0)break;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&c[i]);
            v[i]=1;
        }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            for(int j=M;j>=c[i];j--)
                if(dp[j]<dp[j-c[i]]+c[i]){
                   dp[j]=dp[j-c[i]]+c[i];
                   pre[j]=i;
                }
        dfs(dp[M]);
        sum=0;
        ans=n;
        for(int i=1;i<=n;i++)
            if(v[i]==1){sum+=c[i];ans--;}
        if(sum<=L){
			printf("%d",ans);
    		for(int i=1;i<=n;i++)
				if(v[i]==0)printf(" %d",i);
			printf("\n");
        }
        else printf("Impossible to distribute\n");
    }
    return 0;
}


