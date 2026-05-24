#pragma once 

#include <stdio.h>
#include <memory>
#include <map>
#include <unordered_map>

namespace FromHeLL
{
template <typename T>
using Unique = std::unique_ptr<T>;

template <typename T>
using Shared = std::shared_ptr<T>;

template <typename T>
using Weak = std::weak_ptr<T>;

template<typename T> 
using List = std::vector<T>;

template<typename KeyType, typename ValType, typename Pr = std::less<KeyType>>
using Map = std::map<KeyType, ValType, Pr>;

template<typename KeyType, typename ValType, typename Hasher = std::hash<KeyType>>
using Dictionary = std::unordered_map<KeyType, ValType, Hasher>;

#define LOG(M,...) printf(M "\n", ##__VA_ARGS__)
}