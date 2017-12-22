/*
All in All
题意：判断T是否有一个子序列=S
分析：模拟 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100000;
char s[MAXN+3],t[MAXN+3]; 
bool check(){
	int ls=strlen(s),lt=strlen(t),ct=0;
	for(int i=0;i<ls;i++){
		while(t[ct]!=s[i]&&ct<lt)ct++;
		if(ct>=lt)return false;
		ct++;
	}
	//cout<<ct<<endl;
	return ct<=lt;
}
int main(){
	while(cin>>s>>t){
		printf("%s\n",(check()?"Yes":"No"));
	}
	return 0;
}

