/*
���ļ���
���⣺����û˵�����������ÿ�ο��������ϴ���������һ�����
������DFS������ʵ����û��Ҫ������Ҳ���� 
*/ 
#include<iostream>
using namespace std;
int n,ans=0;
void dfs(int n){
	ans++;
	for(int i=1;i<=n/2;i++)dfs(i);
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	dfs(n);
	cout<<ans;
	return 0;
}
