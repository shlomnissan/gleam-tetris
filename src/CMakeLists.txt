add_executable(tetris
    main.cpp
    game.cpp
    game.hpp
)

find_package(gleam REQUIRED)

target_link_libraries(tetris gleam::gleam)

target_compile_options(tetris PRIVATE
    $<$<CXX_COMPILER_ID:GNU>:-fno-rtti -fno-exceptions>
    $<$<CXX_COMPILER_ID:Clang>:-fno-rtti -fno-exceptions>
    $<$<CXX_COMPILER_ID:AppleClang>:-fno-rtti -fno-exceptions>
    $<$<CXX_COMPILER_ID:MSVC>:/GR- /EHsc->
)

if(WIN32)
    add_custom_command(TARGET tetris POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:gleam::gleam>
        $<TARGET_FILE_DIR:tunnel>
    )
endif()