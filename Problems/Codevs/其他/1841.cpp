/*
��ˮ����
���⣺���ⲻ����⣬ֻҪÿ���µ�ˮ����֮ǰ��ˮ����һ���ȴ����������Ž� 
������n���ǱȽ�С�ģ�������N^2�ǹ����˵ģ����ֵ�ǰ��ı���һ����һ�α����º󣬻�������0����ôֱ����������
	  ����һ�����ʣ��������¶�֮�ͼ�Ϊ��Ҫ���ߵ��¶ȣ���������ʲ�֪����ô���� 
*/
#include<iostream>
#include<cstdio>
using namespace std;
int n;
double T[300003];
double solve(int n){
	double ans,t=0,k=4200.0/n;
	int cur=1;
	for(int i=1;i<=n;i++){
		T[i]=0;
		for(int j=cur;j<i;j++){
			//if(T[j]-T[i]<0.01)continue;
			T[j]=T[i]=(T[j]+T[i])/2;
		}
		//if(100-T[i]<0.1)break;
		t+=(100-T[i]);T[i]=100;
		while(T[cur]<0.00001)cur++;
		//cout<<t<<endl;
	}
	ans=k*t;
	return ans;
}
int main(){
	cin>>n;
	printf("%.2lf\n",solve(n));
	return 0;
}
