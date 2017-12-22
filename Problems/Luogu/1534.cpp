#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
int n,a,b,sum=0,ans=0;
int main(){
	cin>>n;
	while(n--){
		cin>>a>>b;
		ans+=(sum+=a+b-8);
	}
	cout<<ans;
	return 0;
}

