/*
�˫��
��������can[i][j]��ʾ�����߶�Ϊi,j�Ƿ���У�Ȼ�󱳰�����
	  ע�⼸��ϸ�ڣ��ڲ�ѭ������Ҫ���أ�Ȼ��ѡ��һά����ת�ƣ�������ά�ֱ�ת�ƣ����к�Ч��
	  ������ʱѭ����1����Ҫѭ����0��0һ�����У�
	  �����ĸ��Ӷ���:n*sum^2������Ҳ�ܹ�
	  ��һ��״̬��ʾ��
	  ��f[i,j]��ʾʹ��ǰi��ˮ��,����߶Ȳ�Ϊj��˫��ʱ,�ϰ����Ǹ��������߶��Ƕ��١�
  		�����Ļ�,����ÿһ��ˮ���������־���,��ʹ��,�ŵ�������,�ŵ�������.���ŵ������ϻ����������,һ��ʹ�����ĸ߶ȳ����˸���,����û�г����� 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2000,INF=0x3f3f3f3f;
bool can[MAXN+3][MAXN+3];
int n,a[100+3],sum=0,ans=-1; 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),sum+=a[i];
	can[0][0]=1;
	sum>>=1;
	for(int i=1;i<=n;i++){
		for(int j=sum;j>=0;j--){
			for(int k=sum;k>=0;k--){
				if(j>=a[i])can[j][k]|=can[j-a[i]][k];
				if(k>=a[i])can[j][k]|=can[j][k-a[i]];
			}
		}
	}
	for(int i=sum;i>=1;i--){
		if(can[i][i]){ans=i;break;}
	}
	if(ans==-1)puts("Impossible");
	else printf("%d\n",ans); 
	return 0;
}

