/*
[NOIP1998P1]ÇÉÃîÌîÊı
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
int v[10];
void calc(int t){
	while(t){
		v[t%10]++;
		t/=10;
	}
}
bool check(){
	if(v[0])return false;
	for(int i=1;i<=9;i++){
		if(v[i]!=1)return false; 
	}
	return true;
}
int main(){
	for(int i=100,j,k;i*3<1000;i++){
		memset(v,0,sizeof(v));
		calc(i);calc(i*2);calc(i*3);
		if(check())printf("%d %d %d\n",i,i*2,i*3);
	}
	return 0;
}

