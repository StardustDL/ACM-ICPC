/*
邮票
分析：实质就是背包问题：当前邮资i可以看作背包容量，每种邮票可以看作是一个物品，邮票的面值就是物品的体积，k可以看作是对物品数量的一个限制。 
	  注意数组的大小 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=50,MAXL=10000*200;
int n,k,a[MAXN+3],opt[MAXL+3];
void input(){
	cin>>k>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
}
int dp(){
	int ans=0;
	do{
		opt[++ans]=k+3;
		for(int j=1;j<=n&&a[j]<=ans;j++){
			opt[ans]=min(opt[ans-a[j]]+1,opt[ans]);
		}
	}while(opt[ans]<=k);
	return ans-1;
}
int main(){
	input();
	cout<<dp();
	return 0;
}
