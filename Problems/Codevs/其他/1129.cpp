/*
������Ϸ
�������ɲ��Կ�֪��ֻ���ܵõ����Ž⣬����ά���δ�ֵ���� 
*/
#include<iostream>
#include<algorithm>
using namespace std;
int ns[502][502],n,ans=-1;
int main(){
	cin>>n;
	int x;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i;j++){
			cin>>x;
			ns[i][i+j]=ns[i+j][i]=x;
		}
	}
	for(int i=1;i<=n;i++){
		int m1=-1,m2=-1;
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(ns[i][j]>m1){
				m2=m1;
				m1=ns[i][j];
			}
			else m2=max(m2,ns[i][j]);
		}
		ans=max(m2,ans);
	}
	cout<<1<<endl;
	cout<<ans;
	return 0;
}  
