/*
[BeiJing2011��ѵ]����
�����������ƶ������޹أ���Ϊ���������Ʋ�����2��ͬʱ��ͬ��ͬ���ƶ���������ֻҪ���������и������յ㣬��������ô�ۼ������ģ��ܵ���ĵ㵽����ľ������ȣ�
		�ھ����У��Խ��ߵľ����ǲ����ġ���������Ҫ����ھ��������ʡ����ǽ�������ηŵ�ÿ����������ԭ���ε����Ͻǵ�ÿ����ľ���
		�������Ǽ���������(i,j),(i,k)���м��ƶ�һ����k>j+1����ô���ǿ��Ի�õļ�ֵΪk-j�����������Ƕ���ÿ�����ÿ���ǵ�����Ϊ a[(i,j)]=i*i+j*j�������������㿪ʼ������Ϊi*i+j*j+i*i+k*k���ƶ�֮���������Ϊ(i,j+1),(i,k-1)���� ʱ������Ϊi*i+(j+1)*(j+1)+i*i+(k-1)����ʱ��������Ϊ2*k-2*j��Ϊ��ü�ֵ��2������Ϊ�������еļ�ֵ��ö����Բ��������ķ������������ǿ��������ʼ����������ͣ���������������ͣ����>>1���Ǵ𰸡� 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=200,INF=0x3f3f3f3f;
typedef long long LL;
int n,m;
LL s1,s2;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1,x;j<=m;j++){
			scanf("%d",&x);
			s1+=((i*i)+(j*j))*x;
		}
	for(int i=1;i<=n;i++)
		for(int j=1,x;j<=m;j++){
			scanf("%d",&x);
			s2+=((i*i)+(j*j))*x;
		}
	printf("%lld\n",s1-s2>>1);
	return 0;
}
