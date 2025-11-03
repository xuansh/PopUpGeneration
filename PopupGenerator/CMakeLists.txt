cmake_minimum_required(VERSION 3.19)
project(PopupGenerator LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets LinguistTools)

qt_standard_project_setup()

qt_add_executable(PopupGenerator
    WIN32 MACOSX_BUNDLE
    main.cpp
    popupgenerator.cpp
    popupgenerator.h
    popupgenerator.ui
    popup.h
    popup.cpp
    PopupGenerator.rc
)

qt_add_translations(
    TARGETS PopupGenerator
    TS_FILES PopupGenerator_zh_CN.ts
)

target_link_libraries(PopupGenerator
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS PopupGenerator
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET PopupGenerator
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
