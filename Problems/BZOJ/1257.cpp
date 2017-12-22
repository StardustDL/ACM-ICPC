/*
[CQOI2007]余数之和sum
分析：sigma{k%i|i=1..n}=sigma{k-[k/i]*i}=n*k-sigma{ [k/i]*i }
	   注意[k/i]最多有sqrt(k)个取值，分段做即可 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=1000,INF=0x3f3f3f3f;
LL n,k,ans,i,l,r;
int main(){
	cin>>n>>k;
	i=k/n;
	l=k/(i+1)+1;
	r=n;
	ans=n*k;
	while(l>0){
		ans-=i*(r+l)*(r-l+1)/2;
		if(l==1)break;
		i=k/(l-1);//i=k/(k/(i+1))相当于枚举因数 
		l=k/(i+1)+1;
		r=k/i;
	}
	cout<<ans<<endl;
	return 0;
}

