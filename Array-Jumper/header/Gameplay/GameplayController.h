#pragma once
#include "../../header/Level/BlockType.h"

using namespace Level;

namespace Gameplay
{
	class GameplayController
	{
	private:
		

	public:
		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();

		void processObstacle();
		bool isObstacle(BlockType value);
		bool isEndBlock(BlockType value);
		bool isLastLevel();
		void loadNextLevel();
		void onPositionChanged(int position);
		void processEndBlock();
		void onDeath();
		void gameOver();
		void gameWon();
	};
}