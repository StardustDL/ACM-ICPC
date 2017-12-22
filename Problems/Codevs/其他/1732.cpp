/*
Fibonacci数列 2
分析：同1250 
*/
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
const ll MOD=1000000007; 
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
MS jzc(MS a,MS b){
	MS c=MS(a.n,b.m);
	for(int i=1;i<=a.n;i++)
		for(int j=1;j<=b.m;j++){
			c.data[i][j]=0;
			for(int k=1;k<=a.m;k++)
				c.data[i][j]=(c.data[i][j]+a.data[i][k]*b.data[k][j])%MOD;
		}
	return c;
}
MS ksm(MS a,ll b){
	MS ans=MS(a.n,a.m);
	for(int i=1;i<=4;i++)ans.data[i][i]=1;
	while(b>0){
		if(b&1)ans=jzc(ans,a);
		b>>=1;
		a=jzc(a,a);
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
	while(cin>>n){
		if(n==1||n==2){
			cout<<1<<endl;continue; 
		} 
		MS t1=ksm(con,n-2);
		MS t2=jzc(start,t1);
		printf("%d\n",t2.data[1][1]);
	}
	return 0;
}
