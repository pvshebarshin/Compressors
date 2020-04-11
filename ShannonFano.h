#include <vector>
using namespace std;
class ShannonFano
{
public:
    ShannonFano()
    {

    }

    ~ShannonFano()
    {
        delete[] codes;
    }

    //Реализация алгоритма
    void fillTree(int *left, int *right, int sum)
    {
        int* leftCopy = left;
        int leftSum = *left;
        int* next = left + 1;
        while(abs(leftSum + *next - (sum - leftSum - *next))
              < abs(leftSum - (sum - leftSum)))
        {
            leftSum += *next;
            leftCopy = next;
            ++next;
        }

        int i = (left - values - 1);

        for(; i < leftCopy - values; ++i)
            codes[i] += '0';

        for(; i < right - values; ++i)
            codes[i] += '1';

        if(leftCopy > left)
            fillTree(left, leftCopy, leftSum);
        if(leftCopy < right - 1)
            fillTree(leftCopy + 1, right, sum - leftSum);
    }

    // запускает алгоритм (после того как были добавлены все элементы)
    void build()
    {
        int n = chances.size();
        values = chances.data() - 1;
        codes = new string[n];
        fillTree(values + 1, values + n, sum);
    }

    // добавляет элемент в список
    void addChance (int chance)
    {
        chances.push_back(chance);
        sum += chance;
    }
    string get (int i)
    {
        // выдает битовый код i символа
        return codes[i];
    }

private:
    vector<int> chances;
    int* values = nullptr;
    string* codes = nullptr;
    int sum = 0;
};