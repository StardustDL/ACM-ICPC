/*
Fast Food
题意：n个加工厂，m个原料厂，原料厂地址与加工厂一致，m<=n，求最佳分配，使得每个加工厂到达与它最近的那个原料厂，且使得总距离最小。
分析：dp[i][j]为前i个厂，j个原料厂最佳分配的总代价。另外，对于加工厂区间[a,b]用原料厂去覆盖的方法应该是建立在最中间那个点上，这样左右工厂数相等，到达它的距离之和最小。
	  dp[i][j]=min(dp[k][j-1]+ds[k+1][i])，厂址位置就在(k+1+i)/2位置，可以用pre[i][j]记录该原料厂相关的区间的左端点，最后再算一下就行了。
	  因为没有将ds数组清零，WA好几次 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<vector>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=200;
int ds[MAXN+3][MAXN+3],opt[MAXN+3][MAXN+3],pre[MAXN+3][MAXN+3],n,k,d[MAXN+3];
struct Ans{
	int depot,from,to;
	Ans(int d,int f,int t):depot(d),from(f),to(t){}; 
	bool operator<(const Ans &ne)const{  
        return depot<ne.depot;  
    } 
};
vector<Ans> vs;
bool input(){
	scanf("%d%d",&n,&k);
	if(n==0&&k==0)return false;
	for(int i=1;i<=n;i++)scanf("%d",&d[i]);
	d[n+1]=INF;d[0]=-INF;
	memset(ds,0,sizeof(ds));
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int t=d[(i+j)>>1],l=i,r=j,&a=ds[i][j];
			while(l<=r)a+=abs(t-d[l++]);
		}
	}
	return true;
}
void dp(){
	memset(opt,INF,sizeof(opt));
	memset(pre,-1,sizeof(pre));
	for(int i=1;i<=n;i++)
		opt[i][1]=ds[1][i];
	for(int i=2;i<=n;i++)
		for(int j=2;j<=k;j++)
			for(int e=1,tp;e<i;e++)
				if(opt[i][j]>(tp=opt[e][j-1]+ds[e+1][i]))
					opt[i][j]=tp,pre[i][j]=e;
	vs.clear();
	for(int i=n,j=k,e;j!=0;){
		e=pre[i][j];if(e==-1)e=0;
		vs.push_back(Ans((e+i+1)>>1,e+1,i));
		i=e;j--;
	}
	sort(vs.begin(),vs.end());
}
void output(){
	for(int i=0;i<vs.size();i++){  
		printf("Depot %d at restaurant %d serves restaurant",i+1,vs[i].depot);  
		if(vs[i].from==vs[i].to) printf(" %d\n",vs[i].from);
		else printf("s %d to %d\n",vs[i].from,vs[i].to);
    }  
    printf("Total distance sum = %d\n\n",opt[n][k]); 
}
int main(){
	int kase=0;
	while(input()){
		printf("Chain %d\n",++kase);
		dp();
		output();
	}
	return 0;
}
