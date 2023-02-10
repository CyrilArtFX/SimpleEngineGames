#include "RacingScene.h"
#include <SimpleEngine/Assets.h>
#include <SimpleEngine/Game.h>
#include "ActorsComponents/RacingTrack.h"

void RacingScene::load(Game* game)
{
	Assets::setAssetsPath("Games/Racing/Assets/");

	Assets::loadGridMap("RacingTrackV1.lua", "trackV1");

	auto track = new RacingTrack(Assets::getGridMap("trackV1"));

	game->getCamera().setCamPos(Vector2::zero);
}