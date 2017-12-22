#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int MAXN=10000,INF=0x3f3f3f3f;
int len,m,l,r;
bitset<MAXN+3> has;
int main(){
	cin>>len>>m;len++;
	for(int i=1;i<=m;i++){
		cin>>l>>r;
		for(int i=l;i<=r;i++){
			if(!has[i]){
				has[i]=1;len--;
			}
		}
	}
	cout<<len;
	return 0;
}


