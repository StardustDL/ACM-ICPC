/*
[SHOI2008]СԼ������ϷJohn 
�����������nim��Ϸ�����в�ͬ�������������һ��ȡ���䡣�����nim��һ����������ʯ�Ӹ���xor�������==0��˵��brotherӮ������johnӮ������Ҳ�������ģ���ΪֻҪѡ��ʱ������һ������ǿ�ȶ��������һ���������ǵ�ʯ��ȫ������1��ʱ�����ǡǡ�෴������һ�¾ͺ���
*/
#include<cstdio>
using namespace std;
const char STR[2][10]={"Brother","John"};
int n,ans,x,k; 
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);ans=0;k=1;
		while(n--){
			scanf("%d",&x);
			ans^=x;
			if(x!=1)k=0;
		}
		puts(STR[(ans!=0)^k]);
	}
	return 0;
}

