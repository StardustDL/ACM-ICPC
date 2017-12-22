/*
PA2014Final Zarowki
������̰�ģ���p���������̰��ѡȡ�Ϸ���w�����ģ���p-w��������
		δƥ���wʹ��k������k����ʣ�࣬�Ӷ���ȡk�����Ļ��������´� 
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef multiset<int>::iterator mit;
const int MAXN=500000; 
long long ans;
int p[MAXN+3],w[MAXN+3],n,k;
multiset<int> st;
priority_queue<int>q;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<=n;i++){scanf("%d",&w[i]);st.insert(w[i]);}
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++){
		mit it=st.upper_bound(p[i]);
		if(it!=st.begin()){
			q.push(p[i]-*(--it));
			st.erase(it);
			ans+=p[i];
		}
	}
	if(st.size()>k){puts("NIE");return 0;}
	for(mit it=st.begin();it!=st.end();it++)
		k--,ans+=*it;
	while(k--){ans-=q.top();q.pop();}
	printf("%lld\n",ans);
	return 0;
}
