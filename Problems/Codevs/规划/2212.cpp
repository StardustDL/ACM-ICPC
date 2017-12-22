/*
������
������ע�⵽��ÿ���������ڵ��������񡱣�������DP���
	  ��opt[i]��ʾǰi����������Ž⣬
	  ת��Ϊopt[i]=min{opt[k]+s*(f[n]-f[k])+t[i]*(f[i]-f[k])|0<=k<i}
	  ����f[n]��ʾ����ϵ��ǰ׺�ͣ�t[i]��ʾǰi�������ʱ���ܺ�
	  ת�Ʒ��̷�Ϊ3���֣�
	  	opt[k]:֮ǰ�����Ž�
		s*(f[n]-f[k]):���ڻ����������µĺ�[k+1..n]����ķ�������
		t[i]*(f[i]-f[k]):��[k+1..i]����ķ��ã�����s 
	  ע��߽�opt[0]=0 
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5000,INF=0x3f3f3f3f;
int n,opt[MAXN+3],t[MAXN+3],f[MAXN+3],s;
void input(){
	cin>>n>>s;
	for(int i=1;i<=n;i++){
		cin>>t[i]>>f[i];
		t[i]+=t[i-1];
		f[i]+=f[i-1];
	}
}
int dp(){
	memset(opt,INF,sizeof(opt));
	opt[0]=0;
	for(int i=1;i<=n;i++){
		for(int k=0;k<i;k++){
			opt[i]=min(opt[i],opt[k]+s*(f[n]-f[k])+t[i]*(f[i]-f[k]));
		}
	}
	return opt[n];
}
int main(){
	input();
	cout<<dp();
	return 0;
} 
