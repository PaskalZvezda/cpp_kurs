cmake_minimum_required(VERSION 3.15)
project(SFML_Project)
set(CMAKE_CXX_STANDARD 17)
set(SFML_DIR "C:/SFML-2.6.1-windows-vc17-64-bit/SFML-2.6.1/lib/cmake/SFML")
find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)
add_executable(main main.cpp)
target_link_libraries(main PRIVATE sfml-graphics sfml-window sfml-system)
add_custom_command(TARGET main POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "C:/SFML-2.6.1-windows-vc17-64-bit/SFML-2.6.1/bin/sfml-graphics-2.dll" $<TARGET_FILE_DIR:main>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "C:/SFML-2.6.1-windows-vc17-64-bit/SFML-2.6.1/bin/sfml-window-2.dll" $<TARGET_FILE_DIR:main>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "C:/SFML-2.6.1-windows-vc17-64-bit/SFML-2.6.1/bin/sfml-system-2.dll" $<TARGET_FILE_DIR:main>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "C:/SFML-2.6.1-windows-vc17-64-bit/SFML-2.6.1/bin/sfml-graphics-d-2.dll" $<TARGET_FILE_DIR:main>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "C:/SFML-2.6.1-windows-vc17-64-bit/SFML-2.6.1/bin/sfml-window-d-2.dll" $<TARGET_FILE_DIR:main>
    COMMAND ${CMAKE_COMMAND} -E copy_if_different "C:/SFML-2.6.1-windows-vc17-64-bit/SFML-2.6.1/bin/sfml-system-d-2.dll" $<TARGET_FILE_DIR:main>
)