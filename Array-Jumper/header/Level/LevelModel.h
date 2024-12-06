#pragma once
#include "../../header/Level/LevelConfiguration.h"
#include "../../header/Level/LevelData.h"

namespace Level
{
	struct BoxDimensions
	{
		float box_width;
		float box_height;
		float box_spacing;

		float box_spacing_percentage = 0.3f;
		float bottom_offset = 200.f;
	};

	class LevelModel
	{
	private:
		const int number_of_level = LevelConfiguration::NUMBER_OF_LEVELS;
		LevelConfiguration level_configuration;

		int current_level_index;

	public:
		LevelModel();
		~LevelModel();

		BlockType getCurrentBoxValue(int currentPosition);

		int getCurrentLevelNumber();

		void loadNextLevel();
		void reset();

		bool isLastLevel();
	};
}