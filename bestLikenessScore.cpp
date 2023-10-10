 // CSCI1300 Spring 2021
 // Author: Alex Reid
 // Recitation: 107 – Sourav Chakraborty
 // Project 1 - Problem 5
#include <iostream>
#include <string>
using namespace std; 
double bestLikenessScore(string seq1, string gold_seq);
double calcLikenessScore(string one, string two); 

int main()
{
    cout << bestLikenessScore("S7H8SJ​D9H8CJD9", "H8C6D6") << endl;
    cout << bestLikenessScore("S7H8SJD9​H8CJD9​", "H8C6D6"); 
}

 double bestLikenessScore(string seq1, string gold_seq)
{
    double best = 0.0;
    if(seq1.length() < gold_seq.length())
    {
        return -1.0;
    }
    else
    {
        for(int i = 0; i < seq1.length(); i+=2)
        {
            double test = calcLikenessScore(seq1.substr(i, gold_seq.length()), gold_seq);
            if(test > best)
            {
                best = test; 
            }
        }
        return best; 
    }
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