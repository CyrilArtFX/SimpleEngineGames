#include "StoneshardMap.h"
#include <Components/GridComponents/GridTileDrawRectangle.h>
#include <Components/GridComponents/GridTileDrawSprite.h>
#include <SimpleEngine/Assets/Assets.h>

StoneshardMap::StoneshardMap(GridMap* gridMapP)
{
	gridComp = new GridComponent(this, gridMapP);
	gridComp->setTileSize(Vector2{ 32.0f, 32.0f });

	/*gridComp->setTileTraduction(0, new TileTraduction{new GridTileDrawRectangle(Color(154, 205, 50, 255), Rectangle::unitRect), true});
	gridComp->setTileTraduction(1, new TileTraduction{ new GridTileDrawRectangle(Color(34, 139, 34, 255), Rectangle::unitRect), true });*/

	gridComp->setTileTraduction(1, new TileTraduction{ new GridTileDrawSprite(Assets::getTexture("tile_tree_top")), true });
	gridComp->setTileTraduction(2, new TileTraduction{ new GridTileDrawSprite(Assets::getTexture("tile_grass")), true });
	gridComp->setTileTraduction(3, new TileTraduction{ new GridTileDrawSprite(Assets::getTexture("tile_big_tree_top_left")), true });
	gridComp->setTileTraduction(4, new TileTraduction{ new GridTileDrawSprite(Assets::getTexture("tile_big_tree_top_right")), true });
	gridComp->setTileTraduction(5, new TileTraduction{ new GridTileDrawSprite(Assets::getTexture("tile_tree_middle")), true });
	gridComp->setTileTraduction(6, new TileTraduction{ new GridTileDrawSprite(Assets::getTexture("tile_bush")), true });
	gridComp->setTileTraduction(7, new TileTraduction{ new GridTileDrawSprite(Assets::getTexture("tile_big_tree_middle_left")), true });
	gridComp->setTileTraduction(8, new TileTraduction{ new GridTileDrawSprite(Assets::getTexture("tile_big_tree_middle_right")), true });
	gridComp->setTileTraduction(9, new TileTraduction{ new GridTileDrawSprite(Assets::getTexture("tile_tree_bottom")), true });
	gridComp->setTileTraduction(10, new TileTraduction{ new GridTileDrawSprite(Assets::getTexture("tile_small_tree")), true });
	gridComp->setTileTraduction(11, new TileTraduction{ new GridTileDrawSprite(Assets::getTexture("tile_big_tree_bottom_left")), true });
	gridComp->setTileTraduction(12, new TileTraduction{ new GridTileDrawSprite(Assets::getTexture("tile_big_tree_bottom_right")), true });

	//  if anyone see this, yeah I know this is horrible, I will do a proper integration of tilesheet but I don't have time to do that now, it will be done this summer

	
	gridComp->setAstarTraduction(2, AstarTraduction{ true, 10, 14 });
}