/*
To the Max
*/
#include<iostream>
using namespace std;
const int MAXN=100;
int n,a[MAXN+3][MAXN+3];
int dp(){
	int ans=0,sum;
	for(int i=1;i<=n;i++){//枚举遍历起始行 
		for(int j=i;j<=n;j++){//枚举当前行 
			sum=0;
			for(int k=1;k<=n;k++){//枚举列 
				int t=a[j][k]-a[i-1][k];
				sum=max(sum+t,0);
				ans=max(ans,sum);
			}
		}
	}
	return ans;
}
void input(){
	cin>>n;
	int t;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){//预处理每一列的前缀和 
			cin>>t;
			a[i][j]=a[i-1][j]+t;
		}
}
int main(){
	input();
	cout<<dp();
	return 0;
}
