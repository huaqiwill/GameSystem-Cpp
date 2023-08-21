//素材
//1.棋盘画出来
//2.下棋
//3.判断输赢

//  C++ /(数据结构) //链表  - > 对象池 －＞设计模式（框架）
//       
// 
#include<graphics.h>//图形头文件
#include<mmsystem.h>//播放音乐的头文件
#pragma comment(lib,"winmm.lib")//播放音乐的库文件

int board[18][18] = { 0 };//棋盘数组
int flag = 0;

//函数声明
int judge(int a, int b);
 int i, int j, int num;
void InitGame()//初始化游戏界面
{
	//绘图
	initgraph(700, 600);//把图界面输出
	//setbkcolor(GREEN);//绿色
	//cleardevice();//刷新
	loadimage(NULL, "1.jpg", 700, 600, true);
	//播放背景音乐   多媒体控制接口
	//先打开
	/*mciSendString("open 1.mp3", 0, 0, 0);*/
	//在播放
	/*mciSendString("play 1.mp3", 0, 0, 0);*/
	//画线 绘制棋盘
	
	setlinecolor(BLACK);//把线设置成黑色
	//line(0, 0, 700, 500);//画线
	for (int i = 70; i <= 500; i += 25)
	{
		line(5, i, 430, i);//画横着的线
		line(i - 65, 70, i - 65, 495);//画垂直的线
	}
	line(431, 70, 431, 495);//加粗
	line(5, 69, 430, 69);
	//输出玩家信息
	outtextxy(480, 80, "玩家1:黑");
	outtextxy(480, 180, "玩家2:白");
}
//下棋
void playChess()
{
	int a, b;
	MOUSEMSG m;
	HWND hwnd;//输出窗口
	hwnd = GetHWnd();
	//鼠标左键点击下棋
	while (1)
	{
		m = GetMouseMsg();//获取鼠标消息
		if (m.uMsg == WM_LBUTTONDOWN)//如果左键按下
		{
			a = (m.x+13) / 25;
			b = (m.y - 70+13) / 25;
			if (a > 17 || a < 0 || b>17 || b < 0)
			{
				MessageBox(hwnd, "鼠标点击越界", "提示", MB_OK);
				continue;
			}
			if (board[a][b] != 0)
			{
				MessageBox(hwnd, "这里已经有棋子了", "提示", MB_OK);
				continue;
			}
			if (flag % 2 == 0)//是偶数
			{
				//显示为黑棋
				setfillcolor(BLACK);
				board[a][b] = 1;
			}
			if (flag % 2 != 0)//为奇数
			{
				setfillcolor(GREEN);
				board[a][b] = 2;		
			}
			//落棋
			solidcircle(a*25+5, b*25+70, 10);//画一个圆
			flag++;
			//判断输赢
			if (judge(a, b))
			{
				if (flag % 2 == 1)
				{
					MessageBox(hwnd, "玩家1胜利", "提示", MB_OK);
					return;
				}
				else
				{
					MessageBox(hwnd, "玩家2胜利", "提示", MB_OK);
					return;
				}
			}

		}
	}
}

int judge(int a, int b)
{

	//左右
	for (i = a - 4, num = 1; i <= a + 4; i++)
	{
		if (i > 17 || i < 0) continue;//排除越界
		if (board[a][b] == board[i][b]&&a!=i)//一旦相同就加1
			num++;
		else
		{
			if (a != i)//排除循环中自己的比较
			num = 1;
		}
		if (num == 5)
			return 1;
	}
	//上下
	for (i = b - 4, num = 1; i <= b + 4; i++)
	{
		if (i > 17 || i < 0) continue;//排除越界
		if (board[a][b] == board[a][i] && b != i)//一旦相同就加1
			num++;
		else
		{
			if (b != i)//排除循环中自己的比较
				num = 1;
		}
		if (num == 5)
			return 1;
	}
	//右上
	for (i = a - 4,j=b+4, num = 1; i <= a + 4&&j>=b-4; i++,j--)
	{
		if (i > 17 || i < 0||j>17||j<0) continue;//排除越界
		if (board[a][b] == board[i][j] && a != i&&b!=j)//一旦相同就加1
			num++;
		else
		{
			if (a != i&&b != j)//排除循环中自己的比较
				num = 1;
		}
		if (num == 5)
			return 1;
	}
	return 0;
}
//判断输赢
int main()//主函数  有且仅有一个
{
	InitGame();//初始画图形
	playChess();//调用下棋
	while (1);
	return 0;
}