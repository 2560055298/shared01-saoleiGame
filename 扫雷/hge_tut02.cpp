//添加数字前
#include "include\hge.h"
#include "include\hgefont.h"
#include <iostream>

HEFFECT backMusic;
HCHANNEL backMusicChannel;
int volume;//音量
using namespace std;
#define ROW 30
#define COL 30
HEFFECT snd;


//定义一个hge引擎指针(全局)
HGE* hge = 0;

int countNum = 0;		//用来：交替控制：递归方向 
int control = 0;		//用来：控制结束


struct Block
{
	//周围雷的数量
	int num;
	//方块是否打开
	bool bOpen;
};


//---------------------后续添加----------------------------

//定义一个(笑脸)纹理句柄
HTEXTURE TexSmilingFace;
//定义一个(笑脸)精灵的指针
hgeSprite* SprSmilingFace;

//---------------------后续添加----------------------------


//---------------------后续添加----------------------------

//定义一个(笑脸)纹理句柄
HTEXTURE TexTime;
//定义一个(笑脸)精灵的指针
hgeSprite* SprTime;

//定义一个(笑脸)纹理句柄
HTEXTURE TexTime2;
//定义一个(笑脸)精灵的指针
hgeSprite* SprTime2;

//---------------------后续添加----------------------------



//---------------------后续添加----------------------------

//定义一个(笑脸)纹理句柄
HTEXTURE TexFail;
//定义一个(笑脸)精灵的指针
hgeSprite* SprTexFail;

//---------------------后续添加----------------------------

//定义一个纹理句柄
HTEXTURE Tex;
//定义一个精灵的指针
hgeSprite* Spr;



//定义一个方块的二维数组
Block MyBlock[ROW][COL];

//给数组每一个元素初始化,形参表示雷的总数量
void BlockInit(int num)
{
	int nums = 0;
	int count = 0;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			MyBlock[i][j].bOpen = false;
			//if (count <= num)
			//{
			//	MyBlock[i][j].num = 9;//9表示当前元素为雷
			//	++count;
			//}
			//else
			//{
			//	
			//	MyBlock[i][j].num = nums++;
			//	if (nums == 9) {
			//		nums = 0;
			//	}
			//}

			//	MyBlock[i][j].num = nums++;
			//	if (nums == 9) {
			//		nums = 0;

			nums++;

			if (nums < 10) {
				if (nums == 9) {
					if (count == 1) {
						MyBlock[i][j].num = nums;
						count = 0;
					}
					else {
						count++;
					}
				}
				else {
					MyBlock[i][j].num = nums;
				}
			}
			else {
				nums = 0;
			}
			

		}
	}
}
//从文件中加载资源，并创建一个精灵
void LoadRes()
{
	//1.从文件中加载纹理图片，并用纹理句柄保存
	Tex = hge->Texture_Load("res/bmp_mine.png");
	//2.通过纹理句柄创建一个精灵
	Spr = new hgeSprite(Tex, 0, 0, 16, 16);
}

//---------------------后续添加（图加载）----------------------------

//从文件中加载资源，并创建一个(笑脸)精灵
void LoadResSmilingFace()
{	//res/face.png

	//1.从文件中加载纹理图片，并用纹理句柄保存
	TexSmilingFace = hge->Texture_Load("res/dataiyang.png");
	//2.通过纹理句柄创建一个精灵
	SprSmilingFace = new hgeSprite(TexSmilingFace, 0, 0, 32, 32);
}

//---------------------后续添加----------------------------

//从文件中加载资源，并创建一个(时间)精灵
void LoadResTime()
{	//res/face.png

	//1.从文件中加载纹理图片，并用纹理句柄保存
	TexTime = hge->Texture_Load("res/time.png");
	//2.通过纹理句柄创建一个精灵
	SprTime = new hgeSprite(TexTime, 0, 0, 32, 32);
}

void LoadResTime2()
{	//res/face.png

	//1.从文件中加载纹理图片，并用纹理句柄保存
	TexTime2 = hge->Texture_Load("res/time.png");
	//2.通过纹理句柄创建一个精灵
	SprTime2 = new hgeSprite(TexTime, 0, 0, 32, 32);
}

//---------------------后续添加（图加载）----------------------------

//从文件中加载资源，并创建一个(失败)精灵
void LoadResFail()
{

	//1.从文件中加载纹理图片，并用纹理句柄保存
	TexFail = hge->Texture_Load("res/fail.jpg");
	//2.通过纹理句柄创建一个精灵
	SprTexFail = new hgeSprite(TexFail, 0, 0, 100, 100);
}

//---------------------后续添加----------------------------



