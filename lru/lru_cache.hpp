#pragma once

#include <unordered_map>
#include <list>

template <typename K, typename V> class LRUCache {
private:
    using iterator = typename std::unordered_map<K, V>::iterator;
    size_t                                                 _capacity;
    std::unordered_map<K, V>                               _kv;
    std::unordered_map<K, typename std::list<K>::iterator> _ki;
    std::list<K>                                           _kl;

public:
    explicit LRUCache(size_t capacity) { _capacity = capacity; }
    iterator get(K key) {
        auto it = _kv.find(key);
        if (it == _kv.end())
            return it;
        auto ki = _ki.find(key);
        _kl.splice(_kl.begin(), _kl, ki->second);
        return it;
    }
    void put(K key, V value) {
        if (_kv.find(key) != _kv.end()) {
            _kv[key] = value;
            auto ki = _ki.find(key);
            _kl.splice(_kl.begin(), _kl, ki->second);
            return;
        }
        _kv[key] = value;
        _kl.emplace_front(key);
        _ki[key] = _kl.begin();
        if (_kv.size() > _capacity) {
            _kv.erase(_kl.back());
            _ki.erase(_kl.back());
            _kl.pop_back();
        }
    }
};