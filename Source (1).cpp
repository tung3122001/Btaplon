#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<string>
#include<time.h>
#include<cstdlib>
#include <fstream>
#include<string>
using namespace std;
char map[50][55];
int ViTri[4];
// Hàm thay đổi kích cỡ của khung cmd.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}


void gotoxy(int x,int y)
{    
	HANDLE hConsoleOutput;    
	COORD Cursor_an_Pos = {x-1,y-1};   
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}

// Hàm xóa màn hình.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
void Draw(int x, int y,int codeCol,int a)
{
	gotoxy(x,y);
	textcolor(codeCol);
	cout<<a;


}
void randPosNum(int Val[][4],int check);
//Tao Map Tao Khung Vien
int SetMap(char map[][55] )
{
	resizeConsole(1000,500);
	//Ve Khung GameView
	for(int i=0;i<17;i++)
	{

		for(int j=0;j<25;j++)
		{


			if((j==6 || j==12 || j== 18) && (i!=0 || i!= 24))
			{

				map[i][j]=' ';

			}
			if(i==0 || i== 16)
			{
				map[i][j]=' ';

			}
			if(i==4 || i==8 || i==12)
			{

				map[i][j]=' ';

			}
			if(j==0 || j== 24)
			{
				map[i][j]=' ';

			}

		}

	}
	map[0][0]=' ';
	map[16][24]=' ';
	map[0][24]=' ';
	map[16][0]=' ';

	return 0;
}
//In Map ra man hinh + set mau
int DrawMap(char map[][55])
{
	for(int i=0;i<17;i++)
	{
		for(int j=0;j<25;j++)
		{
			//textcolor(32);
			if(i==0 || i==16|| j==0 || j==24 || i==4 || i==8 || i==12 || j==6 || j==12 || j== 18)
				textcolor(112);
			else
				textcolor(51);

			cout<<map[i][j];
		}
		cout<<endl;
	}
	textcolor(11);
	gotoxy(30,4);
	cout<<"Huong Dan:";
	textcolor(7);
	gotoxy(30,5);
	cout<<"_A: Sang Trai";
	textcolor(13);
	gotoxy(30,6);
	cout<<"_D: Sang Phai";
	textcolor(14);
	gotoxy(30,7);
	cout<<"_W: Keo  Len";
	gotoxy(30,8);
	textcolor(10);
	cout<<"_S: Keo Xuong";
	gotoxy(27,10);
	textcolor(15);
	cout<<"Nhan X de thoat chuong trinh.";
	textcolor(10);
	return 0;
}
//Gia tri bien
int Val[4][4]={0};
//Thiet Lap vi tri
int SetPos(int ViTri[],int Val[][4])
{
	srand(time(0));
	ViTri[0] = rand()%(4);		// Random 2 vi tri cua so dau tien
	ViTri[1] = rand()%(4);


	do {
		ViTri[2] = rand()%(4);		//Random 2 vi tri cua so thu hai
		ViTri[3] = rand()%(4);
	}
	while(ViTri[0]==ViTri[2] || ViTri[1]==ViTri[3]);
	//textcolor(126);
	Val[ViTri[2]][ViTri[3]]=2;
	Val[ViTri[0]][ViTri[1]]=2;


	/*cout<<ViTri[0]<<"    "<<Val[ViTri[0]][ViTri[0]]<<endl;
	cout<<ViTri[1]<<"    "<<Val[ViTri[1]][ViTri[1]];*/

	return 0;
}

