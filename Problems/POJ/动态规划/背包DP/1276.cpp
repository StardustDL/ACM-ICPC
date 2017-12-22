/*
Cash Machine
题意：有各种不同面值的货币，每种面值的货币有不同的数量，请找出利用这些货币可以凑成的最接近且小于等于给定的数字cash的金额。 
分析：多重背包，但由于只是是否存在的问题，所以可以用类似完全背包的方法，但这个的正确性暂时不会证明 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=10,MAXM=100000;
int cash,n,c[MAXN+3],d[MAXN+3],cnt[MAXM+3],opt[MAXM+3];
bool input(){
	if(!(cin>>cash>>n))return false;
	for(int i=1;i<=n;i++)cin>>c[i]>>d[i];
	return true;
}
int dp(){
	memset(opt,0,(cash+3)*sizeof(int));//数组较大，不要直接用sizeof(opt) 
	for(int i=1;i<=n;i++){
		memset(cnt,0,(cash+3)*sizeof(int));//cnt记录当前钞票在不同现金要求最优解下的使用张数 
		for(int j=d[i];j<=cash;j++){
			if(cnt[j-d[i]]+1<=c[i]&&opt[j-d[i]]+d[i]>opt[j]){//若还可以用，且更优 
				opt[j]=opt[j-d[i]]+d[i];
				cnt[j]=cnt[j-d[i]]+1;
			}
		}
	}
	return opt[cash];
}
int main(){
	while(input())cout<<dp()<<endl;
	return 0;
}
