cmake_minimum_required(VERSION 3.19)
project(Python_hybrid_test LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(Python_hybrid_test
    WIN32 MACOSX_BUNDLE
    main.cpp
    widget.cpp
    widget.h
    widget.ui


    mainwindow.h mainwindow.cpp mainwindow.ui
    thirdwindow.h thirdwindow.cpp thirdwindow.ui
    fourthpage.h fourthpage.cpp fourthpage.ui
)

target_link_libraries(Python_hybrid_test
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS Python_hybrid_test
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Python_hybrid_test
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
