//CSCI 340
//JUSTIN ROESNER
//z1858242
//ASSIGNMENT 1
//DUE 1-30-19

#include <algorithm>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

const int DATA_SIZE = 200;
const int DATA_RANGE = 200;
const int DATA_SEED = 9;
const int SEARCH_SEED = 17;

//linear search for vector
int linear_search(const vector<int>& inputVec, const int x, int& comparisons) {
    //loop through each index of the vector
    for(unsigned int i = 0; i < inputVec.size(); i++){
        //each time we make a comparison add 1 to the comparisons
        comparisons++;
        //if the current index = what we are looking for return the index
        if(inputVec[i] == x){
            return i;
        }
    }
    //if we cant find the value inside vector return -1
    return -1;
}

//binary search for vector
int binary_search(const vector<int>& inputVec, const int x, int& comparisons) {
    //left starting spot is index 0, right is the size of the vector -1
    int left = 0;
    int right = inputVec.size() - 1;

    //while we haven't overlapped left and right continue 
    while (left<=right){
        //each middle is left+right /2 inside this loop
        int middle = (left + right) / 2;
        
        //each time we compare we add 1 to comparisons
        comparisons++;
        //if middle is our value return the index
        if (inputVec[middle] == x){
            return middle;
        }
        //if middle is greater than x, x will be to the left so make right = middle -1
        else if (inputVec[middle] > x){
            right = middle - 1;
        }
        //if middle is less than x, x will be to the right so make left = middle + 1
        else{
            left = middle + 1;
        }
    }
    //if the value can not be found return -1
    return - 1;
    
}

//print the vector
void print_vec( const vector<int>& vec ){
    int count = 0;
    for (unsigned int i = 0; i < vec.size(); i++){
        //for every 8 lines make a new line
        if (count == 8){
            cout << endl;
            count = 0;
        }
        
        //print each number with a set width of 4
        cout << setw(4) << vec[i];

        //add one to the count for each number printed
        count++;
    }
}

void average_comparisons(const vector<int>& inputVec, const vector<int>& searchVec, int (*search)(const vector<int>&, const int, int&) ) {
    int i, comparison = 0, sum = 0, found = 0;
    int res = 0;
    for (i = 0; i < (int)searchVec.size(); i++) {
        res = search( inputVec, searchVec[i], comparison );
        sum += comparison;
        if ( res >= 0 )
           found++;
    }
    cout << found << " numbers are found. The average number of comparisons in each search: " << (double)sum/(double)searchVec.size() << endl << endl;
}

int random_number() {
    return rand()%DATA_RANGE + 1;
}


int main () {

    // -------- create unique random numbers ------------------//
    vector<int> inputVec(DATA_SIZE);
    srand(DATA_SEED);
    generate(inputVec.begin(), inputVec.end(), random_number);
    sort(inputVec.begin(), inputVec.end());
    vector<int>::iterator it = unique(inputVec.begin(), inputVec.end());
    inputVec.resize( it - inputVec.begin() );
    random_shuffle( inputVec.begin(), inputVec.end() );

    cout << "------ Data source: " << inputVec.size() << " unique random numbers ------" << endl; 
    print_vec(inputVec);
    cout << endl;

    // -------- create random numbers to be searched ---------//
    vector<int> searchVec(DATA_SIZE/2);
    srand(SEARCH_SEED);
    generate(searchVec.begin(), searchVec.end(), random_number);

    cout << "------ " << searchVec.size() << " random numbers to be searched: ------" << endl;
    print_vec(searchVec);
    cout << endl;

    cout << "Linear search: ";
    average_comparisons(inputVec, searchVec, linear_search);
    cout << "Binary search: ";
    average_comparisons(inputVec, searchVec, binary_search);

    sort(inputVec.begin(), inputVec.end());
    cout << "------- numbers in data source are now sorted ---------" << endl << endl;
    cout << "Linear search: ";
    average_comparisons(inputVec, searchVec, linear_search);
    cout << "Binary search: ";
    average_comparisons(inputVec, searchVec, binary_search);

    return 0;

}


