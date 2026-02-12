#include <bits/stdc++.h>
using namespace std;

struct Block{
    int next;
    int used;
};

int main(){
    int totalBlocks;
    cin>>totalBlocks;

    vector<Block> disk(totalBlocks);
    for(int i=0;i<totalBlocks;i++){
        disk[i].used=0;
        disk[i].next=-1;
    }

    map<string,pair<int,int>> table;

    int files;
    cin>>files;

    while(files--){
        string name;
        int size;
        cin>>name>>size;

        vector<int> freeBlocks;
        for(int i=0;i<totalBlocks;i++){
            if(!disk[i].used) freeBlocks.push_back(i);
            if(freeBlocks.size()==size) break;
        }

        if(freeBlocks.size()<size){
            cout<<"Cannot allocate "<<name<<"\n";
            continue;
        }

        for(int i=0;i<size;i++){
            int b=freeBlocks[i];
            disk[b].used=1;
            if(i<size-1) disk[b].next=freeBlocks[i+1];
            else disk[b].next=-1;
        }

        table[name]={freeBlocks[0],size};

        cout<<"Allocated "<<name<<" blocks: ";
        for(int x:freeBlocks) cout<<x<<" ";
        cout<<"\n";
    }

    int q;
    cin>>q;

    while(q--){
        string name;
        cin>>name;

        if(!table.count(name)){
            cout<<"File not found\n";
            continue;
        }

        int curr=table[name].first;

        while(curr!=-1){
            int nxt=disk[curr].next;
            disk[curr].used=0;
            disk[curr].next=-1;
            curr=nxt;
        }

        table.erase(name);
        cout<<"Freed "<<name<<"\n";
    }
}
