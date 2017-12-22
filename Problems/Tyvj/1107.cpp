/*
Hankson��Ȥζ��
������1��Ԥ����trunc(sqrt(2000000000))��50000���ڵ����������������ɸ��������ʱ�����˵�ˣ�
��	��2����ʼ��sum=1��Ȼ��ѭ����������a0��a1��b0��b1�����ж��ٸ����������ӣ���Ϊaa0��aa1��bb0��bb1��ͬʱ��a0��a1��b0��b1���ĸ����ֱ���ȥ���и��������ӣ�
��	��3������aa0��aa1��bb0��bb1ȷ��������������������������ӵĸ����Ͻ�high���½�low��
��	��4������Ҫ������ĸ���sum:=sum*(high-low+1)�� 
		���Ǳ����WA��һ�����ݣ���֪��Ϊʲô������
		��������gcd��lcm�����ʣ�gcdΪÿ�����ֽ���������ָ��ȡ��Сֵ��lcmΪȡ���ֵ 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<vector> 
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
bitset<50003> vis=0;
vector<int> pris;
int a0,a1,b0,b1,a2,a3,b2,b3,ans=1;
int main(){
	for(int i=2;i<=50000;i++)if(!vis[i]){pris.push_back(i);for(int j=i*i;j>0&&j<=50000;j+=i)vis[j]=1;}
	int n;scanf("%d",&n);
	while(n--){
		scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
		ans=1;
		for(int i=0;i<pris.size();i++){
			a2=a3=b2=b3=0;
			while(a0>1&&a0%pris[i]==0)a2++,a0/=pris[i];
			while(a1>1&&a1%pris[i]==0)a3++,a1/=pris[i];
			while(b0>1&&b0%pris[i]==0)b2++,b0/=pris[i];
			while(b1>1&&b1%pris[i]==0)b3++,b1/=pris[i];
			//if(a2<a3){ans=0;break;}
			//if(b2>b3){ans=0;break;}
			if(b3<a3){ans=0;break;}
			if(b2>=b3&&a2<=a3){
				ans*=(b3-a3+1);
			}
			else if(b2<b3&&a2>a3&&a3!=b3){ans=0;break;}
		}
		printf("%d\n",ans);
	}
	return 0;
}

