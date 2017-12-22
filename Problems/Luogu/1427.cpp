#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
void read(){
	int k;
	cin>>k;
	if(k==0)return;
	read();
	cout<<k<<" ";
}
int main(){
	read();
	return 0;
}

