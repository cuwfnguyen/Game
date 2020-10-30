#include "GSPlay.h"
#include"GSMenu.h"
#include "Shaders.h"
#include "Texture.h"
#include "Models.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
std::shared_ptr<GameButton> button1;
extern int screenWidth; //need get on Graphic engine
extern int screenHeight; //need get on Graphic engine

GSPlay::GSPlay()
{
}


GSPlay::~GSPlay()
{

}


void GSPlay::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_play");

	//BackGround
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_BackGround = std::make_shared<Sprite2D>(model, shader, texture);
	m_BackGround->Set2DPosition(screenWidth / 2, screenHeight / 2);
	m_BackGround->SetSize(screenWidth, screenHeight);


	//text game title
	std::shared_ptr<Shaders> shader1 = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd");
	m_score = std::make_shared< Text>(shader1, font, "score: 10", TEXT_COLOR::RED, 1.0);
	m_score->Set2DPosition(Vector2(5, 25));

	//play button
	texture = ResourceManagers::GetInstance()->GetTexture("button_back");
	button1 = std::make_shared<GameButton>(model, shader, texture);
	button1->Set2DPosition(screenWidth / 2, 600);
	button1->SetSize(200,50);
	button1->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateTypes::STATE_Menu);
	});
	
}

void GSPlay::Exit()
{

}


void GSPlay::Pause()
{

}

void GSPlay::Resume()
{

}


void GSPlay::HandleEvents()
{

}

void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
	
}

void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	button1->HandleTouchEvents(x, y, bIsPressed);
	//if (button1->IsHandle());
}

void GSPlay::Update(float deltaTime)
{
	m_BackGround->Update(deltaTime);
	button1->Update(deltaTime);

}

void GSPlay::Draw()
{
	m_BackGround->Draw();
	m_score->Draw();
	button1->Draw();
}

void GSPlay::SetNewPostionForBullet()
{
}