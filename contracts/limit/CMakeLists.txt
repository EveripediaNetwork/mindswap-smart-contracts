add_contract(limit limit ${CMAKE_CURRENT_SOURCE_DIR}/src/limit.cpp)
target_include_directories(limit PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(limit PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/tables)
target_include_directories(limit PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../token/include)
target_include_directories(limit PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../)
set_target_properties(limit PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")
configure_file( ${CMAKE_CURRENT_SOURCE_DIR}/ricardian/limit.contracts.md.in ${CMAKE_CURRENT_BINARY_DIR}/ricardian/limit.contracts.md @ONLY )
target_compile_options( limit PUBLIC -R${CMAKE_CURRENT_SOURCE_DIR}/ricardian -R${CMAKE_CURRENT_BINARY_DIR}/ricardian )