
add_executable (Trie "main.cpp" "main.h" "Trie.h" "Trie.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Trie PROPERTY CXX_STANDARD 20)
endif()
