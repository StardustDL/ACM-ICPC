/*
���ִ�
��������a��������У�ͬʱ����һ��b�����a������Ԫ�س��ֵĴ��������磺a=��1,2,3��
		��b[1]=1; b[2]=1; b[3]=1;
		Ȼ��������ָ�룬i,j��ʾͷ��β��ÿ��inc(j)��Ȼ���a[j]Ԫ����ӣ����a[j]��1..n�ķ�Χ֮�ڣ���a[j]��δ���ֹ�(b[a[j]]=0)��ôinc(k),k��һ������������ʾ�������ж��ٸ���1..n�е�Ԫ�ء�
		��a[j]Ԫ����Ӻ���Ҫ���ж�ͷ���Ʋ������������a[j]��Ӻ󣬶�ͷԪ�س�����һ�����ϣ���ô��ͷ���У��ڶ�ͷ���к����µĶ�ͷ��Ȼ���ֹ������߲���1..m�ķ�Χ�ڣ���ô��ͷ�������ӡ�
		���Ѷ���Ķ�ͷ�Ƴ������ǿ������ж�k�������ǰk=n�����ҵ�ǰ���г���(j-i+1)�ȼ�¼�е�ֵС����ô����������г���ȥ������Сֵ��
		�ظ����ϲ���ֱ��j=m��
		������г�����Сֵmin�� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=200000,INF=0x3f3f3f3f;
int n,m,a[MAXN+3],cnt[MAXN+3],k=0,ans=INF;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]); 
	for(int l=1,r=1;r<=n;r++){
		if((cnt[a[r]]++)==0)k++;
		while(cnt[a[l]]>1)cnt[a[l++]]--;
		if(k==m)ans=min(ans,r-l+1);
	}
	if(ans==INF)puts("NO");
	else printf("%d",ans); 
	return 0;
}

