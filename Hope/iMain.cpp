#include<iostream>
using namespace std;
#include "iGraphics.h"


#define screenWidth 1920
#define screenHeight 1080
#define SPEED 3


struct buttonCordinate{

	int x;
	int y;
}bCordinate[6];


char homemenu[20] = "Background\\menu.png";
char button[6][25] = { "Buttons\\play.png", "Buttons\\store.png", "Buttons\\options.png", "Buttons\\help.png", "Buttons\\credit.png", "Buttons\\exit.png" };

char play[20] = "Background\\bg4.png";
char store[25] = "Background\\store.png";
char gameOverImage[30] = "Background\\gameover.png";
char khelaparena[30] = "Background\\tanjiroded.png";
char credit[30] = "Background\\credit scene.png";
char help[30] = "Background\\help.png";
char navigation[30] = "Background\\help2.png";
char sfx[30] = "Background\\sfx.png";

//power limit
int hk = 0;
int wb11 = 0;
int wb1 = 0;

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
bool musicon = false;

int attack, autoindex;
int gameState = -1;

//tanjiro
char tanjiro[6][25] = { "Tanjiro\\dour1.png", "Tanjiro\\dour2.png", "Tanjiro\\dour3.png", "Tanjiro\\dour4.png", "Tanjiro\\dour5.png", "Tanjiro\\dour6.png" };
char rtanjiro[6][25] = { "Tanjiro\\r.dour1.png", "Tanjiro\\r.dour2.png", "Tanjiro\\r.dour3.png", "Tanjiro\\r.dour4.png", "Tanjiro\\r.dour5.png", "Tanjiro\\r.dour6.png" };
char tanjirostand[25] = "Tanjiro\\kharayase.png";
char tanjirowaterbreathing1[10][25] = { "water1\\wb1.png", "water1\\wb2.png", "water1\\wb3.png", "water1\\wb4.png", "water1\\wb5.png", "water1\\wb6.png", "water1\\wb7.png", "water1\\wb8.png", "water1\\wb9.png", "water1\\wb10.png" };
char tanjirobasicattack[9][25] = { "battack\\ba1.png", "battack\\ba2.png", "battack\\ba3.png", "battack\\ba4.png", "battack\\ba5.png", "battack\\ba6.png", "battack\\ba7.png", "battack\\ba8.png", "battack\\ba9.png" };
char tanjirowaterbreathing11[7][25] = { "water11\\wb1.png", "water11\\wb2.png", "water11\\wb3.png", "water11\\wbd1.png", "water11\\wbd2.png", "water11\\wbd3.png", "water11\\wbd4.png" };
char hinogamikagura[11][25] = { "hinogamikagura\\1st.png", "hinogamikagura\\2nd.png", "hinogamikagura\\3rd.png", "hinogamikagura\\4th.png", "hinogamikagura\\5th.png", "hinogamikagura\\6th.png", "hinogamikagura\\7th.png"};
int tanjiroCordinateX = 450;
int tanjiroCordinateY = 100;
int tanjiroIndex = 0;
int rtanjiroIndex = 0;
int tanjirowb1Index = 0;
int tanjirobaIndex = 0;
int tanjirowb11Index = 0;
int tanjirohkIndex = 0;
int storeCoins = 0;
//muzan
char muzan[4][25] = { "Villain\\m.png" , "Villain\\n.png" , "Villain\\o.png" , "Villain\\p.png" };
char muzanstand[25] = "Villain\\m.png";
char muzanatk[10][50] = { "Villain\\1.png", "Villain\\2.png", "Villain\\3.png", "Villain\\4.png", "Villain\\5.png", "Villain\\6.png", "Villain\\7.png", "Villain\\8.png" , "Villain\\9.png", "Villain\\10.png" };
char muzandatk[10][50] = { "Villain\\1.png", "Villain\\2.png", "Villain\\3.png", "Villain\\4.png", "Villain\\5.png", "Villain\\6.png", "Villain\\7.png", "Villain\\8.png", "Villain\\9.png", "Villain\\10.png" };
int muzanCordinateX = 1350;
int muzanCordinateY = 100;
int muzanIndex = 0;
int muzanatkIndex = 0;
int muzanatk2Index = 0;
int muzanatk3Index = 0;
int muzanAnimationtimer;

