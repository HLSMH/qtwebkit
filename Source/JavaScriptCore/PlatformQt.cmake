if (${JavaScriptCore_LIBRARY_TYPE} MATCHES STATIC)
    add_definitions(-DSTATICALLY_LINKED_WITH_WTF)
endif ()

list(APPEND JavaScriptCore_INCLUDE_DIRECTORIES
    ${WTF_DIR}
)

list(APPEND JavaScriptCore_SOURCES
    API/JSStringRefQt.cpp
)

list(APPEND JavaScriptCore_SYSTEM_INCLUDE_DIRECTORIES
    ${Qt5Core_INCLUDE_DIRS}
)

list(APPEND JavaScriptCore_LIBRARIES
    ${Qt5Core_LIBRARIES}
)

if (QT_STATIC_BUILD)
    list(APPEND JavaScriptCore_LIBRARIES
        ${STATIC_LIB_DEPENDENCIES}
    )
endif ()

# From PlatformWin.cmake
if (WIN32)
    list(REMOVE_ITEM JavaScriptCore_SOURCES
        inspector/JSGlobalObjectInspectorController.cpp
    )
endif ()
