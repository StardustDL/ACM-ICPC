/*
[HNOI2008]越狱
分析：直接计算不好算，进行补集转换：可能越狱个数=总数-不会越狱个数（任意两间相邻的房间不信仰同种宗教）
	  总数=M^N,不越狱个数=m*(m-1)^(n-1) 
	  第一个人可以任意选择宗教，后面的n-1个人每个人都只有m-1个宗教可以选择（不能跟他们前面的一样），所以，不越狱的状态数是m*(m-1)^(n-1) 
	  注意负数问题 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
typedef long long LL;
const LL MOD=100003;
LL m,n;
LL ksm(LL a,LL n){
	LL ans=1;
	while(n>0){
		if(n&1)(ans*=a)%=MOD;
		(a*=a)%=MOD;
		n>>=1;
	}
	return ans;
}
int main(){
	cin>>m>>n; 
	cout<<(ksm(m,n)%MOD-(m*ksm(m-1,n-1))%MOD+MOD)%MOD;
	return 0;
}