bool muzand = false;
bool muzans = false;
bool muzanatk1 = true;
bool muzanatk2 = false;
bool muzanatk3 = false;
bool muzandefeated = false;
bool tanjirodefeated = false;
//stance
bool standPosition = true;
bool fight1 = false;
bool fight2 = false;
bool fight3 = false;
bool fight4 = false;
bool running = false;
bool frunning = false;
bool brunning = false;
int standcount = 0;
int rstandcount = 0;


//health
int health = 292;
int muzanhealth = 292;
int healthbarImage;
int muzanhealthbarImage;
char healthbar[25] = "Background\\Healthbar.png";
char muzanhealthBar[30] = "Background\\muzanhealthbar.png";

//score
int totalCoins;
int countTimer;
int randatk;
char scoreStr[100000];

bool playh;
bool storeh;
bool optionsh;
bool helph;
bool credith;
bool exith;
bool backh;
bool onh;
bool offh;


bool slay = false;
void Healthbar()
{

	healthbarImage = iLoadImage(healthbar);
	iShowImage(50, 900, 400, 100, healthbarImage);

	iSetColor(160, 160, 160);
	iFilledRectangle(150, 925, 292, 37);
	if (health > 180)
		iSetColor(0, 204, 0);
	else if (health > 60)
		iSetColor(220, 220, 0);
	else
		iSetColor(204, 0, 0);

	iFilledRectangle(150, 925, health, 37);
	if (health <= 1)
	{
		tanjirodefeated = true;
	}
}
void muzanHealthBar()
{
	muzanhealthbarImage = iLoadImage(muzanhealthBar);
	iShowImage(1400, 900, 400, 100, muzanhealthbarImage);

	iSetColor(160, 160, 160);
	iFilledRectangle(1408, 930, 292, 34);
	if (muzanhealth > 180)
		iSetColor(0, 204, 0);
	else if (muzanhealth > 60)
		iSetColor(220, 220, 0);
	else
		iSetColor(204, 0, 0);

	iFilledRectangle(1408, 930, muzanhealth, 34);
	if (muzanhealth == 0)
	{
		muzandefeated = true;
	}
}
void muzankibutsuji()
{
	if (muzand)
	{
		int muzandour = iLoadImage(muzan[muzanIndex]);
		iShowImage(muzanCordinateX, muzanCordinateY, 250, 216, muzandour);
	}
	if (muzanatk1)
	{
		int muzanattack1 = iLoadImage(muzanatk[muzanatkIndex]);
		iShowImage(muzanCordinateX, muzanCordinateY, 350, 316, muzanattack1);
	}
	if (muzanatk2)
	{
		int muzanattack2 = iLoadImage(muzandatk[muzanatk2Index]);
		iShowImage(muzanCordinateX, 65, 350, 316, muzanattack2);
	}
	if (muzanatk3)
	{
		int muzanattack3 = iLoadImage(muzandatk[muzanatk3Index]);
		iShowImage(muzanCordinateX, muzanCordinateY, 350, 316, muzanattack3);
	}
}
void muzananimation()
{

	if (muzanatk1)
	{
		if (tanjiroCordinateX + 250 > muzanCordinateX && tanjiroCordinateX<muzanCordinateX + 350)
		{
			health -= 1;

		}
		muzanCordinateX -= 40;
		if (muzanatkIndex < 15)
		{
			muzanatkIndex++;

			if (muzanCordinateX <= 450)
			{
				muzanCordinateX = 1350;
			}
		}
		else
		{
			muzanatkIndex = 0;
		}

	}

	if (muzanatk2)
	{
		if (tanjiroCordinateX + 250 > muzanCordinateX && tanjiroCordinateX<muzanCordinateX + 350)
		{
			health -= 2;

		}
		muzanCordinateX -= 40;
		if (muzanatk2Index < 16)
		{
			muzanatk2Index++;

			if (muzanCordinateX <= 450)
			{
				muzanCordinateX = 1350;
			}
		}
		else
		{
			muzanatk2Index = 0;
		}
	}

}

