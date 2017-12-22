/*
反正切函数的应用
分析：由题意，推导=>arctan(1/a)=arctan[(1/b+1/c)/(1-1/b*c)]=>bc-1=a(b+c)，令b=a+m,c=a+n（这样为什么对啊？） 
	  (a+m)*(a+n)-1=a*(a+m+a+n)=>m*n=a*a+1
	  注意m越大，b+c越小，暴力一下，注意数据范围 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
typedef unsigned int UI;
UI a,t,m;
int main(){
	cin>>a;t=a*a+1;
	for(m=a;m>=1;m--)if(t%m==0)break;
	//之前写成t%a，就RE了，为什么？ 
	cout<<a+a+(t/m)+m;
	return 0;
}

