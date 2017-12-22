/*
������Ϸ 2
�����������뵽��Ҫʹ��������ȱ����������Ų��ᷭ��
	  Ȼ���ص����ڷ��̵���д��
	  ��һ����д�˸�
	  opt[i][j]=max(opt[i-1][j],opt[i-1][j-1]+a[i]-b[i]*(m-j))
	  �����Ǵ�ģ�����ʹ��(m-j)�൱�ڸ��Ժ��������ֵ�ȼ���b[i]
	  ���ⲻ����״̬���޺�Ч�ԣ�״̬Ҫ��֮ǰ����Ϣ�õ���
	  Ϊʲô�أ�ע��Ҫȡmax����������Ϊ����ĺ�һ����Ϊ����һ��ֵ����Ȼ֮���״̬�����a[i]����
	  ��ʹ�þ��߲�ѡ������⣬�����ᵼ�´�⣬��������û������
	  ֻ��ת�����̣����b[i]������
	  opt[i][j]=max(opt[i-1][j],opt[i-1][j-1]+a[i]-b[i]*(j-1));
	  ʵ���ϵ�һ�������൱�ڵ�ǰ״̬���ѡ��ѡa[i]������
	  ����һ������Ϊ�ǲ��ǵ�һ��ѡa[i] 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=200;
struct data{
	int a,b;
	bool operator < (const data &d)const{
		return b>d.b;
	}
}da[MAXN+3];
int n,m,opt[MAXN+3][MAXN+3];
int dp(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			opt[i][j]=max(opt[i-1][j],opt[i-1][j-1]+da[i].a-da[i].b*(j-1));
		}
	}
	return opt[n][m];
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>da[i].a;
	for(int i=1;i<=n;i++)cin>>da[i].b;
	sort(da+1,da+n+1);
	cout<<dp();
	return 0;
}
