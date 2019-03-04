//CSCI 340
//JUSTIN ROESNER
//z1858242
//ASSIGNMENT 3
//DUE 2-15-2019

#include <set>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>


using namespace std;

//global variable i made to count 6 values before new line for my lamda funciton
int countValues;

//remove all non prime numbers from the set passed in. also takes in lower and upper bounds
void sieve( set<int>& s, const int lower, const int upper) {
    //make a temporary set that i can iterate over while making changes to "s" the real set 
    set<int> tempSet;
    //loop through starting with lower bound up until upper 
    for (int i = lower; i <= upper; i++){
        //insert each number into s set and temporary set
        tempSet.insert(i);
        s.insert(i);
    }

    // if 1 is present erase 1 from it
    s.erase(1);

    //for each value inside of temporary set check if it is prime
    for (auto it = tempSet.begin(); it != tempSet.end(); it++){
        //for each value take half iterate over half of its value checking for 0 remainders
        for (int i = 2; i <= *it / 2; i++){
            //check if it has 0 as a remainder using modulous division
            if (*it % i == 0){
                //it is not prime so remove from my real set "s"
                s.erase(*it);
            }
        }
    }
    cout << endl;
}

//print all numbers inside of the set
void print_primes( const set<int>& s, const int lower, const int upper) {
    countValues = 0;
    // display the size and the lower and upperbounds of the set
    cout << "There are " << s.size() << " prime numbers between " << lower << " and " << upper << ":" << endl;

    //for each value inside of the set print it
    for_each(s.begin(), s.end(), [](const int & value){
        //print the value with a setw of 4
        cout << setw(4) << value;
        countValues++;
        //for every 6 values print a new line and reset the counter
        if (countValues== 6){
            cout << endl;
            countValues = 0;
        }
    });
    cout << endl;

}

//driver function for the program continues to loop until passed a no from user
void run_game(set<int>& s) {
    //variables for lower and upper bounds, bool for loop, string for user input
    int lower;
    int upper;
    bool keepLooping = true;
    string answer;

    //continue to loop until passed no from user
    while (keepLooping){
        //ask user for input
        cout << "Please input lower bound and upper bound and hit enter (e.g. 10 100):" << endl;
        //take in lower and upper bounds
        cin >> lower;
        cin >> upper;
        //if lower is < upper continue as expected
        if (lower < upper){
            //send sieve the set
            sieve(s, lower, upper);
            //send set to be printed
            print_primes(s, lower, upper);
            //clear the set before asking for a new set from the user
            s.clear();
        }
        //ask if they want to continue or not
        cout << "Do you want to continue or not? Please answer yes or no and hit enter: " << endl;
        cin >> answer;
        //if they say no break the loop
        if (answer == "no"){
            keepLooping = false;
        }
    }	
}

int main() {
    set<int> s;
    run_game(s);
    return 0;
}
