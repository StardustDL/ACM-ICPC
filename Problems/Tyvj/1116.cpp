/*
被7整除
*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
int n,cnt=0; 
int main(){
	cin>>n;
	for(int i=1,x=1;i<=n;i++){
		(x<<=1)%=7;
		if((x-((i%7)*(i%7))%7)%7==0)cnt++;//注意要取mod 
	}
	cout<<cnt<<endl;
	return 0;
}

