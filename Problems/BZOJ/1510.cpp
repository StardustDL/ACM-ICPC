/*
[POI2006]Kra-The Disks
���������ȿ��԰Ѱ뾶��һ��ǰ׺min�������õ�һ���ݼ��İ뾶���У�Ȼ�����һ��ѯ��x������ѯ������ݼ�����[1..lastans-1]�����һ��>=x��λ�á�
	  �����б�ɸ��ģ��õ�һ�������ģ�ֱ�ӵ���upper_bound(x)-1���ɣ���һ����lastans�����滹�����档 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=300000,INF=0x3f3f3f3f;
int a[MAXN+3],n,m,lst;
int main(){
	scanf("%d%d",&n,&m);a[0]=-INF;
	for(int i=1;i<=n;i++){scanf("%d",&a[i]);a[i]=max(a[i-1],-a[i]);}
	lst=n+1;
	for(int x,i=1;i<=m;i++){
		scanf("%d",&x);
		int t=upper_bound(a+1,a+n+1,-x)-a-1;//ȡ�����һ������t�� 
		if(t>=lst)lst--;else lst=t;
	}
	printf("%d\n",max(lst,0));//ע��������lst����Ϊ�� 
	return 0;
}

