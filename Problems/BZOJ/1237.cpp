/*
[SCOI2008]���
����������Ϊ�Ƕ���ͼ���Ȩƥ�䣬��ʵ���ϲ���
	  ���������������Ԫ�ز��������һ ���ƣ��������һһƥ�伴�ɡ�
	  ����������ƣ���ô������ȵ�Ԫ�ؾ�Ҫ����ǰ����е�������Ȼ��������Զ�ĵ��������������ĵ����š�
	  ��ô����Ҫ�ڶ��ķ�Χ�ڵ������ܱ�֤�����أ���ţ�����Ľ������������������Ԫ���ڵ������ɡ���ô֤���أ�
	  �����϶��ǲ��еģ�����n=3������Ԫ�ؾ���Ӧ��ȣ���ʱ����Ҫ����Ԫ��֮���������ô����4������Ԫ�ض�Ӧ����أ���ʱǰ���������������������ɵõ����š�����ò����ĸ�������
	  �����Ļ� DP���ɡ�opt[i]��ʾǰi��Ԫ��ƥ���������ֵ��opt[i]��opt[i-1],opt[i-2],opt[i-3]ת��
	  ��long long �ܷ��ˣ����ֵ��Ҫ���1LL<<62�������Ӻ�ʱ�ᱬ��Ҫ�� 0x7ffffffffffll��10��f������������� 0x7ffffffffffffffll����f���࣬������ͻᱬ�� 
	  	Ȼ��-1Ҫ��-1LL��һ��longlong���־��к�׺LL 
	  	long long �10^20 
*/ 
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
const LL MAXN=100000,INF=0x7ffffffffffll;
int a[MAXN+3],b[MAXN+3],n;
LL opt[MAXN+3];
void input(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d %d",&a[i],&b[i]);
	sort(a+1,a+n+1);sort(b+1,b+n+1);
}
LL G(LL a,LL b){return a==b?INF:abs(a-b);}//����������㣬�����ܻ���ΪINF+INF���� 
LL dp(){
	opt[1]=G(a[1],b[1]);
	opt[2]=min(opt[1]+G(a[2],b[2]),G(a[1],b[2])+G(a[2],b[1]));
	for(int i=3;i<=n;i++){
		opt[i]=opt[i-1]+G(a[i],b[i]);//���ܻ���ΪINF+INF����
		opt[i]=min(opt[i],opt[i-2]+G(a[i-1],b[i])+G(a[i],b[i-1]));
		opt[i]=min(opt[i],opt[i-3]+
			min(G(a[i],b[i-1])+G(a[i-1],b[i-2])+G(a[i-2],b[i]),
				G(a[i],b[i-2])+G(a[i-1],b[i])+G(a[i-2],b[i-1])));
	}
	return opt[n]<INF?opt[n]:-1LL;//ע��LL 
}
int main(){
	 printf("%lld",INF+INF);
	input();
	printf("%lld",dp());
	return 0;
}
