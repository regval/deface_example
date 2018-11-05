#include <windows.h>
#include <stdio.h>


#define s "Hello, World!"

#define _EVENT_ 10

#define _PER_ 10

#define _N_ 5


HWND h=0;


main(int argc, char **argv)

//int WinMain(HINSTANCE, HINSTANCE, LPSTR, int)

{

	int a; HDC dc; RECT rect, fill_rect; HBRUSH br; HFONT font; char buf[100];

	h=FindWindow(0, "Калькулятор");

	//h=FindWindow(0, "Обработчик команд Windows NT");

	//h=FindWindow(0, "Командная строка");

	//if (argc > 1) h=FindWindow(0, argv[1]);
	//if (h==0) return -1;

	dc = GetDC(h); if (dc)

	{

		br=CreateSolidBrush(RGB(69,0,0));

		rect.left=1; rect.right=1000; rect.top=1; rect.bottom=1000;

		GetClientRect(h, &rect);

		font=CreateFont(rect.bottom/2,rect.right/strlen(s),0,0,100,0,0,0,

			ANSI_CHARSET, OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,

			DEFAULT_QUALITY,FF_MODERN, "Comic Sans MS");

		fill_rect.top=3*rect.bottom/4; fill_rect.bottom=rect.bottom-10;

		fill_rect.left=10; fill_rect.right=10; ReleaseDC(h, dc);

		for (a=0; a < 255; a++)

		{

			printf("\r%03d",100*a/255);

			if (dc = GetDC(h))

			{

				SelectObject(dc, font);SetBkMode(dc, TRANSPARENT);

				SetTextColor(dc, rand()); //RGB(255-a,0,0));

				TextOut(dc, 0, rect.bottom/8, s ,strlen(s) );

				ReleaseDC(h, dc);

			}

			SetWindowText(h, ltoa(100*a/255,buf,10)); Sleep(69);

		}

		SendMessage(h, WM_SYSCOMMAND, SC_MINIMIZE, 0); Sleep(69);

		SendMessage(h, WM_SYSCOMMAND, SC_RESTORE, 0);

		SetWindowText(h, "Hello, Sailor!");

		for (a=0; a < 10; a++) {ShowWindow(h, a & 1); Sleep(69);}

	}
	else 
		printf("-ERR\n");

}