void playermovement()
{	//tanjiro stand and run
	if (running)
	{
		if (frunning)
		{
			int tandour = iLoadImage(tanjiro[tanjiroIndex]);
			iShowImage(tanjiroCordinateX, tanjiroCordinateY, 250, 216, tandour);
			standcount++;
			if (standcount >= 20)
			{
				standcount = 0;
				tanjiroIndex = 0;
				standPosition = true;
			}

		}
		if (brunning)
		{
			int rtandour = iLoadImage(rtanjiro[rtanjiroIndex]);
			iShowImage(tanjiroCordinateX, tanjiroCordinateY, 250, 216, rtandour);
			rstandcount++;
			if (rstandcount >= 20)
			{
				rstandcount = 0;
				rtanjiroIndex = 0;
				standPosition = true;
			}

		}
		else if (standPosition)
		{
			frunning = false;
			brunning = false;
			int tanstand = iLoadImage(tanjirostand);
			iShowImage(tanjiroCordinateX, tanjiroCordinateY, 250, 216, tanstand);
		}

	}

	//waterbreathing1 ATTACK 1

	else if (fight1)
	{
		int sword = iLoadImage(tanjirobasicattack[tanjirobaIndex]);
		iShowImage(tanjiroCordinateX, tanjiroCordinateY, 250, 216, sword);
	}
	// basic attacck!
	else if (fight2)
	{
		int waterbreathing1 = iLoadImage(tanjirowaterbreathing1[tanjirowb1Index]);
		iShowImage(tanjiroCordinateX, tanjiroCordinateY, 250, 216, waterbreathing1);
	}

	//waterbreathing11 ATTACK 2

	else if (fight3)
	{
		int waterbreathing11 = iLoadImage(tanjirowaterbreathing11[tanjirowb11Index]);
		iShowImage(tanjiroCordinateX, tanjiroCordinateY, 250, 216, waterbreathing11);
	}

	//Hinogami kagura Attack 3

	else if (fight4)
	{
		int hinogami = iLoadImage(hinogamikagura[tanjirohkIndex]);
		iShowImage(tanjiroCordinateX, tanjiroCordinateY, 250, 216, hinogami);
	}

	else if (standPosition)
	{
		int tanstand = iLoadImage(tanjirostand);
		iShowImage(tanjiroCordinateX, tanjiroCordinateY, 250, 216, tanstand);
	}

}



void CollisionCheck()
{
	if (fight1)
	{
		if ((tanjiroCordinateX + 250 >= muzanCordinateX) && (tanjiroCordinateX <= muzanCordinateX + 350))
		{
			muzanhealth -= 10;
			storeCoins += 20;

		}
	}
	else if (fight2)
	{
		if (tanjiroCordinateX + 250 > muzanCordinateX && tanjiroCordinateX<muzanCordinateX + 350)
		{
			muzanhealth -= 15;
			storeCoins += 40;

		}
	}
	else if (fight3)
	{
		if (tanjiroCordinateX + 250 > muzanCordinateX && tanjiroCordinateX<muzanCordinateX + 350)
		{
			muzanhealth -= 30;
			storeCoins += 120;

		}
	}
	else if (fight4)
	{
		if (tanjiroCordinateX + 250 > muzanCordinateX && tanjiroCordinateX<muzanCordinateX + 350)
		{
			muzanhealth -= 50;
			storeCoins += 200;

		}
	}


}
void ShowGameOver()
{
	if (muzandefeated)
	{
		int goim = iLoadImage(gameOverImage);
		iShowImage(0, 0, 1920, 1080, goim);
	}
	if (tanjirodefeated)
	{
		int td = iLoadImage(khelaparena);
		iShowImage(0, 0, 1920, 1080, td);
	}
}
void gameOver()
{
	muzanatk1 = false;
	muzanatk2 = false;
	iPauseTimer(randatk);
	iPauseTimer(muzanAnimationtimer);

}
void randAttack()
{
	if (muzanatk1)
	{
		if (muzanatkIndex >= 8)
		{
			muzanatk1 = false;
			muzanatk2 = true;
			muzanatkIndex = 0;
		}
	}
	if (muzanatk2)
	{
		if (muzanatk2Index >= 8)
		{
			muzanatk2 = false;
			muzanatk1 = true;
			muzanatk2Index = 0;
		}
	}
}

