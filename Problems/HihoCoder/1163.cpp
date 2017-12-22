#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m;
int main(){
	cin>>n;
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);m^=x;
	}
	printf("%s",m?"Alice":"Bob");
	return 0;
}