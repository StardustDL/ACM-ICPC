/*
�ɶ�
���������������������̶��˵�һ��Ԫ�ؾͲ������� 
*/
#include<iostream>
#include<cmath>
#include<bitset>
using namespace std;
const int MAXN=10;
int n,k,a[MAXN+3],s[MAXN+3],ans=0,mn=1<<30,p=0;
bitset<MAXN+3> used=0;
void dfs(int ind){
	if(ind>n){
		if(abs(s[n]-s[1])<=k)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!used[i]&&abs(a[i]-s[ind-1])<=k){
			s[ind]=a[i];used[i]=1;
			dfs(ind+1);
			used[i]=0;
		}
	}
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	s[1]=a[1];used[1]=1;//��������Сֵ���������ΪֻҪ�н⣬a[1]������ǿ��еģ�ע���ǻ��� 
	dfs(2);
	cout<<ans;
	return 0;
}
