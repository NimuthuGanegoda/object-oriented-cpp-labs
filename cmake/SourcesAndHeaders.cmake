set(sources
    src/tmp.cpp
)

set(exe_sources
		src/main.cpp
		${sources}
)

set(headers
  include/object-oriented-cpp-labs/tmp.hpp
)

set(test_sources
  ${CMAKE_CURRENT_SOURCE_DIR}/test/src/tmp_test.cpp
)

# Add a simple CLI test that runs the built executable when available
set(cli_test_command "${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}/object-oriented-cpp-labs")
