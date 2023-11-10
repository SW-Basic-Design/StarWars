#include "Frame.hpp"
#include "Object.hpp"

#ifndef FRAME_MANAGER_HPP
#define FRAME_MANAGER_HPP

class FrameManager {
public:
	void InitFrame();
	void DestroyFrame();
	void ClearScreen();
	void SwapBuffer();
	void Print(const char*);
	void PrintWithPosition(const char*, COORD);
	void UpdateFrame();
	void ClearBuffer();
	void SetCursorPosition(COORD);
	COORD GetCursorPosition();
	void MakeFrame(std::vector<Object>&);
private:
	Frame frame;
};

#endif
