/*
 * @Author: NatureLan-sudo lantianran282@163.com
 * @Date: 2022-10-10 08:37:39
 * @LastEditors: NatureLan-sudo lantianran282@163.com
 * @LastEditTime: 2022-10-10 11:30:39
 * @FilePath: /leet/zhanyuduilie/347.cpp
 * @brief: 
 * 
 * Copyright (c) 2022 by NatureLan-sudo lantianran282@163.com, All Rights Reserved. 
 */
// 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。
// k是返回的个数
// 朴素想法是： 1、统计元素出现的次数 用map存 2、对元素进行排序 3、取出前k个元素
// 优化：1、统计元素出现的次数 用map存 2、只排序到前k个元素就输出
// map会根据键值对元素进行排序，set的键和值是相等的，所以当我们想统计元素的个数，需要键和值不一样的时候，应该使用map
// 如果用大顶堆，那我们得到的是一个升序的序列，最大的在后面
// 所以我们要用小顶堆，因为要统计最大前k个元素，只有小顶堆每次将最小的元素弹出，最后小顶堆里剩下的是K个频率最高的元素。
#include "common_include.h"
class Solution {
public:
     // 通过重载运算符定义出小顶堆，我们弹出最小的元素
    class mycomparison {
        public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
           return lhs.second > rhs.second;   //返回大的
            }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans(k);
       unordered_map<int,int> key;
        for (int i = 0; i < nums.size(); i++) {
            key[nums[i]]++;
        }
        // 需要注意数据类型
        // 中间的容器类型只能是vector,queue等
        // 因为我们需要比较的是 map中的value。如果是pair类型优先比较的是第一个值。所以我们需要自定义一个数据类型，是以value为比较对象的小顶堆
        priority_queue < pair<int, int>, vector< pair<int,int> >, mycomparison >  q;   // 优先级队列 (数据类型，容器类型，比较方式)，升序序列，小顶堆
        // 通过迭代器，遍历map和仅仅通过序号有区别吗？有的，这里是指向内容
        for (unordered_map<int, int>::iterator it = key.begin(); it != key.end(); it++) {
            q.push(*it); 
            if (q.size()>k) {
                q.pop(); // 顶是最小的，把小的都弹出去
            }
        }
        // 将值放到vector输出 ,不要求顺序直接保存，要求顺序倒序保存
        // q中是 12345 升序，我们想把频率最大的先输出，所以倒序保存
        for (int i = k - 1; i >=0; i--) {
            ans[i]=q.top().first;    // 这里还是队列，把顶取出来再剔除。
            q.pop();
        }
        return ans;

    }
};