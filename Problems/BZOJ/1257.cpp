/*
[CQOI2007]����֮��sum
������sigma{k%i|i=1..n}=sigma{k-[k/i]*i}=n*k-sigma{ [k/i]*i }
	   ע��[k/i]�����sqrt(k)��ȡֵ���ֶ������� 
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
		i=k/(l-1);//i=k/(k/(i+1))�൱��ö������ 
		l=k/(i+1)+1;
		r=k/i;
	}
	cout<<ans<<endl;
	return 0;
}