// In cac gia tri len khung GameView
int DrawVal(int Val[][4],char map[][55])
{

	int a=4;
	for(int i=0;i<4;i++)
	{


		if(Val[0][i]!=0){

			switch (Val[0][i])
			{
			case 2:
				{Draw(a,3,63,Val[0][i]);
				break;}
			case 4:
				{Draw(a,3,62,Val[0][i]);
				break;}
			case 8:
				{Draw(a,3,61,Val[0][i]);
				break;}
			case 16:
				{Draw(a,3,60,Val[0][i]);
				break;}
			case 32:
				{Draw(a,3,59,Val[0][i]);
				break;}
			case 64:
				{Draw(a,3,58,Val[0][i]);
				break;}
			case 128:
				{Draw(a,3,57,Val[0][i]);
				break;}
			case 256:
				{Draw(a,3,49,Val[0][i]);
				break;}
			case 512:
				{Draw(a,3,50,Val[0][i]);
				break;}
			case 1024:
				{Draw(a,3,52,Val[0][i]);
				break;}
			default:
				{Draw(a,3,48,Val[0][i]);
				break;}
			}
		}

		a+=6;

	}
	a=4;
	for(int i=0;i<4;i++)
	{
		if(Val[1][i]!=0){

			switch (Val[1][i])
			{
			case 2:
				{Draw(a,7,63,Val[1][i]);
				break;}
			case 4:
				{Draw(a,7,62,Val[1][i]);
				break;}
			case 8:
				{Draw(a,7,61,Val[1][i]);
				break;}
			case 16:
				{Draw(a,7,60,Val[1][i]);
				break;}
			case 32:
				{Draw(a,7,59,Val[1][i]);
				break;}
			case 64:
				{Draw(a,7,58,Val[1][i]);
				break;}
			case 128:
				{Draw(a,7,57,Val[1][i]);
				break;}
			case 256:
				{Draw(a,7,49,Val[1][i]);
				break;}
			case 512:
				{Draw(a,7,50,Val[1][i]);
				break;}
			case 1024:
				{Draw(a,7,52,Val[1][i]);
				break;}
			default:
				{Draw(a,7,48,Val[1][i]);
				break;}
			}
		}
		a+=6;
	}
	a=4;
	for(int i=0;i<4;i++)
	{
		if(Val[2][i]!=0){
			//Draw(a,11,52,Val[2][i]);
			switch (Val[2][i])
			{
			case 2:
				{Draw(a,11,63,Val[2][i]);
				break;}
			case 4:
				{Draw(a,11,62,Val[2][i]);
				break;}
			case 8:
				{Draw(a,11,61,Val[2][i]);
				break;}
			case 16:
				{Draw(a,11,60,Val[2][i]);
				break;}
			case 32:
				{Draw(a,11,59,Val[2][i]);
				break;}
			case 64:
				{Draw(a,11,58,Val[2][i]);
				break;}
			case 128:
				{Draw(a,11,57,Val[2][i]);
				break;}
			case 256:
				{Draw(a,11,49,Val[2][i]);
				break;}
			case 512:
				{Draw(a,11,50,Val[2][i]);
				break;}
			case 1024:
				{Draw(a,11,52,Val[2][i]);
				break;}
			default:
				{Draw(a,11,48,Val[2][i]);
				break;}
			}
		}
		a+=6;
	}

	a=4;

	for(int i=0;i<4;i++)
	{
		if(Val[3][i]!=0){
			//Draw(a,15,52,Val[3][i]);
			switch (Val[3][i])
			{
			case 2:
				{Draw(a,15,63,Val[3][i]);
				break;}
			case 4:
				{Draw(a,15,62,Val[3][i]);
				break;}
			case 8:
				{Draw(a,15,61,Val[3][i]);
				break;}
			case 16:
				{Draw(a,15,60,Val[3][i]);
				break;}
			case 32:
				{Draw(a,15,59,Val[3][i]);
				break;}
			case 64:
				{Draw(a,15,58,Val[3][i]);
				break;}
			case 128:
				{Draw(a,15,57,Val[3][i]);
				break;}
			case 256:
				{Draw(a,15,49,Val[3][i]);
				break;}
			case 512:
				{Draw(a,15,50,Val[3][i]);
				break;}
			case 1024:
				{Draw(a,15,52,Val[3][i]);
				break;}
			default:
				{Draw(a,15,48,Val[3][i]);
				break;}
			}
		}
		a+=6;
	}

	return 0;
}
int a[4][4],check=0;
void turnLeft(int Val[][4],int &diem,int a[][4],int &check)
{
	for(int hang=0;hang<4;hang++){



		for(int j=1;j<4;j++)
		{
			for(int i=j-1;i>=0;i--)		


			{
				if(Val[hang][i]==0)
				{Val[hang][i]=Val[hang][i+1];
				Val[hang][i+1]=0;}
			}
		}
	}

	//Xet 2 gia tri ke nhau ma bang nhau thi cong 2 so lai roi xoa di 1 so
	for(int h=0;h<4;h++)
	{
		for(int c=0;c<4;c++)
		{
			if(Val[h][c] == Val[h][c+1])
			{
				Val[h][c]+=Val[h][c];
				diem+=Val[h][c];
				Val[h][c+1]=0;

			}

		}

	}
	//Di chuyen lai 1 lan nua cac phan tu trong hang
	for(int hang=0;hang<4;hang++){



		for(int j=1;j<4;j++)
		{
			for(int i=j-1;i>=0;i--)		


			{
				if(Val[hang][i]==0)
				{Val[hang][i]=Val[hang][i+1];
				Val[hang][i+1]=0;

				}


			}
		}
	}
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++){
			if(a[i][j]!=Val[i][j])
			{
				check=1;
				
			}

		}

	}

}

