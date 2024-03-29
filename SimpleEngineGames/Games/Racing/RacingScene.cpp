#include "RacingScene.h"
#include <SimpleEngine/Assets/Assets.h>
#include <SimpleEngine/Game.h>
#include "ActorsComponents/RacingTrack.h"
#include "ActorsComponents/PlayerCar.h"
#include "ActorsComponents/RacingManager.h"

void RacingScene::load(Game* game)
{
	Assets::setAssetsPath("Games/Racing/Assets/");

	Assets::loadFont("Pixeled.ttf", "pixeled30", 30);
	Assets::loadGridMap("RacingTrackV2.lua", "trackV2");
	Assets::loadTexture(game->getRenderer(), "redcar.png", "player1Car");
	Assets::loadTexture(game->getRenderer(), "greencar.png", "player2Car");
	Assets::loadTexture(game->getRenderer(), "track_road.png", "track_road");
	Assets::loadTexture(game->getRenderer(), "track_wall.png", "track_wall");
	Assets::loadTexture(game->getRenderer(), "track_goal.png", "track_goal");
	Assets::loadTexture(game->getRenderer(), "track_grass.png", "track_grass");
	Assets::loadTexture(game->getRenderer(), "track_flag.png", "track_flag");

	auto track = new RacingTrack(Assets::getGridMap("trackV2"));

	auto player_one = new PlayerCar(Assets::getTexture("player1Car"), false);
	auto player_two = new PlayerCar(Assets::getTexture("player2Car"), true);

	auto manager = new RacingManager(track, player_one, player_two);

	game->getCamera().setCamPos(Vector2::zero);
}