/*
���ֻ�ľ
��������ʵ���ǡ���������������棬���Ǹ��·�Χ��A�� 
	  ͨ����������ַ����Ƚϣ�sortһ�鼴�� 
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string a[1003];
int n;
bool cmp(const string &a,const string &b){
	return a+b>b+a;
}
int main(){
	ios::sync_with_stdio(false); 
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)cout<<a[i];
	return 0;
}
