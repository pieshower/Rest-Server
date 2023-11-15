cmake_minimum_required(VERSION 3.10)



# Set the project name
project(Rest-Server)


# Add a library with the above sources
add_executable(${PROJECT_NAME} 
    src/main.cpp 
)


target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/src
    PUBLIC ${PROJECT_SOURCE_DIR}/inc
)


set(CMAKE_CXX_STANDARD 20)


# find_package(OpenCV REQUIRED)
# find_library(PIGPIO_LIBRARY NAMES pigpio)


# ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)
# set(Boost_USE_STATIC_LIBS OFF) 
# set(Boost_USE_MULTITHREADED ON)  
# set(Boost_USE_STATIC_RUNTIME OFF) 
# FIND_PACKAGE( Boost REQUIRED COMPONENTS log system program_options filesystem serialization  )
# target_link_libraries(${PROJECT_NAME} rt)


# INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR} )
# INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})

# target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

# target_include_directories(${PROJECT_NAME}
#     PRIVATE
#     ${CMAKE_CURRENT_LIST_DIR}
# )


# target_link_libraries(${PROJECT_NAME}
#     ${Boost_LIBRARIES} 
#     #${OpenCV_LIBS}
#     Threads::Threads
#     rt
#     pigpio
# )