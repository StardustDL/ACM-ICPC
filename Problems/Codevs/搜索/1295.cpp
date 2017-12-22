/*
N�ʺ�����
�������������ã��бȽϺ��жϣ��Խ�����һ���ȽϺõķ�����
	  ����(x,y)��֮ǰ�Ļʺ�(i,t)����Խ����ϵ������ǣ� 
	   t+i==x+y || i-t==x-y
*/
#include<iostream>
using namespace std;
const int MAXN=13;
int n,d[MAXN+3],ans=0;
bool check(int x,int y){
	for(int i=1;i<x;i++){
		int t=d[i];
		if(t==y || t+i==x+y || i-t==x-y)return false;
	}
	return true;
}
void dfs(int ind){
	if(ind>n){
		ans++;return;
	}
	for(int i=1;i<=n;i++){
		if(check(ind,i)){
			d[ind]=i;
			dfs(ind+1);
		}
	}
}
int main(){
	cin>>n;
	dfs(1);
	cout<<ans;
	return 0;
}
