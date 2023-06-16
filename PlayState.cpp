
/*

This cpp file contains all the game logic 


*/


#include <string>
#include <iostream>
#include<SDL_mixer.h>
#include "PlayState.h"
#include "PauseState.h"
#include "GameOverState.h"
#include "AnimatedGraphic.h"
#include "Board.h"
#include <cmath>
#include "Game.h"

static int goatdead;
static int indexOfGoat = 4;//starting goat object in the array of objects
static int numberOfGoat = 24;//number of objects inside the game


const std::string PlayState::s_playID = "PLAY";




void PlayState::update()
{
	

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE)) {
		TheGame::Instance()->getStateMachine()->pushState(new PauseState());//go to pause state
	}

	
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();//update each objects position
	}

	
	
	dynamiccasting();//change base class pointers into specific class objects
	
	int b = gameTurn % 2;//to change turn

	switch (b) {

	case(0) :
		
		if (indexOfGoat >23) {
			turnMoveGoat();//for first 20 goats
		}
		else {
			turnGoat();//after 20 goats have been placed in the board
		}
		break;
		
	case(1) :
		turnTiger();
		break;
	default:
		std::cout << "wrong input" << std::endl;
		break;
	}
	
	
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_BACKSPACE))
	{
		TheGame::Instance()->getStateMachine()->pushState(new GameOverState());//change state manually
	}

	
}



bool PlayState::onEnter()//when you enter from menu state
{   
	//Loading Objects
	if (!TheTextureManager::Instance()->load("assets/tigerMain.png", "tiger1", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/tigerMain.png", "tiger2", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/tigerMain.png", "tiger3", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/tigerMain.png", "tiger4", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat1", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat2", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat3", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat4", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat5", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat6", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat7", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat8", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat9", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat10", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat11", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat12", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat13", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat14", TheGame::Instance()->getRenderer()))
	{
		return false;
	}	
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat15", TheGame::Instance()->getRenderer()))
	{
		return false;
	}	
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat16", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat17", TheGame::Instance()->getRenderer()))
	{
		return false;
	}	
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat18", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat19", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/goatMain.png", "goat20", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/board.png", "board", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	
	int goatXPos = 1250;
	int goatYPos = 950;

	//pointing objects with base class Pointer
	GameObject* player1 = new Player(new LoaderParams(goatXPos, goatYPos, 128, 128, "goat1"));
	GameObject* player2 = new Player(new LoaderParams(goatXPos, goatYPos, 128, 128, "goat2"));
	GameObject* player3 = new Player(new LoaderParams(goatXPos, goatYPos, 128, 128, "goat3"));
	GameObject* player4 = new Player(new LoaderParams(goatXPos, goatYPos, 128, 128, "goat4"));
	GameObject* player5 = new Player(new LoaderParams(goatXPos, goatYPos, 128, 128, "goat5"));
	GameObject* player6 = new Player(new LoaderParams(goatXPos, goatYPos, 128, 128, "goat6"));
	GameObject* player7 = new Player(new LoaderParams(goatXPos, goatYPos, 128, 128, "goat7"));
	GameObject* player8 = new Player(new LoaderParams(goatXPos, goatYPos, 128, 128, "goat8"));
	GameObject* player9 = new Player(new LoaderParams(goatXPos, goatYPos, 128, 128, "goat9"));
	GameObject* player10 = new Player(new LoaderParams(goatXPos, goatYPos, 128, 128, "goat10"));
	GameObject* player11 = new Player(new LoaderParams(goatXPos, goatYPos, 128, 128, "goat11"));
	GameObject* player12 = new Player(new LoaderParams(goatXPos, goatYPos, 128, 128, "goat12"));
	GameObject* player13 = new Player(new LoaderParams(goatXPos, goatYPos, 128, 128, "goat13"));
	GameObject* player14 = new Player(new LoaderParams(goatXPos, goatYPos, 128, 128, "goat14"));
	GameObject* player15 = new Player(new LoaderParams(goatXPos, goatYPos, 128, 128, "goat15"));
	GameObject* player16 = new Player(new LoaderParams(goatXPos, goatYPos, 128, 128, "goat16"));
	GameObject* player17 = new Player(new LoaderParams(goatXPos, goatYPos, 128, 128, "goat17"));
	GameObject* player18 = new Player(new LoaderParams(goatXPos, goatYPos, 128, 128, "goat18"));
	GameObject* player19 = new Player(new LoaderParams(goatXPos, goatYPos, 128, 128, "goat19"));
	GameObject* player20 = new Player(new LoaderParams(goatXPos, goatYPos, 128, 128, "goat20"));


	GameObject* enemy1 = new Enemy(new LoaderParams(0, 0, 128, 128, "tiger1"));
	GameObject* enemy2 = new Enemy(new LoaderParams(800, 800, 128, 128, "tiger3"));
	GameObject* enemy3 = new Enemy(new LoaderParams(800, 0, 128, 128, "tiger2"));
	GameObject* enemy4 = new Enemy(new LoaderParams(0, 800, 128, 128, "tiger4"));


	//loading enemy(tiger)
	m_gameObjects.push_back(enemy1);
	m_gameObjects.push_back(enemy2);
	m_gameObjects.push_back(enemy3);
	m_gameObjects.push_back(enemy4);

	//loading player(goat)
	m_gameObjects.push_back(player1);
	m_gameObjects.push_back(player2);
	m_gameObjects.push_back(player3);
	m_gameObjects.push_back(player4);
	m_gameObjects.push_back(player5);
	m_gameObjects.push_back(player6);
	m_gameObjects.push_back(player7);
	m_gameObjects.push_back(player8);
	m_gameObjects.push_back(player9);
	m_gameObjects.push_back(player10);
	m_gameObjects.push_back(player11);
	m_gameObjects.push_back(player12);
	m_gameObjects.push_back(player13);
	m_gameObjects.push_back(player14);
	m_gameObjects.push_back(player15);
	m_gameObjects.push_back(player16);
	m_gameObjects.push_back(player17);
	m_gameObjects.push_back(player18);
	m_gameObjects.push_back(player19);
	m_gameObjects.push_back(player20);
	
	std::cout << "entering PlayState\n";

	return true;
}

