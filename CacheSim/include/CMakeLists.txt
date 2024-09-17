            add_library(
                    cache-lib
                    hpp/Cache.hpp
                    cpp/Cache.cpp
                    hpp/DirectMapped.hpp
                    cpp/DirectMapped.cpp
                    hpp/cacheline.hpp
                    hpp/Associative.hpp
                    cpp/Associative.cpp
                    hpp/ReplacementPolicy.hpp
                    hpp/IdealLRU.hpp
                    cpp/IdealLRU.cpp
                    hpp/Random_replace.hpp
                    cpp/Random_replace.cpp
                )
            target_include_directories(cache-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/hpp)
