#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

struct WordCount
{
    char word[31];
    int count;
};

//prototypes 
int countWords(const char*, WordCount[]);
void stripPunctuation(char*);
void stringToUpper(char*);
int searchForWord(const char*, const WordCount[], int);
void sortWords(WordCount[], int);
void printWords(const WordCount[], int);

int main(int argc, char* argv[])
{
    WordCount wordArray[200];
    //numWords = unique words
    int numWords = 0;

    if (argc == 1) //if im missing input file exit program.
    {
        cout << "usage: assgn1 (file-name)\n";
        exit(1);
    }   

    numWords = countWords(argv[1], wordArray);
    sortWords(wordArray, numWords);
    printWords(wordArray, numWords);
    
    return 0;
}
int countWords(const char* fileName, WordCount wordArray[])
{
    char word[31];
    int numWords = 0;

    ifstream inFile(fileName);
    if (!inFile)
    {
        cout << "error unable to open file " << fileName << endl;
        exit(1);
    }
    //read and count the words
    while (inFile >> word)
    {
        stripPunctuation(word);
        //as long as length of the word is not 0 continue. in case of just punctuation being pulled in.
        if (strlen(word) != 0)
        {
            stringToUpper(word);
            int indexOfFoundWord;
            indexOfFoundWord = searchForWord(word, wordArray, numWords);

            //if the index is -1 the word was not found so add it to the array.
            if (indexOfFoundWord == -1) 
            {
                strcpy(wordArray[numWords].word, word);
                wordArray[numWords].count++;
                numWords++;
            }
            //otherwise add 1 to the count at the found index
            else
            {
                wordArray[indexOfFoundWord].count++;
            }
        }
    }
    inFile.close();
    return numWords;
}
void stripPunctuation(char* s)
{
    char* temp = s; 
    int currentCharacter = 0;
    int lengthOfWord = strlen(s);

    //check front for punctuation
    for(int i=0; i<=lengthOfWord; i++)
    {
        //loop until nonpuntuation is found
        if (!ispunct(s[i]))
        {
            //loop the remainder of the word into temp array
            for(int ii=i; ii<=lengthOfWord; ii++)
            {
                temp[currentCharacter] = s[ii]; 
                currentCharacter++;
            }
            break;
        } 
    }
    //check back to front for punctuation
    for(int i=strlen(temp)-1; i >= 0; i--)
    {
        //loop until nonpunctuation is found
        if (!ispunct(temp[i]))
        {
            //add a new terminating character to cut off punctuation
            temp[++i] = '\0';
            break;
        }
    }
    strcpy(s,temp);

}
void stringToUpper(char* s)
{
    int lengthOfWord = strlen(s);
    //make entire word uppercase
    for(int i=0; i<=lengthOfWord; i++)
    {
        s[i] = toupper(s[i]);
    }
}
int searchForWord(const char* word, const WordCount wordArray[], int numWords)
{
    for (int i = 0; i <= numWords; i++)
    {
        //loop through array looking for matching words
        if (strcmp(wordArray[i].word, word) == 0)
        {
            //if i find a match return its index
            return i;
        }
    }
    //if no matches it's a unique word return -1
    return -1;
}
void sortWords(WordCount wordArray[], int numWords)
{
    int min;
    WordCount temp;
    
    //loop through each array index 
    for (int i = 0; i < (numWords -1); i++)
    {
        min = i;
            //loop through the array 1 ahead of current min to find new min.
            for (int ii=i+1; ii < numWords; ii++)
            {
                if (strcmp(wordArray[ii].word,  wordArray[min].word) < 0)
                    min =ii;
            }
        temp = wordArray[min];
        wordArray[min] = wordArray[i];
        wordArray[i] = temp;
    }
}
void printWords(const WordCount wordArray[], int numWords)
{
    cout << endl;
    cout << "Word Counts for input.txt";
    cout << endl;
    cout << endl;
    cout << left << setw(20) << "Word" << right << setw(20) << "Count";
    cout << endl;

    int totalWordCount = 0; 
    for (int i = 0; i < numWords; i++)
    {
        cout << left <<  setw(20) << wordArray[i].word;
        cout << setw(20) << right << wordArray[i].count;
        cout << endl;
        totalWordCount += wordArray[i].count;
    }
    
    cout << endl;
    cout << left << setw(20) << "Number of words:" << right << setw(20) <<  totalWordCount;
    cout << endl;
    cout << left << setw(10) << "Number of distinct words:" << right << setw(15) << numWords;
    cout << endl;
}













