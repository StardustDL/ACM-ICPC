/*
���⣺����m1��m2�Լ����ɸ���si����si^a mod m1^m2=0��a����Сֵ�����޽⣬���-1��
��������������̫�󣬸�������ֱ�Ӽ��㣬�������ǿ���ͨ����ʽ�ֽ����ҵ�ͻ�Ƶ㡣
	  ��m1�ֽ��һ��������s[i]û��ʱ����������϶��޽⣬��m1��s[i]�Դ���������һ������ʱ��
	  ���ǿ��Ը����������ô������õ�������a��Сֵ
	  �����ܲ����������������Ŵ𰸣�ȡ�������������ģ��������ܱ�֤s^a��m1^m2�ı�������xΪm1�������ĸ�����yΪs[i]�������ĸ�������a=x div y; If  x*a<y then inc(a)�� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cstdio>
#include<bitset> 
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
struct data{
	int c,v;
	data(int a,int b):v(a),c(b){}
};
vector<data> ds;
int m1,m2,n,ans=INF;
int main(){
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=2,cnt;m1>1;i++){
		if(m1%i==0){
			for(cnt=0;m1%i==0;m1/=i)cnt+=m2;
			ds.push_back(data(i,cnt));
		}
	}
	for(int s,t,i,k;n;n--){
		scanf("%d",&s);
		for(i=0,t=0;i<ds.size();i++){
			if(s%ds[i].v!=0)break;
			k=0;while(s%ds[i].v==0)k++,s/=ds[i].v;
			int a=ds[i].c/k;if(a*k<ds[i].c)a++;
			t=max(t,a);
		}
		if(i<ds.size())continue;
		ans=min(ans,t);
	}
	printf("%d",ans==INF?-1:ans);
	return 0;
}

