include(FindPackageHandleStandardArgs)

find_path(POPPLER_INCLUDE_DIR
        NAMES
        poppler-qt5.h
        PATH_SUFFIXES
        "poppler/qt5"
        HINTS "${CMAKE_PREFIX_PATH}/include"
        )

find_library(POPPLER_LIBRARY
        NAMES
        poppler-qt5
        HINTS "${CMAKE_PREFIX_PATH}/lib"
        )

find_package_handle_standard_args(POPPLER DEFAULT_MSG POPPLER_LIBRARY POPPLER_INCLUDE_DIR)

mark_as_advanced(POPPLER_INCLUDE_DIR POPPLER_LIBRARY )

if(POPPLER_FOUND)
    set(POPPLER_INCLUDE_DIRS ${POPPLER_INCLUDE_DIR})
    set(POPPLER_LIBRARIES ${POPPLER_LIBRARY})
endif()

include_directories(${POPPLER_INCLUDE_DIRS})