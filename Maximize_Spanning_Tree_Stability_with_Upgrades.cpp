#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DSU {
public:
    vector<int> parent, rankv;

    DSU(int n) {
        parent.resize(n);
        rankv.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int find(int x){
        if(parent[x]!=x)
            parent[x]=find(parent[x]);
        return parent[x];
    }

    bool unite(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b) return false;

        if(rankv[a]<rankv[b]) swap(a,b);
        parent[b]=a;
        if(rankv[a]==rankv[b]) rankv[a]++;

        return true;
    }
};

bool can(int n, vector<vector<int>>& edges, int k, int X){

    DSU dsu(n);
    int upgrades=0;
    int used=0;

    vector<vector<int>> optional;

    for(auto &e:edges){
        int u=e[0],v=e[1],s=e[2],must=e[3];

        if(must){
            if(s<X) return false;
            if(!dsu.unite(u,v)) return false;
            used++;
        }
        else{
            optional.push_back(e);
        }
    }

    vector<pair<int,vector<int>>> candidates;

    for(auto &e:optional){
        int s=e[2];

        if(s>=X)
            candidates.push_back({0,e});
        else if(2*s>=X)
            candidates.push_back({1,e});
    }

    sort(candidates.begin(),candidates.end());

    for(auto &p:candidates){
        int cost=p.first;
        auto &e=p.second;

        if(dsu.unite(e[0],e[1])){
            upgrades+=cost;
            used++;

            if(upgrades>k) return false;
            if(used==n-1) return true;
        }
    }

    return used==n-1;
}

int maxStability(int n, vector<vector<int>>& edges, int k) {

    int lo=0,hi=200000;
    int ans=-1;

    while(lo<=hi){
        int mid=(lo+hi)/2;

        if(can(n,edges,k,mid)){
            ans=mid;
            lo=mid+1;
        }
        else{
            hi=mid-1;
        }
    }

    return ans;
}

int main(){

    int n,m,k;
    cin >> n >> m >> k;

    vector<vector<int>> edges(m, vector<int>(4));

    for(int i=0;i<m;i++){
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2] >> edges[i][3];
    }

    cout << maxStability(n,edges,k);

    return 0;
}