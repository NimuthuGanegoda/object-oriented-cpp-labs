# Project exercises organized by week

# Week 1
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/Week 1")
    file(GLOB WEEK1_SOURCES "Week 1/*.cpp")
    foreach(source ${WEEK1_SOURCES})
        get_filename_component(exec_name ${source} NAME_WE)
        string(REPLACE " " "_" exec_name "${exec_name}")
        string(REGEX REPLACE "[^A-Za-z0-9_]" "_" exec_name "${exec_name}")
        add_executable(week1_${exec_name} ${source})
        target_compile_features(week1_${exec_name} PRIVATE cxx_std_17)
        set_target_properties(week1_${exec_name} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Project/Week1"
        )
    endforeach()
endif()

# Week 2
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/Week 2")
    file(GLOB WEEK2_SOURCES "Week 2/*.cpp")
    foreach(source ${WEEK2_SOURCES})
        get_filename_component(exec_name ${source} NAME_WE)
        string(REPLACE " " "_" exec_name "${exec_name}")
        string(REGEX REPLACE "[^A-Za-z0-9_]" "_" exec_name "${exec_name}")
        add_executable(week2_${exec_name} ${source})
        target_compile_features(week2_${exec_name} PRIVATE cxx_std_17)
        set_target_properties(week2_${exec_name} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Project/Week2"
        )
    endforeach()
endif()

# Week 3
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/Week 3")
    file(GLOB WEEK3_SOURCES "Week 3/*.cpp")
    foreach(source ${WEEK3_SOURCES})
        get_filename_component(exec_name ${source} NAME_WE)
        # Replace spaces and non-alnum chars with underscores for valid target names
        string(REPLACE " " "_" exec_name "${exec_name}")
        string(REGEX REPLACE "[^A-Za-z0-9_]" "_" exec_name "${exec_name}")
        add_executable(week3_${exec_name} ${source})
        target_compile_features(week3_${exec_name} PRIVATE cxx_std_17)
        set_target_properties(week3_${exec_name} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Project/Week3"
        )
    endforeach()
endif()

# Week 4
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/Week 4")
    file(GLOB WEEK4_SOURCES "Week 4/*.cpp")
    foreach(source ${WEEK4_SOURCES})
        get_filename_component(exec_name ${source} NAME_WE)
        string(REPLACE " " "_" exec_name "${exec_name}")
        string(REGEX REPLACE "[^A-Za-z0-9_]" "_" exec_name "${exec_name}")
        add_executable(week4_${exec_name} ${source})
        target_compile_features(week4_${exec_name} PRIVATE cxx_std_17)
        set_target_properties(week4_${exec_name} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Project/Week4"
        )
    endforeach()
endif()
