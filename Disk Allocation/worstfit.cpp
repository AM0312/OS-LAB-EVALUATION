#include<bits/stdc++.h>
using namespace std;

void worstFit(int blocks[],int m,int processes[],int n){
    int alloc[n];
    memset(alloc,-1,sizeof(alloc));
    for(int i=0;i<n;i++){
        int worstIdx=-1;
        for(int j=0;j<m;j++){
            if(blocks[j]>=processes[i]){
                if(worstIdx==-1) worstIdx=j;
                else if(blocks[worstIdx]<blocks[j]) worstIdx=j;
            }
        }
        if(worstIdx!=-1){
            alloc[i]=worstIdx;
            blocks[worstIdx]-=processes[i];
        }
    }
    cout<<"----------WORST FIT----------"<<endl;
    cout<<"Process ID\t"<<"Size\t"<<"Block Id\n";
    for(int i=0;i<n;i++){
        if(alloc[i]!=-1) cout<<i<<"\t\t"<<processes[i]<<"\t\t"<<alloc[i]<<endl;
        else cout<<i<<"\t\t"<<processes[i]<<"\t\t"<<"Not Allocated"<<endl;
    }
}

int main(){
    int bs[]={100,500,300,600,150};
    int ps[]={90,110,250,500};
    worstFit(bs,5,ps,4);
    return 0;
}