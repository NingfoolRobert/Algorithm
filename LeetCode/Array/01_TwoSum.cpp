#include <iostream>
#include <string.h>
#include <map>
#include <vector>
#include <hash_map>



//使用map表 算法复杂度：nlog(n)
//从列表中
using namespace std;
std::vector<int, int> twoSum(int *pnArray, int cnArray, int target)
{
    map<int,int> mapArray;
    for (size_t i = 0; i < cnArray; i++)
    {
        /* code */
        int num = target - pnArray[i];
        std::map<int,int>::iterator it = mapArray.find(target);
        if(it != mapArray.end())
        {
            return {it->second,pnArray[i]};
        }
        mapArray[pnArray[i]] = num;
    }
    
}
int main()
{
    int nArray[] ={2,7,11,15,19};

    vector<int, int> list;
    list = twoSum(nArray,5,9);
    cout << "Test end"<< endl;
    return 0;
}