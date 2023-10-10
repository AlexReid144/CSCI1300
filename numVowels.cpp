// CSCI1300 Spring 2021
 // Author: Alex Reid
 // Recitation: 107 – Sourav Chakraborty
 // Project 1 - Problem 3
#include <iostream>
#include <string>
using namespace std;
int numVowels(string word);
bool isVowel(char let); 
 

int main()
{
   cout <<  numVowels("computer science") << endl;
   cout << numVowels("Can the lockdown end already?");
}
int numVowels(string word)
{
    int tot = 0; 
    for(int i =0; i < word.length(); i++)
    {
        //call isVowel to see if the index of the string is a fall or not and will return true if it is
        if(isVowel(word[i]) == 1)
        {
            tot++;
        }
        
    }
    return tot; 

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