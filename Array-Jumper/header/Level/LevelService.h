#pragma once
#include "../../header/Level/LevelData.h"

namespace Level
{
	class LevelController;
	struct BoxDimensions;

	class LevelService
	{
	private:
		LevelController* level_controller;

		void destroy();

	public:
		LevelService();
		~LevelService();

		void initialize();
		void update();
		void render();

		BoxDimensions getBoxDimensions();
		BlockType getCurrentBoxValue(int currentPosition);

		bool isLastLevel();
		void resetLevel();
		void loadNextLevel();
		int getCurrentLevelNumber();
	};
}