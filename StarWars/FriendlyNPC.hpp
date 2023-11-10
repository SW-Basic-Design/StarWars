#include "NonPlayerCharacter.hpp"

#ifndef FRIENDLY_NPC_HPP
#define FRIENDLY_NPC_HPP

class FriendlyNPC : public NonPlayerCharacter {
public:
	FriendlyNPC() : NonPlayerCharacter() {}
	~FriendlyNPC() = default;
private:
};

#endif