/*
Write a simple HTML Browser
���⣺����һ������HTML�ĵ�������ʽ���
������ģ�⣬ע���ַ���ϸ�� 
*/ 
#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char a[100],b[10000];
	int i=0,used=0;
	while(cin>>a){
		if(strcmp(a,"<br>")==0){
			b[i++]='\n';
			used=0;
			continue;
		}
		if(strcmp(a,"<hr>")==0){
			if(used!=0)b[i++]='\n';
			for(int j=0;j<80;j++)b[i++]='-';
			b[i++]='\n';
			used=0;
			continue;
		}
		int len=strlen(a);
		if(len+1+used>80){
			b[i++]='\n';
		    for(int j=0;j<len;j++)b[i++]=a[j];
			used=len;
		}
		else{
			if(used)b[i++]=' '; 
			for(int j=0;j<len;j++)b[i++]=a[j];
			used+=len+1;
		}
	} 
	b[i]=0;
	cout<<b<<endl;
	return 0;
}


