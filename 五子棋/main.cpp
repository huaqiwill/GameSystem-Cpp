//�ز�
//1.���̻�����
//2.����
//3.�ж���Ӯ

//  C++ /(���ݽṹ) //����  - > ����� �������ģʽ����ܣ�
//       
// 
#include<graphics.h>//ͼ��ͷ�ļ�
#include<mmsystem.h>//�������ֵ�ͷ�ļ�
#pragma comment(lib,"winmm.lib")//�������ֵĿ��ļ�

int board[18][18] = { 0 };//��������
int flag = 0;

//��������
int judge(int a, int b);
 int i, int j, int num;
void InitGame()//��ʼ����Ϸ����
{
	//��ͼ
	initgraph(700, 600);//��ͼ�������
	//setbkcolor(GREEN);//��ɫ
	//cleardevice();//ˢ��
	loadimage(NULL, "1.jpg", 700, 600, true);
	//���ű�������   ��ý����ƽӿ�
	//�ȴ�
	/*mciSendString("open 1.mp3", 0, 0, 0);*/
	//�ڲ���
	/*mciSendString("play 1.mp3", 0, 0, 0);*/
	//���� ��������
	
	setlinecolor(BLACK);//�������óɺ�ɫ
	//line(0, 0, 700, 500);//����
	for (int i = 70; i <= 500; i += 25)
	{
		line(5, i, 430, i);//�����ŵ���
		line(i - 65, 70, i - 65, 495);//����ֱ����
	}
	line(431, 70, 431, 495);//�Ӵ�
	line(5, 69, 430, 69);
	//��������Ϣ
	outtextxy(480, 80, "���1:��");
	outtextxy(480, 180, "���2:��");
}
//����
void playChess()
{
	int a, b;
	MOUSEMSG m;
	HWND hwnd;//�������
	hwnd = GetHWnd();
	//�������������
	while (1)
	{
		m = GetMouseMsg();//��ȡ�����Ϣ
		if (m.uMsg == WM_LBUTTONDOWN)//����������
		{
			a = (m.x+13) / 25;
			b = (m.y - 70+13) / 25;
			if (a > 17 || a < 0 || b>17 || b < 0)
			{
				MessageBox(hwnd, "�����Խ��", "��ʾ", MB_OK);
				continue;
			}
			if (board[a][b] != 0)
			{
				MessageBox(hwnd, "�����Ѿ���������", "��ʾ", MB_OK);
				continue;
			}
			if (flag % 2 == 0)//��ż��
			{
				//��ʾΪ����
				setfillcolor(BLACK);
				board[a][b] = 1;
			}
			if (flag % 2 != 0)//Ϊ����
			{
				setfillcolor(GREEN);
				board[a][b] = 2;		
			}
			//����
			solidcircle(a*25+5, b*25+70, 10);//��һ��Բ
			flag++;
			//�ж���Ӯ
			if (judge(a, b))
			{
				if (flag % 2 == 1)
				{
					MessageBox(hwnd, "���1ʤ��", "��ʾ", MB_OK);
					return;
				}
				else
				{
					MessageBox(hwnd, "���2ʤ��", "��ʾ", MB_OK);
					return;
				}
			}

		}
	}
}

int judge(int a, int b)
{

	//����
	for (i = a - 4, num = 1; i <= a + 4; i++)
	{
		if (i > 17 || i < 0) continue;//�ų�Խ��
		if (board[a][b] == board[i][b]&&a!=i)//һ����ͬ�ͼ�1
			num++;
		else
		{
			if (a != i)//�ų�ѭ�����Լ��ıȽ�
			num = 1;
		}
		if (num == 5)
			return 1;
	}
	//����
	for (i = b - 4, num = 1; i <= b + 4; i++)
	{
		if (i > 17 || i < 0) continue;//�ų�Խ��
		if (board[a][b] == board[a][i] && b != i)//һ����ͬ�ͼ�1
			num++;
		else
		{
			if (b != i)//�ų�ѭ�����Լ��ıȽ�
				num = 1;
		}
		if (num == 5)
			return 1;
	}
	//����
	for (i = a - 4,j=b+4, num = 1; i <= a + 4&&j>=b-4; i++,j--)
	{
		if (i > 17 || i < 0||j>17||j<0) continue;//�ų�Խ��
		if (board[a][b] == board[i][j] && a != i&&b!=j)//һ����ͬ�ͼ�1
			num++;
		else
		{
			if (a != i&&b != j)//�ų�ѭ�����Լ��ıȽ�
				num = 1;
		}
		if (num == 5)
			return 1;
	}
	return 0;
}
//�ж���Ӯ
int main()//������  ���ҽ���һ��
{
	InitGame();//��ʼ��ͼ��
	playChess();//��������
	while (1);
	return 0;
}