#pragma once
#include "../../header/Level/BlockType.h"
#include "../../header/Level/LevelModel.h"

namespace Level
{
	class LevelModel;
	class LevelView;

	class LevelController
	{
	private:
		LevelModel* level_model;
		LevelView* level_view;

	public:
		LevelController();
		~LevelController();

		void initialize();
		void update();
		void render();

		BlockType GetCurrentBoxValue(int currentPosition);
		BoxDimensions getBoxDimensions();

		bool isLastLevel();
		void loadNextLevel();
		void resetLevels();
		int getCurrentLevelNumber();
	};
}