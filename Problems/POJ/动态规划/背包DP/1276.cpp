/*
Cash Machine
���⣺�и��ֲ�ͬ��ֵ�Ļ��ң�ÿ����ֵ�Ļ����в�ͬ�����������ҳ�������Щ���ҿ��Դճɵ���ӽ���С�ڵ��ڸ���������cash�Ľ� 
���������ر�����������ֻ���Ƿ���ڵ����⣬���Կ�����������ȫ�����ķ��������������ȷ����ʱ����֤�� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=10,MAXM=100000;
int cash,n,c[MAXN+3],d[MAXN+3],cnt[MAXM+3],opt[MAXM+3];
bool input(){
	if(!(cin>>cash>>n))return false;
	for(int i=1;i<=n;i++)cin>>c[i]>>d[i];
	return true;
}
int dp(){
	memset(opt,0,(cash+3)*sizeof(int));//����ϴ󣬲�Ҫֱ����sizeof(opt) 
	for(int i=1;i<=n;i++){
		memset(cnt,0,(cash+3)*sizeof(int));//cnt��¼��ǰ��Ʊ�ڲ�ͬ�ֽ�Ҫ�����Ž��µ�ʹ������ 
		for(int j=d[i];j<=cash;j++){
			if(cnt[j-d[i]]+1<=c[i]&&opt[j-d[i]]+d[i]>opt[j]){//���������ã��Ҹ��� 
				opt[j]=opt[j-d[i]]+d[i];
				cnt[j]=cnt[j-d[i]]+1;
			}
		}
	}
	return opt[cash];
}
int main(){
	while(input())cout<<dp()<<endl;
	return 0;
}
