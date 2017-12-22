/*
n里的质数
*/
#include<iostream>
#include<bitset>
using namespace std;
int main(){
	bitset<203> bt=0;
	int n;
	cin>>n;
	bt[0]=bt[1]=1;
	if(n==0||n==1){
		cout<<n;
		return 0;
	}
	for(int i=2;i<=n;i++)
		if(!bt[i])for(int j=i*i;j<=n;j+=i)bt[j]=1;
	for(int i=1;i<=n;i++)
		if(!bt[i])cout<<i<<" ";
	return 0;
}
