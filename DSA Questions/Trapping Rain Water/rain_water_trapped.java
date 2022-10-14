public class rain_water_trapped {
    static int waterStored(int arr[], int n){

//        Using two auxiliary arrays to store left maximum wall and right maximum wall
        int left[] = new int[n];
        int right[] = new int[n];

        left[0] = arr[0];
        for (int i = 1; i < n; i++)
            left[i] = Math.max(left[i-1], arr[i]);

        right[n-1] = arr[n-1];
        for(int i=n-2; i>= 0; i--)
            right[i] = Math.max(right[i+1], arr[i]);

//        To find max water stored we can find the minimum of the two auxiliary walls
//        and subtract it with the height of the current wall
        int water =0;
        for (int i = 0; i < n; i++)
            water += Math.min(left[i], right[i])-arr[i];

        return water;
    }

    public static void main(String[] args) {
        int arr[] = {7,4,0,9};
        int n = arr.length;
        System.out.println(waterStored(arr,n));
    }
}
