/*
放苹果
分析：其实就是将M分成1份，2份，3份，...，N份。所以套用数字划分的代码，最后统计opt[n][1..m]即可。 
*/
#include<iostream>
using namespace std;
const int MAXN=10;
long long opt[MAXN+3][MAXN+3],n,k;
int dp(){
	opt[0][0]=1; 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++)
			if(i>=j)opt[i][j]=opt[i-1][j-1]+opt[i-j][j];
	}
	int ans=0;
	for(int i=1;i<=k;i++){
		ans+=opt[n][i];
	}
	return ans;
}
int main(){
	int t;cin>>t;
	while(t-->0){
		cin>>n>>k;
		cout<<dp()<<endl;
	}
	return 0;
}
