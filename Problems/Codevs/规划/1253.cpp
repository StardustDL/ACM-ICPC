/*
超级市场
分析：注意两个菜单都是有序的，所以opt[i][j]表示市场中前i种菜，已经买了前j种菜的最优解，
	  对每个菜有买和不买两种，而买是有条件的：刚好是当前要买的菜。
	  先写出了由opt[i][j]转移到opt[i+1][j]和opt[i+1][j+1]的方程，但这样不方便设计边界 
	  所以改了一下方程，边界是opt[0][0]=0,opt[0][1..m]=INF 
*/
#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<algorithm>
using namespace std;
const int MAXN=100000,MAXM=100,INF=0x3f3f3f3f;
struct vegt{
	int k;double p;
};
bitset<MAXN+3> exi;
int m,n,x[MAXM+3];
double opt[MAXN+3][MAXM+3];
vector<vegt> vs;
void input(){
	cin>>m>>n;exi=0;int k;double p;
	for(int i=1;i<=m;i++){
		cin>>x[i];exi[x[i]]=1;
	}
	vs.push_back((vegt){0,0});bool flg=true;
	for(int i=1;i<=n;i++){
		cin>>k>>p;
		if(flg&&k!=x[1])continue;
		else flg=false;
		if(exi[k])vs.push_back((vegt){k,p});
	}
}
double dp(){
	opt[0][0]=0;
	for(int i=0;i<vs.size();i++)for(int j=1;j<=m;j++)opt[i][j]=INF;
	for(int i=1;i<vs.size();i++){
		for(int j=1;j<=min(i,m);j++){
			opt[i][j]=min(opt[i-1][j],vs[i].k==x[j]?(opt[i-1][j-1]+vs[i].p):INF);
			/*opt[i+1][j+1]=min(opt[i+1][j+1],opt[i][j]+vs[i].p);
			opt[i+1][j]=min(opt[i+1][j],opt[i][j]);*/
		}
	}
	double ans=INF;
	for(int i=m;i<vs.size();i++)
		ans=min(ans,opt[i][m]);
	return ans;
}
int main(){
	input();
	double ans=dp();
	if(ans==INF)printf("Impossible");
	else printf("%.2lf",ans);
	return 0;
}
