/*
Fibonacci数列 2
分析：矩阵乘+快速幂，由递推式可得矩阵 
*/
#include<cstdio>
#include<cstring>
using namespace std;
typedef int ll;
struct MS{
	ll data[5][5];
	int n,m;
	MS(int n,int m){
		this->n=n;
		this->m=m;
		memset(data,0,sizeof(data)); 
	}
	MS(){
		memset(data,0,sizeof(data)); 
	}
};
MS con=MS(2,2),start=MS(1,2);
void pri(MS m){
	for(int i=1;i<=m.n;i++){
		for(int j=1;j<=m.m;j++)
			printf("%lld ",m.data[i][j]);
		printf("\n");
	}
	printf("\n");
}
MS jzc(MS a,MS b,ll mod){
	MS c=MS(a.n,b.m);
	for(int i=1;i<=a.n;i++)
		for(int j=1;j<=b.m;j++){
			c.data[i][j]=0;
			for(int k=1;k<=a.m;k++)
				c.data[i][j]=(c.data[i][j]+a.data[i][k]*b.data[k][j])%mod;
		}
	return c;
}
MS ksm(MS a,ll b,ll mod){
	MS ans=MS(a.n,a.m);
	for(int i=1;i<=4;i++)ans.data[i][i]=1;
	while(b>0){
		if(b&1)ans=jzc(ans,a,mod);
		b>>=1;
		a=jzc(a,a,mod);
	}
	return ans;
}
int main(){
	con.data[1][1]=1;
	con.data[1][2]=1;
	con.data[2][1]=1;
	con.data[2][2]=0;
	start.data[1][1]=1;
	start.data[1][2]=1;
	ll n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int p,q;
		scanf("%d %d",&p,&q);
		MS t1=ksm(con,p-1,q);
		MS t2=jzc(start,t1,q);
		printf("%d\n",t2.data[1][1]);
	}
	return 0;
}
