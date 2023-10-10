 // CSCI1300 Spring 2021
 // Author: Alex Reid
 // Recitation: 107 – Sourav Chakraborty
 // Project 1 - Problem 2
 #include <iostream>
 using namespace std;
 bool isVowel(char let);

 int main()
 { 
     //call function is value passing it the char a 
     cout << isVowel('I') << endl;
     cout << isVowel('k');
 }
 bool isVowel(char let)
 {
     switch(let)
     {
         //return true if any of these characters is equal to the char passed into the switch statement
         case 'a': 
         case 'A':
         case 'e':
         case 'E':
         case 'i':
         case 'I':
         case 'o':
         case 'O':
         case 'u':
         case 'U':
         return true; 
         default:
         return false; 
     }
 }