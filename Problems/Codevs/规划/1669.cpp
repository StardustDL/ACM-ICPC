/*
运输装备
分析：两个限制条件的零一背包DP 
*/
#include<iostream>
using namespace std;
const int MAXN=1000;
int n,V,G,opt[MAXN+3][MAXN+3],a,b,c;
int main(){
	cin>>V>>G>>n;
	while(n-->0){
		cin>>a>>b>>c;
		for(int i=V;i>=b;i--){
			for(int j=G;j>=c;j--){
				opt[i][j]=max(opt[i][j],opt[i-b][j-c]+a);
			}
		}
	}
	cout<<opt[V][G];
	return 0;
} 
