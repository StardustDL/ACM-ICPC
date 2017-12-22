/*
[SDOI2008]仪仗队
分析：观察图形，按对角线划分的话，两边都等于sigma(phi[i],2<=i<=n-1)
	  所以答案= sigma(phi[i],2<=i<=n-1)*2 + 3(左下角的3个点)
	  注意n=1的情况 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef unsigned long long ULL;
const int MAXN=40000,INF=0x3f3f3f3f;
int mindiv[MAXN+3],pcnt;
ULL phi[MAXN+3],pris[MAXN+3];
inline void init(int size){
	pcnt=0;phi[1]=1;
	for(int i=2;i<=size;i++){
		if(mindiv[i]==0){mindiv[i]=i;pris[++pcnt]=i;phi[i]=i-1;}
		for(int j=1,k;j<=pcnt&&(k=i*pris[j])<=size;j++){
			mindiv[k]=pris[j];
			if(mindiv[i]==pris[j]){phi[k]=phi[i]*pris[j];break;}
			phi[k]=phi[i]*(pris[j]-1);
		}
	}
}
int main(){
	int n;cin>>n;
	if(n<=1){cout<<0<<endl;return 0;}
	init(n);
	long long ans=2;
	for(int i=2;i<n;i++)ans+=phi[i];
	cout<<ans*2-1<<endl;
	return 0;
}

