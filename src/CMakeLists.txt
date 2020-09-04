find_library(CocoaLib Cocoa)

configure_file(RextEditorWindowStyle.qss RextEditorWindowStyle.qss)

add_library(FileManager "")
target_sources(FileManager
        PRIVATE
            FileManager.cpp
        PUBLIC
            FileManager.h
        )
target_link_libraries(FileManager
        PRIVATE
            Qt5::Widgets
        )

add_library(RextEditorWindow "")
target_sources(RextEditorWindow
        PRIVATE
            RextEditorWindow.cpp
            RextEditorWindow.mm
        PUBLIC
            RextEditorWindow.h
            RextEditorWindow.ui
        )
target_link_libraries(RextEditorWindow
        PRIVATE
            Qt5::Widgets
            Qt5::Core
            ${CocoaLib}
            FileManager
        )



add_executable(RextEditor "")
target_sources(RextEditor
        PRIVATE
            main.cpp
        )
target_link_libraries(RextEditor
        FileManager
        RextEditorWindow
        Qt5::Widgets
        )