void turnRight(int Val[][4],int &diem,int a[][4],int &check)
{

	for(int hang=0;hang<4;hang++){
		for(int j=2;j>=0;j--)
		{
			for(int i=j+1;i<=3;i++)
			{
				if(Val[hang][i]==0)
				{Val[hang][i]=Val[hang][i-1];
				Val[hang][i-1]=0;}


			}
		}
	}
	//Xet 2 gia tri ke nhau ma bang nhau thi cong 2 so lai roi xoa di 1 so

	for(int i=0;i<=3;i++)
	{
		for(int j=2;j>=0;j--)
		{
			if (Val[i][j]==Val[i][j+1])
			{
				Val[i][j+1]+=Val[i][j+1];
				Val[i][j]=0;
				diem+=Val[i][j+1]; 
			}
		}
	}

	for(int hang=0;hang<4;hang++){
		for(int j=2;j>=0;j--)
		{
			for(int i=j+1;i<=3;i++)
			{
				if(Val[hang][i]==0)
				{Val[hang][i]=Val[hang][i-1];
				Val[hang][i-1]=0;
				}


			}
		}
	}
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++){
			if(a[i][j]!=Val[i][j])
			{
				check=1;
				
			}

		}

	}

}


void goUp(int Val[][4],int &diem,int a[][4],int &check)
{
	for(int cot=0;cot<4;cot++){
		for(int i=1;i<4;i++)
		{
			for(int j=i-1;j>=0;j--)
			{
				//Thay doi cot 1
				if(Val[j][cot]==0)
				{
					Val[j][cot]=Val[j+1][cot];
					Val[j+1][cot]=0;
				}

			}
		}
	}

	//Xet 2 gia tri ke nhau ma bang nhau thi cong 2 so lai roi xoa di 1 so

	for(int j=0;j<4;j++)
	{
		for(int i=1;i<4;i++)
		{
			if(Val[i][j]==Val[i-1][j])
			{
				Val[i-1][j]+=Val[i-1][j];
				diem=diem + Val[i-1][j];
				Val[i][j]=0;

			}

		}

	}
	for(int cot=0;cot<4;cot++){
		for(int i=1;i<4;i++)
		{
			for(int j=i-1;j>=0;j--)
			{
				//Thay doi cot 1
				if(Val[j][cot]==0)
				{
					Val[j][cot]=Val[j+1][cot];
					Val[j+1][cot]=0;

				}

			}
		}
	}
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++){
			if(a[i][j]!=Val[i][j])
			{
				check=1;
				
			}

		}

	}
}

