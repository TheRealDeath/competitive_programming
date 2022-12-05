void restore(vector<vector<int>>& v, int items, int cap, vector<int>& result, vector<pair<int,int>>& objects) {
    //returns the indexes of the elements in the knapsack
    if(v[items][cap] == 0) return;
    if(v[items-1][cap] == v[items][cap]) restore(v,items-1,cap,result,objects);
    else {
        restore(v,items-1,cap-objects[items].second,result,objects);
        result.push_back(items-1);
    }
}
void knapsack(int items, int cap, vector<vector<int>>& v,vector<pair<int,int>>& objects) {
    for(int i = 1;i<objects.size();i++) {
        pair<int,int> temp = objects[i];
        for(int j = 1;j<=cap;j++) {
            if(j<temp.second) {
                v[i][j] = v[i-1][j];
                continue;
            }
            v[i][j] = max(v[i-1][j-temp.second]+temp.first,v[i-1][j]);
        }
    }
}
