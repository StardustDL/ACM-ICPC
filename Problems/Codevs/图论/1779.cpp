/*
���ʵĻ���
������ת��ͼ�����·�������ַ���ƥ�䣬Ȼ�����ÿ��ƥ��λ��i����һ��(ƥ����㣬ƥ���յ�+1)��ע����ÿ��ƥ��λ�ã��������ڱ�����ô���ģ����Դ���opt[len+1] 
*/ 
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
const int MAXN=100; 
int n,mp[MAXN+3][MAXN+3],opt[MAXN+3];
string s,t;
int main(){
	cin>>s;
	cin>>n;
	memset(mp,0,sizeof(mp));
	memset(opt,0x3f,sizeof(opt));
	for(int i=1;i<=n;i++){
		cin>>t;
		int k=-1;
		while((k=s.find(t,k+1))!=-1)mp[k+1][k+t.length()+1]=1;
	}
	opt[1]=0;
	for(int i=2;i<=s.length()+1;i++)
		for(int j=1;j<i;j++)
			if(mp[j][i])opt[i]=min(opt[j]+1,opt[i]);
	cout<<opt[s.length()+1]; 
	return 0;
}
