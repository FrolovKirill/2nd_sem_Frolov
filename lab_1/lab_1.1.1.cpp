#include <iostream>
#include <cstdlib>
#include <ctime>

int base(int m, int n) {

    int dislocation[3];

    dislocation[0] = m / 2;
    dislocation[1] = n / 2;
    dislocation[2] = 1;

    int count = 0; //переменная, отвечающая за время остановки всех дислокаций
    int direction;

    while(dislocation[2])
    {
        count += 1;

        direction = rand() % 4;
        if (direction == 0)
        {
            dislocation[0]++;
        } else if (direction == 1) {
            dislocation[0]--;
        } else if (direction == 2) {
            dislocation[1]++;
        } else {
            dislocation[1]--;
        }

        if (dislocation[0] == 1 or dislocation[0] == m) {
            dislocation[2] = 0;
        } else if (dislocation[1] == 1 or dislocation[1] == n) {
            dislocation[2] = 0;
        }
    }

    return count;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int results[290];
    int summ;
    for (int i = 1; i < 291; i++)
    {
        summ = 0;
        for (int j = 0; j < 2000; j++) {
            summ += base(9 + i, 9 + i);
        }
        results[i - 1] = summ / 2000;
        std::cout << i << std::endl;
    }

    for (int i = 0; i < 290; i++) {
        std::cout << results[i] << ", ";
    }

    return 0;
}