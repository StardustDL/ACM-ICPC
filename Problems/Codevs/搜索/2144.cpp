/*
������� 2
���������Զ������������������ݲ���̫��Ҳ���Լ�һ��Ѽ�֦AC
	  ��֦���£��ȶ��������Ӵ�С����������ѡ��ģ����õļ�С������Χ��
	  	Ȼ�����ɺ�׺�ͣ��������������ǰ��֮�����������ѡ�������Դﵽm����֦
		�����ǰ�𰸲������Ž⣬��֦
		���ѡ�����Ʒ��ʹ���ܺͳ���m����֦ 
*/ 
#include<iostream>
#include<cstring>
#include<algorithm>
#include<bitset>
using namespace std;
const int MAXN=30; 
int n,m,ans,a[MAXN+3],s[MAXN+3];
bitset<MAXN+3> used;
void dfs(int cur,int d,int pos){
	if(d>=ans)return;
	if(cur==0){ans=min(ans,d);return;}
	for(int i=pos;i<=n;i++){
		if(cur-a[i]>=0){
			if(cur-s[i]>0)return;
			dfs(cur-a[i],d+1,i+1);
		}
	}
}
bool cmp(int x,int y){return x>y;}
int main(){
	cin>>n>>m;ans=n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=n;i>=1;i--)s[i]=s[i+1]+a[i];
	dfs(m,0,1);
	cout<<ans;
	return 0; 
}
