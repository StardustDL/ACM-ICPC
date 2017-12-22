/*
[Baltic2000]Division expression
分析：X2一定是分母，然后约分一下就行了 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=100000;
int a[MAXN+3],n,x2,x1,T;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&a[1],&x2);
		for(int i=2;i<n;i++)scanf("%d",&a[i]);
		for(int i=1;i<n;i++){
			x2/=gcd(x2,a[i]);
			if(x2==1)break;
		}
		puts(x2==1?"YES":"NO");
	}
	return 0;
}

