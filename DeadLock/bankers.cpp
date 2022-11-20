#include<bits/stdc++.h>
using namespace std;

#define n 5
#define m 3

void bankersAlgo(int alloc[n][m],int max[n][m],int avail[m]){
    int finished[n]={0},safeSequence[n],idx=0;
    int need[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(finished[j]==0){
                bool flag=false;
                for(int k=0;k<m;k++){
                    if(need[j][k]>avail[k]){
                        flag=true;
                        break;
                    }
                }
                if(!flag){
                    safeSequence[idx++]=j;
                    for(int k=0;k<m;k++){
                        avail[k]+=alloc[j][k];
                    }
                    finished[j]=1;
                }
            }
        }
    }
    cout<<"Safe Sequence is:"<<endl;
    for(int i=0;i<n;i++){
        cout<<safeSequence[i]<<"\t";
    }
}

int main(){
    int alloc[n][m]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
    int max[n][m]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
	int av[m]={3,3,2};
    bankersAlgo(alloc,max,av);
    return 0;
}