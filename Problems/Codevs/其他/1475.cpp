/*
m进制转十进制
*/
#include<iostream>
#include<cstring>
using namespace std;
int m,e[9];
char a[9];
int work(char* t,int m){
	int ans=0,k=1;
	for(int i=0;i<strlen(t);i++){
		if(t[i]<='9')e[i]=t[i]-'0';
		else e[i]=t[i]-'A'+10;
	}
	for(int i=strlen(t)-1;i>=0;i--){
		ans+=e[i]*k;
		k*=m;
	}
	return ans;
}
int main(){
	cin>>a>>m;
	cout<<work(a,m);
	return 0;
}


