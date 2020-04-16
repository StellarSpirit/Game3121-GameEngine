#include "RenderComponentInterface.h"



RenderComponentInterface::RenderComponentInterface(SceneManager* pSceneManager)
{
	mpSceneManager = pSceneManager;
}

void RenderComponentInterface::Update(float dt, sf::RenderWindow* window)
{
	window->clear();
	mRenderActors = mpSceneManager->GetActorsWithRenderComponent();
	for (auto e : mRenderActors)
	{
		RenderComponent* eRender = e->GetRenderComponent();
		TransformComponent* eTransform = e->GetTransformComponent();
		sf::Sprite lSprite = eRender->mSprite;
		lSprite.setPosition(eTransform->GetPosition());
		window->draw(lSprite);
		
	}
	
	
	window->display();
}
