/*
Big Number
���⣺��N!�ж���λ
��������log 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
int n,T; 
int main(){
	cin>>T;
	while(T--){
		cin>>n;double t=0;
		for(int i=1;i<=n;i++)t+=log10(i*1.0);
		cout<<(int(t))+1<<endl;
	}
	return 0;
}

