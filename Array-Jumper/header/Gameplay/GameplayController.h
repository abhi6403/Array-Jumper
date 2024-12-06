#pragma once
#include "../../header/Level/BlockType.h"

using namespace Level;

namespace Gameplay
{
	class GameplayController
	{
	private:
		bool isObstacle(BlockType value);
		bool isEndBlock(BlockType value);
		bool isLastLevel();
		void processObstacle();
		void loadNextLevel();
		void processEndBlock();
		void gameOver();
		void gameWon();

	public:
		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();

		
		void onPositionChanged(int position);
		void startGame();
		void onDeath();
		
	};
}