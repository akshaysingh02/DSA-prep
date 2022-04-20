for(auto i = adj[s].begin();i!=adj[s].end();i++){
                if(!vis[*i]){
                    stack.push(*i);
                }
            }