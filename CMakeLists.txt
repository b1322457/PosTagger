cmake_minimum_required(VERSION 3.3)
project(PosTagger)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    README.md src/tagger/crf/CRFTagger.cpp include/tagger/crf/CRFTagger.h src/tagger/preprocessor/PreProcessor.cpp include/tagger/preprocessor/PreProcessor.h src/tagger/Base_Tagger.cpp include/tagger/Base_Tagger.h src/tagger/train.cpp)
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/third_party/rapidjson/include)
LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/lib)

add_executable(PosTagger ${SOURCE_FILES})
target_link_libraries(PosTagger crfpp)