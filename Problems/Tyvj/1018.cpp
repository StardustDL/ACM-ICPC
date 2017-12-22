/*
½×³ËÍ³¼Æ
*/
#include<iostream>
using namespace std;
typedef long long LL;
int n,k;
LL s=1,t=1;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		s*=i;
		while(s%10==0)s/=10; 
	}
	for(int i=1;i<=k;i++)t*=10;
	if(t>s)cout<<s;
	else for(int i=1;i<=k;i++)cout<<s%t/(t/=10);
	return 0;
}
