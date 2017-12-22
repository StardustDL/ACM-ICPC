/*
Financial Management
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
double x,sum=0; 
int main(){
	for(int i=1;i<=12;i++){scanf("%lf",&x);sum+=x;}
	printf("$%.2lf",sum/12);
	return 0;
}

