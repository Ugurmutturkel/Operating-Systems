#include <stdio.h>
#include <string.h>


//prototypes
int sum(int[], int);
int countOccur(char[], char);
int getStringLength(char[], int);

int main() {
    int arr[5] = {1, -2, 3, 4, 5};
    
    // unsigned
    printf("Size of arr: %lu\n", sizeof(arr)); 
    printf("size of an int: %lu\n", sizeof(int));
    
    printf("Length of arr: %lu\n", sizeof(arr) / sizeof(arr[0]));
    
    printf("Sum of arr: %d\n", sum(arr, 5));
    
    char test[20] = "Hello";
    
    printf("Size of test: %lu\n", sizeof(test)); //sizeof(char) = 1
    printf("Count occurence of e: %d\n", countOccur(test,'e'));
    printf("Count occurence of l: %d\n", countOccur(test,'l'));
    printf("Count occurence of i: %d\n", countOccur(test,'i'));
    
    for(int i= 0; i < 20; i++){
        printf("%c(%d)-", test[i], (int)test[i]);
    }
    
    printf("\n");
    
    printf("Length of test: %d\n", getStringLength(test, 20));
    
}

/*

    (description) sum up all elements in the given array 
    (parameters)
    @param arr int[]
    @param length int
    
    (return)
    @return total
*/

int sum(int a[], int length){
    int total = 0;

    for(int i = 0; i < length; i++){
        total += a[i];
    }
    
    return total;
    
}

/* 
    count the number of occurences of c in the given string
    
    @param str char[]
    @param c char
    
    @return numOccur
*/

int countOccur(char str[], char c){
    int length = strlen(str);//num of chars
    int numOccur = 0;
    
    for (int i=0; i < length; i++) {
		if(str[i] == c) {
			numOccur++;
		}
	}

	return numOccur;
}

/* 
    get the length of te string from given char array
    
    @param str char[]
    @param length int
    
    @return strlen
    */

int getStringLength(char str[], int length){
    
    int strLen = 0;
    
    for(int i = 0; i < length; i++){
        if (str[i] != 0) {
			strLen++;
		}
    }
    
    return strLen;
    
}