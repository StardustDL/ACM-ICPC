/*
Bridging signals
���⣺ԭ�����Ҷ˿�Ӧ����˳�����ӡ�����ֻ���г�������·��ʹ���κ���·�����ཻ��ϣ����дһ������������ʣ�¶�����·��
������LIS nlogn 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=40000,INF=0x3f3f3f3f;
int T,n,s[MAXN+3],ans,x,id; 
int main(){
	for(scanf("%d",&T);T;T--,ans=0){
		scanf("%d",&n);memset(s,INF,sizeof(s));
		while(n--){
			scanf("%d",&x);
			s[id=lower_bound(s+1,s+ans+1,x)-s]=x;
			ans=max(ans,id);
		}
		printf("%d\n",ans);
	}
	return 0;
}

