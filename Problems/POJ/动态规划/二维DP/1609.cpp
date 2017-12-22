/*
Tiling Up Blocks
题意：Michael The Kid有n块积木，每块积木如下图，左上有l个凸口，右上有w个凸口，左下右l个凹口，右下有w个凹口。当l >= l'并且m >= m'时，木块'可安装于另一个上面。问最高能叠几层积木。
分析：前几句都是废话， “当l >= l'并且m >= m'时”，由这句可知，可以用类似LIS的方法（二维），但这是N^2的，先说下二维LIS：先按第一维排序，再对第二维做LIS
	  但由于l,m范围较小，直接用opt[i][j]表示所有<=i,<=j的积木个数，即可。opt[i][j]=(i,j)出现次数+max(opt[i-1][j],opt[i][j-1]) 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100;
int opt[MAXN+3][MAXN+3];
bool input(){
	int n,l,r;
	cin>>n;
	if(n==0)return false;
	memset(opt,0,sizeof(opt));
	while(n-->0){
		cin>>l>>r;opt[l][r]++;
	}
	return true;
}
int dp(){
	int ans=0;
	for(int i=1;i<=MAXN;i++){
		for(int j=1;j<=MAXN;j++)
			opt[i][j]+=max(opt[i-1][j],opt[i][j-1]);
	}
	return opt[MAXN][MAXN];
}
int main(){
	while(input())cout<<dp()<<endl;
	cout<<'*';
	return 0;
}
