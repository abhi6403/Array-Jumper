#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerModel.h"
#include "../../header/Player/PlayerView.h"
#include "../../header/Player/MovementDirection.h"
#include "../../header/Level/LevelData.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Gameplay/GameplayService.h"

namespace Player
{

	PlayerController::PlayerController()
	{
		player_model = new PlayerModel();
		player_view = new PlayerView(this);
	}

	PlayerController::~PlayerController() { destroy(); }

	void PlayerController::initialize()
	{
		player_model->initialize();
		player_view->initialize();
		takeDamage();

		event_service = Global::ServiceLocator::getInstance()->getEventService();
	}

	void PlayerController::update()
	{
		player_view->update();
		readInput();
	}

	void PlayerController::render()
	{
		player_view->render();
	}

	PlayerState PlayerController::getPlayerState()
	{
		return player_model->getPlayerState();
	}

	void PlayerController::setPlayerState(PlayerState new_player_state)
	{
		player_model->setPlayerState(new_player_state);
	}

	void PlayerController::destroy()
	{
		delete(player_model);
		delete(player_view);
	}

	int PlayerController::getCurrentPosition()
	{
		return player_model->getCurrentPosition();
	}

	void PlayerController::move(MovementDirection direction)
	{
		int steps, targetPosition;
		
		switch (direction)
		{
		case MovementDirection::FORWARD:
			steps = 1;
			break;

		case MovementDirection::BACKWARD:
			steps = -1;
			break;

		default:
			steps = 0;
			break;
		}

		targetPosition = player_model->getCurrentPosition() + steps;

		if (!isPositionInBound(targetPosition))
			return;

		player_model->setCurrentPosition(targetPosition);
		Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::MOVE);
		Global::ServiceLocator::getInstance()->getGameplayService()->onPositionChanged(targetPosition);
	}

	bool PlayerController::isPositionInBound(int targetPosition)
	{
		if (targetPosition >= 0 && targetPosition < Level::LevelData::NUMBER_OF_BOXES)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void PlayerController::readInput()
	{
		if (event_service->pressedRightArrowKey() || event_service->pressedDKey())
		{
			if (event_service->heldSpaceKey())
			{
				jump(MovementDirection::FORWARD);
			}
			else
			{
				move(MovementDirection::FORWARD);
			}
			
		}
		if (event_service->pressedLeftArrowKey() || event_service->pressedAKey())
		{
			if (event_service->heldSpaceKey())
			{
				jump(MovementDirection::BACKWARD);
			}
			else
			{
				move(MovementDirection::BACKWARD);
			}
			
		}
	}

	void PlayerController::jump(MovementDirection direction)
	{
		int currentPosition = player_model->getCurrentPosition();
		Level::BlockType box_value = Global::ServiceLocator::getInstance()->getLevelService()->getCurrentBoxValue(currentPosition);
		int steps, targetPosition;

		switch (direction)
		{
		case MovementDirection::FORWARD:
			steps = box_value;
			break;
		case MovementDirection::BACKWARD:
			steps = -box_value;
			break;
		default:
			steps = 0;
			break;
		}

		targetPosition = currentPosition + steps;

		if (!isPositionInBound(targetPosition))
			return;

		player_model->setCurrentPosition(targetPosition);
		Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::JUMP);

		Global::ServiceLocator::getInstance()->getGameplayService()->onPositionChanged(targetPosition);
	}

	void PlayerController::takeDamage()
	{
		player_model->resetPlayer();
	}
}