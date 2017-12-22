/*
Keep the Customer Satisfied
���⣺��һ����˾��һ�������ߣ�ÿ��λʱ��ֻ������һ����Ʒ���ڿ�ʼ��ʱ�������ܵ�N��������ÿ�������в�Ʒ��q�ͽ�ֹ����d��������Ч��������һЩ�����ᷢ����ͻ���������һ���ĵ�����������ܹ��������ٶ���ʹ����Щ���������԰�ʱ��ɡ�
����������Ķ��֡�һ���ǽ���ҵ�ԭ�򡣡�
	  ��ʵ̰�ļ��ɣ�����ֹʱ���С����������Ϊһ��Ҫ��ѡ��ֹʱ����ģ�����ά��ǰi��������ɾ��������С����ʱ��time 
	  	����һ���¶���K������need[K]+time<=last[K]�������ѡ�����������������һ�����ţ�����֮��Ҫ������
		����������������������ȥ��һ�������еĶ�����ʹK����ѡ��һ��һ���𰸲��䣩���������Ҫ����ʹtime��С������
		Ҫ�Ƚ���ѡ��������Ҫʱ�����E����need[E]>need[K]����E��ΪK��Ȼ�Ϸ�����time��С
		���Ĵ𰸼�Ϊ���ն����ڵ�Ԫ�ظ��� 
	  �������ȶ���ά������Ѽ���
	  ע�����Ϊ�յ�ʱ�� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=800000;
priority_queue<int> q;
struct thing{
	int l,w;
	bool operator < (const thing &t)const{
		return l<t.l;
	}
}ts[MAXN+3];
int n;
int main(){
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++)scanf("%d%d",&ts[i].w,&ts[i].l);
		while(!q.empty())q.pop();
		sort(ts+1,ts+n+1);
		int cur=0;
		for(int i=1;i<=n;i++){
			if(cur+ts[i].w<=ts[i].l || (!q.empty()&&ts[i].w<q.top())){q.push(ts[i].w);cur+=ts[i].w;}
			if(cur>ts[i].l){cur-=q.top();q.pop();} 
		}
		printf("%d\n",q.size());
	}
	return 0;
}

