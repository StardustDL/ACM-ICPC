/*
[Usaco2005 Feb]Feed Accounting ���ϼ���
�����������ò�����У�f2ÿ�θ��£�ֱ����f2>=f1��ʱ������
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int c,f1,f2,d,r,sum;
int a[2000+3];
int main(){
	scanf("%d%d%d%d",&c,&f1,&f2,&d);
	for(int x,y;c;c--){
		scanf("%d%d",&x,&y);
		a[x-1]--;a[y]++;
		r=max(r,y);
	}
	for(int i=r;i;i--){
		sum+=a[i];if(i<=d)f2+=sum;
		if(f2>=f1){printf("%d\n",i);break;}
	}
	return 0;
}
