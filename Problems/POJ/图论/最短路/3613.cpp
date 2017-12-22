/*
Cow Relays
���⣺�ʴ�S �� T �����ߵĸ���ǡΪk�����·�Ƕ��١�
������Floyd��Ͽ����ݣ�ע�ⲻ�Ǽ򵥵ľ���ˣ��������·����
	  floyd��ÿ��ʹ��һ���м��kȥ����i,j֮��ľ��룬��ô���³ɹ���ʾi,j֮��ǡ��һ����kʱ�����·��
	  	�����N - 1��floyd��ô������i,j֮�����N - 1 ����ʱ�����·�ˡ�
	  	floydÿ�θ��µĶ��Ǳ�������k=3ʱ��dis[1][5]����dis[1][3]��dis[3][5]��Ϊ���·��
	  	����Ҫȥ֪��1,3֮���ж��ٸ��㣬��Ϊǰ���Ѿ������ֻ֪����һ�������dis[1][5]�����һ��3����㡣
	  �ص����⣬floyd�㷨�Ƕ����������£��������ȴ�Ǹ��µ���һ�������ϣ����Բ�����ָո��¹���ֵ�������¡�����k�μ��� 
	  1��N��floyd�����ñ���˼����٣������Ե����ϵĶ��֡��������������ݡ�
	  2�����ﻹ��һ��Ҫע�⣬T�ķ�Χ��(2~100),������ඥ��ֻ��200���������ŵķ�Χȴ(1 �� I1i �� 1,000; 1 �� I2i �� 1,000)���������ǿ��Խ������ɢ����
	  3�����һ��������infҪ���ܴ󣬿��ܻᱬ����inf����Ϊ-1����û��������ˡ�
*/
#include<iostream>
#include<cstring> 
using namespace std;
const int MAX=105;
const int NMAX=1005;
struct Matrix{
	int v[MAX][MAX];
    Matrix(){memset(v,-1,sizeof(v));}
};
int N=0,hash[NMAX];
Matrix mtMul(Matrix A,Matrix B){
    int i,j,k,tmp;
    Matrix C;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            for(k=0;k<N;k++){
                if(A.v[i][k]==-1 || B.v[k][j]==-1)continue;
                tmp=A.v[i][k]+B.v[k][j];
                if(C.v[i][j]==-1 || C.v[i][j]>tmp)C.v[i][j]=tmp;
            }
    return C;}
Matrix mtPow(Matrix A, int k){
    if(k==1)return A;
    Matrix B=mtPow(A,k/2);
    if(k&1)return mtMul(mtMul(B,B),A);
	else return mtMul(B,B);
}
int main(){
    int n,t,s,e,i;
    memset(hash,-1,sizeof(hash));
    cin>>n>>t>>s>>e;
    Matrix A;
    for(i=0;i<t;i++){
        int len,u,v;
        cin>>len>>u>>v;
        if(hash[u]==-1)hash[u]=N++;//��ż���ɢ�£����ַ���Ӧ�������İɡ�
        if(hash[v]==-1)hash[v]=N++;
        A.v[hash[u]][hash[v]]=len;
        A.v[hash[v]][hash[u]]=len;
    }
    A=mtPow(A,n);
    printf("%d\n",A.v[hash[s]][hash[e]]);
    return 0;
}
