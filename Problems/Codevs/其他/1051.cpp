/*
������Ϸ
������ע��ǰ׺���ǽ���������������ǽ����е��ʰ��ֵ�������������ʹ��ǰ׺��ͬ�ĵ�����һ����
	  Ȼ������ά��һ��ջ��ö�����е��ַ��������ֵ����źõģ�
	  �����ǰ���ַ����ܺ�ջ�����ַ��������Ļ�����ô��ǰ�ַ�����ջ������ö����һ���ַ�����
	  ������ܽ�������ôջ���ַ�����������ǰ�ַ��������뵯�����ջ���ַ����Ƚϣ�ֱ����ǰ�ַ�����ջ���ַ����ܽӳ�����Ȼ��ǰ�ַ�����ջ��
	  �����ڼ�ͳ��ջ����ж��ٸ�Ԫ�� 
	  ���˼���е�����LIS��nlogn�㷨 
*/
#include<iostream>
#include<stack>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int n,ans=0;
string s[100000+3];
stack<string> S;
bool pp(string a,string b){
	if(a.length()>b.length())return false;
	for(int i=0;i<a.length();i++)if(a[i]!=b[i])return false;
	return a.length()<b.length();
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i];
	sort(s+1,s+n+1);
	S.push(s[1]);ans=1;
	for(int i=2;i<=n;i++){
		while(!S.empty()&&!pp(S.top(),s[i]))S.pop();
		S.push(s[i]);
		ans=max(ans,(int)S.size());
	}
	cout<<ans;
	return 0;
}
