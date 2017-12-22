/*
[HAOI2006]均分数据
分析：模拟退火，每次尝试将一个数分到另一个组，检查答案，多做几次 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN=20,INF=0x3f3f3f3f;
int n,m,a[MAXN+3],pos[MAXN+3];
double ans=1e30,ave=0,sum[MAXN+3]; 
#define sqr(x) ((x)*(x))
double solve(){
	memset(sum,0,sizeof(sum));
	double res=0,T=10000;
	for(int i=1;i<=n;i++)
		pos[i]=rand()%m+1,sum[pos[i]]+=a[i];
	for(int i=1;i<=m;i++)res+=sqr(sum[i]-ave);
	//cout<<res<<endl;
	while(T>0.1){
		T*=0.9;int t=rand()%n+1,x=pos[t],y=rand()%m+1;
		if(T>500)y=min_element(sum+1,sum+m+1)-sum;
		if(x==y)continue;
		double ta=res;
		//cout<<ta<<endl;
		ta-=sqr(sum[x]-ave)+sqr(sum[y]-ave);
		sum[x]-=a[t];sum[y]+=a[t];
		ta+=sqr(sum[x]-ave)+sqr(sum[y]-ave);
		if(ta<res || rand()%10000<T)res=ta,pos[t]=y;//接受的条件，注意是< 
		else{sum[x]+=a[t];sum[y]-=a[t];}//不接受，记着改回去 
	}
	return res; 
}
int main(){
	srand(20160312);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);ave+=a[i];
	}
	random_shuffle(a+1,a+n+1);
	ave/=m;
	for(int i=1;i<=10000;i++)ans=min(ans,solve());
	//cout<<ans<<endl<<m<<endl;
	printf("%.2lf\n",sqrt(ans/m));
	return 0;
}

