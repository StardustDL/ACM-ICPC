/*
��������
���������Է���������������Ҫ��ģ���Ҫ��׼ȷ��֪��ǰn�����������ֵ 
*/ 
#include<iostream>
#include<bitset>
#include<vector>
using namespace std;
const int MAXN=1400000;
bitset<MAXN+3> isp=0;
vector<int> v;
int n;
int main(){
	cin>>n;
	isp[1]=1;
	for(int i=2;i<=MAXN&&v.size()<n;i++){
		if(isp[i])continue;
		v.push_back(i);
		for(int j=i<<1;j<=MAXN;j+=i)isp[j]=1;
	}
	for(int i=0;i<n;i++)cout<<v[i]<<" ";
	return 0;
}
