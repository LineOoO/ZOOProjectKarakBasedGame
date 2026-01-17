#include "Map.h"

bool Map::randBool() {
    // Use random_device to generate a good seed sequence
    static std::random_device rd;
    static std::seed_seq seed{ rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd() };
    static std::mt19937 gen(seed);                 // Mersenne Twister seeded once
    static std::bernoulli_distribution dist(0.5);  // 50% true / false
    return dist(gen);
}

Map::~Map()
{
	for (auto& it : this->m_map) {
		delete it;
	}
}

Map::Map()
{
	this->createCard(0, 0);
}

void Map::createCard(int x, int y)
{
	bool canBeCreated{ true };

	for (const auto& it: this->m_map) // go through the whole map and find out if our x y coords are already occupied
	{		
		const auto &tempCoords = it->getCoords();
		if (x == tempCoords.at(0) and y == tempCoords.at(1)) // compare coords
		{
			canBeCreated = false;
			std::cerr << LOG() << "Trying to create Card for coords: "
				<< x << ";" << y << " but this position is already occupied!\n";

		}
	}
	if (canBeCreated) // this will be true if the position we want to create new card at is free
	{
		m_map.push_back(new Card(x, y));
		auto newlyCreatedCard = m_map.back(); // save the pointer of our newly created card for easy access
		for (const auto& it : this->m_map) // Look for 4 possible neigbours for our newly created Card (left right up down) 
		{
			const auto& tempCoords = it->getCoords();
			if ((x-1) == tempCoords.at(0) and (y) == tempCoords.at(1)) // Card to the left
			{
				const auto& tempExits = it->getExits();
				if (tempExits.at(2) == true) // Check if the card to the left has RIGHT(2) exit open so we can connect
				{
					newlyCreatedCard->setExit(0, true);
				}
			}

			if ((x) == tempCoords.at(0) and (y+1) == tempCoords.at(1)) // Card above
			{
				const auto& tempExits = it->getExits();
				if (tempExits.at(3) == true) // Check if the card above has DOWN(3) exit open so we can connect
				{
					newlyCreatedCard->setExit(1, true);
				}
			}

			if ((x+1) == tempCoords.at(0) and (y) == tempCoords.at(1)) // Card to the right
			{
				const auto& tempExits = it->getExits();
				if (tempExits.at(0) == true) // Check if the card to the right has LEFT(0) exit open so we can connect
				{
					newlyCreatedCard->setExit(2, true);
				}
			}
			if ((x) == tempCoords.at(0) and (y-1) == tempCoords.at(1)) // Card below
			{
				const auto& tempExits = it->getExits();
				if (tempExits.at(1) == true) // Check if the card below has UP(1) exit open so we can connect
				{
					newlyCreatedCard->setExit(3, true);
				}
			}
		}
		// At this point our newly created Card has exits connected to all neighbors
		// If an exit is closed, there is no neighbor in that direction
		// The code below generates random exits for potential future room connections
		auto exits = newlyCreatedCard->getExits(); // exits now holds copy of exit info for our newly created card
		bool deadEndChecker = false; // logs if room has at least one exit after neigbor and random generation
		for (size_t i = 0; i < newlyCreatedCard->getExits().size(); i++)
		{
			if (exits.at(i) == false) // if exit is closed, randomly try to open it
			{
				bool randomResult = randBool();
				deadEndChecker = deadEndChecker | randomResult;
				newlyCreatedCard->setExit(i, randomResult);
			}
			else {
				deadEndChecker = true;
			}
		}

		if (!deadEndChecker) // This will trigger if there are 0 exits even after random generation
		{
			newlyCreatedCard->setExit(2, true); // This will happen rarely so just open RIGHT exit for simplicity
		}
	}
}

bool Map::checkIfCardExists(int x, int y)
{
	for (const auto& it : this->m_map) {
		const auto& tempCoords = it->getCoords();
		if (x == tempCoords.at(0) and y == tempCoords.at(1)) {
			return true; 
		}
	}
	return false;
}

Card* Map::getCard(int x, int y)
{
	for (const auto& it : this->m_map) {
		const auto& tempCoords = it->getCoords();
		if (x == tempCoords.at(0) and y == tempCoords.at(1)) {
			return it;  // Card found at x y
		}
	}
	return nullptr;  // No Card found at x y
}

const std::vector<Card*>& Map::getCards() const
{
	return m_map;
}
