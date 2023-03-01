#include "RacingScene.h"
#include <SimpleEngine/Assets/Assets.h>
#include <SimpleEngine/Game.h>
#include "ActorsComponents/RacingTrack.h"
#include "ActorsComponents/PlayerCar.h"
#include "ActorsComponents/RacingManager.h"

void RacingScene::load(Game* game)
{
	Assets::setAssetsPath("Games/Racing/Assets/");

	Assets::loadGridMap("RacingTrackV1.lua", "trackV1");
	Assets::loadTexture(game->getRenderer(), "redcar.png", "player1Car");

	auto track = new RacingTrack(Assets::getGridMap("trackV1"));

	auto player_one = new PlayerCar(Assets::getTexture("player1Car"));

	auto manager = new RacingManager(track, player_one);

	game->getCamera().setCamPos(Vector2::zero);
}