//#include "include\hge.h"
//#include "include\hgefont.h"
//#include <iostream>
//
//HGE* hge = 0;//����HGEָ��
//
//HEFFECT snd;//����һ��Effect(��Ч)����
//
//bool RenderFunc()//���ƺ���������ʼ��HGE����ͣ������
//{
//	return false;//���Ƿ���false
//}
//bool FrameFunc()//�߼�����������ʼ��HGE����ͣ��������һЩ�߼��жϻ��ߴ������д�����
//{
//	if (hge->Input_GetKeyState(HGEK_A))//����Ƿ�����A��
//		hge->Effect_Play(snd);//���������A�����򲥷�����snd
//	return false;//��������ʱ���Ƿ���false������true����System_Start����ִ��
//}
//
//int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)//WinMain�������������ڡ�
//{
//	hge = hgeCreate(HGE_VERSION);//ʹ��hgeCreate��������HGE�ӿڣ��������봫����ȷ��HGE_VERSION,������hge.h�ж����
//	hge->System_SetState(HGE_SCREENWIDTH, 800);//����Ļ�������Ϊ800
//	hge->System_SetState(HGE_SCREENHEIGHT, 600);//����Ļ�߶�����Ϊ600
//	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);//�����߼�����ΪFrameFunc����
//	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);//���û��ƺ���ΪRenderFunc����
//	hge->System_SetState(HGE_TITLE, "��������");//���ô��ڱ���Ϊ������������
//	hge->System_SetState(HGE_WINDOWED, true);//����ʹ�ô���ģʽ
//	hge->System_SetState(HGE_USESOUND, true);//����ʹ������
//	if (hge->System_Initiate())//��hge���System_Initiate()����������ʼ���Ƿ��д�����֡�
//	{
//		snd = hge->Effect_Load("music.mp3");//����·����������
//		if (snd)//��������Ƿ��Ѿ�����ɹ�
//			hge->System_Start();//���û�����⣬��ʹ��System_Start��������ʼ����
//	}
//	hge->Effect_Free(snd);//�ͷ�������Դ
//	hge->System_Shutdown();//����ֹͣ
//	hge->Release();//�ͷ�HGE��ռ�õ��ڴ档
//}