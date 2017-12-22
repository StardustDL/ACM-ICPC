/*
明明的随机数
分析：桶排序即可 
*/
#include<iostream>
#include<bitset>
using namespace std;
const int MAXN=1003;
bitset<MAXN> c=0;
int n,t,k=0;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	while(n-->0){
		cin>>t;
		if(!c[t]){
			c[t]=1;k++;
		}
	}
	cout<<k<<endl;
	for(int i=1;i<=MAXN;i++){
		if(c[i])cout<<i<<" ";
	}
	return 0;
}
