#pragma once
#include "../../header/Level/BlockType.h"

using namespace Level;

namespace Gameplay
{
	class GameplayController
	{

	public:
		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();

		void processObstacle();
		bool isObstacle(BlockType value);
		void onPositionChanged(int position);
	};
}