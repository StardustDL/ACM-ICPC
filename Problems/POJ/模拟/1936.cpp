/*
All in All
���⣺�ж�T�Ƿ���һ��������=S
������ģ�� 
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

