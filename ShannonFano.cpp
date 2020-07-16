#include "ShannonFano.h"

ShannonFano::~ShannonFano()
{
    delete[] codes;
}

void ShannonFano::fillTree(int *left, int *right, int sum)
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

void ShannonFano::build()
{
    int n = chances.size();
    values = chances.data() - 1;
    codes = new std::string[n];
    fillTree(values + 1, values + n, sum);
}

void ShannonFano::addChance(int chance)
{
    chances.push_back(chance);
    sum += chance;
}

std::string ShannonFano::get(int i)
{
    return codes[i];
}
