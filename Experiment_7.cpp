class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> prs(n);
        for(int i=0;i<flights.size();i++){
            prs[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<int> dist(n,INT_MAX);
        while(!q.empty() ){
           auto [steps,a]=q.front();
           auto [srci,cost]=a;
           q.pop();
           if(steps>k) continue;
           
           for(auto c:prs[srci]){
            auto [srcu,cst]=c;
             if( steps<=k && dist[srcu]>cost+cst){
                dist[srcu]=cost+cst;
                    q.push({steps+1,{srcu,cost+cst}});
                }
           }
           
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};