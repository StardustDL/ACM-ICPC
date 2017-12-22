/*
A+B for Input-Output Practice (IV)
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
int main(){
	int n,sum,k;
	while(cin>>n,n){
		sum=0;
		while(n--){
			cin>>k;sum+=k; 
		}
		cout<<sum<<endl;
	}
	return 0;
}

