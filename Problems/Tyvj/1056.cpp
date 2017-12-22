#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100,INF=1<<30;
int w[MAXN*2+3],n,opt[MAXN*2+3][MAXN*2+3];
inline void read(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>w[i];
		w[i+n]=w[i];
	}
}
int dp(){
	int l=2*n;
	for(int len=2;len<=l;len++){
		for(int i=1;i<=l-len+1;i++){
			//注意此题的特点：w[i]与w[i+1]表示珠子i的信息 
			int j=i+len,s=w[i]*w[j];
			int &t=opt[i][j];
			for(int k=i+1;k<j;k++){
				t=max(t,opt[i][k]+opt[k][j]+s*w[k]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,opt[i][i+n]);
	return ans;
}
int main(){
	read();
	cout<<dp();
	return 0;
}
