/*
�����������
������ע��n�ϴ�Ҫ��nlogn�ķ��������񻹿�����״���飬Ҫѧϰһ��
	  LIS��nlogn�����������Ǿ��ߵ����ԣ�������Բ�ά�����߱���ά��һ��ջ��ջ��Ԫ�ص���
	  ��ÿ��Ҫ�����Ԫ�أ�����ջ���󣬷ŵ�ջ���Ϸ�
	  ���򣬽�ջ�б��������ĵ�һ�����滻Ϊ������������������еĴ�Сû�䣬��Ǳ��������
	  ע��˷����������������ջ�������Ԫ�ؿ��ܲ�������˳���Ⱥ�ֻ�����������ȷ��
	  �������һ��ѡһ�����أ�
	  ֻҪ����֮ǰ�����������ɾ������֮�����С������ɾ������ 
*/
#include<iostream>
#include<cstring> 
#include<algorithm>
using namespace std;
const int MAXN=200000;
int n,k,sta[MAXN+3],a[MAXN+3],top=0;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<k;i++)if(a[i]>a[k])a[i]=-1;
	for(int i=k+1;i<=n;i++)if(a[i]<a[k])a[i]=-1;
	sta[0]=-1;
	for(int i=1;i<=n;i++){
		if(a[i]==-1)continue;
		if(a[i]>sta[top]){
			sta[++top]=a[i];continue;
		}
		int p=lower_bound(sta+1,sta+top+1,a[i])-sta;
		sta[p]=a[i];
	}
	cout<<top;
	return 0;
}
