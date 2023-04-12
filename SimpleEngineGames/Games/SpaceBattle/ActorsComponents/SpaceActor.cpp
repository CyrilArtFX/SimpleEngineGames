#include "SpaceActor.h"
#include <SimpleEngine/Game.h>

void SpaceActor::EdgeWrap()
{
	Vector2 pos = getPosition();

	if (pos.y < 0.0f)
	{
		pos.y = getGame().getScreenHeight();
	}
	else if (pos.y > getGame().getScreenHeight())
	{
		pos.y = 0.0f;
	}

	if (pos.x < 0.0f)
	{
		pos.x = getGame().getScreenWidth();
	}
	else if (pos.x > getGame().getScreenWidth())
	{
		pos.x = 0;
	}

	setPosition(pos);
}
