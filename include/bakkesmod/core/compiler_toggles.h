#pragma once

#ifndef BM_CPP20_SUPPORT
    #if __cplusplus >= 202002L
        #define BM_CPP20_SUPPORT
    #elif defined( __cpp_concepts )
            #if __cpp_concepts >= 201907L
                #define BM_CPP20_SUPPORT
            #endif
    #elif defined(__cpp_constexpr)
            #if __cpp_constexpr >= 201806L
                #define BM_CPP20_SUPPORT
            #endif
        #elif 
    #endif
#endif


#ifdef BM_CPP20_SUPPORT
	#define DEFAULTEQUALITY(clazz)\
	    bool operator==(const clazz&) const = default;
	#define DEFAULTCOMPARE(clazz)\
	    auto operator<=>(const clazz&) const = default;
#else
	#define DEFAULTEQUALITY(clazz)
	#define DEFAULTCOMPARE(clazz)
#endif