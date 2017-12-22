/*
矩形覆盖
分析：首先将点按x升序，y升序排序（这样之后DP就不会出现重叠），
		可以想到，这样排序后，最优解一定是满足覆盖了一段连续的点， 
	  用opt[i][j][k]表示i..j这些点用k个矩形覆盖的最小面积，
	  然后就可以枚举最后一个矩形覆盖了哪些点，进行转移，
	  初值opt[i][i+...][1]=一个矩形全覆盖,opt[i][i]=0 
	  注意要将坐标系转九十度（交换x,y），再做一遍，这是另一种覆盖方法 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=50,INF=0x3f3f3f3f;
struct point{
	int x,y; 
	bool operator <(const point &t)const{
		return x<t.x||x==t.x&&y<t.y;
	}
}ps[MAXN+3];
int n,m,opt[MAXN+3][MAXN+3][9],ans=INF;
int geth(int l,int r){
	int mn=INF,mx=0;
	for(;l<=r;l++){
		mn=min(mn,ps[l].y);
		mx=max(mx,ps[l].y);
	}
	return mx-mn;
}
void input(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&ps[i].x,&ps[i].y);
}
int dp(){
	memset(opt,INF,sizeof(opt));
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			opt[i][j][1]=(ps[j].x-ps[i].x)*geth(i,j);
	for(int i=1;i<=n;i++)
		memset(opt[i][i],0,sizeof(opt[i][i]));
	for(int k=2;k<=m;k++)
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int l=i+1;l<=j;l++)
					opt[i][j][k]=min(opt[i][j][k],opt[i][l-1][k-1]+(ps[j].x-ps[l].x)*geth(l,j));
	return opt[1][n][m];
}
int main(){
	input();
	sort(ps+1,ps+n+1);
	ans=min(ans,dp());
	for(int i=1;i<=n;i++)swap(ps[i].x,ps[i].y);
	sort(ps+1,ps+n+1);
	ans=min(ans,dp());
	printf("%d\n",ans); 
	return 0;
}

