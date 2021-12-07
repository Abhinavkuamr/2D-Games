/*
 * ArcadeScene.cpp
 *
 *  Created on: Jan. 14, 2019
 *      Author: serge
 */

#include "ArcadeScene.h"
#include "Screen.h"
#include "GameController.h"
#include <iostream>
#include "App.h"
#include "GameScene.h"
#include "BreakOut.h"
#include "NotImplementedScene.h"
#include "PacmanStartScene.h"

ArcadeScene::ArcadeScene():ButtonOptionsScene({"Tetris", "Break Out!", "Asteroids", "Pac-man"}, Color::Cyan())
{

}

void ArcadeScene::Init()
{

	std::vector<Button::ButtonAction> actions;

	actions.push_back([this]{
		App::Singleton().PushScene(GetScene(TETRIS));
	});

	actions.push_back([this]{
		App::Singleton().PushScene(GetScene(BREAK_OUT));
	});

	actions.push_back([this]{
		App::Singleton().PushScene(GetScene(ASTEROIDS));
	});

	actions.push_back([this]{
		App::Singleton().PushScene(GetScene(PACMAN));
	});

	SetButtonActions(actions);

	ButtonOptionsScene::Init();
}

void ArcadeScene::Update(uint32_t dt)
{
}

void ArcadeScene::Draw(Screen& theScreen)
{
	ButtonOptionsScene::Draw(theScreen);
}

const std::string& ArcadeScene::GetSceneName() const
{
	static std::string sceneName = "Arcade";
	return sceneName;
}


std::unique_ptr<Scene> ArcadeScene::GetScene(eGame game)
{
	switch(game)
	{
		case TETRIS:
		{

		}
		break;

		case BREAK_OUT:
		{
			std::unique_ptr<BreakOut> breakoutGame = std::make_unique<BreakOut>();

			std::unique_ptr<GameScene> breakoutScene = std::make_unique<GameScene>(std::move(breakoutGame));

			return breakoutScene;
		}
		break;

		case ASTEROIDS:
		{

		}
		break;

		case PACMAN:
		{
			return std::make_unique<PacmanStartScene>();
		}
		break;
	}

	std::unique_ptr<Scene> notImplementedScene = std::make_unique<NotImplementedScene>();

	return notImplementedScene;
}
