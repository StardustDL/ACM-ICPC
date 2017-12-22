/*
送外卖
分析：作为写的第一道状压DP，过程可谓艰难，方法比较好想，先求任意两点最短路，然后DP
	  但要注意细节：
	  	用opt[i][j]表示在状态i，位于j时的最优解 
	  	首先要赋初值opt[1<<i][i]=mp[0][i],else opt[x][y]=INF
	  	然后要预处理出含有i个1的状态集合：state[i]={状态1，状态2，...}
		这一步很重要，因为之后的DP必须要从1少的转移到1多的，而不能随意转移。
		第一次写错就是因此：
	for(int u=1;u<=n;u++){//错误代码 
		for(int i=0;i<mx;i++){
			for(int v=1;v<=n;v++){
				if(u==v)continue;
				if((i&(1<<(u-1))==0)||(i&(1<<(v-1))==1))continue;
				opt[i|(1<<(v-1))][v]=min(opt[i|(1<<(v-1))][v],opt[i][u]+mp[u][v]);
			}
		}
	}
		然后枚举1的个数，枚举满足的所有状态，枚举起点，终点，注意状态还必须满足已到达起点和未到达终点。 
		转移就很简单了：opt[状态i∪点v][v]=min{opt[状态i][u]+mp[u][v]}
		最后由于要回到起点，还要再枚举所有终状态中的最优解。 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=15,INF=1<<30;
int mp[MAXN+3][MAXN+3],n,opt[1<<17][MAXN+3],state[MAXN+3][1<<17],num[MAXN+3];
void floyd(){
	for(int k=0;k<=n;k++){
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
			}
		}
	}
}
int dp(){
	int mx=1<<n;
	for(int i=0;i<=(1<<(n+1));i++)  
            for(int j=0;j<=n+1;j++)  
                  opt[i][j]=INF;  
    for(int i=0;i<mx;i++)  
    {  
		int tot=0;  
        for(int j=0;j<n;j++)if((1<<j)&i)tot++;  
        state[tot][++num[tot]]=i;              
    } 
	for(int i=1;i<=n;i++)opt[1<<(i-1)][i]=mp[0][i];
	for(int i=1;i<n;i++)  
        for(int l=1;l<=num[i];l++)  
			for(int j=1;j<=n;j++)  
            {
                if(!((1<<(j-1))&state[i][l]))continue;
                for(int k=1;k<=n;k++)  
                {
					if(!((1<<(k-1))&state[i][l]))  
						opt[(state[i][l]+(1<<(k-1)))][k]=min(opt[(state[i][l]+(1<<(k-1)))][k],opt[state[i][l]][j]+mp[j][k]);  
				}
            }
	int ans=INF;
	for(int i=1;i<=n;i++){
		ans=min(ans,opt[mx-1][i]+mp[i][0]);
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++)cin>>mp[i][j];
	}
	floyd();
	cout<<dp();
	return 0;
} 
