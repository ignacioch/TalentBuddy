#include <stdio.h>
#include <stdlib.h>


void find_missing_number(int *v, int v_length) {
    // Write your code here
	int i ;
	int current_sum=0;
	int expected_sum=0;
    for (i = 0; i <v_length ; i ++) {
    	// summing all the values
    	current_sum += v[i];
    }
    for (i = 1; i <=v_length ; i ++) {
    	// calculate the expected value
    	expected_sum += i;
    }
    printf("Missing number : %d\n",expected_sum - current_sum);
}

int main( int argc, char *argv[] )  
{
    if (argc == 1) {
        printf ("Please provide arguments in the following format :");
        printf ("./missing number 1st_element 2nd_element ....and so on");

        exit(1);
    } else {
        printf("Running Missing number with n = %s\n",argv[1]);
        int v_length = argc;
        int  v[v_length];
        int i ;
        for (i = 0 ; i < v_length; i++) {
        	v[i] = atoi(argv[i]);
        //	printf("Index %d: %d",i,v[i]);
        }
        find_missing_number(v,v_length);
    } 
}
