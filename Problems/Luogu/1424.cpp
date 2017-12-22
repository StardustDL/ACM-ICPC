#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
int n,x,len=0;
int main(){
	cin>>x>>n;x--;
	for(int i=1;i<=n;i++){
		if(x!=5&&x!=6){
			len+=250;
		}
		(x+=1)%=7;
	}
	cout<<len;
	return 0;
}

