class MyClass {
    
    public static void count_occurences(Integer[] v, Integer k) {
        // Write your code here
        // To print results to the standard output please use System.out.println
        // Example: System.out.println("Hello world!");
        
        if (v==null) System.out.println ("v on main is null");
        
        MyClass x = new MyClass();
        int counter = x.count_occurences_temp(v,k);
        
        System.out.println(counter);
        
    }
    
    public int count_occurences_temp(Integer[] v, Integer K) {
        
        int length = v.length;
        int middle_element = (length % 2 == 0) ? v[length%2] : v[length%2+1] ;
        
        Integer[] left_array = new Integer[length+1];
        Integer[] right_array = new Integer[length+1];
        
        System.arraycopy(v,0,left_array,0,length%2); 
        System.arraycopy(v,middle_element,right_array,0,length%2); 
        
        
        if (left_array == null) System.out.println("Left array is null");
        if (right_array == null) System.out.println("Right array is null");

        
        if (v.length==1) {
            if (middle_element == K) return 1;
            else return 0;
        }
        
        if (middle_element > K) {    // middle element is bigger, K belongs to the left array    
            count_occurences_temp(left_array,K);     
        } else if (middle_element < K) {
            count_occurences_temp(right_array,K);
        } else if (middle_element == K) { //we have found the element  increase the counter by 1
            return 1 +    count_occurences_temp(left_array,K) +  count_occurences_temp(right_array,K);           
        }
        
        return 0;
    }
    
}
