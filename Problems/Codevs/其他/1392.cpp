/*
�ϲ�ɵ��
������������ʯ�ӹ鲢2һ�� 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100,INF=500;
int n,m,w[2*MAXN+3],s[2*MAXN+3],fmax[2*MAXN+3][2*MAXN+3],fmin[2*MAXN+3][2*MAXN+3],i,j,k;
int main(){
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>w[i];
		w[i+n]=w[i];
	}
	for(i=1;i<=2*n;i++){
		s[i]=s[i-1]+w[i];
	}
	for(int len=2;len<=n;len++){
		for(i=1;i<=2*n-len+1;i++){
			j=i+len-1;
			int m=0;
			for(k=i;k<j;k++){
				m=max(m,fmax[i][k]+fmax[k+1][j]); 
			}
			fmax[i][j]=m+s[j]-s[i-1];
			m=INF;
			for(k=i;k<j;k++){//ö�������е����пɻ��ֵ㣬����Ϊ[i..k]��[k+1..j]�������� 
				m=min(m,fmin[i][k]+fmin[k+1][j]);//Ѱ����Сֵ 
			}
			fmin[i][j]=m+s[j]-s[i-1];//��Сֵ+�ϲ������ѵĴ���(s[k]-s[i-1]+s[j]-s[k]) 
		}
	}
	int amax=0,amin=INF;
	for(int i=1;i<=n;i++){
		amax=max(amax,fmax[i][i+n-1]);
		amin=min(amin,fmin[i][i+n-1]);
	}
	if(m>amax)cout<<"It is easy";
	else if(m<amin)cout<<"I am..Sha...X";
	else cout<<"I will go to play WarIII";
	return 0;
}
