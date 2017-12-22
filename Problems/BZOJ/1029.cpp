/*
[JSOI2007]��������
������̰��
	  ��t2���������򣬶�ÿһ�������������ǰ����ʱ��+t1<=t2����ά�����������
	  ���򣬱Ƚ�t1��֮ǰά�޵����н�����t1�����ֵ�����˽���t1��С���ô˽����滻�Ǹ����������ʹ�𰸲��䣬����ʹ��ʱ���С 
*/
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=150000,INF=0x3f3f3f3f;
struct data{
	int t1,t2;
	bool operator < (const data &t)const{
		return t2<t.t2;
	}
}ds[MAXN+3];
int n,curtime=0,ans=0;
priority_queue<int> q;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&ds[i].t1,&ds[i].t2);
	sort(ds+1,ds+n+1);
	for(int i=1;i<=n;i++){
		if(curtime+ds[i].t1<=ds[i].t2){ans++;curtime+=ds[i].t1;q.push(ds[i].t1);}
		else{
			if(q.empty())continue;
			if(ds[i].t1<q.top()){
				(curtime-=q.top())+=ds[i].t1;q.pop();
				q.push(ds[i].t1);
			}
		}
	}
	printf("%d\n",ans); 
	return 0;
}