void PlayState::render()
{
	
	//Displaying Background
	TheBoard::Instance()->render();

	TheTextureManager::Instance()->load("assets/1to20.png", "1to20", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("assets/0.png", "0", TheGame::Instance()->getRenderer());

	TheTextureManager::Instance()->load("assets/0to5.jpg", "0to5", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("assets/GoatLogo.png", "gturn", TheGame::Instance()->getRenderer());
	TheTextureManager::Instance()->load("assets/TigerLogo.png", "tturn", TheGame::Instance()->getRenderer());
	
	//dispplaying counter
	if (a > 4 && b>4) {
		TheTextureManager::Instance()->drawFrame("1to20", 975, 250, 75, 75, 4, 4, TheGame::Instance()->getRenderer());
	}
	else if (a == 0 && b == 0) {
		TheTextureManager::Instance()->draw("0", 975, 250, 50, 50,  TheGame::Instance()->getRenderer());

	}
	else  {
		TheTextureManager::Instance()->drawFrame("1to20", 975, 250, 75, 75, a, b, TheGame::Instance()->getRenderer());
	}

	if (goatdead==0) {
		TheTextureManager::Instance()->draw("0", 980, 490, 50, 50, TheGame::Instance()->getRenderer());

	}
	else {
		TheTextureManager::Instance()->drawFrame("1to20", 980, 490, 75, 75, 1, goatdead - 1, TheGame::Instance()->getRenderer());
	}

	int b = gameTurn % 2;
	if (b == 0) {
		TheTextureManager::Instance()->draw("gturn", 990, 800, 100, 50, TheGame::Instance()->getRenderer());
	}
	else {
		TheTextureManager::Instance()->draw("tturn", 990, 800, 100, 50, TheGame::Instance()->getRenderer());
	}
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onExit()
{
	for (int i = 0;i < m_SDLgameObjects.size();i++)
	{
		TheTextureManager::Instance()->clearFromTextureMap(m_SDLgameObjects[i]->getm_textureID());//Deleting objects from array

	}
	
	return true;
}

void PlayState::handleState(){
	
}


void PlayState::limitmoves(SDLGameObject* tiger)//Check Movement Of tiger
{
	//Position of Mouse Click
	int x = TheBoard::Instance()->getR_X();
	int y = TheBoard::Instance()->getR_Y();
	//Position of Object
	int x_pos = (((int)abs(tiger->getPosition().getX())) / 200) % 2;
	int y_pos = (((int)abs(tiger->getPosition().getY())) / 200) % 2;

	if ((x_pos == 1 && y_pos == 0) || (x_pos == 0 && y_pos == 1))  //Either of the condition must be satisfied to move diagonally
	{
		int a = abs(tiger->getPosition().getX() - x);
		int b = abs(tiger->getPosition().getY() - y);
		float c = (float)sqrt(abs(pow(a, 2) + pow(b, 2)));

		if (c == 200)
		{
			if (dontoverlap(x, y))//check whether it overlaps any other objects or not
			{
				Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 1, 1024);
				Mix_Music* gmusic = Mix_LoadMUS("C:/users/shaswot paudel/Downloads/test.WAV");
				Mix_Chunk* gsound = Mix_LoadWAV("C:/users/shaswot paudel/Downloads/test.WAV");
				Mix_PlayMusic(gmusic, 0);
				tiger->handleInput();//Calling objects Handle input
				gameTurn++;
			}
		}
		else if (c == 400)
		{
			int midx = (x + tiger->getPosition().getX()) / 2;
			int midy = (y + tiger->getPosition().getY()) / 2;

			if (dontoverlap(x, y))//check whether it overlaps any other objects or not 
			{
				if (killer(midx, midy))//check whether goats get killed or not
				{
					Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 1, 1024);
					Mix_Music* gmusic = Mix_LoadMUS("C:/users/shaswot paudel/Downloads/GOATKILL.WAV");
					Mix_Chunk* gsound = Mix_LoadWAV("C:/users/shaswot paudel/Downloads/GOATKILL.WAV");
					Mix_PlayMusic(gmusic, 0);
					tiger->handleInput();
					goatdead++;//incrementing the number of goad dead

					if (goatdead == 5)
					{
						indexOfGoat = 4;
						a = 0;
						b = 0;
						numberOfGoat = 24;
						TheGame::Instance()->getStateMachine()->pushState(new GameOverState());//change to game over after tiger win
					}
					gameTurn++;
				}
			}
		}
	}
	else {//for the tiger objects that can move diagonally

		int a = abs(tiger->getPosition().getX() - x);
		int b = abs(tiger->getPosition().getY() - y);
		double e = sqrt(abs(pow(a, 2) + pow(b, 2)));
		double d = 200 * sqrt(2);



		if (e == 200 || e == (double)200 * sqrt(2))
		{

			if (dontoverlap(x, y)) {
				Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 1, 1024);
				Mix_Music* gmusic = Mix_LoadMUS("C:/users/shaswot paudel/Downloads/test.WAV");
				Mix_Chunk* gsound = Mix_LoadWAV("C:/users/shaswot paudel/Downloads/test.WAV");
				Mix_PlayMusic(gmusic, 0);
				tiger->handleInput();
				gameTurn++;
			}
		}
		else if (e == 400 || e == 400 * sqrt(2))
		{

			int midx = (x + tiger->getPosition().getX()) / 2;
			int midy = (y + tiger->getPosition().getY()) / 2;


			if (dontoverlap(x, y))
			{
				if (killer(midx, midy))
				{
					Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 1, 1024);
					Mix_Music* gmusic = Mix_LoadMUS("C:/users/shaswot paudel/Downloads/GOATKILL.WAV");
					Mix_Chunk* gsound = Mix_LoadWAV("C:/users/shaswot paudel/Downloads/GOATKILL.WAV");
					Mix_PlayMusic(gmusic, 0);
					tiger->handleInput();
					goatdead++;
					
					if (goatdead == 5)
					{
						indexOfGoat = 4;
						a = 0;
						b = 
						numberOfGoat = 24;0;
						TheGame::Instance()->getStateMachine()->pushState(new GameOverState());
					}
					gameTurn++;
				}
			}
		}
	}
}

