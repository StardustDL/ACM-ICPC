/*
[Beijing wc2012]�㲻������ʽ
��������ת��Ϊ����Ϊy=(q/p)x��ֱ������ߺ�����ĵ�ĸ�����ע�������ָ����x,y�ķ�Χ������һ�룬
		���Դ����ܵ������ķ�֮һ 
		ע��p==q��p!=qʱ�ֱ���(p-1)*(p+1)/4��(p-1)*(q-1)/4 
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long LL;
LL p,q; 
int main(){
	scanf("%lld%lld",&p,&q);
	printf("%lld",(p==q)?(p-1)*(q+1)/4:(p-1)*(q-1)/4);
	return 0;
}




