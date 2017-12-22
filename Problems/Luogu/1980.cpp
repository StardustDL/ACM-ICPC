#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
int n,cnt=0,x;
int main(){
	cin>>n>>x;
	for(int i=1,j;i<=n;i++){
		j=i;
		while(j){
			if(j%10==x)cnt++;
			j/=10;
		}
	}
	cout<<cnt;
	return 0;
}


