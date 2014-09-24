class MyClass {
    
    public static void count_occurences(Integer[] v, Integer k) {
        // Write your code here
        // To print results to the standard output please use System.out.println
        // Example: System.out.println("Hello world!");
        
        if (v==null) System.out.println ("v on main is null");
        
        MyClass x = new MyClass();
        int counter = x.count_occurences_temp(v,k);
        
        System.out.println("FINAL : " +counter);
        
    }
    
    public int count_occurences_temp(Integer[] v, Integer K) {
        
        if (v==null) System.out.println ("v on main is null");
        
        if (v.length ==0) {
            System.out.println("Termination. Empty array");
            return 0;
        } else if (v.length==1) {
            if (v[0] == K) {
                System.out.println("Termination. Found. ++");
                return 1;
            }
            else {
                System.out.println("Termination. Not the same");
                return 0;
            }
        }
        
        int length = v.length;  
        boolean isEven = ((length % 2) == 0 );
        System.out.println("Array length is :" + length );
        
        int middle_position = (isEven) ? (length/2) : (length/2) +1 ;
        System.out.println("Position of the middle element is :" +middle_position);
        int middle_element = v[middle_position-1] ;
        System.out.println("Middle element is : " + middle_element );
        
        int items_in_left_array;
        int items_in_right_array;
        
        if (isEven) {
            // the left array contains the middle position element
            items_in_left_array = middle_position -1;
            items_in_right_array = length - middle_position;
            System.out.println("isEven. Left contains : "+items_in_left_array + ". Right contains : "+items_in_right_array);
        } else {
            // none of them contains the item
            items_in_left_array = middle_position -1;
            items_in_right_array = length - middle_position;
            System.out.println("isOdd. Left contains : "+items_in_left_array + ". Right contains : "+items_in_right_array);
        }
        
        Integer[] left_array = new Integer[items_in_left_array];
        Integer[] right_array = new Integer[items_in_right_array];
        
        System.arraycopy(v,0,left_array,0,items_in_left_array); 
        
        System.out.println("---------------------------------");
        System.out.print("Left Array :");
        for (int i=0;i<items_in_left_array;i++){
            System.out.print(left_array[i]+",");
        }
        System.out.println("");
        
        System.arraycopy(v,middle_position,right_array,0,items_in_right_array); 
        System.out.println("---------------------------------");
        System.out.print("Right Array :");
        for (int i=0;i<items_in_right_array;i++){
            System.out.print(right_array[i]+",");
        }
        System.out.println("");
        
        if (left_array == null) System.out.println("Left array is null");
        if (right_array == null) System.out.println("Right array is null");

        System.out.println("---------------------------------");

        
        
        
        if (middle_element > K) {    // middle element is bigger, K belongs to the left array 
            System.out.println("Middle is bigger, will need to search in the left array");
            count_occurences_temp(left_array,K);     
        } else if (middle_element < K) {
            System.out.println("Middle is less, will need to search in hte right array");
            count_occurences_temp(right_array,K);
        } else if (middle_element == K) { //we have found the element  increase the counter by 1
            System.out.println("Increasing by 1. Calling for both");
            return 1 +    count_occurences_temp(left_array,K) +  count_occurences_temp(right_array,K);           
        } 
        
        return 0;
        
    }
    
}
