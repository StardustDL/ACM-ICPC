/*
Monster
�������ܿ������������������
	  1.OTK��2.��k�غϿ�����3.��Ϣ֮��Ѫ���ȳ�ʼ�ͣ�
	  ע�⿪long long ����� 
*/
#include<cstdio>
using namespace std;
const char ANS[2][5]={"NO","YES"};
long long h,a,b,k;int cnt=0;
int main(){
	while(scanf("%lld%lld%lld%lld",&h,&a,&b,&k),h+a+b+k)
		printf("Case #%d: %s\n",++cnt,ANS[(a>=h)||(a*k>=h+b*(k-1))||(a*k>b*(k+1))]);
	return 0;
}

