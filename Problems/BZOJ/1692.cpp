/*
[Usaco2007 Dec]���б任 
������̰�ģ�ע�����������AABA�����Ҷ˵���ȣ�Ӧ�ô������ң��ʹ�������ȣ�ѡ��С�ģ������N^2��������ˮ��
	  �����׺����Ԥ����Ƚϣ���ת�Ӻ��棩 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2000,INF=0x3f3f3f3f;
char str[MAXN+3];
int n;
bool isleft(int l,int r){
	while(l<r){
		if(str[l]==str[r])l++,r--;
		else return str[l]<str[r];
	}
	return true;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){getchar();str[i]=getchar();}
	for(int i=1,l=1,r=n;i<=n;i++){
		if(isleft(l,r))putchar(str[l++]);
		else putchar(str[r--]);
		if(i%80==0)puts("");
	}
	return 0;
}

