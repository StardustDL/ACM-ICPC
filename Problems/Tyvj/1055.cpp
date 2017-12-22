#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=300,INF=1<<32;
int n,m[MAXN+3],sum[MAXN+3],opt[MAXN+3][MAXN+3];
inline void read(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>m[i];
}
void init(){
	sum[0]=0;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+m[i];
	}
	memset(opt,0,sizeof(opt));
}
int dp(){
	for(int len=2;len<=n;len++){
		for(int i=1;i<=n-len+1;i++){
			int j=i+len-1,t=INF;
			for(int k=i;k<j;k++){//但这里是k<j，因为下面会有k+1 
				//注意这里从i开始，因为可以分割成i,i+1..j 
				t=min(t,opt[i][k]+opt[k+1][j]);
			}
			opt[i][j]=t+sum[j]-sum[i-1];
		}
	}
	return opt[1][n];
}
int main(){
	read();
	init();
	cout<<dp();
	return 0;
}
