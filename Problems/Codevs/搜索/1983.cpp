/*
等式问题
分析：dfs+判断即可 
*/
#include<iostream>
using namespace std;
int f[10],ans=0,n;
bool check(){
	int sum=0,t=0;
	for(int i=0;i<=8;){
		int j=i+1;
		while(f[j]==0)j++;
		t=0;
		for(int k=i+1;k<=j;k++)t=t*10+k;
		if(f[i]==1)sum+=t;
		else sum-=t;
		i=j;
	}
	return sum==n;
}
void dfs(int c){
	if(c==9){
		if(check())ans++;
	}
	else{
		for(int i=0;i<=2;i++){
			f[c]=i;dfs(c+1);
		}
	}
}
int main(){
	cin>>n;
	f[0]=f[9]=1;
	dfs(1);
	cout<<ans;
	return 0;
}
