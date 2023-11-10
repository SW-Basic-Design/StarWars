#include "Character.hpp"

#ifndef NON_PLAYER_CHARACTER_HPP
#define NON_PLAYER_CHARACTER_HPP

class NonPlayerCharacter : public Character {
public:
	NonPlayerCharacter() :Character() {}
	~NonPlayerCharacter() = default;
protected:
};

#endif