void playGame()
{
	iResumeTimer(muzanAnimationtimer);
	iResumeTimer(randatk);
	int img3 = iLoadImage(play);
	iShowImage(0, 0, 1920, 1080, img3);
	int nav = iLoadImage(navigation);
	iShowImage(50, 600, 300, 300, nav);

	Healthbar();
	muzanHealthBar();
	playermovement();
	muzankibutsuji();


	if (muzanhealth <= 1)
	{
		muzandefeated = true;
	}
	if (muzandefeated)
	{
		ShowGameOver();
		gameOver();
		sprintf_s(scoreStr, "%d", storeCoins);
		iSetColor(255, 255, 255);
		iText(970, 430, scoreStr, GLUT_BITMAP_TIMES_ROMAN_24);
		tanjirodefeated = false;

	}

	if (tanjirodefeated)
	{
		gameOver();
		ShowGameOver();

	}
}
void iDraw()
{
	iClear();

	if (gameState == -1)
	{
		//HomePage(Menu)

		int img = iLoadImage(homemenu);
		iShowImage(0, 0, 1920, 1080, img);
		if (playh)
		{
			int high = iLoadImage("Background\\hl.png");
			iShowImage(702, 806, 500, 200, high);
		}
		if (storeh)
		{
			int high = iLoadImage("Background\\hl.png");
			iShowImage(702, 656, 500, 200, high);
		}
		if (optionsh)
		{
			int high = iLoadImage("Background\\hl.png");
			iShowImage(702, 506, 500, 200, high);
		}
		if (helph)
		{
			int high = iLoadImage("Background\\hl.png");
			iShowImage(702, 356, 500, 200, high);
		}
		if (credith)
		{
			int high = iLoadImage("Background\\hl.png");
			iShowImage(702, 206, 500, 200, high);
		}
		if (exith)
		{
			int high = iLoadImage("Background\\hl.png");
			iShowImage(702, 56, 500, 200, high);
		}
		for (int i = 0; i < 6; i++)
		{
			int img2 = iLoadImage(button[i]);
			iShowImage(bCordinate[i].x, bCordinate[i].y, 309, 112, img2);
		}
	}
	//PLAY WINDOW
	else if (gameState == 0)
	{

		playGame();

	}
	//Store
	else if (gameState == 1)
	{

		int img4 = iLoadImage(store);
		iShowImage(0, 0, 1920, 1080, img4);

		if (backh)
		{
			int high = iLoadImage("Background\\hl.png");
			iShowImage(613, 215, 670, 270, high);
		}

	}
	else if (gameState == 2)
	{
		int options = iLoadImage(sfx);
		iShowImage(0, 0, 1920, 1080, options);

		if (onh)
		{
			int high = iLoadImage("Background\\hl.png");
			iShowImage(660, 415, 500, 200, high);
		}

		if (offh)
		{
			int high = iLoadImage("Background\\hl.png");
			iShowImage(660, 257, 500, 200, high);
		}
		if (backh)
		{
			int high = iLoadImage("Background\\hl.png");
			iShowImage(1370, 51, 500, 200, high);
		}

	}
	else if (gameState == 3)
	{
		int img5 = iLoadImage(help);
		iShowImage(0, 0, 1920, 1080, img5);

		if (backh)
		{
			int high = iLoadImage("Background\\hl.png");
			iShowImage(1370, 51, 500, 200, high);
		}
	}

	else if (gameState == 4)
	{
		int img6 = iLoadImage(credit);
		iShowImage(0, 0, 1920, 1080, img6);

		if (backh)
		{
			int high = iLoadImage("Background\\hl.png");
			iShowImage(1370, 51, 500, 200, high);
		}
	}

	else if (gameState == 5)
	{
		exit(0);
	}



	return;
}





