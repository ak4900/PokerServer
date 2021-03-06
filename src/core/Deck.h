/*
 * Deck.h
 *
 * Represents a Deck of Cards. Cards are created by the deck during construction
 * are kept for the lifetime of the deck. Calling Top() or Burn() returns or burns a
 * card respectively by moving a pointer over a vector.
 */

#ifndef DECK_H_
#define DECK_H_

#include <vector>
#include <string>
#include "Card.h"

namespace GameEngineCore {

const int CARDS_IN_DECK = 52;

class Deck {
	public:
		Deck();
		const Card& Top();

		void Burn();
		int GetCount() const;
		std::string ToHashString() const;

		std::string ToString() const;
	private:
		std::vector<Card> m_deck;
		int m_pos;
};

std::ostream& operator<<(std::ostream& os, const Deck& deck);

//notes on design: Decided a std::vector was a better idea than
//the actual STL stack object as I want to hold on to the original
//set of cards in the deck, in their positions for the remainder of
//the game, so my Top() function doesn't actually remove them.

}

#endif /* DECK_H_ */
