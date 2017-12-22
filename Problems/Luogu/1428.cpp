#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=100,INF=0x3f3f3f3f;
int n,a[MAXN+3];
int main(){
	cin>>n;
	for(int i=1,cnt;i<=n;i++){
		cin>>a[i];cnt=0;
		for(int j=1;j<i;j++){
			if(a[j]<a[i])cnt++;
		}
		cout<<cnt<<" ";
	}
	return 0;
}


