cmake_minimum_required(VERSION 3.5)

#project(BeautiFRIL LANGUAGES CXX)

#set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

if(ANDROID)
  add_library(BeautiFRIL SHARED
    main.cpp
    mainwindow.cpp
    mainwindow.h
  )
else()
  add_executable(BeautiFRIL
    main.cpp
    mainwindow.cpp
    mainwindow.h
    editor.cpp
    editor.h
    editortabmanager.cpp
    editortabmanager.h
    highlighter.cpp
    highlighter.h
    resources.qrc
  )
endif()

target_link_libraries(BeautiFRIL PRIVATE Qt5::Widgets)
