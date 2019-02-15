//CSCI 340
//JUSTIN ROESNER
//ASSIGNMENT 2 DRIVER 
//DUE 2-6-19

#include <vector>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>


using namespace std;

const int DATA_SIZE = 100;
const int SEARCH_SIZE = 50;
const int DATA_SEED = 11;
const int SEARCH_SEED = 7;

//generate random numbers between 1-100 and put them inside a vector
void genRndNums( vector<int>& v, int seed ) {
    //initialize rng with the seed provided
    srand(seed);

    //loop through vector add a random number between 1-100
    for(unsigned int i = 0; i < v.size(); i++){
        v[i] = rand() % 100 + 1;
    }
}

//use linear search to find a value, returns bool based on found or not
bool linearSearch( const vector<int>& inputVec, int x) {
    //use find to look for x value
    auto it = find(inputVec.begin(), inputVec.end(), x);

    //if we are not at the end then we found the value return true
    if (it != inputVec.end())
        return true;
    //if we are at position .end return false. we did not find the value
    else
        return 0;
}

//use binary_search to look for x value inside of vector returns true on found.
bool binarySearch( const vector<int>& inputVec, int x) {
    //returns false if x value isnt found. true on found.
    return binary_search(inputVec.begin(), inputVec.end(), x);
}


int search( const vector<int>& inputVec, const vector<int>& searchVec,
        bool (*p)( const vector<int>&, int) ){
    int successfulSearches = 0;
    for(unsigned int i = 0; i < searchVec.size(); i++){
       //if (p(inputVec.begin(), inputVec.end(), searchVec[i]))
       if (p(inputVec, searchVec[i]))
           successfulSearches++;
    }
    return successfulSearches;
}

//sort vector using sort
void sortVector (vector<int>& inputVec) {
    sort(inputVec.begin(), inputVec.end());
}

//prints the percent of successful searches
void printStat (int totalSucCnt, int vec_size) {
    //find % of successful finds out of vector
    float successRate; 
    successRate = (float)totalSucCnt / (float)vec_size;

    //print successrate
    cout << "Successful searches: " << fixed << setprecision(2) <<  successRate * 100 << "%";
    cout << endl;
}

//print the vector
void print_vec( const vector<int>& vec ){
    int count = 0;
    for (unsigned int i = 0; i < vec.size(); i++){
        //for every 10 items make a new line
        if (count == 10){
            cout << endl;
            count = 0;
        }
        
        //print each number with a set width of 6
        cout << setw(6) << vec[i];

        //add one to the count for each number printed
        count++;
    }
}

int main() {
    vector<int> inputVec(DATA_SIZE);
    vector<int> searchVec(SEARCH_SIZE);
    genRndNums(inputVec, DATA_SEED);
    genRndNums(searchVec, SEARCH_SEED);

    cout << "----- Data source: " << inputVec.size() << " randomly generated numbers ------" << endl;
    print_vec( inputVec );
    cout << "----- " << searchVec.size() << " random numbers to be searched -------" << endl;
    print_vec( searchVec );

    cout << "\nConducting linear search on unsorted data source ..." << endl;
    int linear_search_count = search( inputVec, searchVec, linearSearch );
    printStat ( linear_search_count, SEARCH_SIZE );

    cout << "\nConducting binary search on unsorted data source ..." << endl;
    int binary_search_count = search( inputVec, searchVec, binarySearch );
    printStat ( binary_search_count, SEARCH_SIZE );

    sortVector( inputVec );

    cout << "\nConducting linear search on sorted data source ..." << endl;
    linear_search_count = search( inputVec, searchVec, linearSearch );
    printStat ( linear_search_count, SEARCH_SIZE );

    cout << "\nConducting binary search on sorted data source ..." << endl;
    binary_search_count = search( inputVec, searchVec, binarySearch );
    printStat ( binary_search_count, SEARCH_SIZE );

    return 0;
}

