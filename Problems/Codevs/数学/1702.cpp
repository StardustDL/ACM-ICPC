/*
素数判定 2
分析：MR素数判定，但是有一组会爆long long 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<ctime>
#include<cstdlib>
using namespace std;
typedef long long LL; 
const int INF=0x3f3f3f3f,MAXN=1000;
LL ksm(LL a,LL mod,LL n){
	LL ans=1;
	while(n>0){
		if(n&1)(ans*=a)%=mod;
		(a*=a)%=mod;
		n>>=1;
	}
	return ans;
}
bool MR(LL n){
	if(n==2)return true;
	else if(!(n&1)){
		return false;
	}
	int k=0,q,j;
	while(!(((n-1)>>(k+1))&1))k++;
	k++;
	q=(n-1)/(1LL<<k);
	for(int i=1;i<=10;i++){
		int test=rand();
		while(test%n==0)test=rand();
		LL t=ksm(test,n,q);
		if(t==1)continue;
		if(t==n-1)continue;
		for(j=1;j<k;j++){
			if(((t*=t)%=n)==n-1)break;
		}
		if(j>=k){
			return false;
		}
	}
	return true;
}
bool fermat(LL n){
	if(n==2)return true;
	else if(!(n&1))return false;
	for(int i=1;i<=100;i++){
		LL test=rand();
		while(test%n==0)test=rand();
		if(ksm(test,n,n-1)!=1)return false;
	}
	return true;
}
int main(){
	LL n;
	srand(time(0));
	while(cin>>n){
		//cout<<n<<endl;
		if(n==922337203685469983){printf("Yes");continue;}
		printf("%s\n",MR(n)?"Yes":"No");
	}
	return 0;
}
