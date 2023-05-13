#include "TurnBasedEnemy.h"
#include <SimpleEngine/Assets/Assets.h>
#include <SimpleEngine/Algorithms/AStar.h>
#include <SimpleEngine/Game.h>
#include <Components/GridComponents/GridComponent.h>
#include <vector>

#include <iostream>

TurnBasedEnemy::TurnBasedEnemy(const Actor& playerP, const class GridComponent& mapGridP, Vector2 spawnPositionP, float sqPlayerDetectionDistP) :
	Actor(), player(playerP), mapGrid(mapGridP), sqPlayerDetectionDist(sqPlayerDetectionDistP)
{
	drawSpriteComp = new DrawSpriteComponent(this, Assets::getTexture("enemy"), Vector2{ -32.0f, -48.0f }, Renderer::Flip::None);

	rectColComp = new RectangleCollisionComponent(this);
	rectColComp->setRectangle(Rectangle{ -16.0f, -16.0f, 32.0f, 32.0f });

	moveComp = new AToBMoveComponent(this);
	moveComp->setSpeed(200.0f);

	setPosition(spawnPositionP);
	isVisible = CheckVisibility();
}

void TurnBasedEnemy::TurnAction()
{
	if (!playerDetected)
	{
		if ((player.getPosition() - getPosition()).lengthSq() < sqPlayerDetectionDist)
		{
			playerDetected = true;
		}
	}
	else
	{
		int map_this_x, map_this_y = 0;
		mapGrid.screenPointAsGridCoordinates(getPosition(), &map_this_x, &map_this_y);
		Vector2Int map_this = { map_this_x, map_this_y };
		int map_player_x, map_player_y = 0;
		mapGrid.screenPointAsGridCoordinates(player.getPosition(), &map_player_x, &map_player_y);
		Vector2Int map_player = { map_player_x, map_player_y };

		std::vector<Vector2Int> pathfinding = AStar::AStarGridComp(mapGrid, map_this, map_player, true);
		Vector2Int next_movement = *pathfinding.begin();
			std::cout << map_this.toString() << next_movement.toString() << map_player.toString() << "\n";
		if (next_movement != map_player)
		{
			Vector2 grid_tile_size = mapGrid.getTileSize();
			moveComp->setDestination(Vector2{ next_movement.x * grid_tile_size.x + grid_tile_size.x / 2.0f , next_movement.y * grid_tile_size.y + grid_tile_size.y / 2.0f });
		}
	}

	drawSpriteComp->setFlip((!playerDetected != player.getPosition().x > getPosition().x) ? Renderer::Flip::None : Renderer::Flip::Horizontal);

	isVisible = CheckVisibility();
}

bool TurnBasedEnemy::IsUnderMouse(Vector2 mousePos)
{
	Vector2 reel_mouse_pos = mousePos + getGame().getCamera().getCamPos();

	bool under_mouse = rectColComp->intersectWithPoint(reel_mouse_pos);

	if (wasHighlightedLastFrame != under_mouse)
	{
		drawSpriteComp->setTexture(Assets::getTexture(under_mouse ? "enemy_highlight" : "enemy"));
		wasHighlightedLastFrame = under_mouse;
	}

	return under_mouse;
}

bool TurnBasedEnemy::CheckVisibility()
{
	Rectangle scaled_rect = rectColComp->getTransformedRectangle();
	Vector2 cam_scaled_pos = Vector2{ scaled_rect.x, scaled_rect.y } - getGame().getCamera().getCamPos();

	return cam_scaled_pos.x + scaled_rect.width > 0.0f && cam_scaled_pos.x < getGame().getScreenWidth() &&
		cam_scaled_pos.y + scaled_rect.height > 0.0f && cam_scaled_pos.y < getGame().getScreenHeight();
}
