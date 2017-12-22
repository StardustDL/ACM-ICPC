/*
板猪飞盘队
分析：opt[i][j]表示第i个物品，mod f=j的方案数，则opt[i][j]=sum{opt[l][k]|1<=l<i;k+a[i] % f==j}，可以知道k是唯一的，k=(j-a[i])%f，注意要大于0
	  但上述方程为O(n*f*f)的，会超时1组，注意到sum{opt[1..i-1][k]}是可以用类似前缀和的方法维护的，所以有了改进方法 
*/ 
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2000,MOD=100000000;
int n,f,a[MAXN+3],opt[MAXN+3][1000+3],s[1000+3];
void input(){
	cin>>n>>f;
	for(int i=1;i<=n;i++)cin>>a[i];
}
int get(int x){
	while(x<0)x+=f;
	return x%f;
}
int dp(){
	memset(opt,0,sizeof(opt));memset(s,0,sizeof(s));
	for(int i=1;i<=n;i++)opt[i][a[i]%f]=1;
	for(int i=0;i<f;i++)s[i]=opt[1][i];
	for(int i=2;i<=n;i++){
		for(int j=0;j<f;j++){
			opt[i][j]=(opt[i][j]+s[get(j-a[i])])%MOD;//这里的s[k]实际上是s[1..i-1][k] 
		}
		for(int j=0;j<f;j++)s[j]=(s[j]+opt[i][j])%MOD;//注意，只能在这里改变s，若放到上面的循环中，会影响后面的值判断 
	}
	return s[0];
}
/*int dp(int t){
	memset(opt,0,sizeof(opt));memset(s,0,sizeof(s));
	for(int i=1;i<=n;i++)opt[i][a[i]%f]=1;
	for(int i=2;i<=n;i++){
		for(int j=0;j<f;j++){
			int k=(j-a[i]);while(k<0)k+=f;k%=f;
			for(int l=1;l<i;l++){
				opt[i][j]=(opt[i][j]+opt[l][k])%MOD;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=(ans+opt[i][0])%MOD;
		//cout<<opt[i][0]<<endl;
	}
	return ans;
}*/
int main(){
	input();
	cout<<dp();
	return 0;
}
