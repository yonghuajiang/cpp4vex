// Include the iostream library for input and output
#include <iostream>
// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;
// Define a function that adds two numbers and returns the result
int add(int a, int b) {
    return a + b; // Return the sum of a and b
}
// The main function - execution starts here
int main() {
    // Declare integer variables to store user input
    int num1 = 0;
    int num2 = 0;
    // Prompt the user for the first number
    //<< (Stream Insertion Operator): This operator takes the data on its right and sends it to the stream on its left.
    cout << "Enter the first number: ";
    cin >> num1; // Read input from the user and store in num1
    // Prompt the user for the second number
    cout << "Enter the second number: ";
    cin >> num2; // Read input from the user and store in num2
    // Call the add() function and store the result
    int result = add(num1, num2);
    // Display the result
    cout << "The sum is: " << result << endl;
    // Optional: Use an if-else condition
    if (result > 100) {
        cout << "That's a big number!" << endl;
    } else {
        cout << "That's a reasonable number." << endl;
    }
    // Use a for loop to count up to the result
    cout << "Counting to your result: ";
    for (int i = 1; i <= result && i <= 10; ++i) {
        cout << i << " "; // Print numbers from 1 to result (limit to 10)
    }
    cout << endl; // End the line after the loop
    return 0; // Indicate successful program end
}
