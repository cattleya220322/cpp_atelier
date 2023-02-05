cmake_minimum_required(VERSION 3.14)

project(test_fetch)

# Build mylib
include(FetchContent)
FetchContent_Declare(
    mylib
    GIT_REPOSITORY https://github.com/cattleya220322/cpp_mylib.git
    GIT_TAG        84016b2b6f6661173d7499e284a25f8c43f14ecc
)
FetchContent_MakeAvailable(mylib)

# 実行ファイル a.out を ソース *.cpp から生成
add_executable(
    GenDaily
    GenDaily.cpp
)

# C++ の標準規格の指定
target_compile_features(
    GenDaily
    PRIVATE
    cxx_std_14
)

# ライブラリのリンク
target_link_libraries(
    GenDaily
    # 追記
    mylib
)