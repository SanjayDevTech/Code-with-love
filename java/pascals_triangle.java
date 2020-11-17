//Generates the first n number of rows of Pascal's triangle.
class Solution {
    public List<List<Integer>> generate(int n) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> pre = new ArrayList<Integer>();
        if(numRows==0) return res;
        
        pre.add(1);
        res.add(pre);
        if(numRows==1) return res;
    
        for(int i=2; i<=numRows; i++){
            List<Integer> cur = new ArrayList<Integer>();
            cur.add(1);
            for(int j=0; j<pre.size()-1; j++){
                cur.add(pre.get(j)+pre.get(j+1));
            }
            cur.add(1);
            pre = cur;
            res.add(cur);
        }
        return res;
    }
}
