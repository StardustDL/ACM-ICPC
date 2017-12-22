/*
�˻����
����������DP�������ɵ�iλ����jλ������s[i][j]����opt[i][j]��ʾ��[1..i]�����Χ�ڲ���j���˺ŵ����Ž�
		��opt[i][j]=max{opt[p][j-1]*s[p+1][i]|j<=p<i} 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=43,MAXK=7;
int k,opt[MAXN][MAXK],s[MAXN][MAXN],n;
char str[MAXN]; 
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>k;
	cin>>str;
	for(int i=1;i<=n;i++){
		s[i][i]=str[i-1]-'0';
		for(int j=i+1;j<=n;j++){
			s[i][j]=s[i][j-1]*10+str[j-1]-'0';
		}
	}
	for(int i=1;i<=n;i++)opt[i][0]=s[1][i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			int &t=opt[i][j];
			for(int p=j;p<i;p++){
				t=max(t,opt[p][j-1]*s[p+1][i]);
			}
		}
	}
	cout<<opt[n][k];
	return 0;
}
