#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
double x; 
int main(){
	cin>>x;
	int k=1;
	double l=2,len=2;
	while(len<x){
		k++;
		l=l*0.98;
		len+=l;
	}
	cout<<k<<endl;
	return 0;
}