bool PlayState::killer(int midx,int midy)//function which kills the goat object
{
	
	int a;
	int b;
	
	for (int i = 4;i < numberOfGoat; i++) {
		
		a = m_SDLgameObjects[i]->getPosition().getX();
		b = m_SDLgameObjects[i]->getPosition().getY();

		if (a == midx && b == midy)
		{
			TheTextureManager::Instance()->clearFromTextureMap(m_SDLgameObjects[i]->getm_textureID());
			m_SDLgameObjects.erase(m_SDLgameObjects.begin() + i);
			numberOfGoat -= 1;
			return true;
		}
	}
	return false;
}

void PlayState::dynamiccasting() 
{
	for (int i = 0; i <4; i++)
	{
		m_SDLgameObjectsTiger.push_back(dynamic_cast<SDLGameObject*>(m_gameObjects[i]));
		m_SDLgameObjects.push_back(dynamic_cast<SDLGameObject*>(m_gameObjects[i]));
		
	}
	for (int i = 4; i < m_gameObjects.size(); i++)
	{
		m_SDLgameObjectsGoat.push_back(dynamic_cast<SDLGameObject*>(m_gameObjects[i]));
		m_SDLgameObjects.push_back(dynamic_cast<SDLGameObject*>(m_gameObjects[i]));
		
	}

}

