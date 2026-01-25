# Workshop exercises organized by week

# Helper macro to add executables for a week
macro(add_week_executables week_num week_dir)
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${week_dir}")
        file(GLOB WEEK_SOURCES "${week_dir}/*.cpp")
        foreach(source ${WEEK_SOURCES})
            get_filename_component(exec_name ${source} NAME_WE)
            string(REPLACE " " "_" exec_name "${exec_name}")
            string(REGEX REPLACE "[^A-Za-z0-9_]" "_" exec_name "${exec_name}")
            add_executable(week${week_num}_${exec_name} ${source})
            target_compile_features(week${week_num}_${exec_name} PRIVATE cxx_std_17)
            set_target_properties(week${week_num}_${exec_name} PROPERTIES
                RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Workshops/Week${week_num}"
            )
        endforeach()
    endif()
endmacro()

add_week_executables(1 "Week 1")
add_week_executables(2 "Week 2")
add_week_executables(3 "Week 3")
add_week_executables(4 "Week 4")
add_week_executables(5 "Week 5")
# Week 6 handled separately below
# add_week_executables(6 "Week 6")
add_week_executables(7 "Week 7")
add_week_executables(8 "Week 8")
add_week_executables(9 "Week 9")

# Week 3 Resource Files
file(COPY "Week 3/map.txt" "Week 3/names.txt" DESTINATION "${CMAKE_BINARY_DIR}/Workshops/Week3")

# Week 6: Inheritance
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/Week 6")
    # Inheritance Main Executable
    add_executable(week6_Inheritance
        "Week 6/InheritanceMain.cpp"
        "Week 6/Mammal.cpp"
        "Week 6/Lion.cpp"
        "Week 6/Tiger.cpp"
        "Week 6/Liger.cpp"
    )
    target_compile_features(week6_Inheritance PRIVATE cxx_std_17)
    set_target_properties(week6_Inheritance PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Workshops/Week6"
    )

    # HRSystem Executable
    add_executable(week6_HRSystem "Week 6/HRSystem.cpp")
    target_compile_features(week6_HRSystem PRIVATE cxx_std_17)
    set_target_properties(week6_HRSystem PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/Workshops/Week6"
    )

    # Copy employees.txt
    file(COPY "Week 6/employees.txt" DESTINATION "${CMAKE_BINARY_DIR}/Workshops/Week6")
endif()