void goDown(int Val[][4],int &diem,int a[][4],int &check)
{

	for(int cot=0;cot<4;cot++){
		for(int j=2;j>=0;j--)
		{
			for(int i=j+1;i<=3;i++)
			{
				if(Val[i][cot]==0)
				{Val[i][cot]=Val[i-1][cot];
				Val[i-1][cot]=0;}


			}
		}
	}
	//Xet 2 gia tri ke nhau ma bang nhau thi cong 2 so lai roi xoa di 1 so

	for(int j=0;j<4;j++)
	{
		for(int i=3;i>=0;i--)
		{
			if(Val[i][j]==Val[i-1][j])
			{
				Val[i][j]+=Val[i][j];
				diem=diem +Val[i][j];
				Val[i-1][j]=0;

			}
		}
	}
	for(int cot=0;cot<4;cot++){
		for(int j=2;j>=0;j--)
		{
			for(int i=j+1;i<=3;i++)
			{
				if(Val[i][cot]==0)
				{Val[i][cot]=Val[i-1][cot];
				Val[i-1][cot]=0;

				}


			}
		}
	}
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++){
			if(a[i][j]!=Val[i][j])
			{
				check=1;
				
			}

		}

	}
}
int state=0;
int diem=0;
int getKey()
{


	//while(!_kbhit()){
	char c=_getch();
	if(c=='d' )
	{turnRight(Val,diem,a,check);
	state=1;}
	else if(c=='s')
	{goDown(Val,diem,a,check);
	state=1;}
	else if(c=='w')
	{goUp(Val,diem,a,check);
	state=1;}
	else if(c=='a')
	{turnLeft(Val,diem,a,check);
	state=1;}
	else if(c== 'x')
	{exit(1);
	}
	else
		state =0;

}
void randPosNum(int Val[][4],int check)
{
	
	int pos1,pos2;
	srand(time(0));
	do
	{

		pos1= rand()%(4);
		pos2= rand()%(4);
	} while (Val[pos1][pos2] !=0);
	do
	{ 
		Val[pos1][pos2]= 2 + rand()%(3);
	} while (Val[pos1][pos2] ==3);

}
//Ham kiem tra xem ket thuc game chua
int checkGame(int Val[][4])
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(Val[i][j]==0)
				return 1;	
		}

	}
	return 0;

}

