/*
 * Name: Your Name
 * Email: Your email
 */
#include <iostream>
#include "card.h"
#include "deck.h"

namespace csen79 {
	   // implement Fisher-Yates here
   void Deck::shuffle(void) {
       srand(time(NULL));
       //Fisher Yates Algorithm
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
       return cards[next++];   // replace this line with your implementation of the function.
   }
}
