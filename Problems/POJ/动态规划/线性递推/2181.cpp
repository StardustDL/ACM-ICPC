/*
Jumping Cows
���⣺ţ�����������򣬵�����û�취��Ծ��������ʦ������һЩ���ϣ�ÿ��������һ��strengthֵ��ÿ�θ���n�����ϣ�һ������ֻ��ʹ��һ�Σ��ұ��밴�ո���˳��ʹ�ã�����һֻţʹ����m�����ϣ�����ʹ�õĵ����������ϣ�1��3��5,������������ţ����Ծ����������ż�������ϻή��ţ����Ծ��������ţ����Ծ�����߶ȡ�
����������ֻ��������ѡ�Ͳ�ѡ��ά������Ϊ������ż�������Ž⣬ɨһ�鼴�ɣ�ע��n=1����� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
int n,t,odd,even,k; 
int main(){
	scanf("%d",&n);
	if(n==1){scanf("%d",&t);printf("%d",t);return 0;}
	scanf("%d%d",&odd,&even);
	t=even;
	even=odd-even;
	odd=max(odd,t);
	for(int i=3;i<=n;i++){
		scanf("%d",&k);
		t=max(odd,even+k);//ѡk�����evenת�� 
		even=max(even,odd-k);//ѡk�����oddת�� 
		odd=t;
	}
	printf("%d",max(odd,even)); 
	return 0;
}

