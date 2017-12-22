/*
爱改名的小融
*/
#include<iostream>
#include<cstring>
#include<ctype.h>
using namespace std;
const char R[3]={'R','K','Y'};
int n;
char str[100003];
bool check(){
	int k=strlen(str);
	int cur=0;
	for(int i=0;i<k;i++)
		if(R[cur]==str[i])cur++;
	return cur>2;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	while(n-->0){
		cin>>str;
		if(check())cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
