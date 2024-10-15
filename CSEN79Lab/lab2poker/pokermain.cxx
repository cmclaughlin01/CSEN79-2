/*
 * CSEN 79 Lab: Poker Statistics
 */
#include <ctime>
#include <iomanip>
#include <iostream>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <chrono>
#include "card.h"
#include "deck.h"
#include "poker.h"

using namespace std;
using namespace csen79;

// Generate one sample hand for each rank
void pokerHands(Poker &poker) {
    const int totalRanks = Poker::POKER_ARRAY_SIZE;

    unordered_map<Poker::Rank, bool> rankFound;
    unordered_map<Poker::Rank, Poker> sampleHands;
    int foundCount = 0;

    while (foundCount < totalRanks) {
        poker.dealHand();
        Poker::Rank rank = poker.rankHand();

        // Check if the rank is valid by looking it up in RankToIndex
        if (Poker::RankToIndex.find(rank) != Poker::RankToIndex.end()) {
            if (rankFound.find(rank) == rankFound.end()) {
                rankFound[rank] = true;
                sampleHands[rank] = poker;
                foundCount++;
                int index = Poker::RankToIndex.at(rank);
                cout << sampleHands[rank] << " - "
                          << Poker::RankNames[index] << endl;
            }
        } else {
            cerr << "Invalid rank encountered: " << rank << endl;
        }
    }
}

// Collect statistics for each rank of Poker
void pokerStats(Poker &poker) {
    const int totalRanks = csen79::Poker::POKER_ARRAY_SIZE;

    // Counters for each rank
    std::unordered_map<csen79::Poker::Rank, uint64_t> rankCounts;
    for (const auto& pair : csen79::Poker::RankToIndex) {
        rankCounts[pair.first] = 0;
    }

    // Variables for timing
    using clock = std::chrono::high_resolution_clock;
    auto startTime = clock::now();

    // Number of hands to deal
    const uint64_t totalHandsToDeal = 1000000; // Adjust as needed

    // Variables for progress reporting
    const uint64_t intervalHands = 50000; // Number of hands per interval
    uint64_t totalHands = 0;

    std::cout << "Computing poker statistics. Please wait..." << std::endl;

    while (totalHands < totalHandsToDeal) {
        for (uint64_t i = 0; i < intervalHands && totalHands < totalHandsToDeal; ++i) {
            poker.dealHand();
            csen79::Poker::Rank rank = poker.rankHand();

            // Increment the count for the rank
            if (rankCounts.find(rank) != rankCounts.end()) {
                rankCounts[rank]++;
            } else {
                // Handle unexpected rank values
                std::cerr << "Invalid rank encountered: " << rank << std::endl;
            }
            totalHands++;
        }

        // Print progress
        auto currentTime = clock::now();
        std::chrono::duration<double> elapsedTime = currentTime - startTime;
        std::cout << "After dealing " << totalHands << " hands. Elapsed Time: "
                  << elapsedTime.count() << " seconds." << std::endl;
    }

    // Final timing
    auto endTime = clock::now();
    std::chrono::duration<double> totalElapsedTime = endTime - startTime;
    double averageTimePerInterval = (totalElapsedTime.count() / (totalHands / intervalHands));

    // Print final statistics
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Dealt " << totalHands << " hands. Elapsed Time: "
              << totalElapsedTime.count() << " seconds." << std::endl;
    std::cout << "Average " << averageTimePerInterval << " seconds per " << intervalHands << " hands" << std::endl;

    // Print counts and percentages for each rank
    std::cout << std::endl;
    for (const auto& pair : csen79::Poker::RankToIndex) {
        csen79::Poker::Rank rank = pair.first;
        int idx = pair.second;
        uint64_t count = rankCounts[rank];
        double percentage = (static_cast<double>(count) / totalHands) * 100.0;
        std::cout << csen79::Poker::RankNames[idx] << ": " << count << " "
                  << std::fixed << std::setprecision(2) << percentage << "%" << std::endl;
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
