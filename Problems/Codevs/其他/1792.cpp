/*
�ֽ�������
����������1-n�е�������ö��ÿ���������ɣ���һ�ַ�����ɸ����ʱͬʱ���зֽ⣬�������� 
ע�⣺bitset�����ֵ�Ļ����Ͳ��ܿ�̫�����￪��1<<22�͵����ˣ����������ֵ�����Կ���1<<31�������ύʱ����� 
*/
#include<iostream>
#include<bitset>
using namespace std;
/*����1�� 
const int MAXN=1<<29;
bitset<MAXN> isp;
int pris[100003],prin=0,n;
bool isfirst=true;
void prime(int t){
	//isp=0;//ע������ 
	for(int i=2;i<=t;i++){
		if(!isp[i]){
			pris[++prin]=i;
			for(int j=i*i;j<=t;j+=i){
				isp[j]=1;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	prime(n);
	cout<<n<<"=";
	for(int i=1;i<=prin;i++){
		while(n%pris[i]==0){
			if(!isfirst)cout<<"*"<<pris[i];
			else{
				isfirst=false;
				cout<<pris[i];
			}
			n/=pris[i];
		}
	}
	return 0;
}*/
const int MAXN=1<<25;
bitset<MAXN> isp;
int n;
bool isfirst=true;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	cout<<n<<"=";
	for(int i=2;i<=n;i++){
		if(!isp[i]){
			while(n%i==0){
				if(!isfirst)cout<<"*"<<i;
				else{
					isfirst=false;
					cout<<i;
				}
				n/=i;
			}
			for(int j=i*i;j<=n;j+=i){
				isp[j]=1;
			}
		}
	}
	return 0;
}
