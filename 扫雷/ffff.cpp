//#include "include\hge.h"
//#include "include\hgefont.h"
//#include <iostream>
//
//HGE* hge = 0;//创建HGE指针
//
//HEFFECT snd;//定义一个Effect(音效)对象
//
//bool RenderFunc()//绘制函数，程序开始后HGE将不停调用它
//{
//	return false;//总是返回false
//}
//bool FrameFunc()//逻辑函数，程序开始后HGE将不停调用它，一些逻辑判断或者处理可以写在这里。
//{
//	if (hge->Input_GetKeyState(HGEK_A))//检测是否按下了A键
//		hge->Effect_Play(snd);//如果按下了A键，则播放音乐snd
//	return false;//程序正常时总是返回false，返回true将从System_Start往下执行
//}
//
//int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)//WinMain函数，程序的入口。
//{
//	hge = hgeCreate(HGE_VERSION);//使用hgeCreate函数创建HGE接口，参数必须传递正确的HGE_VERSION,它是在hge.h中定义的
//	hge->System_SetState(HGE_SCREENWIDTH, 800);//将屏幕宽度设置为800
//	hge->System_SetState(HGE_SCREENHEIGHT, 600);//将屏幕高度设置为600
//	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);//设置逻辑函数为FrameFunc函数
//	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);//设置绘制函数为RenderFunc函数
//	hge->System_SetState(HGE_TITLE, "播放声音");//设置窗口标题为“播放声音”
//	hge->System_SetState(HGE_WINDOWED, true);//设置使用窗口模式
//	hge->System_SetState(HGE_USESOUND, true);//设置使用声音
//	if (hge->System_Initiate())//用hge类的System_Initiate()方法，检测初始化是否有错误出现。
//	{
//		snd = hge->Effect_Load("music.mp3");//根据路径载入声音
//		if (snd)//检测声音是否已经载入成功
//			hge->System_Start();//如果没有问题，则使用System_Start方法，开始程序。
//	}
//	hge->Effect_Free(snd);//释放声音资源
//	hge->System_Shutdown();//程序停止
//	hge->Release();//释放HGE所占用的内存。
//}