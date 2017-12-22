/*
Bugs Integrated, Inc.
题意：将 2*3 的芯片嵌入 n行m列 的单位尺寸模板中，模板上面有一些坏点将被标记出，求最大的芯片数量。m<=10
分析：注意每一行的信息与上两行有关，用三进制表示状态，
	  	1.a[x] = 0  表示方格（x-1,y）空闲，方格（x-2,y）空闲
		2.a[x] = 1  表示方格（x-1,y）空闲，方格（x-2,y）被占据
		3.a[x] = 2, 表示方格（x-1,y）被占据 
	  这样就可以转移了，注意坏点：dfs时同时记录上一行的状态（其实包含了上两行的信息），和这一行的什么都没放状态（包含了这一行的坏点和上一行的填法信息）
	  决策有两种：横着放，竖着放 
	  三进制状态压缩的实现：无法用位运算，先预处理3的幂，然后模拟即可，注意要有状态信息的解压和压缩 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f;
int tpow[15],opt[2][60003],p[15],q[12],mp[150+3][15],ans=0,m,n,cur;
void loadtpow(){tpow[0]=1;for(int i=1;i<=11;i++)tpow[i]=tpow[i-1]*3;}
int qstate(int *p,int *q,int i,int j){
	//cout<<j<<":"<<endl;
	int res=0;memset(p,0,sizeof(p));memset(q,0,sizeof(q));
	/*for(int k=1,t=j;k<=m&&t;k++,t/=3)cout<<(p[k]=t%3)<<" ";//这两种写法有什么区别，上面的这种直接WA 
	puts("");
	for(int k=1;k<=m;k++,j/=3)cout<<(p[k]=j%3)<<" ";
	puts("");*/
	for(int k=1;k<=m;k++,j/=3)p[k]=j%3;
	for(int k=1;k<=m;k++){
		if(mp[i][k])q[k]=2;
		else if(p[k]==2)q[k]=1;
		else if(p[k]<2)q[k]=0;
		res+=tpow[k-1]*q[k];
	}
	//cout<<res<<endl;
	return res;
}
void dfs(int now,int y,int r){
	ans=max(now,ans);
	if(y+1<=m&&p[y]+p[y+1]+q[y]+q[y+1]==0){//放入3行2列的 
		q[y]=q[y+1]=2;
		int nxt=r+tpow[y-1]*2+tpow[y]*2;
		opt[cur][nxt]=max(opt[cur][nxt],now+1);
		dfs(now+1,y+2,nxt);
		q[y]=q[y+1]=0;
	}
	if(y+2<=m&&q[y]+q[y+1]+q[y+2]==0){//放入2行3列的
		q[y]=q[y+1]=q[y+2]=2;
		int nxt=r+tpow[y-1]*2+tpow[y]*2+tpow[y+1]*2;
		opt[cur][nxt]=max(opt[cur][nxt],now+1);
		dfs(now+1,y+3,nxt);
		q[y]=q[y+1]=q[y+2]=0;
	}
	opt[cur][r]=max(opt[cur][r],now);
	if(y+1<=m)dfs(now,y+1,r);
}
int main(){
	int T;scanf("%d",&T);loadtpow();//cout<<tpow[4]<<endl;
	while(T--){
		int k,a,b,st=0;memset(mp,0,sizeof(mp));
		scanf("%d%d%d",&n,&m,&k);
		while(k--){
			scanf("%d%d",&a,&b);mp[a][b]=1;
		}
		//cout<<mp[1][m]<<endl;
		for(int i=0;i<m;i++)if(mp[1][i+1])st+=tpow[i]*2;else st+=tpow[i];
		//cout<<st<<endl;
		cur=0;memset(opt,-1,sizeof(opt));ans=0;opt[cur][st]=0;
		for(int i=2;i<=n;i++){
			cur^=1;memset(opt[cur],-1,sizeof(opt[cur]));
			for(int j=0;j<tpow[m];j++){
				if(opt[cur^1][j]==-1)continue;
				dfs(opt[cur^1][j],1,qstate(p,q,i,j));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

