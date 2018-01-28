#include <assert.h>
#include <limits.h>


int add(int a, int b) {
    long c = (long) a + b;
    assert(c < INT_MAX && c > INT_MIN);
    
    return (int) c;
}

int substract(int a, int b) {
    long c = (long) a - b;
    assert(c < INT_MAX && c > INT_MIN);
    
    return (int) c;
}