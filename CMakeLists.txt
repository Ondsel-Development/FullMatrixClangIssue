cmake_minimum_required(VERSION 3.16)
project(FullMatrix)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(FullMatrix STATIC)

target_sources(FullMatrix PRIVATE
        FullMatrixClangIssue/Array.cpp
        FullMatrixClangIssue/FullColumn.cpp
        FullMatrixClangIssue/FullRow.cpp
        FullMatrixClangIssue/FullVector.cpp
        FullMatrixClangIssue/RowTypeMatrix.cpp
        FullMatrixClangIssue/Array.h
        FullMatrixClangIssue/FullColumn.h
        FullMatrixClangIssue/FullRow.h
        FullMatrixClangIssue/FullVector.h
        FullMatrixClangIssue/RowTypeMatrix.h
)

add_executable(FullMatrixClangIssue FullMatrixClangIssue/FullMatrixClangIssue.cpp)

install(TARGETS FullMatrix FullMatrixClangIssue)