class Solution {


        public long minimumTime(int[] time, int totalTrips) {
            Arrays.sort(time);
            long right= (long) time[time.length - 1] *totalTrips;
            long left = (long) 0;
            long mid = (right+left)/2;
            System.out.println("Starting vals:");
            System.out.println("Left :" + left);
            System.out.println("Right :" + right);
            System.out.println("Mid :" + mid);
            System.out.println("##################");
            while(true){
                long counter = 0;
                for (int t : time) {
                    counter += mid / t;
                    if (counter > totalTrips) {
                        right = mid;
                        mid = (right+left)/2;
                                    System.out.println("KIRDIM");

                        break;
                    }
                }
                if (counter < totalTrips){
                    left = mid+1;
                    mid = (right+left)/2;

                }else if (counter == totalTrips){
                    right = mid;
                    left = mid-1;
                    mid = (right+left)/2;

                }
                if (left == right){
                    System.out.println("####### BREAK #######");
                    System.out.println("Left :" + left);
                    System.out.println("Right :" + right);
                    System.out.println("Mid :" + mid);
                    System.out.println("Counter :" + counter);
                    System.out.println("##################");
                    break;
                }
                System.out.println("Left :" + left);
                System.out.println("Right :" + right);
                System.out.println("Mid :" + mid);
                System.out.println("Counter :" + counter);
                System.out.println("##################");
            }
            return mid;
        }
    }