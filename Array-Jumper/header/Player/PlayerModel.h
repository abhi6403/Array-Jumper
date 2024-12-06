#pragma once

namespace Player
{
	enum class PlayerState
	{
		ALIVE,
		DEAD,
	};

	class PlayerModel
	{
	private:
		int current_position;
		const int max_lives = 3;
		int current_lives;
		PlayerState player_state;

	public:
		PlayerModel();
		~PlayerModel();

		PlayerState getPlayerState();
		void setPlayerState(PlayerState new_player_state);

		int getCurrentPosition();
		int getCurrentLives();
		void setCurrentPosition(int new_position);
		void decrementLife();
		void resetPosition();

		void initialize();

		void resetPlayer();
	};
}