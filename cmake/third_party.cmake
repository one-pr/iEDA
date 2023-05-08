SET(THIRD_PARTY_HOME ${HOME_THIRDPARTY})

add_definitions("-DBOOST_ALLOW_DEPRECATED_HEADERS")
add_definitions("-DBOOST_BIND_GLOBAL_PLACEHOLDERS")

INCLUDE_DIRECTORIES(SYSTEM 
    ## third party
    ${THIRD_PARTY_HOME}/json
    ${THIRD_PARTY_HOME}/gurobi
)

find_package(OpenMP REQUIRED)
if (OPENMP_FOUND)
    message("OPENMP FOUND")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()
