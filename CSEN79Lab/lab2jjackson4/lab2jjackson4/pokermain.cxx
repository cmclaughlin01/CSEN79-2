/*
 * CSEN 79 Lab: Poker Statistics
 */
#include <ctime>
#include <iomanip>
#include <iostream>
#include <cstring>
#include <cmath>
#include "card.h"
#include "deck.h"
#include "poker.h"
#include <vector>
#include <map>

using namespace std;
//lab2jjackson4@scu.edu
using namespace lab2jjackson4;

// Generate one sample hand for each rank
void pokerHands(Poker &poker) {
	std::map<Poker::Rank, Poker> sampleHands;

    while (sampleHands.size() < Poker::Rank::POKER_STRAIGHT_FLUSH + 1) {
    poker.dealHand();
    Poker::Rank rank = poker.rankHand(); 

    if (sampleHands.find(rank) == sampleHands.end()) {
        sampleHands[rank] = poker; 
        std::cout << sampleHands[rank] << " " << Poker::RankNames[rank] << std::endl;
        }
    }
}
	

// Collect statistics for each rank of Poker
void pokerStats(Poker &poker) {

    const size_t handsPerBatch = 50000;    // How many hands per batch
    const size_t maxHands = 10000000;      // Maximum number of hands to simulate

    // Initialize counters for each rank
    size_t rankCount[Poker::Rank::POKER_ARRAY_SIZE] = {0};
    size_t totalHandsDealt = 0;

    // Timer variables
    clock_t startTime = clock();
    size_t batchCount = 0; 

    while (totalHandsDealt < maxHands) {
        // Deal a batch of hands
        for (size_t i = 0; i < handsPerBatch; ++i) {
            poker.dealHand();                 // Deal a hand
            Poker::Rank rank = poker.rankHand();  // Get the hand's rank
            rankCount[rank]++;                // Increment the count for this rank
        }

        totalHandsDealt += handsPerBatch;
        batchCount++;

        // Calculate the elapsed time after the current batch
        
    }
    double elapsedTime = double(clock() - startTime) / CLOCKS_PER_SEC;
    double averageTimePerBatch = elapsedTime / batchCount;
    // Print the statistics after every batch
        std::cout << "\nDealt " << totalHandsDealt << " hands. Elapsed Time: " << elapsedTime << " seconds." << std::endl;
        std::cout << "Average " << std::setprecision(7) << averageTimePerBatch << " seconds per " << handsPerBatch << " hands" << std::endl;

        // Display rank statistics
        for (size_t i = 0; i < Poker::POKER_ARRAY_SIZE; ++i) {
            double percentage = (rankCount[i] / static_cast<double>(totalHandsDealt)) * 100;
            std::cout << std::setw(20) << Poker::RankNames[i] << ": " << rankCount[i]
                      << " (" << std::fixed << std::setprecision(2) << percentage << "%)\n";
        }
}
   
int main(void) {
	Poker poker;
	cout << "Sample hand for each Rank:" << endl;
	pokerHands(poker);
	cout << endl << "Statistics:" << endl;
	pokerStats(poker);

	return EXIT_SUCCESS;
}
