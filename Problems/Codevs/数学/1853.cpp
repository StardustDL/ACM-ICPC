/*
容易题
分析：应该仔细推导一下 
	  答案是每一位的可能取值的和的乘积，式子如下：
	  pi{sigma{j|1<=j<=n&&a[i]可以是j}|1<=i<=m}
	  先对限制排序，枚举限制，注意判重，
	  计算有限制的位置的和，乘起来
	  再乘上没有限制的（用快速幂） 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MOD=1000000007,MAXK=1e+5;
typedef long long LL;
struct tip{
	int x,y;
	bool operator < (const tip &t)const{
		return x<t.x||x==t.x&&y<t.y;
	}
}ts[MAXK+3];
int n,m,k,cur=1;
LL ans=1;
LL ksm(LL a,int n){
	LL an=1;
	while(n>0){
		if(n&1)an=(an*a)%MOD;
		a=(a*a)%MOD;
		n>>=1;
	}
	return an;
}
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)cin>>ts[i].x>>ts[i].y;
	sort(ts+1,ts+k+1);
	LL sum=(LL)n*(n+1)/2%MOD,tmp=sum,tot=m;
	for(int i=1;i<=k+1;i++){
		if(ts[i].x!=ts[i-1].x&&i!=1){
			ans=(ans*tmp)%MOD;tmp=sum;tot--;
		}
		if(ts[i].x!=ts[i-1].x||ts[i].y!=ts[i-1].y){
			tmp-=ts[i].y;
			if(tmp<0)tmp+=MOD;
		}
	}
	cout<<(ans*ksm(sum,tot)%MOD);
	return 0;
}
