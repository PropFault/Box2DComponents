cmake_minimum_required(VERSION 2.8)

project(Box2DComponent)


set(CMAKE_CXX_STANDARD 17)

# Download automatically, you can also just copy the conan.cmake file
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
                  "${CMAKE_BINARY_DIR}/conan.cmake")
endif()
include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_add_remote(NAME bincrafters INDEX 1
            URL https://api.bintray.com/conan/bincrafters/public-conan)
conan_cmake_run(REQUIRES  sdl2/2.0.12@bincrafters/stable  bzip2/1.0.8@conan/stable  zlib/1.2.9@conan/stable  nlohmann_json/3.7.3  boost_dll/1.69.0@bincrafters/stable boost_any/1.69.0@bincrafters/stable boost_filesystem/1.69.0@bincrafters/stable  box2d/2.3.2.ef96a4f@conan/stable BASIC_SETUP BUILD missing)

add_library(${PROJECT_NAME} SHARED "main.cpp" "box2dsystem.cpp" "physicsbodycomponent.cpp" "staticbodycomponent.cpp" "dynamicbodycomponent.cpp" "physicsfixturecomponent.cpp" "circlefixturecomponent.cpp" "boxfixturecomponent.cpp")
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})
