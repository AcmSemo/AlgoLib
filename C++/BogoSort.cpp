#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

bool IsSorted(std::vector<int> vals)
{
    for(int i = 0; i < vals.size() - 1; ++i)
    {
        if(vals[i] >= vals[i + 1])
        {
            return false;
        }
    }

    return true;
}

void BogoSort(std::vector<int> vals)
{
    srand(time(NULL));
    while(!IsSorted(vals))
    {
        for(int i = 0; i < vals.size(); ++i)
        {
            int temp = vals[i];
            int target = rand() % vals.size();
            vals[i] = vals[target];
            vals[target] = temp;
        }

        for(int n : vals)
            std::cout << n << " ";
        std::cout << "\n";
    }
}

int main()
{
    std::vector<int> test = {5, 4, 3, 2, 1};
    BogoSort(test);
}