void PlayState::turnTiger()//
{
	static int palo = 25;
	Vector2D* pMousePos2 = TheInputHandler::Instance()->getMousePosition();
	int  mouspos_X, mouspos_Y;
	//mouse position
	mouspos_X = TheBoard::Instance()->getR_X();
	mouspos_Y = TheBoard::Instance()->getR_Y();

	if (mouspos_X == m_SDLgameObjects[0]->getPosition().getX() && mouspos_Y == m_SDLgameObjects[0]->getPosition().getY()) {
		palo = 1;
	}

	if (mouspos_X == m_SDLgameObjects[1]->getPosition().getX() && mouspos_Y == m_SDLgameObjects[1]->getPosition().getY()) {
		palo = 2;
	}
	if (mouspos_X == m_SDLgameObjects[2]->getPosition().getX() && mouspos_Y == m_SDLgameObjects[2]->getPosition().getY()) {
		palo = 3;
	}
	if (mouspos_X == m_SDLgameObjects[3]->getPosition().getX() && mouspos_Y == m_SDLgameObjects[3]->getPosition().getY()) {
		palo = 4;
	}
	
	switch (palo) {

	case 1:
		
		limitmoves(m_SDLgameObjectsTiger[0]);
		break;
	case 2:
		limitmoves(m_SDLgameObjectsTiger[1]);
		break; 
	case 3:
		limitmoves(m_SDLgameObjectsTiger[2]);
		break;
	case 4:
		limitmoves(m_SDLgameObjectsTiger[3]);
		break;
	default:
		break;

	}


}

void PlayState::turnGoat() {

	int p=1250;
	int q=950;

	if (TheInputHandler::Instance()->getMouseButtonState(RIGHT))
	{
		Vector2D* pMousePos = TheInputHandler::Instance()->getMousePosition();

		p = (TheBoard::Instance()->filterX(pMousePos->getX()));
		q = (TheBoard::Instance()->filterY(pMousePos->getY()));

	}
    int correct = 0;
	
	for (int i = 0;i <numberOfGoat;i++) {

		if ( (m_SDLgameObjects[i]->getPosition().getX() != p) || (m_SDLgameObjects[i]->getPosition().getY() != q) ) {
			correct++;
			continue;
		}
	}

	if (correct == numberOfGoat) {
		Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 1, 1024);
		Mix_Music* gmusic = Mix_LoadMUS("C:/users/shaswot paudel/Downloads/GOATSOUND.mp3");
		Mix_Chunk* gsound = Mix_LoadWAV("C:/users/shaswot paudel/Downloads/GOATSOUND.mp3");
		Mix_PlayMusic(gmusic, 0);

		m_SDLgameObjects[indexOfGoat-goatdead]->getPosition().setX(p);
		m_SDLgameObjects[indexOfGoat-goatdead]->getPosition().setY(q);

		
		indexOfGoat++;
		if (b == 4) {
			a++;
			b = 0;
		}
		else  if (a == 0) {
			a++;
		}
		else {
			b++;
		}
		
		
		correct = 0;

		gameTurn++;
	}	
	goatWinWin();
}

