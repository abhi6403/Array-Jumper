#pragma once
#include "../../header/Level/BlockType.h"
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
	};
}