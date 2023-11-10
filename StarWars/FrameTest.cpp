#include "includes.hpp"
#include "GameManager.hpp"
#include "FrameManager.hpp"

void test()
{
	FrameManager frameManager;

	frameManager.InitFrame();

	short index = 0;

	bool test[10][5][5] = {
		{
			{ true, true, true, true, true },
			{ true, false, false, false, true },
			{ true, false, false, false, true },
			{ true, false, false, false, true },
			{ true, true, true, true, true }
		},
		{
			{ true, true, true, true, true },
			{ true, true, false, false, true },
			{ true, false, false, false, true },
			{ true, false, false, false, true },
			{ true, true, true, true, true }
		},
		{
			{ true, true, true, true, true },
			{ true, false, true, false, true },
			{ true, false, false, false, true },
			{ true, false, false, false, true },
			{ true, true, true, true, true }
		},
		{
			{ true, true, true, true, true },
			{ true, false, false, true, true },
			{ true, false, false, false, true },
			{ true, false, false, false, true },
			{ true, true, true, true, true }
		},
		{
			{ true, true, true, true, true },
			{ true, false, false, false, true },
			{ true, false, false, true, true },
			{ true, false, false, false, true },
			{ true, true, true, true, true }
		},
		{
			{ true, true, true, true, true },
			{ true, false, false, false, true },
			{ true, false, false, false, true },
			{ true, false, false, true, true },
			{ true, true, true, true, true }
		},
		{
			{ true, true, true, true, true },
			{ true, false, false, false, true },
			{ true, false, false, false, true },
			{ true, false, true, false, true },
			{ true, true, true, true, true }
		},
		{
			{ true, true, true, true, true },
			{ true, false, false, false, true },
			{ true, false, false, false, true },
			{ true, true, false, false, true },
			{ true, true, true, true, true }
		},
		{
			{ true, true, true, true, true },
			{ true, false, false, false, true },
			{ true, true, false, false, true },
			{ true, false, false, false, true },
			{ true, true, true, true, true }
		},
		{
			{ true, true, true, true, true },
			{ true, false, false, false, true },
			{ true, false, true, false, true },
			{ true, false, false, false, true },
			{ true, true, true, true, true }
		},
	};

	while (true)
	{
		for (short i = 0; i < 5; ++i)
		{
			frameManager.SetCursorPosition({ index, i });

			for (int j = 0; j < 5; ++j)
			{
				if (test[index][i][j] == true)
					frameManager.Print("1");
				else
					frameManager.Print("0");
			}
		}

		frameManager.UpdateFrame();
		index = (index + 1) % 10;

		Sleep(1000 / 120);
	}

	_getch();
	_getch();
	frameManager.DestroyFrame();

	return;
}