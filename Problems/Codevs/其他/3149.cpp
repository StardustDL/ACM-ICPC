/*
爱改名的小融 2
*/
#include<iostream>
#include<cstring>
#include<ctype.h>
using namespace std;
int n;
char str[100003];
bool check(){
	int k=strlen(str);
	for(int i=0;i<k;i++)
		if(!isalpha(str[i]))return false;
	return true;
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
