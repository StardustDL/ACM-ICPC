/*
[HAOI2007]��������
��������Ҫ�����ÿ������ͷ������������г��ȣ�����LIS���յó�����ÿ�����ֽ�β��������г��ȣ�����������Ҫ��������е���������������DP������ڵ��ŵ������У���ÿ�����ֽ�β����½������г��ȣ�����൱��ԭ��������ÿ�����ֿ�ͷ������������г����ˡ�
	  Ȼ��������𰸼��ɣ�ע�Ⲣ����Ҫ��¼ 
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=10000; 
int n,m,cnt,a[MAXN+3],f[MAXN+3],best[MAXN+3],len; //f[i]=�Ե�i�����ֽ�β����½������г��ȣ��ȼ����Ե�i�����ֿ�ͷ������������г��ȣ���best[i]=����Ϊi��LIS�ĵ�i��Ԫ��,cnt=LIS����
void solve(int x){ //�������Ϊx������������
	int last=0; //�Ѿ�������������е����һ������
	for(int i=1;i<=n;i++)
		if(f[i]>=x&&a[i]>last){
			printf("%d",a[i]);
			if(x!=1)putchar(' ');//����������һ�����֣���Ҫ����ո�BZOJ���񲻻���˵���ĩ�ո�����Ҫ����������WA
			last=a[i];
			x--;
			if(!x) break;
		}
	puts(""); 
}
int ef(int x){ //����Ѱ�Ҵ���x����ӽ�x��Ԫ�أ�ע��lower_bound:ָ���ֵ>= key�ĵ�һ��Ԫ�أ�upper_bound:ָ���ֵ> key�ĵ�һ��Ԫ�� 
	int l=1,r=cnt,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(best[mid]>x){ans=mid;l=mid+1;}
		else r=mid-1;
	}
	return ans;
}
void preDP(){ //DPԤ����
	for(int i=n;i>=1;i--){
		int t=ef(a[i])+1;
		f[i]=t;
		cnt=max(cnt,t);
		best[t]=max(best[t],a[i]);
	}
	//����ʹ��lower_bound�����ȵ�������������������У�������½�����ת�ɸ����������������Լ�д���� 
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	preDP();
	scanf("%d",&m);
	while(m--){
		scanf("%d",&len);
		if(len<=cnt)solve(len);
		else puts("Impossible");
	}
	return 0;
}
