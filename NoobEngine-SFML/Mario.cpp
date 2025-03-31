#include "Mario.h"

Mario::Mario()
{
	marioSpriteSheet.loadFromFile("gfx/MarioSheetT.png");
	setSize(sf::Vector2f(16*4, 21*4));
	setPosition(300, 100);
	setTexture(&marioSpriteSheet);

	walk.addFrame(sf::IntRect(0, 0, 15, 21));
	walk.addFrame(sf::IntRect(15, 0, 15, 21));
	walk.addFrame(sf::IntRect(30, 0, 15, 21));
	walk.addFrame(sf::IntRect(45, 0, 15, 21));
	walk.setFrameSpeed(1.f / 10.f);

	swim.addFrame(sf::IntRect(0, 21, 16, 20));
	swim.addFrame(sf::IntRect(16, 21, 16, 20));
	swim.addFrame(sf::IntRect(32, 21, 16, 20));
	swim.setFrameSpeed(1.f / 4.f);

	currentAnimation = &walk;
	setTextureRect(currentAnimation->getCurrentFrame());

	duck.addFrame(sf::IntRect(0, 44, 17, 17));
	duck.setFrameSpeed(1.f / 2.f);
	currentAnimation = &walk;
	setTextureRect(currentAnimation->getCurrentFrame());
}

Mario::~Mario()
{
}

void Mario::update(float dt)
{

}

void Mario::handleInput(float dt)
{
	velocity.x = 0.f;
	setTextureRect(currentAnimation->getCurrentFrame());

	if (input->isKeyDown(sf::Keyboard::A))
	{
		currentAnimation->setFlipped(true);
		currentAnimation = &walk;
		velocity.x = -200;
	}
	else if (input->isKeyDown(sf::Keyboard::D))
	{
		currentAnimation->setFlipped(false);
		currentAnimation = &walk;
		velocity.x = 200;
	}
	else if (input->isKeyDown(sf::Keyboard::S))
	{
		currentAnimation = &duck;
	}
	else if (input->isKeyDown(sf::Keyboard::W))
	{
		currentAnimation = &swim;
	}
	else
	{
		currentAnimation->reset();
		currentAnimation = &walk;
	}

	if (input->isKeyDown(sf::Keyboard::Space) && canJump)
	{
		Jump(160.f);
	}
	currentAnimation->animate(dt);
}
