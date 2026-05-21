class Solution {
        public int maximizeSquareHoleArea(int n, int m, int[] hBars, int[] vBars) {
            int res = 0;
            Arrays.sort(hBars);
            Arrays.sort(vBars);
            int H = 1;
            int V = 1;
            int tempH = 1;
            int tempV = 1;
            for (int i = 0 ; i < hBars.length-1 ; i++){
                if (hBars[i+1] == (hBars[i]+1)){
                    tempH++;
                    H = Math.max(tempH,H);
                }else{
                    H = Math.max(tempH,H);
                    tempH = 1;
                    
                }
            }
            for (int i = 0 ; i < vBars.length-1 ; i++){
                if (vBars[i+1] == (vBars[i]+1)){
                    tempV++;
                    V = Math.max(tempV,V);
                }else{
                    V = Math.max(tempV,V);
                    tempV = 1;
                }
            }
            res = (Math.min(H,V)+1);
            res *= res;



            return res;
        }
    }