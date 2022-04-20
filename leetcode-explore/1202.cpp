#include <iostream>
using namespace std;

class unionFind {
    public:
        unionFind(int sz): root(sz),rank(sz){
            for(int i = 0; i<sz; i++){
                root[i] = i;
                rank[i] = 1;
            }
        }
    
        int find(int x){
            if(root[x] == x)
                return x;
            
            return root[x] = find(root[x]);
        }
    
        void unionSet(int x, int y){
            int rootx = find(x);
            int rooty = find(y);
            
            if(rootx != rooty){
                if(rank[rootx]>rank[rooty]){
                    root[rooty] = rootx;
                }
                else if (rank[rootx] < rank[rooty]){
                    root[rootx] = rooty;
                }
                else{
                    root[rooty] = rootx;
                    rank[rootx]++;
                }
            }
        }
    
    private:
        vector<int> root;
        vector<int> rank;
};


class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        if(pairs.size() == 0){
            return s;
        }
        
        int n = pairs.size();
        int sz = s.size();
        
        unionFind uf(sz);
        
        for (int i = 0; i<n; i++){
            uf.unionSet(pairs[i][0],pairs[i][1]);
        }
        
        unordered_map <int, vector<int>> mp;
        
        for(int i = 0; i<sz; i++){
            mp[uf.find(i)].push_back(s[i]);
        }
        
//         for(i=0;i<sz;i++){
            
//         }
        for(auto &p: mp){
            p->second.sort();
        }
        string res = "";
        
        for(int i = 0; i<sz; i++){
            string front = mp[uf.root[i]].begin();
            res += front;
            mp[uf.root[i]].erase(mp[uf.root[i]].begin);
        }
        return res;
    }
};