bool PlayState :: dontoverlap(int a,int b)//to check whether the position has any other object or not
{
	for (int i = 0; i < numberOfGoat; i++)
	{

		if ((m_SDLgameObjects[i]->getPosition().getX() == a) && (m_SDLgameObjects[i]->getPosition().getY() == b)) {
			return false;
		}
	}
	return true;
}

bool PlayState::goatWin(int a)
{
	int  right = 0;//to count how many objects block the specific tiger

	int c = m_SDLgameObjects[a]->getPosition().getX();
	int d = m_SDLgameObjects[a]->getPosition().getY();
	int x = c / 200;
	int y = d / 200;
	int x_pos = (((int)abs(m_SDLgameObjects[a]->getPosition().getX())) / 200) % 2;
	int y_pos = (((int)abs(m_SDLgameObjects[a]->getPosition().getY())) / 200) % 2;

	if ((x_pos == 1 && y_pos == 0) || (x_pos == 0 && y_pos == 1))//to check tigers which cannot move diagonally
	{
		

		for (int i = 0; i < numberOfGoat; i++)
		{
			int x1 = m_SDLgameObjects[i]->getPosition().getX();
			int y1 = m_SDLgameObjects[i]->getPosition().getY();



			double xdistance = pow(abs(x1 - c), 2);
			double ydistance = pow(abs(y1 - d), 2);
			double distance = pow(xdistance + ydistance, 0.5);//distace between the object in the funtion and everyother object inside the board

			if (distance == 200)
			{
				right++;
			}
			if (distance == 400)
			{
				right++;
			}
		}
		if ((x==2 && y==1) || (x ==1 && y ==2 ) || (x ==2 && y ==3 ) || (x ==3 && y ==2 ))
		{		
					if (right == 7) {
						
						return true;
					}
		}else if (right == 5) 
		{
				return true;
		}
	}else  
	{
		for (int i = 0; i < numberOfGoat; i++)
		{
			int x1 = m_SDLgameObjects[i]->getPosition().getX();
			int y1 = m_SDLgameObjects[i]->getPosition().getY();

			double xdistance = pow(abs(x1 - c), 2);
			double ydistance = pow(abs(y1 - d), 2);
			double distance = pow(xdistance + ydistance, 0.5);

			if (distance == 200)
			{
				right++;
			}
			if (distance == 200 * sqrt(2))
			{
				right++;
			}
			if (distance == 400)
			{
				right++;
			}
			if (distance == 400 * sqrt(2))
			{
				right++;
			}
		}
		if (x % 2 == 0 && y % 2 == 0)
		{
			if (x == 2 && y == 2)
			{
				if (right == 16)
				{
					return true;
				}
			}else if ((x == 0 && y == 0) || (x == 4 && y == 0) || (x == 0 && y == 4) || (x == 4 && y == 4)) 
			{
				if (right == 6)
				{
					return true;
				}
			}else if (right == 10)
			{
				return true;
			}
		}else if (x != 2 && y != 2)
		{
			if (x % 2 == 1 && y % 2 == 1)
			{
				if (right == 11) 
				{
					return true;
				}
			}
		}
	}
    return false;
}
void PlayState::goatWinWin()
{
	if ( goatWin(0)&&goatWin(1)&&goatWin(2)&&goatWin(3))//check whether all the goats are trapped or not
	{
		gameTurn = 0;
		TheGame::Instance()->getStateMachine()->pushState(new GameOverState());//gameover goat win
	}
}