//随机布雷
void SetMine()
{
	//遍历整个二维数组，随机行列下标，让其对应的元素和当前的元素进行交换
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			//随机行列下标
			int row = hge->Random_Int(0, ROW - 1);
			int col = hge->Random_Int(0, COL - 1);

			//交换两个元素的值
			int Temp = MyBlock[i][j].num;
			MyBlock[i][j].num = MyBlock[row][col].num;
			MyBlock[row][col].num = Temp;
		}
	}
}


//渲染所有的方块
void BlockRender()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{	
			if (i >= 2) {
				if (MyBlock[i][j].bOpen)
				{
					switch (MyBlock[i][j].num)
					{
					case 0:
						Spr->SetTextureRect(16 * 0, 0, 16, 16);
						Spr->Render(j * 16, i * 16);
						break;
					case 1:
						Spr->SetTextureRect(16 * 1, 0, 16, 16);
						Spr->Render(j * 16, i * 16);
						break;
					case 2:
						Spr->SetTextureRect(16 * 2, 0, 16, 16);
						Spr->Render(j * 16, i * 16);
						break;
					case 3:
						Spr->SetTextureRect(16 * 3, 0, 16, 16);
						Spr->Render(j * 16, i * 16);
						break;
					case 4:
						Spr->SetTextureRect(16 * 4, 0, 16, 16);
						Spr->Render(j * 16, i * 16);
						break;
					case 5:
						Spr->SetTextureRect(16 * 5, 0, 16, 16);
						Spr->Render(j * 16, i * 16);
						break;
					case 6:
						Spr->SetTextureRect(16 * 6, 0, 16, 16);
						Spr->Render(j * 16, i * 16);
						break;
					case 7:
						Spr->SetTextureRect(16 * 7, 0, 16, 16);
						Spr->Render(j * 16, i * 16);
						break;
					case 8:
						//取景框的位置和大小
						Spr->SetTextureRect(MyBlock[i][j].num * 16, 0, 16, 16);
						break;
					case 9:
						Spr->SetTextureRect(16 * 13, 0, 16, 16);
						break;
					}
				}
				else
					Spr->SetTextureRect(16 * 9, 0, 16, 16);

				Spr->Render(j * 16, i * 16);
			}
		}
	}
	SprSmilingFace->SetTextureRect(0, 0, 32, 32);		//设置供精灵使用的纹理区域。
	SprSmilingFace->Render(225, 0);

	SprTime->SetTextureRect(0, 0, 55, 30);		//设置供精灵使用的纹理区域。
	SprTime->Render(5, 0);

	SprTime2->SetTextureRect(0, 0, 55, 30);		//设置供精灵使用的纹理区域。
	SprTime2->Render(417, 0);


	if (control == 1) {
		SprTexFail->SetTextureRect(0, 0, 300, 100);		//设置供精灵使用的纹理区域。
		SprTexFail->Render(100, 160);
	}



}


int GetMineNum(int row, int col)
{
	int nums = 0;
	int count = 0;
	for (int i = row - 1; i <= row + 1; i++)
	{
		for (int j = col; j <= col + 1; j++)
		{
			if (9 == MyBlock[i][j].num)
			{
				++count;
			}
		}
	}
	return count;
}
void CountMine()
{

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (MyBlock[i][j].num != 9)
			{
				MyBlock[i][j].num = GetMineNum(i, j);
			}

		}
	}
}

//递归：开方块
void FindMine(int row, int col)
{

	if (row >= 0 && row < ROW && col >= 0 && col < ROW)//防止数组越界
	{
		if (!MyBlock[row][col].bOpen)//方块是否打开
		{
			if (9 != MyBlock[row][col].num)
				MyBlock[row][col].bOpen = true;

			if (0 == MyBlock[row][col].num)//表示方块周围没有雷
			{
				//递归调用周围8个方块

				switch (countNum % 4) {
				case 0:


					FindMine(row, col + 1);			//0号
					FindMine(row - 1, col);			//0号

					break;


				case 1:
					FindMine(row - 1, col - 1);		//1号	
					FindMine(row + 1, col);			//1号

					break;

				case 2:
					FindMine(row - 1, col + 1);		//2号
					FindMine(row, col - 1);			//2号

					break;

				case 3:
					FindMine(row + 1, col - 1);		//3号
					FindMine(row + 1, col + 1);		//3号
					break;
				}


			}
		}



	}
}


