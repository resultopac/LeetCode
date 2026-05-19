class Solution {
        public int minimumLength(String s) {
            int[] arr = new int[256];
            for (int i = 0 ; i < s.length(); i++){
                arr[s.charAt(i)]++;
            }
            int res = 0 ;
            for (int i = 0 ; i < 256 ; i++){
                if (arr[i] > 2){
                    while(arr[i] > 2){
                        arr[i]-=2;
                    }
                    res += arr[i];
                }else{
                    res+= arr[i];
                }
            }
            return res;
        }
    }