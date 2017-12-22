/*
ËØÊýºÍ
*/
#include<iostream>
#include<algorithm>
#include<bitset>
#define N 65536
using namespace std;
typedef long long ll;
ll a,b;
bitset<N+7> isz=0;
void szs(ll n){
	for(ll i=2;i<=n;i++)
		if(!isz[i])
			for(ll j=i*i;j<=n;j+=i)
				isz[j]=1;
}
void init(){
	cin>>a>>b;
	isz[1]=1;
	if(a>b)swap(a,b);
	szs(b);
}
ll sum(ll a,ll b){
	long ans=0;
	for(ll i=a+1;i<b;i++)
		if(!isz[i])ans+=i;
	return ans;
}
int main(){
	init();
	cout<<sum(a,b);
	return 0;
}
