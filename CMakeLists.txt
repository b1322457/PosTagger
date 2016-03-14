cmake_minimum_required(VERSION 3.3)
project(PosTagger)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_VERBOSE_MAKEFILE ON)

set(SOURCE_FILES  src/tagger/preprocessor/PreProcessor.cpp  src/tagger/crf/CRFTagger.cpp src/tagger/Base_Tagger.cpp  src/tagger/train.cpp src/tagger/preprocessor/strtool.cpp)
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/third_party/rapidjson/include)
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib)

add_executable(train ${SOURCE_FILES})
target_link_libraries(train crfpp)
find_package(Boost REQUIRED COMPONENTS program_options)
if(Boost_FOUND)
    target_link_libraries(train ${Boost_LIBRARIES})
    include_directories(${Boost_INCLUDE_DIRS})
endif()

set(TEST_FILES  src/tagger/preprocessor/PreProcessor.cpp  src/tagger/crf/CRFTagger.cpp src/tagger/Base_Tagger.cpp  src/tagger/preprocessor/strtool.cpp src/tagger/predict.cpp)
add_executable(predict ${TEST_FILES})
target_link_libraries(predict crfpp)


