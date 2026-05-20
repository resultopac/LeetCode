class Solution {
        class Building {
            int length;
            int idx;
            Building(int length,int idx){
                this.length = length;
                this.idx = idx;
            }

        }

        public int maxJumps(int[] arr, int d) {
            int max = 0;
            int[] dp = new int[arr.length];
            PriorityQueue<Building> pq = new PriorityQueue<>(
                    (a, b) -> Integer.compare(a.length, b.length)
            );
            for (int i = 0 ; i < arr.length ; i++){
                Building b = new Building(arr[i],i);
                pq.add(b);
            }
            while(!pq.isEmpty()){
                Building curr = pq.poll();
                int currIdx = curr.idx;
                int currLength = curr.length;
                int currMax = dp[currIdx];
                for (int i = currIdx+1 ; i  < arr.length && currIdx+d >= i; i++){
                    if (arr[i] >= currLength){
                        break;
                    }else{
                        currMax = Math.max(currMax,dp[i]);
                    }
                }
                for (int i = currIdx-1 ; i >= 0 && i >= currIdx-d ; i--){
                    if (arr[i] >= currLength){
                        break;
                    }else{
                        currMax = Math.max(currMax,dp[i]);
                    }
                }
                dp[currIdx] = 1+currMax;
            }
            for(int i : dp){
                max = Math.max(max,i);
            }
            return max;
        }
    }