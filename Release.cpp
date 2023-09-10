#include "Release.h"

int main()
{
    cout << "기본금은 10000입니다. 신중히 선택해 주십시오." << endl;
    cout << " " << endl;

    Sleep(1000);
    system("cls");

retry:

ret:
    system("cls");

    cout << "현재금액은 " << money << "입니다. 신중히 선택해 주십시오." << endl;
    cin >> choose;

    if (choose != "player")
    {
        if (choose != "banker")
        {
            if (choose != "tie")
            {
                if (choose != "pair")
                {
                    cout << "player, banker, tie, pair중 정확하게 기입 하세요.";
                    Sleep(1000);
                    system("cls");
                    goto ret;
                }
            }
        }
    }

    cout << "베팅할 금액을 결정하세요." << endl;
    cin >> bet;

    money -= bet;

    srand((unsigned int)time(NULL));


    for (int a = 0; a < 6; a++)
    {
        random[a] = rand() % 52 + 1;

        SUM[a] = 0;
        SUM[a] += random[a];

        for (int j = 0; j < a; j++)
        {
            if (random[a] == random[j])
            {
                a--;
                break;
            }
        }
    }
    three[0] = 0;
    three[1] = 0;

    cout << "Player의 카드" << endl;
    i += 0;
    check();
    cout << picture[0] << card[0] << endl;

    i += 1;
    check();
    cout << picture[1] << card[1] << endl;

    cout << " " << endl;


    cout << "Banker의 카드" << endl;
    i += 2;
    check();
    cout << picture[2] << card[2] << endl;

    i += 3;
    check();
    cout << picture[3] << card[3] << endl;

    cout << " " << endl;



    Sleep(3000);

    three[0] += SUM[0] + SUM[1];
    three[1] += SUM[2] + SUM[3];
    

    for (int b = 0; b < 2; b++)
    {
        if (three[b] >= 30)
        {
            three[b] -= 30;
        }
        else if (three[b] >= 20)
        {
            three[b] -= 20;
        }
        else if (three[b] >= 10)
        {
            three[b] -= 10;
        }
    }

    if (card[0] == card[1])
    {
        pb += 1;
        goto end;
    }
    else
    {
        pb += 0;
    }

    if (card[2] == card[3])
    {
        pb += 1;
        goto end;
        
    }
    else
    {
        pb += 0;
    }

    if (three[0] == 8)
    {
        goto end;
    }
    else if (three[0] == 9)
    {
        goto end;
    }
    else if (three[1] == 8)
    {
        goto end;
    }
    else if (three[1] == 9)
    {
        goto end;
    }

    if (three[0] < 6)
    {
        i += 4;
        check();

        cout << "Player의 3번째 카드" << endl;
        cout << picture[4] << card[4] << endl;

        three[0] += SUM[4];
    }

    i += 5;
    check();

    if (three[1] == 0)
    {
        aaa();
    }
    else if (three[1] == 1)
    {
        aaa();
    }
    else if (three[1] == 2)
    {
        aaa();
    }
    else if (three[1] == 3)
    {
        if (three[0] != 8)
        {
            aaa();
        }
    }
    else if (three[1] == 4)
    {
        if (three[0] == 0)
        {
            goto end;
        }
        else if (three[0] == 1)
        {
            goto end;
        }
        else if (three[0] == 8)
        {
            goto end;
        }
        else if (three[0] == 9)
        {
            goto end;
        }
        else
        {
            aaa();
        }
    }
    else if (three[1] == 5)
    {
        if (three[0] == 0)
        {
            goto end;
        }
        else if (three[0] == 1)
        {
            goto end;
        }
        else if (three[0] == 8)
        {
            goto end;
        }
        else if (three[0] == 9)
        {
            goto end;
        }
        else if (three[0] == 2)
        {
            goto end;
        }
        else if (three[0] == 3)
        {
            goto end;
        }
        else
        {
            aaa();
        }
    }
    else if (three[1] == 5)
    {
        if (three[0] != 6)
        {
            aaa();
        }
        else if (three[0] != 7)
        {
            aaa();
        }
    }


    for (int b = 0; b < 2; b++)
    {
        if (three[b] >= 30)
        {
            three[b] -= 30;
        }
        else if (three[b] >= 20)
        {
            three[b] -= 20;
        }
        else if (three[b] >= 10)
        {
            three[b] -= 10;
        }
    }

    cout << " " << endl;
    cout << "결과: ";
    cout << "Player는 " << three[0] << ", Banker는" << three[1] << "입니다....." << endl;


end:

    Sleep(2000);

    if (pb == 1)
    {
        cout << "Pair Bet." << endl;

        if (choose == "pair")
        {
            money += bet * 11;

            cout << "현재 금액" << money << endl;
        }
        else
        {
            cout << "현재 금액" << money << endl;
        }
        goto ending;
    }

    if (three[0] > three[1])
    {
        cout << "Player 승." << endl;

        if (choose == "player")
        {
            money += bet;
            cout << "현재 금액" << money << endl;
            cout << "축하합니다." << endl;
        }
        else
        {
            cout << "현재 금액" << money << endl;
        }
    }
    else if (three[0] < three[1])
    {
        cout << "Banker 승." << endl;

        if (choose == "Banker")
        {
            money += bet * 95 / 100;
            cout << "현재 금액" << money << endl;
            cout << "축하합니다." << endl;
        }
        else
        {
            cout << "현재 금액" << money << endl;
        }
    }
    else if (three[0] == three[1])
    {
        cout << "Tie." << endl;

        if (choose == "tie")
        {
            money += bet * 8;
            cout << "현재 금액" << money << endl;
            cout << "축하합니다." << endl;
        }
        else
        {
            cout << "현재 금액" << money << endl;
        }
    }

ending:
    cout << "다시 하시겠습니까? (y/n)" << endl;
    cin >> ret;

    if (ret == "y")
    {
        
        
        goto retry;
    }
    else if (ret == "n")
    {
        return 0;
    }
}//룰은 "https://namu.wiki/w/%EB%B0%94%EC%B9%B4%EB%9D%BC#fn-8"로부터 가져옴.