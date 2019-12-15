// Min Distance To The Farthest Node

// Find the Diameter of the graph i.e: the Longest distance between any two nodes in a tree.

// Two cases possible :
// the answer is ( diameter / 2 ) if the diameter value is even
// answer = ( diameter / 2 ) + 1 if the diameter value is odd.

int findMax(vector<vector<int>>& adj, int c, int p, int& res){
    vector<int> v;
    
    for(auto x:adj[c]){
        if(x!=p){
            v.push_back(findMax(adj,x,c,res));
        }
    }
    
    int n = v.size();
    if(n==0){
        res = max(res, 1);
        return 1;
    }else if(n==1){
        res = max(res, v[0]);
        return v[0]+1;
    }
    
    sort(v.begin(),v.end(), greater<int>());
    res = max(res, v[0]+v[1]);
    return v[0]+1;
    
}

int Solution::solve(vector<int> &A) {
    
    int n = A.size();
    
    if(n<=1) return 0;
    
    vector<vector<int>> adj(n);
    
    int res = 1;
    
    for(int i = 0; i<n;i++){
        if(A[i]==-1) continue;
        
        adj[A[i]].push_back(i);
        adj[i].push_back(A[i]);
    }
    
    findMax(adj, 0, -1, res);
    
    return res;

    
}




///////////////////////////////////////////////////////


// "static void main" must be defined in a public class.
// https://leetcode.com/discuss/interview-question/356378/Google-or-OA-2019-or-Min-Distance-To-The-Farthest-Node
public class Main {
    public static void main(String[] args) {
        int N = 10;
        
        int[][] edges = new int[][]{{1,2}, {2,3}, {3,4}, {4,5}, {5,6}, {6,7}, {7,8}, {8,9}, {9,10}};
        System.out.println("Min Dis: "+getMinDisFarthestNode(N, edges));
    }
    
    private static int getMinDisFarthestNode(int N, int[][] edges) {
        Map<Integer, List<Integer>> hmap = new HashMap<>();
        
        for(int i=0;i<edges.length;i++) {
            if(hmap.containsKey(edges[i][0]-1)) {
                hmap.get(edges[i][0]-1).add(edges[i][1]-1);
            } else {
                List<Integer> temp = new ArrayList<>();
                temp.add(edges[i][1]-1);
                hmap.put(edges[i][0]-1, temp);
            }
            if(hmap.containsKey(edges[i][1]-1)) {
                hmap.get(edges[i][1]-1).add(edges[i][0]-1);
            } else {
                List<Integer> temp = new ArrayList<>();
                temp.add(edges[i][0]-1);
                hmap.put(edges[i][1]-1, temp);
            }
        }
            
        boolean[] visited = new boolean[N];
        int[] maxLeafDist = new int[N];
        
        for(int i=0;i<N;i++) {
            if(hmap.get(i).size() == 1) {
                recurr(hmap, visited, maxLeafDist, i, 0);
                visited = new boolean[N];
            }
        }
        
        int result=Integer.MAX_VALUE;
        for(int i=0;i<maxLeafDist.length;i++) {
            result = Math.min(result, maxLeafDist[i]);
        }
        return result;
    }
    
    private static void recurr(Map<Integer, List<Integer>> hmap, boolean[] visited, int[] maxLeafDist, int node, int level) {
        maxLeafDist[node] = Math.max(maxLeafDist[node], level);
        
        for(int n:hmap.get(node)) {
            if(!visited[n]) {
                visited[n] = true;
                recurr(hmap, visited, maxLeafDist, n, level+1);
            }
        }
    }
       
}
