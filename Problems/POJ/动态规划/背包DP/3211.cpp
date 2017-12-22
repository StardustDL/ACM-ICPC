/*
Washing Clothes
���⣺������ϴ�·��� ÿ����ɫ���·��ж���� Ҫ������ֻ��ͬʱϴ��ͬ��ɫ���·��� ��ϴ�·������ʱ�䡣
��������Ϊֻ��ͬʱϴ��ͬ��ɫ���·��� ��˿ɽ���ͬ��ɫ���·���Ϊ��ͬ���飬 �ֱ������ÿ������ʱ�䣬 ��ͼ�Ϊ����ÿ�����ʱ�����0 1����������ÿ����ɫϴ������һ����ʱ�䣬Ҫ��ϴ������ɫ������ʱ�䣬�������ܲ���һ����ϴ������ɫ���·��ﵽ��ʱ���һ�룬Ҳ������������ϴ������ɫ���·���ʱ�価������ͬ��
	  �����ϴÿ����ɫ���·����õ���ʱ�䣬Ϊ��������������ʱ�価������ͬ������ʱ���һ�뵱������������ÿ���·������ѵ�ʱ��������������������Ʒ��ֵ��������ת��Ϊ01�������󱳰�������ֵ��Ȼ����������ɫ����ʱ���ȥ����ֵ����ϴ������ɫ���·����õ����ʱ�䡣
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<map>
#include<vector>
#include<string>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100000/2;
map<string,int> mp;
struct data{
	int sum;
	vector<int> thing;
}ds[13];
int n,m,opt[MAXN+3];
bool input(){
	cin>>m>>n;
	if(m+n==0)return false;
	string tmp; 
	for(int i=1;i<=m;i++){
		cin>>tmp;
		mp[tmp]=i; 
		ds[i].thing.clear(),ds[i].sum=0;
	}
	for(int i=1,t;i<=n;i++){
		cin>>t>>tmp;
		ds[mp[tmp]].thing.push_back(t);
		ds[mp[tmp]].sum+=t;
	}
	return true;
}
int solve(){
	int ans=0;
	for(int i=1;i<=m;i++){
		memset(opt,0,sizeof(opt));
		for(int j=0;j<ds[i].thing.size();j++){
			for(int k=ds[i].sum/2;k>=ds[i].thing[j];k--){
				opt[k]=max(opt[k-ds[i].thing[j]]+ds[i].thing[j],opt[k]);
			}
		}
		ans+=ds[i].sum-opt[ds[i].sum/2];
	}
	return ans;
}
int main(){
	while(input()){
		printf("%d\n",solve());
	}
	return 0;
}

