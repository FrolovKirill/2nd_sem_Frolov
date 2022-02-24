#include <iostream>
#include <cstdlib>
#include <ctime>

const int num = 500; //кол-во дислокаций

void AdhesionTest(int* dislocation, int m, int per) //проверка на слипание
{
    for (int i = 0; i < num * per / 100; i++)
    {
        dislocation[i * 2 + 1] = 1; //может ли дислокация двигаться, 1 - да, 0 - нет, 2 - да, но это критическая ситуация
    }

    bool logic;
    int j;
    for (int i = 0; i < num * per / 100; i++) //проверка на слипание
    {
        logic = false;
        j = 0;
        while(j < i && !logic)
        {
            if (abs(dislocation[i * 2] - dislocation[j * 2]) == 1)
            {
                dislocation[i * 2 + 1] = dislocation[j * 2 + 1] = 0;
                logic = true;
            }else if (abs(dislocation[i * 2] - dislocation[j * 2]) == 2) {
                dislocation[i * 2 + 1] = 2;
                if (dislocation[j * 2 + 1] != 0) dislocation[j * 2 + 1] = 2;
            }
            j++;
        }
        if (dislocation[i * 2] == 1 or dislocation[i* 2] == m) {
            dislocation[i * 2 + 1] = 0;
        }
    }
}

void Move(int* dislocation, int per) //функция передвижения
{
    int direction;
    bool logic;
    int j;

    for (int i = 0; i < num * per / 100; i++)
    {
        if (dislocation[i * 2 + 1] == 0)
        {
            continue;
        } else if (dislocation[i * 2 + 1] == 1) {
            direction = rand() % 2;
            if (direction == 0)
            {
                dislocation[i * 2]++;
            } else if (direction == 1) {
                dislocation[i * 2]--;
            }
        } else { //dislocation[...][1] = 2
            direction = rand() % 2;

            logic = true;
            j = 0;
            while (j < i && logic)
            {
                if (dislocation[j * 2 + 1] == 0 or dislocation[j * 2 + 1] == 1)
                {
                    j++;
                    continue;
                }

                if (direction == 0 && dislocation[i * 2] + 1 == dislocation[j * 2])
                {
                    logic = false;
                } else if (direction == 1 && dislocation[i * 2] - 1 == dislocation[j * 2]) {
                    logic = false;
                }
                j++;
            }
            if (logic)
            {
                if (direction == 0)
                {
                    dislocation[i * 2]++;
                } else if (direction == 1) {
                    dislocation[i * 2]--;
                }
            }
        }
    }
}

int base(int m, int per) {

    int dislocation[num][2];

    for (int i = 0; i < num * per / 100; i++) { //задание начальных параметров дислокаций
        dislocation[i][0] = rand() % m + 1; //первая координата дислокации

        for (int j = 0; j < i; j++) //проверка совпадения начальных координат
        {
            if (dislocation[i][0] == dislocation[j][0])
            {
                dislocation[i][0] = rand() % m + 1;
                j = -1;
            }
        }
    }
    AdhesionTest(&dislocation[0][0], m, per);

    int count = 0; //переменная, отвечающая за время остановки всех дислокаций

    int mobility = 0;
    for (int i = 0; i < num * per / 100; i++)
    {
        mobility += dislocation[i][1];
    }

    while(mobility != 0)
    {
        count += 1;
        Move(&dislocation[0][0], per);

        AdhesionTest(&dislocation[0][0], m, per);

        mobility = 0;
        for (int i = 0; i < num * per / 100; i++) {
            mobility += dislocation[i][1];
        }
    }

    return count;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int m = 500;
    float results[90];
    int summ;
    for (int percents = 1; percents < 91; percents++)
    {
        summ = 0;
        for (int j = 0; j < 300; j++) {
            summ += base(m, percents);
        }
        results[percents - 1] = summ / 300;
        std::cout << percents << std::endl;
    }

    for (int i = 0; i < 90; i++) {
        std::cout << results[i] << ", ";
    }

    return 0;
}