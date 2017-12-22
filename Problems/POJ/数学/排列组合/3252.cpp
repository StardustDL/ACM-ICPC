/*
Round Numbers
题意：如果一个数是round number，则它的二进制表示中，0的个数大于等于1的个数。现在给一段数据范围[start, end]。求这一段数中round number的个数.(1 <= start < end <= 2,000,000,000) 
分析：先将区间问题转成前缀和。类似Code，k=n的二进制位数，先统计二进制位=1..k-1的答案，
	  再对于k位二进制，统计比n小的数，对于每一位，如果遇到1。则将其当成0，然后后边几位任意取，求符合条件的情况数。
	  也就是说11010改成10xxx。实现方法是统计前边有多少个0和1.然后可以知道后边不确定的部分还至少需要多少个0才可以满足条件。
	  要格外注意位数的奇偶性 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset> 
using namespace std;
const int INF=0x3f3f3f3f,MAXN=50;//MAXN设成1000就跑不出来了 
int C[MAXN+3][MAXN+3]; 
bitset<MAXN+3> bit;
int table(int n,int m){
	if(n==0||m==0||n==1||m==n)return 1;
	if(C[n][m])return C[n][m];
	C[n-1][m]=table(n-1,m);
	C[n-1][m-1]=table(n-1,m-1);
	C[n][m]=C[n-1][m]+C[n-1][m-1];
	return C[n][m];
}
int solve(int n){
	bit=n;
	int ans=1,cnt=0;
	int temp=n;while(temp){temp>>=1;cnt++;}
	for(int i=1;i<cnt-1;i++){
		for(int j=((i&1)?(i>>1):((i+1)>>1))+1;j<=i;j++){
			ans+=table(i,j);
		}
	}
	int a=1,b=0;//a:1的个数，b:0的个数 
	for(int i=cnt-2;i>=0;i--){
		if(bit[i]){
			int x=max(i+a-b-1,0);//t表示后边可以自由组合的位数，设x为后边至少需要的0的个数，x + b + 1 = t - x + a，x = (t + a - b - 1)/2，注意x可能小于0
			for(int j=(x&1)?((x+1)>>1):(x>>1);j<=i;j++){
				ans+=table(i,j);
			}
			a++;
		}
		else b++;
	}
	if(b>=a)ans++;//判断n是不是round number
	return ans; 
}
int main(){
	int l,r;
	while(~scanf("%d%d",&l,&r)){
		printf("%d\n",solve(r)-solve(l-1));
	}
	return 0;
} 
 
