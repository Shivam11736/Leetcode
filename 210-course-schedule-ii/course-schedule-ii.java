class Solution {
    public int[] findOrder(int n, int[][] pre) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) adj.add(new ArrayList<>());
        for (int[] arr : pre) adj.get(arr[1]).add(arr[0]);
        int[] indeg = new int[n];
        for (int i = 0; i < n; i++) {
            for( int it : adj.get(i)) indeg[it] += 1;
        }
        Queue<Integer> q = new LinkedList<>();
        int cnt = 0, ind = 0;
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                q.add(i); ans[ind++] = i;
            }
        }
        while (!q.isEmpty()) {
            int node = q.poll();
            cnt += 1;
            for (int it : adj.get(node)) {
                indeg[it] -= 1;
                if (indeg[it] == 0)  {
                    ans[ind++] = it; q.add(it);
                }
            }
        }
        return cnt == n ? ans : new int[0];
    }
}

