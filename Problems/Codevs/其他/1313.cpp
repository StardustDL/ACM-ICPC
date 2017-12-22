/*
质因数分解
*/
#include<iostream>
#include<cmath>
using namespace std;
bool isprime(int n){
	int t=(int)sqrt(n)+1;
	while(--t>1){
		if(n%t==0)return false;
	}
	return true;
}
int main(){
	int n,a;
	cin>>n;
	a=(int)sqrt(n);
	for(int i=2;i<=a;i++){
		cout<<i<<" "<<n%i<<" "<<isprime(i)<<endl;
		if(n%i==0&&isprime(i)){
			cout<<n/i;
			return 0;
		}
	}
}