int Score(int diem)
{
	int s=diem;

	return s;
}
int  sc=2;
int fileScore(int s,int &sc)
{
	fstream fileScore;
	//Mo file de luu gia tri diem so hien tai kieu nhi phan
	fileScore.open("Score.txt",ios::out | ios::binary); 
	fileScore.write(reinterpret_cast<char *>(&s),sizeof(s));
	fileScore.close();
	//Mo file de lay gia tri diem so gan vao bien sc
	return 0;
}
void bestScore(int &sc)
{
	fstream fileScore;
	fileScore.open("Score.txt",ios::in | ios:: binary);
	{fileScore.read(reinterpret_cast<char *>(&sc),sizeof(sc));
	}

	fileScore.close();
	gotoxy(40,1);
	cout<<"Best: ";
	cout<<sc;
}
void Intro()
{
	fstream GioiThieu;
	GioiThieu.open("gt.txt",ios::in);

	gotoxy(16,2);
	while(!GioiThieu.eof())
	{
		textcolor(9);
		char c;
		GioiThieu.get(c);
		cout<<c;
		Sleep(10);
	}

	GioiThieu.close();
	Sleep(100);
	gotoxy(1,5);
	textcolor(11);
	cout<<"        =======\n";
	Sleep(10);
	cout<<"     ===      ====\n";
	Sleep(10);
	cout<<"    ==       ====\n";
	Sleep(10);
	cout<<"           ====\n";
	Sleep(10);
	cout<<"         ====\n";
	Sleep(10);
	cout<<"       ====\n";
	Sleep(10);
	cout<<"     ====\n";
	Sleep(10);
	cout<<"   =====\n";
	Sleep(10);
	cout<<"  =============\n";
	Sleep(10);
	cout<<"  =============\n";
	gotoxy(20,5);
	Sleep(100);
	textcolor(12);
	cout<<"      =====\n";
	Sleep(10);
	gotoxy(20,6);
	cout<<"   ===     ===\n";
	Sleep(10);
	gotoxy(20,7);
	cout<<"  ===       ===\n";
	Sleep(10);
	gotoxy(20,8);
	cout<<" ===         ===\n";
	Sleep(10);
	gotoxy(20,9);
	cout<<" ===         ===\n";
	Sleep(10);
	gotoxy(20,10);
	cout<<" ===         ===\n";
	Sleep(10);
	gotoxy(20,11);
	cout<<" ===         ===\n";
	Sleep(10);
	gotoxy(20,12);
	cout<<"  ===       ===\n";
	Sleep(10);
	gotoxy(20,13);
	cout<<"   ===     ===\n";
	Sleep(10);
	gotoxy(20,14);
	cout<<"      =====\n";
	Sleep(10);
	gotoxy(36,5);
	Sleep(100);
	textcolor(14);
	cout<<"          ===\n";
	Sleep(10);
	gotoxy(36,6);
	cout<<"        ===\n";
	Sleep(10);
	gotoxy(36,7);
	cout<<"      ===     \n";
	Sleep(10);
	gotoxy(36,8);
	cout<<"    ===       ===\n";
	Sleep(10);
	gotoxy(36,9);
	cout<<"    ==============\n";
	Sleep(10);
	gotoxy(36,10);
	cout<<"    ==============\n";
	Sleep(10);
	gotoxy(36,11);
	cout<<"              ===\n";
	Sleep(10);
	gotoxy(36,12);
	cout<<"              ===\n";
	Sleep(10);
	gotoxy(36,13);
	cout<<"              ===\n";
	Sleep(10);
	gotoxy(36,14);
	cout<<"              ===\n";
	Sleep(10);
	gotoxy(54,5);
	Sleep(100);
	textcolor(10);
	cout<<"        ====\n";
	Sleep(10);
	gotoxy(55,6);
	cout<<"    ===    ===\n";
	Sleep(10);
	gotoxy(55,7);
	cout<<"   ===      ===\n";
	Sleep(10);
	gotoxy(55,8);
	cout<<"    ===    ===\n";
	Sleep(10);
	gotoxy(55,9);
	cout<<"       ====\n";
	Sleep(10);
	gotoxy(55,10);
	cout<<"    ===    ===\n";
	Sleep(10);
	gotoxy(55,11);
	cout<<"   ===      ===\n";
	Sleep(10);
	gotoxy(55,12);
	cout<<"   ===      ===\n";
	Sleep(10);
	gotoxy(55,13);
	cout<<"    ===    ===\n";
	Sleep(10);
	gotoxy(55,14);
	cout<<"       ====\n";
	Sleep(10);
	gotoxy(60,16);
	textcolor(6);
	cout<<"Made by nhom lop pho\n";
	textcolor(13);
	cout<<"Nhan phim bat ky de bat dau choi...";
}

int main()
{
	//resizeConsole(800,800);

	Intro();
	getch();
	system("cls");
	resizeConsole(400,400);
	SetMap(map);
	DrawMap(map);
	SetPos(ViTri,Val);
	bestScore(sc);
	DrawVal(Val,map);
	
	while(true)
	{		


		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				a[i][j]=Val[i][j];
			}

		}
		check=0;
		gotoxy(28,1);
		textcolor(11);
		cout<<"Score :";
		Draw(35,1,12,diem);

		getKey();

		if(state==1)
		{gotoxy(1,1);
		DrawMap(map);

		}
		if(checkGame(Val)==0)
		{
			gotoxy(30,13);
			textcolor(12);
			cout<<"Game Over! ";
			cout<<"Diem Cua Ban :"<<Score(diem);
			if(Score(diem)>sc)
				fileScore(Score(diem),sc);		
			break;
		}
		else
		{
			if(check==1)
				randPosNum(Val,check);
			
		DrawVal(Val,map);
		
		}
		/*for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				a[i][j]=Val[i][j];
			}

		}*/
		
		
	}
	getch();
	return 0;
}
