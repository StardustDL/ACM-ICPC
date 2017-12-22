/*
[Zjoi2013]K������ѯ
������ע����Ŀ�е�ע�ͣ���Ҫ����
	  �����������������������᡿��������֡�������ô���ӵı෨��
	  �����������ǵ�K��һ��ʼ�����ǿյģ����ԣ������в�������Ӵ�С���򣬵ڶ��ؼ���Ϊִ��ʱ��
	  Ȼ��ִ��˳��ɨһ�����в��������ڲ����ǣ�����
	  ���ڲ�ѯ������������˳��ɨһ����������ͳ�����ĸ����������ڵ�ǰ��ѯ�ĸ���ʱ������������� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=50000;
struct oper{
	int tme,tp,a,b,c;
	bool operator < (const oper &t)const{
		return c==t.c?(tme<t.tme):(c>t.c);
	}
}ops[MAXN+3];
vector<oper> chs;
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		ops[i].tme=i;
		scanf("%d%d%d%d",&ops[i].tp,&ops[i].a,&ops[i].b,&ops[i].c);
		if(ops[i].tp==1)chs.push_back(ops[i]);
	}
	sort(chs.begin(),chs.end());
	for(int i=1;i<=m;i++){
		if(ops[i].tp==1)continue;
		int cnt=0,j;
		for(j=0;j<chs.size();j++){
			if(chs[j].tme>i)continue; 
			int len=min(chs[j].b,ops[i].b)-max(chs[j].a,ops[i].a)+1;
			if(len<0)continue;
			if((cnt+=len)>=ops[i].c)break;
		}
		printf("%d\n",chs[j].c);
	}
	return 0;
}

