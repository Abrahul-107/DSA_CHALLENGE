#include<iostream>
#include<list>
#include<unordered_map>

using namespace std;

class LruCache
{
private:
    int capacity;
    list<pair<int,int>>cache;
    unordered_map<int,list<pair<int,int>>::iterator>mp;

public:
    LruCache(int size)
    {
        capacity = size;
    }


    int get(int key)
    {
        //If key is not there return -1
        if(mp.find(key)==mp.end())
            return -1;

        //Get the value from map 
        int value = mp[key]->second;

        //Move node to front
        cache.erase(mp[key]);
        cache.push_front({key,value});

        mp[key]= cache.begin();
        return value;

    }
    void put(int key,int value)
    {
        if(mp.find(key)!=mp.end())
            cache.erase(mp[key]);
        else if(mp.size()==capacity) // if cache is full
        {
            int lastKey = cache.back().first;
            cache.pop_back();
            mp.erase(lastKey);
        }
        cache.push_front({key,value});
        mp[key]=cache.begin();

    }
};


int main()
{
    LruCache lru(2);

    lru.put(1, 10);
    lru.put(2, 20);

    cout << lru.get(1) << endl;   // 10

    lru.put(3, 30);               // Removes key 2

    cout << lru.get(2) << endl;   // -1
    cout << lru.get(3) << endl;   // 30

    return 0;

}