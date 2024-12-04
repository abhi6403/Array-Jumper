#pragma once
#include "../../header/Event/EventService.h"

namespace Player
{
	class PlayerView;
	class PlayerModel;
	enum class PlayerState;
	enum MovementDirection;
	struct LevelData;
	class BlockType;

	class PlayerController
	{
	private:
		PlayerModel* player_model;
		PlayerView* player_view;
		Event::EventService* event_service;

		void move(MovementDirection direction);
		void readInput();
		void jump(MovementDirection direction);
		
		bool isPositionInBound(int targetPosition);

		void destroy();

	public:
		PlayerController();
		~PlayerController();

		void initialize();
		void update();
		void render();

		PlayerState getPlayerState();
		void setPlayerState(PlayerState new_player_state);
		int getCurrentPosition();

	};
}