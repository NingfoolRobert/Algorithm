题目分析

> 给出n个区间[l,r]，现要求将区间合并，有重叠的区间将合并成一个区间。 如，初始区间为：[1,3],[2,6],[8,10],[15,18] 合并之后的区间为：[1,6],[8,10],[15,18]

解题思路

>贪心思路，将初始区间序列ins按照左端点的从小到大排序，接着遍历ins。 一开始将第一个区间ins[0]放入结果区间序列res，接着每次遍历到一个新的区间[l,r]，将其与当前合并后的最后一个区间[L,R]比较：
>
>1. 若l <= R，说明新区间与当前最有一个区间有重叠，应该将这两个区间合并，也就需要修改当前最后一个区间为[L，max(r,R)]。
>2. 若l > R，说明新区间与当前最后一个区间没有重叠，所以不需要合并，直接将新区间加入结果序列res，成为新的最后一个区间。

算法正确性

> 在上述贪心思路中，只考虑了新区间的左端点与最后一个区间的右端点的大小比较，最后只会对最后区间的右端点进行修改，却不会修改左端点。之所以不考虑左端点，是因为初始化时已经将ins按照左端点排序，保证后遍历的左端点l >= 之前遍历过的左端点L。 算法复杂度为O(nlogn)。





```c++
static bool cmp(const Interval &a, const Interval &b)
{
     return a.start < b.start;
}


vector<Interval> merge(vector<Interval>& ins) 
{
    vector <Interval> res;
    if (ins.empty()) return res;
    sort(ins.begin(), ins.end(), cmp);
    res.push_back(ins[0]);
    int cnt = ins.size();
    for (int i = 1; i < cnt; i++) 
    {
        if (ins[i].start <= res.back().end) 
        {
            res.back().end = max(res.back().end, ins[i].end);
        }
        else 
        {
            res.push_back(ins[i]);
        }
    }
    return res;
}
```

