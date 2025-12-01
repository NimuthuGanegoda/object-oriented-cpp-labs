set(sources
    src/tmp.cpp
    src/ExampleClass.cpp
)

set(exe_sources
		src/main.cpp
		${sources}
)

set(headers
    include/object-oriented-cpp-labs/tmp.hpp
    include/object-oriented-cpp-labs/ExampleClass.hpp
)

set(test_sources
  src/tmp_test.cpp
  src/test.cpp
  src/ExampleClass_test.cpp
)
