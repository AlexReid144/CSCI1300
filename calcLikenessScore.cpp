 // CSCI1300 Spring 2021
 // Author: Alex Reid
 // Recitation: 107 – Sourav Chakraborty
 // Project 1 - Problem 4
#include <iostream>
#include <string> 
using namespace std; 
double calcLikenessScore(string one, string two);

int main()
{
    //test cases calling the function with different strings
    cout << calcLikenessScore("S7H8CJD9HA", "S7H8CJD9HA") << endl;
    cout << calcLikenessScore("HQDASJ", "DAD8SJ") << endl;
    cout << calcLikenessScore("D7H2S4", "H5DTS8C5");
}
 
double calcLikenessScore(string one, string two)
{
    double suit = 0.0; 
    int match = 0.0;
    if(one.length() != two.length())
    {
        return -1;
    }
    else
    {
        for(int i = 0; i < one.length(); i++)
        {
            if(i % 2 == 0)
            {
                if(one[i] == two[i])
                {
                    suit++; 
                }
                if(one[i + 1] == two[i + 1])
                {
                    match+= 1.0; 
                }
            }
        }
        double score = (suit / (one.length() / 2.0)) + (match * 1);
        return score; 
    }
    
}