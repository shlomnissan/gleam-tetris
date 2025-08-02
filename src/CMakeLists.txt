add_executable(${PROJECT_NAME}
    main.cpp
    game.cpp
    game.hpp
)

find_package(gleam REQUIRED)

target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<CXX_COMPILER_ID:GNU>:-fno-rtti -fno-exceptions>
    $<$<CXX_COMPILER_ID:Clang>:-fno-rtti -fno-exceptions>
    $<$<CXX_COMPILER_ID:AppleClang>:-fno-rtti -fno-exceptions>
    $<$<CXX_COMPILER_ID:MSVC>:/GR- /EHsc->
)

target_link_libraries(${PROJECT_NAME} gleam::gleam)

if(WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:gleam::gleam>
        $<TARGET_FILE_DIR:tunnel>
    )
endif()