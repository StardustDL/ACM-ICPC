/*
Prime Path
���⣺��������λ������a��b��ÿ���滻a��һ����λ����a�䵽b������ÿ���滻�������ɵ�����λ��Ҳ������������������Ҫ���ٲ���
������ö��ÿһλ���ж����� 
*/
#include<iostream>
#include<algorithm>
#include<queue> 
#include<cstring>
#include<cstdio>
#include<cmath>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=10000;
bitset<MAXN+3> vis;
bool isprime(int n){
    for(int i=2;i*i<=n;i++)if(n%i==0)return false;
    return true;
}
struct number{
    int num,step;
    number(int a,int b):num(a),step(b){}
};
queue<number>q;
int bfs(int s,int t){
	while(!q.empty())q.pop();
    vis=0;
    q.push(number(s,0));
    while(!q.empty()){
        number u=q.front();q.pop();
        if(u.num==t)return u.step;
        for(int i=3;i>=0;i--){//�����λ��ʼ
            double p=(double)pow((double)10,(int)i);
            int x=(u.num/(int)p)%10;
            for(int j=0;j<10;j++){
                if(i==3&&j==0)continue;//���λ����Ϊ0
                int y=u.num+(j-x)*p;//�ж���һ����
                if(!vis[y]&&isprime(y)){//���û����������������
                    vis[y]=1;
                    q.push(number(y,u.step+1));
                }
            }
        }
    }
    return -1;
}
int main(){
    int n,s,t;
    scanf("%d",&n);
    while(n--){
        int target;
        scanf("%d%d",&s,&t);
        int ok=bfs(s,t);
        if(ok!=-1)printf("%d\n",ok);
        else printf("Impossible\n");
    }
    return 0;
}

