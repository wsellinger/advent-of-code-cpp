#pragma once
#include <map>

namespace AdventOfCodeLibrary
{
    namespace MapUtils
    {
        template<typename TKey, typename TValue>
        TValue GetValueOrDefault(const std::map<TKey, TValue>& map, const TKey& key)
        {
            bool isFound = false;
            auto it = map.find(key);

            return it != map.end() ? it->second : TValue();
        }
    }
}