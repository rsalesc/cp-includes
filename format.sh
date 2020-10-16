find -name "*.cpp" -not -path "./tests/*" | xargs clang-format -i -style=LLVM
