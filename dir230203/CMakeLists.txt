# https://google.github.io/googletest/quickstart-cmake.html

# 1)
# https://qiita.com/Hiroya_W/items/049bfb4c6ad3dfe6ff0c
# 動作確認出来ている最も低いバージョンを記載
# 動作を保証するための何よりも一番最初に設定しておくポリシー
cmake_minimum_required(VERSION 3.14)
# https://cmake.org/cmake/help/latest/command/project.html
# project(<PROJECT-NAME>
#     [VERSION <major>[.<minor>[.<patch>[.<tweak>]]]]
#     [DESCRIPTION <project-description-string>]
#     [HOMEPAGE_URL <url-string>]
#     [LANGUAGES <language-name>...])
project(my_project)

# GoogleTest requires at least C++14
# set(CMAKE_CXX_STANDARD 14)

# 2)
# https://qiita.com/shohirose/items/d2b9c595a37b27ece607
# ビルドに必要なライブラリを自分のCMakeプロジェクト内で使えるようにする
# FetchContent CMake module を include
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG 2f2e72bae991138cedd0e3d06a115022736cd568    # 230203 nain head
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# 3)
# https://qiita.com/mrk_21/items/25ee7f00cebb9934b472
# CTest を有効にするためには、enable_testing()コマンドを利用する必要がある
# プロジェクトルートで実行する必要がある
# 実行後、各ビルドディレクトリに CTestTestfile.cmake というテスト用のファイルが生成される
enable_testing()

# 4)
# 実行ファイル a.out を ソース *.cpp から生成
add_executable(
    a.out
    gtest_quickstart.cpp
)

# 5)
# C++ の標準規格の指定
target_compile_features(
    a.out
    PRIVATE cxx_std_14
)

# 6)
# ライブラリのリンク
target_link_libraries(
    a.out
    GTest::gtest_main
)

# The last two lines enable CMake’s test runner
# to discover the tests included in the binary

# 7)
include(GoogleTest)

# 8)
# discovers tests by asking the compiled test executable to enumerate its tests.
gtest_discover_tests(a.out)

# command
# 1)
# - ソースツリーとビルドツリーの場所を指定
# - mkdir build;cd build; cmake .. とかしなくていい
# - ビルドツリーで指定したディレクトリが存在しない場合は自動的に作成
# cmake -S . -B build
# 2)
# ビルドシステムに依存せずに、ビルドを実行できる
# cmake --build build
# 3)
# cd build && ctest