cmake_minimum_required(VERSION 3.22)

FetchContent_Declare(
        Boost
        URL "https://github.com/boostorg/boost/releases/download/boost-1.83.0/boost-1.83.0.tar.xz"
        DOWNLOAD_EXTRACT_TIMESTAMP ON
)

set(BOOST_RUNTIME_LINK static)
set(BOOST_INCLUDE_LIBRARIES
        asio
        assert
        align
        array
        bind
        coroutine
        config
        context
        core
        chrono
        date_time
        exception
        function
        move
        system
        smart_ptr
        throw_exception
        type_traits
        lockfree
        utility
)
FetchContent_MakeAvailable(Boost)

foreach (lib ${BOOST_INCLUDE_LIBRARIES})
    target_link_libraries(
            Uniti
            PUBLIC
            Boost::${lib}
    )
endforeach ()