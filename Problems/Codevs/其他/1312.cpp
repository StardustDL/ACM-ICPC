/*
连续自然数和
分析：暴力枚举，居然过了。。 
*/
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=100000;
int m;
int sum(int l,int r){
	return (l+r)*(r-l+1)/2;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>m;
	for(int i=1;i<m;i++){
		for(int j=i;j<m;j++){
			int t=sum(i,j);
			if(t>m)break;
			else if(t==m)cout<<i<<" "<<j<<endl;
		}
	}
	return 0;
}
