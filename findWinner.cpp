 // CSCI1300 Spring 2021
 // Author: Alex Reid
 // Recitation: 107 – Sourav Chakraborty
 // Project 1 - Problem 6
#include <iostream>
#include <string>
using namespace std; 
void findWinner(string seq1, string seq2, string seq3, string gold_seq);
double bestLikenessScore(string seq1, string gold_seq);
double calcLikenessScore(string one, string two); 

int main()
{
    //findWinner("CAH7S5CJCK", "S7H9SQCA03", "H2S6H7CTS9HK", "D4D5D6") << endl;
    //findWinner("DAH7S5​CJ" , "S7H9DQ​CA", "H2​S6CTD7", "D4D5D6") << endl; 
    //findWinner("DAH7S5​CJ", "S7D2DQ​CAH7", "H2​DTCTD7​S8C5", "DTD2D3") << endl; 
   // findWinner("H2​DTHTSA​S7CA", "D7H2SQ​CAH7", "CJ​DAH7C5", "DTH7SA") << endl;
    findWinner("DAH7S5​CJ", "S7H9DQ​CA", "H2​S6CTD7", "D4D5D6");
    cout << endl;
    findWinner("CAH7S5CJCK", "S7H9SQCA03", "H2S6H7CTS9HK", "D4D5D6");
    cout << endl;
    findWinner("DAH7S5​CJ", "S7D2DQ​CAH7", "H2​DTCTD7​S8C5", "DTH7SA");
    cout << endl;
    findWinner("H2​DTHTSA​S7CA", "D7H2SQ​CAH7", "CJ​DAH7C5", "DTH7SA");

}

 void findWinner(string seq1, string seq2, string seq3, string gold_seq)
{
    double tot1 = bestLikenessScore(seq1, gold_seq);
    double tot2 = bestLikenessScore(seq2, gold_seq);
    double tot3 = bestLikenessScore(seq3, gold_seq);
    
    if(tot1 == 0 && tot2 == 0 && tot3 == 0)
    {
        cout << "Better luck next time everyone!";
        return; 
    }
    else if(tot1 == tot2 && tot1 == tot3)
    {
        cout << "Congratulations everyone! You have all won!";
        return;
    }
    else if(tot1 > tot2 && tot1 > tot3)
    {
        cout << "Congratulations Player 1! You have won!";
        return;
    }
     else if(tot2 > tot1 && tot2 > tot3)
    {
        cout << "Congratulations Player 2! You have won!";
        return;
    }
    else if(tot3 > tot2 && tot3 > tot1)
    {
        cout << "Congratulations Player 3! You have won!";
        return;
    }
    else if(tot1 == tot2 && tot1 > tot3)
    {
        cout << "Congratulations Players 1 and 2! You have won!";
        return;
    }
    else if(tot2 == tot3 && tot2 > tot1)
    {
        cout << "Congratulations Players 2 and 3! You have won!";
        return;
    }
    else if(tot1 == tot3 && tot1 > tot2)
    {
        cout << "Congratulations Players 1 and 3! You have won!";
        return;
    }
    
}

 double bestLikenessScore(string seq1, string gold_seq)
{
    double best = 0.0;
    //make sure the first string is shorter
    if(seq1.length() < gold_seq.length())
    {
        return -1.0;
    }
    else
    {
        for(int i = 0; i < seq1.length(); i+=2)
        {
            //call the function calcLikenessScore with a substring of the first string so it is equal length of the second string
            double test = calcLikenessScore(seq1.substr(i, gold_seq.length()), gold_seq);
            if(test > best)
            {
                //see if it has a better score
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
    // making sure that the second string cannot be longer than the first string
    if(one.length() != two.length())
    {
        return -1;
    }
    else
    {
        for(int i = 0; i < one.length(); i++)
        {
            //if statement to only evaulate the suits and not the values
            if(i % 2 == 0)
            {
                //if the suits are the same add one to the suits variable
                if(one[i] == two[i])
                {
                    suit++; 
                }
                //if the suit and the number are the same add one to to the match varaible
                if(one[i + 1] == two[i + 1])
                {
                    match+= 1.0; 
                }
            }
        }
        //use the numbers calculated to find the likeness score
        double score = (suit / (one.length() / 2.0)) + (match * 1);
        return score; 
    }
    
}

