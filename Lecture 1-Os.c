#include <stdio.h>
#include <string.h>

/*
     %s -> string
     %d -> integer
     %f -> float
     %ld -> long
     %lu -> unsigned long
     %c -> char
*/ 

int main(){
    
    char test[20] = "Bilgi";
    printf("Test variable: %s\n", test);
    
    printf("Enter an integer: ");
    int x;
    scanf("%d", &x);
    
    printf("Given value is %d\n", x);
    
    printf("Before string %s\n", test);
    strcpy(test, "Hello World");
    printf("After string %s\n", test);
    
    printf("Is equal %d\n", strcmp(test, "Hello World"));
    printf("Is equal %d\n", strcmp(test, "Hello world"));
    
    printf("Length of string %lu\n", strlen(test));
    
}
