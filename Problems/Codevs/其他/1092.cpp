/*
不高兴的津津
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
int id=-1;
int main(){
	for(int i=0,a,b,mx=0;i<7;i++){
		scanf("%d%d",&a,&b);
		if(a+b>8)if(a+b-8>mx)mx=a+b-8,id=i;
	}
	printf("%d",id+1);
	return 0;
}

