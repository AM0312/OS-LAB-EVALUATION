#include<bits/stdc++.h>
using namespace std;

void bestFit(int blocks[],int m,int processes[],int n){
    int alloc[n];
    memset(alloc,-1,sizeof(alloc));
    for(int i=0;i<n;i++){
        int bestIdx=-1;
        for(int j=0;j<m;j++){
            if(blocks[j]>=processes[i]){
                if(bestIdx==-1) bestIdx=j;
                else if(blocks[j]<blocks[bestIdx]) bestIdx=j;
            }
        }
        if(bestIdx!=-1){
            alloc[i]=bestIdx;
            blocks[bestIdx]-=processes[i];
        }
    }
    cout<<"----------BEST FIT----------"<<endl;
    cout<<"Process ID\t"<<"Size\t"<<"Block Id\n";
    for(int i=0;i<n;i++){
        if(alloc[i]!=-1) cout<<i<<"\t\t"<<processes[i]<<"\t\t"<<alloc[i]<<endl;
        else cout<<i<<"\t\t"<<processes[i]<<"\t\t"<<"Not Allocated"<<endl;
    }
}

int main(){
    int bs[]={100,300,200,600,500};
    int ps[]={97,140,300,444};
    bestFit(bs,5,ps,4);
    return 0;
}