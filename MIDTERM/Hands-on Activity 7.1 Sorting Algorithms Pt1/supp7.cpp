#include "sorting.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

const int max_size = 100;
const int no_of_candidates = 5;

void displayArr(int arr[]);

int main() {
    //unsorted votes array
    int arr[max_size];
    srand(0);
    for (int i = 0; i < max_size; i++) {
        arr[i] = (rand() % 5) + 1; //limiting output to 1-5
    }

    std::string candidates[no_of_candidates] = { //candidates array
        "Bo Dalton Capistrano",
        "Cornelius Raymon Agustín",
        "Deja Jayla Bañaga",
        "Lalla Brielle Yabut",
        "Franklin Relano Castro",
    };

    std::cout << "\nUnsorted: \n";
    displayArr(arr);

    std::cout << "\nInsertion sorted: \n";
    insertionSort(arr, max_size);
    displayArr(arr); 
    
    int votes[no_of_candidates] = {0,0,0,0,0};
    for(int i = 0; i < max_size; i++) {
        votes[arr[i] - 1]++; //increment the index of the candidates votes
    }

    int winner = 0; 
    for(int i = 1; i < no_of_candidates; i++){ //determine winner
        if(votes[i] > votes[winner]){winner = i;}
    }

    bool tie = false;
    for(int i = 0; i < no_of_candidates; i++){ //check if theres tie in votes
        if((votes[winner] == votes[i]) && winner != i){
            tie = true;
        }
    }

    if (tie){
        std::cout << "\nThere is a tie in votes. There shall be a revote!\n";
        
    } else{
        std::cout << "\nThe winner of the election is " 
                << candidates[winner] 
                << ", with a total of "
                << votes[winner]
                << " votes!\n";
    }
    
    return 0;
}

void displayArr(int arr[]) {
    for (int i = 0; i < max_size; i++) {
        std::cout << arr[i] << ' ';
    }
}