#pragma once
#include "../UIElement/TextView.h"

namespace UI
{
	namespace GameplayUI
	{
		class GameplayUIController
		{
		private:
			UIElement::TextView* life_count_text;
			UIElement::TextView* level_count_text;

			float font_size = 55;

			const float top_offset = 100.f;
			const float left_offset = 100.f;
			const float right_offset = 250.f;

			void createTexts();
			void initializeTexts();
			void initializeLifeCountText();
			void initializeLevelCountText();
			void updateLevelCountText();
			void updateLifeCountText();

			void destroy();

		public:
			GameplayUIController();
			~GameplayUIController();

			void initialize();
			void update();
			void render();
		};
	}
}