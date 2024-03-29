#pragma once
#include <SimpleEngine/ActorsComponents/Component.h>
#include <SimpleEngine/Renderer.h>

class DrawComponent : public Component
{
public:
	DrawComponent(Actor* ownerP, int drawOrderP = 100);
	virtual ~DrawComponent();
	DrawComponent() = delete;
	DrawComponent(const DrawComponent&) = delete;
	DrawComponent& operator=(const DrawComponent&) = delete;

	virtual void draw(Renderer& renderer);

	int getDrawOrder() const { return drawOrder; }

	void setWillDraw(bool willDrawP);

protected:
	int drawOrder;
	bool willDraw{ true };
};

