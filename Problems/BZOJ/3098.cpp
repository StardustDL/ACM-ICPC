/*
Hash Killer II
��������ʵ���ʾ�����mod��������MOD�������������ظ��� 
	  ���һ����������23����23�����ϵ��ˣ���ô�����������˵�������ͬ�ĸ���Ҫ����50%���������n���������ѡ������ô���ѡ��n�ξ���ѡ����ͬ������������Rp broken)
	  ͬ���ģ������Hashֵ��0��1000000007.
	  �Ǿ�Ҫѡ���10^5�Σ�Ψһע�����lҪȡ��ʹ�÷���������Mod
	  ����Ͳ�������2��������ͬ��Hashֵ
*/
#include<cstdio>
#include<cstdlib> 
using namespace std;
const int MAXN=100000,INF=0x3f3f3f3f;
int main(){
	srand(0);
	printf("%d %d\n",MAXN,20);
	for(int i=1;i<=MAXN;i++)putchar(rand()%26+'a');
	puts("");
	return 0;
}

