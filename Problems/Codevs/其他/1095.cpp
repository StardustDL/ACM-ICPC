/*
������
��������ʵ�������ɽ������ĵ�m������ 
*/
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,m,a[10001];
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)next_permutation(a,a+n);
	for(int i=0;i<n;i++)cout<<a[i]<<' ';
}