//判断鼠标点击的是哪一个方块， 若周围方块也无雷， 则打开
void ClickBlock()
{
	//判断鼠标左键是否按下
	if (hge->Input_KeyDown(HGEK_LBUTTON))
	{
		float mouse_x, mouse_y;
		//获取鼠标的坐标
		hge->Input_GetMousePos(&mouse_x, &mouse_y);
		int row = (int)mouse_y / 16;
		int col = (int)mouse_x / 16;
		if (row < ROW && col < COL)//防止数组越界
		{
			if (MyBlock[row][col].num == 9) {
				control = 1;
			}

			countNum++;
			if(row > 2){
				FindMine(row, col);
			}
		}

	}
}




//初始化
void InitFunc()
{
	control = 0;
	countNum = 0;
	BlockInit(10);
	SetMine();
	LoadRes();
	LoadResSmilingFace();
	LoadResFail();
	LoadResTime();
	LoadResTime2();
	CountMine();
}

//---------------------后续添加（鼠标监听）----------------------------


//判断：是否点到（笑脸了） --->>>此处：老师是用了枚举， 我没有用， 我直接算出来（太阳位置），直接写死
void ClickBlockFace()	 //--->>>      算出（人工算出太阳的：坐标），if直接等于，然后调用一次（初始化）
{
	//判断鼠标左键是否按下
	if (hge->Input_KeyDown(HGEK_LBUTTON))
	{
		float mouse_facex, mouse_facey;
		//获取鼠标的坐标
		hge->Input_GetMousePos(&mouse_facex, &mouse_facey);
		if (mouse_facex >= 16 * 14 && mouse_facex < 16 * 16 && mouse_facey >= 0 && mouse_facey < 18) {
			InitFunc();
		}


	}
}
//---------------------后续添加----------------------------



//遍历出所有雷，并结束游戏，结束游戏
void controlGame() {


	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			MyBlock[i][j].bOpen = true;
		}
	}

	BlockRender();
}


//帧函数:如果函数返回值为true,表示程序结束
bool FrameFunc()
{
	if ((hge->Input_GetKeyState(HGEK_ADD) || hge->Input_GetKeyState(HGEK_EQUALS)) && volume < 100)

	{
		volume++;

		hge->Channel_SetVolume(backMusicChannel, volume);

	}

	if ((hge->Input_GetKeyState(HGEK_SUBTRACT) || hge->Input_GetKeyState(HGEK_MINUS)) && volume > 0)

	{
		volume--;

		hge->Channel_SetVolume(backMusicChannel, volume);

	}


	if (control == 1) {
		controlGame();
	}

	//逻辑处理代码:
	ClickBlock();

	ClickBlockFace();

	if (hge->Input_GetKeyState(HGEK_A))//检测是否按下了A键
		hge->Effect_Play(snd);//如果按下了A键，则播放音乐snd
	return false;//程序正常时总是返回false，返回true将从System_Start往下执行


	// Continue execution
	return false;
}

//渲染函数
bool RenderFunc()
{
	//开始场景的绘制
	hge->Gfx_BeginScene();
	// 清屏(颜色值:ARGB)
	hge->Gfx_Clear(0xFFc0c0c0);

	//3.实际绘制代码:
	BlockRender();



	//结束场景的绘制并翻转
	hge->Gfx_EndScene();

	// RenderFunc should always return false
	return false;
}


//主函数
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// 获取HGE引擎的指针
	hge = hgeCreate(HGE_VERSION);

	//设置帧函数(逻辑函数)
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	//设置渲染函数(绘制图形)
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	//设置标题
	hge->System_SetState(HGE_TITLE, "MineSweeper");

	// 设置显示的模式
	hge->System_SetState(HGE_WINDOWED, true);//是否为窗口模式
	hge->System_SetState(HGE_SCREENWIDTH, 480);//设置窗口的宽
	hge->System_SetState(HGE_SCREENHEIGHT, 480);//设置窗口的高
	hge->System_SetState(HGE_HIDEMOUSE, false);//是否隐藏鼠标
	hge->System_SetState(HGE_FPS, 100);//设置FPS



	//系统的初始化:
	if (hge->System_Initiate())
	{
		//自己的初始化
		InitFunc();

		snd = hge->Effect_Load("music.mp3");//根据路径载入声音
		if (snd)//检测声音是否已经载入成功
			hge->System_Start();//如果没有问题，则使用System_Start方法，开始程序。
	

		//启动系统
		//hge->System_Start();

	}
	else MessageBox(NULL, hge->System_GetErrorMessage(), "Error", MB_OK | MB_ICONERROR | MB_SYSTEMMODAL);


	backMusic = hge->Effect_Load("‪‪E:\1.mp3");
	backMusicChannel = hge->Effect_PlayEx(backMusic, volume, 0, 90.0f, true);
	hge->Channel_SetVolume(backMusicChannel, volume);

	//关闭系统，并释放hge指针
	hge->System_Shutdown();
	hge->Release();
	return 0;
}
