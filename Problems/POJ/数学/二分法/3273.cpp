/*
Monthly Expense
���⣺һ�������ֳ�M�ݣ�MIN{MAX{ÿ�������ĺ�}} 
���������ִ𰸣����Ƕ���д���ˡ�����ѧ����һ���µĶ��ַ� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100000;
int n,m,a[MAXN+3];
bool check(int v){
	int cur=1,s=0;
	for(int i=1;i<=n;i++){
		if(s+a[i]<=v)s+=a[i];
		else{
			s=a[i];cur++;
		}
	}
	return cur<=m;
}
int ef(int l,int r){
	int mid=(l+r)>>1;
	while(l<r){
		if(!check(mid)){
			l=mid+1;//�˴���û�п��ܶ���mid����� 
		}
		else r=mid-1;
		mid=(l+r)>>1;//������м�ֵ 
	}
	return mid;
}
int main(){
	scanf("%d%d",&n,&m);
	int low=0,high=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		low=max(low,a[i]);
		high+=a[i];
	}
	printf("%d",ef(low,high));
	return 0;
}

