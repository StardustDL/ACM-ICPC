/*
分解质因数
分析：先求1-n中的质数，枚举每个质数即可，另一种方法是筛质数时同时进行分解，这样更好 
注意：bitset如果赋值的话，就不能开太大，这里开到1<<22就到顶了，但如果不赋值，可以开到1<<31，但是提交时会出错 
*/
#include<iostream>
#include<bitset>
using namespace std;
/*方法1： 
const int MAXN=1<<29;
bitset<MAXN> isp;
int pris[100003],prin=0,n;
bool isfirst=true;
void prime(int t){
	//isp=0;//注意这里 
	for(int i=2;i<=t;i++){
		if(!isp[i]){
			pris[++prin]=i;
			for(int j=i*i;j<=t;j+=i){
				isp[j]=1;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	prime(n);
	cout<<n<<"=";
	for(int i=1;i<=prin;i++){
		while(n%pris[i]==0){
			if(!isfirst)cout<<"*"<<pris[i];
			else{
				isfirst=false;
				cout<<pris[i];
			}
			n/=pris[i];
		}
	}
	return 0;
}*/
const int MAXN=1<<25;
bitset<MAXN> isp;
int n;
bool isfirst=true;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	cout<<n<<"=";
	for(int i=2;i<=n;i++){
		if(!isp[i]){
			while(n%i==0){
				if(!isfirst)cout<<"*"<<i;
				else{
					isfirst=false;
					cout<<i;
				}
				n/=i;
			}
			for(int j=i*i;j<=n;j+=i){
				isp[j]=1;
			}
		}
	}
	return 0;
}
