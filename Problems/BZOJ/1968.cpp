/*
[Ahoi2005]COMMON Լ���о�
����������˼ά������ÿ����������Ĺ�����1-n�������У�iһ�����Գ�Ϊn/i������Լ����Ҳ�����е�Լ������n/i��i������ɨһ���ۼӴ𰸾ͺ��ˡ� 
*/
#include<cstdio>
int main(){
	int n,ans=0;scanf("%d",&n);
	for(int i=1;i<=n;i++)ans+=n/i;
	printf("%d",ans);
	return 0;
}

