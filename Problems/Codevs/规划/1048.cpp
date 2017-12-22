/*
石子归并
分析：区间DP，前缀和预处理，对于每一个区间，枚举划分点。 
*/
#include<iostream>
using namespace std;
const int MAXN=103,INF=1<<30;
int n,w[MAXN],opt[MAXN][MAXN],s[MAXN];
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>w[i];
		s[i]=s[i-1]+w[i];
	}
	for(int len=2;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1,&m=opt[i][j];
			m=INF;
			for(int k=i;k<j;k++){
				m=min(opt[i][k]+opt[k+1][j],m);
			}
			m+=s[j]-s[i-1];
		}
	}
	cout<<opt[1][n];
	return 0;
}
