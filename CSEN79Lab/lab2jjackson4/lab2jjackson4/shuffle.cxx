/*
 * Name: Julian Jackson
 * Email: jjackson4@scu.edu
 */
#include <iostream>
#include "card.h"
#include "deck.h"


namespace lab2jjackson4 {
	// implement Fisher-Yates here
	void Deck::shuffle(void) {
		srand(time(NULL));
		int len = (sizeof(cards)/sizeof(*cards));
		Card temp;

		for (int i = len-1; i > 0; i--)
		{
			int j = rand() % i;
			std::swap(cards[i],cards[j]);
		}
		next = 0;
	}

	// deal out one card
	const Card &Deck::deal() {
		if (next + guard >= nCards) {
        	shuffle();
    }
    	return cards[next++];	// replace this line with your implementation of the function.
	}
}

