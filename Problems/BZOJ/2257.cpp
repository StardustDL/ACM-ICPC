/*
[Jsoi2009]ƿ�Ӻ�ȼ��
����������������ѡ�񼸸����֣����Եõ��Ĵ�Ϊ���ǵ����Լ��
	  �������ǿ������ÿ����������������Ȼ�������������Ҹ��������k������
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
int n,k,ans=0;
vector<int> v;
inline void primes(int val){
	int to=floor(sqrt(val*1.0));
	for(int i=1;i<=to;i++)if(val%i==0){v.push_back(i);if(i!=val/i)v.push_back(val/i);}
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1,t;i<=n;i++){
		scanf("%d",&t);
		primes(t);
	}
	sort(v.begin(),v.end());
	for(int i=v.size()-2,t=1;i>=0&&ans==0;i--){
		if(v[i]==v[i+1])t++;
		else{
			if(t>=k)ans=v[i+1];
			t=1;
		}
	}
	printf("%d",ans);
	return 0;
}