void iMouseMove(int mx, int my)
{

}
//ipassiveMouse//
void iPassiveMouseMove(int mx, int my)
{
	if (gameState == -1)
	{
		if (mx >= 800 && mx <= 1106 && my >= 851 && my <= 961)
		{
			playh = true;
		}
		else
		{
			playh = false;
		}

		if (mx >= 800 && mx <= 1106 && my >= 701 && my <= 811)
		{
			storeh = true;
		}
		else
		{
			storeh = false;
		}

		if (mx >= 800 && mx <= 1106 && my >= 551 && my <= 661)
		{
			optionsh = true;
		}
		else
		{
			optionsh = false;
		}

		if (mx >= 800 && mx <= 1106 && my >= 401 && my <= 511)
		{
			helph = true;
		}
		else
		{
			helph = false;
		}

		if (mx >= 800 && mx <= 1106 && my >= 251 && my <= 361)
		{
			credith = true;
		}
		else
		{
			credith = false;
		}

		if (mx >= 800 && mx <= 1106 && my >= 101 && my <= 211)
		{
			exith = true;
		}
		else
		{
			exith = false;
		}
	}
	if (gameState == 1)
	{
		if (mx >= 748 && mx <= 1149 && my >= 277 && my <= 426)
		{
			backh = true;
		}
		else
		{
			backh = false;
		}
	}
	if (gameState == 2)
	{
		if (mx >= 765 && mx <= 1056 && my >= 460 && my <= 570)
		{
			onh = true;
		}
		else
		{
			onh = false;
		}
		if (mx >= 765 && mx <= 1056 && my >= 300 && my <= 410)
		{
			offh = true;
		}
		else
		{
			offh = false;
		}

		if (mx >= 1470 && mx <= 1770 && my >= 105 && my <= 205)
		{
			backh = true;
		}
		else
		{
			backh = false;
		}
	}
	if (gameState == 3)
	{
		if (mx >= 1470 && mx <= 1770 && my >= 105 && my <= 205)
		{
			backh = true;
		}
		else
		{
			backh = false;
		}

	}
	if (gameState == 4)
	{
		if (mx >= 1470 && mx <= 1770 && my >= 105 && my <= 205)
		{
			backh = true;
		}
		else
		{
			backh = false;
		}

	}
}

void iMouse(int button, int state, int mx, int my)
{
	cout << mx << " " << my << endl;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (gameState == -1)
		{
			for (int i = 0; i < 6; i++)
			{
				if (mx >= bCordinate[i].x && mx <= bCordinate[i].x + 309 && my >= bCordinate[i].y && my <= bCordinate[i].y + 112)
				{
					gameState = i;
				}
			}
		}
		if (muzandefeated)
		{
			if (mx >= 261 && mx <= 650 && my >= 114 && my <= 253)
			{
				gameState = -1;
				if (gameState == -1)
				{
					muzandefeated = false;
				}
			}
			if (mx >= 786 && mx <= 1176 && my >= 114 && my <= 253)
			{
				gameState = 0;

			}
			if (mx >= 1300 && mx <= 1700 && my >= 114 && my <= 253)
			{
				exit(0);
			}
		}
		if (tanjirodefeated)
		{
			if (mx >= 253 && mx <= 650 && my >= 215 && my <= 351)
			{
				gameState = -1;
			}
			if (mx >= 786 && mx <= 1176 && my >= 215 && my <= 351)
			{
				gameState = 0;

			}
			if (mx >= 1300 && mx <= 1700 && my >= 215 && my <= 351)
			{
				exit(0);
			}
		}
		if (gameState == 1)
		{
			if (mx >= 748 && mx <= 1150 && my >= 277 && my <= 426)
			{
				gameState = -1;
			}
		}
		if (gameState == 2)
		{
			if (mx >= 1470 && mx <= 1770 && my >= 105 && my <= 205)
			{
				gameState = -1;
			}
			if (mx >= 770 && mx <= 1055 && my >= 466 && my <= 565)
			{
				PlaySound("Music\\abcsfx.wav", NULL, SND_LOOP | SND_ASYNC);
				musicon = true;
			}
			if (mx >= 770 && mx <= 1055 && my >= 310 && my <= 410)
			{
				if (musicon){
					PlaySound(0, 0, 0);
					musicon = false;
				}
			}
		}
		if (gameState == 3)
		{
			if (mx >= 1470 && mx <= 1770 && my >= 105 && my <= 205)
			{
				gameState = -1;
			}
		}
		if (gameState == 4)
		{
			if (mx >= 1480 && mx <= 1770 && my >= 105 && my <= 205)
			{
				gameState = -1;
			}
		}

	}


	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}




