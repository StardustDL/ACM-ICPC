/*
[HEOI2015]定价
分析：每次将最后一位非0数字+1
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int add(int x){
	int res=1;
	while(x%10==0)x/=10,res*=10;
	return res;
}
int calc(int x){
	while(x%10==0)x/=10;
	int t=x%10,res=0;
	while(x)x/=10,res++;
	return t==5?(2*res-1):(2*res);
}
int main(){
	int T;scanf("%d",&T);
	for(int l,r,i=1;i<=T;i++){
		scanf("%d%d",&l,&r);
		int ans=l,mn=calc(l);l+=add(l);
		while(l<=r){
			int t=calc(l);
			if(t<mn)mn=t,ans=l;
			l+=add(l);
		}
		printf("%d\n",ans); 
	} 
	return 0;
}

