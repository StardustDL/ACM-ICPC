/*
Beer Refrigerator
���⣺����һ��������������ʹ��������С���󳤿�ߣ�����߾�Ϊ������
�������������������ӣ�Ȼ����ö��3����ĳ��ȣ�������С����� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000000;
typedef long long LL;
vector<int> fi;
int n,mn=INF,a,b,c,t;
int main(){
	scanf("%d",&n);
	for(int i=1;((LL)i)*i<=n;i++){
		fi.push_back(i);
		fi.push_back(n/i);
	}
	for(int i=0;i<fi.size();i++){
		for(int j=0;j<fi.size();j++){
			if(n%(fi[i]*fi[j])!=0)continue;
			for(int k=0;k<fi.size();k++){
				if(n==fi[i]*fi[j]*fi[k]&&(t=fi[i]*fi[j]+fi[j]*fi[k]+fi[k]*fi[i])<mn){
					mn=t;
					a=i,b=j,c=k;
				}
			}
		}
	}
	printf("%d %d %d",fi[a],fi[b],fi[c]);
	return 0;
}

