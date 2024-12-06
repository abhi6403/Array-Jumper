#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GameService.h"

using namespace Global;
using namespace Level;
using namespace Main;

namespace Gameplay
{
	GameplayController::GameplayController()
	{

	}

	GameplayController::~GameplayController()
	{

	}

	void GameplayController::initialize()
	{

	}

	void GameplayController::update()
	{

	}

	void GameplayController::render()
	{

	}

	void GameplayController::startGame()
	{
		GameService::setGameState(GameState::GAMEPLAY);
		return ServiceLocator::getInstance()->getLevelService()->resetLevel();
		return ServiceLocator::getInstance()->getPlayerService()->resetPlayer();
	}
	void GameplayController::processObstacle()
	{
		ServiceLocator::getInstance()->getPlayerService()->takeDamage();
		ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::DEATH);
	}

	bool GameplayController::isObstacle(BlockType value)
	{
		if (value == BlockType::OBSTACLE_ONE || value == BlockType::OBSTACLE_TWO)
			return true;
		return false;
	}

	bool GameplayController::isEndBlock(BlockType value)
	{
		if (value == BlockType::TARGET)
			return true;
		return false;
	}

	void GameplayController::onPositionChanged(int position)
	{
		BlockType value = ServiceLocator::getInstance()->getLevelService()->getCurrentBoxValue(position);

		if (isObstacle(value))
		{
			processObstacle();
		}
		if (isEndBlock(value))
		{
			processEndBlock();
		}
			
	}

	void GameplayController::processEndBlock()
	{
		ServiceLocator::getInstance()->getPlayerService()->levelComplete();
		ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::LEVEL_COMPLETE);

		if (isLastLevel())
		{
			gameWon();
			return;
		}
		else
		{
			loadNextLevel();
		}
	}

	bool GameplayController::isLastLevel()
	{
		return ServiceLocator::getInstance()->getLevelService()->isLastLevel();
	}

	void GameplayController::loadNextLevel()
	{
		ServiceLocator::getInstance()->getLevelService()->loadNextLevel();
	}
	void GameplayController::gameOver()
	{
		GameService::setGameState(GameState::CREDITS);
		ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::DEATH);
	}

	void GameplayController::onDeath()
	{
		gameOver();
	}

	void GameplayController::gameWon()
	{
		GameService::setGameState(GameState::CREDITS);
		ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::LEVEL_COMPLETE);
	}
}