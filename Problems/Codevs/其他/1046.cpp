/*
���мҵ�Ԥ��
������̰��
	  1.������ܵ���ļ���վ�У��ͷ��бȵ�ǰ����վ���˵ģ��͵�һ������������ͷѱȵ�ǰ����վ���˵ļ���վȥ���ڵ�ǰ����վ���ϸպ��ܵ��Ǹ�����վ���ͣ�ʹ�������վʱ���ù⡣
	  2.������ܵ���ļ���վ�У��ͷ�û�бȵ�ǰ����վ���˵ģ��Ǿ��ڴ˼���վ�����ͣ�Ȼ�󿪵��ܵ���ļ���վ���ͷ���С�ļ���վȥ��
	  һֱѭ����ȥ�����ܵ����յ��ˣ����Һ����վ���ͷ�û�и�С���ˣ���������մ𰸡�
	  ���Ҳ�������վ�ˣ����޽⡣ 
*/
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
double d1,c,d2,p,n,i[22],dis[22],pi[22],x[22],shen[22],h,flag,len,sum;
int j,k;
double go(){
	len = c*d2;
	shen[0] = 0;
	for( k = 0; k <= n;){
		j = k + 1;
        if(dis[j] - dis[k] > len) return 0;
        while(dis[j] - dis[k] <= len && j <= n){
            if(pi[j] < pi[k])break;
            j++;
        }
        if(dis[j] - dis[k] < len){
            if(shen[k]*d2 >= dis[j] - dis[k])
                shen[j] = shen[k] - (dis[j] - dis[k])/d2;
            else
                x[k]=(dis[j] - dis[k])/d2 - shen[k];
        }
        else{
            x[k] = c - shen[k];
            j = k + 1;
            shen[j] = c - (dis[j]-dis[k])/d2;
        }
        k=j;
    }
    sum=0;
    for(int f = 0; f <= n; f++)
        sum += x[f]*pi[f];
    return sum;
}
int first(){
    while(cin>>d1){
        memset(pi,0,sizeof(pi));
        memset(i,0,sizeof(i));
        memset(dis,0,sizeof(dis));
        memset(x,0,sizeof(x));
        flag = 0;
        cin>>c>>d2>>pi[0]>>n;
        for(k = 1; k <= n; k++)cin>>dis[k]>>pi[k];
        dis[k] = d1;
        flag = go();
        if(!flag)cout<<"No Solution"<<endl;
        else{
            cout.setf(ios::fixed);
            cout.precision(2);
            cout<<flag<<endl;
        }
    }
    return 0;
}
int main(){
    first();
    return 0;
}


