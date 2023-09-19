###Leetcode问题描述：
实现一个LRU(least recently used)Cache数据结构,该结构存储一系列键值对，该数据结构的读写都是常数时间，当数据结构达到设定容量并且要进行写入操作的时候，需要将最近最少用到的键值对去除。

代码实现如下：
```c++
class LRUCache {
private:
    size_t m_cap;
    list<pair<int, int>> m_list;
    unordered_map<int, list<pair<int, int>>::iterator> m_map;
public:
    LRUCache(int capacity):m_cap(capacity) {
        
    }
    
    int get(int key) {
        auto found_iter = m_map.find(key);
        if(found_iter == m_map.end())   return -1;
        m_list.splice(m_list.begin(), m_list, found_iter->second);
        return found_iter->second->second;
    }
    
    void put(int key, int value) {
        auto found_iter = m_map.find(key);
        if(found_iter != m_map.end()){
            m_list.splice(m_list.begin(), m_list, found_iter->second);
            found_iter->second->second = value;
            return;
        }
        if(m_map.size() == m_cap){
            int key_to_del = m_list.back().first;
            m_list.pop_back();
            m_map.erase(key_to_del);
        }
        m_list.emplace_front(key, value);
        m_map[key] = m_list.begin();
    }
};
```

###代码分析如下：
代码的核心思想在于，**建立一个map数据结构，用来管理缓存链表的迭代器**。
这样在调用get方法的时候，我们利用map可以在O(1)时间内获取迭代器，也就相应获得键值，然后可以调用list的splice方法，将该节点放到链表最前面。
当调用put方法时，如果key已经存在，我们也要找到相应的迭代器，并将list相应的节点挪到最前面，最后更改value的值。当cache容量已满时，我们只需要删除list最后的节点，清除掉map里面相应的键值对即可，然后将键值对放到list最前面，更新map的键值对。