/*
[POI2007]��Ȼ���ܵ�Gaz
������1.��Ȼ���������ϻ��򶫽���ܵ�
      2.�������پ��������ŷ����þ���
      �����зֿ����ǣ����ڴ���˵������������x���Ǹ��ģ�y�������ģ�����תվ���෴ 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
typedef long long LL;
int n;
LL ans=0;
int main(){
	scanf("%d",&n); 
	for(int i=1,x,y;i<=n;i++){
		scanf("%d%d",&x,&y);
		ans-=x,ans+=y;
	}
	for(int i=1,x,y;i<=n;i++){
		scanf("%d%d",&x,&y);
		ans+=x,ans-=y;
	}
	printf("%lld",ans);
	return 0;
}

