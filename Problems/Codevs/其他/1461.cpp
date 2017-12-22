/*
ÊÖ»ú
*/
#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
const int C[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
const int K=1;
char str[255];
int ans=0;
int main(){
	gets(str);
	for(int i=0;i<strlen(str);i++){
		if(str[i]==' ')ans+=K;
		else ans+=C[str[i]-'a'];
	}
	cout<<ans;
	return 0;
}
