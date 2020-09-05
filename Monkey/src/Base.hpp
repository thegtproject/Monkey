#pragma once

#include <iostream>

#define PRINT(...) printf(__VA_ARGS__)

#define Interface class

#ifdef _DEBUG
 // #define TRACE(...) PRINT("[trace] %s() %s\n", __FUNCTION__, __VA_ARGS__)
 #define TRACE() PRINT("[trace] %s()\n", __FUNCTION__)
#else
 #define TRACE(...)
#endif

template<typename T>
using Scope = std::unique_ptr<T>;
template<typename T, typename ... Args>
constexpr Scope<T> CreateScope(Args&& ... args)
{
	return std::make_unique<T>(std::forward<Args>(args)...);
}

template<typename T>
using Ref = std::shared_ptr<T>;
template<typename T, typename ... Args>
constexpr Ref<T> CreateRef(Args&& ... args)
{
	return std::make_shared<T>(std::forward<Args>(args)...);
}