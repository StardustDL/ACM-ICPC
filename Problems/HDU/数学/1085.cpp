/*
Holding Bin-Laden Captive!
���⣺������ֵΪ2,3,5��Ӳ��ö����������ЩӲ�Ҳ�����ɵ���С���
����������������ĸ����������ʵ��ɲ���
	  ���ж��ܷ���1,2���[1..4]�Ľ�������ô����[1..c*5+a+b*2]�Ľ�������� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
int a,b,c;
int main(){
	while(scanf("%d%d%d",&a,&b,&c),a+b+c>0){
		if(/*a>=4||a>=1&&b>=2||a>=2&&b>=1||a>=3&&b>=1*/a&&(a+b*2>=4))printf("%d\n",c*5+a+b*2+1);
		else printf("%d\n",(a==0?1:b*2+1+a));
	}
	return 0;
}