void PlayState::turnMoveGoat() {//After 20 goats have been dropped 
	static int paloGoat = 25;
	Vector2D* pMousePos2 = TheInputHandler::Instance()->getMousePosition();

	int  mouspos_X, mouspos_Y;
	//mouse position
	mouspos_X = TheBoard::Instance()->getR_X();
	mouspos_Y = TheBoard::Instance()->getR_Y();

	for (int i = 4; i < numberOfGoat; i++) {
		if (mouspos_X == m_SDLgameObjects[i]->getPosition().getX() && mouspos_Y == m_SDLgameObjects[i]->getPosition().getY()) {
			paloGoat = i+1;
		}
	}
	switch (paloGoat)
	{
	case(5):
		limitmovesGoat(m_SDLgameObjects[4]);
		break;
	case(6):
		limitmovesGoat(m_SDLgameObjects[5]);
		break;
	case(7):
		limitmovesGoat(m_SDLgameObjects[6]);
		break;
	case(8):
		limitmovesGoat(m_SDLgameObjects[7]);
		break;
	case(9):
		limitmovesGoat(m_SDLgameObjects[8]);
		break;
	case(10):
		limitmovesGoat(m_SDLgameObjects[9]);
		break;
	case(11):
		limitmovesGoat(m_SDLgameObjects[10]);
		break;
	case(12):
		limitmovesGoat(m_SDLgameObjects[11]);
		break;
	case(13):
		limitmovesGoat(m_SDLgameObjects[12]);
		break;
	case(14):
		limitmovesGoat(m_SDLgameObjects[13]);
		break;
	case(15):
		limitmovesGoat(m_SDLgameObjects[14]);
		break;
	case(16):
		limitmovesGoat(m_SDLgameObjects[15]);
		break;
	case(17):
		limitmovesGoat(m_SDLgameObjects[16]);
		break;
	case(18):
		limitmovesGoat(m_SDLgameObjects[17]);
		break;
	case(19):
		limitmovesGoat(m_SDLgameObjects[18]);
		break;
	case(20):
		limitmovesGoat(m_SDLgameObjects[19]);
		break;
	case(21):
		limitmovesGoat(m_SDLgameObjects[20]);
		break;
	case(22):
		limitmovesGoat(m_SDLgameObjects[21]);
		break;
	case(23):
		limitmovesGoat(m_SDLgameObjects[22]);
		break;
	case(24):
		limitmovesGoat(m_SDLgameObjects[23]);
		break;
	default:
		break;
	}
}
void PlayState::limitmovesGoat(SDLGameObject* goat) {//so that goat doesnot move randomly
	int x = TheBoard::Instance()->getR_X();
	int y = TheBoard::Instance()->getR_Y();

	int x_pos = (((int)abs(goat->getPosition().getX())) / 200) % 2;
	int y_pos = (((int)abs(goat->getPosition().getY())) / 200) % 2;

	if ((x_pos == 1 && y_pos == 0) || (x_pos == 0 && y_pos == 1))  //Either of the condition must be satisfied to move diagonally
	{
		int a = abs(goat->getPosition().getX() - x);
		int b = abs(goat->getPosition().getY() - y);
		float c = (float)sqrt(abs(pow(a, 2) + pow(b, 2)));

		if (c == 200)
		{

			if (dontoverlap(x, y))
			{
				Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 1, 1024);
				Mix_Music* gmusic = Mix_LoadMUS("C:/users/shaswot paudel/Downloads/GOATSOUND.mp3");
				Mix_Chunk* gsound = Mix_LoadWAV("C:/users/shaswot paudel/Downloads/GOATSOUND.mp3");
				Mix_PlayMusic(gmusic, 0);
				goat->handleInput();
				goatWinWin();
				gameTurn++;
			}
		}
	}
	else {
		int a = abs(goat->getPosition().getX() - x);
		int b = abs(goat->getPosition().getY() - y);
		double e = sqrt(abs(pow(a, 2) + pow(b, 2)));
		double d = 200 * sqrt(2);



		if (e == 200 || e == (double)200 * sqrt(2))
		{

			if (dontoverlap(x, y)) {
				Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 1, 1024);
				Mix_Music* gmusic = Mix_LoadMUS("C:/users/shaswot paudel/Downloads/GOATSOUND.mp3");
				Mix_Chunk* gsound = Mix_LoadWAV("C:/users/shaswot paudel/Downloads/GOATSOUND.mp3");
				Mix_PlayMusic(gmusic, 0);
				goat->handleInput();
				goatWinWin();
				gameTurn++;

			}
		}
	}

}


	