void iKeyboard(unsigned char key)
{

	if (key == '\q')
	{

		wb1++;
		if (wb1 <= 5)
		{
			fight2 = true;
			tanjirowb1Index = 0;
			iResumeTimer(countTimer);
			CollisionCheck();
			if (tanjirowb1Index >= 9 && tanjiroCordinateX < 1300)
			{
				fight2 = false;
				standPosition = true;
				iPauseTimer(countTimer);
				tanjirowb1Index = 0;
			}

			if (tanjirowb1Index <= 9 && tanjiroCordinateX < 1300){

				running = false;
				fight2 = true;
				standPosition = false;
			}
		}

	}

	if (key == '\e')
	{
		fight1 = true;
		iResumeTimer(countTimer);
		tanjirobaIndex = 0;
		CollisionCheck();
		if (tanjirobaIndex <= 10){

			running = false;
			fight1 = true;
			standPosition = false;
		}
		if (tanjirobaIndex >= 10)
		{
			fight1 = false;
			standPosition = true;
			iPauseTimer(countTimer);
			tanjirobaIndex = 0;
		}

//

	}
	if (key == '\c')
	{
		fight2 = false;
		fight4 = false;
		wb11++;
		if (wb11 <= 3)
		{
			fight3 = true;
			tanjirowb11Index = 0;
			iResumeTimer(countTimer);
			CollisionCheck();


			if (tanjirowb11Index <= 8 && tanjiroCordinateX < 1300){

				running = false;
				fight3 = true;
				standPosition = false;
			}
			if (tanjirowb11Index >= 8 && tanjiroCordinateX < 1300)
			{
				fight3 = false;
				standPosition = true;
				iPauseTimer(countTimer);
				tanjirowb11Index = 0;
			}
		}




	}

	if (key == '\z')
	{
		fight3 = false;
		fight2 = false;
		hk++;


		if (hk <= 2)
		{
			fight4 = true;
			tanjirohkIndex = 0;
			iResumeTimer(countTimer);
			CollisionCheck();
			if (tanjirohkIndex <= 6 && tanjiroCordinateX < 1300){

				running = false;
				fight4 = true;
				standPosition = false;
			}

			if (tanjirohkIndex >= 6 && tanjiroCordinateX < 1300)
			{
				fight4 = false;
				standPosition = true;
				iPauseTimer(countTimer);
				tanjirohkIndex = 0;
			}

		}


	}

}


void iSpecialKeyboard(unsigned char key)
{


	if (key == GLUT_KEY_RIGHT || tanjiroCordinateX <350)
	{
		tanjiroCordinateX += 45;
		tanjiroIndex++;

		if (tanjiroIndex >= 6)
		{
			tanjiroIndex = 0;
		}
		running = true;
		brunning = false;
		frunning = true;
		fight1 = false;
		standPosition = false;

	}
	if (key == GLUT_KEY_LEFT || tanjiroCordinateX >1400)
	{
		tanjiroCordinateX -= 45;

		rtanjiroIndex++;

		if (rtanjiroIndex >= 6)
		{
			rtanjiroIndex = 0;
		}
		running = true;
		frunning = false;
		brunning = true;
		fight1 = false;
		standPosition = false;
	}

	if (key == GLUT_KEY_HOME)
	{
		gameState = -1;
	}
	if (key == GLUT_KEY_END)
	{
		exit(0);
	}

}
void changeindex()
{
	if ((tanjirobaIndex >= 0 && tanjirobaIndex <= 8) && fight1)
	{
		tanjirobaIndex++;
	}
	if ((tanjirowb1Index >= 0 && tanjirowb1Index <= 8) && (tanjiroCordinateX >= 400 && tanjiroCordinateX <= 1400) && fight2)
	{
		tanjirowb1Index++;


	}
	if ((tanjirowb11Index >= 0 && tanjirowb11Index <= 5) && (tanjiroCordinateX >= 400 && tanjiroCordinateX <= 1400) && fight3)
	{
		tanjirowb11Index++;


	}
	if ((tanjirohkIndex >= 0 && tanjirohkIndex <= 9) && (tanjiroCordinateX >= 400 && tanjiroCordinateX <= 1400) && fight4)
	{
		tanjirohkIndex++;


	}

}

int main(void)
{
	int sum = 100;
	///srand((unsigned)time(NULL));
	iInitialize(screenWidth, screenHeight, "Demon Slayer: Kimetsu No Yaiba");


	///updated see the documentations

	if (musicon == true){
		PlaySound("Music\\abcsfx.wav", NULL, SND_LOOP | SND_ASYNC);
	}

	for (int i = 5; i >= 0; i--)
	{
		bCordinate[i].x = 800;
		bCordinate[i].y = sum;
		sum += 150;
	}

	countTimer = iSetTimer(150, changeindex);
	iPauseTimer(countTimer);
	muzanAnimationtimer = iSetTimer(140, muzananimation);
	randatk = iSetTimer(150, randAttack);
	iPauseTimer(muzanAnimationtimer);
	iPauseTimer(randatk);
	iStart();
	return 0;
}