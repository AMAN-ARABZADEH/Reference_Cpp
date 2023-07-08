#include <iostream>
// References:
// "References (C++)" on Wikipedia: https://en.wikipedia.org/wiki/Reference_(C%2B%2B)
// "C++ References" on GeeksforGeeks: https://www.geeksforgeeks.org/references-in-c/
// "The C++ Programming Language" by Bjarne Stroustrup (Book)

// Function to increment a variable by reference
int increment(int& num) {
    return num++;
}

// Function to get the larger value between two variables by reference
int& getLarger(int& a, int& b) {
    return (a > b) ? a : b;
}

// Function that attempts to return a reference to a local variable (which is invalid)
int& getValue() {
    int value;
    value = 10;
    return value; // Error: Returning reference to local variable
}

// Function to print the value referred by a reference (const reference is used to avoid modification)
void printReference(const int& ref) {
    std::cout << ref << std::endl;
}

int main() {
    // References

    // What is a reference?
    // In C++, a reference is an alias or an alternative name for an existing variable.
    // References allow us to create multiple names (or references) that refer to the same variable.
    //  References cannot be reassigned to refer to a different object once they are initialized.
    //  Once a reference is bound to an object, it remains bound to that object throughout its lifetime.
    //  If reassignment is required, a pointer should be used instead.

    // Why use references in C++?
    // References are used in C++ for various reasons:
    // 1. Function parameter passing: References enable us to pass variables to functions by reference, allowing modifications to be made directly to the original variable.
    // 2. Avoiding copying: References can be used to avoid unnecessary copying of large objects when passing them to functions or assigning them to other variables or for range-based loops.
    // 3. Syntactic convenience: References provide a convenient way to work with variables without explicitly using pointers.

    // Potential pitfalls with references

    // 1. Dangling references
    // References should always refer to valid objects.
    // Avoid using references that refer to objects that have been deallocated.
    ///  int& ref; // Error: Reference not initialized
    int number = 10;
    ///  ref = number; // Error

    // 2. Lifetime management
    // References are valid only as long as the referred object is in scope.
    // Be cautious when returning references to local variables or objects with limited lifetimes.
    int& invalidRef = getValue(); // Error: Returning reference to local variable
    // std::cout << &invalidRef << std::endl;  // Error

    // 3. Confusing with pointers
    // References and pointers have similarities but also important differences.
    // Understand the distinctions between them to avoid confusion and misuse.
    int* ptr = nullptr;
    int& refPtr = *ptr; // Error: Dereferencing null pointer, Do Not do this
    // std::cout << &refPtr << std::endl; /// Error Big Error, do not do this
    int v = 7;
    // Example of passing a reference to a temporary object
    printReference(0); // Error: Reference to temporary object, Same here do not pass a number

    // Examples of using references

    // 1. Reference declaration and initialization
    int number1 = 10;
    int& ref = number1;          // Declares and initializes a reference  to number1
    std::cout << "Value of ref: " << ref << std::endl;

    // 3. Passing variables by reference to functions
    int value = 5;
    increment(value);           // Passes value by reference, increments its value
    std::cout << "Value after increment: " << value << std::endl;

    // 4. Returning references from functions
    int x1 = 10, y1 = 5;
    int& larger = getLarger(x1, y1);  // Returns a reference to the larger variable (larger will refer to x)
    std::cout << "Larger value: " << larger << std::endl;

    // 5. Reference variables in range-based for loops
    int numbers1[] = {1, 2, 3, 4, 5};
    for (int& num : numbers1) {
        num *= 2;               // Modifies the original elements in the array
    }

    std::cout << "Modified numbers: ";
    for (int num : numbers1) {
        std::cout << num << " ";   // Output: 2 4 6 8 10
    }
    std::cout << std::endl;

    return 0;
}
