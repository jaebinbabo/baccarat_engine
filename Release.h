#include <iostream>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <string>

using namespace std;


int SUM[6]{ 0,0,0,0,0,0 };
int random[6];
int three[2]{ 0,0 };
int i = 0;
int pb = 0;
int money = 10000;
int bet = 0;

bool stand;

string picture[6];
string card[6];
string ret;
string choose;


int check()
{   
retry:

    if (SUM[i] <= 13)
    {
        picture[i] = "클로버";
    }
    else if (SUM[i] <= 26)
    {
        if (SUM[i] <= 13)
        {
            picture[i] = "클로버";
        }

        picture[i] = "스페이드";
        SUM[i] -= 13;
    }
    else if (SUM[i] <= 39)
    {
        if (SUM[i] <= 26)
        {
            if (SUM[i] <= 13)
            {
                picture[i] = "클로버";
            }

            picture[i] = "스페이드";
            SUM[i] -= 13;
        }

        picture[i] = "하트";
        SUM[i] -= 26;
    }
    else if(SUM[i] <= 52)
    {
        if (SUM[i] <= 39)
        {
            if (SUM[i] <= 26)
            {
                if (SUM[i] <= 13)
                {
                    picture[i] = "클로버";
                }

                picture[i] = "스페이드";
                SUM[i] -= 13;
            }

            picture[i] = "하트";
            SUM[i] -= 26;
        }

        picture[i] = "다이아";
        SUM[i] -= 39;
    }

    if (SUM[i] == 1)
    {
        card[i] = "1";
    }
    else if (SUM[i] == 2)
    {
        card[i] = "2";
    }
    else if (SUM[i] == 3)
    {
        card[i] = "3";
    }
    else if (SUM[i] == 4)
    {
        card[i] = "4";
    }
    else if (SUM[i] == 5)
    {
        card[i] = "5";
    }
    else if (SUM[i] == 6)
    {
        card[i] = "6";
    }
    else if (SUM[i] == 7)
    {
        card[i] = "7";
    }
    else if (SUM[i] == 8)
    {
        card[i] = "8";
    }
    else if (SUM[i] == 9)
    {
        card[i] = "9";
    }
    else if (SUM[i] == 10)
    {
        card[i] = "J";
        SUM[i] = 0;
    }
    else if (SUM[i] == 11)
    {
        card[i] = "Q";
        SUM[i] = 0;
    }
    else if (SUM[i] == 12)
    {
        card[i] = "K";
        SUM[i] = 0;
    }
    else if (SUM[i] == 13)
    {
        card[i] = "A";
        SUM[i] = 1;
    }
    else
    {
        card[i] = "error";
        goto retry;
    }

    i = 0;

    return 0;

}// 1~13까지는 클 로버,14~26까지는 스페이드, 27~39까지는 하트,40~52까지는 다이아로 지정한다.

int aaa() 
{
    cout << "Banker의 카드" << endl;
    cout << picture[5] << card[5] << endl;

    three[1] += SUM[5];

    return 0;
}