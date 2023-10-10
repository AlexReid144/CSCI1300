 // CSCI1300 Spring 2021
 // Author: Alex Reid
 // Recitation: 107 – Sourav Chakraborty
 // Project 1 - Problem 1

  // CSCI1300 Spring 2021
 // Author: Alex Reid
 // Recitation: 107 – Sourav Chakraborty
 // Project 1 - Problem 7
#include <iostream>
#include <string>
using namespace std; 
void findWinner(string seq1, string seq2, string seq3, string gold_seq);
double bestLikenessScore(string seq1, string gold_seq);
double calcLikenessScore(string one, string two); 

int main()
{
        string one;
        string two; 
        string three; 
        string gold; 
    int choice; 
    cout << "---- Menu ----" << endl;
    cout << "1: Calculate the Likeness Score between 2 strings of equal length." << endl;
    cout << "2: Calculate the Best Likeness Score between 2 sequences of possibly different length." << endl;
    cout << "3: Find winner among sequences of 3 players and a Golden Sequence." << endl;
    cout << "4: Exit." << endl;
    cout << "Enter your choice (1-4):" << endl;
    cin >> choice; 
    if(choice > 4 && choice < 1)
    {
        cout << "Invalid input. Choices between 1-4." << endl;
        main();
    }
    if(choice == 4)
    {
        cout << "Exiting.";
        return 0; 
    }
    else if(choice == 3)
    {
       
    
        cout << "Enter Sequence of Player 1" << endl;
        cin >> one;
        cout << "Enter Sequence of Player 2" << endl;
        cin >> two;
       cout <<  "Enter Sequence of Player 3" << endl;
       cin >> three;
        cout << "Enter Golden sequence" << endl;
        cin >> gold;
        findWinner(one, two, three, gold);
        main();
    }
    else if(choice == 2)
    {
        cout << "Enter Sequence 1" << endl;
        cin >>  one; 
        cout << "Enter Sequence 2" << endl;
        cin >>  two;
        cout << "Best Likeness Score: " << bestLikenessScore(one, two) << endl;
        main();
    }
    else if(choice == 1)
    {
        cout << "Enter Sequence 1" << endl;
        cin >> one;
        cout << "Enter Sequence 2" << endl;
        cin >> two;
        if(one.length() != two.length())
        {
            cout << "Invalid input. Sequences of different length." << endl;
            main();
            return 0;  
        }
        cout << "Score: " << calcLikenessScore(one, two) << endl;
        main();
    }
    return 0;

}
    

 void findWinner(string seq1, string seq2, string seq3, string gold_seq)
{
    double tot1 = bestLikenessScore(seq1, gold_seq);
    double tot2 = bestLikenessScore(seq2, gold_seq);
    double tot3 = bestLikenessScore(seq3, gold_seq);
    
    if(tot1 == 0 && tot2 == 0 && tot3 == 0)
    {
        cout << "Better luck next time everyone!" << endl;
        return; 
    }
    else if(tot1 == tot2 && tot1 == tot3)
    {
        cout << "Congratulations everyone! You have all won!" <<endl;
        return;
    }
    else if(tot1 > tot2 && tot1 > tot3)
    {
        cout << "Congratulations Player 1! You have won!" <<endl;
        return;
    }
     else if(tot2 > tot1 && tot2 > tot3)
    {
        cout << "Congratulations Player 2! You have won!" << endl;
        return;
    }
    else if(tot3 > tot2 && tot3 > tot1)
    {
        cout << "Congratulations Player 3! You have won!" << endl;
        return;
    }
    else if(tot1 == tot2 && tot1 > tot3)
    {
        cout << "Congratulations Players 1 and 2! You have won!" << endl;
        return;
    }
    else if(tot2 == tot3 && tot2 > tot1)
    {
        cout << "Congratulations Players 2 and 3! You have won!" << endl;
        return;
    }
    else if(tot1 == tot3 && tot1 > tot2)
    {
        cout << "Congratulations Players 1 and 3! You have won!" << endl;
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

