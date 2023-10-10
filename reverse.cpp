 // CSCI1300 Spring 2021
 // Author: Alex Reid
 // Recitation: 107 – Sourav Chakraborty
 // Project 1 - Problem 1
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
void reverse(string num);
int main()
{
    reverse("1234567890");
    reverse("04022021");
    // call function reverse to activate it
}
void reverse(string num)
{
    int rev = num.length() - 1; 
    string num2 = num; 
    // use as place holder for values in for loop
    for(int i = 0; i < num.length(); i++)
    {
        num2[i] = num[rev];
        rev--; 
        //go through and switch the order of each index without affecting the original string 
    }
    cout << num2 << endl; 

}