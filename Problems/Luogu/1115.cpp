/*
����Ӷκ�
����������DP�����ڵ�ǰ���������ѡ�Ͳ�ѡ���־��ߣ�ע��ȫ�Ǹ��������
	  ��һ�ַ�����ά����Сǰ׺�ͣ�ÿ���õ�ǰǰ׺��-��Сǰ׺�͸��´� 
*/
#include<algorithm>
#include<cstdio>
using namespace std;
const int INF=0x3f3f3f3f;
int n,a,ans=-INF,cur=0;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		ans=max(ans,(cur=max(cur+a,a)));
	}
	printf("%d",ans);
	return 0;
}
/*#include<algorithm>
#include<cstdio>
using namespace std;
const int INF=0x3f3f3f3f;
int n,a,ans=-INF,cur=0,mn=0,sum=0;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		sum+=a;
		ans=max(ans,sum-mn);
		mn=min(mn,sum);
	}
	printf("%d",ans);
	return 0;
}*/
