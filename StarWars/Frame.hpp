#include "includes.hpp"

#ifndef FRAME_HPP
#define FRAME_HPP

struct stRect {
	int nWidth;
	int nHeight;
};

class Frame {
public:
	Frame() :
		consoleHandler(nullptr), bufferHandler{ nullptr, nullptr }, currentBufferIndex(0) 
	{}

	HANDLE consoleHandler;
	stRect consoleInfo;
	HANDLE bufferHandler[2];
	int currentBufferIndex;
};
#endif
