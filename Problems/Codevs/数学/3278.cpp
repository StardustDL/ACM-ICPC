/*
��Сm �κ�����
���������ִ𰸣������㣬����1..mid�У�������mid+1..n�� 
*/ 
#include<iostream>
#include<algorithm>
using namespace std;
int n,a[1003],m;
bool check(int ans){
	int cnt=0,s=0;
	for(int i=1;i<=n;i++){
		if(s+a[i]<=ans)s+=a[i]; 
		else{
			s=a[i];if(++cnt>m)return false; 
		}
	}
	return cnt+1<=m;
}
int dichotomy(int l,int r){
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	return l;
}
int main(){
	cin>>n>>m;int sum=0,mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];sum+=a[i];mx=max(mx,a[i]); 
	}
	cout<<dichotomy(mx,sum);//ע��ӵ���Ԫ�����ֵ��ʼ 
	return 0;
}
