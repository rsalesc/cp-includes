---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: tests/catch.hpp
    title: tests/catch.hpp
  - icon: ':warning:'
    path: utils/Annotation.cpp
    title: utils/Annotation.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utils/Annotation.cpp\"\n\n\n#include <bits/stdc++.h>\n\n\
    namespace lib {\nusing namespace std;\ntemplate <typename T, typename A = void>\n\
    struct Note : public T {\nprivate:\n    A m_data = A();\n    Note(const T& t,\
    \ const A& a) : T(t), m_data(a) {}\npublic:\n    using T::T;\n\n    static Note\
    \ make(const T& t, const A& a) {\n        return Note(t, a);\n    }\n\n    friend\
    \ A& annotation(Note& note) {\n        return note.m_data;\n    }\n    friend\
    \ const A& annotation(const Note& note) {\n        return note.m_data;\n    }\n\
    \n    template<typename C, typename D>\n    operator Note<T,A>() const {\n   \
    \     return Note<C, D>(*this, m_data);\n    }\n};\n\ntemplate <typename T>\n\
    struct Note<T, void> : public T {\n    using T::T;\n    using T::operator=;\n\
    \    \n    Note(const T& a) : T(a) {}\n    Note(T &&a): T(std::move(a)) {}\n};\n\
    \ntemplate<typename T, typename A>\nNote<T, A> make_note(const T& t, const A&\
    \ a) {\n    return Note<T, A>::make(t, a);\n}\n} // namespace lib\n\n\n#line 1\
    \ \"tests/catch.hpp\"\n/*\n *  Catch v2.13.2\n *  Generated: 2020-10-07 11:32:53.302017\n\
    \ *  ----------------------------------------------------------\n *  This file\
    \ has been merged from multiple headers. Please don't edit it directly\n *  Copyright\
    \ (c) 2020 Two Blue Cubes Ltd. All rights reserved.\n *\n *  Distributed under\
    \ the Boost Software License, Version 1.0. (See accompanying\n *  file LICENSE_1_0.txt\
    \ or copy at http://www.boost.org/LICENSE_1_0.txt)\n */\n#ifndef TWOBLUECUBES_SINGLE_INCLUDE_CATCH_HPP_INCLUDED\n\
    #define TWOBLUECUBES_SINGLE_INCLUDE_CATCH_HPP_INCLUDED\n// start catch.hpp\n\n\
    \n#define CATCH_VERSION_MAJOR 2\n#define CATCH_VERSION_MINOR 13\n#define CATCH_VERSION_PATCH\
    \ 2\n\n#ifdef __clang__\n#    pragma clang system_header\n#elif defined __GNUC__\n\
    #    pragma GCC system_header\n#endif\n\n// start catch_suppress_warnings.h\n\n\
    #ifdef __clang__\n#   ifdef __ICC // icpc defines the __clang__ macro\n#     \
    \  pragma warning(push)\n#       pragma warning(disable: 161 1682)\n#   else //\
    \ __ICC\n#       pragma clang diagnostic push\n#       pragma clang diagnostic\
    \ ignored \"-Wpadded\"\n#       pragma clang diagnostic ignored \"-Wswitch-enum\"\
    \n#       pragma clang diagnostic ignored \"-Wcovered-switch-default\"\n#    endif\n\
    #elif defined __GNUC__\n     // Because REQUIREs trigger GCC's -Wparentheses,\
    \ and because still\n     // supported version of g++ have only buggy support\
    \ for _Pragmas,\n     // Wparentheses have to be suppressed globally.\n#    pragma\
    \ GCC diagnostic ignored \"-Wparentheses\" // See #674 for details\n\n#    pragma\
    \ GCC diagnostic push\n#    pragma GCC diagnostic ignored \"-Wunused-variable\"\
    \n#    pragma GCC diagnostic ignored \"-Wpadded\"\n#endif\n// end catch_suppress_warnings.h\n\
    #if defined(CATCH_CONFIG_MAIN) || defined(CATCH_CONFIG_RUNNER)\n#  define CATCH_IMPL\n\
    #  define CATCH_CONFIG_ALL_PARTS\n#endif\n\n// In the impl file, we want to have\
    \ access to all parts of the headers\n// Can also be used to sanely support PCHs\n\
    #if defined(CATCH_CONFIG_ALL_PARTS)\n#  define CATCH_CONFIG_EXTERNAL_INTERFACES\n\
    #  if defined(CATCH_CONFIG_DISABLE_MATCHERS)\n#    undef CATCH_CONFIG_DISABLE_MATCHERS\n\
    #  endif\n#  if !defined(CATCH_CONFIG_ENABLE_CHRONO_STRINGMAKER)\n#    define\
    \ CATCH_CONFIG_ENABLE_CHRONO_STRINGMAKER\n#  endif\n#endif\n\n#if !defined(CATCH_CONFIG_IMPL_ONLY)\n\
    // start catch_platform.h\n\n#ifdef __APPLE__\n# include <TargetConditionals.h>\n\
    # if TARGET_OS_OSX == 1\n#  define CATCH_PLATFORM_MAC\n# elif TARGET_OS_IPHONE\
    \ == 1\n#  define CATCH_PLATFORM_IPHONE\n# endif\n\n#elif defined(linux) || defined(__linux)\
    \ || defined(__linux__)\n#  define CATCH_PLATFORM_LINUX\n\n#elif defined(WIN32)\
    \ || defined(__WIN32__) || defined(_WIN32) || defined(_MSC_VER) || defined(__MINGW32__)\n\
    #  define CATCH_PLATFORM_WINDOWS\n#endif\n\n// end catch_platform.h\n\n#ifdef\
    \ CATCH_IMPL\n#  ifndef CLARA_CONFIG_MAIN\n#    define CLARA_CONFIG_MAIN_NOT_DEFINED\n\
    #    define CLARA_CONFIG_MAIN\n#  endif\n#endif\n\n// start catch_user_interfaces.h\n\
    \nnamespace Catch {\n    unsigned int rngSeed();\n}\n\n// end catch_user_interfaces.h\n\
    // start catch_tag_alias_autoregistrar.h\n\n// start catch_common.h\n\n// start\
    \ catch_compiler_capabilities.h\n\n// Detect a number of compiler features - by\
    \ compiler\n// The following features are defined:\n//\n// CATCH_CONFIG_COUNTER\
    \ : is the __COUNTER__ macro supported?\n// CATCH_CONFIG_WINDOWS_SEH : is Windows\
    \ SEH supported?\n// CATCH_CONFIG_POSIX_SIGNALS : are POSIX signals supported?\n\
    // CATCH_CONFIG_DISABLE_EXCEPTIONS : Are exceptions enabled?\n// ****************\n\
    // Note to maintainers: if new toggles are added please document them\n// in configuration.md,\
    \ too\n// ****************\n\n// In general each macro has a _NO_<feature name>\
    \ form\n// (e.g. CATCH_CONFIG_NO_POSIX_SIGNALS) which disables the feature.\n\
    // Many features, at point of detection, define an _INTERNAL_ macro, so they\n\
    // can be combined, en-mass, with the _NO_ forms later.\n\n#ifdef __cplusplus\n\
    \n#  if (__cplusplus >= 201402L) || (defined(_MSVC_LANG) && _MSVC_LANG >= 201402L)\n\
    #    define CATCH_CPP14_OR_GREATER\n#  endif\n\n#  if (__cplusplus >= 201703L)\
    \ || (defined(_MSVC_LANG) && _MSVC_LANG >= 201703L)\n#    define CATCH_CPP17_OR_GREATER\n\
    #  endif\n\n#endif\n\n// We have to avoid both ICC and Clang, because they try\
    \ to mask themselves\n// as gcc, and we want only GCC in this block\n#if defined(__GNUC__)\
    \ && !defined(__clang__) && !defined(__ICC) && !defined(__CUDACC__)\n#    define\
    \ CATCH_INTERNAL_START_WARNINGS_SUPPRESSION _Pragma( \"GCC diagnostic push\" )\n\
    #    define CATCH_INTERNAL_STOP_WARNINGS_SUPPRESSION  _Pragma( \"GCC diagnostic\
    \ pop\" )\n\n#    define CATCH_INTERNAL_IGNORE_BUT_WARN(...) (void)__builtin_constant_p(__VA_ARGS__)\n\
    \n#endif\n\n#if defined(__clang__)\n\n#    define CATCH_INTERNAL_START_WARNINGS_SUPPRESSION\
    \ _Pragma( \"clang diagnostic push\" )\n#    define CATCH_INTERNAL_STOP_WARNINGS_SUPPRESSION\
    \  _Pragma( \"clang diagnostic pop\" )\n\n// As of this writing, IBM XL's implementation\
    \ of __builtin_constant_p has a bug\n// which results in calls to destructors\
    \ being emitted for each temporary,\n// without a matching initialization. In\
    \ practice, this can result in something\n// like `std::string::~string` being\
    \ called on an uninitialized value.\n//\n// For example, this code will likely\
    \ segfault under IBM XL:\n// ```\n// REQUIRE(std::string(\"12\") + \"34\" == \"\
    1234\")\n// ```\n//\n// Therefore, `CATCH_INTERNAL_IGNORE_BUT_WARN` is not implemented.\n\
    #  if !defined(__ibmxl__) && !defined(__CUDACC__)\n#    define CATCH_INTERNAL_IGNORE_BUT_WARN(...)\
    \ (void)__builtin_constant_p(__VA_ARGS__) /* NOLINT(cppcoreguidelines-pro-type-vararg,\
    \ hicpp-vararg) */\n#  endif\n\n#    define CATCH_INTERNAL_SUPPRESS_GLOBALS_WARNINGS\
    \ \\\n         _Pragma( \"clang diagnostic ignored \\\"-Wexit-time-destructors\\\
    \"\" ) \\\n         _Pragma( \"clang diagnostic ignored \\\"-Wglobal-constructors\\\
    \"\")\n\n#    define CATCH_INTERNAL_SUPPRESS_PARENTHESES_WARNINGS \\\n       \
    \  _Pragma( \"clang diagnostic ignored \\\"-Wparentheses\\\"\" )\n\n#    define\
    \ CATCH_INTERNAL_SUPPRESS_UNUSED_WARNINGS \\\n         _Pragma( \"clang diagnostic\
    \ ignored \\\"-Wunused-variable\\\"\" )\n\n#    define CATCH_INTERNAL_SUPPRESS_ZERO_VARIADIC_WARNINGS\
    \ \\\n         _Pragma( \"clang diagnostic ignored \\\"-Wgnu-zero-variadic-macro-arguments\\\
    \"\" )\n\n#    define CATCH_INTERNAL_SUPPRESS_UNUSED_TEMPLATE_WARNINGS \\\n  \
    \       _Pragma( \"clang diagnostic ignored \\\"-Wunused-template\\\"\" )\n\n\
    #endif // __clang__\n\n////////////////////////////////////////////////////////////////////////////////\n\
    // Assume that non-Windows platforms support posix signals by default\n#if !defined(CATCH_PLATFORM_WINDOWS)\n\
    \    #define CATCH_INTERNAL_CONFIG_POSIX_SIGNALS\n#endif\n\n////////////////////////////////////////////////////////////////////////////////\n\
    // We know some environments not to support full POSIX signals\n#if defined(__CYGWIN__)\
    \ || defined(__QNX__) || defined(__EMSCRIPTEN__) || defined(__DJGPP__)\n    #define\
    \ CATCH_INTERNAL_CONFIG_NO_POSIX_SIGNALS\n#endif\n\n#ifdef __OS400__\n#      \
    \ define CATCH_INTERNAL_CONFIG_NO_POSIX_SIGNALS\n#       define CATCH_CONFIG_COLOUR_NONE\n\
    #endif\n\n////////////////////////////////////////////////////////////////////////////////\n\
    // Android somehow still does not support std::to_string\n#if defined(__ANDROID__)\n\
    #    define CATCH_INTERNAL_CONFIG_NO_CPP11_TO_STRING\n#    define CATCH_INTERNAL_CONFIG_ANDROID_LOGWRITE\n\
    #endif\n\n////////////////////////////////////////////////////////////////////////////////\n\
    // Not all Windows environments support SEH properly\n#if defined(__MINGW32__)\n\
    #    define CATCH_INTERNAL_CONFIG_NO_WINDOWS_SEH\n#endif\n\n////////////////////////////////////////////////////////////////////////////////\n\
    // PS4\n#if defined(__ORBIS__)\n#    define CATCH_INTERNAL_CONFIG_NO_NEW_CAPTURE\n\
    #endif\n\n////////////////////////////////////////////////////////////////////////////////\n\
    // Cygwin\n#ifdef __CYGWIN__\n\n// Required for some versions of Cygwin to declare\
    \ gettimeofday\n// see: http://stackoverflow.com/questions/36901803/gettimeofday-not-declared-in-this-scope-cygwin\n\
    #   define _BSD_SOURCE\n// some versions of cygwin (most) do not support std::to_string.\
    \ Use the libstd check.\n// https://gcc.gnu.org/onlinedocs/gcc-4.8.2/libstdc++/api/a01053_source.html\
    \ line 2812-2813\n# if !((__cplusplus >= 201103L) && defined(_GLIBCXX_USE_C99)\
    \ \\\n           && !defined(_GLIBCXX_HAVE_BROKEN_VSWPRINTF))\n\n#    define CATCH_INTERNAL_CONFIG_NO_CPP11_TO_STRING\n\
    \n# endif\n#endif // __CYGWIN__\n\n////////////////////////////////////////////////////////////////////////////////\n\
    // Visual C++\n#if defined(_MSC_VER)\n\n#  define CATCH_INTERNAL_START_WARNINGS_SUPPRESSION\
    \ __pragma( warning(push) )\n#  define CATCH_INTERNAL_STOP_WARNINGS_SUPPRESSION\
    \  __pragma( warning(pop) )\n\n// Universal Windows platform does not support\
    \ SEH\n// Or console colours (or console at all...)\n#  if defined(WINAPI_FAMILY)\
    \ && (WINAPI_FAMILY == WINAPI_FAMILY_APP)\n#    define CATCH_CONFIG_COLOUR_NONE\n\
    #  else\n#    define CATCH_INTERNAL_CONFIG_WINDOWS_SEH\n#  endif\n\n// MSVC traditional\
    \ preprocessor needs some workaround for __VA_ARGS__\n// _MSVC_TRADITIONAL ==\
    \ 0 means new conformant preprocessor\n// _MSVC_TRADITIONAL == 1 means old traditional\
    \ non-conformant preprocessor\n#  if !defined(__clang__) // Handle Clang masquerading\
    \ for msvc\n#    if !defined(_MSVC_TRADITIONAL) || (defined(_MSVC_TRADITIONAL)\
    \ && _MSVC_TRADITIONAL)\n#      define CATCH_INTERNAL_CONFIG_TRADITIONAL_MSVC_PREPROCESSOR\n\
    #    endif // MSVC_TRADITIONAL\n#  endif // __clang__\n\n#endif // _MSC_VER\n\n\
    #if defined(_REENTRANT) || defined(_MSC_VER)\n// Enable async processing, as -pthread\
    \ is specified or no additional linking is required\n# define CATCH_INTERNAL_CONFIG_USE_ASYNC\n\
    #endif // _MSC_VER\n\n////////////////////////////////////////////////////////////////////////////////\n\
    // Check if we are compiled with -fno-exceptions or equivalent\n#if defined(__EXCEPTIONS)\
    \ || defined(__cpp_exceptions) || defined(_CPPUNWIND)\n#  define CATCH_INTERNAL_CONFIG_EXCEPTIONS_ENABLED\n\
    #endif\n\n////////////////////////////////////////////////////////////////////////////////\n\
    // DJGPP\n#ifdef __DJGPP__\n#  define CATCH_INTERNAL_CONFIG_NO_WCHAR\n#endif //\
    \ __DJGPP__\n\n////////////////////////////////////////////////////////////////////////////////\n\
    // Embarcadero C++Build\n#if defined(__BORLANDC__)\n    #define CATCH_INTERNAL_CONFIG_POLYFILL_ISNAN\n\
    #endif\n\n////////////////////////////////////////////////////////////////////////////////\n\
    \n// Use of __COUNTER__ is suppressed during code analysis in\n// CLion/AppCode\
    \ 2017.2.x and former, because __COUNTER__ is not properly\n// handled by it.\n\
    // Otherwise all supported compilers support COUNTER macro,\n// but user still\
    \ might want to turn it off\n#if ( !defined(__JETBRAINS_IDE__) || __JETBRAINS_IDE__\
    \ >= 20170300L )\n    #define CATCH_INTERNAL_CONFIG_COUNTER\n#endif\n\n////////////////////////////////////////////////////////////////////////////////\n\
    \n// RTX is a special version of Windows that is real time.\n// This means that\
    \ it is detected as Windows, but does not provide\n// the same set of capabilities\
    \ as real Windows does.\n#if defined(UNDER_RTSS) || defined(RTX64_BUILD)\n   \
    \ #define CATCH_INTERNAL_CONFIG_NO_WINDOWS_SEH\n    #define CATCH_INTERNAL_CONFIG_NO_ASYNC\n\
    \    #define CATCH_CONFIG_COLOUR_NONE\n#endif\n\n#if !defined(_GLIBCXX_USE_C99_MATH_TR1)\n\
    #define CATCH_INTERNAL_CONFIG_GLOBAL_NEXTAFTER\n#endif\n\n// Various stdlib support\
    \ checks that require __has_include\n#if defined(__has_include)\n  // Check if\
    \ string_view is available and usable\n  #if __has_include(<string_view>) && defined(CATCH_CPP17_OR_GREATER)\n\
    \  #    define CATCH_INTERNAL_CONFIG_CPP17_STRING_VIEW\n  #endif\n\n  // Check\
    \ if optional is available and usable\n  #  if __has_include(<optional>) && defined(CATCH_CPP17_OR_GREATER)\n\
    \  #    define CATCH_INTERNAL_CONFIG_CPP17_OPTIONAL\n  #  endif // __has_include(<optional>)\
    \ && defined(CATCH_CPP17_OR_GREATER)\n\n  // Check if byte is available and usable\n\
    \  #  if __has_include(<cstddef>) && defined(CATCH_CPP17_OR_GREATER)\n  #    include\
    \ <cstddef>\n  #    if __cpp_lib_byte > 0\n  #      define CATCH_INTERNAL_CONFIG_CPP17_BYTE\n\
    \  #    endif\n  #  endif // __has_include(<cstddef>) && defined(CATCH_CPP17_OR_GREATER)\n\
    \n  // Check if variant is available and usable\n  #  if __has_include(<variant>)\
    \ && defined(CATCH_CPP17_OR_GREATER)\n  #    if defined(__clang__) && (__clang_major__\
    \ < 8)\n         // work around clang bug with libstdc++ https://bugs.llvm.org/show_bug.cgi?id=31852\n\
    \         // fix should be in clang 8, workaround in libstdc++ 8.2\n  #      include\
    \ <ciso646>\n  #      if defined(__GLIBCXX__) && defined(_GLIBCXX_RELEASE) &&\
    \ (_GLIBCXX_RELEASE < 9)\n  #        define CATCH_CONFIG_NO_CPP17_VARIANT\n  #\
    \      else\n  #        define CATCH_INTERNAL_CONFIG_CPP17_VARIANT\n  #      endif\
    \ // defined(__GLIBCXX__) && defined(_GLIBCXX_RELEASE) && (_GLIBCXX_RELEASE <\
    \ 9)\n  #    else\n  #      define CATCH_INTERNAL_CONFIG_CPP17_VARIANT\n  #  \
    \  endif // defined(__clang__) && (__clang_major__ < 8)\n  #  endif // __has_include(<variant>)\
    \ && defined(CATCH_CPP17_OR_GREATER)\n#endif // defined(__has_include)\n\n#if\
    \ defined(CATCH_INTERNAL_CONFIG_COUNTER) && !defined(CATCH_CONFIG_NO_COUNTER)\
    \ && !defined(CATCH_CONFIG_COUNTER)\n#   define CATCH_CONFIG_COUNTER\n#endif\n\
    #if defined(CATCH_INTERNAL_CONFIG_WINDOWS_SEH) && !defined(CATCH_CONFIG_NO_WINDOWS_SEH)\
    \ && !defined(CATCH_CONFIG_WINDOWS_SEH) && !defined(CATCH_INTERNAL_CONFIG_NO_WINDOWS_SEH)\n\
    #   define CATCH_CONFIG_WINDOWS_SEH\n#endif\n// This is set by default, because\
    \ we assume that unix compilers are posix-signal-compatible by default.\n#if defined(CATCH_INTERNAL_CONFIG_POSIX_SIGNALS)\
    \ && !defined(CATCH_INTERNAL_CONFIG_NO_POSIX_SIGNALS) && !defined(CATCH_CONFIG_NO_POSIX_SIGNALS)\
    \ && !defined(CATCH_CONFIG_POSIX_SIGNALS)\n#   define CATCH_CONFIG_POSIX_SIGNALS\n\
    #endif\n// This is set by default, because we assume that compilers with no wchar_t\
    \ support are just rare exceptions.\n#if !defined(CATCH_INTERNAL_CONFIG_NO_WCHAR)\
    \ && !defined(CATCH_CONFIG_NO_WCHAR) && !defined(CATCH_CONFIG_WCHAR)\n#   define\
    \ CATCH_CONFIG_WCHAR\n#endif\n\n#if !defined(CATCH_INTERNAL_CONFIG_NO_CPP11_TO_STRING)\
    \ && !defined(CATCH_CONFIG_NO_CPP11_TO_STRING) && !defined(CATCH_CONFIG_CPP11_TO_STRING)\n\
    #    define CATCH_CONFIG_CPP11_TO_STRING\n#endif\n\n#if defined(CATCH_INTERNAL_CONFIG_CPP17_OPTIONAL)\
    \ && !defined(CATCH_CONFIG_NO_CPP17_OPTIONAL) && !defined(CATCH_CONFIG_CPP17_OPTIONAL)\n\
    #  define CATCH_CONFIG_CPP17_OPTIONAL\n#endif\n\n#if defined(CATCH_INTERNAL_CONFIG_CPP17_STRING_VIEW)\
    \ && !defined(CATCH_CONFIG_NO_CPP17_STRING_VIEW) && !defined(CATCH_CONFIG_CPP17_STRING_VIEW)\n\
    #  define CATCH_CONFIG_CPP17_STRING_VIEW\n#endif\n\n#if defined(CATCH_INTERNAL_CONFIG_CPP17_VARIANT)\
    \ && !defined(CATCH_CONFIG_NO_CPP17_VARIANT) && !defined(CATCH_CONFIG_CPP17_VARIANT)\n\
    #  define CATCH_CONFIG_CPP17_VARIANT\n#endif\n\n#if defined(CATCH_INTERNAL_CONFIG_CPP17_BYTE)\
    \ && !defined(CATCH_CONFIG_NO_CPP17_BYTE) && !defined(CATCH_CONFIG_CPP17_BYTE)\n\
    #  define CATCH_CONFIG_CPP17_BYTE\n#endif\n\n#if defined(CATCH_CONFIG_EXPERIMENTAL_REDIRECT)\n\
    #  define CATCH_INTERNAL_CONFIG_NEW_CAPTURE\n#endif\n\n#if defined(CATCH_INTERNAL_CONFIG_NEW_CAPTURE)\
    \ && !defined(CATCH_INTERNAL_CONFIG_NO_NEW_CAPTURE) && !defined(CATCH_CONFIG_NO_NEW_CAPTURE)\
    \ && !defined(CATCH_CONFIG_NEW_CAPTURE)\n#  define CATCH_CONFIG_NEW_CAPTURE\n\
    #endif\n\n#if !defined(CATCH_INTERNAL_CONFIG_EXCEPTIONS_ENABLED) && !defined(CATCH_CONFIG_DISABLE_EXCEPTIONS)\n\
    #  define CATCH_CONFIG_DISABLE_EXCEPTIONS\n#endif\n\n#if defined(CATCH_INTERNAL_CONFIG_POLYFILL_ISNAN)\
    \ && !defined(CATCH_CONFIG_NO_POLYFILL_ISNAN) && !defined(CATCH_CONFIG_POLYFILL_ISNAN)\n\
    #  define CATCH_CONFIG_POLYFILL_ISNAN\n#endif\n\n#if defined(CATCH_INTERNAL_CONFIG_USE_ASYNC)\
    \  && !defined(CATCH_INTERNAL_CONFIG_NO_ASYNC) && !defined(CATCH_CONFIG_NO_USE_ASYNC)\
    \ && !defined(CATCH_CONFIG_USE_ASYNC)\n#  define CATCH_CONFIG_USE_ASYNC\n#endif\n\
    \n#if defined(CATCH_INTERNAL_CONFIG_ANDROID_LOGWRITE) && !defined(CATCH_CONFIG_NO_ANDROID_LOGWRITE)\
    \ && !defined(CATCH_CONFIG_ANDROID_LOGWRITE)\n#  define CATCH_CONFIG_ANDROID_LOGWRITE\n\
    #endif\n\n#if defined(CATCH_INTERNAL_CONFIG_GLOBAL_NEXTAFTER) && !defined(CATCH_CONFIG_NO_GLOBAL_NEXTAFTER)\
    \ && !defined(CATCH_CONFIG_GLOBAL_NEXTAFTER)\n#  define CATCH_CONFIG_GLOBAL_NEXTAFTER\n\
    #endif\n\n// Even if we do not think the compiler has that warning, we still have\n\
    // to provide a macro that can be used by the code.\n#if !defined(CATCH_INTERNAL_START_WARNINGS_SUPPRESSION)\n\
    #   define CATCH_INTERNAL_START_WARNINGS_SUPPRESSION\n#endif\n#if !defined(CATCH_INTERNAL_STOP_WARNINGS_SUPPRESSION)\n\
    #   define CATCH_INTERNAL_STOP_WARNINGS_SUPPRESSION\n#endif\n#if !defined(CATCH_INTERNAL_SUPPRESS_PARENTHESES_WARNINGS)\n\
    #   define CATCH_INTERNAL_SUPPRESS_PARENTHESES_WARNINGS\n#endif\n#if !defined(CATCH_INTERNAL_SUPPRESS_GLOBALS_WARNINGS)\n\
    #   define CATCH_INTERNAL_SUPPRESS_GLOBALS_WARNINGS\n#endif\n#if !defined(CATCH_INTERNAL_SUPPRESS_UNUSED_WARNINGS)\n\
    #   define CATCH_INTERNAL_SUPPRESS_UNUSED_WARNINGS\n#endif\n#if !defined(CATCH_INTERNAL_SUPPRESS_ZERO_VARIADIC_WARNINGS)\n\
    #   define CATCH_INTERNAL_SUPPRESS_ZERO_VARIADIC_WARNINGS\n#endif\n\n// The goal\
    \ of this macro is to avoid evaluation of the arguments, but\n// still have the\
    \ compiler warn on problems inside...\n#if !defined(CATCH_INTERNAL_IGNORE_BUT_WARN)\n\
    #   define CATCH_INTERNAL_IGNORE_BUT_WARN(...)\n#endif\n\n#if defined(__APPLE__)\
    \ && defined(__apple_build_version__) && (__clang_major__ < 10)\n#   undef CATCH_INTERNAL_SUPPRESS_UNUSED_TEMPLATE_WARNINGS\n\
    #elif defined(__clang__) && (__clang_major__ < 5)\n#   undef CATCH_INTERNAL_SUPPRESS_UNUSED_TEMPLATE_WARNINGS\n\
    #endif\n\n#if !defined(CATCH_INTERNAL_SUPPRESS_UNUSED_TEMPLATE_WARNINGS)\n#  \
    \ define CATCH_INTERNAL_SUPPRESS_UNUSED_TEMPLATE_WARNINGS\n#endif\n\n#if defined(CATCH_CONFIG_DISABLE_EXCEPTIONS)\n\
    #define CATCH_TRY if ((true))\n#define CATCH_CATCH_ALL if ((false))\n#define CATCH_CATCH_ANON(type)\
    \ if ((false))\n#else\n#define CATCH_TRY try\n#define CATCH_CATCH_ALL catch (...)\n\
    #define CATCH_CATCH_ANON(type) catch (type)\n#endif\n\n#if defined(CATCH_INTERNAL_CONFIG_TRADITIONAL_MSVC_PREPROCESSOR)\
    \ && !defined(CATCH_CONFIG_NO_TRADITIONAL_MSVC_PREPROCESSOR) && !defined(CATCH_CONFIG_TRADITIONAL_MSVC_PREPROCESSOR)\n\
    #define CATCH_CONFIG_TRADITIONAL_MSVC_PREPROCESSOR\n#endif\n\n// end catch_compiler_capabilities.h\n\
    #define INTERNAL_CATCH_UNIQUE_NAME_LINE2( name, line ) name##line\n#define INTERNAL_CATCH_UNIQUE_NAME_LINE(\
    \ name, line ) INTERNAL_CATCH_UNIQUE_NAME_LINE2( name, line )\n#ifdef CATCH_CONFIG_COUNTER\n\
    #  define INTERNAL_CATCH_UNIQUE_NAME( name ) INTERNAL_CATCH_UNIQUE_NAME_LINE(\
    \ name, __COUNTER__ )\n#else\n#  define INTERNAL_CATCH_UNIQUE_NAME( name ) INTERNAL_CATCH_UNIQUE_NAME_LINE(\
    \ name, __LINE__ )\n#endif\n\n#include <iosfwd>\n#include <string>\n#include <cstdint>\n\
    \n// We need a dummy global operator<< so we can bring it into Catch namespace\
    \ later\nstruct Catch_global_namespace_dummy {};\nstd::ostream& operator<<(std::ostream&,\
    \ Catch_global_namespace_dummy);\n\nnamespace Catch {\n\n    struct CaseSensitive\
    \ { enum Choice {\n        Yes,\n        No\n    }; };\n\n    class NonCopyable\
    \ {\n        NonCopyable( NonCopyable const& )              = delete;\n      \
    \  NonCopyable( NonCopyable && )                  = delete;\n        NonCopyable&\
    \ operator = ( NonCopyable const& ) = delete;\n        NonCopyable& operator =\
    \ ( NonCopyable && )     = delete;\n\n    protected:\n        NonCopyable();\n\
    \        virtual ~NonCopyable();\n    };\n\n    struct SourceLineInfo {\n\n  \
    \      SourceLineInfo() = delete;\n        SourceLineInfo( char const* _file,\
    \ std::size_t _line ) noexcept\n        :   file( _file ),\n            line(\
    \ _line )\n        {}\n\n        SourceLineInfo( SourceLineInfo const& other )\
    \            = default;\n        SourceLineInfo& operator = ( SourceLineInfo const&\
    \ )     = default;\n        SourceLineInfo( SourceLineInfo&& )              noexcept\
    \ = default;\n        SourceLineInfo& operator = ( SourceLineInfo&& ) noexcept\
    \ = default;\n\n        bool empty() const noexcept { return file[0] == '\\0';\
    \ }\n        bool operator == ( SourceLineInfo const& other ) const noexcept;\n\
    \        bool operator < ( SourceLineInfo const& other ) const noexcept;\n\n \
    \       char const* file;\n        std::size_t line;\n    };\n\n    std::ostream&\
    \ operator << ( std::ostream& os, SourceLineInfo const& info );\n\n    // Bring\
    \ in operator<< from global namespace into Catch namespace\n    // This is necessary\
    \ because the overload of operator<< above makes\n    // lookup stop at namespace\
    \ Catch\n    using ::operator<<;\n\n    // Use this in variadic streaming macros\
    \ to allow\n    //    >> +StreamEndStop\n    // as well as\n    //    >> stuff\
    \ +StreamEndStop\n    struct StreamEndStop {\n        std::string operator+()\
    \ const;\n    };\n    template<typename T>\n    T const& operator + ( T const&\
    \ value, StreamEndStop ) {\n        return value;\n    }\n}\n\n#define CATCH_INTERNAL_LINEINFO\
    \ \\\n    ::Catch::SourceLineInfo( __FILE__, static_cast<std::size_t>( __LINE__\
    \ ) )\n\n// end catch_common.h\nnamespace Catch {\n\n    struct RegistrarForTagAliases\
    \ {\n        RegistrarForTagAliases( char const* alias, char const* tag, SourceLineInfo\
    \ const& lineInfo );\n    };\n\n} // end namespace Catch\n\n#define CATCH_REGISTER_TAG_ALIAS(\
    \ alias, spec ) \\\n    CATCH_INTERNAL_START_WARNINGS_SUPPRESSION \\\n    CATCH_INTERNAL_SUPPRESS_GLOBALS_WARNINGS\
    \ \\\n    namespace{ Catch::RegistrarForTagAliases INTERNAL_CATCH_UNIQUE_NAME(\
    \ AutoRegisterTagAlias )( alias, spec, CATCH_INTERNAL_LINEINFO ); } \\\n    CATCH_INTERNAL_STOP_WARNINGS_SUPPRESSION\n\
    \n// end catch_tag_alias_autoregistrar.h\n// start catch_test_registry.h\n\n//\
    \ start catch_interfaces_testcase.h\n\n#include <vector>\n\nnamespace Catch {\n\
    \n    class TestSpec;\n\n    struct ITestInvoker {\n        virtual void invoke\
    \ () const = 0;\n        virtual ~ITestInvoker();\n    };\n\n    class TestCase;\n\
    \    struct IConfig;\n\n    struct ITestCaseRegistry {\n        virtual ~ITestCaseRegistry();\n\
    \        virtual std::vector<TestCase> const& getAllTests() const = 0;\n     \
    \   virtual std::vector<TestCase> const& getAllTestsSorted( IConfig const& config\
    \ ) const = 0;\n    };\n\n    bool isThrowSafe( TestCase const& testCase, IConfig\
    \ const& config );\n    bool matchTest( TestCase const& testCase, TestSpec const&\
    \ testSpec, IConfig const& config );\n    std::vector<TestCase> filterTests( std::vector<TestCase>\
    \ const& testCases, TestSpec const& testSpec, IConfig const& config );\n    std::vector<TestCase>\
    \ const& getAllTestCasesSorted( IConfig const& config );\n\n}\n\n// end catch_interfaces_testcase.h\n\
    // start catch_stringref.h\n\n#include <cstddef>\n#include <string>\n#include\
    \ <iosfwd>\n#include <cassert>\n\nnamespace Catch {\n\n    /// A non-owning string\
    \ class (similar to the forthcoming std::string_view)\n    /// Note that, because\
    \ a StringRef may be a substring of another string,\n    /// it may not be null\
    \ terminated.\n    class StringRef {\n    public:\n        using size_type = std::size_t;\n\
    \        using const_iterator = const char*;\n\n    private:\n        static constexpr\
    \ char const* const s_empty = \"\";\n\n        char const* m_start = s_empty;\n\
    \        size_type m_size = 0;\n\n    public: // construction\n        constexpr\
    \ StringRef() noexcept = default;\n\n        StringRef( char const* rawChars )\
    \ noexcept;\n\n        constexpr StringRef( char const* rawChars, size_type size\
    \ ) noexcept\n        :   m_start( rawChars ),\n            m_size( size )\n \
    \       {}\n\n        StringRef( std::string const& stdString ) noexcept\n   \
    \     :   m_start( stdString.c_str() ),\n            m_size( stdString.size()\
    \ )\n        {}\n\n        explicit operator std::string() const {\n         \
    \   return std::string(m_start, m_size);\n        }\n\n    public: // operators\n\
    \        auto operator == ( StringRef const& other ) const noexcept -> bool;\n\
    \        auto operator != (StringRef const& other) const noexcept -> bool {\n\
    \            return !(*this == other);\n        }\n\n        auto operator[] (\
    \ size_type index ) const noexcept -> char {\n            assert(index < m_size);\n\
    \            return m_start[index];\n        }\n\n    public: // named queries\n\
    \        constexpr auto empty() const noexcept -> bool {\n            return m_size\
    \ == 0;\n        }\n        constexpr auto size() const noexcept -> size_type\
    \ {\n            return m_size;\n        }\n\n        // Returns the current start\
    \ pointer. If the StringRef is not\n        // null-terminated, throws std::domain_exception\n\
    \        auto c_str() const -> char const*;\n\n    public: // substrings and searches\n\
    \        // Returns a substring of [start, start + length).\n        // If start\
    \ + length > size(), then the substring is [start, size()).\n        // If start\
    \ > size(), then the substring is empty.\n        auto substr( size_type start,\
    \ size_type length ) const noexcept -> StringRef;\n\n        // Returns the current\
    \ start pointer. May not be null-terminated.\n        auto data() const noexcept\
    \ -> char const*;\n\n        constexpr auto isNullTerminated() const noexcept\
    \ -> bool {\n            return m_start[m_size] == '\\0';\n        }\n\n    public:\
    \ // iterators\n        constexpr const_iterator begin() const { return m_start;\
    \ }\n        constexpr const_iterator end() const { return m_start + m_size; }\n\
    \    };\n\n    auto operator += ( std::string& lhs, StringRef const& sr ) -> std::string&;\n\
    \    auto operator << ( std::ostream& os, StringRef const& sr ) -> std::ostream&;\n\
    \n    constexpr auto operator \"\" _sr( char const* rawChars, std::size_t size\
    \ ) noexcept -> StringRef {\n        return StringRef( rawChars, size );\n   \
    \ }\n} // namespace Catch\n\nconstexpr auto operator \"\" _catch_sr( char const*\
    \ rawChars, std::size_t size ) noexcept -> Catch::StringRef {\n    return Catch::StringRef(\
    \ rawChars, size );\n}\n\n// end catch_stringref.h\n// start catch_preprocessor.hpp\n\
    \n\n#define CATCH_RECURSION_LEVEL0(...) __VA_ARGS__\n#define CATCH_RECURSION_LEVEL1(...)\
    \ CATCH_RECURSION_LEVEL0(CATCH_RECURSION_LEVEL0(CATCH_RECURSION_LEVEL0(__VA_ARGS__)))\n\
    #define CATCH_RECURSION_LEVEL2(...) CATCH_RECURSION_LEVEL1(CATCH_RECURSION_LEVEL1(CATCH_RECURSION_LEVEL1(__VA_ARGS__)))\n\
    #define CATCH_RECURSION_LEVEL3(...) CATCH_RECURSION_LEVEL2(CATCH_RECURSION_LEVEL2(CATCH_RECURSION_LEVEL2(__VA_ARGS__)))\n\
    #define CATCH_RECURSION_LEVEL4(...) CATCH_RECURSION_LEVEL3(CATCH_RECURSION_LEVEL3(CATCH_RECURSION_LEVEL3(__VA_ARGS__)))\n\
    #define CATCH_RECURSION_LEVEL5(...) CATCH_RECURSION_LEVEL4(CATCH_RECURSION_LEVEL4(CATCH_RECURSION_LEVEL4(__VA_ARGS__)))\n\
    \n#ifdef CATCH_CONFIG_TRADITIONAL_MSVC_PREPROCESSOR\n#define INTERNAL_CATCH_EXPAND_VARGS(...)\
    \ __VA_ARGS__\n// MSVC needs more evaluations\n#define CATCH_RECURSION_LEVEL6(...)\
    \ CATCH_RECURSION_LEVEL5(CATCH_RECURSION_LEVEL5(CATCH_RECURSION_LEVEL5(__VA_ARGS__)))\n\
    #define CATCH_RECURSE(...)  CATCH_RECURSION_LEVEL6(CATCH_RECURSION_LEVEL6(__VA_ARGS__))\n\
    #else\n#define CATCH_RECURSE(...)  CATCH_RECURSION_LEVEL5(__VA_ARGS__)\n#endif\n\
    \n#define CATCH_REC_END(...)\n#define CATCH_REC_OUT\n\n#define CATCH_EMPTY()\n\
    #define CATCH_DEFER(id) id CATCH_EMPTY()\n\n#define CATCH_REC_GET_END2() 0, CATCH_REC_END\n\
    #define CATCH_REC_GET_END1(...) CATCH_REC_GET_END2\n#define CATCH_REC_GET_END(...)\
    \ CATCH_REC_GET_END1\n#define CATCH_REC_NEXT0(test, next, ...) next CATCH_REC_OUT\n\
    #define CATCH_REC_NEXT1(test, next) CATCH_DEFER ( CATCH_REC_NEXT0 ) ( test, next,\
    \ 0)\n#define CATCH_REC_NEXT(test, next)  CATCH_REC_NEXT1(CATCH_REC_GET_END test,\
    \ next)\n\n#define CATCH_REC_LIST0(f, x, peek, ...) , f(x) CATCH_DEFER ( CATCH_REC_NEXT(peek,\
    \ CATCH_REC_LIST1) ) ( f, peek, __VA_ARGS__ )\n#define CATCH_REC_LIST1(f, x, peek,\
    \ ...) , f(x) CATCH_DEFER ( CATCH_REC_NEXT(peek, CATCH_REC_LIST0) ) ( f, peek,\
    \ __VA_ARGS__ )\n#define CATCH_REC_LIST2(f, x, peek, ...)   f(x) CATCH_DEFER (\
    \ CATCH_REC_NEXT(peek, CATCH_REC_LIST1) ) ( f, peek, __VA_ARGS__ )\n\n#define\
    \ CATCH_REC_LIST0_UD(f, userdata, x, peek, ...) , f(userdata, x) CATCH_DEFER (\
    \ CATCH_REC_NEXT(peek, CATCH_REC_LIST1_UD) ) ( f, userdata, peek, __VA_ARGS__\
    \ )\n#define CATCH_REC_LIST1_UD(f, userdata, x, peek, ...) , f(userdata, x) CATCH_DEFER\
    \ ( CATCH_REC_NEXT(peek, CATCH_REC_LIST0_UD) ) ( f, userdata, peek, __VA_ARGS__\
    \ )\n#define CATCH_REC_LIST2_UD(f, userdata, x, peek, ...)   f(userdata, x) CATCH_DEFER\
    \ ( CATCH_REC_NEXT(peek, CATCH_REC_LIST1_UD) ) ( f, userdata, peek, __VA_ARGS__\
    \ )\n\n// Applies the function macro `f` to each of the remaining parameters,\
    \ inserts commas between the results,\n// and passes userdata as the first parameter\
    \ to each invocation,\n// e.g. CATCH_REC_LIST_UD(f, x, a, b, c) evaluates to f(x,\
    \ a), f(x, b), f(x, c)\n#define CATCH_REC_LIST_UD(f, userdata, ...) CATCH_RECURSE(CATCH_REC_LIST2_UD(f,\
    \ userdata, __VA_ARGS__, ()()(), ()()(), ()()(), 0))\n\n#define CATCH_REC_LIST(f,\
    \ ...) CATCH_RECURSE(CATCH_REC_LIST2(f, __VA_ARGS__, ()()(), ()()(), ()()(), 0))\n\
    \n#define INTERNAL_CATCH_EXPAND1(param) INTERNAL_CATCH_EXPAND2(param)\n#define\
    \ INTERNAL_CATCH_EXPAND2(...) INTERNAL_CATCH_NO## __VA_ARGS__\n#define INTERNAL_CATCH_DEF(...)\
    \ INTERNAL_CATCH_DEF __VA_ARGS__\n#define INTERNAL_CATCH_NOINTERNAL_CATCH_DEF\n\
    #define INTERNAL_CATCH_STRINGIZE(...) INTERNAL_CATCH_STRINGIZE2(__VA_ARGS__)\n\
    #ifndef CATCH_CONFIG_TRADITIONAL_MSVC_PREPROCESSOR\n#define INTERNAL_CATCH_STRINGIZE2(...)\
    \ #__VA_ARGS__\n#define INTERNAL_CATCH_STRINGIZE_WITHOUT_PARENS(param) INTERNAL_CATCH_STRINGIZE(INTERNAL_CATCH_REMOVE_PARENS(param))\n\
    #else\n// MSVC is adding extra space and needs another indirection to expand INTERNAL_CATCH_NOINTERNAL_CATCH_DEF\n\
    #define INTERNAL_CATCH_STRINGIZE2(...) INTERNAL_CATCH_STRINGIZE3(__VA_ARGS__)\n\
    #define INTERNAL_CATCH_STRINGIZE3(...) #__VA_ARGS__\n#define INTERNAL_CATCH_STRINGIZE_WITHOUT_PARENS(param)\
    \ (INTERNAL_CATCH_STRINGIZE(INTERNAL_CATCH_REMOVE_PARENS(param)) + 1)\n#endif\n\
    \n#define INTERNAL_CATCH_MAKE_NAMESPACE2(...) ns_##__VA_ARGS__\n#define INTERNAL_CATCH_MAKE_NAMESPACE(name)\
    \ INTERNAL_CATCH_MAKE_NAMESPACE2(name)\n\n#define INTERNAL_CATCH_REMOVE_PARENS(...)\
    \ INTERNAL_CATCH_EXPAND1(INTERNAL_CATCH_DEF __VA_ARGS__)\n\n#ifndef CATCH_CONFIG_TRADITIONAL_MSVC_PREPROCESSOR\n\
    #define INTERNAL_CATCH_MAKE_TYPE_LIST2(...) decltype(get_wrapper<INTERNAL_CATCH_REMOVE_PARENS_GEN(__VA_ARGS__)>())\n\
    #define INTERNAL_CATCH_MAKE_TYPE_LIST(...) INTERNAL_CATCH_MAKE_TYPE_LIST2(INTERNAL_CATCH_REMOVE_PARENS(__VA_ARGS__))\n\
    #else\n#define INTERNAL_CATCH_MAKE_TYPE_LIST2(...) INTERNAL_CATCH_EXPAND_VARGS(decltype(get_wrapper<INTERNAL_CATCH_REMOVE_PARENS_GEN(__VA_ARGS__)>()))\n\
    #define INTERNAL_CATCH_MAKE_TYPE_LIST(...) INTERNAL_CATCH_EXPAND_VARGS(INTERNAL_CATCH_MAKE_TYPE_LIST2(INTERNAL_CATCH_REMOVE_PARENS(__VA_ARGS__)))\n\
    #endif\n\n#define INTERNAL_CATCH_MAKE_TYPE_LISTS_FROM_TYPES(...)\\\n    CATCH_REC_LIST(INTERNAL_CATCH_MAKE_TYPE_LIST,__VA_ARGS__)\n\
    \n#define INTERNAL_CATCH_REMOVE_PARENS_1_ARG(_0) INTERNAL_CATCH_REMOVE_PARENS(_0)\n\
    #define INTERNAL_CATCH_REMOVE_PARENS_2_ARG(_0, _1) INTERNAL_CATCH_REMOVE_PARENS(_0),\
    \ INTERNAL_CATCH_REMOVE_PARENS_1_ARG(_1)\n#define INTERNAL_CATCH_REMOVE_PARENS_3_ARG(_0,\
    \ _1, _2) INTERNAL_CATCH_REMOVE_PARENS(_0), INTERNAL_CATCH_REMOVE_PARENS_2_ARG(_1,\
    \ _2)\n#define INTERNAL_CATCH_REMOVE_PARENS_4_ARG(_0, _1, _2, _3) INTERNAL_CATCH_REMOVE_PARENS(_0),\
    \ INTERNAL_CATCH_REMOVE_PARENS_3_ARG(_1, _2, _3)\n#define INTERNAL_CATCH_REMOVE_PARENS_5_ARG(_0,\
    \ _1, _2, _3, _4) INTERNAL_CATCH_REMOVE_PARENS(_0), INTERNAL_CATCH_REMOVE_PARENS_4_ARG(_1,\
    \ _2, _3, _4)\n#define INTERNAL_CATCH_REMOVE_PARENS_6_ARG(_0, _1, _2, _3, _4,\
    \ _5) INTERNAL_CATCH_REMOVE_PARENS(_0), INTERNAL_CATCH_REMOVE_PARENS_5_ARG(_1,\
    \ _2, _3, _4, _5)\n#define INTERNAL_CATCH_REMOVE_PARENS_7_ARG(_0, _1, _2, _3,\
    \ _4, _5, _6) INTERNAL_CATCH_REMOVE_PARENS(_0), INTERNAL_CATCH_REMOVE_PARENS_6_ARG(_1,\
    \ _2, _3, _4, _5, _6)\n#define INTERNAL_CATCH_REMOVE_PARENS_8_ARG(_0, _1, _2,\
    \ _3, _4, _5, _6, _7) INTERNAL_CATCH_REMOVE_PARENS(_0), INTERNAL_CATCH_REMOVE_PARENS_7_ARG(_1,\
    \ _2, _3, _4, _5, _6, _7)\n#define INTERNAL_CATCH_REMOVE_PARENS_9_ARG(_0, _1,\
    \ _2, _3, _4, _5, _6, _7, _8) INTERNAL_CATCH_REMOVE_PARENS(_0), INTERNAL_CATCH_REMOVE_PARENS_8_ARG(_1,\
    \ _2, _3, _4, _5, _6, _7, _8)\n#define INTERNAL_CATCH_REMOVE_PARENS_10_ARG(_0,\
    \ _1, _2, _3, _4, _5, _6, _7, _8, _9) INTERNAL_CATCH_REMOVE_PARENS(_0), INTERNAL_CATCH_REMOVE_PARENS_9_ARG(_1,\
    \ _2, _3, _4, _5, _6, _7, _8, _9)\n#define INTERNAL_CATCH_REMOVE_PARENS_11_ARG(_0,\
    \ _1, _2, _3, _4, _5, _6, _7, _8, _9, _10) INTERNAL_CATCH_REMOVE_PARENS(_0), INTERNAL_CATCH_REMOVE_PARENS_10_ARG(_1,\
    \ _2, _3, _4, _5, _6, _7, _8, _9, _10)\n\n#define INTERNAL_CATCH_VA_NARGS_IMPL(_0,\
    \ _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ...) N\n\n#define INTERNAL_CATCH_TYPE_GEN\\\
    \n    template<typename...> struct TypeList {};\\\n    template<typename...Ts>\\\
    \n    constexpr auto get_wrapper() noexcept -> TypeList<Ts...> { return {}; }\\\
    \n    template<template<typename...> class...> struct TemplateTypeList{};\\\n\
    \    template<template<typename...> class...Cs>\\\n    constexpr auto get_wrapper()\
    \ noexcept -> TemplateTypeList<Cs...> { return {}; }\\\n    template<typename...>\\\
    \n    struct append;\\\n    template<typename...>\\\n    struct rewrap;\\\n  \
    \  template<template<typename...> class, typename...>\\\n    struct create;\\\n\
    \    template<template<typename...> class, typename>\\\n    struct convert;\\\n\
    \    \\\n    template<typename T> \\\n    struct append<T> { using type = T; };\\\
    \n    template< template<typename...> class L1, typename...E1, template<typename...>\
    \ class L2, typename...E2, typename...Rest>\\\n    struct append<L1<E1...>, L2<E2...>,\
    \ Rest...> { using type = typename append<L1<E1...,E2...>, Rest...>::type; };\\\
    \n    template< template<typename...> class L1, typename...E1, typename...Rest>\\\
    \n    struct append<L1<E1...>, TypeList<mpl_::na>, Rest...> { using type = L1<E1...>;\
    \ };\\\n    \\\n    template< template<typename...> class Container, template<typename...>\
    \ class List, typename...elems>\\\n    struct rewrap<TemplateTypeList<Container>,\
    \ List<elems...>> { using type = TypeList<Container<elems...>>; };\\\n    template<\
    \ template<typename...> class Container, template<typename...> class List, class...Elems,\
    \ typename...Elements>\\\n    struct rewrap<TemplateTypeList<Container>, List<Elems...>,\
    \ Elements...> { using type = typename append<TypeList<Container<Elems...>>, typename\
    \ rewrap<TemplateTypeList<Container>, Elements...>::type>::type; };\\\n    \\\n\
    \    template<template <typename...> class Final, template< typename...> class...Containers,\
    \ typename...Types>\\\n    struct create<Final, TemplateTypeList<Containers...>,\
    \ TypeList<Types...>> { using type = typename append<Final<>, typename rewrap<TemplateTypeList<Containers>,\
    \ Types...>::type...>::type; };\\\n    template<template <typename...> class Final,\
    \ template <typename...> class List, typename...Ts>\\\n    struct convert<Final,\
    \ List<Ts...>> { using type = typename append<Final<>,TypeList<Ts>...>::type;\
    \ };\n\n#define INTERNAL_CATCH_NTTP_1(signature, ...)\\\n    template<INTERNAL_CATCH_REMOVE_PARENS(signature)>\
    \ struct Nttp{};\\\n    template<INTERNAL_CATCH_REMOVE_PARENS(signature)>\\\n\
    \    constexpr auto get_wrapper() noexcept -> Nttp<__VA_ARGS__> { return {}; }\
    \ \\\n    template<template<INTERNAL_CATCH_REMOVE_PARENS(signature)> class...>\
    \ struct NttpTemplateTypeList{};\\\n    template<template<INTERNAL_CATCH_REMOVE_PARENS(signature)>\
    \ class...Cs>\\\n    constexpr auto get_wrapper() noexcept -> NttpTemplateTypeList<Cs...>\
    \ { return {}; } \\\n    \\\n    template< template<INTERNAL_CATCH_REMOVE_PARENS(signature)>\
    \ class Container, template<INTERNAL_CATCH_REMOVE_PARENS(signature)> class List,\
    \ INTERNAL_CATCH_REMOVE_PARENS(signature)>\\\n    struct rewrap<NttpTemplateTypeList<Container>,\
    \ List<__VA_ARGS__>> { using type = TypeList<Container<__VA_ARGS__>>; };\\\n \
    \   template< template<INTERNAL_CATCH_REMOVE_PARENS(signature)> class Container,\
    \ template<INTERNAL_CATCH_REMOVE_PARENS(signature)> class List, INTERNAL_CATCH_REMOVE_PARENS(signature),\
    \ typename...Elements>\\\n    struct rewrap<NttpTemplateTypeList<Container>, List<__VA_ARGS__>,\
    \ Elements...> { using type = typename append<TypeList<Container<__VA_ARGS__>>,\
    \ typename rewrap<NttpTemplateTypeList<Container>, Elements...>::type>::type;\
    \ };\\\n    template<template <typename...> class Final, template<INTERNAL_CATCH_REMOVE_PARENS(signature)>\
    \ class...Containers, typename...Types>\\\n    struct create<Final, NttpTemplateTypeList<Containers...>,\
    \ TypeList<Types...>> { using type = typename append<Final<>, typename rewrap<NttpTemplateTypeList<Containers>,\
    \ Types...>::type...>::type; };\n\n#define INTERNAL_CATCH_DECLARE_SIG_TEST0(TestName)\n\
    #define INTERNAL_CATCH_DECLARE_SIG_TEST1(TestName, signature)\\\n    template<INTERNAL_CATCH_REMOVE_PARENS(signature)>\\\
    \n    static void TestName()\n#define INTERNAL_CATCH_DECLARE_SIG_TEST_X(TestName,\
    \ signature, ...)\\\n    template<INTERNAL_CATCH_REMOVE_PARENS(signature)>\\\n\
    \    static void TestName()\n\n#define INTERNAL_CATCH_DEFINE_SIG_TEST0(TestName)\n\
    #define INTERNAL_CATCH_DEFINE_SIG_TEST1(TestName, signature)\\\n    template<INTERNAL_CATCH_REMOVE_PARENS(signature)>\\\
    \n    static void TestName()\n#define INTERNAL_CATCH_DEFINE_SIG_TEST_X(TestName,\
    \ signature,...)\\\n    template<INTERNAL_CATCH_REMOVE_PARENS(signature)>\\\n\
    \    static void TestName()\n\n#define INTERNAL_CATCH_NTTP_REGISTER0(TestFunc,\
    \ signature)\\\n    template<typename Type>\\\n    void reg_test(TypeList<Type>,\
    \ Catch::NameAndTags nameAndTags)\\\n    {\\\n        Catch::AutoReg( Catch::makeTestInvoker(&TestFunc<Type>),\
    \ CATCH_INTERNAL_LINEINFO, Catch::StringRef(), nameAndTags);\\\n    }\n\n#define\
    \ INTERNAL_CATCH_NTTP_REGISTER(TestFunc, signature, ...)\\\n    template<INTERNAL_CATCH_REMOVE_PARENS(signature)>\\\
    \n    void reg_test(Nttp<__VA_ARGS__>, Catch::NameAndTags nameAndTags)\\\n   \
    \ {\\\n        Catch::AutoReg( Catch::makeTestInvoker(&TestFunc<__VA_ARGS__>),\
    \ CATCH_INTERNAL_LINEINFO, Catch::StringRef(), nameAndTags);\\\n    }\n\n#define\
    \ INTERNAL_CATCH_NTTP_REGISTER_METHOD0(TestName, signature, ...)\\\n    template<typename\
    \ Type>\\\n    void reg_test(TypeList<Type>, Catch::StringRef className, Catch::NameAndTags\
    \ nameAndTags)\\\n    {\\\n        Catch::AutoReg( Catch::makeTestInvoker(&TestName<Type>::test),\
    \ CATCH_INTERNAL_LINEINFO, className, nameAndTags);\\\n    }\n\n#define INTERNAL_CATCH_NTTP_REGISTER_METHOD(TestName,\
    \ signature, ...)\\\n    template<INTERNAL_CATCH_REMOVE_PARENS(signature)>\\\n\
    \    void reg_test(Nttp<__VA_ARGS__>, Catch::StringRef className, Catch::NameAndTags\
    \ nameAndTags)\\\n    {\\\n        Catch::AutoReg( Catch::makeTestInvoker(&TestName<__VA_ARGS__>::test),\
    \ CATCH_INTERNAL_LINEINFO, className, nameAndTags);\\\n    }\n\n#define INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD0(TestName,\
    \ ClassName)\n#define INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD1(TestName, ClassName,\
    \ signature)\\\n    template<typename TestType> \\\n    struct TestName : INTERNAL_CATCH_REMOVE_PARENS(ClassName)<TestType>\
    \ { \\\n        void test();\\\n    }\n\n#define INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD_X(TestName,\
    \ ClassName, signature, ...)\\\n    template<INTERNAL_CATCH_REMOVE_PARENS(signature)>\
    \ \\\n    struct TestName : INTERNAL_CATCH_REMOVE_PARENS(ClassName)<__VA_ARGS__>\
    \ { \\\n        void test();\\\n    }\n\n#define INTERNAL_CATCH_DEFINE_SIG_TEST_METHOD0(TestName)\n\
    #define INTERNAL_CATCH_DEFINE_SIG_TEST_METHOD1(TestName, signature)\\\n    template<typename\
    \ TestType> \\\n    void INTERNAL_CATCH_MAKE_NAMESPACE(TestName)::TestName<TestType>::test()\n\
    #define INTERNAL_CATCH_DEFINE_SIG_TEST_METHOD_X(TestName, signature, ...)\\\n\
    \    template<INTERNAL_CATCH_REMOVE_PARENS(signature)> \\\n    void INTERNAL_CATCH_MAKE_NAMESPACE(TestName)::TestName<__VA_ARGS__>::test()\n\
    \n#ifndef CATCH_CONFIG_TRADITIONAL_MSVC_PREPROCESSOR\n#define INTERNAL_CATCH_NTTP_0\n\
    #define INTERNAL_CATCH_NTTP_GEN(...) INTERNAL_CATCH_VA_NARGS_IMPL(__VA_ARGS__,\
    \ INTERNAL_CATCH_NTTP_1(__VA_ARGS__), INTERNAL_CATCH_NTTP_1(__VA_ARGS__), INTERNAL_CATCH_NTTP_1(__VA_ARGS__),\
    \ INTERNAL_CATCH_NTTP_1(__VA_ARGS__), INTERNAL_CATCH_NTTP_1(__VA_ARGS__), INTERNAL_CATCH_NTTP_1(\
    \ __VA_ARGS__), INTERNAL_CATCH_NTTP_1( __VA_ARGS__), INTERNAL_CATCH_NTTP_1( __VA_ARGS__),\
    \ INTERNAL_CATCH_NTTP_1( __VA_ARGS__),INTERNAL_CATCH_NTTP_1( __VA_ARGS__), INTERNAL_CATCH_NTTP_0)\n\
    #define INTERNAL_CATCH_DEFINE_SIG_TEST_METHOD(TestName, ...) INTERNAL_CATCH_VA_NARGS_IMPL(\
    \ \"dummy\", __VA_ARGS__, INTERNAL_CATCH_DEFINE_SIG_TEST_METHOD_X,INTERNAL_CATCH_DEFINE_SIG_TEST_METHOD_X,\
    \ INTERNAL_CATCH_DEFINE_SIG_TEST_METHOD_X, INTERNAL_CATCH_DEFINE_SIG_TEST_METHOD_X,\
    \ INTERNAL_CATCH_DEFINE_SIG_TEST_METHOD_X, INTERNAL_CATCH_DEFINE_SIG_TEST_METHOD_X,\
    \ INTERNAL_CATCH_DEFINE_SIG_TEST_METHOD_X,INTERNAL_CATCH_DEFINE_SIG_TEST_METHOD_X,INTERNAL_CATCH_DEFINE_SIG_TEST_METHOD_X,\
    \ INTERNAL_CATCH_DEFINE_SIG_TEST_METHOD1, INTERNAL_CATCH_DEFINE_SIG_TEST_METHOD0)(TestName,\
    \ __VA_ARGS__)\n#define INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD(TestName, ClassName,\
    \ ...) INTERNAL_CATCH_VA_NARGS_IMPL( \"dummy\", __VA_ARGS__, INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD_X,INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD_X,\
    \ INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD_X, INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD_X,\
    \ INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD_X, INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD_X,\
    \ INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD_X,INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD_X,INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD_X,\
    \ INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD1, INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD0)(TestName,\
    \ ClassName, __VA_ARGS__)\n#define INTERNAL_CATCH_NTTP_REG_METHOD_GEN(TestName,\
    \ ...) INTERNAL_CATCH_VA_NARGS_IMPL( \"dummy\", __VA_ARGS__, INTERNAL_CATCH_NTTP_REGISTER_METHOD,\
    \ INTERNAL_CATCH_NTTP_REGISTER_METHOD, INTERNAL_CATCH_NTTP_REGISTER_METHOD, INTERNAL_CATCH_NTTP_REGISTER_METHOD,\
    \ INTERNAL_CATCH_NTTP_REGISTER_METHOD, INTERNAL_CATCH_NTTP_REGISTER_METHOD, INTERNAL_CATCH_NTTP_REGISTER_METHOD,\
    \ INTERNAL_CATCH_NTTP_REGISTER_METHOD, INTERNAL_CATCH_NTTP_REGISTER_METHOD, INTERNAL_CATCH_NTTP_REGISTER_METHOD0,\
    \ INTERNAL_CATCH_NTTP_REGISTER_METHOD0)(TestName, __VA_ARGS__)\n#define INTERNAL_CATCH_NTTP_REG_GEN(TestFunc,\
    \ ...) INTERNAL_CATCH_VA_NARGS_IMPL( \"dummy\", __VA_ARGS__, INTERNAL_CATCH_NTTP_REGISTER,\
    \ INTERNAL_CATCH_NTTP_REGISTER, INTERNAL_CATCH_NTTP_REGISTER, INTERNAL_CATCH_NTTP_REGISTER,\
    \ INTERNAL_CATCH_NTTP_REGISTER, INTERNAL_CATCH_NTTP_REGISTER, INTERNAL_CATCH_NTTP_REGISTER,\
    \ INTERNAL_CATCH_NTTP_REGISTER, INTERNAL_CATCH_NTTP_REGISTER, INTERNAL_CATCH_NTTP_REGISTER0,\
    \ INTERNAL_CATCH_NTTP_REGISTER0)(TestFunc, __VA_ARGS__)\n#define INTERNAL_CATCH_DEFINE_SIG_TEST(TestName,\
    \ ...) INTERNAL_CATCH_VA_NARGS_IMPL( \"dummy\", __VA_ARGS__, INTERNAL_CATCH_DEFINE_SIG_TEST_X,\
    \ INTERNAL_CATCH_DEFINE_SIG_TEST_X, INTERNAL_CATCH_DEFINE_SIG_TEST_X, INTERNAL_CATCH_DEFINE_SIG_TEST_X,\
    \ INTERNAL_CATCH_DEFINE_SIG_TEST_X, INTERNAL_CATCH_DEFINE_SIG_TEST_X, INTERNAL_CATCH_DEFINE_SIG_TEST_X,\
    \ INTERNAL_CATCH_DEFINE_SIG_TEST_X,INTERNAL_CATCH_DEFINE_SIG_TEST_X,INTERNAL_CATCH_DEFINE_SIG_TEST1,\
    \ INTERNAL_CATCH_DEFINE_SIG_TEST0)(TestName, __VA_ARGS__)\n#define INTERNAL_CATCH_DECLARE_SIG_TEST(TestName,\
    \ ...) INTERNAL_CATCH_VA_NARGS_IMPL( \"dummy\", __VA_ARGS__, INTERNAL_CATCH_DECLARE_SIG_TEST_X,INTERNAL_CATCH_DECLARE_SIG_TEST_X,\
    \ INTERNAL_CATCH_DECLARE_SIG_TEST_X, INTERNAL_CATCH_DECLARE_SIG_TEST_X, INTERNAL_CATCH_DECLARE_SIG_TEST_X,\
    \ INTERNAL_CATCH_DECLARE_SIG_TEST_X, INTERNAL_CATCH_DEFINE_SIG_TEST_X,INTERNAL_CATCH_DECLARE_SIG_TEST_X,INTERNAL_CATCH_DECLARE_SIG_TEST_X,\
    \ INTERNAL_CATCH_DECLARE_SIG_TEST1, INTERNAL_CATCH_DECLARE_SIG_TEST0)(TestName,\
    \ __VA_ARGS__)\n#define INTERNAL_CATCH_REMOVE_PARENS_GEN(...) INTERNAL_CATCH_VA_NARGS_IMPL(__VA_ARGS__,\
    \ INTERNAL_CATCH_REMOVE_PARENS_11_ARG,INTERNAL_CATCH_REMOVE_PARENS_10_ARG,INTERNAL_CATCH_REMOVE_PARENS_9_ARG,INTERNAL_CATCH_REMOVE_PARENS_8_ARG,INTERNAL_CATCH_REMOVE_PARENS_7_ARG,INTERNAL_CATCH_REMOVE_PARENS_6_ARG,INTERNAL_CATCH_REMOVE_PARENS_5_ARG,INTERNAL_CATCH_REMOVE_PARENS_4_ARG,INTERNAL_CATCH_REMOVE_PARENS_3_ARG,INTERNAL_CATCH_REMOVE_PARENS_2_ARG,INTERNAL_CATCH_REMOVE_PARENS_1_ARG)(__VA_ARGS__)\n\
    #else\n#define INTERNAL_CATCH_NTTP_0(signature)\n#define INTERNAL_CATCH_NTTP_GEN(...)\
    \ INTERNAL_CATCH_EXPAND_VARGS(INTERNAL_CATCH_VA_NARGS_IMPL(__VA_ARGS__, INTERNAL_CATCH_NTTP_1,\
    \ INTERNAL_CATCH_NTTP_1, INTERNAL_CATCH_NTTP_1, INTERNAL_CATCH_NTTP_1, INTERNAL_CATCH_NTTP_1,\
    \ INTERNAL_CATCH_NTTP_1, INTERNAL_CATCH_NTTP_1, INTERNAL_CATCH_NTTP_1, INTERNAL_CATCH_NTTP_1,INTERNAL_CATCH_NTTP_1,\
    \ INTERNAL_CATCH_NTTP_0)( __VA_ARGS__))\n#define INTERNAL_CATCH_DEFINE_SIG_TEST_METHOD(TestName,\
    \ ...) INTERNAL_CATCH_EXPAND_VARGS(INTERNAL_CATCH_VA_NARGS_IMPL( \"dummy\", __VA_ARGS__,\
    \ INTERNAL_CATCH_DEFINE_SIG_TEST_METHOD_X,INTERNAL_CATCH_DEFINE_SIG_TEST_METHOD_X,\
    \ INTERNAL_CATCH_DEFINE_SIG_TEST_METHOD_X, INTERNAL_CATCH_DEFINE_SIG_TEST_METHOD_X,\
    \ INTERNAL_CATCH_DEFINE_SIG_TEST_METHOD_X, INTERNAL_CATCH_DEFINE_SIG_TEST_METHOD_X,\
    \ INTERNAL_CATCH_DEFINE_SIG_TEST_METHOD_X,INTERNAL_CATCH_DEFINE_SIG_TEST_METHOD_X,INTERNAL_CATCH_DEFINE_SIG_TEST_METHOD_X,\
    \ INTERNAL_CATCH_DEFINE_SIG_TEST_METHOD1, INTERNAL_CATCH_DEFINE_SIG_TEST_METHOD0)(TestName,\
    \ __VA_ARGS__))\n#define INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD(TestName, ClassName,\
    \ ...) INTERNAL_CATCH_EXPAND_VARGS(INTERNAL_CATCH_VA_NARGS_IMPL( \"dummy\", __VA_ARGS__,\
    \ INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD_X,INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD_X,\
    \ INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD_X, INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD_X,\
    \ INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD_X, INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD_X,\
    \ INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD_X,INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD_X,INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD_X,\
    \ INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD1, INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD0)(TestName,\
    \ ClassName, __VA_ARGS__))\n#define INTERNAL_CATCH_NTTP_REG_METHOD_GEN(TestName,\
    \ ...) INTERNAL_CATCH_EXPAND_VARGS(INTERNAL_CATCH_VA_NARGS_IMPL( \"dummy\", __VA_ARGS__,\
    \ INTERNAL_CATCH_NTTP_REGISTER_METHOD, INTERNAL_CATCH_NTTP_REGISTER_METHOD, INTERNAL_CATCH_NTTP_REGISTER_METHOD,\
    \ INTERNAL_CATCH_NTTP_REGISTER_METHOD, INTERNAL_CATCH_NTTP_REGISTER_METHOD, INTERNAL_CATCH_NTTP_REGISTER_METHOD,\
    \ INTERNAL_CATCH_NTTP_REGISTER_METHOD, INTERNAL_CATCH_NTTP_REGISTER_METHOD, INTERNAL_CATCH_NTTP_REGISTER_METHOD,\
    \ INTERNAL_CATCH_NTTP_REGISTER_METHOD0, INTERNAL_CATCH_NTTP_REGISTER_METHOD0)(TestName,\
    \ __VA_ARGS__))\n#define INTERNAL_CATCH_NTTP_REG_GEN(TestFunc, ...) INTERNAL_CATCH_EXPAND_VARGS(INTERNAL_CATCH_VA_NARGS_IMPL(\
    \ \"dummy\", __VA_ARGS__, INTERNAL_CATCH_NTTP_REGISTER, INTERNAL_CATCH_NTTP_REGISTER,\
    \ INTERNAL_CATCH_NTTP_REGISTER, INTERNAL_CATCH_NTTP_REGISTER, INTERNAL_CATCH_NTTP_REGISTER,\
    \ INTERNAL_CATCH_NTTP_REGISTER, INTERNAL_CATCH_NTTP_REGISTER, INTERNAL_CATCH_NTTP_REGISTER,\
    \ INTERNAL_CATCH_NTTP_REGISTER, INTERNAL_CATCH_NTTP_REGISTER0, INTERNAL_CATCH_NTTP_REGISTER0)(TestFunc,\
    \ __VA_ARGS__))\n#define INTERNAL_CATCH_DEFINE_SIG_TEST(TestName, ...) INTERNAL_CATCH_EXPAND_VARGS(INTERNAL_CATCH_VA_NARGS_IMPL(\
    \ \"dummy\", __VA_ARGS__, INTERNAL_CATCH_DEFINE_SIG_TEST_X, INTERNAL_CATCH_DEFINE_SIG_TEST_X,\
    \ INTERNAL_CATCH_DEFINE_SIG_TEST_X, INTERNAL_CATCH_DEFINE_SIG_TEST_X, INTERNAL_CATCH_DEFINE_SIG_TEST_X,\
    \ INTERNAL_CATCH_DEFINE_SIG_TEST_X, INTERNAL_CATCH_DEFINE_SIG_TEST_X, INTERNAL_CATCH_DEFINE_SIG_TEST_X,INTERNAL_CATCH_DEFINE_SIG_TEST_X,INTERNAL_CATCH_DEFINE_SIG_TEST1,\
    \ INTERNAL_CATCH_DEFINE_SIG_TEST0)(TestName, __VA_ARGS__))\n#define INTERNAL_CATCH_DECLARE_SIG_TEST(TestName,\
    \ ...) INTERNAL_CATCH_EXPAND_VARGS(INTERNAL_CATCH_VA_NARGS_IMPL( \"dummy\", __VA_ARGS__,\
    \ INTERNAL_CATCH_DECLARE_SIG_TEST_X,INTERNAL_CATCH_DECLARE_SIG_TEST_X, INTERNAL_CATCH_DECLARE_SIG_TEST_X,\
    \ INTERNAL_CATCH_DECLARE_SIG_TEST_X, INTERNAL_CATCH_DECLARE_SIG_TEST_X, INTERNAL_CATCH_DECLARE_SIG_TEST_X,\
    \ INTERNAL_CATCH_DEFINE_SIG_TEST_X,INTERNAL_CATCH_DECLARE_SIG_TEST_X,INTERNAL_CATCH_DECLARE_SIG_TEST_X,\
    \ INTERNAL_CATCH_DECLARE_SIG_TEST1, INTERNAL_CATCH_DECLARE_SIG_TEST0)(TestName,\
    \ __VA_ARGS__))\n#define INTERNAL_CATCH_REMOVE_PARENS_GEN(...) INTERNAL_CATCH_EXPAND_VARGS(INTERNAL_CATCH_VA_NARGS_IMPL(__VA_ARGS__,\
    \ INTERNAL_CATCH_REMOVE_PARENS_11_ARG,INTERNAL_CATCH_REMOVE_PARENS_10_ARG,INTERNAL_CATCH_REMOVE_PARENS_9_ARG,INTERNAL_CATCH_REMOVE_PARENS_8_ARG,INTERNAL_CATCH_REMOVE_PARENS_7_ARG,INTERNAL_CATCH_REMOVE_PARENS_6_ARG,INTERNAL_CATCH_REMOVE_PARENS_5_ARG,INTERNAL_CATCH_REMOVE_PARENS_4_ARG,INTERNAL_CATCH_REMOVE_PARENS_3_ARG,INTERNAL_CATCH_REMOVE_PARENS_2_ARG,INTERNAL_CATCH_REMOVE_PARENS_1_ARG)(__VA_ARGS__))\n\
    #endif\n\n// end catch_preprocessor.hpp\n// start catch_meta.hpp\n\n\n#include\
    \ <type_traits>\n\nnamespace Catch {\n    template<typename T>\n    struct always_false\
    \ : std::false_type {};\n\n    template <typename> struct true_given : std::true_type\
    \ {};\n    struct is_callable_tester {\n        template <typename Fun, typename...\
    \ Args>\n        true_given<decltype(std::declval<Fun>()(std::declval<Args>()...))>\
    \ static test(int);\n        template <typename...>\n        std::false_type static\
    \ test(...);\n    };\n\n    template <typename T>\n    struct is_callable;\n\n\
    \    template <typename Fun, typename... Args>\n    struct is_callable<Fun(Args...)>\
    \ : decltype(is_callable_tester::test<Fun, Args...>(0)) {};\n\n#if defined(__cpp_lib_is_invocable)\
    \ && __cpp_lib_is_invocable >= 201703\n    // std::result_of is deprecated in\
    \ C++17 and removed in C++20. Hence, it is\n    // replaced with std::invoke_result\
    \ here.\n    template <typename Func, typename... U>\n    using FunctionReturnType\
    \ = std::remove_reference_t<std::remove_cv_t<std::invoke_result_t<Func, U...>>>;\n\
    #else\n    // Keep ::type here because we still support C++11\n    template <typename\
    \ Func, typename... U>\n    using FunctionReturnType = typename std::remove_reference<typename\
    \ std::remove_cv<typename std::result_of<Func(U...)>::type>::type>::type;\n#endif\n\
    \n} // namespace Catch\n\nnamespace mpl_{\n    struct na;\n}\n\n// end catch_meta.hpp\n\
    namespace Catch {\n\ntemplate<typename C>\nclass TestInvokerAsMethod : public\
    \ ITestInvoker {\n    void (C::*m_testAsMethod)();\npublic:\n    TestInvokerAsMethod(\
    \ void (C::*testAsMethod)() ) noexcept : m_testAsMethod( testAsMethod ) {}\n\n\
    \    void invoke() const override {\n        C obj;\n        (obj.*m_testAsMethod)();\n\
    \    }\n};\n\nauto makeTestInvoker( void(*testAsFunction)() ) noexcept -> ITestInvoker*;\n\
    \ntemplate<typename C>\nauto makeTestInvoker( void (C::*testAsMethod)() ) noexcept\
    \ -> ITestInvoker* {\n    return new(std::nothrow) TestInvokerAsMethod<C>( testAsMethod\
    \ );\n}\n\nstruct NameAndTags {\n    NameAndTags( StringRef const& name_ = StringRef(),\
    \ StringRef const& tags_ = StringRef() ) noexcept;\n    StringRef name;\n    StringRef\
    \ tags;\n};\n\nstruct AutoReg : NonCopyable {\n    AutoReg( ITestInvoker* invoker,\
    \ SourceLineInfo const& lineInfo, StringRef const& classOrMethod, NameAndTags\
    \ const& nameAndTags ) noexcept;\n    ~AutoReg();\n};\n\n} // end namespace Catch\n\
    \n#if defined(CATCH_CONFIG_DISABLE)\n    #define INTERNAL_CATCH_TESTCASE_NO_REGISTRATION(\
    \ TestName, ... ) \\\n        static void TestName()\n    #define INTERNAL_CATCH_TESTCASE_METHOD_NO_REGISTRATION(\
    \ TestName, ClassName, ... ) \\\n        namespace{                        \\\n\
    \            struct TestName : INTERNAL_CATCH_REMOVE_PARENS(ClassName) { \\\n\
    \                void test();              \\\n            };                \
    \            \\\n        }                                 \\\n        void TestName::test()\n\
    \    #define INTERNAL_CATCH_TEMPLATE_TEST_CASE_NO_REGISTRATION_2( TestName, TestFunc,\
    \ Name, Tags, Signature, ... )  \\\n        INTERNAL_CATCH_DEFINE_SIG_TEST(TestFunc,\
    \ INTERNAL_CATCH_REMOVE_PARENS(Signature))\n    #define INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD_NO_REGISTRATION_2(\
    \ TestNameClass, TestName, ClassName, Name, Tags, Signature, ... )    \\\n   \
    \     namespace{                                                             \
    \                     \\\n            namespace INTERNAL_CATCH_MAKE_NAMESPACE(TestName)\
    \ {                                      \\\n            INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD(TestName,\
    \ ClassName, INTERNAL_CATCH_REMOVE_PARENS(Signature));\\\n        }          \
    \                                                                            \
    \     \\\n        }                                                          \
    \                                 \\\n        INTERNAL_CATCH_DEFINE_SIG_TEST_METHOD(TestName,\
    \ INTERNAL_CATCH_REMOVE_PARENS(Signature))\n\n    #ifndef CATCH_CONFIG_TRADITIONAL_MSVC_PREPROCESSOR\n\
    \        #define INTERNAL_CATCH_TEMPLATE_TEST_CASE_NO_REGISTRATION(Name, Tags,\
    \ ...) \\\n            INTERNAL_CATCH_TEMPLATE_TEST_CASE_NO_REGISTRATION_2( INTERNAL_CATCH_UNIQUE_NAME(\
    \ ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____ ), INTERNAL_CATCH_UNIQUE_NAME(\
    \ ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____F_U_N_C____ ), Name, Tags, typename\
    \ TestType, __VA_ARGS__ )\n    #else\n        #define INTERNAL_CATCH_TEMPLATE_TEST_CASE_NO_REGISTRATION(Name,\
    \ Tags, ...) \\\n            INTERNAL_CATCH_EXPAND_VARGS( INTERNAL_CATCH_TEMPLATE_TEST_CASE_NO_REGISTRATION_2(\
    \ INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____\
    \ ), INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____F_U_N_C____\
    \ ), Name, Tags, typename TestType, __VA_ARGS__ ) )\n    #endif\n\n    #ifndef\
    \ CATCH_CONFIG_TRADITIONAL_MSVC_PREPROCESSOR\n        #define INTERNAL_CATCH_TEMPLATE_TEST_CASE_SIG_NO_REGISTRATION(Name,\
    \ Tags, Signature, ...) \\\n            INTERNAL_CATCH_TEMPLATE_TEST_CASE_NO_REGISTRATION_2(\
    \ INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____\
    \ ), INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____F_U_N_C____\
    \ ), Name, Tags, Signature, __VA_ARGS__ )\n    #else\n        #define INTERNAL_CATCH_TEMPLATE_TEST_CASE_SIG_NO_REGISTRATION(Name,\
    \ Tags, Signature, ...) \\\n            INTERNAL_CATCH_EXPAND_VARGS( INTERNAL_CATCH_TEMPLATE_TEST_CASE_NO_REGISTRATION_2(\
    \ INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____\
    \ ), INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____F_U_N_C____\
    \ ), Name, Tags, Signature, __VA_ARGS__ ) )\n    #endif\n\n    #ifndef CATCH_CONFIG_TRADITIONAL_MSVC_PREPROCESSOR\n\
    \        #define INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD_NO_REGISTRATION( ClassName,\
    \ Name, Tags,... ) \\\n            INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD_NO_REGISTRATION_2(\
    \ INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____C_L_A_S_S____\
    \ ), INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____\
    \ ) , ClassName, Name, Tags, typename T, __VA_ARGS__ )\n    #else\n        #define\
    \ INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD_NO_REGISTRATION( ClassName, Name, Tags,...\
    \ ) \\\n            INTERNAL_CATCH_EXPAND_VARGS( INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD_NO_REGISTRATION_2(\
    \ INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____C_L_A_S_S____\
    \ ), INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____\
    \ ) , ClassName, Name, Tags, typename T, __VA_ARGS__ ) )\n    #endif\n\n    #ifndef\
    \ CATCH_CONFIG_TRADITIONAL_MSVC_PREPROCESSOR\n        #define INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD_SIG_NO_REGISTRATION(\
    \ ClassName, Name, Tags, Signature, ... ) \\\n            INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD_NO_REGISTRATION_2(\
    \ INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____C_L_A_S_S____\
    \ ), INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____\
    \ ) , ClassName, Name, Tags, Signature, __VA_ARGS__ )\n    #else\n        #define\
    \ INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD_SIG_NO_REGISTRATION( ClassName, Name,\
    \ Tags, Signature, ... ) \\\n            INTERNAL_CATCH_EXPAND_VARGS( INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD_NO_REGISTRATION_2(\
    \ INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____C_L_A_S_S____\
    \ ), INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____\
    \ ) , ClassName, Name, Tags, Signature, __VA_ARGS__ ) )\n    #endif\n#endif\n\n\
    \    ///////////////////////////////////////////////////////////////////////////////\n\
    \    #define INTERNAL_CATCH_TESTCASE2( TestName, ... ) \\\n        static void\
    \ TestName(); \\\n        CATCH_INTERNAL_START_WARNINGS_SUPPRESSION \\\n     \
    \   CATCH_INTERNAL_SUPPRESS_GLOBALS_WARNINGS \\\n        namespace{ Catch::AutoReg\
    \ INTERNAL_CATCH_UNIQUE_NAME( autoRegistrar )( Catch::makeTestInvoker( &TestName\
    \ ), CATCH_INTERNAL_LINEINFO, Catch::StringRef(), Catch::NameAndTags{ __VA_ARGS__\
    \ } ); } /* NOLINT */ \\\n        CATCH_INTERNAL_STOP_WARNINGS_SUPPRESSION \\\n\
    \        static void TestName()\n    #define INTERNAL_CATCH_TESTCASE( ... ) \\\
    \n        INTERNAL_CATCH_TESTCASE2( INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_S_T____\
    \ ), __VA_ARGS__ )\n\n    ///////////////////////////////////////////////////////////////////////////////\n\
    \    #define INTERNAL_CATCH_METHOD_AS_TEST_CASE( QualifiedMethod, ... ) \\\n \
    \       CATCH_INTERNAL_START_WARNINGS_SUPPRESSION \\\n        CATCH_INTERNAL_SUPPRESS_GLOBALS_WARNINGS\
    \ \\\n        namespace{ Catch::AutoReg INTERNAL_CATCH_UNIQUE_NAME( autoRegistrar\
    \ )( Catch::makeTestInvoker( &QualifiedMethod ), CATCH_INTERNAL_LINEINFO, \"&\"\
    \ #QualifiedMethod, Catch::NameAndTags{ __VA_ARGS__ } ); } /* NOLINT */ \\\n \
    \       CATCH_INTERNAL_STOP_WARNINGS_SUPPRESSION\n\n    ///////////////////////////////////////////////////////////////////////////////\n\
    \    #define INTERNAL_CATCH_TEST_CASE_METHOD2( TestName, ClassName, ... )\\\n\
    \        CATCH_INTERNAL_START_WARNINGS_SUPPRESSION \\\n        CATCH_INTERNAL_SUPPRESS_GLOBALS_WARNINGS\
    \ \\\n        namespace{ \\\n            struct TestName : INTERNAL_CATCH_REMOVE_PARENS(ClassName)\
    \ { \\\n                void test(); \\\n            }; \\\n            Catch::AutoReg\
    \ INTERNAL_CATCH_UNIQUE_NAME( autoRegistrar ) ( Catch::makeTestInvoker( &TestName::test\
    \ ), CATCH_INTERNAL_LINEINFO, #ClassName, Catch::NameAndTags{ __VA_ARGS__ } );\
    \ /* NOLINT */ \\\n        } \\\n        CATCH_INTERNAL_STOP_WARNINGS_SUPPRESSION\
    \ \\\n        void TestName::test()\n    #define INTERNAL_CATCH_TEST_CASE_METHOD(\
    \ ClassName, ... ) \\\n        INTERNAL_CATCH_TEST_CASE_METHOD2( INTERNAL_CATCH_UNIQUE_NAME(\
    \ ____C_A_T_C_H____T_E_S_T____ ), ClassName, __VA_ARGS__ )\n\n    ///////////////////////////////////////////////////////////////////////////////\n\
    \    #define INTERNAL_CATCH_REGISTER_TESTCASE( Function, ... ) \\\n        CATCH_INTERNAL_START_WARNINGS_SUPPRESSION\
    \ \\\n        CATCH_INTERNAL_SUPPRESS_GLOBALS_WARNINGS \\\n        Catch::AutoReg\
    \ INTERNAL_CATCH_UNIQUE_NAME( autoRegistrar )( Catch::makeTestInvoker( Function\
    \ ), CATCH_INTERNAL_LINEINFO, Catch::StringRef(), Catch::NameAndTags{ __VA_ARGS__\
    \ } ); /* NOLINT */ \\\n        CATCH_INTERNAL_STOP_WARNINGS_SUPPRESSION\n\n \
    \   ///////////////////////////////////////////////////////////////////////////////\n\
    \    #define INTERNAL_CATCH_TEMPLATE_TEST_CASE_2(TestName, TestFunc, Name, Tags,\
    \ Signature, ... )\\\n        CATCH_INTERNAL_START_WARNINGS_SUPPRESSION \\\n \
    \       CATCH_INTERNAL_SUPPRESS_GLOBALS_WARNINGS \\\n        CATCH_INTERNAL_SUPPRESS_ZERO_VARIADIC_WARNINGS\
    \ \\\n        CATCH_INTERNAL_SUPPRESS_UNUSED_TEMPLATE_WARNINGS \\\n        INTERNAL_CATCH_DECLARE_SIG_TEST(TestFunc,\
    \ INTERNAL_CATCH_REMOVE_PARENS(Signature));\\\n        namespace {\\\n       \
    \ namespace INTERNAL_CATCH_MAKE_NAMESPACE(TestName){\\\n            INTERNAL_CATCH_TYPE_GEN\\\
    \n            INTERNAL_CATCH_NTTP_GEN(INTERNAL_CATCH_REMOVE_PARENS(Signature))\\\
    \n            INTERNAL_CATCH_NTTP_REG_GEN(TestFunc,INTERNAL_CATCH_REMOVE_PARENS(Signature))\\\
    \n            template<typename...Types> \\\n            struct TestName{\\\n\
    \                TestName(){\\\n                    int index = 0;           \
    \                         \\\n                    constexpr char const* tmpl_types[]\
    \ = {CATCH_REC_LIST(INTERNAL_CATCH_STRINGIZE_WITHOUT_PARENS, __VA_ARGS__)};\\\n\
    \                    using expander = int[];\\\n                    (void)expander{(reg_test(Types{},\
    \ Catch::NameAndTags{ Name \" - \" + std::string(tmpl_types[index]), Tags } ),\
    \ index++)... };/* NOLINT */ \\\n                }\\\n            };\\\n     \
    \       static int INTERNAL_CATCH_UNIQUE_NAME( globalRegistrar ) = [](){\\\n \
    \           TestName<INTERNAL_CATCH_MAKE_TYPE_LISTS_FROM_TYPES(__VA_ARGS__)>();\\\
    \n            return 0;\\\n        }();\\\n        }\\\n        }\\\n        CATCH_INTERNAL_STOP_WARNINGS_SUPPRESSION\
    \ \\\n        INTERNAL_CATCH_DEFINE_SIG_TEST(TestFunc,INTERNAL_CATCH_REMOVE_PARENS(Signature))\n\
    \n#ifndef CATCH_CONFIG_TRADITIONAL_MSVC_PREPROCESSOR\n    #define INTERNAL_CATCH_TEMPLATE_TEST_CASE(Name,\
    \ Tags, ...) \\\n        INTERNAL_CATCH_TEMPLATE_TEST_CASE_2( INTERNAL_CATCH_UNIQUE_NAME(\
    \ ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____ ), INTERNAL_CATCH_UNIQUE_NAME(\
    \ ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____F_U_N_C____ ), Name, Tags, typename\
    \ TestType, __VA_ARGS__ )\n#else\n    #define INTERNAL_CATCH_TEMPLATE_TEST_CASE(Name,\
    \ Tags, ...) \\\n        INTERNAL_CATCH_EXPAND_VARGS( INTERNAL_CATCH_TEMPLATE_TEST_CASE_2(\
    \ INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____\
    \ ), INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____F_U_N_C____\
    \ ), Name, Tags, typename TestType, __VA_ARGS__ ) )\n#endif\n\n#ifndef CATCH_CONFIG_TRADITIONAL_MSVC_PREPROCESSOR\n\
    \    #define INTERNAL_CATCH_TEMPLATE_TEST_CASE_SIG(Name, Tags, Signature, ...)\
    \ \\\n        INTERNAL_CATCH_TEMPLATE_TEST_CASE_2( INTERNAL_CATCH_UNIQUE_NAME(\
    \ ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____ ), INTERNAL_CATCH_UNIQUE_NAME(\
    \ ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____F_U_N_C____ ), Name, Tags, Signature,\
    \ __VA_ARGS__ )\n#else\n    #define INTERNAL_CATCH_TEMPLATE_TEST_CASE_SIG(Name,\
    \ Tags, Signature, ...) \\\n        INTERNAL_CATCH_EXPAND_VARGS( INTERNAL_CATCH_TEMPLATE_TEST_CASE_2(\
    \ INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____\
    \ ), INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____F_U_N_C____\
    \ ), Name, Tags, Signature, __VA_ARGS__ ) )\n#endif\n\n    #define INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE2(TestName,\
    \ TestFuncName, Name, Tags, Signature, TmplTypes, TypesList) \\\n        CATCH_INTERNAL_START_WARNINGS_SUPPRESSION\
    \                      \\\n        CATCH_INTERNAL_SUPPRESS_GLOBALS_WARNINGS  \
    \                    \\\n        CATCH_INTERNAL_SUPPRESS_ZERO_VARIADIC_WARNINGS\
    \                \\\n        CATCH_INTERNAL_SUPPRESS_UNUSED_TEMPLATE_WARNINGS\
    \              \\\n        template<typename TestType> static void TestFuncName();\
    \       \\\n        namespace {\\\n        namespace INTERNAL_CATCH_MAKE_NAMESPACE(TestName)\
    \ {                                     \\\n            INTERNAL_CATCH_TYPE_GEN\
    \                                                  \\\n            INTERNAL_CATCH_NTTP_GEN(INTERNAL_CATCH_REMOVE_PARENS(Signature))\
    \         \\\n            template<typename... Types>                        \
    \       \\\n            struct TestName {                                    \
    \     \\\n                void reg_tests() {                                 \
    \         \\\n                    int index = 0;                             \
    \       \\\n                    using expander = int[];                      \
    \     \\\n                    constexpr char const* tmpl_types[] = {CATCH_REC_LIST(INTERNAL_CATCH_STRINGIZE_WITHOUT_PARENS,\
    \ INTERNAL_CATCH_REMOVE_PARENS(TmplTypes))};\\\n                    constexpr\
    \ char const* types_list[] = {CATCH_REC_LIST(INTERNAL_CATCH_STRINGIZE_WITHOUT_PARENS,\
    \ INTERNAL_CATCH_REMOVE_PARENS(TypesList))};\\\n                    constexpr\
    \ auto num_types = sizeof(types_list) / sizeof(types_list[0]);\\\n           \
    \         (void)expander{(Catch::AutoReg( Catch::makeTestInvoker( &TestFuncName<Types>\
    \ ), CATCH_INTERNAL_LINEINFO, Catch::StringRef(), Catch::NameAndTags{ Name \"\
    \ - \" + std::string(tmpl_types[index / num_types]) + \"<\" + std::string(types_list[index\
    \ % num_types]) + \">\", Tags } ), index++)... };/* NOLINT */\\\n            \
    \    }                                                     \\\n            };\
    \                                                        \\\n            static\
    \ int INTERNAL_CATCH_UNIQUE_NAME( globalRegistrar ) = [](){ \\\n             \
    \   using TestInit = typename create<TestName, decltype(get_wrapper<INTERNAL_CATCH_REMOVE_PARENS(TmplTypes)>()),\
    \ TypeList<INTERNAL_CATCH_MAKE_TYPE_LISTS_FROM_TYPES(INTERNAL_CATCH_REMOVE_PARENS(TypesList))>>::type;\
    \ \\\n                TestInit t;                                           \\\
    \n                t.reg_tests();                                        \\\n \
    \               return 0;                                             \\\n   \
    \         }();                                                      \\\n     \
    \   }                                                             \\\n       \
    \ }                                                             \\\n        CATCH_INTERNAL_STOP_WARNINGS_SUPPRESSION\
    \                       \\\n        template<typename TestType>              \
    \                     \\\n        static void TestFuncName()\n\n#ifndef CATCH_CONFIG_TRADITIONAL_MSVC_PREPROCESSOR\n\
    \    #define INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE(Name, Tags, ...)\\\n  \
    \      INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE2(INTERNAL_CATCH_UNIQUE_NAME(\
    \ ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____ ), INTERNAL_CATCH_UNIQUE_NAME(\
    \ ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____F_U_N_C____ ), Name, Tags, typename\
    \ T,__VA_ARGS__)\n#else\n    #define INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE(Name,\
    \ Tags, ...)\\\n        INTERNAL_CATCH_EXPAND_VARGS( INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE2(\
    \ INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____\
    \ ), INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____F_U_N_C____\
    \ ), Name, Tags, typename T, __VA_ARGS__ ) )\n#endif\n\n#ifndef CATCH_CONFIG_TRADITIONAL_MSVC_PREPROCESSOR\n\
    \    #define INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE_SIG(Name, Tags, Signature,\
    \ ...)\\\n        INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE2(INTERNAL_CATCH_UNIQUE_NAME(\
    \ ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____ ), INTERNAL_CATCH_UNIQUE_NAME(\
    \ ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____F_U_N_C____ ), Name, Tags, Signature,\
    \ __VA_ARGS__)\n#else\n    #define INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE_SIG(Name,\
    \ Tags, Signature, ...)\\\n        INTERNAL_CATCH_EXPAND_VARGS( INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE2(\
    \ INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____\
    \ ), INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____F_U_N_C____\
    \ ), Name, Tags, Signature, __VA_ARGS__ ) )\n#endif\n\n    #define INTERNAL_CATCH_TEMPLATE_LIST_TEST_CASE_2(TestName,\
    \ TestFunc, Name, Tags, TmplList)\\\n        CATCH_INTERNAL_START_WARNINGS_SUPPRESSION\
    \ \\\n        CATCH_INTERNAL_SUPPRESS_GLOBALS_WARNINGS \\\n        CATCH_INTERNAL_SUPPRESS_UNUSED_TEMPLATE_WARNINGS\
    \ \\\n        template<typename TestType> static void TestFunc();       \\\n \
    \       namespace {\\\n        namespace INTERNAL_CATCH_MAKE_NAMESPACE(TestName){\\\
    \n        INTERNAL_CATCH_TYPE_GEN\\\n        template<typename... Types>     \
    \                          \\\n        struct TestName {                     \
    \                    \\\n            void reg_tests() {                      \
    \                    \\\n                int index = 0;                      \
    \              \\\n                using expander = int[];                   \
    \        \\\n                (void)expander{(Catch::AutoReg( Catch::makeTestInvoker(\
    \ &TestFunc<Types> ), CATCH_INTERNAL_LINEINFO, Catch::StringRef(), Catch::NameAndTags{\
    \ Name \" - \" + std::string(INTERNAL_CATCH_STRINGIZE(TmplList)) + \" - \" + std::to_string(index),\
    \ Tags } ), index++)... };/* NOLINT */\\\n            }                      \
    \                               \\\n        };\\\n        static int INTERNAL_CATCH_UNIQUE_NAME(\
    \ globalRegistrar ) = [](){ \\\n                using TestInit = typename convert<TestName,\
    \ TmplList>::type; \\\n                TestInit t;                           \
    \                \\\n                t.reg_tests();                          \
    \              \\\n                return 0;                                 \
    \            \\\n            }();                                            \
    \          \\\n        }}\\\n        CATCH_INTERNAL_STOP_WARNINGS_SUPPRESSION\
    \                       \\\n        template<typename TestType>              \
    \                     \\\n        static void TestFunc()\n\n    #define INTERNAL_CATCH_TEMPLATE_LIST_TEST_CASE(Name,\
    \ Tags, TmplList) \\\n        INTERNAL_CATCH_TEMPLATE_LIST_TEST_CASE_2( INTERNAL_CATCH_UNIQUE_NAME(\
    \ ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____ ), INTERNAL_CATCH_UNIQUE_NAME(\
    \ ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____F_U_N_C____ ), Name, Tags, TmplList\
    \ )\n\n    #define INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD_2( TestNameClass,\
    \ TestName, ClassName, Name, Tags, Signature, ... ) \\\n        CATCH_INTERNAL_START_WARNINGS_SUPPRESSION\
    \ \\\n        CATCH_INTERNAL_SUPPRESS_GLOBALS_WARNINGS \\\n        CATCH_INTERNAL_SUPPRESS_ZERO_VARIADIC_WARNINGS\
    \ \\\n        CATCH_INTERNAL_SUPPRESS_UNUSED_TEMPLATE_WARNINGS \\\n        namespace\
    \ {\\\n        namespace INTERNAL_CATCH_MAKE_NAMESPACE(TestName){ \\\n       \
    \     INTERNAL_CATCH_TYPE_GEN\\\n            INTERNAL_CATCH_NTTP_GEN(INTERNAL_CATCH_REMOVE_PARENS(Signature))\\\
    \n            INTERNAL_CATCH_DECLARE_SIG_TEST_METHOD(TestName, ClassName, INTERNAL_CATCH_REMOVE_PARENS(Signature));\\\
    \n            INTERNAL_CATCH_NTTP_REG_METHOD_GEN(TestName, INTERNAL_CATCH_REMOVE_PARENS(Signature))\\\
    \n            template<typename...Types> \\\n            struct TestNameClass{\\\
    \n                TestNameClass(){\\\n                    int index = 0;     \
    \                               \\\n                    constexpr char const*\
    \ tmpl_types[] = {CATCH_REC_LIST(INTERNAL_CATCH_STRINGIZE_WITHOUT_PARENS, __VA_ARGS__)};\\\
    \n                    using expander = int[];\\\n                    (void)expander{(reg_test(Types{},\
    \ #ClassName, Catch::NameAndTags{ Name \" - \" + std::string(tmpl_types[index]),\
    \ Tags } ), index++)... };/* NOLINT */ \\\n                }\\\n            };\\\
    \n            static int INTERNAL_CATCH_UNIQUE_NAME( globalRegistrar ) = [](){\\\
    \n                TestNameClass<INTERNAL_CATCH_MAKE_TYPE_LISTS_FROM_TYPES(__VA_ARGS__)>();\\\
    \n                return 0;\\\n        }();\\\n        }\\\n        }\\\n    \
    \    CATCH_INTERNAL_STOP_WARNINGS_SUPPRESSION \\\n        INTERNAL_CATCH_DEFINE_SIG_TEST_METHOD(TestName,\
    \ INTERNAL_CATCH_REMOVE_PARENS(Signature))\n\n#ifndef CATCH_CONFIG_TRADITIONAL_MSVC_PREPROCESSOR\n\
    \    #define INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD( ClassName, Name, Tags,...\
    \ ) \\\n        INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD_2( INTERNAL_CATCH_UNIQUE_NAME(\
    \ ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____C_L_A_S_S____ ), INTERNAL_CATCH_UNIQUE_NAME(\
    \ ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____ ) , ClassName, Name, Tags, typename\
    \ T, __VA_ARGS__ )\n#else\n    #define INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD(\
    \ ClassName, Name, Tags,... ) \\\n        INTERNAL_CATCH_EXPAND_VARGS( INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD_2(\
    \ INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____C_L_A_S_S____\
    \ ), INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____\
    \ ) , ClassName, Name, Tags, typename T, __VA_ARGS__ ) )\n#endif\n\n#ifndef CATCH_CONFIG_TRADITIONAL_MSVC_PREPROCESSOR\n\
    \    #define INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD_SIG( ClassName, Name, Tags,\
    \ Signature, ... ) \\\n        INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD_2( INTERNAL_CATCH_UNIQUE_NAME(\
    \ ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____C_L_A_S_S____ ), INTERNAL_CATCH_UNIQUE_NAME(\
    \ ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____ ) , ClassName, Name, Tags, Signature,\
    \ __VA_ARGS__ )\n#else\n    #define INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD_SIG(\
    \ ClassName, Name, Tags, Signature, ... ) \\\n        INTERNAL_CATCH_EXPAND_VARGS(\
    \ INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD_2( INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____C_L_A_S_S____\
    \ ), INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____\
    \ ) , ClassName, Name, Tags, Signature, __VA_ARGS__ ) )\n#endif\n\n    #define\
    \ INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE_METHOD_2(TestNameClass, TestName,\
    \ ClassName, Name, Tags, Signature, TmplTypes, TypesList)\\\n        CATCH_INTERNAL_START_WARNINGS_SUPPRESSION\
    \ \\\n        CATCH_INTERNAL_SUPPRESS_GLOBALS_WARNINGS \\\n        CATCH_INTERNAL_SUPPRESS_ZERO_VARIADIC_WARNINGS\
    \ \\\n        CATCH_INTERNAL_SUPPRESS_UNUSED_TEMPLATE_WARNINGS \\\n        template<typename\
    \ TestType> \\\n            struct TestName : INTERNAL_CATCH_REMOVE_PARENS(ClassName\
    \ <TestType>) { \\\n                void test();\\\n            };\\\n       \
    \ namespace {\\\n        namespace INTERNAL_CATCH_MAKE_NAMESPACE(TestNameClass)\
    \ {\\\n            INTERNAL_CATCH_TYPE_GEN                  \\\n            INTERNAL_CATCH_NTTP_GEN(INTERNAL_CATCH_REMOVE_PARENS(Signature))\\\
    \n            template<typename...Types>\\\n            struct TestNameClass{\\\
    \n                void reg_tests(){\\\n                    int index = 0;\\\n\
    \                    using expander = int[];\\\n                    constexpr\
    \ char const* tmpl_types[] = {CATCH_REC_LIST(INTERNAL_CATCH_STRINGIZE_WITHOUT_PARENS,\
    \ INTERNAL_CATCH_REMOVE_PARENS(TmplTypes))};\\\n                    constexpr\
    \ char const* types_list[] = {CATCH_REC_LIST(INTERNAL_CATCH_STRINGIZE_WITHOUT_PARENS,\
    \ INTERNAL_CATCH_REMOVE_PARENS(TypesList))};\\\n                    constexpr\
    \ auto num_types = sizeof(types_list) / sizeof(types_list[0]);\\\n           \
    \         (void)expander{(Catch::AutoReg( Catch::makeTestInvoker( &TestName<Types>::test\
    \ ), CATCH_INTERNAL_LINEINFO, #ClassName, Catch::NameAndTags{ Name \" - \" + std::string(tmpl_types[index\
    \ / num_types]) + \"<\" + std::string(types_list[index % num_types]) + \">\",\
    \ Tags } ), index++)... };/* NOLINT */ \\\n                }\\\n            };\\\
    \n            static int INTERNAL_CATCH_UNIQUE_NAME( globalRegistrar ) = [](){\\\
    \n                using TestInit = typename create<TestNameClass, decltype(get_wrapper<INTERNAL_CATCH_REMOVE_PARENS(TmplTypes)>()),\
    \ TypeList<INTERNAL_CATCH_MAKE_TYPE_LISTS_FROM_TYPES(INTERNAL_CATCH_REMOVE_PARENS(TypesList))>>::type;\\\
    \n                TestInit t;\\\n                t.reg_tests();\\\n          \
    \      return 0;\\\n            }(); \\\n        }\\\n        }\\\n        CATCH_INTERNAL_STOP_WARNINGS_SUPPRESSION\
    \ \\\n        template<typename TestType> \\\n        void TestName<TestType>::test()\n\
    \n#ifndef CATCH_CONFIG_TRADITIONAL_MSVC_PREPROCESSOR\n    #define INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE_METHOD(\
    \ ClassName, Name, Tags, ... )\\\n        INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE_METHOD_2(\
    \ INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____\
    \ ), INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____F_U_N_C____\
    \ ), ClassName, Name, Tags, typename T, __VA_ARGS__ )\n#else\n    #define INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE_METHOD(\
    \ ClassName, Name, Tags, ... )\\\n        INTERNAL_CATCH_EXPAND_VARGS( INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE_METHOD_2(\
    \ INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____\
    \ ), INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____F_U_N_C____\
    \ ), ClassName, Name, Tags, typename T,__VA_ARGS__ ) )\n#endif\n\n#ifndef CATCH_CONFIG_TRADITIONAL_MSVC_PREPROCESSOR\n\
    \    #define INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE_METHOD_SIG( ClassName,\
    \ Name, Tags, Signature, ... )\\\n        INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE_METHOD_2(\
    \ INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____\
    \ ), INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____F_U_N_C____\
    \ ), ClassName, Name, Tags, Signature, __VA_ARGS__ )\n#else\n    #define INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE_METHOD_SIG(\
    \ ClassName, Name, Tags, Signature, ... )\\\n        INTERNAL_CATCH_EXPAND_VARGS(\
    \ INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE_METHOD_2( INTERNAL_CATCH_UNIQUE_NAME(\
    \ ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____ ), INTERNAL_CATCH_UNIQUE_NAME(\
    \ ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____F_U_N_C____ ), ClassName, Name,\
    \ Tags, Signature,__VA_ARGS__ ) )\n#endif\n\n    #define INTERNAL_CATCH_TEMPLATE_LIST_TEST_CASE_METHOD_2(\
    \ TestNameClass, TestName, ClassName, Name, Tags, TmplList) \\\n        CATCH_INTERNAL_START_WARNINGS_SUPPRESSION\
    \ \\\n        CATCH_INTERNAL_SUPPRESS_GLOBALS_WARNINGS \\\n        CATCH_INTERNAL_SUPPRESS_UNUSED_TEMPLATE_WARNINGS\
    \ \\\n        template<typename TestType> \\\n        struct TestName : INTERNAL_CATCH_REMOVE_PARENS(ClassName\
    \ <TestType>) { \\\n            void test();\\\n        };\\\n        namespace\
    \ {\\\n        namespace INTERNAL_CATCH_MAKE_NAMESPACE(TestName){ \\\n       \
    \     INTERNAL_CATCH_TYPE_GEN\\\n            template<typename...Types>\\\n  \
    \          struct TestNameClass{\\\n                void reg_tests(){\\\n    \
    \                int index = 0;\\\n                    using expander = int[];\\\
    \n                    (void)expander{(Catch::AutoReg( Catch::makeTestInvoker(\
    \ &TestName<Types>::test ), CATCH_INTERNAL_LINEINFO, #ClassName, Catch::NameAndTags{\
    \ Name \" - \" + std::string(INTERNAL_CATCH_STRINGIZE(TmplList)) + \" - \" + std::to_string(index),\
    \ Tags } ), index++)... };/* NOLINT */ \\\n                }\\\n            };\\\
    \n            static int INTERNAL_CATCH_UNIQUE_NAME( globalRegistrar ) = [](){\\\
    \n                using TestInit = typename convert<TestNameClass, TmplList>::type;\\\
    \n                TestInit t;\\\n                t.reg_tests();\\\n          \
    \      return 0;\\\n            }(); \\\n        }}\\\n        CATCH_INTERNAL_STOP_WARNINGS_SUPPRESSION\
    \ \\\n        template<typename TestType> \\\n        void TestName<TestType>::test()\n\
    \n#define INTERNAL_CATCH_TEMPLATE_LIST_TEST_CASE_METHOD(ClassName, Name, Tags,\
    \ TmplList) \\\n        INTERNAL_CATCH_TEMPLATE_LIST_TEST_CASE_METHOD_2( INTERNAL_CATCH_UNIQUE_NAME(\
    \ ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____ ), INTERNAL_CATCH_UNIQUE_NAME(\
    \ ____C_A_T_C_H____T_E_M_P_L_A_T_E____T_E_S_T____F_U_N_C____ ), ClassName, Name,\
    \ Tags, TmplList )\n\n// end catch_test_registry.h\n// start catch_capture.hpp\n\
    \n// start catch_assertionhandler.h\n\n// start catch_assertioninfo.h\n\n// start\
    \ catch_result_type.h\n\nnamespace Catch {\n\n    // ResultWas::OfType enum\n\
    \    struct ResultWas { enum OfType {\n        Unknown = -1,\n        Ok = 0,\n\
    \        Info = 1,\n        Warning = 2,\n\n        FailureBit = 0x10,\n\n   \
    \     ExpressionFailed = FailureBit | 1,\n        ExplicitFailure = FailureBit\
    \ | 2,\n\n        Exception = 0x100 | FailureBit,\n\n        ThrewException =\
    \ Exception | 1,\n        DidntThrowException = Exception | 2,\n\n        FatalErrorCondition\
    \ = 0x200 | FailureBit\n\n    }; };\n\n    bool isOk( ResultWas::OfType resultType\
    \ );\n    bool isJustInfo( int flags );\n\n    // ResultDisposition::Flags enum\n\
    \    struct ResultDisposition { enum Flags {\n        Normal = 0x01,\n\n     \
    \   ContinueOnFailure = 0x02,   // Failures fail test, but execution continues\n\
    \        FalseTest = 0x04,           // Prefix expression with !\n        SuppressFail\
    \ = 0x08         // Failures are reported but do not fail the test\n    }; };\n\
    \n    ResultDisposition::Flags operator | ( ResultDisposition::Flags lhs, ResultDisposition::Flags\
    \ rhs );\n\n    bool shouldContinueOnFailure( int flags );\n    inline bool isFalseTest(\
    \ int flags ) { return ( flags & ResultDisposition::FalseTest ) != 0; }\n    bool\
    \ shouldSuppressFailure( int flags );\n\n} // end namespace Catch\n\n// end catch_result_type.h\n\
    namespace Catch {\n\n    struct AssertionInfo\n    {\n        StringRef macroName;\n\
    \        SourceLineInfo lineInfo;\n        StringRef capturedExpression;\n   \
    \     ResultDisposition::Flags resultDisposition;\n\n        // We want to delete\
    \ this constructor but a compiler bug in 4.8 means\n        // the struct is then\
    \ treated as non-aggregate\n        //AssertionInfo() = delete;\n    };\n\n} //\
    \ end namespace Catch\n\n// end catch_assertioninfo.h\n// start catch_decomposer.h\n\
    \n// start catch_tostring.h\n\n#include <vector>\n#include <cstddef>\n#include\
    \ <type_traits>\n#include <string>\n// start catch_stream.h\n\n#include <iosfwd>\n\
    #include <cstddef>\n#include <ostream>\n\nnamespace Catch {\n\n    std::ostream&\
    \ cout();\n    std::ostream& cerr();\n    std::ostream& clog();\n\n    class StringRef;\n\
    \n    struct IStream {\n        virtual ~IStream();\n        virtual std::ostream&\
    \ stream() const = 0;\n    };\n\n    auto makeStream( StringRef const &filename\
    \ ) -> IStream const*;\n\n    class ReusableStringStream : NonCopyable {\n   \
    \     std::size_t m_index;\n        std::ostream* m_oss;\n    public:\n      \
    \  ReusableStringStream();\n        ~ReusableStringStream();\n\n        auto str()\
    \ const -> std::string;\n\n        template<typename T>\n        auto operator\
    \ << ( T const& value ) -> ReusableStringStream& {\n            *m_oss << value;\n\
    \            return *this;\n        }\n        auto get() -> std::ostream& { return\
    \ *m_oss; }\n    };\n}\n\n// end catch_stream.h\n// start catch_interfaces_enum_values_registry.h\n\
    \n#include <vector>\n\nnamespace Catch {\n\n    namespace Detail {\n        struct\
    \ EnumInfo {\n            StringRef m_name;\n            std::vector<std::pair<int,\
    \ StringRef>> m_values;\n\n            ~EnumInfo();\n\n            StringRef lookup(\
    \ int value ) const;\n        };\n    } // namespace Detail\n\n    struct IMutableEnumValuesRegistry\
    \ {\n        virtual ~IMutableEnumValuesRegistry();\n\n        virtual Detail::EnumInfo\
    \ const& registerEnum( StringRef enumName, StringRef allEnums, std::vector<int>\
    \ const& values ) = 0;\n\n        template<typename E>\n        Detail::EnumInfo\
    \ const& registerEnum( StringRef enumName, StringRef allEnums, std::initializer_list<E>\
    \ values ) {\n            static_assert(sizeof(int) >= sizeof(E), \"Cannot serialize\
    \ enum to int\");\n            std::vector<int> intValues;\n            intValues.reserve(\
    \ values.size() );\n            for( auto enumValue : values )\n             \
    \   intValues.push_back( static_cast<int>( enumValue ) );\n            return\
    \ registerEnum( enumName, allEnums, intValues );\n        }\n    };\n\n} // Catch\n\
    \n// end catch_interfaces_enum_values_registry.h\n\n#ifdef CATCH_CONFIG_CPP17_STRING_VIEW\n\
    #include <string_view>\n#endif\n\n#ifdef __OBJC__\n// start catch_objc_arc.hpp\n\
    \n#import <Foundation/Foundation.h>\n\n#ifdef __has_feature\n#define CATCH_ARC_ENABLED\
    \ __has_feature(objc_arc)\n#else\n#define CATCH_ARC_ENABLED 0\n#endif\n\nvoid\
    \ arcSafeRelease( NSObject* obj );\nid performOptionalSelector( id obj, SEL sel\
    \ );\n\n#if !CATCH_ARC_ENABLED\ninline void arcSafeRelease( NSObject* obj ) {\n\
    \    [obj release];\n}\ninline id performOptionalSelector( id obj, SEL sel ) {\n\
    \    if( [obj respondsToSelector: sel] )\n        return [obj performSelector:\
    \ sel];\n    return nil;\n}\n#define CATCH_UNSAFE_UNRETAINED\n#define CATCH_ARC_STRONG\n\
    #else\ninline void arcSafeRelease( NSObject* ){}\ninline id performOptionalSelector(\
    \ id obj, SEL sel ) {\n#ifdef __clang__\n#pragma clang diagnostic push\n#pragma\
    \ clang diagnostic ignored \"-Warc-performSelector-leaks\"\n#endif\n    if( [obj\
    \ respondsToSelector: sel] )\n        return [obj performSelector: sel];\n#ifdef\
    \ __clang__\n#pragma clang diagnostic pop\n#endif\n    return nil;\n}\n#define\
    \ CATCH_UNSAFE_UNRETAINED __unsafe_unretained\n#define CATCH_ARC_STRONG __strong\n\
    #endif\n\n// end catch_objc_arc.hpp\n#endif\n\n#ifdef _MSC_VER\n#pragma warning(push)\n\
    #pragma warning(disable:4180) // We attempt to stream a function (address) by\
    \ const&, which MSVC complains about but is harmless\n#endif\n\nnamespace Catch\
    \ {\n    namespace Detail {\n\n        extern const std::string unprintableString;\n\
    \n        std::string rawMemoryToString( const void *object, std::size_t size\
    \ );\n\n        template<typename T>\n        std::string rawMemoryToString( const\
    \ T& object ) {\n          return rawMemoryToString( &object, sizeof(object) );\n\
    \        }\n\n        template<typename T>\n        class IsStreamInsertable {\n\
    \            template<typename Stream, typename U>\n            static auto test(int)\n\
    \                -> decltype(std::declval<Stream&>() << std::declval<U>(), std::true_type());\n\
    \n            template<typename, typename>\n            static auto test(...)->std::false_type;\n\
    \n        public:\n            static const bool value = decltype(test<std::ostream,\
    \ const T&>(0))::value;\n        };\n\n        template<typename E>\n        std::string\
    \ convertUnknownEnumToString( E e );\n\n        template<typename T>\n       \
    \ typename std::enable_if<\n            !std::is_enum<T>::value && !std::is_base_of<std::exception,\
    \ T>::value,\n        std::string>::type convertUnstreamable( T const& ) {\n \
    \           return Detail::unprintableString;\n        }\n        template<typename\
    \ T>\n        typename std::enable_if<\n            !std::is_enum<T>::value &&\
    \ std::is_base_of<std::exception, T>::value,\n         std::string>::type convertUnstreamable(T\
    \ const& ex) {\n            return ex.what();\n        }\n\n        template<typename\
    \ T>\n        typename std::enable_if<\n            std::is_enum<T>::value\n \
    \       , std::string>::type convertUnstreamable( T const& value ) {\n       \
    \     return convertUnknownEnumToString( value );\n        }\n\n#if defined(_MANAGED)\n\
    \        //! Convert a CLR string to a utf8 std::string\n        template<typename\
    \ T>\n        std::string clrReferenceToString( T^ ref ) {\n            if (ref\
    \ == nullptr)\n                return std::string(\"null\");\n            auto\
    \ bytes = System::Text::Encoding::UTF8->GetBytes(ref->ToString());\n         \
    \   cli::pin_ptr<System::Byte> p = &bytes[0];\n            return std::string(reinterpret_cast<char\
    \ const *>(p), bytes->Length);\n        }\n#endif\n\n    } // namespace Detail\n\
    \n    // If we decide for C++14, change these to enable_if_ts\n    template <typename\
    \ T, typename = void>\n    struct StringMaker {\n        template <typename Fake\
    \ = T>\n        static\n        typename std::enable_if<::Catch::Detail::IsStreamInsertable<Fake>::value,\
    \ std::string>::type\n            convert(const Fake& value) {\n             \
    \   ReusableStringStream rss;\n                // NB: call using the function-like\
    \ syntax to avoid ambiguity with\n                // user-defined templated operator<<\
    \ under clang.\n                rss.operator<<(value);\n                return\
    \ rss.str();\n        }\n\n        template <typename Fake = T>\n        static\n\
    \        typename std::enable_if<!::Catch::Detail::IsStreamInsertable<Fake>::value,\
    \ std::string>::type\n            convert( const Fake& value ) {\n#if !defined(CATCH_CONFIG_FALLBACK_STRINGIFIER)\n\
    \            return Detail::convertUnstreamable(value);\n#else\n            return\
    \ CATCH_CONFIG_FALLBACK_STRINGIFIER(value);\n#endif\n        }\n    };\n\n   \
    \ namespace Detail {\n\n        // This function dispatches all stringification\
    \ requests inside of Catch.\n        // Should be preferably called fully qualified,\
    \ like ::Catch::Detail::stringify\n        template <typename T>\n        std::string\
    \ stringify(const T& e) {\n            return ::Catch::StringMaker<typename std::remove_cv<typename\
    \ std::remove_reference<T>::type>::type>::convert(e);\n        }\n\n        template<typename\
    \ E>\n        std::string convertUnknownEnumToString( E e ) {\n            return\
    \ ::Catch::Detail::stringify(static_cast<typename std::underlying_type<E>::type>(e));\n\
    \        }\n\n#if defined(_MANAGED)\n        template <typename T>\n        std::string\
    \ stringify( T^ e ) {\n            return ::Catch::StringMaker<T^>::convert(e);\n\
    \        }\n#endif\n\n    } // namespace Detail\n\n    // Some predefined specializations\n\
    \n    template<>\n    struct StringMaker<std::string> {\n        static std::string\
    \ convert(const std::string& str);\n    };\n\n#ifdef CATCH_CONFIG_CPP17_STRING_VIEW\n\
    \    template<>\n    struct StringMaker<std::string_view> {\n        static std::string\
    \ convert(std::string_view str);\n    };\n#endif\n\n    template<>\n    struct\
    \ StringMaker<char const *> {\n        static std::string convert(char const *\
    \ str);\n    };\n    template<>\n    struct StringMaker<char *> {\n        static\
    \ std::string convert(char * str);\n    };\n\n#ifdef CATCH_CONFIG_WCHAR\n    template<>\n\
    \    struct StringMaker<std::wstring> {\n        static std::string convert(const\
    \ std::wstring& wstr);\n    };\n\n# ifdef CATCH_CONFIG_CPP17_STRING_VIEW\n   \
    \ template<>\n    struct StringMaker<std::wstring_view> {\n        static std::string\
    \ convert(std::wstring_view str);\n    };\n# endif\n\n    template<>\n    struct\
    \ StringMaker<wchar_t const *> {\n        static std::string convert(wchar_t const\
    \ * str);\n    };\n    template<>\n    struct StringMaker<wchar_t *> {\n     \
    \   static std::string convert(wchar_t * str);\n    };\n#endif\n\n    // TBD:\
    \ Should we use `strnlen` to ensure that we don't go out of the buffer,\n    //\
    \      while keeping string semantics?\n    template<int SZ>\n    struct StringMaker<char[SZ]>\
    \ {\n        static std::string convert(char const* str) {\n            return\
    \ ::Catch::Detail::stringify(std::string{ str });\n        }\n    };\n    template<int\
    \ SZ>\n    struct StringMaker<signed char[SZ]> {\n        static std::string convert(signed\
    \ char const* str) {\n            return ::Catch::Detail::stringify(std::string{\
    \ reinterpret_cast<char const *>(str) });\n        }\n    };\n    template<int\
    \ SZ>\n    struct StringMaker<unsigned char[SZ]> {\n        static std::string\
    \ convert(unsigned char const* str) {\n            return ::Catch::Detail::stringify(std::string{\
    \ reinterpret_cast<char const *>(str) });\n        }\n    };\n\n#if defined(CATCH_CONFIG_CPP17_BYTE)\n\
    \    template<>\n    struct StringMaker<std::byte> {\n        static std::string\
    \ convert(std::byte value);\n    };\n#endif // defined(CATCH_CONFIG_CPP17_BYTE)\n\
    \    template<>\n    struct StringMaker<int> {\n        static std::string convert(int\
    \ value);\n    };\n    template<>\n    struct StringMaker<long> {\n        static\
    \ std::string convert(long value);\n    };\n    template<>\n    struct StringMaker<long\
    \ long> {\n        static std::string convert(long long value);\n    };\n    template<>\n\
    \    struct StringMaker<unsigned int> {\n        static std::string convert(unsigned\
    \ int value);\n    };\n    template<>\n    struct StringMaker<unsigned long> {\n\
    \        static std::string convert(unsigned long value);\n    };\n    template<>\n\
    \    struct StringMaker<unsigned long long> {\n        static std::string convert(unsigned\
    \ long long value);\n    };\n\n    template<>\n    struct StringMaker<bool> {\n\
    \        static std::string convert(bool b);\n    };\n\n    template<>\n    struct\
    \ StringMaker<char> {\n        static std::string convert(char c);\n    };\n \
    \   template<>\n    struct StringMaker<signed char> {\n        static std::string\
    \ convert(signed char c);\n    };\n    template<>\n    struct StringMaker<unsigned\
    \ char> {\n        static std::string convert(unsigned char c);\n    };\n\n  \
    \  template<>\n    struct StringMaker<std::nullptr_t> {\n        static std::string\
    \ convert(std::nullptr_t);\n    };\n\n    template<>\n    struct StringMaker<float>\
    \ {\n        static std::string convert(float value);\n        static int precision;\n\
    \    };\n\n    template<>\n    struct StringMaker<double> {\n        static std::string\
    \ convert(double value);\n        static int precision;\n    };\n\n    template\
    \ <typename T>\n    struct StringMaker<T*> {\n        template <typename U>\n\
    \        static std::string convert(U* p) {\n            if (p) {\n          \
    \      return ::Catch::Detail::rawMemoryToString(p);\n            } else {\n \
    \               return \"nullptr\";\n            }\n        }\n    };\n\n    template\
    \ <typename R, typename C>\n    struct StringMaker<R C::*> {\n        static std::string\
    \ convert(R C::* p) {\n            if (p) {\n                return ::Catch::Detail::rawMemoryToString(p);\n\
    \            } else {\n                return \"nullptr\";\n            }\n  \
    \      }\n    };\n\n#if defined(_MANAGED)\n    template <typename T>\n    struct\
    \ StringMaker<T^> {\n        static std::string convert( T^ ref ) {\n        \
    \    return ::Catch::Detail::clrReferenceToString(ref);\n        }\n    };\n#endif\n\
    \n    namespace Detail {\n        template<typename InputIterator, typename Sentinel\
    \ = InputIterator>\n        std::string rangeToString(InputIterator first, Sentinel\
    \ last) {\n            ReusableStringStream rss;\n            rss << \"{ \";\n\
    \            if (first != last) {\n                rss << ::Catch::Detail::stringify(*first);\n\
    \                for (++first; first != last; ++first)\n                    rss\
    \ << \", \" << ::Catch::Detail::stringify(*first);\n            }\n          \
    \  rss << \" }\";\n            return rss.str();\n        }\n    }\n\n#ifdef __OBJC__\n\
    \    template<>\n    struct StringMaker<NSString*> {\n        static std::string\
    \ convert(NSString * nsstring) {\n            if (!nsstring)\n               \
    \ return \"nil\";\n            return std::string(\"@\") + [nsstring UTF8String];\n\
    \        }\n    };\n    template<>\n    struct StringMaker<NSObject*> {\n    \
    \    static std::string convert(NSObject* nsObject) {\n            return ::Catch::Detail::stringify([nsObject\
    \ description]);\n        }\n\n    };\n    namespace Detail {\n        inline\
    \ std::string stringify( NSString* nsstring ) {\n            return StringMaker<NSString*>::convert(\
    \ nsstring );\n        }\n\n    } // namespace Detail\n#endif // __OBJC__\n\n\
    } // namespace Catch\n\n//////////////////////////////////////////////////////\n\
    // Separate std-lib types stringification, so it can be selectively enabled\n\
    // This means that we do not bring in\n\n#if defined(CATCH_CONFIG_ENABLE_ALL_STRINGMAKERS)\n\
    #  define CATCH_CONFIG_ENABLE_PAIR_STRINGMAKER\n#  define CATCH_CONFIG_ENABLE_TUPLE_STRINGMAKER\n\
    #  define CATCH_CONFIG_ENABLE_VARIANT_STRINGMAKER\n#  define CATCH_CONFIG_ENABLE_CHRONO_STRINGMAKER\n\
    #  define CATCH_CONFIG_ENABLE_OPTIONAL_STRINGMAKER\n#endif\n\n// Separate std::pair\
    \ specialization\n#if defined(CATCH_CONFIG_ENABLE_PAIR_STRINGMAKER)\n#include\
    \ <utility>\nnamespace Catch {\n    template<typename T1, typename T2>\n    struct\
    \ StringMaker<std::pair<T1, T2> > {\n        static std::string convert(const\
    \ std::pair<T1, T2>& pair) {\n            ReusableStringStream rss;\n        \
    \    rss << \"{ \"\n                << ::Catch::Detail::stringify(pair.first)\n\
    \                << \", \"\n                << ::Catch::Detail::stringify(pair.second)\n\
    \                << \" }\";\n            return rss.str();\n        }\n    };\n\
    }\n#endif // CATCH_CONFIG_ENABLE_PAIR_STRINGMAKER\n\n#if defined(CATCH_CONFIG_ENABLE_OPTIONAL_STRINGMAKER)\
    \ && defined(CATCH_CONFIG_CPP17_OPTIONAL)\n#include <optional>\nnamespace Catch\
    \ {\n    template<typename T>\n    struct StringMaker<std::optional<T> > {\n \
    \       static std::string convert(const std::optional<T>& optional) {\n     \
    \       ReusableStringStream rss;\n            if (optional.has_value()) {\n \
    \               rss << ::Catch::Detail::stringify(*optional);\n            } else\
    \ {\n                rss << \"{ }\";\n            }\n            return rss.str();\n\
    \        }\n    };\n}\n#endif // CATCH_CONFIG_ENABLE_OPTIONAL_STRINGMAKER\n\n\
    // Separate std::tuple specialization\n#if defined(CATCH_CONFIG_ENABLE_TUPLE_STRINGMAKER)\n\
    #include <tuple>\nnamespace Catch {\n    namespace Detail {\n        template<\n\
    \            typename Tuple,\n            std::size_t N = 0,\n            bool\
    \ = (N < std::tuple_size<Tuple>::value)\n            >\n            struct TupleElementPrinter\
    \ {\n            static void print(const Tuple& tuple, std::ostream& os) {\n \
    \               os << (N ? \", \" : \" \")\n                    << ::Catch::Detail::stringify(std::get<N>(tuple));\n\
    \                TupleElementPrinter<Tuple, N + 1>::print(tuple, os);\n      \
    \      }\n        };\n\n        template<\n            typename Tuple,\n     \
    \       std::size_t N\n        >\n            struct TupleElementPrinter<Tuple,\
    \ N, false> {\n            static void print(const Tuple&, std::ostream&) {}\n\
    \        };\n\n    }\n\n    template<typename ...Types>\n    struct StringMaker<std::tuple<Types...>>\
    \ {\n        static std::string convert(const std::tuple<Types...>& tuple) {\n\
    \            ReusableStringStream rss;\n            rss << '{';\n            Detail::TupleElementPrinter<std::tuple<Types...>>::print(tuple,\
    \ rss.get());\n            rss << \" }\";\n            return rss.str();\n   \
    \     }\n    };\n}\n#endif // CATCH_CONFIG_ENABLE_TUPLE_STRINGMAKER\n\n#if defined(CATCH_CONFIG_ENABLE_VARIANT_STRINGMAKER)\
    \ && defined(CATCH_CONFIG_CPP17_VARIANT)\n#include <variant>\nnamespace Catch\
    \ {\n    template<>\n    struct StringMaker<std::monostate> {\n        static\
    \ std::string convert(const std::monostate&) {\n            return \"{ }\";\n\
    \        }\n    };\n\n    template<typename... Elements>\n    struct StringMaker<std::variant<Elements...>>\
    \ {\n        static std::string convert(const std::variant<Elements...>& variant)\
    \ {\n            if (variant.valueless_by_exception()) {\n                return\
    \ \"{valueless variant}\";\n            } else {\n                return std::visit(\n\
    \                    [](const auto& value) {\n                        return ::Catch::Detail::stringify(value);\n\
    \                    },\n                    variant\n                );\n   \
    \         }\n        }\n    };\n}\n#endif // CATCH_CONFIG_ENABLE_VARIANT_STRINGMAKER\n\
    \nnamespace Catch {\n    // Import begin/ end from std here\n    using std::begin;\n\
    \    using std::end;\n\n    namespace detail {\n        template <typename...>\n\
    \        struct void_type {\n            using type = void;\n        };\n\n  \
    \      template <typename T, typename = void>\n        struct is_range_impl :\
    \ std::false_type {\n        };\n\n        template <typename T>\n        struct\
    \ is_range_impl<T, typename void_type<decltype(begin(std::declval<T>()))>::type>\
    \ : std::true_type {\n        };\n    } // namespace detail\n\n    template <typename\
    \ T>\n    struct is_range : detail::is_range_impl<T> {\n    };\n\n#if defined(_MANAGED)\
    \ // Managed types are never ranges\n    template <typename T>\n    struct is_range<T^>\
    \ {\n        static const bool value = false;\n    };\n#endif\n\n    template<typename\
    \ Range>\n    std::string rangeToString( Range const& range ) {\n        return\
    \ ::Catch::Detail::rangeToString( begin( range ), end( range ) );\n    }\n\n \
    \   // Handle vector<bool> specially\n    template<typename Allocator>\n    std::string\
    \ rangeToString( std::vector<bool, Allocator> const& v ) {\n        ReusableStringStream\
    \ rss;\n        rss << \"{ \";\n        bool first = true;\n        for( bool\
    \ b : v ) {\n            if( first )\n                first = false;\n       \
    \     else\n                rss << \", \";\n            rss << ::Catch::Detail::stringify(\
    \ b );\n        }\n        rss << \" }\";\n        return rss.str();\n    }\n\n\
    \    template<typename R>\n    struct StringMaker<R, typename std::enable_if<is_range<R>::value\
    \ && !::Catch::Detail::IsStreamInsertable<R>::value>::type> {\n        static\
    \ std::string convert( R const& range ) {\n            return rangeToString( range\
    \ );\n        }\n    };\n\n    template <typename T, int SZ>\n    struct StringMaker<T[SZ]>\
    \ {\n        static std::string convert(T const(&arr)[SZ]) {\n            return\
    \ rangeToString(arr);\n        }\n    };\n\n} // namespace Catch\n\n// Separate\
    \ std::chrono::duration specialization\n#if defined(CATCH_CONFIG_ENABLE_CHRONO_STRINGMAKER)\n\
    #include <ctime>\n#include <ratio>\n#include <chrono>\n\nnamespace Catch {\n\n\
    template <class Ratio>\nstruct ratio_string {\n    static std::string symbol();\n\
    };\n\ntemplate <class Ratio>\nstd::string ratio_string<Ratio>::symbol() {\n  \
    \  Catch::ReusableStringStream rss;\n    rss << '[' << Ratio::num << '/'\n   \
    \     << Ratio::den << ']';\n    return rss.str();\n}\ntemplate <>\nstruct ratio_string<std::atto>\
    \ {\n    static std::string symbol();\n};\ntemplate <>\nstruct ratio_string<std::femto>\
    \ {\n    static std::string symbol();\n};\ntemplate <>\nstruct ratio_string<std::pico>\
    \ {\n    static std::string symbol();\n};\ntemplate <>\nstruct ratio_string<std::nano>\
    \ {\n    static std::string symbol();\n};\ntemplate <>\nstruct ratio_string<std::micro>\
    \ {\n    static std::string symbol();\n};\ntemplate <>\nstruct ratio_string<std::milli>\
    \ {\n    static std::string symbol();\n};\n\n    ////////////\n    // std::chrono::duration\
    \ specializations\n    template<typename Value, typename Ratio>\n    struct StringMaker<std::chrono::duration<Value,\
    \ Ratio>> {\n        static std::string convert(std::chrono::duration<Value, Ratio>\
    \ const& duration) {\n            ReusableStringStream rss;\n            rss <<\
    \ duration.count() << ' ' << ratio_string<Ratio>::symbol() << 's';\n         \
    \   return rss.str();\n        }\n    };\n    template<typename Value>\n    struct\
    \ StringMaker<std::chrono::duration<Value, std::ratio<1>>> {\n        static std::string\
    \ convert(std::chrono::duration<Value, std::ratio<1>> const& duration) {\n   \
    \         ReusableStringStream rss;\n            rss << duration.count() << \"\
    \ s\";\n            return rss.str();\n        }\n    };\n    template<typename\
    \ Value>\n    struct StringMaker<std::chrono::duration<Value, std::ratio<60>>>\
    \ {\n        static std::string convert(std::chrono::duration<Value, std::ratio<60>>\
    \ const& duration) {\n            ReusableStringStream rss;\n            rss <<\
    \ duration.count() << \" m\";\n            return rss.str();\n        }\n    };\n\
    \    template<typename Value>\n    struct StringMaker<std::chrono::duration<Value,\
    \ std::ratio<3600>>> {\n        static std::string convert(std::chrono::duration<Value,\
    \ std::ratio<3600>> const& duration) {\n            ReusableStringStream rss;\n\
    \            rss << duration.count() << \" h\";\n            return rss.str();\n\
    \        }\n    };\n\n    ////////////\n    // std::chrono::time_point specialization\n\
    \    // Generic time_point cannot be specialized, only std::chrono::time_point<system_clock>\n\
    \    template<typename Clock, typename Duration>\n    struct StringMaker<std::chrono::time_point<Clock,\
    \ Duration>> {\n        static std::string convert(std::chrono::time_point<Clock,\
    \ Duration> const& time_point) {\n            return ::Catch::Detail::stringify(time_point.time_since_epoch())\
    \ + \" since epoch\";\n        }\n    };\n    // std::chrono::time_point<system_clock>\
    \ specialization\n    template<typename Duration>\n    struct StringMaker<std::chrono::time_point<std::chrono::system_clock,\
    \ Duration>> {\n        static std::string convert(std::chrono::time_point<std::chrono::system_clock,\
    \ Duration> const& time_point) {\n            auto converted = std::chrono::system_clock::to_time_t(time_point);\n\
    \n#ifdef _MSC_VER\n            std::tm timeInfo = {};\n            gmtime_s(&timeInfo,\
    \ &converted);\n#else\n            std::tm* timeInfo = std::gmtime(&converted);\n\
    #endif\n\n            auto const timeStampSize = sizeof(\"2017-01-16T17:06:45Z\"\
    );\n            char timeStamp[timeStampSize];\n            const char * const\
    \ fmt = \"%Y-%m-%dT%H:%M:%SZ\";\n\n#ifdef _MSC_VER\n            std::strftime(timeStamp,\
    \ timeStampSize, fmt, &timeInfo);\n#else\n            std::strftime(timeStamp,\
    \ timeStampSize, fmt, timeInfo);\n#endif\n            return std::string(timeStamp);\n\
    \        }\n    };\n}\n#endif // CATCH_CONFIG_ENABLE_CHRONO_STRINGMAKER\n\n#define\
    \ INTERNAL_CATCH_REGISTER_ENUM( enumName, ... ) \\\nnamespace Catch { \\\n   \
    \ template<> struct StringMaker<enumName> { \\\n        static std::string convert(\
    \ enumName value ) { \\\n            static const auto& enumInfo = ::Catch::getMutableRegistryHub().getMutableEnumValuesRegistry().registerEnum(\
    \ #enumName, #__VA_ARGS__, { __VA_ARGS__ } ); \\\n            return static_cast<std::string>(enumInfo.lookup(\
    \ static_cast<int>( value ) )); \\\n        } \\\n    }; \\\n}\n\n#define CATCH_REGISTER_ENUM(\
    \ enumName, ... ) INTERNAL_CATCH_REGISTER_ENUM( enumName, __VA_ARGS__ )\n\n#ifdef\
    \ _MSC_VER\n#pragma warning(pop)\n#endif\n\n// end catch_tostring.h\n#include\
    \ <iosfwd>\n\n#ifdef _MSC_VER\n#pragma warning(push)\n#pragma warning(disable:4389)\
    \ // '==' : signed/unsigned mismatch\n#pragma warning(disable:4018) // more \"\
    signed/unsigned mismatch\"\n#pragma warning(disable:4312) // Converting int to\
    \ T* using reinterpret_cast (issue on x64 platform)\n#pragma warning(disable:4180)\
    \ // qualifier applied to function type has no meaning\n#pragma warning(disable:4800)\
    \ // Forcing result to true or false\n#endif\n\nnamespace Catch {\n\n    struct\
    \ ITransientExpression {\n        auto isBinaryExpression() const -> bool { return\
    \ m_isBinaryExpression; }\n        auto getResult() const -> bool { return m_result;\
    \ }\n        virtual void streamReconstructedExpression( std::ostream &os ) const\
    \ = 0;\n\n        ITransientExpression( bool isBinaryExpression, bool result )\n\
    \        :   m_isBinaryExpression( isBinaryExpression ),\n            m_result(\
    \ result )\n        {}\n\n        // We don't actually need a virtual destructor,\
    \ but many static analysers\n        // complain if it's not here :-(\n      \
    \  virtual ~ITransientExpression();\n\n        bool m_isBinaryExpression;\n  \
    \      bool m_result;\n\n    };\n\n    void formatReconstructedExpression( std::ostream\
    \ &os, std::string const& lhs, StringRef op, std::string const& rhs );\n\n   \
    \ template<typename LhsT, typename RhsT>\n    class BinaryExpr  : public ITransientExpression\
    \ {\n        LhsT m_lhs;\n        StringRef m_op;\n        RhsT m_rhs;\n\n   \
    \     void streamReconstructedExpression( std::ostream &os ) const override {\n\
    \            formatReconstructedExpression\n                    ( os, Catch::Detail::stringify(\
    \ m_lhs ), m_op, Catch::Detail::stringify( m_rhs ) );\n        }\n\n    public:\n\
    \        BinaryExpr( bool comparisonResult, LhsT lhs, StringRef op, RhsT rhs )\n\
    \        :   ITransientExpression{ true, comparisonResult },\n            m_lhs(\
    \ lhs ),\n            m_op( op ),\n            m_rhs( rhs )\n        {}\n\n  \
    \      template<typename T>\n        auto operator && ( T ) const -> BinaryExpr<LhsT,\
    \ RhsT const&> const {\n            static_assert(always_false<T>::value,\n  \
    \          \"chained comparisons are not supported inside assertions, \"\n   \
    \         \"wrap the expression inside parentheses, or decompose it\");\n    \
    \    }\n\n        template<typename T>\n        auto operator || ( T ) const ->\
    \ BinaryExpr<LhsT, RhsT const&> const {\n            static_assert(always_false<T>::value,\n\
    \            \"chained comparisons are not supported inside assertions, \"\n \
    \           \"wrap the expression inside parentheses, or decompose it\");\n  \
    \      }\n\n        template<typename T>\n        auto operator == ( T ) const\
    \ -> BinaryExpr<LhsT, RhsT const&> const {\n            static_assert(always_false<T>::value,\n\
    \            \"chained comparisons are not supported inside assertions, \"\n \
    \           \"wrap the expression inside parentheses, or decompose it\");\n  \
    \      }\n\n        template<typename T>\n        auto operator != ( T ) const\
    \ -> BinaryExpr<LhsT, RhsT const&> const {\n            static_assert(always_false<T>::value,\n\
    \            \"chained comparisons are not supported inside assertions, \"\n \
    \           \"wrap the expression inside parentheses, or decompose it\");\n  \
    \      }\n\n        template<typename T>\n        auto operator > ( T ) const\
    \ -> BinaryExpr<LhsT, RhsT const&> const {\n            static_assert(always_false<T>::value,\n\
    \            \"chained comparisons are not supported inside assertions, \"\n \
    \           \"wrap the expression inside parentheses, or decompose it\");\n  \
    \      }\n\n        template<typename T>\n        auto operator < ( T ) const\
    \ -> BinaryExpr<LhsT, RhsT const&> const {\n            static_assert(always_false<T>::value,\n\
    \            \"chained comparisons are not supported inside assertions, \"\n \
    \           \"wrap the expression inside parentheses, or decompose it\");\n  \
    \      }\n\n        template<typename T>\n        auto operator >= ( T ) const\
    \ -> BinaryExpr<LhsT, RhsT const&> const {\n            static_assert(always_false<T>::value,\n\
    \            \"chained comparisons are not supported inside assertions, \"\n \
    \           \"wrap the expression inside parentheses, or decompose it\");\n  \
    \      }\n\n        template<typename T>\n        auto operator <= ( T ) const\
    \ -> BinaryExpr<LhsT, RhsT const&> const {\n            static_assert(always_false<T>::value,\n\
    \            \"chained comparisons are not supported inside assertions, \"\n \
    \           \"wrap the expression inside parentheses, or decompose it\");\n  \
    \      }\n    };\n\n    template<typename LhsT>\n    class UnaryExpr : public\
    \ ITransientExpression {\n        LhsT m_lhs;\n\n        void streamReconstructedExpression(\
    \ std::ostream &os ) const override {\n            os << Catch::Detail::stringify(\
    \ m_lhs );\n        }\n\n    public:\n        explicit UnaryExpr( LhsT lhs )\n\
    \        :   ITransientExpression{ false, static_cast<bool>(lhs) },\n        \
    \    m_lhs( lhs )\n        {}\n    };\n\n    // Specialised comparison functions\
    \ to handle equality comparisons between ints and pointers (NULL deduces as an\
    \ int)\n    template<typename LhsT, typename RhsT>\n    auto compareEqual( LhsT\
    \ const& lhs, RhsT const& rhs ) -> bool { return static_cast<bool>(lhs == rhs);\
    \ }\n    template<typename T>\n    auto compareEqual( T* const& lhs, int rhs )\
    \ -> bool { return lhs == reinterpret_cast<void const*>( rhs ); }\n    template<typename\
    \ T>\n    auto compareEqual( T* const& lhs, long rhs ) -> bool { return lhs ==\
    \ reinterpret_cast<void const*>( rhs ); }\n    template<typename T>\n    auto\
    \ compareEqual( int lhs, T* const& rhs ) -> bool { return reinterpret_cast<void\
    \ const*>( lhs ) == rhs; }\n    template<typename T>\n    auto compareEqual( long\
    \ lhs, T* const& rhs ) -> bool { return reinterpret_cast<void const*>( lhs ) ==\
    \ rhs; }\n\n    template<typename LhsT, typename RhsT>\n    auto compareNotEqual(\
    \ LhsT const& lhs, RhsT&& rhs ) -> bool { return static_cast<bool>(lhs != rhs);\
    \ }\n    template<typename T>\n    auto compareNotEqual( T* const& lhs, int rhs\
    \ ) -> bool { return lhs != reinterpret_cast<void const*>( rhs ); }\n    template<typename\
    \ T>\n    auto compareNotEqual( T* const& lhs, long rhs ) -> bool { return lhs\
    \ != reinterpret_cast<void const*>( rhs ); }\n    template<typename T>\n    auto\
    \ compareNotEqual( int lhs, T* const& rhs ) -> bool { return reinterpret_cast<void\
    \ const*>( lhs ) != rhs; }\n    template<typename T>\n    auto compareNotEqual(\
    \ long lhs, T* const& rhs ) -> bool { return reinterpret_cast<void const*>( lhs\
    \ ) != rhs; }\n\n    template<typename LhsT>\n    class ExprLhs {\n        LhsT\
    \ m_lhs;\n    public:\n        explicit ExprLhs( LhsT lhs ) : m_lhs( lhs ) {}\n\
    \n        template<typename RhsT>\n        auto operator == ( RhsT const& rhs\
    \ ) -> BinaryExpr<LhsT, RhsT const&> const {\n            return { compareEqual(\
    \ m_lhs, rhs ), m_lhs, \"==\", rhs };\n        }\n        auto operator == ( bool\
    \ rhs ) -> BinaryExpr<LhsT, bool> const {\n            return { m_lhs == rhs,\
    \ m_lhs, \"==\", rhs };\n        }\n\n        template<typename RhsT>\n      \
    \  auto operator != ( RhsT const& rhs ) -> BinaryExpr<LhsT, RhsT const&> const\
    \ {\n            return { compareNotEqual( m_lhs, rhs ), m_lhs, \"!=\", rhs };\n\
    \        }\n        auto operator != ( bool rhs ) -> BinaryExpr<LhsT, bool> const\
    \ {\n            return { m_lhs != rhs, m_lhs, \"!=\", rhs };\n        }\n\n \
    \       template<typename RhsT>\n        auto operator > ( RhsT const& rhs ) ->\
    \ BinaryExpr<LhsT, RhsT const&> const {\n            return { static_cast<bool>(m_lhs\
    \ > rhs), m_lhs, \">\", rhs };\n        }\n        template<typename RhsT>\n \
    \       auto operator < ( RhsT const& rhs ) -> BinaryExpr<LhsT, RhsT const&> const\
    \ {\n            return { static_cast<bool>(m_lhs < rhs), m_lhs, \"<\", rhs };\n\
    \        }\n        template<typename RhsT>\n        auto operator >= ( RhsT const&\
    \ rhs ) -> BinaryExpr<LhsT, RhsT const&> const {\n            return { static_cast<bool>(m_lhs\
    \ >= rhs), m_lhs, \">=\", rhs };\n        }\n        template<typename RhsT>\n\
    \        auto operator <= ( RhsT const& rhs ) -> BinaryExpr<LhsT, RhsT const&>\
    \ const {\n            return { static_cast<bool>(m_lhs <= rhs), m_lhs, \"<=\"\
    , rhs };\n        }\n        template <typename RhsT>\n        auto operator |\
    \ (RhsT const& rhs) -> BinaryExpr<LhsT, RhsT const&> const {\n            return\
    \ { static_cast<bool>(m_lhs | rhs), m_lhs, \"|\", rhs };\n        }\n        template\
    \ <typename RhsT>\n        auto operator & (RhsT const& rhs) -> BinaryExpr<LhsT,\
    \ RhsT const&> const {\n            return { static_cast<bool>(m_lhs & rhs), m_lhs,\
    \ \"&\", rhs };\n        }\n        template <typename RhsT>\n        auto operator\
    \ ^ (RhsT const& rhs) -> BinaryExpr<LhsT, RhsT const&> const {\n            return\
    \ { static_cast<bool>(m_lhs ^ rhs), m_lhs, \"^\", rhs };\n        }\n\n      \
    \  template<typename RhsT>\n        auto operator && ( RhsT const& ) -> BinaryExpr<LhsT,\
    \ RhsT const&> const {\n            static_assert(always_false<RhsT>::value,\n\
    \            \"operator&& is not supported inside assertions, \"\n           \
    \ \"wrap the expression inside parentheses, or decompose it\");\n        }\n\n\
    \        template<typename RhsT>\n        auto operator || ( RhsT const& ) ->\
    \ BinaryExpr<LhsT, RhsT const&> const {\n            static_assert(always_false<RhsT>::value,\n\
    \            \"operator|| is not supported inside assertions, \"\n           \
    \ \"wrap the expression inside parentheses, or decompose it\");\n        }\n\n\
    \        auto makeUnaryExpr() const -> UnaryExpr<LhsT> {\n            return UnaryExpr<LhsT>{\
    \ m_lhs };\n        }\n    };\n\n    void handleExpression( ITransientExpression\
    \ const& expr );\n\n    template<typename T>\n    void handleExpression( ExprLhs<T>\
    \ const& expr ) {\n        handleExpression( expr.makeUnaryExpr() );\n    }\n\n\
    \    struct Decomposer {\n        template<typename T>\n        auto operator\
    \ <= ( T const& lhs ) -> ExprLhs<T const&> {\n            return ExprLhs<T const&>{\
    \ lhs };\n        }\n\n        auto operator <=( bool value ) -> ExprLhs<bool>\
    \ {\n            return ExprLhs<bool>{ value };\n        }\n    };\n\n} // end\
    \ namespace Catch\n\n#ifdef _MSC_VER\n#pragma warning(pop)\n#endif\n\n// end catch_decomposer.h\n\
    // start catch_interfaces_capture.h\n\n#include <string>\n#include <chrono>\n\n\
    namespace Catch {\n\n    class AssertionResult;\n    struct AssertionInfo;\n \
    \   struct SectionInfo;\n    struct SectionEndInfo;\n    struct MessageInfo;\n\
    \    struct MessageBuilder;\n    struct Counts;\n    struct AssertionReaction;\n\
    \    struct SourceLineInfo;\n\n    struct ITransientExpression;\n    struct IGeneratorTracker;\n\
    \n#if defined(CATCH_CONFIG_ENABLE_BENCHMARKING)\n    struct BenchmarkInfo;\n \
    \   template <typename Duration = std::chrono::duration<double, std::nano>>\n\
    \    struct BenchmarkStats;\n#endif // CATCH_CONFIG_ENABLE_BENCHMARKING\n\n  \
    \  struct IResultCapture {\n\n        virtual ~IResultCapture();\n\n        virtual\
    \ bool sectionStarted(    SectionInfo const& sectionInfo,\n                  \
    \                      Counts& assertions ) = 0;\n        virtual void sectionEnded(\
    \ SectionEndInfo const& endInfo ) = 0;\n        virtual void sectionEndedEarly(\
    \ SectionEndInfo const& endInfo ) = 0;\n\n        virtual auto acquireGeneratorTracker(\
    \ StringRef generatorName, SourceLineInfo const& lineInfo ) -> IGeneratorTracker&\
    \ = 0;\n\n#if defined(CATCH_CONFIG_ENABLE_BENCHMARKING)\n        virtual void\
    \ benchmarkPreparing( std::string const& name ) = 0;\n        virtual void benchmarkStarting(\
    \ BenchmarkInfo const& info ) = 0;\n        virtual void benchmarkEnded( BenchmarkStats<>\
    \ const& stats ) = 0;\n        virtual void benchmarkFailed( std::string const&\
    \ error ) = 0;\n#endif // CATCH_CONFIG_ENABLE_BENCHMARKING\n\n        virtual\
    \ void pushScopedMessage( MessageInfo const& message ) = 0;\n        virtual void\
    \ popScopedMessage( MessageInfo const& message ) = 0;\n\n        virtual void\
    \ emplaceUnscopedMessage( MessageBuilder const& builder ) = 0;\n\n        virtual\
    \ void handleFatalErrorCondition( StringRef message ) = 0;\n\n        virtual\
    \ void handleExpr\n                (   AssertionInfo const& info,\n          \
    \          ITransientExpression const& expr,\n                    AssertionReaction&\
    \ reaction ) = 0;\n        virtual void handleMessage\n                (   AssertionInfo\
    \ const& info,\n                    ResultWas::OfType resultType,\n          \
    \          StringRef const& message,\n                    AssertionReaction& reaction\
    \ ) = 0;\n        virtual void handleUnexpectedExceptionNotThrown\n          \
    \      (   AssertionInfo const& info,\n                    AssertionReaction&\
    \ reaction ) = 0;\n        virtual void handleUnexpectedInflightException\n  \
    \              (   AssertionInfo const& info,\n                    std::string\
    \ const& message,\n                    AssertionReaction& reaction ) = 0;\n  \
    \      virtual void handleIncomplete\n                (   AssertionInfo const&\
    \ info ) = 0;\n        virtual void handleNonExpr\n                (   AssertionInfo\
    \ const &info,\n                    ResultWas::OfType resultType,\n          \
    \          AssertionReaction &reaction ) = 0;\n\n        virtual bool lastAssertionPassed()\
    \ = 0;\n        virtual void assertionPassed() = 0;\n\n        // Deprecated,\
    \ do not use:\n        virtual std::string getCurrentTestName() const = 0;\n \
    \       virtual const AssertionResult* getLastResult() const = 0;\n        virtual\
    \ void exceptionEarlyReported() = 0;\n    };\n\n    IResultCapture& getResultCapture();\n\
    }\n\n// end catch_interfaces_capture.h\nnamespace Catch {\n\n    struct TestFailureException{};\n\
    \    struct AssertionResultData;\n    struct IResultCapture;\n    class RunContext;\n\
    \n    class LazyExpression {\n        friend class AssertionHandler;\n       \
    \ friend struct AssertionStats;\n        friend class RunContext;\n\n        ITransientExpression\
    \ const* m_transientExpression = nullptr;\n        bool m_isNegated;\n    public:\n\
    \        LazyExpression( bool isNegated );\n        LazyExpression( LazyExpression\
    \ const& other );\n        LazyExpression& operator = ( LazyExpression const&\
    \ ) = delete;\n\n        explicit operator bool() const;\n\n        friend auto\
    \ operator << ( std::ostream& os, LazyExpression const& lazyExpr ) -> std::ostream&;\n\
    \    };\n\n    struct AssertionReaction {\n        bool shouldDebugBreak = false;\n\
    \        bool shouldThrow = false;\n    };\n\n    class AssertionHandler {\n \
    \       AssertionInfo m_assertionInfo;\n        AssertionReaction m_reaction;\n\
    \        bool m_completed = false;\n        IResultCapture& m_resultCapture;\n\
    \n    public:\n        AssertionHandler\n            (   StringRef const& macroName,\n\
    \                SourceLineInfo const& lineInfo,\n                StringRef capturedExpression,\n\
    \                ResultDisposition::Flags resultDisposition );\n        ~AssertionHandler()\
    \ {\n            if ( !m_completed ) {\n                m_resultCapture.handleIncomplete(\
    \ m_assertionInfo );\n            }\n        }\n\n        template<typename T>\n\
    \        void handleExpr( ExprLhs<T> const& expr ) {\n            handleExpr(\
    \ expr.makeUnaryExpr() );\n        }\n        void handleExpr( ITransientExpression\
    \ const& expr );\n\n        void handleMessage(ResultWas::OfType resultType, StringRef\
    \ const& message);\n\n        void handleExceptionThrownAsExpected();\n      \
    \  void handleUnexpectedExceptionNotThrown();\n        void handleExceptionNotThrownAsExpected();\n\
    \        void handleThrowingCallSkipped();\n        void handleUnexpectedInflightException();\n\
    \n        void complete();\n        void setCompleted();\n\n        // query\n\
    \        auto allowThrows() const -> bool;\n    };\n\n    void handleExceptionMatchExpr(\
    \ AssertionHandler& handler, std::string const& str, StringRef const& matcherString\
    \ );\n\n} // namespace Catch\n\n// end catch_assertionhandler.h\n// start catch_message.h\n\
    \n#include <string>\n#include <vector>\n\nnamespace Catch {\n\n    struct MessageInfo\
    \ {\n        MessageInfo(    StringRef const& _macroName,\n                  \
    \      SourceLineInfo const& _lineInfo,\n                        ResultWas::OfType\
    \ _type );\n\n        StringRef macroName;\n        std::string message;\n   \
    \     SourceLineInfo lineInfo;\n        ResultWas::OfType type;\n        unsigned\
    \ int sequence;\n\n        bool operator == ( MessageInfo const& other ) const;\n\
    \        bool operator < ( MessageInfo const& other ) const;\n    private:\n \
    \       static unsigned int globalCount;\n    };\n\n    struct MessageStream {\n\
    \n        template<typename T>\n        MessageStream& operator << ( T const&\
    \ value ) {\n            m_stream << value;\n            return *this;\n     \
    \   }\n\n        ReusableStringStream m_stream;\n    };\n\n    struct MessageBuilder\
    \ : MessageStream {\n        MessageBuilder( StringRef const& macroName,\n   \
    \                     SourceLineInfo const& lineInfo,\n                      \
    \  ResultWas::OfType type );\n\n        template<typename T>\n        MessageBuilder&\
    \ operator << ( T const& value ) {\n            m_stream << value;\n         \
    \   return *this;\n        }\n\n        MessageInfo m_info;\n    };\n\n    class\
    \ ScopedMessage {\n    public:\n        explicit ScopedMessage( MessageBuilder\
    \ const& builder );\n        ScopedMessage( ScopedMessage& duplicate ) = delete;\n\
    \        ScopedMessage( ScopedMessage&& old );\n        ~ScopedMessage();\n\n\
    \        MessageInfo m_info;\n        bool m_moved;\n    };\n\n    class Capturer\
    \ {\n        std::vector<MessageInfo> m_messages;\n        IResultCapture& m_resultCapture\
    \ = getResultCapture();\n        size_t m_captured = 0;\n    public:\n       \
    \ Capturer( StringRef macroName, SourceLineInfo const& lineInfo, ResultWas::OfType\
    \ resultType, StringRef names );\n        ~Capturer();\n\n        void captureValue(\
    \ size_t index, std::string const& value );\n\n        template<typename T>\n\
    \        void captureValues( size_t index, T const& value ) {\n            captureValue(\
    \ index, Catch::Detail::stringify( value ) );\n        }\n\n        template<typename\
    \ T, typename... Ts>\n        void captureValues( size_t index, T const& value,\
    \ Ts const&... values ) {\n            captureValue( index, Catch::Detail::stringify(value)\
    \ );\n            captureValues( index+1, values... );\n        }\n    };\n\n\
    } // end namespace Catch\n\n// end catch_message.h\n#if !defined(CATCH_CONFIG_DISABLE)\n\
    \n#if !defined(CATCH_CONFIG_DISABLE_STRINGIFICATION)\n  #define CATCH_INTERNAL_STRINGIFY(...)\
    \ #__VA_ARGS__\n#else\n  #define CATCH_INTERNAL_STRINGIFY(...) \"Disabled by CATCH_CONFIG_DISABLE_STRINGIFICATION\"\
    \n#endif\n\n#if defined(CATCH_CONFIG_FAST_COMPILE) || defined(CATCH_CONFIG_DISABLE_EXCEPTIONS)\n\
    \n///////////////////////////////////////////////////////////////////////////////\n\
    // Another way to speed-up compilation is to omit local try-catch for REQUIRE*\n\
    // macros.\n#define INTERNAL_CATCH_TRY\n#define INTERNAL_CATCH_CATCH( capturer\
    \ )\n\n#else // CATCH_CONFIG_FAST_COMPILE\n\n#define INTERNAL_CATCH_TRY try\n\
    #define INTERNAL_CATCH_CATCH( handler ) catch(...) { handler.handleUnexpectedInflightException();\
    \ }\n\n#endif\n\n#define INTERNAL_CATCH_REACT( handler ) handler.complete();\n\
    \n///////////////////////////////////////////////////////////////////////////////\n\
    #define INTERNAL_CATCH_TEST( macroName, resultDisposition, ... ) \\\n    do {\
    \ \\\n        CATCH_INTERNAL_IGNORE_BUT_WARN(__VA_ARGS__); \\\n        Catch::AssertionHandler\
    \ catchAssertionHandler( macroName##_catch_sr, CATCH_INTERNAL_LINEINFO, CATCH_INTERNAL_STRINGIFY(__VA_ARGS__),\
    \ resultDisposition ); \\\n        INTERNAL_CATCH_TRY { \\\n            CATCH_INTERNAL_START_WARNINGS_SUPPRESSION\
    \ \\\n            CATCH_INTERNAL_SUPPRESS_PARENTHESES_WARNINGS \\\n          \
    \  catchAssertionHandler.handleExpr( Catch::Decomposer() <= __VA_ARGS__ ); \\\n\
    \            CATCH_INTERNAL_STOP_WARNINGS_SUPPRESSION \\\n        } INTERNAL_CATCH_CATCH(\
    \ catchAssertionHandler ) \\\n        INTERNAL_CATCH_REACT( catchAssertionHandler\
    \ ) \\\n    } while( (void)0, (false) && static_cast<bool>( !!(__VA_ARGS__) )\
    \ )\n\n///////////////////////////////////////////////////////////////////////////////\n\
    #define INTERNAL_CATCH_IF( macroName, resultDisposition, ... ) \\\n    INTERNAL_CATCH_TEST(\
    \ macroName, resultDisposition, __VA_ARGS__ ); \\\n    if( Catch::getResultCapture().lastAssertionPassed()\
    \ )\n\n///////////////////////////////////////////////////////////////////////////////\n\
    #define INTERNAL_CATCH_ELSE( macroName, resultDisposition, ... ) \\\n    INTERNAL_CATCH_TEST(\
    \ macroName, resultDisposition, __VA_ARGS__ ); \\\n    if( !Catch::getResultCapture().lastAssertionPassed()\
    \ )\n\n///////////////////////////////////////////////////////////////////////////////\n\
    #define INTERNAL_CATCH_NO_THROW( macroName, resultDisposition, ... ) \\\n    do\
    \ { \\\n        Catch::AssertionHandler catchAssertionHandler( macroName##_catch_sr,\
    \ CATCH_INTERNAL_LINEINFO, CATCH_INTERNAL_STRINGIFY(__VA_ARGS__), resultDisposition\
    \ ); \\\n        try { \\\n            static_cast<void>(__VA_ARGS__); \\\n  \
    \          catchAssertionHandler.handleExceptionNotThrownAsExpected(); \\\n  \
    \      } \\\n        catch( ... ) { \\\n            catchAssertionHandler.handleUnexpectedInflightException();\
    \ \\\n        } \\\n        INTERNAL_CATCH_REACT( catchAssertionHandler ) \\\n\
    \    } while( false )\n\n///////////////////////////////////////////////////////////////////////////////\n\
    #define INTERNAL_CATCH_THROWS( macroName, resultDisposition, ... ) \\\n    do\
    \ { \\\n        Catch::AssertionHandler catchAssertionHandler( macroName##_catch_sr,\
    \ CATCH_INTERNAL_LINEINFO, CATCH_INTERNAL_STRINGIFY(__VA_ARGS__), resultDisposition);\
    \ \\\n        if( catchAssertionHandler.allowThrows() ) \\\n            try {\
    \ \\\n                static_cast<void>(__VA_ARGS__); \\\n                catchAssertionHandler.handleUnexpectedExceptionNotThrown();\
    \ \\\n            } \\\n            catch( ... ) { \\\n                catchAssertionHandler.handleExceptionThrownAsExpected();\
    \ \\\n            } \\\n        else \\\n            catchAssertionHandler.handleThrowingCallSkipped();\
    \ \\\n        INTERNAL_CATCH_REACT( catchAssertionHandler ) \\\n    } while( false\
    \ )\n\n///////////////////////////////////////////////////////////////////////////////\n\
    #define INTERNAL_CATCH_THROWS_AS( macroName, exceptionType, resultDisposition,\
    \ expr ) \\\n    do { \\\n        Catch::AssertionHandler catchAssertionHandler(\
    \ macroName##_catch_sr, CATCH_INTERNAL_LINEINFO, CATCH_INTERNAL_STRINGIFY(expr)\
    \ \", \" CATCH_INTERNAL_STRINGIFY(exceptionType), resultDisposition ); \\\n  \
    \      if( catchAssertionHandler.allowThrows() ) \\\n            try { \\\n  \
    \              static_cast<void>(expr); \\\n                catchAssertionHandler.handleUnexpectedExceptionNotThrown();\
    \ \\\n            } \\\n            catch( exceptionType const& ) { \\\n     \
    \           catchAssertionHandler.handleExceptionThrownAsExpected(); \\\n    \
    \        } \\\n            catch( ... ) { \\\n                catchAssertionHandler.handleUnexpectedInflightException();\
    \ \\\n            } \\\n        else \\\n            catchAssertionHandler.handleThrowingCallSkipped();\
    \ \\\n        INTERNAL_CATCH_REACT( catchAssertionHandler ) \\\n    } while( false\
    \ )\n\n///////////////////////////////////////////////////////////////////////////////\n\
    #define INTERNAL_CATCH_MSG( macroName, messageType, resultDisposition, ... ) \\\
    \n    do { \\\n        Catch::AssertionHandler catchAssertionHandler( macroName##_catch_sr,\
    \ CATCH_INTERNAL_LINEINFO, Catch::StringRef(), resultDisposition ); \\\n     \
    \   catchAssertionHandler.handleMessage( messageType, ( Catch::MessageStream()\
    \ << __VA_ARGS__ + ::Catch::StreamEndStop() ).m_stream.str() ); \\\n        INTERNAL_CATCH_REACT(\
    \ catchAssertionHandler ) \\\n    } while( false )\n\n///////////////////////////////////////////////////////////////////////////////\n\
    #define INTERNAL_CATCH_CAPTURE( varName, macroName, ... ) \\\n    auto varName\
    \ = Catch::Capturer( macroName, CATCH_INTERNAL_LINEINFO, Catch::ResultWas::Info,\
    \ #__VA_ARGS__ ); \\\n    varName.captureValues( 0, __VA_ARGS__ )\n\n///////////////////////////////////////////////////////////////////////////////\n\
    #define INTERNAL_CATCH_INFO( macroName, log ) \\\n    Catch::ScopedMessage INTERNAL_CATCH_UNIQUE_NAME(\
    \ scopedMessage )( Catch::MessageBuilder( macroName##_catch_sr, CATCH_INTERNAL_LINEINFO,\
    \ Catch::ResultWas::Info ) << log );\n\n///////////////////////////////////////////////////////////////////////////////\n\
    #define INTERNAL_CATCH_UNSCOPED_INFO( macroName, log ) \\\n    Catch::getResultCapture().emplaceUnscopedMessage(\
    \ Catch::MessageBuilder( macroName##_catch_sr, CATCH_INTERNAL_LINEINFO, Catch::ResultWas::Info\
    \ ) << log )\n\n///////////////////////////////////////////////////////////////////////////////\n\
    // Although this is matcher-based, it can be used with just a string\n#define\
    \ INTERNAL_CATCH_THROWS_STR_MATCHES( macroName, resultDisposition, matcher, ...\
    \ ) \\\n    do { \\\n        Catch::AssertionHandler catchAssertionHandler( macroName##_catch_sr,\
    \ CATCH_INTERNAL_LINEINFO, CATCH_INTERNAL_STRINGIFY(__VA_ARGS__) \", \" CATCH_INTERNAL_STRINGIFY(matcher),\
    \ resultDisposition ); \\\n        if( catchAssertionHandler.allowThrows() ) \\\
    \n            try { \\\n                static_cast<void>(__VA_ARGS__); \\\n \
    \               catchAssertionHandler.handleUnexpectedExceptionNotThrown(); \\\
    \n            } \\\n            catch( ... ) { \\\n                Catch::handleExceptionMatchExpr(\
    \ catchAssertionHandler, matcher, #matcher##_catch_sr ); \\\n            } \\\n\
    \        else \\\n            catchAssertionHandler.handleThrowingCallSkipped();\
    \ \\\n        INTERNAL_CATCH_REACT( catchAssertionHandler ) \\\n    } while( false\
    \ )\n\n#endif // CATCH_CONFIG_DISABLE\n\n// end catch_capture.hpp\n// start catch_section.h\n\
    \n// start catch_section_info.h\n\n// start catch_totals.h\n\n#include <cstddef>\n\
    \nnamespace Catch {\n\n    struct Counts {\n        Counts operator - ( Counts\
    \ const& other ) const;\n        Counts& operator += ( Counts const& other );\n\
    \n        std::size_t total() const;\n        bool allPassed() const;\n      \
    \  bool allOk() const;\n\n        std::size_t passed = 0;\n        std::size_t\
    \ failed = 0;\n        std::size_t failedButOk = 0;\n    };\n\n    struct Totals\
    \ {\n\n        Totals operator - ( Totals const& other ) const;\n        Totals&\
    \ operator += ( Totals const& other );\n\n        Totals delta( Totals const&\
    \ prevTotals ) const;\n\n        int error = 0;\n        Counts assertions;\n\
    \        Counts testCases;\n    };\n}\n\n// end catch_totals.h\n#include <string>\n\
    \nnamespace Catch {\n\n    struct SectionInfo {\n        SectionInfo\n       \
    \     (   SourceLineInfo const& _lineInfo,\n                std::string const&\
    \ _name );\n\n        // Deprecated\n        SectionInfo\n            (   SourceLineInfo\
    \ const& _lineInfo,\n                std::string const& _name,\n             \
    \   std::string const& ) : SectionInfo( _lineInfo, _name ) {}\n\n        std::string\
    \ name;\n        std::string description; // !Deprecated: this will always be\
    \ empty\n        SourceLineInfo lineInfo;\n    };\n\n    struct SectionEndInfo\
    \ {\n        SectionInfo sectionInfo;\n        Counts prevAssertions;\n      \
    \  double durationInSeconds;\n    };\n\n} // end namespace Catch\n\n// end catch_section_info.h\n\
    // start catch_timer.h\n\n#include <cstdint>\n\nnamespace Catch {\n\n    auto\
    \ getCurrentNanosecondsSinceEpoch() -> uint64_t;\n    auto getEstimatedClockResolution()\
    \ -> uint64_t;\n\n    class Timer {\n        uint64_t m_nanoseconds = 0;\n   \
    \ public:\n        void start();\n        auto getElapsedNanoseconds() const ->\
    \ uint64_t;\n        auto getElapsedMicroseconds() const -> uint64_t;\n      \
    \  auto getElapsedMilliseconds() const -> unsigned int;\n        auto getElapsedSeconds()\
    \ const -> double;\n    };\n\n} // namespace Catch\n\n// end catch_timer.h\n#include\
    \ <string>\n\nnamespace Catch {\n\n    class Section : NonCopyable {\n    public:\n\
    \        Section( SectionInfo const& info );\n        ~Section();\n\n        //\
    \ This indicates whether the section should be executed or not\n        explicit\
    \ operator bool() const;\n\n    private:\n        SectionInfo m_info;\n\n    \
    \    std::string m_name;\n        Counts m_assertions;\n        bool m_sectionIncluded;\n\
    \        Timer m_timer;\n    };\n\n} // end namespace Catch\n\n#define INTERNAL_CATCH_SECTION(\
    \ ... ) \\\n    CATCH_INTERNAL_START_WARNINGS_SUPPRESSION \\\n    CATCH_INTERNAL_SUPPRESS_UNUSED_WARNINGS\
    \ \\\n    if( Catch::Section const& INTERNAL_CATCH_UNIQUE_NAME( catch_internal_Section\
    \ ) = Catch::SectionInfo( CATCH_INTERNAL_LINEINFO, __VA_ARGS__ ) ) \\\n    CATCH_INTERNAL_STOP_WARNINGS_SUPPRESSION\n\
    \n#define INTERNAL_CATCH_DYNAMIC_SECTION( ... ) \\\n    CATCH_INTERNAL_START_WARNINGS_SUPPRESSION\
    \ \\\n    CATCH_INTERNAL_SUPPRESS_UNUSED_WARNINGS \\\n    if( Catch::Section const&\
    \ INTERNAL_CATCH_UNIQUE_NAME( catch_internal_Section ) = Catch::SectionInfo( CATCH_INTERNAL_LINEINFO,\
    \ (Catch::ReusableStringStream() << __VA_ARGS__).str() ) ) \\\n    CATCH_INTERNAL_STOP_WARNINGS_SUPPRESSION\n\
    \n// end catch_section.h\n// start catch_interfaces_exception.h\n\n// start catch_interfaces_registry_hub.h\n\
    \n#include <string>\n#include <memory>\n\nnamespace Catch {\n\n    class TestCase;\n\
    \    struct ITestCaseRegistry;\n    struct IExceptionTranslatorRegistry;\n   \
    \ struct IExceptionTranslator;\n    struct IReporterRegistry;\n    struct IReporterFactory;\n\
    \    struct ITagAliasRegistry;\n    struct IMutableEnumValuesRegistry;\n\n   \
    \ class StartupExceptionRegistry;\n\n    using IReporterFactoryPtr = std::shared_ptr<IReporterFactory>;\n\
    \n    struct IRegistryHub {\n        virtual ~IRegistryHub();\n\n        virtual\
    \ IReporterRegistry const& getReporterRegistry() const = 0;\n        virtual ITestCaseRegistry\
    \ const& getTestCaseRegistry() const = 0;\n        virtual ITagAliasRegistry const&\
    \ getTagAliasRegistry() const = 0;\n        virtual IExceptionTranslatorRegistry\
    \ const& getExceptionTranslatorRegistry() const = 0;\n\n        virtual StartupExceptionRegistry\
    \ const& getStartupExceptionRegistry() const = 0;\n    };\n\n    struct IMutableRegistryHub\
    \ {\n        virtual ~IMutableRegistryHub();\n        virtual void registerReporter(\
    \ std::string const& name, IReporterFactoryPtr const& factory ) = 0;\n       \
    \ virtual void registerListener( IReporterFactoryPtr const& factory ) = 0;\n \
    \       virtual void registerTest( TestCase const& testInfo ) = 0;\n        virtual\
    \ void registerTranslator( const IExceptionTranslator* translator ) = 0;\n   \
    \     virtual void registerTagAlias( std::string const& alias, std::string const&\
    \ tag, SourceLineInfo const& lineInfo ) = 0;\n        virtual void registerStartupException()\
    \ noexcept = 0;\n        virtual IMutableEnumValuesRegistry& getMutableEnumValuesRegistry()\
    \ = 0;\n    };\n\n    IRegistryHub const& getRegistryHub();\n    IMutableRegistryHub&\
    \ getMutableRegistryHub();\n    void cleanUp();\n    std::string translateActiveException();\n\
    \n}\n\n// end catch_interfaces_registry_hub.h\n#if defined(CATCH_CONFIG_DISABLE)\n\
    \    #define INTERNAL_CATCH_TRANSLATE_EXCEPTION_NO_REG( translatorName, signature)\
    \ \\\n        static std::string translatorName( signature )\n#endif\n\n#include\
    \ <exception>\n#include <string>\n#include <vector>\n\nnamespace Catch {\n   \
    \ using exceptionTranslateFunction = std::string(*)();\n\n    struct IExceptionTranslator;\n\
    \    using ExceptionTranslators = std::vector<std::unique_ptr<IExceptionTranslator\
    \ const>>;\n\n    struct IExceptionTranslator {\n        virtual ~IExceptionTranslator();\n\
    \        virtual std::string translate( ExceptionTranslators::const_iterator it,\
    \ ExceptionTranslators::const_iterator itEnd ) const = 0;\n    };\n\n    struct\
    \ IExceptionTranslatorRegistry {\n        virtual ~IExceptionTranslatorRegistry();\n\
    \n        virtual std::string translateActiveException() const = 0;\n    };\n\n\
    \    class ExceptionTranslatorRegistrar {\n        template<typename T>\n    \
    \    class ExceptionTranslator : public IExceptionTranslator {\n        public:\n\
    \n            ExceptionTranslator( std::string(*translateFunction)( T& ) )\n \
    \           : m_translateFunction( translateFunction )\n            {}\n\n   \
    \         std::string translate( ExceptionTranslators::const_iterator it, ExceptionTranslators::const_iterator\
    \ itEnd ) const override {\n#if defined(CATCH_CONFIG_DISABLE_EXCEPTIONS)\n   \
    \             return \"\";\n#else\n                try {\n                   \
    \ if( it == itEnd )\n                        std::rethrow_exception(std::current_exception());\n\
    \                    else\n                        return (*it)->translate( it+1,\
    \ itEnd );\n                }\n                catch( T& ex ) {\n            \
    \        return m_translateFunction( ex );\n                }\n#endif\n      \
    \      }\n\n        protected:\n            std::string(*m_translateFunction)(\
    \ T& );\n        };\n\n    public:\n        template<typename T>\n        ExceptionTranslatorRegistrar(\
    \ std::string(*translateFunction)( T& ) ) {\n            getMutableRegistryHub().registerTranslator\n\
    \                ( new ExceptionTranslator<T>( translateFunction ) );\n      \
    \  }\n    };\n}\n\n///////////////////////////////////////////////////////////////////////////////\n\
    #define INTERNAL_CATCH_TRANSLATE_EXCEPTION2( translatorName, signature ) \\\n\
    \    static std::string translatorName( signature ); \\\n    CATCH_INTERNAL_START_WARNINGS_SUPPRESSION\
    \ \\\n    CATCH_INTERNAL_SUPPRESS_GLOBALS_WARNINGS \\\n    namespace{ Catch::ExceptionTranslatorRegistrar\
    \ INTERNAL_CATCH_UNIQUE_NAME( catch_internal_ExceptionRegistrar )( &translatorName\
    \ ); } \\\n    CATCH_INTERNAL_STOP_WARNINGS_SUPPRESSION \\\n    static std::string\
    \ translatorName( signature )\n\n#define INTERNAL_CATCH_TRANSLATE_EXCEPTION( signature\
    \ ) INTERNAL_CATCH_TRANSLATE_EXCEPTION2( INTERNAL_CATCH_UNIQUE_NAME( catch_internal_ExceptionTranslator\
    \ ), signature )\n\n// end catch_interfaces_exception.h\n// start catch_approx.h\n\
    \n#include <type_traits>\n\nnamespace Catch {\nnamespace Detail {\n\n    class\
    \ Approx {\n    private:\n        bool equalityComparisonImpl(double other) const;\n\
    \        // Validates the new margin (margin >= 0)\n        // out-of-line to\
    \ avoid including stdexcept in the header\n        void setMargin(double margin);\n\
    \        // Validates the new epsilon (0 < epsilon < 1)\n        // out-of-line\
    \ to avoid including stdexcept in the header\n        void setEpsilon(double epsilon);\n\
    \n    public:\n        explicit Approx ( double value );\n\n        static Approx\
    \ custom();\n\n        Approx operator-() const;\n\n        template <typename\
    \ T, typename = typename std::enable_if<std::is_constructible<double, T>::value>::type>\n\
    \        Approx operator()( T const& value ) {\n            Approx approx( static_cast<double>(value)\
    \ );\n            approx.m_epsilon = m_epsilon;\n            approx.m_margin =\
    \ m_margin;\n            approx.m_scale = m_scale;\n            return approx;\n\
    \        }\n\n        template <typename T, typename = typename std::enable_if<std::is_constructible<double,\
    \ T>::value>::type>\n        explicit Approx( T const& value ): Approx(static_cast<double>(value))\n\
    \        {}\n\n        template <typename T, typename = typename std::enable_if<std::is_constructible<double,\
    \ T>::value>::type>\n        friend bool operator == ( const T& lhs, Approx const&\
    \ rhs ) {\n            auto lhs_v = static_cast<double>(lhs);\n            return\
    \ rhs.equalityComparisonImpl(lhs_v);\n        }\n\n        template <typename\
    \ T, typename = typename std::enable_if<std::is_constructible<double, T>::value>::type>\n\
    \        friend bool operator == ( Approx const& lhs, const T& rhs ) {\n     \
    \       return operator==( rhs, lhs );\n        }\n\n        template <typename\
    \ T, typename = typename std::enable_if<std::is_constructible<double, T>::value>::type>\n\
    \        friend bool operator != ( T const& lhs, Approx const& rhs ) {\n     \
    \       return !operator==( lhs, rhs );\n        }\n\n        template <typename\
    \ T, typename = typename std::enable_if<std::is_constructible<double, T>::value>::type>\n\
    \        friend bool operator != ( Approx const& lhs, T const& rhs ) {\n     \
    \       return !operator==( rhs, lhs );\n        }\n\n        template <typename\
    \ T, typename = typename std::enable_if<std::is_constructible<double, T>::value>::type>\n\
    \        friend bool operator <= ( T const& lhs, Approx const& rhs ) {\n     \
    \       return static_cast<double>(lhs) < rhs.m_value || lhs == rhs;\n       \
    \ }\n\n        template <typename T, typename = typename std::enable_if<std::is_constructible<double,\
    \ T>::value>::type>\n        friend bool operator <= ( Approx const& lhs, T const&\
    \ rhs ) {\n            return lhs.m_value < static_cast<double>(rhs) || lhs ==\
    \ rhs;\n        }\n\n        template <typename T, typename = typename std::enable_if<std::is_constructible<double,\
    \ T>::value>::type>\n        friend bool operator >= ( T const& lhs, Approx const&\
    \ rhs ) {\n            return static_cast<double>(lhs) > rhs.m_value || lhs ==\
    \ rhs;\n        }\n\n        template <typename T, typename = typename std::enable_if<std::is_constructible<double,\
    \ T>::value>::type>\n        friend bool operator >= ( Approx const& lhs, T const&\
    \ rhs ) {\n            return lhs.m_value > static_cast<double>(rhs) || lhs ==\
    \ rhs;\n        }\n\n        template <typename T, typename = typename std::enable_if<std::is_constructible<double,\
    \ T>::value>::type>\n        Approx& epsilon( T const& newEpsilon ) {\n      \
    \      double epsilonAsDouble = static_cast<double>(newEpsilon);\n           \
    \ setEpsilon(epsilonAsDouble);\n            return *this;\n        }\n\n     \
    \   template <typename T, typename = typename std::enable_if<std::is_constructible<double,\
    \ T>::value>::type>\n        Approx& margin( T const& newMargin ) {\n        \
    \    double marginAsDouble = static_cast<double>(newMargin);\n            setMargin(marginAsDouble);\n\
    \            return *this;\n        }\n\n        template <typename T, typename\
    \ = typename std::enable_if<std::is_constructible<double, T>::value>::type>\n\
    \        Approx& scale( T const& newScale ) {\n            m_scale = static_cast<double>(newScale);\n\
    \            return *this;\n        }\n\n        std::string toString() const;\n\
    \n    private:\n        double m_epsilon;\n        double m_margin;\n        double\
    \ m_scale;\n        double m_value;\n    };\n} // end namespace Detail\n\nnamespace\
    \ literals {\n    Detail::Approx operator \"\" _a(long double val);\n    Detail::Approx\
    \ operator \"\" _a(unsigned long long val);\n} // end namespace literals\n\ntemplate<>\n\
    struct StringMaker<Catch::Detail::Approx> {\n    static std::string convert(Catch::Detail::Approx\
    \ const& value);\n};\n\n} // end namespace Catch\n\n// end catch_approx.h\n//\
    \ start catch_string_manip.h\n\n#include <string>\n#include <iosfwd>\n#include\
    \ <vector>\n\nnamespace Catch {\n\n    bool startsWith( std::string const& s,\
    \ std::string const& prefix );\n    bool startsWith( std::string const& s, char\
    \ prefix );\n    bool endsWith( std::string const& s, std::string const& suffix\
    \ );\n    bool endsWith( std::string const& s, char suffix );\n    bool contains(\
    \ std::string const& s, std::string const& infix );\n    void toLowerInPlace(\
    \ std::string& s );\n    std::string toLower( std::string const& s );\n    //!\
    \ Returns a new string without whitespace at the start/end\n    std::string trim(\
    \ std::string const& str );\n    //! Returns a substring of the original ref without\
    \ whitespace. Beware lifetimes!\n    StringRef trim(StringRef ref);\n\n    //\
    \ !!! Be aware, returns refs into original string - make sure original string\
    \ outlives them\n    std::vector<StringRef> splitStringRef( StringRef str, char\
    \ delimiter );\n    bool replaceInPlace( std::string& str, std::string const&\
    \ replaceThis, std::string const& withThis );\n\n    struct pluralise {\n    \
    \    pluralise( std::size_t count, std::string const& label );\n\n        friend\
    \ std::ostream& operator << ( std::ostream& os, pluralise const& pluraliser );\n\
    \n        std::size_t m_count;\n        std::string m_label;\n    };\n}\n\n//\
    \ end catch_string_manip.h\n#ifndef CATCH_CONFIG_DISABLE_MATCHERS\n// start catch_capture_matchers.h\n\
    \n// start catch_matchers.h\n\n#include <string>\n#include <vector>\n\nnamespace\
    \ Catch {\nnamespace Matchers {\n    namespace Impl {\n\n        template<typename\
    \ ArgT> struct MatchAllOf;\n        template<typename ArgT> struct MatchAnyOf;\n\
    \        template<typename ArgT> struct MatchNotOf;\n\n        class MatcherUntypedBase\
    \ {\n        public:\n            MatcherUntypedBase() = default;\n          \
    \  MatcherUntypedBase ( MatcherUntypedBase const& ) = default;\n            MatcherUntypedBase&\
    \ operator = ( MatcherUntypedBase const& ) = delete;\n            std::string\
    \ toString() const;\n\n        protected:\n            virtual ~MatcherUntypedBase();\n\
    \            virtual std::string describe() const = 0;\n            mutable std::string\
    \ m_cachedToString;\n        };\n\n#ifdef __clang__\n#    pragma clang diagnostic\
    \ push\n#    pragma clang diagnostic ignored \"-Wnon-virtual-dtor\"\n#endif\n\n\
    \        template<typename ObjectT>\n        struct MatcherMethod {\n        \
    \    virtual bool match( ObjectT const& arg ) const = 0;\n        };\n\n#if defined(__OBJC__)\n\
    \        // Hack to fix Catch GH issue #1661. Could use id for generic Object\
    \ support.\n        // use of const for Object pointers is very uncommon and under\
    \ ARC it causes some kind of signature mismatch that breaks compilation\n    \
    \    template<>\n        struct MatcherMethod<NSString*> {\n            virtual\
    \ bool match( NSString* arg ) const = 0;\n        };\n#endif\n\n#ifdef __clang__\n\
    #    pragma clang diagnostic pop\n#endif\n\n        template<typename T>\n   \
    \     struct MatcherBase : MatcherUntypedBase, MatcherMethod<T> {\n\n        \
    \    MatchAllOf<T> operator && ( MatcherBase const& other ) const;\n         \
    \   MatchAnyOf<T> operator || ( MatcherBase const& other ) const;\n          \
    \  MatchNotOf<T> operator ! () const;\n        };\n\n        template<typename\
    \ ArgT>\n        struct MatchAllOf : MatcherBase<ArgT> {\n            bool match(\
    \ ArgT const& arg ) const override {\n                for( auto matcher : m_matchers\
    \ ) {\n                    if (!matcher->match(arg))\n                       \
    \ return false;\n                }\n                return true;\n           \
    \ }\n            std::string describe() const override {\n                std::string\
    \ description;\n                description.reserve( 4 + m_matchers.size()*32\
    \ );\n                description += \"( \";\n                bool first = true;\n\
    \                for( auto matcher : m_matchers ) {\n                    if( first\
    \ )\n                        first = false;\n                    else\n      \
    \                  description += \" and \";\n                    description\
    \ += matcher->toString();\n                }\n                description += \"\
    \ )\";\n                return description;\n            }\n\n            MatchAllOf<ArgT>\
    \ operator && ( MatcherBase<ArgT> const& other ) {\n                auto copy(*this);\n\
    \                copy.m_matchers.push_back( &other );\n                return\
    \ copy;\n            }\n\n            std::vector<MatcherBase<ArgT> const*> m_matchers;\n\
    \        };\n        template<typename ArgT>\n        struct MatchAnyOf : MatcherBase<ArgT>\
    \ {\n\n            bool match( ArgT const& arg ) const override {\n          \
    \      for( auto matcher : m_matchers ) {\n                    if (matcher->match(arg))\n\
    \                        return true;\n                }\n                return\
    \ false;\n            }\n            std::string describe() const override {\n\
    \                std::string description;\n                description.reserve(\
    \ 4 + m_matchers.size()*32 );\n                description += \"( \";\n      \
    \          bool first = true;\n                for( auto matcher : m_matchers\
    \ ) {\n                    if( first )\n                        first = false;\n\
    \                    else\n                        description += \" or \";\n\
    \                    description += matcher->toString();\n                }\n\
    \                description += \" )\";\n                return description;\n\
    \            }\n\n            MatchAnyOf<ArgT> operator || ( MatcherBase<ArgT>\
    \ const& other ) {\n                auto copy(*this);\n                copy.m_matchers.push_back(\
    \ &other );\n                return copy;\n            }\n\n            std::vector<MatcherBase<ArgT>\
    \ const*> m_matchers;\n        };\n\n        template<typename ArgT>\n       \
    \ struct MatchNotOf : MatcherBase<ArgT> {\n\n            MatchNotOf( MatcherBase<ArgT>\
    \ const& underlyingMatcher ) : m_underlyingMatcher( underlyingMatcher ) {}\n\n\
    \            bool match( ArgT const& arg ) const override {\n                return\
    \ !m_underlyingMatcher.match( arg );\n            }\n\n            std::string\
    \ describe() const override {\n                return \"not \" + m_underlyingMatcher.toString();\n\
    \            }\n            MatcherBase<ArgT> const& m_underlyingMatcher;\n  \
    \      };\n\n        template<typename T>\n        MatchAllOf<T> MatcherBase<T>::operator\
    \ && ( MatcherBase const& other ) const {\n            return MatchAllOf<T>()\
    \ && *this && other;\n        }\n        template<typename T>\n        MatchAnyOf<T>\
    \ MatcherBase<T>::operator || ( MatcherBase const& other ) const {\n         \
    \   return MatchAnyOf<T>() || *this || other;\n        }\n        template<typename\
    \ T>\n        MatchNotOf<T> MatcherBase<T>::operator ! () const {\n          \
    \  return MatchNotOf<T>( *this );\n        }\n\n    } // namespace Impl\n\n} //\
    \ namespace Matchers\n\nusing namespace Matchers;\nusing Matchers::Impl::MatcherBase;\n\
    \n} // namespace Catch\n\n// end catch_matchers.h\n// start catch_matchers_exception.hpp\n\
    \nnamespace Catch {\nnamespace Matchers {\nnamespace Exception {\n\nclass ExceptionMessageMatcher\
    \ : public MatcherBase<std::exception> {\n    std::string m_message;\npublic:\n\
    \n    ExceptionMessageMatcher(std::string const& message):\n        m_message(message)\n\
    \    {}\n\n    bool match(std::exception const& ex) const override;\n\n    std::string\
    \ describe() const override;\n};\n\n} // namespace Exception\n\nException::ExceptionMessageMatcher\
    \ Message(std::string const& message);\n\n} // namespace Matchers\n} // namespace\
    \ Catch\n\n// end catch_matchers_exception.hpp\n// start catch_matchers_floating.h\n\
    \nnamespace Catch {\nnamespace Matchers {\n\n    namespace Floating {\n\n    \
    \    enum class FloatingPointKind : uint8_t;\n\n        struct WithinAbsMatcher\
    \ : MatcherBase<double> {\n            WithinAbsMatcher(double target, double\
    \ margin);\n            bool match(double const& matchee) const override;\n  \
    \          std::string describe() const override;\n        private:\n        \
    \    double m_target;\n            double m_margin;\n        };\n\n        struct\
    \ WithinUlpsMatcher : MatcherBase<double> {\n            WithinUlpsMatcher(double\
    \ target, uint64_t ulps, FloatingPointKind baseType);\n            bool match(double\
    \ const& matchee) const override;\n            std::string describe() const override;\n\
    \        private:\n            double m_target;\n            uint64_t m_ulps;\n\
    \            FloatingPointKind m_type;\n        };\n\n        // Given IEEE-754\
    \ format for floats and doubles, we can assume\n        // that float -> double\
    \ promotion is lossless. Given this, we can\n        // assume that if we do the\
    \ standard relative comparison of\n        // |lhs - rhs| <= epsilon * max(fabs(lhs),\
    \ fabs(rhs)), then we get\n        // the same result if we do this for floats,\
    \ as if we do this for\n        // doubles that were promoted from floats.\n \
    \       struct WithinRelMatcher : MatcherBase<double> {\n            WithinRelMatcher(double\
    \ target, double epsilon);\n            bool match(double const& matchee) const\
    \ override;\n            std::string describe() const override;\n        private:\n\
    \            double m_target;\n            double m_epsilon;\n        };\n\n \
    \   } // namespace Floating\n\n    // The following functions create the actual\
    \ matcher objects.\n    // This allows the types to be inferred\n    Floating::WithinUlpsMatcher\
    \ WithinULP(double target, uint64_t maxUlpDiff);\n    Floating::WithinUlpsMatcher\
    \ WithinULP(float target, uint64_t maxUlpDiff);\n    Floating::WithinAbsMatcher\
    \ WithinAbs(double target, double margin);\n    Floating::WithinRelMatcher WithinRel(double\
    \ target, double eps);\n    // defaults epsilon to 100*numeric_limits<double>::epsilon()\n\
    \    Floating::WithinRelMatcher WithinRel(double target);\n    Floating::WithinRelMatcher\
    \ WithinRel(float target, float eps);\n    // defaults epsilon to 100*numeric_limits<float>::epsilon()\n\
    \    Floating::WithinRelMatcher WithinRel(float target);\n\n} // namespace Matchers\n\
    } // namespace Catch\n\n// end catch_matchers_floating.h\n// start catch_matchers_generic.hpp\n\
    \n#include <functional>\n#include <string>\n\nnamespace Catch {\nnamespace Matchers\
    \ {\nnamespace Generic {\n\nnamespace Detail {\n    std::string finalizeDescription(const\
    \ std::string& desc);\n}\n\ntemplate <typename T>\nclass PredicateMatcher : public\
    \ MatcherBase<T> {\n    std::function<bool(T const&)> m_predicate;\n    std::string\
    \ m_description;\npublic:\n\n    PredicateMatcher(std::function<bool(T const&)>\
    \ const& elem, std::string const& descr)\n        :m_predicate(std::move(elem)),\n\
    \        m_description(Detail::finalizeDescription(descr))\n    {}\n\n    bool\
    \ match( T const& item ) const override {\n        return m_predicate(item);\n\
    \    }\n\n    std::string describe() const override {\n        return m_description;\n\
    \    }\n};\n\n} // namespace Generic\n\n    // The following functions create\
    \ the actual matcher objects.\n    // The user has to explicitly specify type\
    \ to the function, because\n    // inferring std::function<bool(T const&)> is\
    \ hard (but possible) and\n    // requires a lot of TMP.\n    template<typename\
    \ T>\n    Generic::PredicateMatcher<T> Predicate(std::function<bool(T const&)>\
    \ const& predicate, std::string const& description = \"\") {\n        return Generic::PredicateMatcher<T>(predicate,\
    \ description);\n    }\n\n} // namespace Matchers\n} // namespace Catch\n\n//\
    \ end catch_matchers_generic.hpp\n// start catch_matchers_string.h\n\n#include\
    \ <string>\n\nnamespace Catch {\nnamespace Matchers {\n\n    namespace StdString\
    \ {\n\n        struct CasedString\n        {\n            CasedString( std::string\
    \ const& str, CaseSensitive::Choice caseSensitivity );\n            std::string\
    \ adjustString( std::string const& str ) const;\n            std::string caseSensitivitySuffix()\
    \ const;\n\n            CaseSensitive::Choice m_caseSensitivity;\n           \
    \ std::string m_str;\n        };\n\n        struct StringMatcherBase : MatcherBase<std::string>\
    \ {\n            StringMatcherBase( std::string const& operation, CasedString\
    \ const& comparator );\n            std::string describe() const override;\n\n\
    \            CasedString m_comparator;\n            std::string m_operation;\n\
    \        };\n\n        struct EqualsMatcher : StringMatcherBase {\n          \
    \  EqualsMatcher( CasedString const& comparator );\n            bool match( std::string\
    \ const& source ) const override;\n        };\n        struct ContainsMatcher\
    \ : StringMatcherBase {\n            ContainsMatcher( CasedString const& comparator\
    \ );\n            bool match( std::string const& source ) const override;\n  \
    \      };\n        struct StartsWithMatcher : StringMatcherBase {\n          \
    \  StartsWithMatcher( CasedString const& comparator );\n            bool match(\
    \ std::string const& source ) const override;\n        };\n        struct EndsWithMatcher\
    \ : StringMatcherBase {\n            EndsWithMatcher( CasedString const& comparator\
    \ );\n            bool match( std::string const& source ) const override;\n  \
    \      };\n\n        struct RegexMatcher : MatcherBase<std::string> {\n      \
    \      RegexMatcher( std::string regex, CaseSensitive::Choice caseSensitivity\
    \ );\n            bool match( std::string const& matchee ) const override;\n \
    \           std::string describe() const override;\n\n        private:\n     \
    \       std::string m_regex;\n            CaseSensitive::Choice m_caseSensitivity;\n\
    \        };\n\n    } // namespace StdString\n\n    // The following functions\
    \ create the actual matcher objects.\n    // This allows the types to be inferred\n\
    \n    StdString::EqualsMatcher Equals( std::string const& str, CaseSensitive::Choice\
    \ caseSensitivity = CaseSensitive::Yes );\n    StdString::ContainsMatcher Contains(\
    \ std::string const& str, CaseSensitive::Choice caseSensitivity = CaseSensitive::Yes\
    \ );\n    StdString::EndsWithMatcher EndsWith( std::string const& str, CaseSensitive::Choice\
    \ caseSensitivity = CaseSensitive::Yes );\n    StdString::StartsWithMatcher StartsWith(\
    \ std::string const& str, CaseSensitive::Choice caseSensitivity = CaseSensitive::Yes\
    \ );\n    StdString::RegexMatcher Matches( std::string const& regex, CaseSensitive::Choice\
    \ caseSensitivity = CaseSensitive::Yes );\n\n} // namespace Matchers\n} // namespace\
    \ Catch\n\n// end catch_matchers_string.h\n// start catch_matchers_vector.h\n\n\
    #include <algorithm>\n\nnamespace Catch {\nnamespace Matchers {\n\n    namespace\
    \ Vector {\n        template<typename T, typename Alloc>\n        struct ContainsElementMatcher\
    \ : MatcherBase<std::vector<T, Alloc>> {\n\n            ContainsElementMatcher(T\
    \ const &comparator) : m_comparator( comparator) {}\n\n            bool match(std::vector<T,\
    \ Alloc> const &v) const override {\n                for (auto const& el : v)\
    \ {\n                    if (el == m_comparator) {\n                        return\
    \ true;\n                    }\n                }\n                return false;\n\
    \            }\n\n            std::string describe() const override {\n      \
    \          return \"Contains: \" + ::Catch::Detail::stringify( m_comparator );\n\
    \            }\n\n            T const& m_comparator;\n        };\n\n        template<typename\
    \ T, typename AllocComp, typename AllocMatch>\n        struct ContainsMatcher\
    \ : MatcherBase<std::vector<T, AllocMatch>> {\n\n            ContainsMatcher(std::vector<T,\
    \ AllocComp> const &comparator) : m_comparator( comparator ) {}\n\n          \
    \  bool match(std::vector<T, AllocMatch> const &v) const override {\n        \
    \        // !TBD: see note in EqualsMatcher\n                if (m_comparator.size()\
    \ > v.size())\n                    return false;\n                for (auto const&\
    \ comparator : m_comparator) {\n                    auto present = false;\n  \
    \                  for (const auto& el : v) {\n                        if (el\
    \ == comparator) {\n                            present = true;\n            \
    \                break;\n                        }\n                    }\n  \
    \                  if (!present) {\n                        return false;\n  \
    \                  }\n                }\n                return true;\n      \
    \      }\n            std::string describe() const override {\n              \
    \  return \"Contains: \" + ::Catch::Detail::stringify( m_comparator );\n     \
    \       }\n\n            std::vector<T, AllocComp> const& m_comparator;\n    \
    \    };\n\n        template<typename T, typename AllocComp, typename AllocMatch>\n\
    \        struct EqualsMatcher : MatcherBase<std::vector<T, AllocMatch>> {\n\n\
    \            EqualsMatcher(std::vector<T, AllocComp> const &comparator) : m_comparator(\
    \ comparator ) {}\n\n            bool match(std::vector<T, AllocMatch> const &v)\
    \ const override {\n                // !TBD: This currently works if all elements\
    \ can be compared using !=\n                // - a more general approach would\
    \ be via a compare template that defaults\n                // to using !=. but\
    \ could be specialised for, e.g. std::vector<T, Alloc> etc\n                //\
    \ - then just call that directly\n                if (m_comparator.size() != v.size())\n\
    \                    return false;\n                for (std::size_t i = 0; i\
    \ < v.size(); ++i)\n                    if (m_comparator[i] != v[i])\n       \
    \                 return false;\n                return true;\n            }\n\
    \            std::string describe() const override {\n                return \"\
    Equals: \" + ::Catch::Detail::stringify( m_comparator );\n            }\n    \
    \        std::vector<T, AllocComp> const& m_comparator;\n        };\n\n      \
    \  template<typename T, typename AllocComp, typename AllocMatch>\n        struct\
    \ ApproxMatcher : MatcherBase<std::vector<T, AllocMatch>> {\n\n            ApproxMatcher(std::vector<T,\
    \ AllocComp> const& comparator) : m_comparator( comparator ) {}\n\n          \
    \  bool match(std::vector<T, AllocMatch> const &v) const override {\n        \
    \        if (m_comparator.size() != v.size())\n                    return false;\n\
    \                for (std::size_t i = 0; i < v.size(); ++i)\n                \
    \    if (m_comparator[i] != approx(v[i]))\n                        return false;\n\
    \                return true;\n            }\n            std::string describe()\
    \ const override {\n                return \"is approx: \" + ::Catch::Detail::stringify(\
    \ m_comparator );\n            }\n            template <typename = typename std::enable_if<std::is_constructible<double,\
    \ T>::value>::type>\n            ApproxMatcher& epsilon( T const& newEpsilon )\
    \ {\n                approx.epsilon(newEpsilon);\n                return *this;\n\
    \            }\n            template <typename = typename std::enable_if<std::is_constructible<double,\
    \ T>::value>::type>\n            ApproxMatcher& margin( T const& newMargin ) {\n\
    \                approx.margin(newMargin);\n                return *this;\n  \
    \          }\n            template <typename = typename std::enable_if<std::is_constructible<double,\
    \ T>::value>::type>\n            ApproxMatcher& scale( T const& newScale ) {\n\
    \                approx.scale(newScale);\n                return *this;\n    \
    \        }\n\n            std::vector<T, AllocComp> const& m_comparator;\n   \
    \         mutable Catch::Detail::Approx approx = Catch::Detail::Approx::custom();\n\
    \        };\n\n        template<typename T, typename AllocComp, typename AllocMatch>\n\
    \        struct UnorderedEqualsMatcher : MatcherBase<std::vector<T, AllocMatch>>\
    \ {\n            UnorderedEqualsMatcher(std::vector<T, AllocComp> const& target)\
    \ : m_target(target) {}\n            bool match(std::vector<T, AllocMatch> const&\
    \ vec) const override {\n                if (m_target.size() != vec.size()) {\n\
    \                    return false;\n                }\n                return\
    \ std::is_permutation(m_target.begin(), m_target.end(), vec.begin());\n      \
    \      }\n\n            std::string describe() const override {\n            \
    \    return \"UnorderedEquals: \" + ::Catch::Detail::stringify(m_target);\n  \
    \          }\n        private:\n            std::vector<T, AllocComp> const& m_target;\n\
    \        };\n\n    } // namespace Vector\n\n    // The following functions create\
    \ the actual matcher objects.\n    // This allows the types to be inferred\n\n\
    \    template<typename T, typename AllocComp = std::allocator<T>, typename AllocMatch\
    \ = AllocComp>\n    Vector::ContainsMatcher<T, AllocComp, AllocMatch> Contains(\
    \ std::vector<T, AllocComp> const& comparator ) {\n        return Vector::ContainsMatcher<T,\
    \ AllocComp, AllocMatch>( comparator );\n    }\n\n    template<typename T, typename\
    \ Alloc = std::allocator<T>>\n    Vector::ContainsElementMatcher<T, Alloc> VectorContains(\
    \ T const& comparator ) {\n        return Vector::ContainsElementMatcher<T, Alloc>(\
    \ comparator );\n    }\n\n    template<typename T, typename AllocComp = std::allocator<T>,\
    \ typename AllocMatch = AllocComp>\n    Vector::EqualsMatcher<T, AllocComp, AllocMatch>\
    \ Equals( std::vector<T, AllocComp> const& comparator ) {\n        return Vector::EqualsMatcher<T,\
    \ AllocComp, AllocMatch>( comparator );\n    }\n\n    template<typename T, typename\
    \ AllocComp = std::allocator<T>, typename AllocMatch = AllocComp>\n    Vector::ApproxMatcher<T,\
    \ AllocComp, AllocMatch> Approx( std::vector<T, AllocComp> const& comparator )\
    \ {\n        return Vector::ApproxMatcher<T, AllocComp, AllocMatch>( comparator\
    \ );\n    }\n\n    template<typename T, typename AllocComp = std::allocator<T>,\
    \ typename AllocMatch = AllocComp>\n    Vector::UnorderedEqualsMatcher<T, AllocComp,\
    \ AllocMatch> UnorderedEquals(std::vector<T, AllocComp> const& target) {\n   \
    \     return Vector::UnorderedEqualsMatcher<T, AllocComp, AllocMatch>( target\
    \ );\n    }\n\n} // namespace Matchers\n} // namespace Catch\n\n// end catch_matchers_vector.h\n\
    namespace Catch {\n\n    template<typename ArgT, typename MatcherT>\n    class\
    \ MatchExpr : public ITransientExpression {\n        ArgT const& m_arg;\n    \
    \    MatcherT m_matcher;\n        StringRef m_matcherString;\n    public:\n  \
    \      MatchExpr( ArgT const& arg, MatcherT const& matcher, StringRef const& matcherString\
    \ )\n        :   ITransientExpression{ true, matcher.match( arg ) },\n       \
    \     m_arg( arg ),\n            m_matcher( matcher ),\n            m_matcherString(\
    \ matcherString )\n        {}\n\n        void streamReconstructedExpression( std::ostream\
    \ &os ) const override {\n            auto matcherAsString = m_matcher.toString();\n\
    \            os << Catch::Detail::stringify( m_arg ) << ' ';\n            if(\
    \ matcherAsString == Detail::unprintableString )\n                os << m_matcherString;\n\
    \            else\n                os << matcherAsString;\n        }\n    };\n\
    \n    using StringMatcher = Matchers::Impl::MatcherBase<std::string>;\n\n    void\
    \ handleExceptionMatchExpr( AssertionHandler& handler, StringMatcher const& matcher,\
    \ StringRef const& matcherString  );\n\n    template<typename ArgT, typename MatcherT>\n\
    \    auto makeMatchExpr( ArgT const& arg, MatcherT const& matcher, StringRef const&\
    \ matcherString  ) -> MatchExpr<ArgT, MatcherT> {\n        return MatchExpr<ArgT,\
    \ MatcherT>( arg, matcher, matcherString );\n    }\n\n} // namespace Catch\n\n\
    ///////////////////////////////////////////////////////////////////////////////\n\
    #define INTERNAL_CHECK_THAT( macroName, matcher, resultDisposition, arg ) \\\n\
    \    do { \\\n        Catch::AssertionHandler catchAssertionHandler( macroName##_catch_sr,\
    \ CATCH_INTERNAL_LINEINFO, CATCH_INTERNAL_STRINGIFY(arg) \", \" CATCH_INTERNAL_STRINGIFY(matcher),\
    \ resultDisposition ); \\\n        INTERNAL_CATCH_TRY { \\\n            catchAssertionHandler.handleExpr(\
    \ Catch::makeMatchExpr( arg, matcher, #matcher##_catch_sr ) ); \\\n        } INTERNAL_CATCH_CATCH(\
    \ catchAssertionHandler ) \\\n        INTERNAL_CATCH_REACT( catchAssertionHandler\
    \ ) \\\n    } while( false )\n\n///////////////////////////////////////////////////////////////////////////////\n\
    #define INTERNAL_CATCH_THROWS_MATCHES( macroName, exceptionType, resultDisposition,\
    \ matcher, ... ) \\\n    do { \\\n        Catch::AssertionHandler catchAssertionHandler(\
    \ macroName##_catch_sr, CATCH_INTERNAL_LINEINFO, CATCH_INTERNAL_STRINGIFY(__VA_ARGS__)\
    \ \", \" CATCH_INTERNAL_STRINGIFY(exceptionType) \", \" CATCH_INTERNAL_STRINGIFY(matcher),\
    \ resultDisposition ); \\\n        if( catchAssertionHandler.allowThrows() ) \\\
    \n            try { \\\n                static_cast<void>(__VA_ARGS__ ); \\\n\
    \                catchAssertionHandler.handleUnexpectedExceptionNotThrown(); \\\
    \n            } \\\n            catch( exceptionType const& ex ) { \\\n      \
    \          catchAssertionHandler.handleExpr( Catch::makeMatchExpr( ex, matcher,\
    \ #matcher##_catch_sr ) ); \\\n            } \\\n            catch( ... ) { \\\
    \n                catchAssertionHandler.handleUnexpectedInflightException(); \\\
    \n            } \\\n        else \\\n            catchAssertionHandler.handleThrowingCallSkipped();\
    \ \\\n        INTERNAL_CATCH_REACT( catchAssertionHandler ) \\\n    } while( false\
    \ )\n\n// end catch_capture_matchers.h\n#endif\n// start catch_generators.hpp\n\
    \n// start catch_interfaces_generatortracker.h\n\n\n#include <memory>\n\nnamespace\
    \ Catch {\n\n    namespace Generators {\n        class GeneratorUntypedBase {\n\
    \        public:\n            GeneratorUntypedBase() = default;\n            virtual\
    \ ~GeneratorUntypedBase();\n            // Attempts to move the generator to the\
    \ next element\n             //\n             // Returns true iff the move succeeded\
    \ (and a valid element\n             // can be retrieved).\n            virtual\
    \ bool next() = 0;\n        };\n        using GeneratorBasePtr = std::unique_ptr<GeneratorUntypedBase>;\n\
    \n    } // namespace Generators\n\n    struct IGeneratorTracker {\n        virtual\
    \ ~IGeneratorTracker();\n        virtual auto hasGenerator() const -> bool = 0;\n\
    \        virtual auto getGenerator() const -> Generators::GeneratorBasePtr const&\
    \ = 0;\n        virtual void setGenerator( Generators::GeneratorBasePtr&& generator\
    \ ) = 0;\n    };\n\n} // namespace Catch\n\n// end catch_interfaces_generatortracker.h\n\
    // start catch_enforce.h\n\n#include <exception>\n\nnamespace Catch {\n#if !defined(CATCH_CONFIG_DISABLE_EXCEPTIONS)\n\
    \    template <typename Ex>\n    [[noreturn]]\n    void throw_exception(Ex const&\
    \ e) {\n        throw e;\n    }\n#else // ^^ Exceptions are enabled //  Exceptions\
    \ are disabled vv\n    [[noreturn]]\n    void throw_exception(std::exception const&\
    \ e);\n#endif\n\n    [[noreturn]]\n    void throw_logic_error(std::string const&\
    \ msg);\n    [[noreturn]]\n    void throw_domain_error(std::string const& msg);\n\
    \    [[noreturn]]\n    void throw_runtime_error(std::string const& msg);\n\n}\
    \ // namespace Catch;\n\n#define CATCH_MAKE_MSG(...) \\\n    (Catch::ReusableStringStream()\
    \ << __VA_ARGS__).str()\n\n#define CATCH_INTERNAL_ERROR(...) \\\n    Catch::throw_logic_error(CATCH_MAKE_MSG(\
    \ CATCH_INTERNAL_LINEINFO << \": Internal Catch2 error: \" << __VA_ARGS__))\n\n\
    #define CATCH_ERROR(...) \\\n    Catch::throw_domain_error(CATCH_MAKE_MSG( __VA_ARGS__\
    \ ))\n\n#define CATCH_RUNTIME_ERROR(...) \\\n    Catch::throw_runtime_error(CATCH_MAKE_MSG(\
    \ __VA_ARGS__ ))\n\n#define CATCH_ENFORCE( condition, ... ) \\\n    do{ if( !(condition)\
    \ ) CATCH_ERROR( __VA_ARGS__ ); } while(false)\n\n// end catch_enforce.h\n#include\
    \ <memory>\n#include <vector>\n#include <cassert>\n\n#include <utility>\n#include\
    \ <exception>\n\nnamespace Catch {\n\nclass GeneratorException : public std::exception\
    \ {\n    const char* const m_msg = \"\";\n\npublic:\n    GeneratorException(const\
    \ char* msg):\n        m_msg(msg)\n    {}\n\n    const char* what() const noexcept\
    \ override final;\n};\n\nnamespace Generators {\n\n    // !TBD move this into\
    \ its own location?\n    namespace pf{\n        template<typename T, typename...\
    \ Args>\n        std::unique_ptr<T> make_unique( Args&&... args ) {\n        \
    \    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));\n        }\n\
    \    }\n\n    template<typename T>\n    struct IGenerator : GeneratorUntypedBase\
    \ {\n        virtual ~IGenerator() = default;\n\n        // Returns the current\
    \ element of the generator\n        //\n        // \\Precondition The generator\
    \ is either freshly constructed,\n        // or the last call to `next()` returned\
    \ true\n        virtual T const& get() const = 0;\n        using type = T;\n \
    \   };\n\n    template<typename T>\n    class SingleValueGenerator final : public\
    \ IGenerator<T> {\n        T m_value;\n    public:\n        SingleValueGenerator(T&&\
    \ value) : m_value(std::move(value)) {}\n\n        T const& get() const override\
    \ {\n            return m_value;\n        }\n        bool next() override {\n\
    \            return false;\n        }\n    };\n\n    template<typename T>\n  \
    \  class FixedValuesGenerator final : public IGenerator<T> {\n        static_assert(!std::is_same<T,\
    \ bool>::value,\n            \"FixedValuesGenerator does not support bools because\
    \ of std::vector<bool>\"\n            \"specialization, use SingleValue Generator\
    \ instead.\");\n        std::vector<T> m_values;\n        size_t m_idx = 0;\n\
    \    public:\n        FixedValuesGenerator( std::initializer_list<T> values )\
    \ : m_values( values ) {}\n\n        T const& get() const override {\n       \
    \     return m_values[m_idx];\n        }\n        bool next() override {\n   \
    \         ++m_idx;\n            return m_idx < m_values.size();\n        }\n \
    \   };\n\n    template <typename T>\n    class GeneratorWrapper final {\n    \
    \    std::unique_ptr<IGenerator<T>> m_generator;\n    public:\n        GeneratorWrapper(std::unique_ptr<IGenerator<T>>\
    \ generator):\n            m_generator(std::move(generator))\n        {}\n   \
    \     T const& get() const {\n            return m_generator->get();\n       \
    \ }\n        bool next() {\n            return m_generator->next();\n        }\n\
    \    };\n\n    template <typename T>\n    GeneratorWrapper<T> value(T&& value)\
    \ {\n        return GeneratorWrapper<T>(pf::make_unique<SingleValueGenerator<T>>(std::forward<T>(value)));\n\
    \    }\n    template <typename T>\n    GeneratorWrapper<T> values(std::initializer_list<T>\
    \ values) {\n        return GeneratorWrapper<T>(pf::make_unique<FixedValuesGenerator<T>>(values));\n\
    \    }\n\n    template<typename T>\n    class Generators : public IGenerator<T>\
    \ {\n        std::vector<GeneratorWrapper<T>> m_generators;\n        size_t m_current\
    \ = 0;\n\n        void populate(GeneratorWrapper<T>&& generator) {\n         \
    \   m_generators.emplace_back(std::move(generator));\n        }\n        void\
    \ populate(T&& val) {\n            m_generators.emplace_back(value(std::forward<T>(val)));\n\
    \        }\n        template<typename U>\n        void populate(U&& val) {\n \
    \           populate(T(std::forward<U>(val)));\n        }\n        template<typename\
    \ U, typename... Gs>\n        void populate(U&& valueOrGenerator, Gs &&... moreGenerators)\
    \ {\n            populate(std::forward<U>(valueOrGenerator));\n            populate(std::forward<Gs>(moreGenerators)...);\n\
    \        }\n\n    public:\n        template <typename... Gs>\n        Generators(Gs\
    \ &&... moreGenerators) {\n            m_generators.reserve(sizeof...(Gs));\n\
    \            populate(std::forward<Gs>(moreGenerators)...);\n        }\n\n   \
    \     T const& get() const override {\n            return m_generators[m_current].get();\n\
    \        }\n\n        bool next() override {\n            if (m_current >= m_generators.size())\
    \ {\n                return false;\n            }\n            const bool current_status\
    \ = m_generators[m_current].next();\n            if (!current_status) {\n    \
    \            ++m_current;\n            }\n            return m_current < m_generators.size();\n\
    \        }\n    };\n\n    template<typename... Ts>\n    GeneratorWrapper<std::tuple<Ts...>>\
    \ table( std::initializer_list<std::tuple<typename std::decay<Ts>::type...>> tuples\
    \ ) {\n        return values<std::tuple<Ts...>>( tuples );\n    }\n\n    // Tag\
    \ type to signal that a generator sequence should convert arguments to a specific\
    \ type\n    template <typename T>\n    struct as {};\n\n    template<typename\
    \ T, typename... Gs>\n    auto makeGenerators( GeneratorWrapper<T>&& generator,\
    \ Gs &&... moreGenerators ) -> Generators<T> {\n        return Generators<T>(std::move(generator),\
    \ std::forward<Gs>(moreGenerators)...);\n    }\n    template<typename T>\n   \
    \ auto makeGenerators( GeneratorWrapper<T>&& generator ) -> Generators<T> {\n\
    \        return Generators<T>(std::move(generator));\n    }\n    template<typename\
    \ T, typename... Gs>\n    auto makeGenerators( T&& val, Gs &&... moreGenerators\
    \ ) -> Generators<T> {\n        return makeGenerators( value( std::forward<T>(\
    \ val ) ), std::forward<Gs>( moreGenerators )... );\n    }\n    template<typename\
    \ T, typename U, typename... Gs>\n    auto makeGenerators( as<T>, U&& val, Gs\
    \ &&... moreGenerators ) -> Generators<T> {\n        return makeGenerators( value(\
    \ T( std::forward<U>( val ) ) ), std::forward<Gs>( moreGenerators )... );\n  \
    \  }\n\n    auto acquireGeneratorTracker( StringRef generatorName, SourceLineInfo\
    \ const& lineInfo ) -> IGeneratorTracker&;\n\n    template<typename L>\n    //\
    \ Note: The type after -> is weird, because VS2015 cannot parse\n    //      \
    \ the expression used in the typedef inside, when it is in\n    //       return\
    \ type. Yeah.\n    auto generate( StringRef generatorName, SourceLineInfo const&\
    \ lineInfo, L const& generatorExpression ) -> decltype(std::declval<decltype(generatorExpression())>().get())\
    \ {\n        using UnderlyingType = typename decltype(generatorExpression())::type;\n\
    \n        IGeneratorTracker& tracker = acquireGeneratorTracker( generatorName,\
    \ lineInfo );\n        if (!tracker.hasGenerator()) {\n            tracker.setGenerator(pf::make_unique<Generators<UnderlyingType>>(generatorExpression()));\n\
    \        }\n\n        auto const& generator = static_cast<IGenerator<UnderlyingType>\
    \ const&>( *tracker.getGenerator() );\n        return generator.get();\n    }\n\
    \n} // namespace Generators\n} // namespace Catch\n\n#define GENERATE( ... ) \\\
    \n    Catch::Generators::generate( INTERNAL_CATCH_STRINGIZE(INTERNAL_CATCH_UNIQUE_NAME(generator)),\
    \ \\\n                                 CATCH_INTERNAL_LINEINFO, \\\n         \
    \                        [ ]{ using namespace Catch::Generators; return makeGenerators(\
    \ __VA_ARGS__ ); } ) //NOLINT(google-build-using-namespace)\n#define GENERATE_COPY(\
    \ ... ) \\\n    Catch::Generators::generate( INTERNAL_CATCH_STRINGIZE(INTERNAL_CATCH_UNIQUE_NAME(generator)),\
    \ \\\n                                 CATCH_INTERNAL_LINEINFO, \\\n         \
    \                        [=]{ using namespace Catch::Generators; return makeGenerators(\
    \ __VA_ARGS__ ); } ) //NOLINT(google-build-using-namespace)\n#define GENERATE_REF(\
    \ ... ) \\\n    Catch::Generators::generate( INTERNAL_CATCH_STRINGIZE(INTERNAL_CATCH_UNIQUE_NAME(generator)),\
    \ \\\n                                 CATCH_INTERNAL_LINEINFO, \\\n         \
    \                        [&]{ using namespace Catch::Generators; return makeGenerators(\
    \ __VA_ARGS__ ); } ) //NOLINT(google-build-using-namespace)\n\n// end catch_generators.hpp\n\
    // start catch_generators_generic.hpp\n\nnamespace Catch {\nnamespace Generators\
    \ {\n\n    template <typename T>\n    class TakeGenerator : public IGenerator<T>\
    \ {\n        GeneratorWrapper<T> m_generator;\n        size_t m_returned = 0;\n\
    \        size_t m_target;\n    public:\n        TakeGenerator(size_t target, GeneratorWrapper<T>&&\
    \ generator):\n            m_generator(std::move(generator)),\n            m_target(target)\n\
    \        {\n            assert(target != 0 && \"Empty generators are not allowed\"\
    );\n        }\n        T const& get() const override {\n            return m_generator.get();\n\
    \        }\n        bool next() override {\n            ++m_returned;\n      \
    \      if (m_returned >= m_target) {\n                return false;\n        \
    \    }\n\n            const auto success = m_generator.next();\n            //\
    \ If the underlying generator does not contain enough values\n            // then\
    \ we cut short as well\n            if (!success) {\n                m_returned\
    \ = m_target;\n            }\n            return success;\n        }\n    };\n\
    \n    template <typename T>\n    GeneratorWrapper<T> take(size_t target, GeneratorWrapper<T>&&\
    \ generator) {\n        return GeneratorWrapper<T>(pf::make_unique<TakeGenerator<T>>(target,\
    \ std::move(generator)));\n    }\n\n    template <typename T, typename Predicate>\n\
    \    class FilterGenerator : public IGenerator<T> {\n        GeneratorWrapper<T>\
    \ m_generator;\n        Predicate m_predicate;\n    public:\n        template\
    \ <typename P = Predicate>\n        FilterGenerator(P&& pred, GeneratorWrapper<T>&&\
    \ generator):\n            m_generator(std::move(generator)),\n            m_predicate(std::forward<P>(pred))\n\
    \        {\n            if (!m_predicate(m_generator.get())) {\n             \
    \   // It might happen that there are no values that pass the\n              \
    \  // filter. In that case we throw an exception.\n                auto has_initial_value\
    \ = next();\n                if (!has_initial_value) {\n                    Catch::throw_exception(GeneratorException(\"\
    No valid value found in filtered generator\"));\n                }\n         \
    \   }\n        }\n\n        T const& get() const override {\n            return\
    \ m_generator.get();\n        }\n\n        bool next() override {\n          \
    \  bool success = m_generator.next();\n            if (!success) {\n         \
    \       return false;\n            }\n            while (!m_predicate(m_generator.get())\
    \ && (success = m_generator.next()) == true);\n            return success;\n \
    \       }\n    };\n\n    template <typename T, typename Predicate>\n    GeneratorWrapper<T>\
    \ filter(Predicate&& pred, GeneratorWrapper<T>&& generator) {\n        return\
    \ GeneratorWrapper<T>(std::unique_ptr<IGenerator<T>>(pf::make_unique<FilterGenerator<T,\
    \ Predicate>>(std::forward<Predicate>(pred), std::move(generator))));\n    }\n\
    \n    template <typename T>\n    class RepeatGenerator : public IGenerator<T>\
    \ {\n        static_assert(!std::is_same<T, bool>::value,\n            \"RepeatGenerator\
    \ currently does not support bools\"\n            \"because of std::vector<bool>\
    \ specialization\");\n        GeneratorWrapper<T> m_generator;\n        mutable\
    \ std::vector<T> m_returned;\n        size_t m_target_repeats;\n        size_t\
    \ m_current_repeat = 0;\n        size_t m_repeat_index = 0;\n    public:\n   \
    \     RepeatGenerator(size_t repeats, GeneratorWrapper<T>&& generator):\n    \
    \        m_generator(std::move(generator)),\n            m_target_repeats(repeats)\n\
    \        {\n            assert(m_target_repeats > 0 && \"Repeat generator must\
    \ repeat at least once\");\n        }\n\n        T const& get() const override\
    \ {\n            if (m_current_repeat == 0) {\n                m_returned.push_back(m_generator.get());\n\
    \                return m_returned.back();\n            }\n            return\
    \ m_returned[m_repeat_index];\n        }\n\n        bool next() override {\n \
    \           // There are 2 basic cases:\n            // 1) We are still reading\
    \ the generator\n            // 2) We are reading our own cache\n\n          \
    \  // In the first case, we need to poke the underlying generator.\n         \
    \   // If it happily moves, we are left in that state, otherwise it is time to\
    \ start reading from our cache\n            if (m_current_repeat == 0) {\n   \
    \             const auto success = m_generator.next();\n                if (!success)\
    \ {\n                    ++m_current_repeat;\n                }\n            \
    \    return m_current_repeat < m_target_repeats;\n            }\n\n          \
    \  // In the second case, we need to move indices forward and check that we haven't\
    \ run up against the end\n            ++m_repeat_index;\n            if (m_repeat_index\
    \ == m_returned.size()) {\n                m_repeat_index = 0;\n             \
    \   ++m_current_repeat;\n            }\n            return m_current_repeat <\
    \ m_target_repeats;\n        }\n    };\n\n    template <typename T>\n    GeneratorWrapper<T>\
    \ repeat(size_t repeats, GeneratorWrapper<T>&& generator) {\n        return GeneratorWrapper<T>(pf::make_unique<RepeatGenerator<T>>(repeats,\
    \ std::move(generator)));\n    }\n\n    template <typename T, typename U, typename\
    \ Func>\n    class MapGenerator : public IGenerator<T> {\n        // TBD: provide\
    \ static assert for mapping function, for friendly error message\n        GeneratorWrapper<U>\
    \ m_generator;\n        Func m_function;\n        // To avoid returning dangling\
    \ reference, we have to save the values\n        T m_cache;\n    public:\n   \
    \     template <typename F2 = Func>\n        MapGenerator(F2&& function, GeneratorWrapper<U>&&\
    \ generator) :\n            m_generator(std::move(generator)),\n            m_function(std::forward<F2>(function)),\n\
    \            m_cache(m_function(m_generator.get()))\n        {}\n\n        T const&\
    \ get() const override {\n            return m_cache;\n        }\n        bool\
    \ next() override {\n            const auto success = m_generator.next();\n  \
    \          if (success) {\n                m_cache = m_function(m_generator.get());\n\
    \            }\n            return success;\n        }\n    };\n\n    template\
    \ <typename Func, typename U, typename T = FunctionReturnType<Func, U>>\n    GeneratorWrapper<T>\
    \ map(Func&& function, GeneratorWrapper<U>&& generator) {\n        return GeneratorWrapper<T>(\n\
    \            pf::make_unique<MapGenerator<T, U, Func>>(std::forward<Func>(function),\
    \ std::move(generator))\n        );\n    }\n\n    template <typename T, typename\
    \ U, typename Func>\n    GeneratorWrapper<T> map(Func&& function, GeneratorWrapper<U>&&\
    \ generator) {\n        return GeneratorWrapper<T>(\n            pf::make_unique<MapGenerator<T,\
    \ U, Func>>(std::forward<Func>(function), std::move(generator))\n        );\n\
    \    }\n\n    template <typename T>\n    class ChunkGenerator final : public IGenerator<std::vector<T>>\
    \ {\n        std::vector<T> m_chunk;\n        size_t m_chunk_size;\n        GeneratorWrapper<T>\
    \ m_generator;\n        bool m_used_up = false;\n    public:\n        ChunkGenerator(size_t\
    \ size, GeneratorWrapper<T> generator) :\n            m_chunk_size(size), m_generator(std::move(generator))\n\
    \        {\n            m_chunk.reserve(m_chunk_size);\n            if (m_chunk_size\
    \ != 0) {\n                m_chunk.push_back(m_generator.get());\n           \
    \     for (size_t i = 1; i < m_chunk_size; ++i) {\n                    if (!m_generator.next())\
    \ {\n                        Catch::throw_exception(GeneratorException(\"Not enough\
    \ values to initialize the first chunk\"));\n                    }\n         \
    \           m_chunk.push_back(m_generator.get());\n                }\n       \
    \     }\n        }\n        std::vector<T> const& get() const override {\n   \
    \         return m_chunk;\n        }\n        bool next() override {\n       \
    \     m_chunk.clear();\n            for (size_t idx = 0; idx < m_chunk_size; ++idx)\
    \ {\n                if (!m_generator.next()) {\n                    return false;\n\
    \                }\n                m_chunk.push_back(m_generator.get());\n  \
    \          }\n            return true;\n        }\n    };\n\n    template <typename\
    \ T>\n    GeneratorWrapper<std::vector<T>> chunk(size_t size, GeneratorWrapper<T>&&\
    \ generator) {\n        return GeneratorWrapper<std::vector<T>>(\n           \
    \ pf::make_unique<ChunkGenerator<T>>(size, std::move(generator))\n        );\n\
    \    }\n\n} // namespace Generators\n} // namespace Catch\n\n// end catch_generators_generic.hpp\n\
    // start catch_generators_specific.hpp\n\n// start catch_context.h\n\n#include\
    \ <memory>\n\nnamespace Catch {\n\n    struct IResultCapture;\n    struct IRunner;\n\
    \    struct IConfig;\n    struct IMutableContext;\n\n    using IConfigPtr = std::shared_ptr<IConfig\
    \ const>;\n\n    struct IContext\n    {\n        virtual ~IContext();\n\n    \
    \    virtual IResultCapture* getResultCapture() = 0;\n        virtual IRunner*\
    \ getRunner() = 0;\n        virtual IConfigPtr const& getConfig() const = 0;\n\
    \    };\n\n    struct IMutableContext : IContext\n    {\n        virtual ~IMutableContext();\n\
    \        virtual void setResultCapture( IResultCapture* resultCapture ) = 0;\n\
    \        virtual void setRunner( IRunner* runner ) = 0;\n        virtual void\
    \ setConfig( IConfigPtr const& config ) = 0;\n\n    private:\n        static IMutableContext\
    \ *currentContext;\n        friend IMutableContext& getCurrentMutableContext();\n\
    \        friend void cleanUpContext();\n        static void createContext();\n\
    \    };\n\n    inline IMutableContext& getCurrentMutableContext()\n    {\n   \
    \     if( !IMutableContext::currentContext )\n            IMutableContext::createContext();\n\
    \        // NOLINTNEXTLINE(clang-analyzer-core.uninitialized.UndefReturn)\n  \
    \      return *IMutableContext::currentContext;\n    }\n\n    inline IContext&\
    \ getCurrentContext()\n    {\n        return getCurrentMutableContext();\n   \
    \ }\n\n    void cleanUpContext();\n\n    class SimplePcg32;\n    SimplePcg32&\
    \ rng();\n}\n\n// end catch_context.h\n// start catch_interfaces_config.h\n\n\
    // start catch_option.hpp\n\nnamespace Catch {\n\n    // An optional type\n  \
    \  template<typename T>\n    class Option {\n    public:\n        Option() : nullableValue(\
    \ nullptr ) {}\n        Option( T const& _value )\n        : nullableValue( new(\
    \ storage ) T( _value ) )\n        {}\n        Option( Option const& _other )\n\
    \        : nullableValue( _other ? new( storage ) T( *_other ) : nullptr )\n \
    \       {}\n\n        ~Option() {\n            reset();\n        }\n\n       \
    \ Option& operator= ( Option const& _other ) {\n            if( &_other != this\
    \ ) {\n                reset();\n                if( _other )\n              \
    \      nullableValue = new( storage ) T( *_other );\n            }\n         \
    \   return *this;\n        }\n        Option& operator = ( T const& _value ) {\n\
    \            reset();\n            nullableValue = new( storage ) T( _value );\n\
    \            return *this;\n        }\n\n        void reset() {\n            if(\
    \ nullableValue )\n                nullableValue->~T();\n            nullableValue\
    \ = nullptr;\n        }\n\n        T& operator*() { return *nullableValue; }\n\
    \        T const& operator*() const { return *nullableValue; }\n        T* operator->()\
    \ { return nullableValue; }\n        const T* operator->() const { return nullableValue;\
    \ }\n\n        T valueOr( T const& defaultValue ) const {\n            return\
    \ nullableValue ? *nullableValue : defaultValue;\n        }\n\n        bool some()\
    \ const { return nullableValue != nullptr; }\n        bool none() const { return\
    \ nullableValue == nullptr; }\n\n        bool operator !() const { return nullableValue\
    \ == nullptr; }\n        explicit operator bool() const {\n            return\
    \ some();\n        }\n\n    private:\n        T *nullableValue;\n        alignas(alignof(T))\
    \ char storage[sizeof(T)];\n    };\n\n} // end namespace Catch\n\n// end catch_option.hpp\n\
    #include <chrono>\n#include <iosfwd>\n#include <string>\n#include <vector>\n#include\
    \ <memory>\n\nnamespace Catch {\n\n    enum class Verbosity {\n        Quiet =\
    \ 0,\n        Normal,\n        High\n    };\n\n    struct WarnAbout { enum What\
    \ {\n        Nothing = 0x00,\n        NoAssertions = 0x01,\n        NoTests =\
    \ 0x02\n    }; };\n\n    struct ShowDurations { enum OrNot {\n        DefaultForReporter,\n\
    \        Always,\n        Never\n    }; };\n    struct RunTests { enum InWhatOrder\
    \ {\n        InDeclarationOrder,\n        InLexicographicalOrder,\n        InRandomOrder\n\
    \    }; };\n    struct UseColour { enum YesOrNo {\n        Auto,\n        Yes,\n\
    \        No\n    }; };\n    struct WaitForKeypress { enum When {\n        Never,\n\
    \        BeforeStart = 1,\n        BeforeExit = 2,\n        BeforeStartAndExit\
    \ = BeforeStart | BeforeExit\n    }; };\n\n    class TestSpec;\n\n    struct IConfig\
    \ : NonCopyable {\n\n        virtual ~IConfig();\n\n        virtual bool allowThrows()\
    \ const = 0;\n        virtual std::ostream& stream() const = 0;\n        virtual\
    \ std::string name() const = 0;\n        virtual bool includeSuccessfulResults()\
    \ const = 0;\n        virtual bool shouldDebugBreak() const = 0;\n        virtual\
    \ bool warnAboutMissingAssertions() const = 0;\n        virtual bool warnAboutNoTests()\
    \ const = 0;\n        virtual int abortAfter() const = 0;\n        virtual bool\
    \ showInvisibles() const = 0;\n        virtual ShowDurations::OrNot showDurations()\
    \ const = 0;\n        virtual double minDuration() const = 0;\n        virtual\
    \ TestSpec const& testSpec() const = 0;\n        virtual bool hasTestFilters()\
    \ const = 0;\n        virtual std::vector<std::string> const& getTestsOrTags()\
    \ const = 0;\n        virtual RunTests::InWhatOrder runOrder() const = 0;\n  \
    \      virtual unsigned int rngSeed() const = 0;\n        virtual UseColour::YesOrNo\
    \ useColour() const = 0;\n        virtual std::vector<std::string> const& getSectionsToRun()\
    \ const = 0;\n        virtual Verbosity verbosity() const = 0;\n\n        virtual\
    \ bool benchmarkNoAnalysis() const = 0;\n        virtual int benchmarkSamples()\
    \ const = 0;\n        virtual double benchmarkConfidenceInterval() const = 0;\n\
    \        virtual unsigned int benchmarkResamples() const = 0;\n        virtual\
    \ std::chrono::milliseconds benchmarkWarmupTime() const = 0;\n    };\n\n    using\
    \ IConfigPtr = std::shared_ptr<IConfig const>;\n}\n\n// end catch_interfaces_config.h\n\
    // start catch_random_number_generator.h\n\n#include <cstdint>\n\nnamespace Catch\
    \ {\n\n    // This is a simple implementation of C++11 Uniform Random Number\n\
    \    // Generator. It does not provide all operators, because Catch2\n    // does\
    \ not use it, but it should behave as expected inside stdlib's\n    // distributions.\n\
    \    // The implementation is based on the PCG family (http://pcg-random.org)\n\
    \    class SimplePcg32 {\n        using state_type = std::uint64_t;\n    public:\n\
    \        using result_type = std::uint32_t;\n        static constexpr result_type\
    \ (min)() {\n            return 0;\n        }\n        static constexpr result_type\
    \ (max)() {\n            return static_cast<result_type>(-1);\n        }\n\n \
    \       // Provide some default initial state for the default constructor\n  \
    \      SimplePcg32():SimplePcg32(0xed743cc4U) {}\n\n        explicit SimplePcg32(result_type\
    \ seed_);\n\n        void seed(result_type seed_);\n        void discard(uint64_t\
    \ skip);\n\n        result_type operator()();\n\n    private:\n        friend\
    \ bool operator==(SimplePcg32 const& lhs, SimplePcg32 const& rhs);\n        friend\
    \ bool operator!=(SimplePcg32 const& lhs, SimplePcg32 const& rhs);\n\n       \
    \ // In theory we also need operator<< and operator>>\n        // In practice\
    \ we do not use them, so we will skip them for now\n\n        std::uint64_t m_state;\n\
    \        // This part of the state determines which \"stream\" of the numbers\n\
    \        // is chosen -- we take it as a constant for Catch2, so we only\n   \
    \     // need to deal with seeding the main state.\n        // Picked by reading\
    \ 8 bytes from `/dev/random` :-)\n        static const std::uint64_t s_inc = (0x13ed0cc53f939476ULL\
    \ << 1ULL) | 1ULL;\n    };\n\n} // end namespace Catch\n\n// end catch_random_number_generator.h\n\
    #include <random>\n\nnamespace Catch {\nnamespace Generators {\n\ntemplate <typename\
    \ Float>\nclass RandomFloatingGenerator final : public IGenerator<Float> {\n \
    \   Catch::SimplePcg32& m_rng;\n    std::uniform_real_distribution<Float> m_dist;\n\
    \    Float m_current_number;\npublic:\n\n    RandomFloatingGenerator(Float a,\
    \ Float b):\n        m_rng(rng()),\n        m_dist(a, b) {\n        static_cast<void>(next());\n\
    \    }\n\n    Float const& get() const override {\n        return m_current_number;\n\
    \    }\n    bool next() override {\n        m_current_number = m_dist(m_rng);\n\
    \        return true;\n    }\n};\n\ntemplate <typename Integer>\nclass RandomIntegerGenerator\
    \ final : public IGenerator<Integer> {\n    Catch::SimplePcg32& m_rng;\n    std::uniform_int_distribution<Integer>\
    \ m_dist;\n    Integer m_current_number;\npublic:\n\n    RandomIntegerGenerator(Integer\
    \ a, Integer b):\n        m_rng(rng()),\n        m_dist(a, b) {\n        static_cast<void>(next());\n\
    \    }\n\n    Integer const& get() const override {\n        return m_current_number;\n\
    \    }\n    bool next() override {\n        m_current_number = m_dist(m_rng);\n\
    \        return true;\n    }\n};\n\n// TODO: Ideally this would be also constrained\
    \ against the various char types,\n//       but I don't expect users to run into\
    \ that in practice.\ntemplate <typename T>\ntypename std::enable_if<std::is_integral<T>::value\
    \ && !std::is_same<T, bool>::value,\nGeneratorWrapper<T>>::type\nrandom(T a, T\
    \ b) {\n    return GeneratorWrapper<T>(\n        pf::make_unique<RandomIntegerGenerator<T>>(a,\
    \ b)\n    );\n}\n\ntemplate <typename T>\ntypename std::enable_if<std::is_floating_point<T>::value,\n\
    GeneratorWrapper<T>>::type\nrandom(T a, T b) {\n    return GeneratorWrapper<T>(\n\
    \        pf::make_unique<RandomFloatingGenerator<T>>(a, b)\n    );\n}\n\ntemplate\
    \ <typename T>\nclass RangeGenerator final : public IGenerator<T> {\n    T m_current;\n\
    \    T m_end;\n    T m_step;\n    bool m_positive;\n\npublic:\n    RangeGenerator(T\
    \ const& start, T const& end, T const& step):\n        m_current(start),\n   \
    \     m_end(end),\n        m_step(step),\n        m_positive(m_step > T(0))\n\
    \    {\n        assert(m_current != m_end && \"Range start and end cannot be equal\"\
    );\n        assert(m_step != T(0) && \"Step size cannot be zero\");\n        assert(((m_positive\
    \ && m_current <= m_end) || (!m_positive && m_current >= m_end)) && \"Step moves\
    \ away from end\");\n    }\n\n    RangeGenerator(T const& start, T const& end):\n\
    \        RangeGenerator(start, end, (start < end) ? T(1) : T(-1))\n    {}\n\n\
    \    T const& get() const override {\n        return m_current;\n    }\n\n   \
    \ bool next() override {\n        m_current += m_step;\n        return (m_positive)\
    \ ? (m_current < m_end) : (m_current > m_end);\n    }\n};\n\ntemplate <typename\
    \ T>\nGeneratorWrapper<T> range(T const& start, T const& end, T const& step) {\n\
    \    static_assert(std::is_arithmetic<T>::value && !std::is_same<T, bool>::value,\
    \ \"Type must be numeric\");\n    return GeneratorWrapper<T>(pf::make_unique<RangeGenerator<T>>(start,\
    \ end, step));\n}\n\ntemplate <typename T>\nGeneratorWrapper<T> range(T const&\
    \ start, T const& end) {\n    static_assert(std::is_integral<T>::value && !std::is_same<T,\
    \ bool>::value, \"Type must be an integer\");\n    return GeneratorWrapper<T>(pf::make_unique<RangeGenerator<T>>(start,\
    \ end));\n}\n\ntemplate <typename T>\nclass IteratorGenerator final : public IGenerator<T>\
    \ {\n    static_assert(!std::is_same<T, bool>::value,\n        \"IteratorGenerator\
    \ currently does not support bools\"\n        \"because of std::vector<bool> specialization\"\
    );\n\n    std::vector<T> m_elems;\n    size_t m_current = 0;\npublic:\n    template\
    \ <typename InputIterator, typename InputSentinel>\n    IteratorGenerator(InputIterator\
    \ first, InputSentinel last):m_elems(first, last) {\n        if (m_elems.empty())\
    \ {\n            Catch::throw_exception(GeneratorException(\"IteratorGenerator\
    \ received no valid values\"));\n        }\n    }\n\n    T const& get() const\
    \ override {\n        return m_elems[m_current];\n    }\n\n    bool next() override\
    \ {\n        ++m_current;\n        return m_current != m_elems.size();\n    }\n\
    };\n\ntemplate <typename InputIterator,\n          typename InputSentinel,\n \
    \         typename ResultType = typename std::iterator_traits<InputIterator>::value_type>\n\
    GeneratorWrapper<ResultType> from_range(InputIterator from, InputSentinel to)\
    \ {\n    return GeneratorWrapper<ResultType>(pf::make_unique<IteratorGenerator<ResultType>>(from,\
    \ to));\n}\n\ntemplate <typename Container,\n          typename ResultType = typename\
    \ Container::value_type>\nGeneratorWrapper<ResultType> from_range(Container const&\
    \ cnt) {\n    return GeneratorWrapper<ResultType>(pf::make_unique<IteratorGenerator<ResultType>>(cnt.begin(),\
    \ cnt.end()));\n}\n\n} // namespace Generators\n} // namespace Catch\n\n// end\
    \ catch_generators_specific.hpp\n\n// These files are included here so the single_include\
    \ script doesn't put them\n// in the conditionally compiled sections\n// start\
    \ catch_test_case_info.h\n\n#include <string>\n#include <vector>\n#include <memory>\n\
    \n#ifdef __clang__\n#pragma clang diagnostic push\n#pragma clang diagnostic ignored\
    \ \"-Wpadded\"\n#endif\n\nnamespace Catch {\n\n    struct ITestInvoker;\n\n  \
    \  struct TestCaseInfo {\n        enum SpecialProperties{\n            None =\
    \ 0,\n            IsHidden = 1 << 1,\n            ShouldFail = 1 << 2,\n     \
    \       MayFail = 1 << 3,\n            Throws = 1 << 4,\n            NonPortable\
    \ = 1 << 5,\n            Benchmark = 1 << 6\n        };\n\n        TestCaseInfo(\
    \   std::string const& _name,\n                        std::string const& _className,\n\
    \                        std::string const& _description,\n                  \
    \      std::vector<std::string> const& _tags,\n                        SourceLineInfo\
    \ const& _lineInfo );\n\n        friend void setTags( TestCaseInfo& testCaseInfo,\
    \ std::vector<std::string> tags );\n\n        bool isHidden() const;\n       \
    \ bool throws() const;\n        bool okToFail() const;\n        bool expectedToFail()\
    \ const;\n\n        std::string tagsAsString() const;\n\n        std::string name;\n\
    \        std::string className;\n        std::string description;\n        std::vector<std::string>\
    \ tags;\n        std::vector<std::string> lcaseTags;\n        SourceLineInfo lineInfo;\n\
    \        SpecialProperties properties;\n    };\n\n    class TestCase : public\
    \ TestCaseInfo {\n    public:\n\n        TestCase( ITestInvoker* testCase, TestCaseInfo&&\
    \ info );\n\n        TestCase withName( std::string const& _newName ) const;\n\
    \n        void invoke() const;\n\n        TestCaseInfo const& getTestCaseInfo()\
    \ const;\n\n        bool operator == ( TestCase const& other ) const;\n      \
    \  bool operator < ( TestCase const& other ) const;\n\n    private:\n        std::shared_ptr<ITestInvoker>\
    \ test;\n    };\n\n    TestCase makeTestCase(  ITestInvoker* testCase,\n     \
    \                       std::string const& className,\n                      \
    \      NameAndTags const& nameAndTags,\n                            SourceLineInfo\
    \ const& lineInfo );\n}\n\n#ifdef __clang__\n#pragma clang diagnostic pop\n#endif\n\
    \n// end catch_test_case_info.h\n// start catch_interfaces_runner.h\n\nnamespace\
    \ Catch {\n\n    struct IRunner {\n        virtual ~IRunner();\n        virtual\
    \ bool aborting() const = 0;\n    };\n}\n\n// end catch_interfaces_runner.h\n\n\
    #ifdef __OBJC__\n// start catch_objc.hpp\n\n#import <objc/runtime.h>\n\n#include\
    \ <string>\n\n// NB. Any general catch headers included here must be included\n\
    // in catch.hpp first to make sure they are included by the single\n// header\
    \ for non obj-usage\n\n///////////////////////////////////////////////////////////////////////////////\n\
    // This protocol is really only here for (self) documenting purposes, since\n\
    // all its methods are optional.\n@protocol OcFixture\n\n@optional\n\n-(void)\
    \ setUp;\n-(void) tearDown;\n\n@end\n\nnamespace Catch {\n\n    class OcMethod\
    \ : public ITestInvoker {\n\n    public:\n        OcMethod( Class cls, SEL sel\
    \ ) : m_cls( cls ), m_sel( sel ) {}\n\n        virtual void invoke() const {\n\
    \            id obj = [[m_cls alloc] init];\n\n            performOptionalSelector(\
    \ obj, @selector(setUp)  );\n            performOptionalSelector( obj, m_sel );\n\
    \            performOptionalSelector( obj, @selector(tearDown)  );\n\n       \
    \     arcSafeRelease( obj );\n        }\n    private:\n        virtual ~OcMethod()\
    \ {}\n\n        Class m_cls;\n        SEL m_sel;\n    };\n\n    namespace Detail{\n\
    \n        inline std::string getAnnotation(   Class cls,\n                   \
    \                         std::string const& annotationName,\n               \
    \                             std::string const& testCaseName ) {\n          \
    \  NSString* selStr = [[NSString alloc] initWithFormat:@\"Catch_%s_%s\", annotationName.c_str(),\
    \ testCaseName.c_str()];\n            SEL sel = NSSelectorFromString( selStr );\n\
    \            arcSafeRelease( selStr );\n            id value = performOptionalSelector(\
    \ cls, sel );\n            if( value )\n                return [(NSString*)value\
    \ UTF8String];\n            return \"\";\n        }\n    }\n\n    inline std::size_t\
    \ registerTestMethods() {\n        std::size_t noTestMethods = 0;\n        int\
    \ noClasses = objc_getClassList( nullptr, 0 );\n\n        Class* classes = (CATCH_UNSAFE_UNRETAINED\
    \ Class *)malloc( sizeof(Class) * noClasses);\n        objc_getClassList( classes,\
    \ noClasses );\n\n        for( int c = 0; c < noClasses; c++ ) {\n           \
    \ Class cls = classes[c];\n            {\n                u_int count;\n     \
    \           Method* methods = class_copyMethodList( cls, &count );\n         \
    \       for( u_int m = 0; m < count ; m++ ) {\n                    SEL selector\
    \ = method_getName(methods[m]);\n                    std::string methodName =\
    \ sel_getName(selector);\n                    if( startsWith( methodName, \"Catch_TestCase_\"\
    \ ) ) {\n                        std::string testCaseName = methodName.substr(\
    \ 15 );\n                        std::string name = Detail::getAnnotation( cls,\
    \ \"Name\", testCaseName );\n                        std::string desc = Detail::getAnnotation(\
    \ cls, \"Description\", testCaseName );\n                        const char* className\
    \ = class_getName( cls );\n\n                        getMutableRegistryHub().registerTest(\
    \ makeTestCase( new OcMethod( cls, selector ), className, NameAndTags( name.c_str(),\
    \ desc.c_str() ), SourceLineInfo(\"\",0) ) );\n                        noTestMethods++;\n\
    \                    }\n                }\n                free(methods);\n  \
    \          }\n        }\n        return noTestMethods;\n    }\n\n#if !defined(CATCH_CONFIG_DISABLE_MATCHERS)\n\
    \n    namespace Matchers {\n        namespace Impl {\n        namespace NSStringMatchers\
    \ {\n\n            struct StringHolder : MatcherBase<NSString*>{\n           \
    \     StringHolder( NSString* substr ) : m_substr( [substr copy] ){}\n       \
    \         StringHolder( StringHolder const& other ) : m_substr( [other.m_substr\
    \ copy] ){}\n                StringHolder() {\n                    arcSafeRelease(\
    \ m_substr );\n                }\n\n                bool match( NSString* str\
    \ ) const override {\n                    return false;\n                }\n\n\
    \                NSString* CATCH_ARC_STRONG m_substr;\n            };\n\n    \
    \        struct Equals : StringHolder {\n                Equals( NSString* substr\
    \ ) : StringHolder( substr ){}\n\n                bool match( NSString* str )\
    \ const override {\n                    return  (str != nil || m_substr == nil\
    \ ) &&\n                            [str isEqualToString:m_substr];\n        \
    \        }\n\n                std::string describe() const override {\n      \
    \              return \"equals string: \" + Catch::Detail::stringify( m_substr\
    \ );\n                }\n            };\n\n            struct Contains : StringHolder\
    \ {\n                Contains( NSString* substr ) : StringHolder( substr ){}\n\
    \n                bool match( NSString* str ) const override {\n             \
    \       return  (str != nil || m_substr == nil ) &&\n                        \
    \    [str rangeOfString:m_substr].location != NSNotFound;\n                }\n\
    \n                std::string describe() const override {\n                  \
    \  return \"contains string: \" + Catch::Detail::stringify( m_substr );\n    \
    \            }\n            };\n\n            struct StartsWith : StringHolder\
    \ {\n                StartsWith( NSString* substr ) : StringHolder( substr ){}\n\
    \n                bool match( NSString* str ) const override {\n             \
    \       return  (str != nil || m_substr == nil ) &&\n                        \
    \    [str rangeOfString:m_substr].location == 0;\n                }\n\n      \
    \          std::string describe() const override {\n                    return\
    \ \"starts with: \" + Catch::Detail::stringify( m_substr );\n                }\n\
    \            };\n            struct EndsWith : StringHolder {\n              \
    \  EndsWith( NSString* substr ) : StringHolder( substr ){}\n\n               \
    \ bool match( NSString* str ) const override {\n                    return  (str\
    \ != nil || m_substr == nil ) &&\n                            [str rangeOfString:m_substr].location\
    \ == [str length] - [m_substr length];\n                }\n\n                std::string\
    \ describe() const override {\n                    return \"ends with: \" + Catch::Detail::stringify(\
    \ m_substr );\n                }\n            };\n\n        } // namespace NSStringMatchers\n\
    \        } // namespace Impl\n\n        inline Impl::NSStringMatchers::Equals\n\
    \            Equals( NSString* substr ){ return Impl::NSStringMatchers::Equals(\
    \ substr ); }\n\n        inline Impl::NSStringMatchers::Contains\n           \
    \ Contains( NSString* substr ){ return Impl::NSStringMatchers::Contains( substr\
    \ ); }\n\n        inline Impl::NSStringMatchers::StartsWith\n            StartsWith(\
    \ NSString* substr ){ return Impl::NSStringMatchers::StartsWith( substr ); }\n\
    \n        inline Impl::NSStringMatchers::EndsWith\n            EndsWith( NSString*\
    \ substr ){ return Impl::NSStringMatchers::EndsWith( substr ); }\n\n    } // namespace\
    \ Matchers\n\n    using namespace Matchers;\n\n#endif // CATCH_CONFIG_DISABLE_MATCHERS\n\
    \n} // namespace Catch\n\n///////////////////////////////////////////////////////////////////////////////\n\
    #define OC_MAKE_UNIQUE_NAME( root, uniqueSuffix ) root##uniqueSuffix\n#define\
    \ OC_TEST_CASE2( name, desc, uniqueSuffix ) \\\n+(NSString*) OC_MAKE_UNIQUE_NAME(\
    \ Catch_Name_test_, uniqueSuffix ) \\\n{ \\\nreturn @ name; \\\n} \\\n+(NSString*)\
    \ OC_MAKE_UNIQUE_NAME( Catch_Description_test_, uniqueSuffix ) \\\n{ \\\nreturn\
    \ @ desc; \\\n} \\\n-(void) OC_MAKE_UNIQUE_NAME( Catch_TestCase_test_, uniqueSuffix\
    \ )\n\n#define OC_TEST_CASE( name, desc ) OC_TEST_CASE2( name, desc, __LINE__\
    \ )\n\n// end catch_objc.hpp\n#endif\n\n// Benchmarking needs the externally-facing\
    \ parts of reporters to work\n#if defined(CATCH_CONFIG_EXTERNAL_INTERFACES) ||\
    \ defined(CATCH_CONFIG_ENABLE_BENCHMARKING)\n// start catch_external_interfaces.h\n\
    \n// start catch_reporter_bases.hpp\n\n// start catch_interfaces_reporter.h\n\n\
    // start catch_config.hpp\n\n// start catch_test_spec_parser.h\n\n#ifdef __clang__\n\
    #pragma clang diagnostic push\n#pragma clang diagnostic ignored \"-Wpadded\"\n\
    #endif\n\n// start catch_test_spec.h\n\n#ifdef __clang__\n#pragma clang diagnostic\
    \ push\n#pragma clang diagnostic ignored \"-Wpadded\"\n#endif\n\n// start catch_wildcard_pattern.h\n\
    \nnamespace Catch\n{\n    class WildcardPattern {\n        enum WildcardPosition\
    \ {\n            NoWildcard = 0,\n            WildcardAtStart = 1,\n         \
    \   WildcardAtEnd = 2,\n            WildcardAtBothEnds = WildcardAtStart | WildcardAtEnd\n\
    \        };\n\n    public:\n\n        WildcardPattern( std::string const& pattern,\
    \ CaseSensitive::Choice caseSensitivity );\n        virtual ~WildcardPattern()\
    \ = default;\n        virtual bool matches( std::string const& str ) const;\n\n\
    \    private:\n        std::string normaliseString( std::string const& str ) const;\n\
    \        CaseSensitive::Choice m_caseSensitivity;\n        WildcardPosition m_wildcard\
    \ = NoWildcard;\n        std::string m_pattern;\n    };\n}\n\n// end catch_wildcard_pattern.h\n\
    #include <string>\n#include <vector>\n#include <memory>\n\nnamespace Catch {\n\
    \n    struct IConfig;\n\n    class TestSpec {\n        class Pattern {\n     \
    \   public:\n            explicit Pattern( std::string const& name );\n      \
    \      virtual ~Pattern();\n            virtual bool matches( TestCaseInfo const&\
    \ testCase ) const = 0;\n            std::string const& name() const;\n      \
    \  private:\n            std::string const m_name;\n        };\n        using\
    \ PatternPtr = std::shared_ptr<Pattern>;\n\n        class NamePattern : public\
    \ Pattern {\n        public:\n            explicit NamePattern( std::string const&\
    \ name, std::string const& filterString );\n            bool matches( TestCaseInfo\
    \ const& testCase ) const override;\n        private:\n            WildcardPattern\
    \ m_wildcardPattern;\n        };\n\n        class TagPattern : public Pattern\
    \ {\n        public:\n            explicit TagPattern( std::string const& tag,\
    \ std::string const& filterString );\n            bool matches( TestCaseInfo const&\
    \ testCase ) const override;\n        private:\n            std::string m_tag;\n\
    \        };\n\n        class ExcludedPattern : public Pattern {\n        public:\n\
    \            explicit ExcludedPattern( PatternPtr const& underlyingPattern );\n\
    \            bool matches( TestCaseInfo const& testCase ) const override;\n  \
    \      private:\n            PatternPtr m_underlyingPattern;\n        };\n\n \
    \       struct Filter {\n            std::vector<PatternPtr> m_patterns;\n\n \
    \           bool matches( TestCaseInfo const& testCase ) const;\n            std::string\
    \ name() const;\n        };\n\n    public:\n        struct FilterMatch {\n   \
    \         std::string name;\n            std::vector<TestCase const*> tests;\n\
    \        };\n        using Matches = std::vector<FilterMatch>;\n        using\
    \ vectorStrings = std::vector<std::string>;\n\n        bool hasFilters() const;\n\
    \        bool matches( TestCaseInfo const& testCase ) const;\n        Matches\
    \ matchesByFilter( std::vector<TestCase> const& testCases, IConfig const& config\
    \ ) const;\n        const vectorStrings & getInvalidArgs() const;\n\n    private:\n\
    \        std::vector<Filter> m_filters;\n        std::vector<std::string> m_invalidArgs;\n\
    \        friend class TestSpecParser;\n    };\n}\n\n#ifdef __clang__\n#pragma\
    \ clang diagnostic pop\n#endif\n\n// end catch_test_spec.h\n// start catch_interfaces_tag_alias_registry.h\n\
    \n#include <string>\n\nnamespace Catch {\n\n    struct TagAlias;\n\n    struct\
    \ ITagAliasRegistry {\n        virtual ~ITagAliasRegistry();\n        // Nullptr\
    \ if not present\n        virtual TagAlias const* find( std::string const& alias\
    \ ) const = 0;\n        virtual std::string expandAliases( std::string const&\
    \ unexpandedTestSpec ) const = 0;\n\n        static ITagAliasRegistry const& get();\n\
    \    };\n\n} // end namespace Catch\n\n// end catch_interfaces_tag_alias_registry.h\n\
    namespace Catch {\n\n    class TestSpecParser {\n        enum Mode{ None, Name,\
    \ QuotedName, Tag, EscapedName };\n        Mode m_mode = None;\n        Mode lastMode\
    \ = None;\n        bool m_exclusion = false;\n        std::size_t m_pos = 0;\n\
    \        std::size_t m_realPatternPos = 0;\n        std::string m_arg;\n     \
    \   std::string m_substring;\n        std::string m_patternName;\n        std::vector<std::size_t>\
    \ m_escapeChars;\n        TestSpec::Filter m_currentFilter;\n        TestSpec\
    \ m_testSpec;\n        ITagAliasRegistry const* m_tagAliases = nullptr;\n\n  \
    \  public:\n        TestSpecParser( ITagAliasRegistry const& tagAliases );\n\n\
    \        TestSpecParser& parse( std::string const& arg );\n        TestSpec testSpec();\n\
    \n    private:\n        bool visitChar( char c );\n        void startNewMode(\
    \ Mode mode );\n        bool processNoneChar( char c );\n        void processNameChar(\
    \ char c );\n        bool processOtherChar( char c );\n        void endMode();\n\
    \        void escape();\n        bool isControlChar( char c ) const;\n       \
    \ void saveLastMode();\n        void revertBackToLastMode();\n        void addFilter();\n\
    \        bool separate();\n\n        // Handles common preprocessing of the pattern\
    \ for name/tag patterns\n        std::string preprocessPattern();\n        //\
    \ Adds the current pattern as a test name\n        void addNamePattern();\n  \
    \      // Adds the current pattern as a tag\n        void addTagPattern();\n\n\
    \        inline void addCharToPattern(char c) {\n            m_substring += c;\n\
    \            m_patternName += c;\n            m_realPatternPos++;\n        }\n\
    \n    };\n    TestSpec parseTestSpec( std::string const& arg );\n\n} // namespace\
    \ Catch\n\n#ifdef __clang__\n#pragma clang diagnostic pop\n#endif\n\n// end catch_test_spec_parser.h\n\
    // Libstdc++ doesn't like incomplete classes for unique_ptr\n\n#include <memory>\n\
    #include <vector>\n#include <string>\n\n#ifndef CATCH_CONFIG_CONSOLE_WIDTH\n#define\
    \ CATCH_CONFIG_CONSOLE_WIDTH 80\n#endif\n\nnamespace Catch {\n\n    struct IStream;\n\
    \n    struct ConfigData {\n        bool listTests = false;\n        bool listTags\
    \ = false;\n        bool listReporters = false;\n        bool listTestNamesOnly\
    \ = false;\n\n        bool showSuccessfulTests = false;\n        bool shouldDebugBreak\
    \ = false;\n        bool noThrow = false;\n        bool showHelp = false;\n  \
    \      bool showInvisibles = false;\n        bool filenamesAsTags = false;\n \
    \       bool libIdentify = false;\n\n        int abortAfter = -1;\n        unsigned\
    \ int rngSeed = 0;\n\n        bool benchmarkNoAnalysis = false;\n        unsigned\
    \ int benchmarkSamples = 100;\n        double benchmarkConfidenceInterval = 0.95;\n\
    \        unsigned int benchmarkResamples = 100000;\n        std::chrono::milliseconds::rep\
    \ benchmarkWarmupTime = 100;\n\n        Verbosity verbosity = Verbosity::Normal;\n\
    \        WarnAbout::What warnings = WarnAbout::Nothing;\n        ShowDurations::OrNot\
    \ showDurations = ShowDurations::DefaultForReporter;\n        double minDuration\
    \ = -1;\n        RunTests::InWhatOrder runOrder = RunTests::InDeclarationOrder;\n\
    \        UseColour::YesOrNo useColour = UseColour::Auto;\n        WaitForKeypress::When\
    \ waitForKeypress = WaitForKeypress::Never;\n\n        std::string outputFilename;\n\
    \        std::string name;\n        std::string processName;\n#ifndef CATCH_CONFIG_DEFAULT_REPORTER\n\
    #define CATCH_CONFIG_DEFAULT_REPORTER \"console\"\n#endif\n        std::string\
    \ reporterName = CATCH_CONFIG_DEFAULT_REPORTER;\n#undef CATCH_CONFIG_DEFAULT_REPORTER\n\
    \n        std::vector<std::string> testsOrTags;\n        std::vector<std::string>\
    \ sectionsToRun;\n    };\n\n    class Config : public IConfig {\n    public:\n\
    \n        Config() = default;\n        Config( ConfigData const& data );\n   \
    \     virtual ~Config() = default;\n\n        std::string const& getFilename()\
    \ const;\n\n        bool listTests() const;\n        bool listTestNamesOnly()\
    \ const;\n        bool listTags() const;\n        bool listReporters() const;\n\
    \n        std::string getProcessName() const;\n        std::string const& getReporterName()\
    \ const;\n\n        std::vector<std::string> const& getTestsOrTags() const override;\n\
    \        std::vector<std::string> const& getSectionsToRun() const override;\n\n\
    \        TestSpec const& testSpec() const override;\n        bool hasTestFilters()\
    \ const override;\n\n        bool showHelp() const;\n\n        // IConfig interface\n\
    \        bool allowThrows() const override;\n        std::ostream& stream() const\
    \ override;\n        std::string name() const override;\n        bool includeSuccessfulResults()\
    \ const override;\n        bool warnAboutMissingAssertions() const override;\n\
    \        bool warnAboutNoTests() const override;\n        ShowDurations::OrNot\
    \ showDurations() const override;\n        double minDuration() const override;\n\
    \        RunTests::InWhatOrder runOrder() const override;\n        unsigned int\
    \ rngSeed() const override;\n        UseColour::YesOrNo useColour() const override;\n\
    \        bool shouldDebugBreak() const override;\n        int abortAfter() const\
    \ override;\n        bool showInvisibles() const override;\n        Verbosity\
    \ verbosity() const override;\n        bool benchmarkNoAnalysis() const override;\n\
    \        int benchmarkSamples() const override;\n        double benchmarkConfidenceInterval()\
    \ const override;\n        unsigned int benchmarkResamples() const override;\n\
    \        std::chrono::milliseconds benchmarkWarmupTime() const override;\n\n \
    \   private:\n\n        IStream const* openStream();\n        ConfigData m_data;\n\
    \n        std::unique_ptr<IStream const> m_stream;\n        TestSpec m_testSpec;\n\
    \        bool m_hasTestFilters = false;\n    };\n\n} // end namespace Catch\n\n\
    // end catch_config.hpp\n// start catch_assertionresult.h\n\n#include <string>\n\
    \nnamespace Catch {\n\n    struct AssertionResultData\n    {\n        AssertionResultData()\
    \ = delete;\n\n        AssertionResultData( ResultWas::OfType _resultType, LazyExpression\
    \ const& _lazyExpression );\n\n        std::string message;\n        mutable std::string\
    \ reconstructedExpression;\n        LazyExpression lazyExpression;\n        ResultWas::OfType\
    \ resultType;\n\n        std::string reconstructExpression() const;\n    };\n\n\
    \    class AssertionResult {\n    public:\n        AssertionResult() = delete;\n\
    \        AssertionResult( AssertionInfo const& info, AssertionResultData const&\
    \ data );\n\n        bool isOk() const;\n        bool succeeded() const;\n   \
    \     ResultWas::OfType getResultType() const;\n        bool hasExpression() const;\n\
    \        bool hasMessage() const;\n        std::string getExpression() const;\n\
    \        std::string getExpressionInMacro() const;\n        bool hasExpandedExpression()\
    \ const;\n        std::string getExpandedExpression() const;\n        std::string\
    \ getMessage() const;\n        SourceLineInfo getSourceInfo() const;\n       \
    \ StringRef getTestMacroName() const;\n\n    //protected:\n        AssertionInfo\
    \ m_info;\n        AssertionResultData m_resultData;\n    };\n\n} // end namespace\
    \ Catch\n\n// end catch_assertionresult.h\n#if defined(CATCH_CONFIG_ENABLE_BENCHMARKING)\n\
    // start catch_estimate.hpp\n\n // Statistics estimates\n\n\nnamespace Catch {\n\
    \    namespace Benchmark {\n        template <typename Duration>\n        struct\
    \ Estimate {\n            Duration point;\n            Duration lower_bound;\n\
    \            Duration upper_bound;\n            double confidence_interval;\n\n\
    \            template <typename Duration2>\n            operator Estimate<Duration2>()\
    \ const {\n                return { point, lower_bound, upper_bound, confidence_interval\
    \ };\n            }\n        };\n    } // namespace Benchmark\n} // namespace\
    \ Catch\n\n// end catch_estimate.hpp\n// start catch_outlier_classification.hpp\n\
    \n// Outlier information\n\nnamespace Catch {\n    namespace Benchmark {\n   \
    \     struct OutlierClassification {\n            int samples_seen = 0;\n    \
    \        int low_severe = 0;     // more than 3 times IQR below Q1\n         \
    \   int low_mild = 0;       // 1.5 to 3 times IQR below Q1\n            int high_mild\
    \ = 0;      // 1.5 to 3 times IQR above Q3\n            int high_severe = 0; \
    \   // more than 3 times IQR above Q3\n\n            int total() const {\n   \
    \             return low_severe + low_mild + high_mild + high_severe;\n      \
    \      }\n        };\n    } // namespace Benchmark\n} // namespace Catch\n\n//\
    \ end catch_outlier_classification.hpp\n#endif // CATCH_CONFIG_ENABLE_BENCHMARKING\n\
    \n#include <string>\n#include <iosfwd>\n#include <map>\n#include <set>\n#include\
    \ <memory>\n#include <algorithm>\n\nnamespace Catch {\n\n    struct ReporterConfig\
    \ {\n        explicit ReporterConfig( IConfigPtr const& _fullConfig );\n\n   \
    \     ReporterConfig( IConfigPtr const& _fullConfig, std::ostream& _stream );\n\
    \n        std::ostream& stream() const;\n        IConfigPtr fullConfig() const;\n\
    \n    private:\n        std::ostream* m_stream;\n        IConfigPtr m_fullConfig;\n\
    \    };\n\n    struct ReporterPreferences {\n        bool shouldRedirectStdOut\
    \ = false;\n        bool shouldReportAllAssertions = false;\n    };\n\n    template<typename\
    \ T>\n    struct LazyStat : Option<T> {\n        LazyStat& operator=( T const&\
    \ _value ) {\n            Option<T>::operator=( _value );\n            used =\
    \ false;\n            return *this;\n        }\n        void reset() {\n     \
    \       Option<T>::reset();\n            used = false;\n        }\n        bool\
    \ used = false;\n    };\n\n    struct TestRunInfo {\n        TestRunInfo( std::string\
    \ const& _name );\n        std::string name;\n    };\n    struct GroupInfo {\n\
    \        GroupInfo(  std::string const& _name,\n                    std::size_t\
    \ _groupIndex,\n                    std::size_t _groupsCount );\n\n        std::string\
    \ name;\n        std::size_t groupIndex;\n        std::size_t groupsCounts;\n\
    \    };\n\n    struct AssertionStats {\n        AssertionStats( AssertionResult\
    \ const& _assertionResult,\n                        std::vector<MessageInfo> const&\
    \ _infoMessages,\n                        Totals const& _totals );\n\n       \
    \ AssertionStats( AssertionStats const& )              = default;\n        AssertionStats(\
    \ AssertionStats && )                  = default;\n        AssertionStats& operator\
    \ = ( AssertionStats const& ) = delete;\n        AssertionStats& operator = (\
    \ AssertionStats && )     = delete;\n        virtual ~AssertionStats();\n\n  \
    \      AssertionResult assertionResult;\n        std::vector<MessageInfo> infoMessages;\n\
    \        Totals totals;\n    };\n\n    struct SectionStats {\n        SectionStats(\
    \   SectionInfo const& _sectionInfo,\n                        Counts const& _assertions,\n\
    \                        double _durationInSeconds,\n                        bool\
    \ _missingAssertions );\n        SectionStats( SectionStats const& )         \
    \     = default;\n        SectionStats( SectionStats && )                  = default;\n\
    \        SectionStats& operator = ( SectionStats const& ) = default;\n       \
    \ SectionStats& operator = ( SectionStats && )     = default;\n        virtual\
    \ ~SectionStats();\n\n        SectionInfo sectionInfo;\n        Counts assertions;\n\
    \        double durationInSeconds;\n        bool missingAssertions;\n    };\n\n\
    \    struct TestCaseStats {\n        TestCaseStats(  TestCaseInfo const& _testInfo,\n\
    \                        Totals const& _totals,\n                        std::string\
    \ const& _stdOut,\n                        std::string const& _stdErr,\n     \
    \                   bool _aborting );\n\n        TestCaseStats( TestCaseStats\
    \ const& )              = default;\n        TestCaseStats( TestCaseStats && )\
    \                  = default;\n        TestCaseStats& operator = ( TestCaseStats\
    \ const& ) = default;\n        TestCaseStats& operator = ( TestCaseStats && )\
    \     = default;\n        virtual ~TestCaseStats();\n\n        TestCaseInfo testInfo;\n\
    \        Totals totals;\n        std::string stdOut;\n        std::string stdErr;\n\
    \        bool aborting;\n    };\n\n    struct TestGroupStats {\n        TestGroupStats(\
    \ GroupInfo const& _groupInfo,\n                        Totals const& _totals,\n\
    \                        bool _aborting );\n        TestGroupStats( GroupInfo\
    \ const& _groupInfo );\n\n        TestGroupStats( TestGroupStats const& )    \
    \          = default;\n        TestGroupStats( TestGroupStats && )           \
    \       = default;\n        TestGroupStats& operator = ( TestGroupStats const&\
    \ ) = default;\n        TestGroupStats& operator = ( TestGroupStats && )     =\
    \ default;\n        virtual ~TestGroupStats();\n\n        GroupInfo groupInfo;\n\
    \        Totals totals;\n        bool aborting;\n    };\n\n    struct TestRunStats\
    \ {\n        TestRunStats(   TestRunInfo const& _runInfo,\n                  \
    \      Totals const& _totals,\n                        bool _aborting );\n\n \
    \       TestRunStats( TestRunStats const& )              = default;\n        TestRunStats(\
    \ TestRunStats && )                  = default;\n        TestRunStats& operator\
    \ = ( TestRunStats const& ) = default;\n        TestRunStats& operator = ( TestRunStats\
    \ && )     = default;\n        virtual ~TestRunStats();\n\n        TestRunInfo\
    \ runInfo;\n        Totals totals;\n        bool aborting;\n    };\n\n#if defined(CATCH_CONFIG_ENABLE_BENCHMARKING)\n\
    \    struct BenchmarkInfo {\n        std::string name;\n        double estimatedDuration;\n\
    \        int iterations;\n        int samples;\n        unsigned int resamples;\n\
    \        double clockResolution;\n        double clockCost;\n    };\n\n    template\
    \ <class Duration>\n    struct BenchmarkStats {\n        BenchmarkInfo info;\n\
    \n        std::vector<Duration> samples;\n        Benchmark::Estimate<Duration>\
    \ mean;\n        Benchmark::Estimate<Duration> standardDeviation;\n        Benchmark::OutlierClassification\
    \ outliers;\n        double outlierVariance;\n\n        template <typename Duration2>\n\
    \        operator BenchmarkStats<Duration2>() const {\n            std::vector<Duration2>\
    \ samples2;\n            samples2.reserve(samples.size());\n            std::transform(samples.begin(),\
    \ samples.end(), std::back_inserter(samples2), [](Duration d) { return Duration2(d);\
    \ });\n            return {\n                info,\n                std::move(samples2),\n\
    \                mean,\n                standardDeviation,\n                outliers,\n\
    \                outlierVariance,\n            };\n        }\n    };\n#endif //\
    \ CATCH_CONFIG_ENABLE_BENCHMARKING\n\n    struct IStreamingReporter {\n      \
    \  virtual ~IStreamingReporter() = default;\n\n        // Implementing class must\
    \ also provide the following static methods:\n        // static std::string getDescription();\n\
    \        // static std::set<Verbosity> getSupportedVerbosities()\n\n        virtual\
    \ ReporterPreferences getPreferences() const = 0;\n\n        virtual void noMatchingTestCases(\
    \ std::string const& spec ) = 0;\n\n        virtual void reportInvalidArguments(std::string\
    \ const&) {}\n\n        virtual void testRunStarting( TestRunInfo const& testRunInfo\
    \ ) = 0;\n        virtual void testGroupStarting( GroupInfo const& groupInfo )\
    \ = 0;\n\n        virtual void testCaseStarting( TestCaseInfo const& testInfo\
    \ ) = 0;\n        virtual void sectionStarting( SectionInfo const& sectionInfo\
    \ ) = 0;\n\n#if defined(CATCH_CONFIG_ENABLE_BENCHMARKING)\n        virtual void\
    \ benchmarkPreparing( std::string const& ) {}\n        virtual void benchmarkStarting(\
    \ BenchmarkInfo const& ) {}\n        virtual void benchmarkEnded( BenchmarkStats<>\
    \ const& ) {}\n        virtual void benchmarkFailed( std::string const& ) {}\n\
    #endif // CATCH_CONFIG_ENABLE_BENCHMARKING\n\n        virtual void assertionStarting(\
    \ AssertionInfo const& assertionInfo ) = 0;\n\n        // The return value indicates\
    \ if the messages buffer should be cleared:\n        virtual bool assertionEnded(\
    \ AssertionStats const& assertionStats ) = 0;\n\n        virtual void sectionEnded(\
    \ SectionStats const& sectionStats ) = 0;\n        virtual void testCaseEnded(\
    \ TestCaseStats const& testCaseStats ) = 0;\n        virtual void testGroupEnded(\
    \ TestGroupStats const& testGroupStats ) = 0;\n        virtual void testRunEnded(\
    \ TestRunStats const& testRunStats ) = 0;\n\n        virtual void skipTest( TestCaseInfo\
    \ const& testInfo ) = 0;\n\n        // Default empty implementation provided\n\
    \        virtual void fatalErrorEncountered( StringRef name );\n\n        virtual\
    \ bool isMulti() const;\n    };\n    using IStreamingReporterPtr = std::unique_ptr<IStreamingReporter>;\n\
    \n    struct IReporterFactory {\n        virtual ~IReporterFactory();\n      \
    \  virtual IStreamingReporterPtr create( ReporterConfig const& config ) const\
    \ = 0;\n        virtual std::string getDescription() const = 0;\n    };\n    using\
    \ IReporterFactoryPtr = std::shared_ptr<IReporterFactory>;\n\n    struct IReporterRegistry\
    \ {\n        using FactoryMap = std::map<std::string, IReporterFactoryPtr>;\n\
    \        using Listeners = std::vector<IReporterFactoryPtr>;\n\n        virtual\
    \ ~IReporterRegistry();\n        virtual IStreamingReporterPtr create( std::string\
    \ const& name, IConfigPtr const& config ) const = 0;\n        virtual FactoryMap\
    \ const& getFactories() const = 0;\n        virtual Listeners const& getListeners()\
    \ const = 0;\n    };\n\n} // end namespace Catch\n\n// end catch_interfaces_reporter.h\n\
    #include <algorithm>\n#include <cstring>\n#include <cfloat>\n#include <cstdio>\n\
    #include <cassert>\n#include <memory>\n#include <ostream>\n\nnamespace Catch {\n\
    \    void prepareExpandedExpression(AssertionResult& result);\n\n    // Returns\
    \ double formatted as %.3f (format expected on output)\n    std::string getFormattedDuration(\
    \ double duration );\n\n    //! Should the reporter show\n    bool shouldShowDuration(\
    \ IConfig const& config, double duration );\n\n    std::string serializeFilters(\
    \ std::vector<std::string> const& container );\n\n    template<typename DerivedT>\n\
    \    struct StreamingReporterBase : IStreamingReporter {\n\n        StreamingReporterBase(\
    \ ReporterConfig const& _config )\n        :   m_config( _config.fullConfig()\
    \ ),\n            stream( _config.stream() )\n        {\n            m_reporterPrefs.shouldRedirectStdOut\
    \ = false;\n            if( !DerivedT::getSupportedVerbosities().count( m_config->verbosity()\
    \ ) )\n                CATCH_ERROR( \"Verbosity level not supported by this reporter\"\
    \ );\n        }\n\n        ReporterPreferences getPreferences() const override\
    \ {\n            return m_reporterPrefs;\n        }\n\n        static std::set<Verbosity>\
    \ getSupportedVerbosities() {\n            return { Verbosity::Normal };\n   \
    \     }\n\n        ~StreamingReporterBase() override = default;\n\n        void\
    \ noMatchingTestCases(std::string const&) override {}\n\n        void reportInvalidArguments(std::string\
    \ const&) override {}\n\n        void testRunStarting(TestRunInfo const& _testRunInfo)\
    \ override {\n            currentTestRunInfo = _testRunInfo;\n        }\n\n  \
    \      void testGroupStarting(GroupInfo const& _groupInfo) override {\n      \
    \      currentGroupInfo = _groupInfo;\n        }\n\n        void testCaseStarting(TestCaseInfo\
    \ const& _testInfo) override  {\n            currentTestCaseInfo = _testInfo;\n\
    \        }\n        void sectionStarting(SectionInfo const& _sectionInfo) override\
    \ {\n            m_sectionStack.push_back(_sectionInfo);\n        }\n\n      \
    \  void sectionEnded(SectionStats const& /* _sectionStats */) override {\n   \
    \         m_sectionStack.pop_back();\n        }\n        void testCaseEnded(TestCaseStats\
    \ const& /* _testCaseStats */) override {\n            currentTestCaseInfo.reset();\n\
    \        }\n        void testGroupEnded(TestGroupStats const& /* _testGroupStats\
    \ */) override {\n            currentGroupInfo.reset();\n        }\n        void\
    \ testRunEnded(TestRunStats const& /* _testRunStats */) override {\n         \
    \   currentTestCaseInfo.reset();\n            currentGroupInfo.reset();\n    \
    \        currentTestRunInfo.reset();\n        }\n\n        void skipTest(TestCaseInfo\
    \ const&) override {\n            // Don't do anything with this by default.\n\
    \            // It can optionally be overridden in the derived class.\n      \
    \  }\n\n        IConfigPtr m_config;\n        std::ostream& stream;\n\n      \
    \  LazyStat<TestRunInfo> currentTestRunInfo;\n        LazyStat<GroupInfo> currentGroupInfo;\n\
    \        LazyStat<TestCaseInfo> currentTestCaseInfo;\n\n        std::vector<SectionInfo>\
    \ m_sectionStack;\n        ReporterPreferences m_reporterPrefs;\n    };\n\n  \
    \  template<typename DerivedT>\n    struct CumulativeReporterBase : IStreamingReporter\
    \ {\n        template<typename T, typename ChildNodeT>\n        struct Node {\n\
    \            explicit Node( T const& _value ) : value( _value ) {}\n         \
    \   virtual ~Node() {}\n\n            using ChildNodes = std::vector<std::shared_ptr<ChildNodeT>>;\n\
    \            T value;\n            ChildNodes children;\n        };\n        struct\
    \ SectionNode {\n            explicit SectionNode(SectionStats const& _stats)\
    \ : stats(_stats) {}\n            virtual ~SectionNode() = default;\n\n      \
    \      bool operator == (SectionNode const& other) const {\n                return\
    \ stats.sectionInfo.lineInfo == other.stats.sectionInfo.lineInfo;\n          \
    \  }\n            bool operator == (std::shared_ptr<SectionNode> const& other)\
    \ const {\n                return operator==(*other);\n            }\n\n     \
    \       SectionStats stats;\n            using ChildSections = std::vector<std::shared_ptr<SectionNode>>;\n\
    \            using Assertions = std::vector<AssertionStats>;\n            ChildSections\
    \ childSections;\n            Assertions assertions;\n            std::string\
    \ stdOut;\n            std::string stdErr;\n        };\n\n        struct BySectionInfo\
    \ {\n            BySectionInfo( SectionInfo const& other ) : m_other( other )\
    \ {}\n            BySectionInfo( BySectionInfo const& other ) : m_other( other.m_other\
    \ ) {}\n            bool operator() (std::shared_ptr<SectionNode> const& node)\
    \ const {\n                return ((node->stats.sectionInfo.name == m_other.name)\
    \ &&\n                        (node->stats.sectionInfo.lineInfo == m_other.lineInfo));\n\
    \            }\n            void operator=(BySectionInfo const&) = delete;\n\n\
    \        private:\n            SectionInfo const& m_other;\n        };\n\n   \
    \     using TestCaseNode = Node<TestCaseStats, SectionNode>;\n        using TestGroupNode\
    \ = Node<TestGroupStats, TestCaseNode>;\n        using TestRunNode = Node<TestRunStats,\
    \ TestGroupNode>;\n\n        CumulativeReporterBase( ReporterConfig const& _config\
    \ )\n        :   m_config( _config.fullConfig() ),\n            stream( _config.stream()\
    \ )\n        {\n            m_reporterPrefs.shouldRedirectStdOut = false;\n  \
    \          if( !DerivedT::getSupportedVerbosities().count( m_config->verbosity()\
    \ ) )\n                CATCH_ERROR( \"Verbosity level not supported by this reporter\"\
    \ );\n        }\n        ~CumulativeReporterBase() override = default;\n\n   \
    \     ReporterPreferences getPreferences() const override {\n            return\
    \ m_reporterPrefs;\n        }\n\n        static std::set<Verbosity> getSupportedVerbosities()\
    \ {\n            return { Verbosity::Normal };\n        }\n\n        void testRunStarting(\
    \ TestRunInfo const& ) override {}\n        void testGroupStarting( GroupInfo\
    \ const& ) override {}\n\n        void testCaseStarting( TestCaseInfo const& )\
    \ override {}\n\n        void sectionStarting( SectionInfo const& sectionInfo\
    \ ) override {\n            SectionStats incompleteStats( sectionInfo, Counts(),\
    \ 0, false );\n            std::shared_ptr<SectionNode> node;\n            if(\
    \ m_sectionStack.empty() ) {\n                if( !m_rootSection )\n         \
    \           m_rootSection = std::make_shared<SectionNode>( incompleteStats );\n\
    \                node = m_rootSection;\n            }\n            else {\n  \
    \              SectionNode& parentNode = *m_sectionStack.back();\n           \
    \     auto it =\n                    std::find_if(   parentNode.childSections.begin(),\n\
    \                                    parentNode.childSections.end(),\n       \
    \                             BySectionInfo( sectionInfo ) );\n              \
    \  if( it == parentNode.childSections.end() ) {\n                    node = std::make_shared<SectionNode>(\
    \ incompleteStats );\n                    parentNode.childSections.push_back(\
    \ node );\n                }\n                else\n                    node =\
    \ *it;\n            }\n            m_sectionStack.push_back( node );\n       \
    \     m_deepestSection = std::move(node);\n        }\n\n        void assertionStarting(AssertionInfo\
    \ const&) override {}\n\n        bool assertionEnded(AssertionStats const& assertionStats)\
    \ override {\n            assert(!m_sectionStack.empty());\n            // AssertionResult\
    \ holds a pointer to a temporary DecomposedExpression,\n            // which getExpandedExpression()\
    \ calls to build the expression string.\n            // Our section stack copy\
    \ of the assertionResult will likely outlive the\n            // temporary, so\
    \ it must be expanded or discarded now to avoid calling\n            // a destroyed\
    \ object later.\n            prepareExpandedExpression(const_cast<AssertionResult&>(\
    \ assertionStats.assertionResult ) );\n            SectionNode& sectionNode =\
    \ *m_sectionStack.back();\n            sectionNode.assertions.push_back(assertionStats);\n\
    \            return true;\n        }\n        void sectionEnded(SectionStats const&\
    \ sectionStats) override {\n            assert(!m_sectionStack.empty());\n   \
    \         SectionNode& node = *m_sectionStack.back();\n            node.stats\
    \ = sectionStats;\n            m_sectionStack.pop_back();\n        }\n       \
    \ void testCaseEnded(TestCaseStats const& testCaseStats) override {\n        \
    \    auto node = std::make_shared<TestCaseNode>(testCaseStats);\n            assert(m_sectionStack.size()\
    \ == 0);\n            node->children.push_back(m_rootSection);\n            m_testCases.push_back(node);\n\
    \            m_rootSection.reset();\n\n            assert(m_deepestSection);\n\
    \            m_deepestSection->stdOut = testCaseStats.stdOut;\n            m_deepestSection->stdErr\
    \ = testCaseStats.stdErr;\n        }\n        void testGroupEnded(TestGroupStats\
    \ const& testGroupStats) override {\n            auto node = std::make_shared<TestGroupNode>(testGroupStats);\n\
    \            node->children.swap(m_testCases);\n            m_testGroups.push_back(node);\n\
    \        }\n        void testRunEnded(TestRunStats const& testRunStats) override\
    \ {\n            auto node = std::make_shared<TestRunNode>(testRunStats);\n  \
    \          node->children.swap(m_testGroups);\n            m_testRuns.push_back(node);\n\
    \            testRunEndedCumulative();\n        }\n        virtual void testRunEndedCumulative()\
    \ = 0;\n\n        void skipTest(TestCaseInfo const&) override {}\n\n        IConfigPtr\
    \ m_config;\n        std::ostream& stream;\n        std::vector<AssertionStats>\
    \ m_assertions;\n        std::vector<std::vector<std::shared_ptr<SectionNode>>>\
    \ m_sections;\n        std::vector<std::shared_ptr<TestCaseNode>> m_testCases;\n\
    \        std::vector<std::shared_ptr<TestGroupNode>> m_testGroups;\n\n       \
    \ std::vector<std::shared_ptr<TestRunNode>> m_testRuns;\n\n        std::shared_ptr<SectionNode>\
    \ m_rootSection;\n        std::shared_ptr<SectionNode> m_deepestSection;\n   \
    \     std::vector<std::shared_ptr<SectionNode>> m_sectionStack;\n        ReporterPreferences\
    \ m_reporterPrefs;\n    };\n\n    template<char C>\n    char const* getLineOfChars()\
    \ {\n        static char line[CATCH_CONFIG_CONSOLE_WIDTH] = {0};\n        if(\
    \ !*line ) {\n            std::memset( line, C, CATCH_CONFIG_CONSOLE_WIDTH-1 );\n\
    \            line[CATCH_CONFIG_CONSOLE_WIDTH-1] = 0;\n        }\n        return\
    \ line;\n    }\n\n    struct TestEventListenerBase : StreamingReporterBase<TestEventListenerBase>\
    \ {\n        TestEventListenerBase( ReporterConfig const& _config );\n\n     \
    \   static std::set<Verbosity> getSupportedVerbosities();\n\n        void assertionStarting(AssertionInfo\
    \ const&) override;\n        bool assertionEnded(AssertionStats const&) override;\n\
    \    };\n\n} // end namespace Catch\n\n// end catch_reporter_bases.hpp\n// start\
    \ catch_console_colour.h\n\nnamespace Catch {\n\n    struct Colour {\n       \
    \ enum Code {\n            None = 0,\n\n            White,\n            Red,\n\
    \            Green,\n            Blue,\n            Cyan,\n            Yellow,\n\
    \            Grey,\n\n            Bright = 0x10,\n\n            BrightRed = Bright\
    \ | Red,\n            BrightGreen = Bright | Green,\n            LightGrey = Bright\
    \ | Grey,\n            BrightWhite = Bright | White,\n            BrightYellow\
    \ = Bright | Yellow,\n\n            // By intention\n            FileName = LightGrey,\n\
    \            Warning = BrightYellow,\n            ResultError = BrightRed,\n \
    \           ResultSuccess = BrightGreen,\n            ResultExpectedFailure =\
    \ Warning,\n\n            Error = BrightRed,\n            Success = Green,\n\n\
    \            OriginalExpression = Cyan,\n            ReconstructedExpression =\
    \ BrightYellow,\n\n            SecondaryText = LightGrey,\n            Headers\
    \ = White\n        };\n\n        // Use constructed object for RAII guard\n  \
    \      Colour( Code _colourCode );\n        Colour( Colour&& other ) noexcept;\n\
    \        Colour& operator=( Colour&& other ) noexcept;\n        ~Colour();\n\n\
    \        // Use static method for one-shot changes\n        static void use( Code\
    \ _colourCode );\n\n    private:\n        bool m_moved = false;\n    };\n\n  \
    \  std::ostream& operator << ( std::ostream& os, Colour const& );\n\n} // end\
    \ namespace Catch\n\n// end catch_console_colour.h\n// start catch_reporter_registrars.hpp\n\
    \n\nnamespace Catch {\n\n    template<typename T>\n    class ReporterRegistrar\
    \ {\n\n        class ReporterFactory : public IReporterFactory {\n\n         \
    \   IStreamingReporterPtr create( ReporterConfig const& config ) const override\
    \ {\n                return std::unique_ptr<T>( new T( config ) );\n         \
    \   }\n\n            std::string getDescription() const override {\n         \
    \       return T::getDescription();\n            }\n        };\n\n    public:\n\
    \n        explicit ReporterRegistrar( std::string const& name ) {\n          \
    \  getMutableRegistryHub().registerReporter( name, std::make_shared<ReporterFactory>()\
    \ );\n        }\n    };\n\n    template<typename T>\n    class ListenerRegistrar\
    \ {\n\n        class ListenerFactory : public IReporterFactory {\n\n         \
    \   IStreamingReporterPtr create( ReporterConfig const& config ) const override\
    \ {\n                return std::unique_ptr<T>( new T( config ) );\n         \
    \   }\n            std::string getDescription() const override {\n           \
    \     return std::string();\n            }\n        };\n\n    public:\n\n    \
    \    ListenerRegistrar() {\n            getMutableRegistryHub().registerListener(\
    \ std::make_shared<ListenerFactory>() );\n        }\n    };\n}\n\n#if !defined(CATCH_CONFIG_DISABLE)\n\
    \n#define CATCH_REGISTER_REPORTER( name, reporterType ) \\\n    CATCH_INTERNAL_START_WARNINGS_SUPPRESSION\
    \         \\\n    CATCH_INTERNAL_SUPPRESS_GLOBALS_WARNINGS          \\\n    namespace{\
    \ Catch::ReporterRegistrar<reporterType> catch_internal_RegistrarFor##reporterType(\
    \ name ); } \\\n    CATCH_INTERNAL_STOP_WARNINGS_SUPPRESSION\n\n#define CATCH_REGISTER_LISTENER(\
    \ listenerType ) \\\n    CATCH_INTERNAL_START_WARNINGS_SUPPRESSION   \\\n    CATCH_INTERNAL_SUPPRESS_GLOBALS_WARNINGS\
    \    \\\n    namespace{ Catch::ListenerRegistrar<listenerType> catch_internal_RegistrarFor##listenerType;\
    \ } \\\n    CATCH_INTERNAL_STOP_WARNINGS_SUPPRESSION\n#else // CATCH_CONFIG_DISABLE\n\
    \n#define CATCH_REGISTER_REPORTER(name, reporterType)\n#define CATCH_REGISTER_LISTENER(listenerType)\n\
    \n#endif // CATCH_CONFIG_DISABLE\n\n// end catch_reporter_registrars.hpp\n// Allow\
    \ users to base their work off existing reporters\n// start catch_reporter_compact.h\n\
    \nnamespace Catch {\n\n    struct CompactReporter : StreamingReporterBase<CompactReporter>\
    \ {\n\n        using StreamingReporterBase::StreamingReporterBase;\n\n       \
    \ ~CompactReporter() override;\n\n        static std::string getDescription();\n\
    \n        void noMatchingTestCases(std::string const& spec) override;\n\n    \
    \    void assertionStarting(AssertionInfo const&) override;\n\n        bool assertionEnded(AssertionStats\
    \ const& _assertionStats) override;\n\n        void sectionEnded(SectionStats\
    \ const& _sectionStats) override;\n\n        void testRunEnded(TestRunStats const&\
    \ _testRunStats) override;\n\n    };\n\n} // end namespace Catch\n\n// end catch_reporter_compact.h\n\
    // start catch_reporter_console.h\n\n#if defined(_MSC_VER)\n#pragma warning(push)\n\
    #pragma warning(disable:4061) // Not all labels are EXPLICITLY handled in switch\n\
    \                              // Note that 4062 (not all labels are handled\n\
    \                              // and default is missing) is enabled\n#endif\n\
    \nnamespace Catch {\n    // Fwd decls\n    struct SummaryColumn;\n    class TablePrinter;\n\
    \n    struct ConsoleReporter : StreamingReporterBase<ConsoleReporter> {\n    \
    \    std::unique_ptr<TablePrinter> m_tablePrinter;\n\n        ConsoleReporter(ReporterConfig\
    \ const& config);\n        ~ConsoleReporter() override;\n        static std::string\
    \ getDescription();\n\n        void noMatchingTestCases(std::string const& spec)\
    \ override;\n\n        void reportInvalidArguments(std::string const&arg) override;\n\
    \n        void assertionStarting(AssertionInfo const&) override;\n\n        bool\
    \ assertionEnded(AssertionStats const& _assertionStats) override;\n\n        void\
    \ sectionStarting(SectionInfo const& _sectionInfo) override;\n        void sectionEnded(SectionStats\
    \ const& _sectionStats) override;\n\n#if defined(CATCH_CONFIG_ENABLE_BENCHMARKING)\n\
    \        void benchmarkPreparing(std::string const& name) override;\n        void\
    \ benchmarkStarting(BenchmarkInfo const& info) override;\n        void benchmarkEnded(BenchmarkStats<>\
    \ const& stats) override;\n        void benchmarkFailed(std::string const& error)\
    \ override;\n#endif // CATCH_CONFIG_ENABLE_BENCHMARKING\n\n        void testCaseEnded(TestCaseStats\
    \ const& _testCaseStats) override;\n        void testGroupEnded(TestGroupStats\
    \ const& _testGroupStats) override;\n        void testRunEnded(TestRunStats const&\
    \ _testRunStats) override;\n        void testRunStarting(TestRunInfo const& _testRunInfo)\
    \ override;\n    private:\n\n        void lazyPrint();\n\n        void lazyPrintWithoutClosingBenchmarkTable();\n\
    \        void lazyPrintRunInfo();\n        void lazyPrintGroupInfo();\n      \
    \  void printTestCaseAndSectionHeader();\n\n        void printClosedHeader(std::string\
    \ const& _name);\n        void printOpenHeader(std::string const& _name);\n\n\
    \        // if string has a : in first line will set indent to follow it on\n\
    \        // subsequent lines\n        void printHeaderString(std::string const&\
    \ _string, std::size_t indent = 0);\n\n        void printTotals(Totals const&\
    \ totals);\n        void printSummaryRow(std::string const& label, std::vector<SummaryColumn>\
    \ const& cols, std::size_t row);\n\n        void printTotalsDivider(Totals const&\
    \ totals);\n        void printSummaryDivider();\n        void printTestFilters();\n\
    \n    private:\n        bool m_headerPrinted = false;\n    };\n\n} // end namespace\
    \ Catch\n\n#if defined(_MSC_VER)\n#pragma warning(pop)\n#endif\n\n// end catch_reporter_console.h\n\
    // start catch_reporter_junit.h\n\n// start catch_xmlwriter.h\n\n#include <vector>\n\
    \nnamespace Catch {\n    enum class XmlFormatting {\n        None = 0x00,\n  \
    \      Indent = 0x01,\n        Newline = 0x02,\n    };\n\n    XmlFormatting operator\
    \ | (XmlFormatting lhs, XmlFormatting rhs);\n    XmlFormatting operator & (XmlFormatting\
    \ lhs, XmlFormatting rhs);\n\n    class XmlEncode {\n    public:\n        enum\
    \ ForWhat { ForTextNodes, ForAttributes };\n\n        XmlEncode( std::string const&\
    \ str, ForWhat forWhat = ForTextNodes );\n\n        void encodeTo( std::ostream&\
    \ os ) const;\n\n        friend std::ostream& operator << ( std::ostream& os,\
    \ XmlEncode const& xmlEncode );\n\n    private:\n        std::string m_str;\n\
    \        ForWhat m_forWhat;\n    };\n\n    class XmlWriter {\n    public:\n\n\
    \        class ScopedElement {\n        public:\n            ScopedElement( XmlWriter*\
    \ writer, XmlFormatting fmt );\n\n            ScopedElement( ScopedElement&& other\
    \ ) noexcept;\n            ScopedElement& operator=( ScopedElement&& other ) noexcept;\n\
    \n            ~ScopedElement();\n\n            ScopedElement& writeText( std::string\
    \ const& text, XmlFormatting fmt = XmlFormatting::Newline | XmlFormatting::Indent\
    \ );\n\n            template<typename T>\n            ScopedElement& writeAttribute(\
    \ std::string const& name, T const& attribute ) {\n                m_writer->writeAttribute(\
    \ name, attribute );\n                return *this;\n            }\n\n       \
    \ private:\n            mutable XmlWriter* m_writer = nullptr;\n            XmlFormatting\
    \ m_fmt;\n        };\n\n        XmlWriter( std::ostream& os = Catch::cout() );\n\
    \        ~XmlWriter();\n\n        XmlWriter( XmlWriter const& ) = delete;\n  \
    \      XmlWriter& operator=( XmlWriter const& ) = delete;\n\n        XmlWriter&\
    \ startElement( std::string const& name, XmlFormatting fmt = XmlFormatting::Newline\
    \ | XmlFormatting::Indent);\n\n        ScopedElement scopedElement( std::string\
    \ const& name, XmlFormatting fmt = XmlFormatting::Newline | XmlFormatting::Indent);\n\
    \n        XmlWriter& endElement(XmlFormatting fmt = XmlFormatting::Newline | XmlFormatting::Indent);\n\
    \n        XmlWriter& writeAttribute( std::string const& name, std::string const&\
    \ attribute );\n\n        XmlWriter& writeAttribute( std::string const& name,\
    \ bool attribute );\n\n        template<typename T>\n        XmlWriter& writeAttribute(\
    \ std::string const& name, T const& attribute ) {\n            ReusableStringStream\
    \ rss;\n            rss << attribute;\n            return writeAttribute( name,\
    \ rss.str() );\n        }\n\n        XmlWriter& writeText( std::string const&\
    \ text, XmlFormatting fmt = XmlFormatting::Newline | XmlFormatting::Indent);\n\
    \n        XmlWriter& writeComment(std::string const& text, XmlFormatting fmt =\
    \ XmlFormatting::Newline | XmlFormatting::Indent);\n\n        void writeStylesheetRef(\
    \ std::string const& url );\n\n        XmlWriter& writeBlankLine();\n\n      \
    \  void ensureTagClosed();\n\n    private:\n\n        void applyFormatting(XmlFormatting\
    \ fmt);\n\n        void writeDeclaration();\n\n        void newlineIfNecessary();\n\
    \n        bool m_tagIsOpen = false;\n        bool m_needsNewline = false;\n  \
    \      std::vector<std::string> m_tags;\n        std::string m_indent;\n     \
    \   std::ostream& m_os;\n    };\n\n}\n\n// end catch_xmlwriter.h\nnamespace Catch\
    \ {\n\n    class JunitReporter : public CumulativeReporterBase<JunitReporter>\
    \ {\n    public:\n        JunitReporter(ReporterConfig const& _config);\n\n  \
    \      ~JunitReporter() override;\n\n        static std::string getDescription();\n\
    \n        void noMatchingTestCases(std::string const& /*spec*/) override;\n\n\
    \        void testRunStarting(TestRunInfo const& runInfo) override;\n\n      \
    \  void testGroupStarting(GroupInfo const& groupInfo) override;\n\n        void\
    \ testCaseStarting(TestCaseInfo const& testCaseInfo) override;\n        bool assertionEnded(AssertionStats\
    \ const& assertionStats) override;\n\n        void testCaseEnded(TestCaseStats\
    \ const& testCaseStats) override;\n\n        void testGroupEnded(TestGroupStats\
    \ const& testGroupStats) override;\n\n        void testRunEndedCumulative() override;\n\
    \n        void writeGroup(TestGroupNode const& groupNode, double suiteTime);\n\
    \n        void writeTestCase(TestCaseNode const& testCaseNode);\n\n        void\
    \ writeSection(std::string const& className,\n                          std::string\
    \ const& rootName,\n                          SectionNode const& sectionNode);\n\
    \n        void writeAssertions(SectionNode const& sectionNode);\n        void\
    \ writeAssertion(AssertionStats const& stats);\n\n        XmlWriter xml;\n   \
    \     Timer suiteTimer;\n        std::string stdOutForSuite;\n        std::string\
    \ stdErrForSuite;\n        unsigned int unexpectedExceptions = 0;\n        bool\
    \ m_okToFail = false;\n    };\n\n} // end namespace Catch\n\n// end catch_reporter_junit.h\n\
    // start catch_reporter_xml.h\n\nnamespace Catch {\n    class XmlReporter : public\
    \ StreamingReporterBase<XmlReporter> {\n    public:\n        XmlReporter(ReporterConfig\
    \ const& _config);\n\n        ~XmlReporter() override;\n\n        static std::string\
    \ getDescription();\n\n        virtual std::string getStylesheetRef() const;\n\
    \n        void writeSourceInfo(SourceLineInfo const& sourceInfo);\n\n    public:\
    \ // StreamingReporterBase\n\n        void noMatchingTestCases(std::string const&\
    \ s) override;\n\n        void testRunStarting(TestRunInfo const& testInfo) override;\n\
    \n        void testGroupStarting(GroupInfo const& groupInfo) override;\n\n   \
    \     void testCaseStarting(TestCaseInfo const& testInfo) override;\n\n      \
    \  void sectionStarting(SectionInfo const& sectionInfo) override;\n\n        void\
    \ assertionStarting(AssertionInfo const&) override;\n\n        bool assertionEnded(AssertionStats\
    \ const& assertionStats) override;\n\n        void sectionEnded(SectionStats const&\
    \ sectionStats) override;\n\n        void testCaseEnded(TestCaseStats const& testCaseStats)\
    \ override;\n\n        void testGroupEnded(TestGroupStats const& testGroupStats)\
    \ override;\n\n        void testRunEnded(TestRunStats const& testRunStats) override;\n\
    \n#if defined(CATCH_CONFIG_ENABLE_BENCHMARKING)\n        void benchmarkPreparing(std::string\
    \ const& name) override;\n        void benchmarkStarting(BenchmarkInfo const&)\
    \ override;\n        void benchmarkEnded(BenchmarkStats<> const&) override;\n\
    \        void benchmarkFailed(std::string const&) override;\n#endif // CATCH_CONFIG_ENABLE_BENCHMARKING\n\
    \n    private:\n        Timer m_testCaseTimer;\n        XmlWriter m_xml;\n   \
    \     int m_sectionDepth = 0;\n    };\n\n} // end namespace Catch\n\n// end catch_reporter_xml.h\n\
    \n// end catch_external_interfaces.h\n#endif\n\n#if defined(CATCH_CONFIG_ENABLE_BENCHMARKING)\n\
    // start catch_benchmarking_all.hpp\n\n// A proxy header that includes all of\
    \ the benchmarking headers to allow\n// concise include of the benchmarking features.\
    \ You should prefer the\n// individual includes in standard use.\n\n// start catch_benchmark.hpp\n\
    \n // Benchmark\n\n// start catch_chronometer.hpp\n\n// User-facing chronometer\n\
    \n\n// start catch_clock.hpp\n\n// Clocks\n\n\n#include <chrono>\n#include <ratio>\n\
    \nnamespace Catch {\n    namespace Benchmark {\n        template <typename Clock>\n\
    \        using ClockDuration = typename Clock::duration;\n        template <typename\
    \ Clock>\n        using FloatDuration = std::chrono::duration<double, typename\
    \ Clock::period>;\n\n        template <typename Clock>\n        using TimePoint\
    \ = typename Clock::time_point;\n\n        using default_clock = std::chrono::steady_clock;\n\
    \n        template <typename Clock>\n        struct now {\n            TimePoint<Clock>\
    \ operator()() const {\n                return Clock::now();\n            }\n\
    \        };\n\n        using fp_seconds = std::chrono::duration<double, std::ratio<1>>;\n\
    \    } // namespace Benchmark\n} // namespace Catch\n\n// end catch_clock.hpp\n\
    // start catch_optimizer.hpp\n\n // Hinting the optimizer\n\n\n#if defined(_MSC_VER)\n\
    #   include <atomic> // atomic_thread_fence\n#endif\n\nnamespace Catch {\n   \
    \ namespace Benchmark {\n#if defined(__GNUC__) || defined(__clang__)\n       \
    \ template <typename T>\n        inline void keep_memory(T* p) {\n           \
    \ asm volatile(\"\" : : \"g\"(p) : \"memory\");\n        }\n        inline void\
    \ keep_memory() {\n            asm volatile(\"\" : : : \"memory\");\n        }\n\
    \n        namespace Detail {\n            inline void optimizer_barrier() { keep_memory();\
    \ }\n        } // namespace Detail\n#elif defined(_MSC_VER)\n\n#pragma optimize(\"\
    \", off)\n        template <typename T>\n        inline void keep_memory(T* p)\
    \ {\n            // thanks @milleniumbug\n            *reinterpret_cast<char volatile*>(p)\
    \ = *reinterpret_cast<char const volatile*>(p);\n        }\n        // TODO equivalent\
    \ keep_memory()\n#pragma optimize(\"\", on)\n\n        namespace Detail {\n  \
    \          inline void optimizer_barrier() {\n                std::atomic_thread_fence(std::memory_order_seq_cst);\n\
    \            }\n        } // namespace Detail\n\n#endif\n\n        template <typename\
    \ T>\n        inline void deoptimize_value(T&& x) {\n            keep_memory(&x);\n\
    \        }\n\n        template <typename Fn, typename... Args>\n        inline\
    \ auto invoke_deoptimized(Fn&& fn, Args&&... args) -> typename std::enable_if<!std::is_same<void,\
    \ decltype(fn(args...))>::value>::type {\n            deoptimize_value(std::forward<Fn>(fn)\
    \ (std::forward<Args...>(args...)));\n        }\n\n        template <typename\
    \ Fn, typename... Args>\n        inline auto invoke_deoptimized(Fn&& fn, Args&&...\
    \ args) -> typename std::enable_if<std::is_same<void, decltype(fn(args...))>::value>::type\
    \ {\n            std::forward<Fn>(fn) (std::forward<Args...>(args...));\n    \
    \    }\n    } // namespace Benchmark\n} // namespace Catch\n\n// end catch_optimizer.hpp\n\
    // start catch_complete_invoke.hpp\n\n// Invoke with a special case for void\n\
    \n\n#include <type_traits>\n#include <utility>\n\nnamespace Catch {\n    namespace\
    \ Benchmark {\n        namespace Detail {\n            template <typename T>\n\
    \            struct CompleteType { using type = T; };\n            template <>\n\
    \            struct CompleteType<void> { struct type {}; };\n\n            template\
    \ <typename T>\n            using CompleteType_t = typename CompleteType<T>::type;\n\
    \n            template <typename Result>\n            struct CompleteInvoker {\n\
    \                template <typename Fun, typename... Args>\n                static\
    \ Result invoke(Fun&& fun, Args&&... args) {\n                    return std::forward<Fun>(fun)(std::forward<Args>(args)...);\n\
    \                }\n            };\n            template <>\n            struct\
    \ CompleteInvoker<void> {\n                template <typename Fun, typename...\
    \ Args>\n                static CompleteType_t<void> invoke(Fun&& fun, Args&&...\
    \ args) {\n                    std::forward<Fun>(fun)(std::forward<Args>(args)...);\n\
    \                    return {};\n                }\n            };\n\n       \
    \     // invoke and not return void :(\n            template <typename Fun, typename...\
    \ Args>\n            CompleteType_t<FunctionReturnType<Fun, Args...>> complete_invoke(Fun&&\
    \ fun, Args&&... args) {\n                return CompleteInvoker<FunctionReturnType<Fun,\
    \ Args...>>::invoke(std::forward<Fun>(fun), std::forward<Args>(args)...);\n  \
    \          }\n\n            const std::string benchmarkErrorMsg = \"a benchmark\
    \ failed to run successfully\";\n        } // namespace Detail\n\n        template\
    \ <typename Fun>\n        Detail::CompleteType_t<FunctionReturnType<Fun>> user_code(Fun&&\
    \ fun) {\n            CATCH_TRY{\n                return Detail::complete_invoke(std::forward<Fun>(fun));\n\
    \            } CATCH_CATCH_ALL{\n                getResultCapture().benchmarkFailed(translateActiveException());\n\
    \                CATCH_RUNTIME_ERROR(Detail::benchmarkErrorMsg);\n           \
    \ }\n        }\n    } // namespace Benchmark\n} // namespace Catch\n\n// end catch_complete_invoke.hpp\n\
    namespace Catch {\n    namespace Benchmark {\n        namespace Detail {\n   \
    \         struct ChronometerConcept {\n                virtual void start() =\
    \ 0;\n                virtual void finish() = 0;\n                virtual ~ChronometerConcept()\
    \ = default;\n            };\n            template <typename Clock>\n        \
    \    struct ChronometerModel final : public ChronometerConcept {\n           \
    \     void start() override { started = Clock::now(); }\n                void\
    \ finish() override { finished = Clock::now(); }\n\n                ClockDuration<Clock>\
    \ elapsed() const { return finished - started; }\n\n                TimePoint<Clock>\
    \ started;\n                TimePoint<Clock> finished;\n            };\n     \
    \   } // namespace Detail\n\n        struct Chronometer {\n        public:\n \
    \           template <typename Fun>\n            void measure(Fun&& fun) { measure(std::forward<Fun>(fun),\
    \ is_callable<Fun(int)>()); }\n\n            int runs() const { return k; }\n\n\
    \            Chronometer(Detail::ChronometerConcept& meter, int k)\n         \
    \       : impl(&meter)\n                , k(k) {}\n\n        private:\n      \
    \      template <typename Fun>\n            void measure(Fun&& fun, std::false_type)\
    \ {\n                measure([&fun](int) { return fun(); }, std::true_type());\n\
    \            }\n\n            template <typename Fun>\n            void measure(Fun&&\
    \ fun, std::true_type) {\n                Detail::optimizer_barrier();\n     \
    \           impl->start();\n                for (int i = 0; i < k; ++i) invoke_deoptimized(fun,\
    \ i);\n                impl->finish();\n                Detail::optimizer_barrier();\n\
    \            }\n\n            Detail::ChronometerConcept* impl;\n            int\
    \ k;\n        };\n    } // namespace Benchmark\n} // namespace Catch\n\n// end\
    \ catch_chronometer.hpp\n// start catch_environment.hpp\n\n// Environment information\n\
    \n\nnamespace Catch {\n    namespace Benchmark {\n        template <typename Duration>\n\
    \        struct EnvironmentEstimate {\n            Duration mean;\n          \
    \  OutlierClassification outliers;\n\n            template <typename Duration2>\n\
    \            operator EnvironmentEstimate<Duration2>() const {\n             \
    \   return { mean, outliers };\n            }\n        };\n        template <typename\
    \ Clock>\n        struct Environment {\n            using clock_type = Clock;\n\
    \            EnvironmentEstimate<FloatDuration<Clock>> clock_resolution;\n   \
    \         EnvironmentEstimate<FloatDuration<Clock>> clock_cost;\n        };\n\
    \    } // namespace Benchmark\n} // namespace Catch\n\n// end catch_environment.hpp\n\
    // start catch_execution_plan.hpp\n\n // Execution plan\n\n\n// start catch_benchmark_function.hpp\n\
    \n // Dumb std::function implementation for consistent call overhead\n\n\n#include\
    \ <cassert>\n#include <type_traits>\n#include <utility>\n#include <memory>\n\n\
    namespace Catch {\n    namespace Benchmark {\n        namespace Detail {\n   \
    \         template <typename T>\n            using Decay = typename std::decay<T>::type;\n\
    \            template <typename T, typename U>\n            struct is_related\n\
    \                : std::is_same<Decay<T>, Decay<U>> {};\n\n            /// We\
    \ need to reinvent std::function because every piece of code that might add overhead\n\
    \            /// in a measurement context needs to have consistent performance\
    \ characteristics so that we\n            /// can account for it in the measurement.\n\
    \            /// Implementations of std::function with optimizations that aren't\
    \ always applicable, like\n            /// small buffer optimizations, are not\
    \ uncommon.\n            /// This is effectively an implementation of std::function\
    \ without any such optimizations;\n            /// it may be slow, but it is consistently\
    \ slow.\n            struct BenchmarkFunction {\n            private:\n      \
    \          struct callable {\n                    virtual void call(Chronometer\
    \ meter) const = 0;\n                    virtual callable* clone() const = 0;\n\
    \                    virtual ~callable() = default;\n                };\n    \
    \            template <typename Fun>\n                struct model : public callable\
    \ {\n                    model(Fun&& fun) : fun(std::move(fun)) {}\n         \
    \           model(Fun const& fun) : fun(fun) {}\n\n                    model<Fun>*\
    \ clone() const override { return new model<Fun>(*this); }\n\n               \
    \     void call(Chronometer meter) const override {\n                        call(meter,\
    \ is_callable<Fun(Chronometer)>());\n                    }\n                 \
    \   void call(Chronometer meter, std::true_type) const {\n                   \
    \     fun(meter);\n                    }\n                    void call(Chronometer\
    \ meter, std::false_type) const {\n                        meter.measure(fun);\n\
    \                    }\n\n                    Fun fun;\n                };\n\n\
    \                struct do_nothing { void operator()() const {} };\n\n       \
    \         template <typename T>\n                BenchmarkFunction(model<T>* c)\
    \ : f(c) {}\n\n            public:\n                BenchmarkFunction()\n    \
    \                : f(new model<do_nothing>{ {} }) {}\n\n                template\
    \ <typename Fun,\n                    typename std::enable_if<!is_related<Fun,\
    \ BenchmarkFunction>::value, int>::type = 0>\n                    BenchmarkFunction(Fun&&\
    \ fun)\n                    : f(new model<typename std::decay<Fun>::type>(std::forward<Fun>(fun)))\
    \ {}\n\n                BenchmarkFunction(BenchmarkFunction&& that)\n        \
    \            : f(std::move(that.f)) {}\n\n                BenchmarkFunction(BenchmarkFunction\
    \ const& that)\n                    : f(that.f->clone()) {}\n\n              \
    \  BenchmarkFunction& operator=(BenchmarkFunction&& that) {\n                \
    \    f = std::move(that.f);\n                    return *this;\n             \
    \   }\n\n                BenchmarkFunction& operator=(BenchmarkFunction const&\
    \ that) {\n                    f.reset(that.f->clone());\n                   \
    \ return *this;\n                }\n\n                void operator()(Chronometer\
    \ meter) const { f->call(meter); }\n\n            private:\n                std::unique_ptr<callable>\
    \ f;\n            };\n        } // namespace Detail\n    } // namespace Benchmark\n\
    } // namespace Catch\n\n// end catch_benchmark_function.hpp\n// start catch_repeat.hpp\n\
    \n// repeat algorithm\n\n\n#include <type_traits>\n#include <utility>\n\nnamespace\
    \ Catch {\n    namespace Benchmark {\n        namespace Detail {\n           \
    \ template <typename Fun>\n            struct repeater {\n                void\
    \ operator()(int k) const {\n                    for (int i = 0; i < k; ++i) {\n\
    \                        fun();\n                    }\n                }\n  \
    \              Fun fun;\n            };\n            template <typename Fun>\n\
    \            repeater<typename std::decay<Fun>::type> repeat(Fun&& fun) {\n  \
    \              return { std::forward<Fun>(fun) };\n            }\n        } //\
    \ namespace Detail\n    } // namespace Benchmark\n} // namespace Catch\n\n// end\
    \ catch_repeat.hpp\n// start catch_run_for_at_least.hpp\n\n// Run a function for\
    \ a minimum amount of time\n\n\n// start catch_measure.hpp\n\n// Measure\n\n\n\
    // start catch_timing.hpp\n\n// Timing\n\n\n#include <tuple>\n#include <type_traits>\n\
    \nnamespace Catch {\n    namespace Benchmark {\n        template <typename Duration,\
    \ typename Result>\n        struct Timing {\n            Duration elapsed;\n \
    \           Result result;\n            int iterations;\n        };\n        template\
    \ <typename Clock, typename Func, typename... Args>\n        using TimingOf =\
    \ Timing<ClockDuration<Clock>, Detail::CompleteType_t<FunctionReturnType<Func,\
    \ Args...>>>;\n    } // namespace Benchmark\n} // namespace Catch\n\n// end catch_timing.hpp\n\
    #include <utility>\n\nnamespace Catch {\n    namespace Benchmark {\n        namespace\
    \ Detail {\n            template <typename Clock, typename Fun, typename... Args>\n\
    \            TimingOf<Clock, Fun, Args...> measure(Fun&& fun, Args&&... args)\
    \ {\n                auto start = Clock::now();\n                auto&& r = Detail::complete_invoke(fun,\
    \ std::forward<Args>(args)...);\n                auto end = Clock::now();\n  \
    \              auto delta = end - start;\n                return { delta, std::forward<decltype(r)>(r),\
    \ 1 };\n            }\n        } // namespace Detail\n    } // namespace Benchmark\n\
    } // namespace Catch\n\n// end catch_measure.hpp\n#include <utility>\n#include\
    \ <type_traits>\n\nnamespace Catch {\n    namespace Benchmark {\n        namespace\
    \ Detail {\n            template <typename Clock, typename Fun>\n            TimingOf<Clock,\
    \ Fun, int> measure_one(Fun&& fun, int iters, std::false_type) {\n           \
    \     return Detail::measure<Clock>(fun, iters);\n            }\n            template\
    \ <typename Clock, typename Fun>\n            TimingOf<Clock, Fun, Chronometer>\
    \ measure_one(Fun&& fun, int iters, std::true_type) {\n                Detail::ChronometerModel<Clock>\
    \ meter;\n                auto&& result = Detail::complete_invoke(fun, Chronometer(meter,\
    \ iters));\n\n                return { meter.elapsed(), std::move(result), iters\
    \ };\n            }\n\n            template <typename Clock, typename Fun>\n \
    \           using run_for_at_least_argument_t = typename std::conditional<is_callable<Fun(Chronometer)>::value,\
    \ Chronometer, int>::type;\n\n            struct optimized_away_error : std::exception\
    \ {\n                const char* what() const noexcept override {\n          \
    \          return \"could not measure benchmark, maybe it was optimized away\"\
    ;\n                }\n            };\n\n            template <typename Clock,\
    \ typename Fun>\n            TimingOf<Clock, Fun, run_for_at_least_argument_t<Clock,\
    \ Fun>> run_for_at_least(ClockDuration<Clock> how_long, int seed, Fun&& fun) {\n\
    \                auto iters = seed;\n                while (iters < (1 << 30))\
    \ {\n                    auto&& Timing = measure_one<Clock>(fun, iters, is_callable<Fun(Chronometer)>());\n\
    \n                    if (Timing.elapsed >= how_long) {\n                    \
    \    return { Timing.elapsed, std::move(Timing.result), iters };\n           \
    \         }\n                    iters *= 2;\n                }\n            \
    \    throw optimized_away_error{};\n            }\n        } // namespace Detail\n\
    \    } // namespace Benchmark\n} // namespace Catch\n\n// end catch_run_for_at_least.hpp\n\
    #include <algorithm>\n\nnamespace Catch {\n    namespace Benchmark {\n       \
    \ template <typename Duration>\n        struct ExecutionPlan {\n            int\
    \ iterations_per_sample;\n            Duration estimated_duration;\n         \
    \   Detail::BenchmarkFunction benchmark;\n            Duration warmup_time;\n\
    \            int warmup_iterations;\n\n            template <typename Duration2>\n\
    \            operator ExecutionPlan<Duration2>() const {\n                return\
    \ { iterations_per_sample, estimated_duration, benchmark, warmup_time, warmup_iterations\
    \ };\n            }\n\n            template <typename Clock>\n            std::vector<FloatDuration<Clock>>\
    \ run(const IConfig &cfg, Environment<FloatDuration<Clock>> env) const {\n   \
    \             // warmup a bit\n                Detail::run_for_at_least<Clock>(std::chrono::duration_cast<ClockDuration<Clock>>(warmup_time),\
    \ warmup_iterations, Detail::repeat(now<Clock>{}));\n\n                std::vector<FloatDuration<Clock>>\
    \ times;\n                times.reserve(cfg.benchmarkSamples());\n           \
    \     std::generate_n(std::back_inserter(times), cfg.benchmarkSamples(), [this,\
    \ env] {\n                    Detail::ChronometerModel<Clock> model;\n       \
    \             this->benchmark(Chronometer(model, iterations_per_sample));\n  \
    \                  auto sample_time = model.elapsed() - env.clock_cost.mean;\n\
    \                    if (sample_time < FloatDuration<Clock>::zero()) sample_time\
    \ = FloatDuration<Clock>::zero();\n                    return sample_time / iterations_per_sample;\n\
    \                });\n                return times;\n            }\n        };\n\
    \    } // namespace Benchmark\n} // namespace Catch\n\n// end catch_execution_plan.hpp\n\
    // start catch_estimate_clock.hpp\n\n // Environment measurement\n\n\n// start\
    \ catch_stats.hpp\n\n// Statistical analysis tools\n\n\n#include <algorithm>\n\
    #include <functional>\n#include <vector>\n#include <iterator>\n#include <numeric>\n\
    #include <tuple>\n#include <cmath>\n#include <utility>\n#include <cstddef>\n#include\
    \ <random>\n\nnamespace Catch {\n    namespace Benchmark {\n        namespace\
    \ Detail {\n            using sample = std::vector<double>;\n\n            double\
    \ weighted_average_quantile(int k, int q, std::vector<double>::iterator first,\
    \ std::vector<double>::iterator last);\n\n            template <typename Iterator>\n\
    \            OutlierClassification classify_outliers(Iterator first, Iterator\
    \ last) {\n                std::vector<double> copy(first, last);\n\n        \
    \        auto q1 = weighted_average_quantile(1, 4, copy.begin(), copy.end());\n\
    \                auto q3 = weighted_average_quantile(3, 4, copy.begin(), copy.end());\n\
    \                auto iqr = q3 - q1;\n                auto los = q1 - (iqr * 3.);\n\
    \                auto lom = q1 - (iqr * 1.5);\n                auto him = q3 +\
    \ (iqr * 1.5);\n                auto his = q3 + (iqr * 3.);\n\n              \
    \  OutlierClassification o;\n                for (; first != last; ++first) {\n\
    \                    auto&& t = *first;\n                    if (t < los) ++o.low_severe;\n\
    \                    else if (t < lom) ++o.low_mild;\n                    else\
    \ if (t > his) ++o.high_severe;\n                    else if (t > him) ++o.high_mild;\n\
    \                    ++o.samples_seen;\n                }\n                return\
    \ o;\n            }\n\n            template <typename Iterator>\n            double\
    \ mean(Iterator first, Iterator last) {\n                auto count = last - first;\n\
    \                double sum = std::accumulate(first, last, 0.);\n            \
    \    return sum / count;\n            }\n\n            template <typename URng,\
    \ typename Iterator, typename Estimator>\n            sample resample(URng& rng,\
    \ int resamples, Iterator first, Iterator last, Estimator& estimator) {\n    \
    \            auto n = last - first;\n                std::uniform_int_distribution<decltype(n)>\
    \ dist(0, n - 1);\n\n                sample out;\n                out.reserve(resamples);\n\
    \                std::generate_n(std::back_inserter(out), resamples, [n, first,\
    \ &estimator, &dist, &rng] {\n                    std::vector<double> resampled;\n\
    \                    resampled.reserve(n);\n                    std::generate_n(std::back_inserter(resampled),\
    \ n, [first, &dist, &rng] { return first[dist(rng)]; });\n                   \
    \ return estimator(resampled.begin(), resampled.end());\n                });\n\
    \                std::sort(out.begin(), out.end());\n                return out;\n\
    \            }\n\n            template <typename Estimator, typename Iterator>\n\
    \            sample jackknife(Estimator&& estimator, Iterator first, Iterator\
    \ last) {\n                auto n = last - first;\n                auto second\
    \ = std::next(first);\n                sample results;\n                results.reserve(n);\n\
    \n                for (auto it = first; it != last; ++it) {\n                \
    \    std::iter_swap(it, first);\n                    results.push_back(estimator(second,\
    \ last));\n                }\n\n                return results;\n            }\n\
    \n            inline double normal_cdf(double x) {\n                return std::erfc(-x\
    \ / std::sqrt(2.0)) / 2.0;\n            }\n\n            double erfc_inv(double\
    \ x);\n\n            double normal_quantile(double p);\n\n            template\
    \ <typename Iterator, typename Estimator>\n            Estimate<double> bootstrap(double\
    \ confidence_level, Iterator first, Iterator last, sample const& resample, Estimator&&\
    \ estimator) {\n                auto n_samples = last - first;\n\n           \
    \     double point = estimator(first, last);\n                // Degenerate case\
    \ with a single sample\n                if (n_samples == 1) return { point, point,\
    \ point, confidence_level };\n\n                sample jack = jackknife(estimator,\
    \ first, last);\n                double jack_mean = mean(jack.begin(), jack.end());\n\
    \                double sum_squares, sum_cubes;\n                std::tie(sum_squares,\
    \ sum_cubes) = std::accumulate(jack.begin(), jack.end(), std::make_pair(0., 0.),\
    \ [jack_mean](std::pair<double, double> sqcb, double x) -> std::pair<double, double>\
    \ {\n                    auto d = jack_mean - x;\n                    auto d2\
    \ = d * d;\n                    auto d3 = d2 * d;\n                    return\
    \ { sqcb.first + d2, sqcb.second + d3 };\n                });\n\n            \
    \    double accel = sum_cubes / (6 * std::pow(sum_squares, 1.5));\n          \
    \      int n = static_cast<int>(resample.size());\n                double prob_n\
    \ = std::count_if(resample.begin(), resample.end(), [point](double x) { return\
    \ x < point; }) / (double)n;\n                // degenerate case with uniform\
    \ samples\n                if (prob_n == 0) return { point, point, point, confidence_level\
    \ };\n\n                double bias = normal_quantile(prob_n);\n             \
    \   double z1 = normal_quantile((1. - confidence_level) / 2.);\n\n           \
    \     auto cumn = [n](double x) -> int {\n                    return std::lround(normal_cdf(x)\
    \ * n); };\n                auto a = [bias, accel](double b) { return bias + b\
    \ / (1. - accel * b); };\n                double b1 = bias + z1;\n           \
    \     double b2 = bias - z1;\n                double a1 = a(b1);\n           \
    \     double a2 = a(b2);\n                auto lo = std::max(cumn(a1), 0);\n \
    \               auto hi = std::min(cumn(a2), n - 1);\n\n                return\
    \ { point, resample[lo], resample[hi], confidence_level };\n            }\n\n\
    \            double outlier_variance(Estimate<double> mean, Estimate<double> stddev,\
    \ int n);\n\n            struct bootstrap_analysis {\n                Estimate<double>\
    \ mean;\n                Estimate<double> standard_deviation;\n              \
    \  double outlier_variance;\n            };\n\n            bootstrap_analysis\
    \ analyse_samples(double confidence_level, int n_resamples, std::vector<double>::iterator\
    \ first, std::vector<double>::iterator last);\n        } // namespace Detail\n\
    \    } // namespace Benchmark\n} // namespace Catch\n\n// end catch_stats.hpp\n\
    #include <algorithm>\n#include <iterator>\n#include <tuple>\n#include <vector>\n\
    #include <cmath>\n\nnamespace Catch {\n    namespace Benchmark {\n        namespace\
    \ Detail {\n            template <typename Clock>\n            std::vector<double>\
    \ resolution(int k) {\n                std::vector<TimePoint<Clock>> times;\n\
    \                times.reserve(k + 1);\n                std::generate_n(std::back_inserter(times),\
    \ k + 1, now<Clock>{});\n\n                std::vector<double> deltas;\n     \
    \           deltas.reserve(k);\n                std::transform(std::next(times.begin()),\
    \ times.end(), times.begin(),\n                    std::back_inserter(deltas),\n\
    \                    [](TimePoint<Clock> a, TimePoint<Clock> b) { return static_cast<double>((a\
    \ - b).count()); });\n\n                return deltas;\n            }\n\n    \
    \        const auto warmup_iterations = 10000;\n            const auto warmup_time\
    \ = std::chrono::milliseconds(100);\n            const auto minimum_ticks = 1000;\n\
    \            const auto warmup_seed = 10000;\n            const auto clock_resolution_estimation_time\
    \ = std::chrono::milliseconds(500);\n            const auto clock_cost_estimation_time_limit\
    \ = std::chrono::seconds(1);\n            const auto clock_cost_estimation_tick_limit\
    \ = 100000;\n            const auto clock_cost_estimation_time = std::chrono::milliseconds(10);\n\
    \            const auto clock_cost_estimation_iterations = 10000;\n\n        \
    \    template <typename Clock>\n            int warmup() {\n                return\
    \ run_for_at_least<Clock>(std::chrono::duration_cast<ClockDuration<Clock>>(warmup_time),\
    \ warmup_seed, &resolution<Clock>)\n                    .iterations;\n       \
    \     }\n            template <typename Clock>\n            EnvironmentEstimate<FloatDuration<Clock>>\
    \ estimate_clock_resolution(int iterations) {\n                auto r = run_for_at_least<Clock>(std::chrono::duration_cast<ClockDuration<Clock>>(clock_resolution_estimation_time),\
    \ iterations, &resolution<Clock>)\n                    .result;\n            \
    \    return {\n                    FloatDuration<Clock>(mean(r.begin(), r.end())),\n\
    \                    classify_outliers(r.begin(), r.end()),\n                };\n\
    \            }\n            template <typename Clock>\n            EnvironmentEstimate<FloatDuration<Clock>>\
    \ estimate_clock_cost(FloatDuration<Clock> resolution) {\n                auto\
    \ time_limit = std::min(resolution * clock_cost_estimation_tick_limit, FloatDuration<Clock>(clock_cost_estimation_time_limit));\n\
    \                auto time_clock = [](int k) {\n                    return Detail::measure<Clock>([k]\
    \ {\n                        for (int i = 0; i < k; ++i) {\n                 \
    \           volatile auto ignored = Clock::now();\n                          \
    \  (void)ignored;\n                        }\n                    }).elapsed;\n\
    \                };\n                time_clock(1);\n                int iters\
    \ = clock_cost_estimation_iterations;\n                auto&& r = run_for_at_least<Clock>(std::chrono::duration_cast<ClockDuration<Clock>>(clock_cost_estimation_time),\
    \ iters, time_clock);\n                std::vector<double> times;\n          \
    \      int nsamples = static_cast<int>(std::ceil(time_limit / r.elapsed));\n \
    \               times.reserve(nsamples);\n                std::generate_n(std::back_inserter(times),\
    \ nsamples, [time_clock, &r] {\n                    return static_cast<double>((time_clock(r.iterations)\
    \ / r.iterations).count());\n                });\n                return {\n \
    \                   FloatDuration<Clock>(mean(times.begin(), times.end())),\n\
    \                    classify_outliers(times.begin(), times.end()),\n        \
    \        };\n            }\n\n            template <typename Clock>\n        \
    \    Environment<FloatDuration<Clock>> measure_environment() {\n             \
    \   static Environment<FloatDuration<Clock>>* env = nullptr;\n               \
    \ if (env) {\n                    return *env;\n                }\n\n        \
    \        auto iters = Detail::warmup<Clock>();\n                auto resolution\
    \ = Detail::estimate_clock_resolution<Clock>(iters);\n                auto cost\
    \ = Detail::estimate_clock_cost<Clock>(resolution.mean);\n\n                env\
    \ = new Environment<FloatDuration<Clock>>{ resolution, cost };\n             \
    \   return *env;\n            }\n        } // namespace Detail\n    } // namespace\
    \ Benchmark\n} // namespace Catch\n\n// end catch_estimate_clock.hpp\n// start\
    \ catch_analyse.hpp\n\n // Run and analyse one benchmark\n\n\n// start catch_sample_analysis.hpp\n\
    \n// Benchmark results\n\n\n#include <algorithm>\n#include <vector>\n#include\
    \ <string>\n#include <iterator>\n\nnamespace Catch {\n    namespace Benchmark\
    \ {\n        template <typename Duration>\n        struct SampleAnalysis {\n \
    \           std::vector<Duration> samples;\n            Estimate<Duration> mean;\n\
    \            Estimate<Duration> standard_deviation;\n            OutlierClassification\
    \ outliers;\n            double outlier_variance;\n\n            template <typename\
    \ Duration2>\n            operator SampleAnalysis<Duration2>() const {\n     \
    \           std::vector<Duration2> samples2;\n                samples2.reserve(samples.size());\n\
    \                std::transform(samples.begin(), samples.end(), std::back_inserter(samples2),\
    \ [](Duration d) { return Duration2(d); });\n                return {\n      \
    \              std::move(samples2),\n                    mean,\n             \
    \       standard_deviation,\n                    outliers,\n                 \
    \   outlier_variance,\n                };\n            }\n        };\n    } //\
    \ namespace Benchmark\n} // namespace Catch\n\n// end catch_sample_analysis.hpp\n\
    #include <algorithm>\n#include <iterator>\n#include <vector>\n\nnamespace Catch\
    \ {\n    namespace Benchmark {\n        namespace Detail {\n            template\
    \ <typename Duration, typename Iterator>\n            SampleAnalysis<Duration>\
    \ analyse(const IConfig &cfg, Environment<Duration>, Iterator first, Iterator\
    \ last) {\n                if (!cfg.benchmarkNoAnalysis()) {\n               \
    \     std::vector<double> samples;\n                    samples.reserve(last -\
    \ first);\n                    std::transform(first, last, std::back_inserter(samples),\
    \ [](Duration d) { return d.count(); });\n\n                    auto analysis\
    \ = Catch::Benchmark::Detail::analyse_samples(cfg.benchmarkConfidenceInterval(),\
    \ cfg.benchmarkResamples(), samples.begin(), samples.end());\n               \
    \     auto outliers = Catch::Benchmark::Detail::classify_outliers(samples.begin(),\
    \ samples.end());\n\n                    auto wrap_estimate = [](Estimate<double>\
    \ e) {\n                        return Estimate<Duration> {\n                \
    \            Duration(e.point),\n                                Duration(e.lower_bound),\n\
    \                                Duration(e.upper_bound),\n                  \
    \              e.confidence_interval,\n                        };\n          \
    \          };\n                    std::vector<Duration> samples2;\n         \
    \           samples2.reserve(samples.size());\n                    std::transform(samples.begin(),\
    \ samples.end(), std::back_inserter(samples2), [](double d) { return Duration(d);\
    \ });\n                    return {\n                        std::move(samples2),\n\
    \                        wrap_estimate(analysis.mean),\n                     \
    \   wrap_estimate(analysis.standard_deviation),\n                        outliers,\n\
    \                        analysis.outlier_variance,\n                    };\n\
    \                } else {\n                    std::vector<Duration> samples;\n\
    \                    samples.reserve(last - first);\n\n                    Duration\
    \ mean = Duration(0);\n                    int i = 0;\n                    for\
    \ (auto it = first; it < last; ++it, ++i) {\n                        samples.push_back(Duration(*it));\n\
    \                        mean += Duration(*it);\n                    }\n     \
    \               mean /= i;\n\n                    return {\n                 \
    \       std::move(samples),\n                        Estimate<Duration>{mean,\
    \ mean, mean, 0.0},\n                        Estimate<Duration>{Duration(0), Duration(0),\
    \ Duration(0), 0.0},\n                        OutlierClassification{},\n     \
    \                   0.0\n                    };\n                }\n         \
    \   }\n        } // namespace Detail\n    } // namespace Benchmark\n} // namespace\
    \ Catch\n\n// end catch_analyse.hpp\n#include <algorithm>\n#include <functional>\n\
    #include <string>\n#include <vector>\n#include <cmath>\n\nnamespace Catch {\n\
    \    namespace Benchmark {\n        struct Benchmark {\n            Benchmark(std::string\
    \ &&name)\n                : name(std::move(name)) {}\n\n            template\
    \ <class FUN>\n            Benchmark(std::string &&name, FUN &&func)\n       \
    \         : fun(std::move(func)), name(std::move(name)) {}\n\n            template\
    \ <typename Clock>\n            ExecutionPlan<FloatDuration<Clock>> prepare(const\
    \ IConfig &cfg, Environment<FloatDuration<Clock>> env) const {\n             \
    \   auto min_time = env.clock_resolution.mean * Detail::minimum_ticks;\n     \
    \           auto run_time = std::max(min_time, std::chrono::duration_cast<decltype(min_time)>(cfg.benchmarkWarmupTime()));\n\
    \                auto&& test = Detail::run_for_at_least<Clock>(std::chrono::duration_cast<ClockDuration<Clock>>(run_time),\
    \ 1, fun);\n                int new_iters = static_cast<int>(std::ceil(min_time\
    \ * test.iterations / test.elapsed));\n                return { new_iters, test.elapsed\
    \ / test.iterations * new_iters * cfg.benchmarkSamples(), fun, std::chrono::duration_cast<FloatDuration<Clock>>(cfg.benchmarkWarmupTime()),\
    \ Detail::warmup_iterations };\n            }\n\n            template <typename\
    \ Clock = default_clock>\n            void run() {\n                IConfigPtr\
    \ cfg = getCurrentContext().getConfig();\n\n                auto env = Detail::measure_environment<Clock>();\n\
    \n                getResultCapture().benchmarkPreparing(name);\n             \
    \   CATCH_TRY{\n                    auto plan = user_code([&] {\n            \
    \            return prepare<Clock>(*cfg, env);\n                    });\n\n  \
    \                  BenchmarkInfo info {\n                        name,\n     \
    \                   plan.estimated_duration.count(),\n                       \
    \ plan.iterations_per_sample,\n                        cfg->benchmarkSamples(),\n\
    \                        cfg->benchmarkResamples(),\n                        env.clock_resolution.mean.count(),\n\
    \                        env.clock_cost.mean.count()\n                    };\n\
    \n                    getResultCapture().benchmarkStarting(info);\n\n        \
    \            auto samples = user_code([&] {\n                        return plan.template\
    \ run<Clock>(*cfg, env);\n                    });\n\n                    auto\
    \ analysis = Detail::analyse(*cfg, env, samples.begin(), samples.end());\n   \
    \                 BenchmarkStats<FloatDuration<Clock>> stats{ info, analysis.samples,\
    \ analysis.mean, analysis.standard_deviation, analysis.outliers, analysis.outlier_variance\
    \ };\n                    getResultCapture().benchmarkEnded(stats);\n\n      \
    \          } CATCH_CATCH_ALL{\n                    if (translateActiveException()\
    \ != Detail::benchmarkErrorMsg) // benchmark errors have been reported, otherwise\
    \ rethrow.\n                        std::rethrow_exception(std::current_exception());\n\
    \                }\n            }\n\n            // sets lambda to be used in\
    \ fun *and* executes benchmark!\n            template <typename Fun,\n       \
    \         typename std::enable_if<!Detail::is_related<Fun, Benchmark>::value,\
    \ int>::type = 0>\n                Benchmark & operator=(Fun func) {\n       \
    \         fun = Detail::BenchmarkFunction(func);\n                run();\n   \
    \             return *this;\n            }\n\n            explicit operator bool()\
    \ {\n                return true;\n            }\n\n        private:\n       \
    \     Detail::BenchmarkFunction fun;\n            std::string name;\n        };\n\
    \    }\n} // namespace Catch\n\n#define INTERNAL_CATCH_GET_1_ARG(arg1, arg2, ...)\
    \ arg1\n#define INTERNAL_CATCH_GET_2_ARG(arg1, arg2, ...) arg2\n\n#define INTERNAL_CATCH_BENCHMARK(BenchmarkName,\
    \ name, benchmarkIndex)\\\n    if( Catch::Benchmark::Benchmark BenchmarkName{name}\
    \ ) \\\n        BenchmarkName = [&](int benchmarkIndex)\n\n#define INTERNAL_CATCH_BENCHMARK_ADVANCED(BenchmarkName,\
    \ name)\\\n    if( Catch::Benchmark::Benchmark BenchmarkName{name} ) \\\n    \
    \    BenchmarkName = [&]\n\n// end catch_benchmark.hpp\n// start catch_constructor.hpp\n\
    \n// Constructor and destructor helpers\n\n\n#include <type_traits>\n\nnamespace\
    \ Catch {\n    namespace Benchmark {\n        namespace Detail {\n           \
    \ template <typename T, bool Destruct>\n            struct ObjectStorage\n   \
    \         {\n                using TStorage = typename std::aligned_storage<sizeof(T),\
    \ std::alignment_of<T>::value>::type;\n\n                ObjectStorage() : data()\
    \ {}\n\n                ObjectStorage(const ObjectStorage& other)\n          \
    \      {\n                    new(&data) T(other.stored_object());\n         \
    \       }\n\n                ObjectStorage(ObjectStorage&& other)\n          \
    \      {\n                    new(&data) T(std::move(other.stored_object()));\n\
    \                }\n\n                ~ObjectStorage() { destruct_on_exit<T>();\
    \ }\n\n                template <typename... Args>\n                void construct(Args&&...\
    \ args)\n                {\n                    new (&data) T(std::forward<Args>(args)...);\n\
    \                }\n\n                template <bool AllowManualDestruction =\
    \ !Destruct>\n                typename std::enable_if<AllowManualDestruction>::type\
    \ destruct()\n                {\n                    stored_object().~T();\n \
    \               }\n\n            private:\n                // If this is a constructor\
    \ benchmark, destruct the underlying object\n                template <typename\
    \ U>\n                void destruct_on_exit(typename std::enable_if<Destruct,\
    \ U>::type* = 0) { destruct<true>(); }\n                // Otherwise, don't\n\
    \                template <typename U>\n                void destruct_on_exit(typename\
    \ std::enable_if<!Destruct, U>::type* = 0) { }\n\n                T& stored_object()\
    \ {\n                    return *static_cast<T*>(static_cast<void*>(&data));\n\
    \                }\n\n                T const& stored_object() const {\n     \
    \               return *static_cast<T*>(static_cast<void*>(&data));\n        \
    \        }\n\n                TStorage data;\n            };\n        }\n\n  \
    \      template <typename T>\n        using storage_for = Detail::ObjectStorage<T,\
    \ true>;\n\n        template <typename T>\n        using destructable_object =\
    \ Detail::ObjectStorage<T, false>;\n    }\n}\n\n// end catch_constructor.hpp\n\
    // end catch_benchmarking_all.hpp\n#endif\n\n#endif // ! CATCH_CONFIG_IMPL_ONLY\n\
    \n#ifdef CATCH_IMPL\n// start catch_impl.hpp\n\n#ifdef __clang__\n#pragma clang\
    \ diagnostic push\n#pragma clang diagnostic ignored \"-Wweak-vtables\"\n#endif\n\
    \n// Keep these here for external reporters\n// start catch_test_case_tracker.h\n\
    \n#include <string>\n#include <vector>\n#include <memory>\n\nnamespace Catch {\n\
    namespace TestCaseTracking {\n\n    struct NameAndLocation {\n        std::string\
    \ name;\n        SourceLineInfo location;\n\n        NameAndLocation( std::string\
    \ const& _name, SourceLineInfo const& _location );\n        friend bool operator==(NameAndLocation\
    \ const& lhs, NameAndLocation const& rhs) {\n            return lhs.name == rhs.name\n\
    \                && lhs.location == rhs.location;\n        }\n    };\n\n    class\
    \ ITracker;\n\n    using ITrackerPtr = std::shared_ptr<ITracker>;\n\n    class\
    \  ITracker {\n        NameAndLocation m_nameAndLocation;\n\n    public:\n   \
    \     ITracker(NameAndLocation const& nameAndLoc) :\n            m_nameAndLocation(nameAndLoc)\n\
    \        {}\n\n        // static queries\n        NameAndLocation const& nameAndLocation()\
    \ const {\n            return m_nameAndLocation;\n        }\n\n        virtual\
    \ ~ITracker();\n\n        // dynamic queries\n        virtual bool isComplete()\
    \ const = 0; // Successfully completed or failed\n        virtual bool isSuccessfullyCompleted()\
    \ const = 0;\n        virtual bool isOpen() const = 0; // Started but not complete\n\
    \        virtual bool hasChildren() const = 0;\n        virtual bool hasStarted()\
    \ const = 0;\n\n        virtual ITracker& parent() = 0;\n\n        // actions\n\
    \        virtual void close() = 0; // Successfully complete\n        virtual void\
    \ fail() = 0;\n        virtual void markAsNeedingAnotherRun() = 0;\n\n       \
    \ virtual void addChild( ITrackerPtr const& child ) = 0;\n        virtual ITrackerPtr\
    \ findChild( NameAndLocation const& nameAndLocation ) = 0;\n        virtual void\
    \ openChild() = 0;\n\n        // Debug/ checking\n        virtual bool isSectionTracker()\
    \ const = 0;\n        virtual bool isGeneratorTracker() const = 0;\n    };\n\n\
    \    class TrackerContext {\n\n        enum RunState {\n            NotStarted,\n\
    \            Executing,\n            CompletedCycle\n        };\n\n        ITrackerPtr\
    \ m_rootTracker;\n        ITracker* m_currentTracker = nullptr;\n        RunState\
    \ m_runState = NotStarted;\n\n    public:\n\n        ITracker& startRun();\n \
    \       void endRun();\n\n        void startCycle();\n        void completeCycle();\n\
    \n        bool completedCycle() const;\n        ITracker& currentTracker();\n\
    \        void setCurrentTracker( ITracker* tracker );\n    };\n\n    class TrackerBase\
    \ : public ITracker {\n    protected:\n        enum CycleState {\n           \
    \ NotStarted,\n            Executing,\n            ExecutingChildren,\n      \
    \      NeedsAnotherRun,\n            CompletedSuccessfully,\n            Failed\n\
    \        };\n\n        using Children = std::vector<ITrackerPtr>;\n        TrackerContext&\
    \ m_ctx;\n        ITracker* m_parent;\n        Children m_children;\n        CycleState\
    \ m_runState = NotStarted;\n\n    public:\n        TrackerBase( NameAndLocation\
    \ const& nameAndLocation, TrackerContext& ctx, ITracker* parent );\n\n       \
    \ bool isComplete() const override;\n        bool isSuccessfullyCompleted() const\
    \ override;\n        bool isOpen() const override;\n        bool hasChildren()\
    \ const override;\n        bool hasStarted() const override {\n            return\
    \ m_runState != NotStarted;\n        }\n\n        void addChild( ITrackerPtr const&\
    \ child ) override;\n\n        ITrackerPtr findChild( NameAndLocation const& nameAndLocation\
    \ ) override;\n        ITracker& parent() override;\n\n        void openChild()\
    \ override;\n\n        bool isSectionTracker() const override;\n        bool isGeneratorTracker()\
    \ const override;\n\n        void open();\n\n        void close() override;\n\
    \        void fail() override;\n        void markAsNeedingAnotherRun() override;\n\
    \n    private:\n        void moveToParent();\n        void moveToThis();\n   \
    \ };\n\n    class SectionTracker : public TrackerBase {\n        std::vector<std::string>\
    \ m_filters;\n        std::string m_trimmed_name;\n    public:\n        SectionTracker(\
    \ NameAndLocation const& nameAndLocation, TrackerContext& ctx, ITracker* parent\
    \ );\n\n        bool isSectionTracker() const override;\n\n        bool isComplete()\
    \ const override;\n\n        static SectionTracker& acquire( TrackerContext& ctx,\
    \ NameAndLocation const& nameAndLocation );\n\n        void tryOpen();\n\n   \
    \     void addInitialFilters( std::vector<std::string> const& filters );\n   \
    \     void addNextFilters( std::vector<std::string> const& filters );\n    };\n\
    \n} // namespace TestCaseTracking\n\nusing TestCaseTracking::ITracker;\nusing\
    \ TestCaseTracking::TrackerContext;\nusing TestCaseTracking::SectionTracker;\n\
    \n} // namespace Catch\n\n// end catch_test_case_tracker.h\n\n// start catch_leak_detector.h\n\
    \nnamespace Catch {\n\n    struct LeakDetector {\n        LeakDetector();\n  \
    \      ~LeakDetector();\n    };\n\n}\n// end catch_leak_detector.h\n// Cpp files\
    \ will be included in the single-header file here\n// start catch_stats.cpp\n\n\
    // Statistical analysis tools\n\n#if defined(CATCH_CONFIG_ENABLE_BENCHMARKING)\n\
    \n#include <cassert>\n#include <random>\n\n#if defined(CATCH_CONFIG_USE_ASYNC)\n\
    #include <future>\n#endif\n\nnamespace {\n    double erf_inv(double x) {\n   \
    \     // Code accompanying the article \"Approximating the erfinv function\" in\
    \ GPU Computing Gems, Volume 2\n        double w, p;\n\n        w = -log((1.0\
    \ - x) * (1.0 + x));\n\n        if (w < 6.250000) {\n            w = w - 3.125000;\n\
    \            p = -3.6444120640178196996e-21;\n            p = -1.685059138182016589e-19\
    \ + p * w;\n            p = 1.2858480715256400167e-18 + p * w;\n            p\
    \ = 1.115787767802518096e-17 + p * w;\n            p = -1.333171662854620906e-16\
    \ + p * w;\n            p = 2.0972767875968561637e-17 + p * w;\n            p\
    \ = 6.6376381343583238325e-15 + p * w;\n            p = -4.0545662729752068639e-14\
    \ + p * w;\n            p = -8.1519341976054721522e-14 + p * w;\n            p\
    \ = 2.6335093153082322977e-12 + p * w;\n            p = -1.2975133253453532498e-11\
    \ + p * w;\n            p = -5.4154120542946279317e-11 + p * w;\n            p\
    \ = 1.051212273321532285e-09 + p * w;\n            p = -4.1126339803469836976e-09\
    \ + p * w;\n            p = -2.9070369957882005086e-08 + p * w;\n            p\
    \ = 4.2347877827932403518e-07 + p * w;\n            p = -1.3654692000834678645e-06\
    \ + p * w;\n            p = -1.3882523362786468719e-05 + p * w;\n            p\
    \ = 0.0001867342080340571352 + p * w;\n            p = -0.00074070253416626697512\
    \ + p * w;\n            p = -0.0060336708714301490533 + p * w;\n            p\
    \ = 0.24015818242558961693 + p * w;\n            p = 1.6536545626831027356 + p\
    \ * w;\n        } else if (w < 16.000000) {\n            w = sqrt(w) - 3.250000;\n\
    \            p = 2.2137376921775787049e-09;\n            p = 9.0756561938885390979e-08\
    \ + p * w;\n            p = -2.7517406297064545428e-07 + p * w;\n            p\
    \ = 1.8239629214389227755e-08 + p * w;\n            p = 1.5027403968909827627e-06\
    \ + p * w;\n            p = -4.013867526981545969e-06 + p * w;\n            p\
    \ = 2.9234449089955446044e-06 + p * w;\n            p = 1.2475304481671778723e-05\
    \ + p * w;\n            p = -4.7318229009055733981e-05 + p * w;\n            p\
    \ = 6.8284851459573175448e-05 + p * w;\n            p = 2.4031110387097893999e-05\
    \ + p * w;\n            p = -0.0003550375203628474796 + p * w;\n            p\
    \ = 0.00095328937973738049703 + p * w;\n            p = -0.0016882755560235047313\
    \ + p * w;\n            p = 0.0024914420961078508066 + p * w;\n            p =\
    \ -0.0037512085075692412107 + p * w;\n            p = 0.005370914553590063617\
    \ + p * w;\n            p = 1.0052589676941592334 + p * w;\n            p = 3.0838856104922207635\
    \ + p * w;\n        } else {\n            w = sqrt(w) - 5.000000;\n          \
    \  p = -2.7109920616438573243e-11;\n            p = -2.5556418169965252055e-10\
    \ + p * w;\n            p = 1.5076572693500548083e-09 + p * w;\n            p\
    \ = -3.7894654401267369937e-09 + p * w;\n            p = 7.6157012080783393804e-09\
    \ + p * w;\n            p = -1.4960026627149240478e-08 + p * w;\n            p\
    \ = 2.9147953450901080826e-08 + p * w;\n            p = -6.7711997758452339498e-08\
    \ + p * w;\n            p = 2.2900482228026654717e-07 + p * w;\n            p\
    \ = -9.9298272942317002539e-07 + p * w;\n            p = 4.5260625972231537039e-06\
    \ + p * w;\n            p = -1.9681778105531670567e-05 + p * w;\n            p\
    \ = 7.5995277030017761139e-05 + p * w;\n            p = -0.00021503011930044477347\
    \ + p * w;\n            p = -0.00013871931833623122026 + p * w;\n            p\
    \ = 1.0103004648645343977 + p * w;\n            p = 4.8499064014085844221 + p\
    \ * w;\n        }\n        return p * x;\n    }\n\n    double standard_deviation(std::vector<double>::iterator\
    \ first, std::vector<double>::iterator last) {\n        auto m = Catch::Benchmark::Detail::mean(first,\
    \ last);\n        double variance = std::accumulate(first, last, 0., [m](double\
    \ a, double b) {\n            double diff = b - m;\n            return a + diff\
    \ * diff;\n            }) / (last - first);\n            return std::sqrt(variance);\n\
    \    }\n\n}\n\nnamespace Catch {\n    namespace Benchmark {\n        namespace\
    \ Detail {\n\n            double weighted_average_quantile(int k, int q, std::vector<double>::iterator\
    \ first, std::vector<double>::iterator last) {\n                auto count = last\
    \ - first;\n                double idx = (count - 1) * k / static_cast<double>(q);\n\
    \                int j = static_cast<int>(idx);\n                double g = idx\
    \ - j;\n                std::nth_element(first, first + j, last);\n          \
    \      auto xj = first[j];\n                if (g == 0) return xj;\n\n       \
    \         auto xj1 = *std::min_element(first + (j + 1), last);\n             \
    \   return xj + g * (xj1 - xj);\n            }\n\n            double erfc_inv(double\
    \ x) {\n                return erf_inv(1.0 - x);\n            }\n\n          \
    \  double normal_quantile(double p) {\n                static const double ROOT_TWO\
    \ = std::sqrt(2.0);\n\n                double result = 0.0;\n                assert(p\
    \ >= 0 && p <= 1);\n                if (p < 0 || p > 1) {\n                  \
    \  return result;\n                }\n\n                result = -erfc_inv(2.0\
    \ * p);\n                // result *= normal distribution standard deviation (1.0)\
    \ * sqrt(2)\n                result *= /*sd * */ ROOT_TWO;\n                //\
    \ result += normal disttribution mean (0)\n                return result;\n  \
    \          }\n\n            double outlier_variance(Estimate<double> mean, Estimate<double>\
    \ stddev, int n) {\n                double sb = stddev.point;\n              \
    \  double mn = mean.point / n;\n                double mg_min = mn / 2.;\n   \
    \             double sg = std::min(mg_min / 4., sb / std::sqrt(n));\n        \
    \        double sg2 = sg * sg;\n                double sb2 = sb * sb;\n\n    \
    \            auto c_max = [n, mn, sb2, sg2](double x) -> double {\n          \
    \          double k = mn - x;\n                    double d = k * k;\n       \
    \             double nd = n * d;\n                    double k0 = -n * nd;\n \
    \                   double k1 = sb2 - n * sg2 + nd;\n                    double\
    \ det = k1 * k1 - 4 * sg2 * k0;\n                    return (int)(-2. * k0 / (k1\
    \ + std::sqrt(det)));\n                };\n\n                auto var_out = [n,\
    \ sb2, sg2](double c) {\n                    double nc = n - c;\n            \
    \        return (nc / n) * (sb2 - nc * sg2);\n                };\n\n         \
    \       return std::min(var_out(1), var_out(std::min(c_max(0.), c_max(mg_min))))\
    \ / sb2;\n            }\n\n            bootstrap_analysis analyse_samples(double\
    \ confidence_level, int n_resamples, std::vector<double>::iterator first, std::vector<double>::iterator\
    \ last) {\n                CATCH_INTERNAL_START_WARNINGS_SUPPRESSION\n       \
    \         CATCH_INTERNAL_SUPPRESS_GLOBALS_WARNINGS\n                static std::random_device\
    \ entropy;\n                CATCH_INTERNAL_STOP_WARNINGS_SUPPRESSION\n\n     \
    \           auto n = static_cast<int>(last - first); // seriously, one can't use\
    \ integral types without hell in C++\n\n                auto mean = &Detail::mean<std::vector<double>::iterator>;\n\
    \                auto stddev = &standard_deviation;\n\n#if defined(CATCH_CONFIG_USE_ASYNC)\n\
    \                auto Estimate = [=](double(*f)(std::vector<double>::iterator,\
    \ std::vector<double>::iterator)) {\n                    auto seed = entropy();\n\
    \                    return std::async(std::launch::async, [=] {\n           \
    \             std::mt19937 rng(seed);\n                        auto resampled\
    \ = resample(rng, n_resamples, first, last, f);\n                        return\
    \ bootstrap(confidence_level, first, last, resampled, f);\n                  \
    \  });\n                };\n\n                auto mean_future = Estimate(mean);\n\
    \                auto stddev_future = Estimate(stddev);\n\n                auto\
    \ mean_estimate = mean_future.get();\n                auto stddev_estimate = stddev_future.get();\n\
    #else\n                auto Estimate = [=](double(*f)(std::vector<double>::iterator,\
    \ std::vector<double>::iterator)) {\n                    auto seed = entropy();\n\
    \                    std::mt19937 rng(seed);\n                    auto resampled\
    \ = resample(rng, n_resamples, first, last, f);\n                    return bootstrap(confidence_level,\
    \ first, last, resampled, f);\n                };\n\n                auto mean_estimate\
    \ = Estimate(mean);\n                auto stddev_estimate = Estimate(stddev);\n\
    #endif // CATCH_USE_ASYNC\n\n                double outlier_variance = Detail::outlier_variance(mean_estimate,\
    \ stddev_estimate, n);\n\n                return { mean_estimate, stddev_estimate,\
    \ outlier_variance };\n            }\n        } // namespace Detail\n    } //\
    \ namespace Benchmark\n} // namespace Catch\n\n#endif // CATCH_CONFIG_ENABLE_BENCHMARKING\n\
    // end catch_stats.cpp\n// start catch_approx.cpp\n\n#include <cmath>\n#include\
    \ <limits>\n\nnamespace {\n\n// Performs equivalent check of std::fabs(lhs - rhs)\
    \ <= margin\n// But without the subtraction to allow for INFINITY in comparison\n\
    bool marginComparison(double lhs, double rhs, double margin) {\n    return (lhs\
    \ + margin >= rhs) && (rhs + margin >= lhs);\n}\n\n}\n\nnamespace Catch {\nnamespace\
    \ Detail {\n\n    Approx::Approx ( double value )\n    :   m_epsilon( std::numeric_limits<float>::epsilon()*100\
    \ ),\n        m_margin( 0.0 ),\n        m_scale( 0.0 ),\n        m_value( value\
    \ )\n    {}\n\n    Approx Approx::custom() {\n        return Approx( 0 );\n  \
    \  }\n\n    Approx Approx::operator-() const {\n        auto temp(*this);\n  \
    \      temp.m_value = -temp.m_value;\n        return temp;\n    }\n\n    std::string\
    \ Approx::toString() const {\n        ReusableStringStream rss;\n        rss <<\
    \ \"Approx( \" << ::Catch::Detail::stringify( m_value ) << \" )\";\n        return\
    \ rss.str();\n    }\n\n    bool Approx::equalityComparisonImpl(const double other)\
    \ const {\n        // First try with fixed margin, then compute margin based on\
    \ epsilon, scale and Approx's value\n        // Thanks to Richard Harris for his\
    \ help refining the scaled margin value\n        return marginComparison(m_value,\
    \ other, m_margin)\n            || marginComparison(m_value, other, m_epsilon\
    \ * (m_scale + std::fabs(std::isinf(m_value)? 0 : m_value)));\n    }\n\n    void\
    \ Approx::setMargin(double newMargin) {\n        CATCH_ENFORCE(newMargin >= 0,\n\
    \            \"Invalid Approx::margin: \" << newMargin << '.'\n            <<\
    \ \" Approx::Margin has to be non-negative.\");\n        m_margin = newMargin;\n\
    \    }\n\n    void Approx::setEpsilon(double newEpsilon) {\n        CATCH_ENFORCE(newEpsilon\
    \ >= 0 && newEpsilon <= 1.0,\n            \"Invalid Approx::epsilon: \" << newEpsilon\
    \ << '.'\n            << \" Approx::epsilon has to be in [0, 1]\");\n        m_epsilon\
    \ = newEpsilon;\n    }\n\n} // end namespace Detail\n\nnamespace literals {\n\
    \    Detail::Approx operator \"\" _a(long double val) {\n        return Detail::Approx(val);\n\
    \    }\n    Detail::Approx operator \"\" _a(unsigned long long val) {\n      \
    \  return Detail::Approx(val);\n    }\n} // end namespace literals\n\nstd::string\
    \ StringMaker<Catch::Detail::Approx>::convert(Catch::Detail::Approx const& value)\
    \ {\n    return value.toString();\n}\n\n} // end namespace Catch\n// end catch_approx.cpp\n\
    // start catch_assertionhandler.cpp\n\n// start catch_debugger.h\n\nnamespace\
    \ Catch {\n    bool isDebuggerActive();\n}\n\n#ifdef CATCH_PLATFORM_MAC\n\n  \
    \  #if defined(__i386__) || defined(__x86_64__)\n        #define CATCH_TRAP()\
    \ __asm__(\"int $3\\n\" : : ) /* NOLINT */\n    #elif defined(__aarch64__)\n \
    \       #define CATCH_TRAP()  __asm__(\".inst 0xd4200000\")\n    #endif\n\n#elif\
    \ defined(CATCH_PLATFORM_IPHONE)\n\n    // use inline assembler\n    #if defined(__i386__)\
    \ || defined(__x86_64__)\n        #define CATCH_TRAP()  __asm__(\"int $3\")\n\
    \    #elif defined(__aarch64__)\n        #define CATCH_TRAP()  __asm__(\".inst\
    \ 0xd4200000\")\n    #elif defined(__arm__) && !defined(__thumb__)\n        #define\
    \ CATCH_TRAP()  __asm__(\".inst 0xe7f001f0\")\n    #elif defined(__arm__) && \
    \ defined(__thumb__)\n        #define CATCH_TRAP()  __asm__(\".inst 0xde01\")\n\
    \    #endif\n\n#elif defined(CATCH_PLATFORM_LINUX)\n    // If we can use inline\
    \ assembler, do it because this allows us to break\n    // directly at the location\
    \ of the failing check instead of breaking inside\n    // raise() called from\
    \ it, i.e. one stack frame below.\n    #if defined(__GNUC__) && (defined(__i386)\
    \ || defined(__x86_64))\n        #define CATCH_TRAP() asm volatile (\"int $3\"\
    ) /* NOLINT */\n    #else // Fall back to the generic way.\n        #include <signal.h>\n\
    \n        #define CATCH_TRAP() raise(SIGTRAP)\n    #endif\n#elif defined(_MSC_VER)\n\
    \    #define CATCH_TRAP() __debugbreak()\n#elif defined(__MINGW32__)\n    extern\
    \ \"C\" __declspec(dllimport) void __stdcall DebugBreak();\n    #define CATCH_TRAP()\
    \ DebugBreak()\n#endif\n\n#ifndef CATCH_BREAK_INTO_DEBUGGER\n    #ifdef CATCH_TRAP\n\
    \        #define CATCH_BREAK_INTO_DEBUGGER() []{ if( Catch::isDebuggerActive()\
    \ ) { CATCH_TRAP(); } }()\n    #else\n        #define CATCH_BREAK_INTO_DEBUGGER()\
    \ []{}()\n    #endif\n#endif\n\n// end catch_debugger.h\n// start catch_run_context.h\n\
    \n// start catch_fatal_condition.h\n\n// start catch_windows_h_proxy.h\n\n\n#if\
    \ defined(CATCH_PLATFORM_WINDOWS)\n\n#if !defined(NOMINMAX) && !defined(CATCH_CONFIG_NO_NOMINMAX)\n\
    #  define CATCH_DEFINED_NOMINMAX\n#  define NOMINMAX\n#endif\n#if !defined(WIN32_LEAN_AND_MEAN)\
    \ && !defined(CATCH_CONFIG_NO_WIN32_LEAN_AND_MEAN)\n#  define CATCH_DEFINED_WIN32_LEAN_AND_MEAN\n\
    #  define WIN32_LEAN_AND_MEAN\n#endif\n\n#ifdef __AFXDLL\n#include <AfxWin.h>\n\
    #else\n#include <windows.h>\n#endif\n\n#ifdef CATCH_DEFINED_NOMINMAX\n#  undef\
    \ NOMINMAX\n#endif\n#ifdef CATCH_DEFINED_WIN32_LEAN_AND_MEAN\n#  undef WIN32_LEAN_AND_MEAN\n\
    #endif\n\n#endif // defined(CATCH_PLATFORM_WINDOWS)\n\n// end catch_windows_h_proxy.h\n\
    #if defined( CATCH_CONFIG_WINDOWS_SEH )\n\nnamespace Catch {\n\n    struct FatalConditionHandler\
    \ {\n\n        static LONG CALLBACK handleVectoredException(PEXCEPTION_POINTERS\
    \ ExceptionInfo);\n        FatalConditionHandler();\n        static void reset();\n\
    \        ~FatalConditionHandler();\n\n    private:\n        static bool isSet;\n\
    \        static ULONG guaranteeSize;\n        static PVOID exceptionHandlerHandle;\n\
    \    };\n\n} // namespace Catch\n\n#elif defined ( CATCH_CONFIG_POSIX_SIGNALS\
    \ )\n\n#include <signal.h>\n\nnamespace Catch {\n\n    struct FatalConditionHandler\
    \ {\n\n        static bool isSet;\n        static struct sigaction oldSigActions[];\n\
    \        static stack_t oldSigStack;\n        static char altStackMem[];\n\n \
    \       static void handleSignal( int sig );\n\n        FatalConditionHandler();\n\
    \        ~FatalConditionHandler();\n        static void reset();\n    };\n\n}\
    \ // namespace Catch\n\n#else\n\nnamespace Catch {\n    struct FatalConditionHandler\
    \ {\n        void reset();\n    };\n}\n\n#endif\n\n// end catch_fatal_condition.h\n\
    #include <string>\n\nnamespace Catch {\n\n    struct IMutableContext;\n\n    ///////////////////////////////////////////////////////////////////////////\n\
    \n    class RunContext : public IResultCapture, public IRunner {\n\n    public:\n\
    \        RunContext( RunContext const& ) = delete;\n        RunContext& operator\
    \ =( RunContext const& ) = delete;\n\n        explicit RunContext( IConfigPtr\
    \ const& _config, IStreamingReporterPtr&& reporter );\n\n        ~RunContext()\
    \ override;\n\n        void testGroupStarting( std::string const& testSpec, std::size_t\
    \ groupIndex, std::size_t groupsCount );\n        void testGroupEnded( std::string\
    \ const& testSpec, Totals const& totals, std::size_t groupIndex, std::size_t groupsCount\
    \ );\n\n        Totals runTest(TestCase const& testCase);\n\n        IConfigPtr\
    \ config() const;\n        IStreamingReporter& reporter() const;\n\n    public:\
    \ // IResultCapture\n\n        // Assertion handlers\n        void handleExpr\n\
    \                (   AssertionInfo const& info,\n                    ITransientExpression\
    \ const& expr,\n                    AssertionReaction& reaction ) override;\n\
    \        void handleMessage\n                (   AssertionInfo const& info,\n\
    \                    ResultWas::OfType resultType,\n                    StringRef\
    \ const& message,\n                    AssertionReaction& reaction ) override;\n\
    \        void handleUnexpectedExceptionNotThrown\n                (   AssertionInfo\
    \ const& info,\n                    AssertionReaction& reaction ) override;\n\
    \        void handleUnexpectedInflightException\n                (   AssertionInfo\
    \ const& info,\n                    std::string const& message,\n            \
    \        AssertionReaction& reaction ) override;\n        void handleIncomplete\n\
    \                (   AssertionInfo const& info ) override;\n        void handleNonExpr\n\
    \                (   AssertionInfo const &info,\n                    ResultWas::OfType\
    \ resultType,\n                    AssertionReaction &reaction ) override;\n\n\
    \        bool sectionStarted( SectionInfo const& sectionInfo, Counts& assertions\
    \ ) override;\n\n        void sectionEnded( SectionEndInfo const& endInfo ) override;\n\
    \        void sectionEndedEarly( SectionEndInfo const& endInfo ) override;\n\n\
    \        auto acquireGeneratorTracker( StringRef generatorName, SourceLineInfo\
    \ const& lineInfo ) -> IGeneratorTracker& override;\n\n#if defined(CATCH_CONFIG_ENABLE_BENCHMARKING)\n\
    \        void benchmarkPreparing( std::string const& name ) override;\n      \
    \  void benchmarkStarting( BenchmarkInfo const& info ) override;\n        void\
    \ benchmarkEnded( BenchmarkStats<> const& stats ) override;\n        void benchmarkFailed(\
    \ std::string const& error ) override;\n#endif // CATCH_CONFIG_ENABLE_BENCHMARKING\n\
    \n        void pushScopedMessage( MessageInfo const& message ) override;\n   \
    \     void popScopedMessage( MessageInfo const& message ) override;\n\n      \
    \  void emplaceUnscopedMessage( MessageBuilder const& builder ) override;\n\n\
    \        std::string getCurrentTestName() const override;\n\n        const AssertionResult*\
    \ getLastResult() const override;\n\n        void exceptionEarlyReported() override;\n\
    \n        void handleFatalErrorCondition( StringRef message ) override;\n\n  \
    \      bool lastAssertionPassed() override;\n\n        void assertionPassed()\
    \ override;\n\n    public:\n        // !TBD We need to do this another way!\n\
    \        bool aborting() const final;\n\n    private:\n\n        void runCurrentTest(\
    \ std::string& redirectedCout, std::string& redirectedCerr );\n        void invokeActiveTestCase();\n\
    \n        void resetAssertionInfo();\n        bool testForMissingAssertions( Counts&\
    \ assertions );\n\n        void assertionEnded( AssertionResult const& result\
    \ );\n        void reportExpr\n                (   AssertionInfo const &info,\n\
    \                    ResultWas::OfType resultType,\n                    ITransientExpression\
    \ const *expr,\n                    bool negated );\n\n        void populateReaction(\
    \ AssertionReaction& reaction );\n\n    private:\n\n        void handleUnfinishedSections();\n\
    \n        TestRunInfo m_runInfo;\n        IMutableContext& m_context;\n      \
    \  TestCase const* m_activeTestCase = nullptr;\n        ITracker* m_testCaseTracker\
    \ = nullptr;\n        Option<AssertionResult> m_lastResult;\n\n        IConfigPtr\
    \ m_config;\n        Totals m_totals;\n        IStreamingReporterPtr m_reporter;\n\
    \        std::vector<MessageInfo> m_messages;\n        std::vector<ScopedMessage>\
    \ m_messageScopes; /* Keeps owners of so-called unscoped messages. */\n      \
    \  AssertionInfo m_lastAssertionInfo;\n        std::vector<SectionEndInfo> m_unfinishedSections;\n\
    \        std::vector<ITracker*> m_activeSections;\n        TrackerContext m_trackerContext;\n\
    \        bool m_lastAssertionPassed = false;\n        bool m_shouldReportUnexpected\
    \ = true;\n        bool m_includeSuccessfulResults;\n    };\n\n    void seedRng(IConfig\
    \ const& config);\n    unsigned int rngSeed();\n} // end namespace Catch\n\n//\
    \ end catch_run_context.h\nnamespace Catch {\n\n    namespace {\n        auto\
    \ operator <<( std::ostream& os, ITransientExpression const& expr ) -> std::ostream&\
    \ {\n            expr.streamReconstructedExpression( os );\n            return\
    \ os;\n        }\n    }\n\n    LazyExpression::LazyExpression( bool isNegated\
    \ )\n    :   m_isNegated( isNegated )\n    {}\n\n    LazyExpression::LazyExpression(\
    \ LazyExpression const& other ) : m_isNegated( other.m_isNegated ) {}\n\n    LazyExpression::operator\
    \ bool() const {\n        return m_transientExpression != nullptr;\n    }\n\n\
    \    auto operator << ( std::ostream& os, LazyExpression const& lazyExpr ) ->\
    \ std::ostream& {\n        if( lazyExpr.m_isNegated )\n            os << \"!\"\
    ;\n\n        if( lazyExpr ) {\n            if( lazyExpr.m_isNegated && lazyExpr.m_transientExpression->isBinaryExpression()\
    \ )\n                os << \"(\" << *lazyExpr.m_transientExpression << \")\";\n\
    \            else\n                os << *lazyExpr.m_transientExpression;\n  \
    \      }\n        else {\n            os << \"{** error - unchecked empty expression\
    \ requested **}\";\n        }\n        return os;\n    }\n\n    AssertionHandler::AssertionHandler\n\
    \        (   StringRef const& macroName,\n            SourceLineInfo const& lineInfo,\n\
    \            StringRef capturedExpression,\n            ResultDisposition::Flags\
    \ resultDisposition )\n    :   m_assertionInfo{ macroName, lineInfo, capturedExpression,\
    \ resultDisposition },\n        m_resultCapture( getResultCapture() )\n    {}\n\
    \n    void AssertionHandler::handleExpr( ITransientExpression const& expr ) {\n\
    \        m_resultCapture.handleExpr( m_assertionInfo, expr, m_reaction );\n  \
    \  }\n    void AssertionHandler::handleMessage(ResultWas::OfType resultType, StringRef\
    \ const& message) {\n        m_resultCapture.handleMessage( m_assertionInfo, resultType,\
    \ message, m_reaction );\n    }\n\n    auto AssertionHandler::allowThrows() const\
    \ -> bool {\n        return getCurrentContext().getConfig()->allowThrows();\n\
    \    }\n\n    void AssertionHandler::complete() {\n        setCompleted();\n \
    \       if( m_reaction.shouldDebugBreak ) {\n\n            // If you find your\
    \ debugger stopping you here then go one level up on the\n            // call-stack\
    \ for the code that caused it (typically a failed assertion)\n\n            //\
    \ (To go back to the test and change execution, jump over the throw, next)\n \
    \           CATCH_BREAK_INTO_DEBUGGER();\n        }\n        if (m_reaction.shouldThrow)\
    \ {\n#if !defined(CATCH_CONFIG_DISABLE_EXCEPTIONS)\n            throw Catch::TestFailureException();\n\
    #else\n            CATCH_ERROR( \"Test failure requires aborting test!\" );\n\
    #endif\n        }\n    }\n    void AssertionHandler::setCompleted() {\n      \
    \  m_completed = true;\n    }\n\n    void AssertionHandler::handleUnexpectedInflightException()\
    \ {\n        m_resultCapture.handleUnexpectedInflightException( m_assertionInfo,\
    \ Catch::translateActiveException(), m_reaction );\n    }\n\n    void AssertionHandler::handleExceptionThrownAsExpected()\
    \ {\n        m_resultCapture.handleNonExpr(m_assertionInfo, ResultWas::Ok, m_reaction);\n\
    \    }\n    void AssertionHandler::handleExceptionNotThrownAsExpected() {\n  \
    \      m_resultCapture.handleNonExpr(m_assertionInfo, ResultWas::Ok, m_reaction);\n\
    \    }\n\n    void AssertionHandler::handleUnexpectedExceptionNotThrown() {\n\
    \        m_resultCapture.handleUnexpectedExceptionNotThrown( m_assertionInfo,\
    \ m_reaction );\n    }\n\n    void AssertionHandler::handleThrowingCallSkipped()\
    \ {\n        m_resultCapture.handleNonExpr(m_assertionInfo, ResultWas::Ok, m_reaction);\n\
    \    }\n\n    // This is the overload that takes a string and infers the Equals\
    \ matcher from it\n    // The more general overload, that takes any string matcher,\
    \ is in catch_capture_matchers.cpp\n    void handleExceptionMatchExpr( AssertionHandler&\
    \ handler, std::string const& str, StringRef const& matcherString  ) {\n     \
    \   handleExceptionMatchExpr( handler, Matchers::Equals( str ), matcherString\
    \ );\n    }\n\n} // namespace Catch\n// end catch_assertionhandler.cpp\n// start\
    \ catch_assertionresult.cpp\n\nnamespace Catch {\n    AssertionResultData::AssertionResultData(ResultWas::OfType\
    \ _resultType, LazyExpression const & _lazyExpression):\n        lazyExpression(_lazyExpression),\n\
    \        resultType(_resultType) {}\n\n    std::string AssertionResultData::reconstructExpression()\
    \ const {\n\n        if( reconstructedExpression.empty() ) {\n            if(\
    \ lazyExpression ) {\n                ReusableStringStream rss;\n            \
    \    rss << lazyExpression;\n                reconstructedExpression = rss.str();\n\
    \            }\n        }\n        return reconstructedExpression;\n    }\n\n\
    \    AssertionResult::AssertionResult( AssertionInfo const& info, AssertionResultData\
    \ const& data )\n    :   m_info( info ),\n        m_resultData( data )\n    {}\n\
    \n    // Result was a success\n    bool AssertionResult::succeeded() const {\n\
    \        return Catch::isOk( m_resultData.resultType );\n    }\n\n    // Result\
    \ was a success, or failure is suppressed\n    bool AssertionResult::isOk() const\
    \ {\n        return Catch::isOk( m_resultData.resultType ) || shouldSuppressFailure(\
    \ m_info.resultDisposition );\n    }\n\n    ResultWas::OfType AssertionResult::getResultType()\
    \ const {\n        return m_resultData.resultType;\n    }\n\n    bool AssertionResult::hasExpression()\
    \ const {\n        return !m_info.capturedExpression.empty();\n    }\n\n    bool\
    \ AssertionResult::hasMessage() const {\n        return !m_resultData.message.empty();\n\
    \    }\n\n    std::string AssertionResult::getExpression() const {\n        //\
    \ Possibly overallocating by 3 characters should be basically free\n        std::string\
    \ expr; expr.reserve(m_info.capturedExpression.size() + 3);\n        if (isFalseTest(m_info.resultDisposition))\
    \ {\n            expr += \"!(\";\n        }\n        expr += m_info.capturedExpression;\n\
    \        if (isFalseTest(m_info.resultDisposition)) {\n            expr += ')';\n\
    \        }\n        return expr;\n    }\n\n    std::string AssertionResult::getExpressionInMacro()\
    \ const {\n        std::string expr;\n        if( m_info.macroName.empty() )\n\
    \            expr = static_cast<std::string>(m_info.capturedExpression);\n   \
    \     else {\n            expr.reserve( m_info.macroName.size() + m_info.capturedExpression.size()\
    \ + 4 );\n            expr += m_info.macroName;\n            expr += \"( \";\n\
    \            expr += m_info.capturedExpression;\n            expr += \" )\";\n\
    \        }\n        return expr;\n    }\n\n    bool AssertionResult::hasExpandedExpression()\
    \ const {\n        return hasExpression() && getExpandedExpression() != getExpression();\n\
    \    }\n\n    std::string AssertionResult::getExpandedExpression() const {\n \
    \       std::string expr = m_resultData.reconstructExpression();\n        return\
    \ expr.empty()\n                ? getExpression()\n                : expr;\n \
    \   }\n\n    std::string AssertionResult::getMessage() const {\n        return\
    \ m_resultData.message;\n    }\n    SourceLineInfo AssertionResult::getSourceInfo()\
    \ const {\n        return m_info.lineInfo;\n    }\n\n    StringRef AssertionResult::getTestMacroName()\
    \ const {\n        return m_info.macroName;\n    }\n\n} // end namespace Catch\n\
    // end catch_assertionresult.cpp\n// start catch_capture_matchers.cpp\n\nnamespace\
    \ Catch {\n\n    using StringMatcher = Matchers::Impl::MatcherBase<std::string>;\n\
    \n    // This is the general overload that takes a any string matcher\n    //\
    \ There is another overload, in catch_assertionhandler.h/.cpp, that only takes\
    \ a string and infers\n    // the Equals matcher (so the header does not mention\
    \ matchers)\n    void handleExceptionMatchExpr( AssertionHandler& handler, StringMatcher\
    \ const& matcher, StringRef const& matcherString  ) {\n        std::string exceptionMessage\
    \ = Catch::translateActiveException();\n        MatchExpr<std::string, StringMatcher\
    \ const&> expr( exceptionMessage, matcher, matcherString );\n        handler.handleExpr(\
    \ expr );\n    }\n\n} // namespace Catch\n// end catch_capture_matchers.cpp\n\
    // start catch_commandline.cpp\n\n// start catch_commandline.h\n\n// start catch_clara.h\n\
    \n// Use Catch's value for console width (store Clara's off to the side, if present)\n\
    #ifdef CLARA_CONFIG_CONSOLE_WIDTH\n#define CATCH_TEMP_CLARA_CONFIG_CONSOLE_WIDTH\
    \ CATCH_CLARA_TEXTFLOW_CONFIG_CONSOLE_WIDTH\n#undef CATCH_CLARA_TEXTFLOW_CONFIG_CONSOLE_WIDTH\n\
    #endif\n#define CATCH_CLARA_TEXTFLOW_CONFIG_CONSOLE_WIDTH CATCH_CONFIG_CONSOLE_WIDTH-1\n\
    \n#ifdef __clang__\n#pragma clang diagnostic push\n#pragma clang diagnostic ignored\
    \ \"-Wweak-vtables\"\n#pragma clang diagnostic ignored \"-Wexit-time-destructors\"\
    \n#pragma clang diagnostic ignored \"-Wshadow\"\n#endif\n\n// start clara.hpp\n\
    // Copyright 2017 Two Blue Cubes Ltd. All rights reserved.\n//\n// Distributed\
    \ under the Boost Software License, Version 1.0. (See accompanying\n// file LICENSE_1_0.txt\
    \ or copy at http://www.boost.org/LICENSE_1_0.txt)\n//\n// See https://github.com/philsquared/Clara\
    \ for more details\n\n// Clara v1.1.5\n\n\n#ifndef CATCH_CLARA_CONFIG_CONSOLE_WIDTH\n\
    #define CATCH_CLARA_CONFIG_CONSOLE_WIDTH 80\n#endif\n\n#ifndef CATCH_CLARA_TEXTFLOW_CONFIG_CONSOLE_WIDTH\n\
    #define CATCH_CLARA_TEXTFLOW_CONFIG_CONSOLE_WIDTH CATCH_CLARA_CONFIG_CONSOLE_WIDTH\n\
    #endif\n\n#ifndef CLARA_CONFIG_OPTIONAL_TYPE\n#ifdef __has_include\n#if __has_include(<optional>)\
    \ && __cplusplus >= 201703L\n#include <optional>\n#define CLARA_CONFIG_OPTIONAL_TYPE\
    \ std::optional\n#endif\n#endif\n#endif\n\n// ----------- #included from clara_textflow.hpp\
    \ -----------\n\n// TextFlowCpp\n//\n// A single-header library for wrapping and\
    \ laying out basic text, by Phil Nash\n//\n// Distributed under the Boost Software\
    \ License, Version 1.0. (See accompanying\n// file LICENSE.txt or copy at http://www.boost.org/LICENSE_1_0.txt)\n\
    //\n// This project is hosted at https://github.com/philsquared/textflowcpp\n\n\
    \n#include <cassert>\n#include <ostream>\n#include <sstream>\n#include <vector>\n\
    \n#ifndef CATCH_CLARA_TEXTFLOW_CONFIG_CONSOLE_WIDTH\n#define CATCH_CLARA_TEXTFLOW_CONFIG_CONSOLE_WIDTH\
    \ 80\n#endif\n\nnamespace Catch {\nnamespace clara {\nnamespace TextFlow {\n\n\
    inline auto isWhitespace(char c) -> bool {\n\tstatic std::string chars = \" \\\
    t\\n\\r\";\n\treturn chars.find(c) != std::string::npos;\n}\ninline auto isBreakableBefore(char\
    \ c) -> bool {\n\tstatic std::string chars = \"[({<|\";\n\treturn chars.find(c)\
    \ != std::string::npos;\n}\ninline auto isBreakableAfter(char c) -> bool {\n\t\
    static std::string chars = \"])}>.,:;*+-=&/\\\\\";\n\treturn chars.find(c) !=\
    \ std::string::npos;\n}\n\nclass Columns;\n\nclass Column {\n\tstd::vector<std::string>\
    \ m_strings;\n\tsize_t m_width = CATCH_CLARA_TEXTFLOW_CONFIG_CONSOLE_WIDTH;\n\t\
    size_t m_indent = 0;\n\tsize_t m_initialIndent = std::string::npos;\n\npublic:\n\
    \tclass iterator {\n\t\tfriend Column;\n\n\t\tColumn const& m_column;\n\t\tsize_t\
    \ m_stringIndex = 0;\n\t\tsize_t m_pos = 0;\n\n\t\tsize_t m_len = 0;\n\t\tsize_t\
    \ m_end = 0;\n\t\tbool m_suffix = false;\n\n\t\titerator(Column const& column,\
    \ size_t stringIndex)\n\t\t\t: m_column(column),\n\t\t\tm_stringIndex(stringIndex)\
    \ {}\n\n\t\tauto line() const -> std::string const& { return m_column.m_strings[m_stringIndex];\
    \ }\n\n\t\tauto isBoundary(size_t at) const -> bool {\n\t\t\tassert(at > 0);\n\
    \t\t\tassert(at <= line().size());\n\n\t\t\treturn at == line().size() ||\n\t\t\
    \t\t(isWhitespace(line()[at]) && !isWhitespace(line()[at - 1])) ||\n\t\t\t\tisBreakableBefore(line()[at])\
    \ ||\n\t\t\t\tisBreakableAfter(line()[at - 1]);\n\t\t}\n\n\t\tvoid calcLength()\
    \ {\n\t\t\tassert(m_stringIndex < m_column.m_strings.size());\n\n\t\t\tm_suffix\
    \ = false;\n\t\t\tauto width = m_column.m_width - indent();\n\t\t\tm_end = m_pos;\n\
    \t\t\tif (line()[m_pos] == '\\n') {\n\t\t\t\t++m_end;\n\t\t\t}\n\t\t\twhile (m_end\
    \ < line().size() && line()[m_end] != '\\n')\n\t\t\t\t++m_end;\n\n\t\t\tif (m_end\
    \ < m_pos + width) {\n\t\t\t\tm_len = m_end - m_pos;\n\t\t\t} else {\n\t\t\t\t\
    size_t len = width;\n\t\t\t\twhile (len > 0 && !isBoundary(m_pos + len))\n\t\t\
    \t\t\t--len;\n\t\t\t\twhile (len > 0 && isWhitespace(line()[m_pos + len - 1]))\n\
    \t\t\t\t\t--len;\n\n\t\t\t\tif (len > 0) {\n\t\t\t\t\tm_len = len;\n\t\t\t\t}\
    \ else {\n\t\t\t\t\tm_suffix = true;\n\t\t\t\t\tm_len = width - 1;\n\t\t\t\t}\n\
    \t\t\t}\n\t\t}\n\n\t\tauto indent() const -> size_t {\n\t\t\tauto initial = m_pos\
    \ == 0 && m_stringIndex == 0 ? m_column.m_initialIndent : std::string::npos;\n\
    \t\t\treturn initial == std::string::npos ? m_column.m_indent : initial;\n\t\t\
    }\n\n\t\tauto addIndentAndSuffix(std::string const &plain) const -> std::string\
    \ {\n\t\t\treturn std::string(indent(), ' ') + (m_suffix ? plain + \"-\" : plain);\n\
    \t\t}\n\n\tpublic:\n\t\tusing difference_type = std::ptrdiff_t;\n\t\tusing value_type\
    \ = std::string;\n\t\tusing pointer = value_type * ;\n\t\tusing reference = value_type\
    \ & ;\n\t\tusing iterator_category = std::forward_iterator_tag;\n\n\t\texplicit\
    \ iterator(Column const& column) : m_column(column) {\n\t\t\tassert(m_column.m_width\
    \ > m_column.m_indent);\n\t\t\tassert(m_column.m_initialIndent == std::string::npos\
    \ || m_column.m_width > m_column.m_initialIndent);\n\t\t\tcalcLength();\n\t\t\t\
    if (m_len == 0)\n\t\t\t\tm_stringIndex++; // Empty string\n\t\t}\n\n\t\tauto operator\
    \ *() const -> std::string {\n\t\t\tassert(m_stringIndex < m_column.m_strings.size());\n\
    \t\t\tassert(m_pos <= m_end);\n\t\t\treturn addIndentAndSuffix(line().substr(m_pos,\
    \ m_len));\n\t\t}\n\n\t\tauto operator ++() -> iterator& {\n\t\t\tm_pos += m_len;\n\
    \t\t\tif (m_pos < line().size() && line()[m_pos] == '\\n')\n\t\t\t\tm_pos += 1;\n\
    \t\t\telse\n\t\t\t\twhile (m_pos < line().size() && isWhitespace(line()[m_pos]))\n\
    \t\t\t\t\t++m_pos;\n\n\t\t\tif (m_pos == line().size()) {\n\t\t\t\tm_pos = 0;\n\
    \t\t\t\t++m_stringIndex;\n\t\t\t}\n\t\t\tif (m_stringIndex < m_column.m_strings.size())\n\
    \t\t\t\tcalcLength();\n\t\t\treturn *this;\n\t\t}\n\t\tauto operator ++(int) ->\
    \ iterator {\n\t\t\titerator prev(*this);\n\t\t\toperator++();\n\t\t\treturn prev;\n\
    \t\t}\n\n\t\tauto operator ==(iterator const& other) const -> bool {\n\t\t\treturn\n\
    \t\t\t\tm_pos == other.m_pos &&\n\t\t\t\tm_stringIndex == other.m_stringIndex\
    \ &&\n\t\t\t\t&m_column == &other.m_column;\n\t\t}\n\t\tauto operator !=(iterator\
    \ const& other) const -> bool {\n\t\t\treturn !operator==(other);\n\t\t}\n\t};\n\
    \tusing const_iterator = iterator;\n\n\texplicit Column(std::string const& text)\
    \ { m_strings.push_back(text); }\n\n\tauto width(size_t newWidth) -> Column& {\n\
    \t\tassert(newWidth > 0);\n\t\tm_width = newWidth;\n\t\treturn *this;\n\t}\n\t\
    auto indent(size_t newIndent) -> Column& {\n\t\tm_indent = newIndent;\n\t\treturn\
    \ *this;\n\t}\n\tauto initialIndent(size_t newIndent) -> Column& {\n\t\tm_initialIndent\
    \ = newIndent;\n\t\treturn *this;\n\t}\n\n\tauto width() const -> size_t { return\
    \ m_width; }\n\tauto begin() const -> iterator { return iterator(*this); }\n\t\
    auto end() const -> iterator { return { *this, m_strings.size() }; }\n\n\tinline\
    \ friend std::ostream& operator << (std::ostream& os, Column const& col) {\n\t\
    \tbool first = true;\n\t\tfor (auto line : col) {\n\t\t\tif (first)\n\t\t\t\t\
    first = false;\n\t\t\telse\n\t\t\t\tos << \"\\n\";\n\t\t\tos << line;\n\t\t}\n\
    \t\treturn os;\n\t}\n\n\tauto operator + (Column const& other)->Columns;\n\n\t\
    auto toString() const -> std::string {\n\t\tstd::ostringstream oss;\n\t\toss <<\
    \ *this;\n\t\treturn oss.str();\n\t}\n};\n\nclass Spacer : public Column {\n\n\
    public:\n\texplicit Spacer(size_t spaceWidth) : Column(\"\") {\n\t\twidth(spaceWidth);\n\
    \t}\n};\n\nclass Columns {\n\tstd::vector<Column> m_columns;\n\npublic:\n\n\t\
    class iterator {\n\t\tfriend Columns;\n\t\tstruct EndTag {};\n\n\t\tstd::vector<Column>\
    \ const& m_columns;\n\t\tstd::vector<Column::iterator> m_iterators;\n\t\tsize_t\
    \ m_activeIterators;\n\n\t\titerator(Columns const& columns, EndTag)\n\t\t\t:\
    \ m_columns(columns.m_columns),\n\t\t\tm_activeIterators(0) {\n\t\t\tm_iterators.reserve(m_columns.size());\n\
    \n\t\t\tfor (auto const& col : m_columns)\n\t\t\t\tm_iterators.push_back(col.end());\n\
    \t\t}\n\n\tpublic:\n\t\tusing difference_type = std::ptrdiff_t;\n\t\tusing value_type\
    \ = std::string;\n\t\tusing pointer = value_type * ;\n\t\tusing reference = value_type\
    \ & ;\n\t\tusing iterator_category = std::forward_iterator_tag;\n\n\t\texplicit\
    \ iterator(Columns const& columns)\n\t\t\t: m_columns(columns.m_columns),\n\t\t\
    \tm_activeIterators(m_columns.size()) {\n\t\t\tm_iterators.reserve(m_columns.size());\n\
    \n\t\t\tfor (auto const& col : m_columns)\n\t\t\t\tm_iterators.push_back(col.begin());\n\
    \t\t}\n\n\t\tauto operator ==(iterator const& other) const -> bool {\n\t\t\treturn\
    \ m_iterators == other.m_iterators;\n\t\t}\n\t\tauto operator !=(iterator const&\
    \ other) const -> bool {\n\t\t\treturn m_iterators != other.m_iterators;\n\t\t\
    }\n\t\tauto operator *() const -> std::string {\n\t\t\tstd::string row, padding;\n\
    \n\t\t\tfor (size_t i = 0; i < m_columns.size(); ++i) {\n\t\t\t\tauto width =\
    \ m_columns[i].width();\n\t\t\t\tif (m_iterators[i] != m_columns[i].end()) {\n\
    \t\t\t\t\tstd::string col = *m_iterators[i];\n\t\t\t\t\trow += padding + col;\n\
    \t\t\t\t\tif (col.size() < width)\n\t\t\t\t\t\tpadding = std::string(width - col.size(),\
    \ ' ');\n\t\t\t\t\telse\n\t\t\t\t\t\tpadding = \"\";\n\t\t\t\t} else {\n\t\t\t\
    \t\tpadding += std::string(width, ' ');\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn row;\n\
    \t\t}\n\t\tauto operator ++() -> iterator& {\n\t\t\tfor (size_t i = 0; i < m_columns.size();\
    \ ++i) {\n\t\t\t\tif (m_iterators[i] != m_columns[i].end())\n\t\t\t\t\t++m_iterators[i];\n\
    \t\t\t}\n\t\t\treturn *this;\n\t\t}\n\t\tauto operator ++(int) -> iterator {\n\
    \t\t\titerator prev(*this);\n\t\t\toperator++();\n\t\t\treturn prev;\n\t\t}\n\t\
    };\n\tusing const_iterator = iterator;\n\n\tauto begin() const -> iterator { return\
    \ iterator(*this); }\n\tauto end() const -> iterator { return { *this, iterator::EndTag()\
    \ }; }\n\n\tauto operator += (Column const& col) -> Columns& {\n\t\tm_columns.push_back(col);\n\
    \t\treturn *this;\n\t}\n\tauto operator + (Column const& col) -> Columns {\n\t\
    \tColumns combined = *this;\n\t\tcombined += col;\n\t\treturn combined;\n\t}\n\
    \n\tinline friend std::ostream& operator << (std::ostream& os, Columns const&\
    \ cols) {\n\n\t\tbool first = true;\n\t\tfor (auto line : cols) {\n\t\t\tif (first)\n\
    \t\t\t\tfirst = false;\n\t\t\telse\n\t\t\t\tos << \"\\n\";\n\t\t\tos << line;\n\
    \t\t}\n\t\treturn os;\n\t}\n\n\tauto toString() const -> std::string {\n\t\tstd::ostringstream\
    \ oss;\n\t\toss << *this;\n\t\treturn oss.str();\n\t}\n};\n\ninline auto Column::operator\
    \ + (Column const& other) -> Columns {\n\tColumns cols;\n\tcols += *this;\n\t\
    cols += other;\n\treturn cols;\n}\n}\n\n}\n}\n\n// ----------- end of #include\
    \ from clara_textflow.hpp -----------\n// ........... back in clara.hpp\n\n#include\
    \ <cctype>\n#include <string>\n#include <memory>\n#include <set>\n#include <algorithm>\n\
    \n#if !defined(CATCH_PLATFORM_WINDOWS) && ( defined(WIN32) || defined(__WIN32__)\
    \ || defined(_WIN32) || defined(_MSC_VER) )\n#define CATCH_PLATFORM_WINDOWS\n\
    #endif\n\nnamespace Catch { namespace clara {\nnamespace detail {\n\n    // Traits\
    \ for extracting arg and return type of lambdas (for single argument lambdas)\n\
    \    template<typename L>\n    struct UnaryLambdaTraits : UnaryLambdaTraits<decltype(\
    \ &L::operator() )> {};\n\n    template<typename ClassT, typename ReturnT, typename...\
    \ Args>\n    struct UnaryLambdaTraits<ReturnT( ClassT::* )( Args... ) const> {\n\
    \        static const bool isValid = false;\n    };\n\n    template<typename ClassT,\
    \ typename ReturnT, typename ArgT>\n    struct UnaryLambdaTraits<ReturnT( ClassT::*\
    \ )( ArgT ) const> {\n        static const bool isValid = true;\n        using\
    \ ArgType = typename std::remove_const<typename std::remove_reference<ArgT>::type>::type;\n\
    \        using ReturnType = ReturnT;\n    };\n\n    class TokenStream;\n\n   \
    \ // Transport for raw args (copied from main args, or supplied via init list\
    \ for testing)\n    class Args {\n        friend TokenStream;\n        std::string\
    \ m_exeName;\n        std::vector<std::string> m_args;\n\n    public:\n      \
    \  Args( int argc, char const* const* argv )\n            : m_exeName(argv[0]),\n\
    \              m_args(argv + 1, argv + argc) {}\n\n        Args( std::initializer_list<std::string>\
    \ args )\n        :   m_exeName( *args.begin() ),\n            m_args( args.begin()+1,\
    \ args.end() )\n        {}\n\n        auto exeName() const -> std::string {\n\
    \            return m_exeName;\n        }\n    };\n\n    // Wraps a token coming\
    \ from a token stream. These may not directly correspond to strings as a single\
    \ string\n    // may encode an option + its argument if the : or = form is used\n\
    \    enum class TokenType {\n        Option, Argument\n    };\n    struct Token\
    \ {\n        TokenType type;\n        std::string token;\n    };\n\n    inline\
    \ auto isOptPrefix( char c ) -> bool {\n        return c == '-'\n#ifdef CATCH_PLATFORM_WINDOWS\n\
    \            || c == '/'\n#endif\n        ;\n    }\n\n    // Abstracts iterators\
    \ into args as a stream of tokens, with option arguments uniformly handled\n \
    \   class TokenStream {\n        using Iterator = std::vector<std::string>::const_iterator;\n\
    \        Iterator it;\n        Iterator itEnd;\n        std::vector<Token> m_tokenBuffer;\n\
    \n        void loadBuffer() {\n            m_tokenBuffer.resize( 0 );\n\n    \
    \        // Skip any empty strings\n            while( it != itEnd && it->empty()\
    \ )\n                ++it;\n\n            if( it != itEnd ) {\n              \
    \  auto const &next = *it;\n                if( isOptPrefix( next[0] ) ) {\n \
    \                   auto delimiterPos = next.find_first_of( \" :=\" );\n     \
    \               if( delimiterPos != std::string::npos ) {\n                  \
    \      m_tokenBuffer.push_back( { TokenType::Option, next.substr( 0, delimiterPos\
    \ ) } );\n                        m_tokenBuffer.push_back( { TokenType::Argument,\
    \ next.substr( delimiterPos + 1 ) } );\n                    } else {\n       \
    \                 if( next[1] != '-' && next.size() > 2 ) {\n                \
    \            std::string opt = \"- \";\n                            for( size_t\
    \ i = 1; i < next.size(); ++i ) {\n                                opt[1] = next[i];\n\
    \                                m_tokenBuffer.push_back( { TokenType::Option,\
    \ opt } );\n                            }\n                        } else {\n\
    \                            m_tokenBuffer.push_back( { TokenType::Option, next\
    \ } );\n                        }\n                    }\n                } else\
    \ {\n                    m_tokenBuffer.push_back( { TokenType::Argument, next\
    \ } );\n                }\n            }\n        }\n\n    public:\n        explicit\
    \ TokenStream( Args const &args ) : TokenStream( args.m_args.begin(), args.m_args.end()\
    \ ) {}\n\n        TokenStream( Iterator it, Iterator itEnd ) : it( it ), itEnd(\
    \ itEnd ) {\n            loadBuffer();\n        }\n\n        explicit operator\
    \ bool() const {\n            return !m_tokenBuffer.empty() || it != itEnd;\n\
    \        }\n\n        auto count() const -> size_t { return m_tokenBuffer.size()\
    \ + (itEnd - it); }\n\n        auto operator*() const -> Token {\n           \
    \ assert( !m_tokenBuffer.empty() );\n            return m_tokenBuffer.front();\n\
    \        }\n\n        auto operator->() const -> Token const * {\n           \
    \ assert( !m_tokenBuffer.empty() );\n            return &m_tokenBuffer.front();\n\
    \        }\n\n        auto operator++() -> TokenStream & {\n            if( m_tokenBuffer.size()\
    \ >= 2 ) {\n                m_tokenBuffer.erase( m_tokenBuffer.begin() );\n  \
    \          } else {\n                if( it != itEnd )\n                    ++it;\n\
    \                loadBuffer();\n            }\n            return *this;\n   \
    \     }\n    };\n\n    class ResultBase {\n    public:\n        enum Type {\n\
    \            Ok, LogicError, RuntimeError\n        };\n\n    protected:\n    \
    \    ResultBase( Type type ) : m_type( type ) {}\n        virtual ~ResultBase()\
    \ = default;\n\n        virtual void enforceOk() const = 0;\n\n        Type m_type;\n\
    \    };\n\n    template<typename T>\n    class ResultValueBase : public ResultBase\
    \ {\n    public:\n        auto value() const -> T const & {\n            enforceOk();\n\
    \            return m_value;\n        }\n\n    protected:\n        ResultValueBase(\
    \ Type type ) : ResultBase( type ) {}\n\n        ResultValueBase( ResultValueBase\
    \ const &other ) : ResultBase( other ) {\n            if( m_type == ResultBase::Ok\
    \ )\n                new( &m_value ) T( other.m_value );\n        }\n\n      \
    \  ResultValueBase( Type, T const &value ) : ResultBase( Ok ) {\n            new(\
    \ &m_value ) T( value );\n        }\n\n        auto operator=( ResultValueBase\
    \ const &other ) -> ResultValueBase & {\n            if( m_type == ResultBase::Ok\
    \ )\n                m_value.~T();\n            ResultBase::operator=(other);\n\
    \            if( m_type == ResultBase::Ok )\n                new( &m_value ) T(\
    \ other.m_value );\n            return *this;\n        }\n\n        ~ResultValueBase()\
    \ override {\n            if( m_type == Ok )\n                m_value.~T();\n\
    \        }\n\n        union {\n            T m_value;\n        };\n    };\n\n\
    \    template<>\n    class ResultValueBase<void> : public ResultBase {\n    protected:\n\
    \        using ResultBase::ResultBase;\n    };\n\n    template<typename T = void>\n\
    \    class BasicResult : public ResultValueBase<T> {\n    public:\n        template<typename\
    \ U>\n        explicit BasicResult( BasicResult<U> const &other )\n        : \
    \  ResultValueBase<T>( other.type() ),\n            m_errorMessage( other.errorMessage()\
    \ )\n        {\n            assert( type() != ResultBase::Ok );\n        }\n\n\
    \        template<typename U>\n        static auto ok( U const &value ) -> BasicResult\
    \ { return { ResultBase::Ok, value }; }\n        static auto ok() -> BasicResult\
    \ { return { ResultBase::Ok }; }\n        static auto logicError( std::string\
    \ const &message ) -> BasicResult { return { ResultBase::LogicError, message };\
    \ }\n        static auto runtimeError( std::string const &message ) -> BasicResult\
    \ { return { ResultBase::RuntimeError, message }; }\n\n        explicit operator\
    \ bool() const { return m_type == ResultBase::Ok; }\n        auto type() const\
    \ -> ResultBase::Type { return m_type; }\n        auto errorMessage() const ->\
    \ std::string { return m_errorMessage; }\n\n    protected:\n        void enforceOk()\
    \ const override {\n\n            // Errors shouldn't reach this point, but if\
    \ they do\n            // the actual error message will be in m_errorMessage\n\
    \            assert( m_type != ResultBase::LogicError );\n            assert(\
    \ m_type != ResultBase::RuntimeError );\n            if( m_type != ResultBase::Ok\
    \ )\n                std::abort();\n        }\n\n        std::string m_errorMessage;\
    \ // Only populated if resultType is an error\n\n        BasicResult( ResultBase::Type\
    \ type, std::string const &message )\n        :   ResultValueBase<T>(type),\n\
    \            m_errorMessage(message)\n        {\n            assert( m_type !=\
    \ ResultBase::Ok );\n        }\n\n        using ResultValueBase<T>::ResultValueBase;\n\
    \        using ResultBase::m_type;\n    };\n\n    enum class ParseResultType {\n\
    \        Matched, NoMatch, ShortCircuitAll, ShortCircuitSame\n    };\n\n    class\
    \ ParseState {\n    public:\n\n        ParseState( ParseResultType type, TokenStream\
    \ const &remainingTokens )\n        : m_type(type),\n          m_remainingTokens(\
    \ remainingTokens )\n        {}\n\n        auto type() const -> ParseResultType\
    \ { return m_type; }\n        auto remainingTokens() const -> TokenStream { return\
    \ m_remainingTokens; }\n\n    private:\n        ParseResultType m_type;\n    \
    \    TokenStream m_remainingTokens;\n    };\n\n    using Result = BasicResult<void>;\n\
    \    using ParserResult = BasicResult<ParseResultType>;\n    using InternalParseResult\
    \ = BasicResult<ParseState>;\n\n    struct HelpColumns {\n        std::string\
    \ left;\n        std::string right;\n    };\n\n    template<typename T>\n    inline\
    \ auto convertInto( std::string const &source, T& target ) -> ParserResult {\n\
    \        std::stringstream ss;\n        ss << source;\n        ss >> target;\n\
    \        if( ss.fail() )\n            return ParserResult::runtimeError( \"Unable\
    \ to convert '\" + source + \"' to destination type\" );\n        else\n     \
    \       return ParserResult::ok( ParseResultType::Matched );\n    }\n    inline\
    \ auto convertInto( std::string const &source, std::string& target ) -> ParserResult\
    \ {\n        target = source;\n        return ParserResult::ok( ParseResultType::Matched\
    \ );\n    }\n    inline auto convertInto( std::string const &source, bool &target\
    \ ) -> ParserResult {\n        std::string srcLC = source;\n        std::transform(\
    \ srcLC.begin(), srcLC.end(), srcLC.begin(), []( unsigned char c ) { return static_cast<char>(\
    \ std::tolower(c) ); } );\n        if (srcLC == \"y\" || srcLC == \"1\" || srcLC\
    \ == \"true\" || srcLC == \"yes\" || srcLC == \"on\")\n            target = true;\n\
    \        else if (srcLC == \"n\" || srcLC == \"0\" || srcLC == \"false\" || srcLC\
    \ == \"no\" || srcLC == \"off\")\n            target = false;\n        else\n\
    \            return ParserResult::runtimeError( \"Expected a boolean value but\
    \ did not recognise: '\" + source + \"'\" );\n        return ParserResult::ok(\
    \ ParseResultType::Matched );\n    }\n#ifdef CLARA_CONFIG_OPTIONAL_TYPE\n    template<typename\
    \ T>\n    inline auto convertInto( std::string const &source, CLARA_CONFIG_OPTIONAL_TYPE<T>&\
    \ target ) -> ParserResult {\n        T temp;\n        auto result = convertInto(\
    \ source, temp );\n        if( result )\n            target = std::move(temp);\n\
    \        return result;\n    }\n#endif // CLARA_CONFIG_OPTIONAL_TYPE\n\n    struct\
    \ NonCopyable {\n        NonCopyable() = default;\n        NonCopyable( NonCopyable\
    \ const & ) = delete;\n        NonCopyable( NonCopyable && ) = delete;\n     \
    \   NonCopyable &operator=( NonCopyable const & ) = delete;\n        NonCopyable\
    \ &operator=( NonCopyable && ) = delete;\n    };\n\n    struct BoundRef : NonCopyable\
    \ {\n        virtual ~BoundRef() = default;\n        virtual auto isContainer()\
    \ const -> bool { return false; }\n        virtual auto isFlag() const -> bool\
    \ { return false; }\n    };\n    struct BoundValueRefBase : BoundRef {\n     \
    \   virtual auto setValue( std::string const &arg ) -> ParserResult = 0;\n   \
    \ };\n    struct BoundFlagRefBase : BoundRef {\n        virtual auto setFlag(\
    \ bool flag ) -> ParserResult = 0;\n        virtual auto isFlag() const -> bool\
    \ { return true; }\n    };\n\n    template<typename T>\n    struct BoundValueRef\
    \ : BoundValueRefBase {\n        T &m_ref;\n\n        explicit BoundValueRef(\
    \ T &ref ) : m_ref( ref ) {}\n\n        auto setValue( std::string const &arg\
    \ ) -> ParserResult override {\n            return convertInto( arg, m_ref );\n\
    \        }\n    };\n\n    template<typename T>\n    struct BoundValueRef<std::vector<T>>\
    \ : BoundValueRefBase {\n        std::vector<T> &m_ref;\n\n        explicit BoundValueRef(\
    \ std::vector<T> &ref ) : m_ref( ref ) {}\n\n        auto isContainer() const\
    \ -> bool override { return true; }\n\n        auto setValue( std::string const\
    \ &arg ) -> ParserResult override {\n            T temp;\n            auto result\
    \ = convertInto( arg, temp );\n            if( result )\n                m_ref.push_back(\
    \ temp );\n            return result;\n        }\n    };\n\n    struct BoundFlagRef\
    \ : BoundFlagRefBase {\n        bool &m_ref;\n\n        explicit BoundFlagRef(\
    \ bool &ref ) : m_ref( ref ) {}\n\n        auto setFlag( bool flag ) -> ParserResult\
    \ override {\n            m_ref = flag;\n            return ParserResult::ok(\
    \ ParseResultType::Matched );\n        }\n    };\n\n    template<typename ReturnType>\n\
    \    struct LambdaInvoker {\n        static_assert( std::is_same<ReturnType, ParserResult>::value,\
    \ \"Lambda must return void or clara::ParserResult\" );\n\n        template<typename\
    \ L, typename ArgType>\n        static auto invoke( L const &lambda, ArgType const\
    \ &arg ) -> ParserResult {\n            return lambda( arg );\n        }\n   \
    \ };\n\n    template<>\n    struct LambdaInvoker<void> {\n        template<typename\
    \ L, typename ArgType>\n        static auto invoke( L const &lambda, ArgType const\
    \ &arg ) -> ParserResult {\n            lambda( arg );\n            return ParserResult::ok(\
    \ ParseResultType::Matched );\n        }\n    };\n\n    template<typename ArgType,\
    \ typename L>\n    inline auto invokeLambda( L const &lambda, std::string const\
    \ &arg ) -> ParserResult {\n        ArgType temp{};\n        auto result = convertInto(\
    \ arg, temp );\n        return !result\n           ? result\n           : LambdaInvoker<typename\
    \ UnaryLambdaTraits<L>::ReturnType>::invoke( lambda, temp );\n    }\n\n    template<typename\
    \ L>\n    struct BoundLambda : BoundValueRefBase {\n        L m_lambda;\n\n  \
    \      static_assert( UnaryLambdaTraits<L>::isValid, \"Supplied lambda must take\
    \ exactly one argument\" );\n        explicit BoundLambda( L const &lambda ) :\
    \ m_lambda( lambda ) {}\n\n        auto setValue( std::string const &arg ) ->\
    \ ParserResult override {\n            return invokeLambda<typename UnaryLambdaTraits<L>::ArgType>(\
    \ m_lambda, arg );\n        }\n    };\n\n    template<typename L>\n    struct\
    \ BoundFlagLambda : BoundFlagRefBase {\n        L m_lambda;\n\n        static_assert(\
    \ UnaryLambdaTraits<L>::isValid, \"Supplied lambda must take exactly one argument\"\
    \ );\n        static_assert( std::is_same<typename UnaryLambdaTraits<L>::ArgType,\
    \ bool>::value, \"flags must be boolean\" );\n\n        explicit BoundFlagLambda(\
    \ L const &lambda ) : m_lambda( lambda ) {}\n\n        auto setFlag( bool flag\
    \ ) -> ParserResult override {\n            return LambdaInvoker<typename UnaryLambdaTraits<L>::ReturnType>::invoke(\
    \ m_lambda, flag );\n        }\n    };\n\n    enum class Optionality { Optional,\
    \ Required };\n\n    struct Parser;\n\n    class ParserBase {\n    public:\n \
    \       virtual ~ParserBase() = default;\n        virtual auto validate() const\
    \ -> Result { return Result::ok(); }\n        virtual auto parse( std::string\
    \ const& exeName, TokenStream const &tokens) const -> InternalParseResult  = 0;\n\
    \        virtual auto cardinality() const -> size_t { return 1; }\n\n        auto\
    \ parse( Args const &args ) const -> InternalParseResult {\n            return\
    \ parse( args.exeName(), TokenStream( args ) );\n        }\n    };\n\n    template<typename\
    \ DerivedT>\n    class ComposableParserImpl : public ParserBase {\n    public:\n\
    \        template<typename T>\n        auto operator|( T const &other ) const\
    \ -> Parser;\n\n\t\ttemplate<typename T>\n        auto operator+( T const &other\
    \ ) const -> Parser;\n    };\n\n    // Common code and state for Args and Opts\n\
    \    template<typename DerivedT>\n    class ParserRefImpl : public ComposableParserImpl<DerivedT>\
    \ {\n    protected:\n        Optionality m_optionality = Optionality::Optional;\n\
    \        std::shared_ptr<BoundRef> m_ref;\n        std::string m_hint;\n     \
    \   std::string m_description;\n\n        explicit ParserRefImpl( std::shared_ptr<BoundRef>\
    \ const &ref ) : m_ref( ref ) {}\n\n    public:\n        template<typename T>\n\
    \        ParserRefImpl( T &ref, std::string const &hint )\n        :   m_ref(\
    \ std::make_shared<BoundValueRef<T>>( ref ) ),\n            m_hint( hint )\n \
    \       {}\n\n        template<typename LambdaT>\n        ParserRefImpl( LambdaT\
    \ const &ref, std::string const &hint )\n        :   m_ref( std::make_shared<BoundLambda<LambdaT>>(\
    \ ref ) ),\n            m_hint(hint)\n        {}\n\n        auto operator()( std::string\
    \ const &description ) -> DerivedT & {\n            m_description = description;\n\
    \            return static_cast<DerivedT &>( *this );\n        }\n\n        auto\
    \ optional() -> DerivedT & {\n            m_optionality = Optionality::Optional;\n\
    \            return static_cast<DerivedT &>( *this );\n        };\n\n        auto\
    \ required() -> DerivedT & {\n            m_optionality = Optionality::Required;\n\
    \            return static_cast<DerivedT &>( *this );\n        };\n\n        auto\
    \ isOptional() const -> bool {\n            return m_optionality == Optionality::Optional;\n\
    \        }\n\n        auto cardinality() const -> size_t override {\n        \
    \    if( m_ref->isContainer() )\n                return 0;\n            else\n\
    \                return 1;\n        }\n\n        auto hint() const -> std::string\
    \ { return m_hint; }\n    };\n\n    class ExeName : public ComposableParserImpl<ExeName>\
    \ {\n        std::shared_ptr<std::string> m_name;\n        std::shared_ptr<BoundValueRefBase>\
    \ m_ref;\n\n        template<typename LambdaT>\n        static auto makeRef(LambdaT\
    \ const &lambda) -> std::shared_ptr<BoundValueRefBase> {\n            return std::make_shared<BoundLambda<LambdaT>>(\
    \ lambda) ;\n        }\n\n    public:\n        ExeName() : m_name( std::make_shared<std::string>(\
    \ \"<executable>\" ) ) {}\n\n        explicit ExeName( std::string &ref ) : ExeName()\
    \ {\n            m_ref = std::make_shared<BoundValueRef<std::string>>( ref );\n\
    \        }\n\n        template<typename LambdaT>\n        explicit ExeName( LambdaT\
    \ const& lambda ) : ExeName() {\n            m_ref = std::make_shared<BoundLambda<LambdaT>>(\
    \ lambda );\n        }\n\n        // The exe name is not parsed out of the normal\
    \ tokens, but is handled specially\n        auto parse( std::string const&, TokenStream\
    \ const &tokens ) const -> InternalParseResult override {\n            return\
    \ InternalParseResult::ok( ParseState( ParseResultType::NoMatch, tokens ) );\n\
    \        }\n\n        auto name() const -> std::string { return *m_name; }\n \
    \       auto set( std::string const& newName ) -> ParserResult {\n\n         \
    \   auto lastSlash = newName.find_last_of( \"\\\\/\" );\n            auto filename\
    \ = ( lastSlash == std::string::npos )\n                    ? newName\n      \
    \              : newName.substr( lastSlash+1 );\n\n            *m_name = filename;\n\
    \            if( m_ref )\n                return m_ref->setValue( filename );\n\
    \            else\n                return ParserResult::ok( ParseResultType::Matched\
    \ );\n        }\n    };\n\n    class Arg : public ParserRefImpl<Arg> {\n    public:\n\
    \        using ParserRefImpl::ParserRefImpl;\n\n        auto parse( std::string\
    \ const &, TokenStream const &tokens ) const -> InternalParseResult override {\n\
    \            auto validationResult = validate();\n            if( !validationResult\
    \ )\n                return InternalParseResult( validationResult );\n\n     \
    \       auto remainingTokens = tokens;\n            auto const &token = *remainingTokens;\n\
    \            if( token.type != TokenType::Argument )\n                return InternalParseResult::ok(\
    \ ParseState( ParseResultType::NoMatch, remainingTokens ) );\n\n            assert(\
    \ !m_ref->isFlag() );\n            auto valueRef = static_cast<detail::BoundValueRefBase*>(\
    \ m_ref.get() );\n\n            auto result = valueRef->setValue( remainingTokens->token\
    \ );\n            if( !result )\n                return InternalParseResult( result\
    \ );\n            else\n                return InternalParseResult::ok( ParseState(\
    \ ParseResultType::Matched, ++remainingTokens ) );\n        }\n    };\n\n    inline\
    \ auto normaliseOpt( std::string const &optName ) -> std::string {\n#ifdef CATCH_PLATFORM_WINDOWS\n\
    \        if( optName[0] == '/' )\n            return \"-\" + optName.substr( 1\
    \ );\n        else\n#endif\n            return optName;\n    }\n\n    class Opt\
    \ : public ParserRefImpl<Opt> {\n    protected:\n        std::vector<std::string>\
    \ m_optNames;\n\n    public:\n        template<typename LambdaT>\n        explicit\
    \ Opt( LambdaT const &ref ) : ParserRefImpl( std::make_shared<BoundFlagLambda<LambdaT>>(\
    \ ref ) ) {}\n\n        explicit Opt( bool &ref ) : ParserRefImpl( std::make_shared<BoundFlagRef>(\
    \ ref ) ) {}\n\n        template<typename LambdaT>\n        Opt( LambdaT const\
    \ &ref, std::string const &hint ) : ParserRefImpl( ref, hint ) {}\n\n        template<typename\
    \ T>\n        Opt( T &ref, std::string const &hint ) : ParserRefImpl( ref, hint\
    \ ) {}\n\n        auto operator[]( std::string const &optName ) -> Opt & {\n \
    \           m_optNames.push_back( optName );\n            return *this;\n    \
    \    }\n\n        auto getHelpColumns() const -> std::vector<HelpColumns> {\n\
    \            std::ostringstream oss;\n            bool first = true;\n       \
    \     for( auto const &opt : m_optNames ) {\n                if (first)\n    \
    \                first = false;\n                else\n                    oss\
    \ << \", \";\n                oss << opt;\n            }\n            if( !m_hint.empty()\
    \ )\n                oss << \" <\" << m_hint << \">\";\n            return { {\
    \ oss.str(), m_description } };\n        }\n\n        auto isMatch( std::string\
    \ const &optToken ) const -> bool {\n            auto normalisedToken = normaliseOpt(\
    \ optToken );\n            for( auto const &name : m_optNames ) {\n          \
    \      if( normaliseOpt( name ) == normalisedToken )\n                    return\
    \ true;\n            }\n            return false;\n        }\n\n        using\
    \ ParserBase::parse;\n\n        auto parse( std::string const&, TokenStream const\
    \ &tokens ) const -> InternalParseResult override {\n            auto validationResult\
    \ = validate();\n            if( !validationResult )\n                return InternalParseResult(\
    \ validationResult );\n\n            auto remainingTokens = tokens;\n        \
    \    if( remainingTokens && remainingTokens->type == TokenType::Option ) {\n \
    \               auto const &token = *remainingTokens;\n                if( isMatch(token.token\
    \ ) ) {\n                    if( m_ref->isFlag() ) {\n                       \
    \ auto flagRef = static_cast<detail::BoundFlagRefBase*>( m_ref.get() );\n    \
    \                    auto result = flagRef->setFlag( true );\n               \
    \         if( !result )\n                            return InternalParseResult(\
    \ result );\n                        if( result.value() == ParseResultType::ShortCircuitAll\
    \ )\n                            return InternalParseResult::ok( ParseState( result.value(),\
    \ remainingTokens ) );\n                    } else {\n                       \
    \ auto valueRef = static_cast<detail::BoundValueRefBase*>( m_ref.get() );\n  \
    \                      ++remainingTokens;\n                        if( !remainingTokens\
    \ )\n                            return InternalParseResult::runtimeError( \"\
    Expected argument following \" + token.token );\n                        auto\
    \ const &argToken = *remainingTokens;\n                        if( argToken.type\
    \ != TokenType::Argument )\n                            return InternalParseResult::runtimeError(\
    \ \"Expected argument following \" + token.token );\n                        auto\
    \ result = valueRef->setValue( argToken.token );\n                        if(\
    \ !result )\n                            return InternalParseResult( result );\n\
    \                        if( result.value() == ParseResultType::ShortCircuitAll\
    \ )\n                            return InternalParseResult::ok( ParseState( result.value(),\
    \ remainingTokens ) );\n                    }\n                    return InternalParseResult::ok(\
    \ ParseState( ParseResultType::Matched, ++remainingTokens ) );\n             \
    \   }\n            }\n            return InternalParseResult::ok( ParseState(\
    \ ParseResultType::NoMatch, remainingTokens ) );\n        }\n\n        auto validate()\
    \ const -> Result override {\n            if( m_optNames.empty() )\n         \
    \       return Result::logicError( \"No options supplied to Opt\" );\n       \
    \     for( auto const &name : m_optNames ) {\n                if( name.empty()\
    \ )\n                    return Result::logicError( \"Option name cannot be empty\"\
    \ );\n#ifdef CATCH_PLATFORM_WINDOWS\n                if( name[0] != '-' && name[0]\
    \ != '/' )\n                    return Result::logicError( \"Option name must\
    \ begin with '-' or '/'\" );\n#else\n                if( name[0] != '-' )\n  \
    \                  return Result::logicError( \"Option name must begin with '-'\"\
    \ );\n#endif\n            }\n            return ParserRefImpl::validate();\n \
    \       }\n    };\n\n    struct Help : Opt {\n        Help( bool &showHelpFlag\
    \ )\n        :   Opt([&]( bool flag ) {\n                showHelpFlag = flag;\n\
    \                return ParserResult::ok( ParseResultType::ShortCircuitAll );\n\
    \            })\n        {\n            static_cast<Opt &>( *this )\n        \
    \            (\"display usage information\")\n                    [\"-?\"][\"\
    -h\"][\"--help\"]\n                    .optional();\n        }\n    };\n\n   \
    \ struct Parser : ParserBase {\n\n        mutable ExeName m_exeName;\n       \
    \ std::vector<Opt> m_options;\n        std::vector<Arg> m_args;\n\n        auto\
    \ operator|=( ExeName const &exeName ) -> Parser & {\n            m_exeName =\
    \ exeName;\n            return *this;\n        }\n\n        auto operator|=( Arg\
    \ const &arg ) -> Parser & {\n            m_args.push_back(arg);\n           \
    \ return *this;\n        }\n\n        auto operator|=( Opt const &opt ) -> Parser\
    \ & {\n            m_options.push_back(opt);\n            return *this;\n    \
    \    }\n\n        auto operator|=( Parser const &other ) -> Parser & {\n     \
    \       m_options.insert(m_options.end(), other.m_options.begin(), other.m_options.end());\n\
    \            m_args.insert(m_args.end(), other.m_args.begin(), other.m_args.end());\n\
    \            return *this;\n        }\n\n        template<typename T>\n      \
    \  auto operator|( T const &other ) const -> Parser {\n            return Parser(\
    \ *this ) |= other;\n        }\n\n        // Forward deprecated interface with\
    \ '+' instead of '|'\n        template<typename T>\n        auto operator+=( T\
    \ const &other ) -> Parser & { return operator|=( other ); }\n        template<typename\
    \ T>\n        auto operator+( T const &other ) const -> Parser { return operator|(\
    \ other ); }\n\n        auto getHelpColumns() const -> std::vector<HelpColumns>\
    \ {\n            std::vector<HelpColumns> cols;\n            for (auto const &o\
    \ : m_options) {\n                auto childCols = o.getHelpColumns();\n     \
    \           cols.insert( cols.end(), childCols.begin(), childCols.end() );\n \
    \           }\n            return cols;\n        }\n\n        void writeToStream(\
    \ std::ostream &os ) const {\n            if (!m_exeName.name().empty()) {\n \
    \               os << \"usage:\\n\" << \"  \" << m_exeName.name() << \" \";\n\
    \                bool required = true, first = true;\n                for( auto\
    \ const &arg : m_args ) {\n                    if (first)\n                  \
    \      first = false;\n                    else\n                        os <<\
    \ \" \";\n                    if( arg.isOptional() && required ) {\n         \
    \               os << \"[\";\n                        required = false;\n    \
    \                }\n                    os << \"<\" << arg.hint() << \">\";\n\
    \                    if( arg.cardinality() == 0 )\n                        os\
    \ << \" ... \";\n                }\n                if( !required )\n        \
    \            os << \"]\";\n                if( !m_options.empty() )\n        \
    \            os << \" options\";\n                os << \"\\n\\nwhere options\
    \ are:\" << std::endl;\n            }\n\n            auto rows = getHelpColumns();\n\
    \            size_t consoleWidth = CATCH_CLARA_CONFIG_CONSOLE_WIDTH;\n       \
    \     size_t optWidth = 0;\n            for( auto const &cols : rows )\n     \
    \           optWidth = (std::max)(optWidth, cols.left.size() + 2);\n\n       \
    \     optWidth = (std::min)(optWidth, consoleWidth/2);\n\n            for( auto\
    \ const &cols : rows ) {\n                auto row =\n                       \
    \ TextFlow::Column( cols.left ).width( optWidth ).indent( 2 ) +\n            \
    \            TextFlow::Spacer(4) +\n                        TextFlow::Column(\
    \ cols.right ).width( consoleWidth - 7 - optWidth );\n                os << row\
    \ << std::endl;\n            }\n        }\n\n        friend auto operator<<( std::ostream\
    \ &os, Parser const &parser ) -> std::ostream& {\n            parser.writeToStream(\
    \ os );\n            return os;\n        }\n\n        auto validate() const ->\
    \ Result override {\n            for( auto const &opt : m_options ) {\n      \
    \          auto result = opt.validate();\n                if( !result )\n    \
    \                return result;\n            }\n            for( auto const &arg\
    \ : m_args ) {\n                auto result = arg.validate();\n              \
    \  if( !result )\n                    return result;\n            }\n        \
    \    return Result::ok();\n        }\n\n        using ParserBase::parse;\n\n \
    \       auto parse( std::string const& exeName, TokenStream const &tokens ) const\
    \ -> InternalParseResult override {\n\n            struct ParserInfo {\n     \
    \           ParserBase const* parser = nullptr;\n                size_t count\
    \ = 0;\n            };\n            const size_t totalParsers = m_options.size()\
    \ + m_args.size();\n            assert( totalParsers < 512 );\n            //\
    \ ParserInfo parseInfos[totalParsers]; // <-- this is what we really want to do\n\
    \            ParserInfo parseInfos[512];\n\n            {\n                size_t\
    \ i = 0;\n                for (auto const &opt : m_options) parseInfos[i++].parser\
    \ = &opt;\n                for (auto const &arg : m_args) parseInfos[i++].parser\
    \ = &arg;\n            }\n\n            m_exeName.set( exeName );\n\n        \
    \    auto result = InternalParseResult::ok( ParseState( ParseResultType::NoMatch,\
    \ tokens ) );\n            while( result.value().remainingTokens() ) {\n     \
    \           bool tokenParsed = false;\n\n                for( size_t i = 0; i\
    \ < totalParsers; ++i ) {\n                    auto&  parseInfo = parseInfos[i];\n\
    \                    if( parseInfo.parser->cardinality() == 0 || parseInfo.count\
    \ < parseInfo.parser->cardinality() ) {\n                        result = parseInfo.parser->parse(exeName,\
    \ result.value().remainingTokens());\n                        if (!result)\n \
    \                           return result;\n                        if (result.value().type()\
    \ != ParseResultType::NoMatch) {\n                            tokenParsed = true;\n\
    \                            ++parseInfo.count;\n                            break;\n\
    \                        }\n                    }\n                }\n\n     \
    \           if( result.value().type() == ParseResultType::ShortCircuitAll )\n\
    \                    return result;\n                if( !tokenParsed )\n    \
    \                return InternalParseResult::runtimeError( \"Unrecognised token:\
    \ \" + result.value().remainingTokens()->token );\n            }\n           \
    \ // !TBD Check missing required options\n            return result;\n       \
    \ }\n    };\n\n    template<typename DerivedT>\n    template<typename T>\n   \
    \ auto ComposableParserImpl<DerivedT>::operator|( T const &other ) const -> Parser\
    \ {\n        return Parser() | static_cast<DerivedT const &>( *this ) | other;\n\
    \    }\n} // namespace detail\n\n// A Combined parser\nusing detail::Parser;\n\
    \n// A parser for options\nusing detail::Opt;\n\n// A parser for arguments\nusing\
    \ detail::Arg;\n\n// Wrapper for argc, argv from main()\nusing detail::Args;\n\
    \n// Specifies the name of the executable\nusing detail::ExeName;\n\n// Convenience\
    \ wrapper for option parser that specifies the help option\nusing detail::Help;\n\
    \n// enum of result types from a parse\nusing detail::ParseResultType;\n\n// Result\
    \ type for parser operation\nusing detail::ParserResult;\n\n}} // namespace Catch::clara\n\
    \n// end clara.hpp\n#ifdef __clang__\n#pragma clang diagnostic pop\n#endif\n\n\
    // Restore Clara's value for console width, if present\n#ifdef CATCH_TEMP_CLARA_CONFIG_CONSOLE_WIDTH\n\
    #define CATCH_CLARA_TEXTFLOW_CONFIG_CONSOLE_WIDTH CATCH_TEMP_CLARA_CONFIG_CONSOLE_WIDTH\n\
    #undef CATCH_TEMP_CLARA_CONFIG_CONSOLE_WIDTH\n#endif\n\n// end catch_clara.h\n\
    namespace Catch {\n\n    clara::Parser makeCommandLineParser( ConfigData& config\
    \ );\n\n} // end namespace Catch\n\n// end catch_commandline.h\n#include <fstream>\n\
    #include <ctime>\n\nnamespace Catch {\n\n    clara::Parser makeCommandLineParser(\
    \ ConfigData& config ) {\n\n        using namespace clara;\n\n        auto const\
    \ setWarning = [&]( std::string const& warning ) {\n                auto warningSet\
    \ = [&]() {\n                    if( warning == \"NoAssertions\" )\n         \
    \               return WarnAbout::NoAssertions;\n\n                    if ( warning\
    \ == \"NoTests\" )\n                        return WarnAbout::NoTests;\n\n   \
    \                 return WarnAbout::Nothing;\n                }();\n\n       \
    \         if (warningSet == WarnAbout::Nothing)\n                    return ParserResult::runtimeError(\
    \ \"Unrecognised warning: '\" + warning + \"'\" );\n                config.warnings\
    \ = static_cast<WarnAbout::What>( config.warnings | warningSet );\n          \
    \      return ParserResult::ok( ParseResultType::Matched );\n            };\n\
    \        auto const loadTestNamesFromFile = [&]( std::string const& filename )\
    \ {\n                std::ifstream f( filename.c_str() );\n                if(\
    \ !f.is_open() )\n                    return ParserResult::runtimeError( \"Unable\
    \ to load input file: '\" + filename + \"'\" );\n\n                std::string\
    \ line;\n                while( std::getline( f, line ) ) {\n                \
    \    line = trim(line);\n                    if( !line.empty() && !startsWith(\
    \ line, '#' ) ) {\n                        if( !startsWith( line, '\"' ) )\n \
    \                           line = '\"' + line + '\"';\n                     \
    \   config.testsOrTags.push_back( line );\n                        config.testsOrTags.emplace_back(\
    \ \",\" );\n                    }\n                }\n                //Remove\
    \ comma in the end\n                if(!config.testsOrTags.empty())\n        \
    \            config.testsOrTags.erase( config.testsOrTags.end()-1 );\n\n     \
    \           return ParserResult::ok( ParseResultType::Matched );\n           \
    \ };\n        auto const setTestOrder = [&]( std::string const& order ) {\n  \
    \              if( startsWith( \"declared\", order ) )\n                    config.runOrder\
    \ = RunTests::InDeclarationOrder;\n                else if( startsWith( \"lexical\"\
    , order ) )\n                    config.runOrder = RunTests::InLexicographicalOrder;\n\
    \                else if( startsWith( \"random\", order ) )\n                \
    \    config.runOrder = RunTests::InRandomOrder;\n                else\n      \
    \              return clara::ParserResult::runtimeError( \"Unrecognised ordering:\
    \ '\" + order + \"'\" );\n                return ParserResult::ok( ParseResultType::Matched\
    \ );\n            };\n        auto const setRngSeed = [&]( std::string const&\
    \ seed ) {\n                if( seed != \"time\" )\n                    return\
    \ clara::detail::convertInto( seed, config.rngSeed );\n                config.rngSeed\
    \ = static_cast<unsigned int>( std::time(nullptr) );\n                return ParserResult::ok(\
    \ ParseResultType::Matched );\n            };\n        auto const setColourUsage\
    \ = [&]( std::string const& useColour ) {\n                    auto mode = toLower(\
    \ useColour );\n\n                    if( mode == \"yes\" )\n                \
    \        config.useColour = UseColour::Yes;\n                    else if( mode\
    \ == \"no\" )\n                        config.useColour = UseColour::No;\n   \
    \                 else if( mode == \"auto\" )\n                        config.useColour\
    \ = UseColour::Auto;\n                    else\n                        return\
    \ ParserResult::runtimeError( \"colour mode must be one of: auto, yes or no. '\"\
    \ + useColour + \"' not recognised\" );\n                return ParserResult::ok(\
    \ ParseResultType::Matched );\n            };\n        auto const setWaitForKeypress\
    \ = [&]( std::string const& keypress ) {\n                auto keypressLc = toLower(\
    \ keypress );\n                if (keypressLc == \"never\")\n                \
    \    config.waitForKeypress = WaitForKeypress::Never;\n                else if(\
    \ keypressLc == \"start\" )\n                    config.waitForKeypress = WaitForKeypress::BeforeStart;\n\
    \                else if( keypressLc == \"exit\" )\n                    config.waitForKeypress\
    \ = WaitForKeypress::BeforeExit;\n                else if( keypressLc == \"both\"\
    \ )\n                    config.waitForKeypress = WaitForKeypress::BeforeStartAndExit;\n\
    \                else\n                    return ParserResult::runtimeError(\
    \ \"keypress argument must be one of: never, start, exit or both. '\" + keypress\
    \ + \"' not recognised\" );\n            return ParserResult::ok( ParseResultType::Matched\
    \ );\n            };\n        auto const setVerbosity = [&]( std::string const&\
    \ verbosity ) {\n            auto lcVerbosity = toLower( verbosity );\n      \
    \      if( lcVerbosity == \"quiet\" )\n                config.verbosity = Verbosity::Quiet;\n\
    \            else if( lcVerbosity == \"normal\" )\n                config.verbosity\
    \ = Verbosity::Normal;\n            else if( lcVerbosity == \"high\" )\n     \
    \           config.verbosity = Verbosity::High;\n            else\n          \
    \      return ParserResult::runtimeError( \"Unrecognised verbosity, '\" + verbosity\
    \ + \"'\" );\n            return ParserResult::ok( ParseResultType::Matched );\n\
    \        };\n        auto const setReporter = [&]( std::string const& reporter\
    \ ) {\n            IReporterRegistry::FactoryMap const& factories = getRegistryHub().getReporterRegistry().getFactories();\n\
    \n            auto lcReporter = toLower( reporter );\n            auto result\
    \ = factories.find( lcReporter );\n\n            if( factories.end() != result\
    \ )\n                config.reporterName = lcReporter;\n            else\n   \
    \             return ParserResult::runtimeError( \"Unrecognized reporter, '\"\
    \ + reporter + \"'. Check available with --list-reporters\" );\n            return\
    \ ParserResult::ok( ParseResultType::Matched );\n        };\n\n        auto cli\n\
    \            = ExeName( config.processName )\n            | Help( config.showHelp\
    \ )\n            | Opt( config.listTests )\n                [\"-l\"][\"--list-tests\"\
    ]\n                ( \"list all/matching test cases\" )\n            | Opt( config.listTags\
    \ )\n                [\"-t\"][\"--list-tags\"]\n                ( \"list all/matching\
    \ tags\" )\n            | Opt( config.showSuccessfulTests )\n                [\"\
    -s\"][\"--success\"]\n                ( \"include successful tests in output\"\
    \ )\n            | Opt( config.shouldDebugBreak )\n                [\"-b\"][\"\
    --break\"]\n                ( \"break into debugger on failure\" )\n         \
    \   | Opt( config.noThrow )\n                [\"-e\"][\"--nothrow\"]\n       \
    \         ( \"skip exception tests\" )\n            | Opt( config.showInvisibles\
    \ )\n                [\"-i\"][\"--invisibles\"]\n                ( \"show invisibles\
    \ (tabs, newlines)\" )\n            | Opt( config.outputFilename, \"filename\"\
    \ )\n                [\"-o\"][\"--out\"]\n                ( \"output filename\"\
    \ )\n            | Opt( setReporter, \"name\" )\n                [\"-r\"][\"--reporter\"\
    ]\n                ( \"reporter to use (defaults to console)\" )\n           \
    \ | Opt( config.name, \"name\" )\n                [\"-n\"][\"--name\"]\n     \
    \           ( \"suite name\" )\n            | Opt( [&]( bool ){ config.abortAfter\
    \ = 1; } )\n                [\"-a\"][\"--abort\"]\n                ( \"abort at\
    \ first failure\" )\n            | Opt( [&]( int x ){ config.abortAfter = x; },\
    \ \"no. failures\" )\n                [\"-x\"][\"--abortx\"]\n               \
    \ ( \"abort after x failures\" )\n            | Opt( setWarning, \"warning name\"\
    \ )\n                [\"-w\"][\"--warn\"]\n                ( \"enable warnings\"\
    \ )\n            | Opt( [&]( bool flag ) { config.showDurations = flag ? ShowDurations::Always\
    \ : ShowDurations::Never; }, \"yes|no\" )\n                [\"-d\"][\"--durations\"\
    ]\n                ( \"show test durations\" )\n            | Opt( config.minDuration,\
    \ \"seconds\" )\n                [\"-D\"][\"--min-duration\"]\n              \
    \  ( \"show test durations for tests taking at least the given number of seconds\"\
    \ )\n            | Opt( loadTestNamesFromFile, \"filename\" )\n              \
    \  [\"-f\"][\"--input-file\"]\n                ( \"load test names to run from\
    \ a file\" )\n            | Opt( config.filenamesAsTags )\n                [\"\
    -#\"][\"--filenames-as-tags\"]\n                ( \"adds a tag for the filename\"\
    \ )\n            | Opt( config.sectionsToRun, \"section name\" )\n           \
    \     [\"-c\"][\"--section\"]\n                ( \"specify section to run\" )\n\
    \            | Opt( setVerbosity, \"quiet|normal|high\" )\n                [\"\
    -v\"][\"--verbosity\"]\n                ( \"set output verbosity\" )\n       \
    \     | Opt( config.listTestNamesOnly )\n                [\"--list-test-names-only\"\
    ]\n                ( \"list all/matching test cases names only\" )\n         \
    \   | Opt( config.listReporters )\n                [\"--list-reporters\"]\n  \
    \              ( \"list all reporters\" )\n            | Opt( setTestOrder, \"\
    decl|lex|rand\" )\n                [\"--order\"]\n                ( \"test case\
    \ order (defaults to decl)\" )\n            | Opt( setRngSeed, \"'time'|number\"\
    \ )\n                [\"--rng-seed\"]\n                ( \"set a specific seed\
    \ for random numbers\" )\n            | Opt( setColourUsage, \"yes|no\" )\n  \
    \              [\"--use-colour\"]\n                ( \"should output be colourised\"\
    \ )\n            | Opt( config.libIdentify )\n                [\"--libidentify\"\
    ]\n                ( \"report name and version according to libidentify standard\"\
    \ )\n            | Opt( setWaitForKeypress, \"never|start|exit|both\" )\n    \
    \            [\"--wait-for-keypress\"]\n                ( \"waits for a keypress\
    \ before exiting\" )\n            | Opt( config.benchmarkSamples, \"samples\"\
    \ )\n                [\"--benchmark-samples\"]\n                ( \"number of\
    \ samples to collect (default: 100)\" )\n            | Opt( config.benchmarkResamples,\
    \ \"resamples\" )\n                [\"--benchmark-resamples\"]\n             \
    \   ( \"number of resamples for the bootstrap (default: 100000)\" )\n        \
    \    | Opt( config.benchmarkConfidenceInterval, \"confidence interval\" )\n  \
    \              [\"--benchmark-confidence-interval\"]\n                ( \"confidence\
    \ interval for the bootstrap (between 0 and 1, default: 0.95)\" )\n          \
    \  | Opt( config.benchmarkNoAnalysis )\n                [\"--benchmark-no-analysis\"\
    ]\n                ( \"perform only measurements; do not perform any analysis\"\
    \ )\n            | Opt( config.benchmarkWarmupTime, \"benchmarkWarmupTime\" )\n\
    \                [\"--benchmark-warmup-time\"]\n                ( \"amount of\
    \ time in milliseconds spent on warming up each test (default: 100)\" )\n    \
    \        | Arg( config.testsOrTags, \"test name|pattern|tags\" )\n           \
    \     ( \"which test or tests to use\" );\n\n        return cli;\n    }\n\n} //\
    \ end namespace Catch\n// end catch_commandline.cpp\n// start catch_common.cpp\n\
    \n#include <cstring>\n#include <ostream>\n\nnamespace Catch {\n\n    bool SourceLineInfo::operator\
    \ == ( SourceLineInfo const& other ) const noexcept {\n        return line ==\
    \ other.line && (file == other.file || std::strcmp(file, other.file) == 0);\n\
    \    }\n    bool SourceLineInfo::operator < ( SourceLineInfo const& other ) const\
    \ noexcept {\n        // We can assume that the same file will usually have the\
    \ same pointer.\n        // Thus, if the pointers are the same, there is no point\
    \ in calling the strcmp\n        return line < other.line || ( line == other.line\
    \ && file != other.file && (std::strcmp(file, other.file) < 0));\n    }\n\n  \
    \  std::ostream& operator << ( std::ostream& os, SourceLineInfo const& info )\
    \ {\n#ifndef __GNUG__\n        os << info.file << '(' << info.line << ')';\n#else\n\
    \        os << info.file << ':' << info.line;\n#endif\n        return os;\n  \
    \  }\n\n    std::string StreamEndStop::operator+() const {\n        return std::string();\n\
    \    }\n\n    NonCopyable::NonCopyable() = default;\n    NonCopyable::~NonCopyable()\
    \ = default;\n\n}\n// end catch_common.cpp\n// start catch_config.cpp\n\nnamespace\
    \ Catch {\n\n    Config::Config( ConfigData const& data )\n    :   m_data( data\
    \ ),\n        m_stream( openStream() )\n    {\n        // We need to trim filter\
    \ specs to avoid trouble with superfluous\n        // whitespace (esp. important\
    \ for bdd macros, as those are manually\n        // aligned with whitespace).\n\
    \n        for (auto& elem : m_data.testsOrTags) {\n            elem = trim(elem);\n\
    \        }\n        for (auto& elem : m_data.sectionsToRun) {\n            elem\
    \ = trim(elem);\n        }\n\n        TestSpecParser parser(ITagAliasRegistry::get());\n\
    \        if (!m_data.testsOrTags.empty()) {\n            m_hasTestFilters = true;\n\
    \            for (auto const& testOrTags : m_data.testsOrTags) {\n           \
    \     parser.parse(testOrTags);\n            }\n        }\n        m_testSpec\
    \ = parser.testSpec();\n    }\n\n    std::string const& Config::getFilename()\
    \ const {\n        return m_data.outputFilename ;\n    }\n\n    bool Config::listTests()\
    \ const          { return m_data.listTests; }\n    bool Config::listTestNamesOnly()\
    \ const  { return m_data.listTestNamesOnly; }\n    bool Config::listTags() const\
    \           { return m_data.listTags; }\n    bool Config::listReporters() const\
    \      { return m_data.listReporters; }\n\n    std::string Config::getProcessName()\
    \ const { return m_data.processName; }\n    std::string const& Config::getReporterName()\
    \ const { return m_data.reporterName; }\n\n    std::vector<std::string> const&\
    \ Config::getTestsOrTags() const { return m_data.testsOrTags; }\n    std::vector<std::string>\
    \ const& Config::getSectionsToRun() const { return m_data.sectionsToRun; }\n\n\
    \    TestSpec const& Config::testSpec() const { return m_testSpec; }\n    bool\
    \ Config::hasTestFilters() const { return m_hasTestFilters; }\n\n    bool Config::showHelp()\
    \ const { return m_data.showHelp; }\n\n    // IConfig interface\n    bool Config::allowThrows()\
    \ const                   { return !m_data.noThrow; }\n    std::ostream& Config::stream()\
    \ const               { return m_stream->stream(); }\n    std::string Config::name()\
    \ const                   { return m_data.name.empty() ? m_data.processName :\
    \ m_data.name; }\n    bool Config::includeSuccessfulResults() const      { return\
    \ m_data.showSuccessfulTests; }\n    bool Config::warnAboutMissingAssertions()\
    \ const    { return !!(m_data.warnings & WarnAbout::NoAssertions); }\n    bool\
    \ Config::warnAboutNoTests() const              { return !!(m_data.warnings &\
    \ WarnAbout::NoTests); }\n    ShowDurations::OrNot Config::showDurations() const\
    \ { return m_data.showDurations; }\n    double Config::minDuration() const   \
    \              { return m_data.minDuration; }\n    RunTests::InWhatOrder Config::runOrder()\
    \ const     { return m_data.runOrder; }\n    unsigned int Config::rngSeed() const\
    \               { return m_data.rngSeed; }\n    UseColour::YesOrNo Config::useColour()\
    \ const       { return m_data.useColour; }\n    bool Config::shouldDebugBreak()\
    \ const              { return m_data.shouldDebugBreak; }\n    int Config::abortAfter()\
    \ const                     { return m_data.abortAfter; }\n    bool Config::showInvisibles()\
    \ const                { return m_data.showInvisibles; }\n    Verbosity Config::verbosity()\
    \ const                { return m_data.verbosity; }\n\n    bool Config::benchmarkNoAnalysis()\
    \ const                      { return m_data.benchmarkNoAnalysis; }\n    int Config::benchmarkSamples()\
    \ const                          { return m_data.benchmarkSamples; }\n    double\
    \ Config::benchmarkConfidenceInterval() const            { return m_data.benchmarkConfidenceInterval;\
    \ }\n    unsigned int Config::benchmarkResamples() const               { return\
    \ m_data.benchmarkResamples; }\n    std::chrono::milliseconds Config::benchmarkWarmupTime()\
    \ const { return std::chrono::milliseconds(m_data.benchmarkWarmupTime); }\n\n\
    \    IStream const* Config::openStream() {\n        return Catch::makeStream(m_data.outputFilename);\n\
    \    }\n\n} // end namespace Catch\n// end catch_config.cpp\n// start catch_console_colour.cpp\n\
    \n#if defined(__clang__)\n#    pragma clang diagnostic push\n#    pragma clang\
    \ diagnostic ignored \"-Wexit-time-destructors\"\n#endif\n\n// start catch_errno_guard.h\n\
    \nnamespace Catch {\n\n    class ErrnoGuard {\n    public:\n        ErrnoGuard();\n\
    \        ~ErrnoGuard();\n    private:\n        int m_oldErrno;\n    };\n\n}\n\n\
    // end catch_errno_guard.h\n#include <sstream>\n\nnamespace Catch {\n    namespace\
    \ {\n\n        struct IColourImpl {\n            virtual ~IColourImpl() = default;\n\
    \            virtual void use( Colour::Code _colourCode ) = 0;\n        };\n\n\
    \        struct NoColourImpl : IColourImpl {\n            void use( Colour::Code\
    \ ) override {}\n\n            static IColourImpl* instance() {\n            \
    \    static NoColourImpl s_instance;\n                return &s_instance;\n  \
    \          }\n        };\n\n    } // anon namespace\n} // namespace Catch\n\n\
    #if !defined( CATCH_CONFIG_COLOUR_NONE ) && !defined( CATCH_CONFIG_COLOUR_WINDOWS\
    \ ) && !defined( CATCH_CONFIG_COLOUR_ANSI )\n#   ifdef CATCH_PLATFORM_WINDOWS\n\
    #       define CATCH_CONFIG_COLOUR_WINDOWS\n#   else\n#       define CATCH_CONFIG_COLOUR_ANSI\n\
    #   endif\n#endif\n\n#if defined ( CATCH_CONFIG_COLOUR_WINDOWS ) /////////////////////////////////////////\n\
    \nnamespace Catch {\nnamespace {\n\n    class Win32ColourImpl : public IColourImpl\
    \ {\n    public:\n        Win32ColourImpl() : stdoutHandle( GetStdHandle(STD_OUTPUT_HANDLE)\
    \ )\n        {\n            CONSOLE_SCREEN_BUFFER_INFO csbiInfo;\n           \
    \ GetConsoleScreenBufferInfo( stdoutHandle, &csbiInfo );\n            originalForegroundAttributes\
    \ = csbiInfo.wAttributes & ~( BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_BLUE\
    \ | BACKGROUND_INTENSITY );\n            originalBackgroundAttributes = csbiInfo.wAttributes\
    \ & ~( FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY\
    \ );\n        }\n\n        void use( Colour::Code _colourCode ) override {\n \
    \           switch( _colourCode ) {\n                case Colour::None:      return\
    \ setTextAttribute( originalForegroundAttributes );\n                case Colour::White:\
    \     return setTextAttribute( FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE\
    \ );\n                case Colour::Red:       return setTextAttribute( FOREGROUND_RED\
    \ );\n                case Colour::Green:     return setTextAttribute( FOREGROUND_GREEN\
    \ );\n                case Colour::Blue:      return setTextAttribute( FOREGROUND_BLUE\
    \ );\n                case Colour::Cyan:      return setTextAttribute( FOREGROUND_BLUE\
    \ | FOREGROUND_GREEN );\n                case Colour::Yellow:    return setTextAttribute(\
    \ FOREGROUND_RED | FOREGROUND_GREEN );\n                case Colour::Grey:   \
    \   return setTextAttribute( 0 );\n\n                case Colour::LightGrey: \
    \    return setTextAttribute( FOREGROUND_INTENSITY );\n                case Colour::BrightRed:\
    \     return setTextAttribute( FOREGROUND_INTENSITY | FOREGROUND_RED );\n    \
    \            case Colour::BrightGreen:   return setTextAttribute( FOREGROUND_INTENSITY\
    \ | FOREGROUND_GREEN );\n                case Colour::BrightWhite:   return setTextAttribute(\
    \ FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE );\n\
    \                case Colour::BrightYellow:  return setTextAttribute( FOREGROUND_INTENSITY\
    \ | FOREGROUND_RED | FOREGROUND_GREEN );\n\n                case Colour::Bright:\
    \ CATCH_INTERNAL_ERROR( \"not a colour\" );\n\n                default:\n    \
    \                CATCH_ERROR( \"Unknown colour requested\" );\n            }\n\
    \        }\n\n    private:\n        void setTextAttribute( WORD _textAttribute\
    \ ) {\n            SetConsoleTextAttribute( stdoutHandle, _textAttribute | originalBackgroundAttributes\
    \ );\n        }\n        HANDLE stdoutHandle;\n        WORD originalForegroundAttributes;\n\
    \        WORD originalBackgroundAttributes;\n    };\n\n    IColourImpl* platformColourInstance()\
    \ {\n        static Win32ColourImpl s_instance;\n\n        IConfigPtr config =\
    \ getCurrentContext().getConfig();\n        UseColour::YesOrNo colourMode = config\n\
    \            ? config->useColour()\n            : UseColour::Auto;\n        if(\
    \ colourMode == UseColour::Auto )\n            colourMode = UseColour::Yes;\n\
    \        return colourMode == UseColour::Yes\n            ? &s_instance\n    \
    \        : NoColourImpl::instance();\n    }\n\n} // end anon namespace\n} // end\
    \ namespace Catch\n\n#elif defined( CATCH_CONFIG_COLOUR_ANSI ) //////////////////////////////////////\n\
    \n#include <unistd.h>\n\nnamespace Catch {\nnamespace {\n\n    // use POSIX/ ANSI\
    \ console terminal codes\n    // Thanks to Adam Strzelecki for original contribution\n\
    \    // (http://github.com/nanoant)\n    // https://github.com/philsquared/Catch/pull/131\n\
    \    class PosixColourImpl : public IColourImpl {\n    public:\n        void use(\
    \ Colour::Code _colourCode ) override {\n            switch( _colourCode ) {\n\
    \                case Colour::None:\n                case Colour::White:     return\
    \ setColour( \"[0m\" );\n                case Colour::Red:       return setColour(\
    \ \"[0;31m\" );\n                case Colour::Green:     return setColour( \"\
    [0;32m\" );\n                case Colour::Blue:      return setColour( \"[0;34m\"\
    \ );\n                case Colour::Cyan:      return setColour( \"[0;36m\" );\n\
    \                case Colour::Yellow:    return setColour( \"[0;33m\" );\n   \
    \             case Colour::Grey:      return setColour( \"[1;30m\" );\n\n    \
    \            case Colour::LightGrey:     return setColour( \"[0;37m\" );\n   \
    \             case Colour::BrightRed:     return setColour( \"[1;31m\" );\n  \
    \              case Colour::BrightGreen:   return setColour( \"[1;32m\" );\n \
    \               case Colour::BrightWhite:   return setColour( \"[1;37m\" );\n\
    \                case Colour::BrightYellow:  return setColour( \"[1;33m\" );\n\
    \n                case Colour::Bright: CATCH_INTERNAL_ERROR( \"not a colour\"\
    \ );\n                default: CATCH_INTERNAL_ERROR( \"Unknown colour requested\"\
    \ );\n            }\n        }\n        static IColourImpl* instance() {\n   \
    \         static PosixColourImpl s_instance;\n            return &s_instance;\n\
    \        }\n\n    private:\n        void setColour( const char* _escapeCode )\
    \ {\n            getCurrentContext().getConfig()->stream()\n                <<\
    \ '\\033' << _escapeCode;\n        }\n    };\n\n    bool useColourOnPlatform()\
    \ {\n        return\n#if defined(CATCH_PLATFORM_MAC) || defined(CATCH_PLATFORM_IPHONE)\n\
    \            !isDebuggerActive() &&\n#endif\n#if !(defined(__DJGPP__) && defined(__STRICT_ANSI__))\n\
    \            isatty(STDOUT_FILENO)\n#else\n            false\n#endif\n       \
    \     ;\n    }\n    IColourImpl* platformColourInstance() {\n        ErrnoGuard\
    \ guard;\n        IConfigPtr config = getCurrentContext().getConfig();\n     \
    \   UseColour::YesOrNo colourMode = config\n            ? config->useColour()\n\
    \            : UseColour::Auto;\n        if( colourMode == UseColour::Auto )\n\
    \            colourMode = useColourOnPlatform()\n                ? UseColour::Yes\n\
    \                : UseColour::No;\n        return colourMode == UseColour::Yes\n\
    \            ? PosixColourImpl::instance()\n            : NoColourImpl::instance();\n\
    \    }\n\n} // end anon namespace\n} // end namespace Catch\n\n#else  // not Windows\
    \ or ANSI ///////////////////////////////////////////////\n\nnamespace Catch {\n\
    \n    static IColourImpl* platformColourInstance() { return NoColourImpl::instance();\
    \ }\n\n} // end namespace Catch\n\n#endif // Windows/ ANSI/ None\n\nnamespace\
    \ Catch {\n\n    Colour::Colour( Code _colourCode ) { use( _colourCode ); }\n\
    \    Colour::Colour( Colour&& other ) noexcept {\n        m_moved = other.m_moved;\n\
    \        other.m_moved = true;\n    }\n    Colour& Colour::operator=( Colour&&\
    \ other ) noexcept {\n        m_moved = other.m_moved;\n        other.m_moved\
    \  = true;\n        return *this;\n    }\n\n    Colour::~Colour(){ if( !m_moved\
    \ ) use( None ); }\n\n    void Colour::use( Code _colourCode ) {\n        static\
    \ IColourImpl* impl = platformColourInstance();\n        // Strictly speaking,\
    \ this cannot possibly happen.\n        // However, under some conditions it does\
    \ happen (see #1626),\n        // and this change is small enough that we can\
    \ let practicality\n        // triumph over purity in this case.\n        if (impl\
    \ != nullptr) {\n            impl->use( _colourCode );\n        }\n    }\n\n \
    \   std::ostream& operator << ( std::ostream& os, Colour const& ) {\n        return\
    \ os;\n    }\n\n} // end namespace Catch\n\n#if defined(__clang__)\n#    pragma\
    \ clang diagnostic pop\n#endif\n\n// end catch_console_colour.cpp\n// start catch_context.cpp\n\
    \nnamespace Catch {\n\n    class Context : public IMutableContext, NonCopyable\
    \ {\n\n    public: // IContext\n        IResultCapture* getResultCapture() override\
    \ {\n            return m_resultCapture;\n        }\n        IRunner* getRunner()\
    \ override {\n            return m_runner;\n        }\n\n        IConfigPtr const&\
    \ getConfig() const override {\n            return m_config;\n        }\n\n  \
    \      ~Context() override;\n\n    public: // IMutableContext\n        void setResultCapture(\
    \ IResultCapture* resultCapture ) override {\n            m_resultCapture = resultCapture;\n\
    \        }\n        void setRunner( IRunner* runner ) override {\n           \
    \ m_runner = runner;\n        }\n        void setConfig( IConfigPtr const& config\
    \ ) override {\n            m_config = config;\n        }\n\n        friend IMutableContext&\
    \ getCurrentMutableContext();\n\n    private:\n        IConfigPtr m_config;\n\
    \        IRunner* m_runner = nullptr;\n        IResultCapture* m_resultCapture\
    \ = nullptr;\n    };\n\n    IMutableContext *IMutableContext::currentContext =\
    \ nullptr;\n\n    void IMutableContext::createContext()\n    {\n        currentContext\
    \ = new Context();\n    }\n\n    void cleanUpContext() {\n        delete IMutableContext::currentContext;\n\
    \        IMutableContext::currentContext = nullptr;\n    }\n    IContext::~IContext()\
    \ = default;\n    IMutableContext::~IMutableContext() = default;\n    Context::~Context()\
    \ = default;\n\n    SimplePcg32& rng() {\n        static SimplePcg32 s_rng;\n\
    \        return s_rng;\n    }\n\n}\n// end catch_context.cpp\n// start catch_debug_console.cpp\n\
    \n// start catch_debug_console.h\n\n#include <string>\n\nnamespace Catch {\n \
    \   void writeToDebugConsole( std::string const& text );\n}\n\n// end catch_debug_console.h\n\
    #if defined(CATCH_CONFIG_ANDROID_LOGWRITE)\n#include <android/log.h>\n\n    namespace\
    \ Catch {\n        void writeToDebugConsole( std::string const& text ) {\n   \
    \         __android_log_write( ANDROID_LOG_DEBUG, \"Catch\", text.c_str() );\n\
    \        }\n    }\n\n#elif defined(CATCH_PLATFORM_WINDOWS)\n\n    namespace Catch\
    \ {\n        void writeToDebugConsole( std::string const& text ) {\n         \
    \   ::OutputDebugStringA( text.c_str() );\n        }\n    }\n\n#else\n\n    namespace\
    \ Catch {\n        void writeToDebugConsole( std::string const& text ) {\n   \
    \         // !TBD: Need a version for Mac/ XCode and other IDEs\n            Catch::cout()\
    \ << text;\n        }\n    }\n\n#endif // Platform\n// end catch_debug_console.cpp\n\
    // start catch_debugger.cpp\n\n#if defined(CATCH_PLATFORM_MAC) || defined(CATCH_PLATFORM_IPHONE)\n\
    \n#  include <cassert>\n#  include <sys/types.h>\n#  include <unistd.h>\n#  include\
    \ <cstddef>\n#  include <ostream>\n\n#ifdef __apple_build_version__\n    // These\
    \ headers will only compile with AppleClang (XCode)\n    // For other compilers\
    \ (Clang, GCC, ... ) we need to exclude them\n#  include <sys/sysctl.h>\n#endif\n\
    \n    namespace Catch {\n        #ifdef __apple_build_version__\n        // The\
    \ following function is taken directly from the following technical note:\n  \
    \      // https://developer.apple.com/library/archive/qa/qa1361/_index.html\n\n\
    \        // Returns true if the current process is being debugged (either\n  \
    \      // running under the debugger or has a debugger attached post facto).\n\
    \        bool isDebuggerActive(){\n            int                 mib[4];\n \
    \           struct kinfo_proc   info;\n            std::size_t         size;\n\
    \n            // Initialize the flags so that, if sysctl fails for some bizarre\n\
    \            // reason, we get a predictable result.\n\n            info.kp_proc.p_flag\
    \ = 0;\n\n            // Initialize mib, which tells sysctl the info we want,\
    \ in this case\n            // we're looking for information about a specific\
    \ process ID.\n\n            mib[0] = CTL_KERN;\n            mib[1] = KERN_PROC;\n\
    \            mib[2] = KERN_PROC_PID;\n            mib[3] = getpid();\n\n     \
    \       // Call sysctl.\n\n            size = sizeof(info);\n            if( sysctl(mib,\
    \ sizeof(mib) / sizeof(*mib), &info, &size, nullptr, 0) != 0 ) {\n           \
    \     Catch::cerr() << \"\\n** Call to sysctl failed - unable to determine if\
    \ debugger is active **\\n\" << std::endl;\n                return false;\n  \
    \          }\n\n            // We're being debugged if the P_TRACED flag is set.\n\
    \n            return ( (info.kp_proc.p_flag & P_TRACED) != 0 );\n        }\n \
    \       #else\n        bool isDebuggerActive() {\n            // We need to find\
    \ another way to determine this for non-appleclang compilers on macOS\n      \
    \      return false;\n        }\n        #endif\n    } // namespace Catch\n\n\
    #elif defined(CATCH_PLATFORM_LINUX)\n    #include <fstream>\n    #include <string>\n\
    \n    namespace Catch{\n        // The standard POSIX way of detecting a debugger\
    \ is to attempt to\n        // ptrace() the process, but this needs to be done\
    \ from a child and not\n        // this process itself to still allow attaching\
    \ to this process later\n        // if wanted, so is rather heavy. Under Linux\
    \ we have the PID of the\n        // \"debugger\" (which doesn't need to be gdb,\
    \ of course, it could also\n        // be strace, for example) in /proc/$PID/status,\
    \ so just get it from\n        // there instead.\n        bool isDebuggerActive(){\n\
    \            // Libstdc++ has a bug, where std::ifstream sets errno to 0\n   \
    \         // This way our users can properly assert over errno values\n      \
    \      ErrnoGuard guard;\n            std::ifstream in(\"/proc/self/status\");\n\
    \            for( std::string line; std::getline(in, line); ) {\n            \
    \    static const int PREFIX_LEN = 11;\n                if( line.compare(0, PREFIX_LEN,\
    \ \"TracerPid:\\t\") == 0 ) {\n                    // We're traced if the PID\
    \ is not 0 and no other PID starts\n                    // with 0 digit, so it's\
    \ enough to check for just a single\n                    // character.\n     \
    \               return line.length() > PREFIX_LEN && line[PREFIX_LEN] != '0';\n\
    \                }\n            }\n\n            return false;\n        }\n  \
    \  } // namespace Catch\n#elif defined(_MSC_VER)\n    extern \"C\" __declspec(dllimport)\
    \ int __stdcall IsDebuggerPresent();\n    namespace Catch {\n        bool isDebuggerActive()\
    \ {\n            return IsDebuggerPresent() != 0;\n        }\n    }\n#elif defined(__MINGW32__)\n\
    \    extern \"C\" __declspec(dllimport) int __stdcall IsDebuggerPresent();\n \
    \   namespace Catch {\n        bool isDebuggerActive() {\n            return IsDebuggerPresent()\
    \ != 0;\n        }\n    }\n#else\n    namespace Catch {\n       bool isDebuggerActive()\
    \ { return false; }\n    }\n#endif // Platform\n// end catch_debugger.cpp\n//\
    \ start catch_decomposer.cpp\n\nnamespace Catch {\n\n    ITransientExpression::~ITransientExpression()\
    \ = default;\n\n    void formatReconstructedExpression( std::ostream &os, std::string\
    \ const& lhs, StringRef op, std::string const& rhs ) {\n        if( lhs.size()\
    \ + rhs.size() < 40 &&\n                lhs.find('\\n') == std::string::npos &&\n\
    \                rhs.find('\\n') == std::string::npos )\n            os << lhs\
    \ << \" \" << op << \" \" << rhs;\n        else\n            os << lhs << \"\\\
    n\" << op << \"\\n\" << rhs;\n    }\n}\n// end catch_decomposer.cpp\n// start\
    \ catch_enforce.cpp\n\n#include <stdexcept>\n\nnamespace Catch {\n#if defined(CATCH_CONFIG_DISABLE_EXCEPTIONS)\
    \ && !defined(CATCH_CONFIG_DISABLE_EXCEPTIONS_CUSTOM_HANDLER)\n    [[noreturn]]\n\
    \    void throw_exception(std::exception const& e) {\n        Catch::cerr() <<\
    \ \"Catch will terminate because it needed to throw an exception.\\n\"\n     \
    \                 << \"The message was: \" << e.what() << '\\n';\n        std::terminate();\n\
    \    }\n#endif\n\n    [[noreturn]]\n    void throw_logic_error(std::string const&\
    \ msg) {\n        throw_exception(std::logic_error(msg));\n    }\n\n    [[noreturn]]\n\
    \    void throw_domain_error(std::string const& msg) {\n        throw_exception(std::domain_error(msg));\n\
    \    }\n\n    [[noreturn]]\n    void throw_runtime_error(std::string const& msg)\
    \ {\n        throw_exception(std::runtime_error(msg));\n    }\n\n} // namespace\
    \ Catch;\n// end catch_enforce.cpp\n// start catch_enum_values_registry.cpp\n\
    // start catch_enum_values_registry.h\n\n#include <vector>\n#include <memory>\n\
    \nnamespace Catch {\n\n    namespace Detail {\n\n        std::unique_ptr<EnumInfo>\
    \ makeEnumInfo( StringRef enumName, StringRef allValueNames, std::vector<int>\
    \ const& values );\n\n        class EnumValuesRegistry : public IMutableEnumValuesRegistry\
    \ {\n\n            std::vector<std::unique_ptr<EnumInfo>> m_enumInfos;\n\n   \
    \         EnumInfo const& registerEnum( StringRef enumName, StringRef allEnums,\
    \ std::vector<int> const& values) override;\n        };\n\n        std::vector<StringRef>\
    \ parseEnums( StringRef enums );\n\n    } // Detail\n\n} // Catch\n\n// end catch_enum_values_registry.h\n\
    \n#include <map>\n#include <cassert>\n\nnamespace Catch {\n\n    IMutableEnumValuesRegistry::~IMutableEnumValuesRegistry()\
    \ {}\n\n    namespace Detail {\n\n        namespace {\n            // Extracts\
    \ the actual name part of an enum instance\n            // In other words, it\
    \ returns the Blue part of Bikeshed::Colour::Blue\n            StringRef extractInstanceName(StringRef\
    \ enumInstance) {\n                // Find last occurence of \":\"\n         \
    \       size_t name_start = enumInstance.size();\n                while (name_start\
    \ > 0 && enumInstance[name_start - 1] != ':') {\n                    --name_start;\n\
    \                }\n                return enumInstance.substr(name_start, enumInstance.size()\
    \ - name_start);\n            }\n        }\n\n        std::vector<StringRef> parseEnums(\
    \ StringRef enums ) {\n            auto enumValues = splitStringRef( enums, ','\
    \ );\n            std::vector<StringRef> parsed;\n            parsed.reserve(\
    \ enumValues.size() );\n            for( auto const& enumValue : enumValues )\
    \ {\n                parsed.push_back(trim(extractInstanceName(enumValue)));\n\
    \            }\n            return parsed;\n        }\n\n        EnumInfo::~EnumInfo()\
    \ {}\n\n        StringRef EnumInfo::lookup( int value ) const {\n            for(\
    \ auto const& valueToName : m_values ) {\n                if( valueToName.first\
    \ == value )\n                    return valueToName.second;\n            }\n\
    \            return \"{** unexpected enum value **}\"_sr;\n        }\n\n     \
    \   std::unique_ptr<EnumInfo> makeEnumInfo( StringRef enumName, StringRef allValueNames,\
    \ std::vector<int> const& values ) {\n            std::unique_ptr<EnumInfo> enumInfo(\
    \ new EnumInfo );\n            enumInfo->m_name = enumName;\n            enumInfo->m_values.reserve(\
    \ values.size() );\n\n            const auto valueNames = Catch::Detail::parseEnums(\
    \ allValueNames );\n            assert( valueNames.size() == values.size() );\n\
    \            std::size_t i = 0;\n            for( auto value : values )\n    \
    \            enumInfo->m_values.emplace_back(value, valueNames[i++]);\n\n    \
    \        return enumInfo;\n        }\n\n        EnumInfo const& EnumValuesRegistry::registerEnum(\
    \ StringRef enumName, StringRef allValueNames, std::vector<int> const& values\
    \ ) {\n            m_enumInfos.push_back(makeEnumInfo(enumName, allValueNames,\
    \ values));\n            return *m_enumInfos.back();\n        }\n\n    } // Detail\n\
    } // Catch\n\n// end catch_enum_values_registry.cpp\n// start catch_errno_guard.cpp\n\
    \n#include <cerrno>\n\nnamespace Catch {\n        ErrnoGuard::ErrnoGuard():m_oldErrno(errno){}\n\
    \        ErrnoGuard::~ErrnoGuard() { errno = m_oldErrno; }\n}\n// end catch_errno_guard.cpp\n\
    // start catch_exception_translator_registry.cpp\n\n// start catch_exception_translator_registry.h\n\
    \n#include <vector>\n#include <string>\n#include <memory>\n\nnamespace Catch {\n\
    \n    class ExceptionTranslatorRegistry : public IExceptionTranslatorRegistry\
    \ {\n    public:\n        ~ExceptionTranslatorRegistry();\n        virtual void\
    \ registerTranslator( const IExceptionTranslator* translator );\n        std::string\
    \ translateActiveException() const override;\n        std::string tryTranslators()\
    \ const;\n\n    private:\n        std::vector<std::unique_ptr<IExceptionTranslator\
    \ const>> m_translators;\n    };\n}\n\n// end catch_exception_translator_registry.h\n\
    #ifdef __OBJC__\n#import \"Foundation/Foundation.h\"\n#endif\n\nnamespace Catch\
    \ {\n\n    ExceptionTranslatorRegistry::~ExceptionTranslatorRegistry() {\n   \
    \ }\n\n    void ExceptionTranslatorRegistry::registerTranslator( const IExceptionTranslator*\
    \ translator ) {\n        m_translators.push_back( std::unique_ptr<const IExceptionTranslator>(\
    \ translator ) );\n    }\n\n#if !defined(CATCH_CONFIG_DISABLE_EXCEPTIONS)\n  \
    \  std::string ExceptionTranslatorRegistry::translateActiveException() const {\n\
    \        try {\n#ifdef __OBJC__\n            // In Objective-C try objective-c\
    \ exceptions first\n            @try {\n                return tryTranslators();\n\
    \            }\n            @catch (NSException *exception) {\n              \
    \  return Catch::Detail::stringify( [exception description] );\n            }\n\
    #else\n            // Compiling a mixed mode project with MSVC means that CLR\n\
    \            // exceptions will be caught in (...) as well. However, these\n \
    \           // do not fill-in std::current_exception and thus lead to crash\n\
    \            // when attempting rethrow.\n            // /EHa switch also causes\
    \ structured exceptions to be caught\n            // here, but they fill-in current_exception\
    \ properly, so\n            // at worst the output should be a little weird, instead\
    \ of\n            // causing a crash.\n            if (std::current_exception()\
    \ == nullptr) {\n                return \"Non C++ exception. Possibly a CLR exception.\"\
    ;\n            }\n            return tryTranslators();\n#endif\n        }\n  \
    \      catch( TestFailureException& ) {\n            std::rethrow_exception(std::current_exception());\n\
    \        }\n        catch( std::exception& ex ) {\n            return ex.what();\n\
    \        }\n        catch( std::string& msg ) {\n            return msg;\n   \
    \     }\n        catch( const char* msg ) {\n            return msg;\n       \
    \ }\n        catch(...) {\n            return \"Unknown exception\";\n       \
    \ }\n    }\n\n    std::string ExceptionTranslatorRegistry::tryTranslators() const\
    \ {\n        if (m_translators.empty()) {\n            std::rethrow_exception(std::current_exception());\n\
    \        } else {\n            return m_translators[0]->translate(m_translators.begin()\
    \ + 1, m_translators.end());\n        }\n    }\n\n#else // ^^ Exceptions are enabled\
    \ // Exceptions are disabled vv\n    std::string ExceptionTranslatorRegistry::translateActiveException()\
    \ const {\n        CATCH_INTERNAL_ERROR(\"Attempted to translate active exception\
    \ under CATCH_CONFIG_DISABLE_EXCEPTIONS!\");\n    }\n\n    std::string ExceptionTranslatorRegistry::tryTranslators()\
    \ const {\n        CATCH_INTERNAL_ERROR(\"Attempted to use exception translators\
    \ under CATCH_CONFIG_DISABLE_EXCEPTIONS!\");\n    }\n#endif\n\n}\n// end catch_exception_translator_registry.cpp\n\
    // start catch_fatal_condition.cpp\n\n#if defined(__GNUC__)\n#    pragma GCC diagnostic\
    \ push\n#    pragma GCC diagnostic ignored \"-Wmissing-field-initializers\"\n\
    #endif\n\n#if defined( CATCH_CONFIG_WINDOWS_SEH ) || defined( CATCH_CONFIG_POSIX_SIGNALS\
    \ )\n\nnamespace {\n    // Report the error condition\n    void reportFatal( char\
    \ const * const message ) {\n        Catch::getCurrentContext().getResultCapture()->handleFatalErrorCondition(\
    \ message );\n    }\n}\n\n#endif // signals/SEH handling\n\n#if defined( CATCH_CONFIG_WINDOWS_SEH\
    \ )\n\nnamespace Catch {\n    struct SignalDefs { DWORD id; const char* name;\
    \ };\n\n    // There is no 1-1 mapping between signals and windows exceptions.\n\
    \    // Windows can easily distinguish between SO and SigSegV,\n    // but SigInt,\
    \ SigTerm, etc are handled differently.\n    static SignalDefs signalDefs[] =\
    \ {\n        { static_cast<DWORD>(EXCEPTION_ILLEGAL_INSTRUCTION),  \"SIGILL -\
    \ Illegal instruction signal\" },\n        { static_cast<DWORD>(EXCEPTION_STACK_OVERFLOW),\
    \ \"SIGSEGV - Stack overflow\" },\n        { static_cast<DWORD>(EXCEPTION_ACCESS_VIOLATION),\
    \ \"SIGSEGV - Segmentation violation signal\" },\n        { static_cast<DWORD>(EXCEPTION_INT_DIVIDE_BY_ZERO),\
    \ \"Divide by zero error\" },\n    };\n\n    LONG CALLBACK FatalConditionHandler::handleVectoredException(PEXCEPTION_POINTERS\
    \ ExceptionInfo) {\n        for (auto const& def : signalDefs) {\n           \
    \ if (ExceptionInfo->ExceptionRecord->ExceptionCode == def.id) {\n           \
    \     reportFatal(def.name);\n            }\n        }\n        // If its not\
    \ an exception we care about, pass it along.\n        // This stops us from eating\
    \ debugger breaks etc.\n        return EXCEPTION_CONTINUE_SEARCH;\n    }\n\n \
    \   FatalConditionHandler::FatalConditionHandler() {\n        isSet = true;\n\
    \        // 32k seems enough for Catch to handle stack overflow,\n        // but\
    \ the value was found experimentally, so there is no strong guarantee\n      \
    \  guaranteeSize = 32 * 1024;\n        exceptionHandlerHandle = nullptr;\n   \
    \     // Register as first handler in current chain\n        exceptionHandlerHandle\
    \ = AddVectoredExceptionHandler(1, handleVectoredException);\n        // Pass\
    \ in guarantee size to be filled\n        SetThreadStackGuarantee(&guaranteeSize);\n\
    \    }\n\n    void FatalConditionHandler::reset() {\n        if (isSet) {\n  \
    \          RemoveVectoredExceptionHandler(exceptionHandlerHandle);\n         \
    \   SetThreadStackGuarantee(&guaranteeSize);\n            exceptionHandlerHandle\
    \ = nullptr;\n            isSet = false;\n        }\n    }\n\n    FatalConditionHandler::~FatalConditionHandler()\
    \ {\n        reset();\n    }\n\nbool FatalConditionHandler::isSet = false;\nULONG\
    \ FatalConditionHandler::guaranteeSize = 0;\nPVOID FatalConditionHandler::exceptionHandlerHandle\
    \ = nullptr;\n\n} // namespace Catch\n\n#elif defined( CATCH_CONFIG_POSIX_SIGNALS\
    \ )\n\nnamespace Catch {\n\n    struct SignalDefs {\n        int id;\n       \
    \ const char* name;\n    };\n\n    // 32kb for the alternate stack seems to be\
    \ sufficient. However, this value\n    // is experimentally determined, so that's\
    \ not guaranteed.\n    static constexpr std::size_t sigStackSize = 32768 >= MINSIGSTKSZ\
    \ ? 32768 : MINSIGSTKSZ;\n\n    static SignalDefs signalDefs[] = {\n        {\
    \ SIGINT,  \"SIGINT - Terminal interrupt signal\" },\n        { SIGILL,  \"SIGILL\
    \ - Illegal instruction signal\" },\n        { SIGFPE,  \"SIGFPE - Floating point\
    \ error signal\" },\n        { SIGSEGV, \"SIGSEGV - Segmentation violation signal\"\
    \ },\n        { SIGTERM, \"SIGTERM - Termination request signal\" },\n       \
    \ { SIGABRT, \"SIGABRT - Abort (abnormal termination) signal\" }\n    };\n\n \
    \   void FatalConditionHandler::handleSignal( int sig ) {\n        char const\
    \ * name = \"<unknown signal>\";\n        for (auto const& def : signalDefs) {\n\
    \            if (sig == def.id) {\n                name = def.name;\n        \
    \        break;\n            }\n        }\n        reset();\n        reportFatal(name);\n\
    \        raise( sig );\n    }\n\n    FatalConditionHandler::FatalConditionHandler()\
    \ {\n        isSet = true;\n        stack_t sigStack;\n        sigStack.ss_sp\
    \ = altStackMem;\n        sigStack.ss_size = sigStackSize;\n        sigStack.ss_flags\
    \ = 0;\n        sigaltstack(&sigStack, &oldSigStack);\n        struct sigaction\
    \ sa = { };\n\n        sa.sa_handler = handleSignal;\n        sa.sa_flags = SA_ONSTACK;\n\
    \        for (std::size_t i = 0; i < sizeof(signalDefs)/sizeof(SignalDefs); ++i)\
    \ {\n            sigaction(signalDefs[i].id, &sa, &oldSigActions[i]);\n      \
    \  }\n    }\n\n    FatalConditionHandler::~FatalConditionHandler() {\n       \
    \ reset();\n    }\n\n    void FatalConditionHandler::reset() {\n        if( isSet\
    \ ) {\n            // Set signals back to previous values -- hopefully nobody\
    \ overwrote them in the meantime\n            for( std::size_t i = 0; i < sizeof(signalDefs)/sizeof(SignalDefs);\
    \ ++i ) {\n                sigaction(signalDefs[i].id, &oldSigActions[i], nullptr);\n\
    \            }\n            // Return the old stack\n            sigaltstack(&oldSigStack,\
    \ nullptr);\n            isSet = false;\n        }\n    }\n\n    bool FatalConditionHandler::isSet\
    \ = false;\n    struct sigaction FatalConditionHandler::oldSigActions[sizeof(signalDefs)/sizeof(SignalDefs)]\
    \ = {};\n    stack_t FatalConditionHandler::oldSigStack = {};\n    char FatalConditionHandler::altStackMem[sigStackSize]\
    \ = {};\n\n} // namespace Catch\n\n#else\n\nnamespace Catch {\n    void FatalConditionHandler::reset()\
    \ {}\n}\n\n#endif // signals/SEH handling\n\n#if defined(__GNUC__)\n#    pragma\
    \ GCC diagnostic pop\n#endif\n// end catch_fatal_condition.cpp\n// start catch_generators.cpp\n\
    \n#include <limits>\n#include <set>\n\nnamespace Catch {\n\nIGeneratorTracker::~IGeneratorTracker()\
    \ {}\n\nconst char* GeneratorException::what() const noexcept {\n    return m_msg;\n\
    }\n\nnamespace Generators {\n\n    GeneratorUntypedBase::~GeneratorUntypedBase()\
    \ {}\n\n    auto acquireGeneratorTracker( StringRef generatorName, SourceLineInfo\
    \ const& lineInfo ) -> IGeneratorTracker& {\n        return getResultCapture().acquireGeneratorTracker(\
    \ generatorName, lineInfo );\n    }\n\n} // namespace Generators\n} // namespace\
    \ Catch\n// end catch_generators.cpp\n// start catch_interfaces_capture.cpp\n\n\
    namespace Catch {\n    IResultCapture::~IResultCapture() = default;\n}\n// end\
    \ catch_interfaces_capture.cpp\n// start catch_interfaces_config.cpp\n\nnamespace\
    \ Catch {\n    IConfig::~IConfig() = default;\n}\n// end catch_interfaces_config.cpp\n\
    // start catch_interfaces_exception.cpp\n\nnamespace Catch {\n    IExceptionTranslator::~IExceptionTranslator()\
    \ = default;\n    IExceptionTranslatorRegistry::~IExceptionTranslatorRegistry()\
    \ = default;\n}\n// end catch_interfaces_exception.cpp\n// start catch_interfaces_registry_hub.cpp\n\
    \nnamespace Catch {\n    IRegistryHub::~IRegistryHub() = default;\n    IMutableRegistryHub::~IMutableRegistryHub()\
    \ = default;\n}\n// end catch_interfaces_registry_hub.cpp\n// start catch_interfaces_reporter.cpp\n\
    \n// start catch_reporter_listening.h\n\nnamespace Catch {\n\n    class ListeningReporter\
    \ : public IStreamingReporter {\n        using Reporters = std::vector<IStreamingReporterPtr>;\n\
    \        Reporters m_listeners;\n        IStreamingReporterPtr m_reporter = nullptr;\n\
    \        ReporterPreferences m_preferences;\n\n    public:\n        ListeningReporter();\n\
    \n        void addListener( IStreamingReporterPtr&& listener );\n        void\
    \ addReporter( IStreamingReporterPtr&& reporter );\n\n    public: // IStreamingReporter\n\
    \n        ReporterPreferences getPreferences() const override;\n\n        void\
    \ noMatchingTestCases( std::string const& spec ) override;\n\n        void reportInvalidArguments(std::string\
    \ const&arg) override;\n\n        static std::set<Verbosity> getSupportedVerbosities();\n\
    \n#if defined(CATCH_CONFIG_ENABLE_BENCHMARKING)\n        void benchmarkPreparing(std::string\
    \ const& name) override;\n        void benchmarkStarting( BenchmarkInfo const&\
    \ benchmarkInfo ) override;\n        void benchmarkEnded( BenchmarkStats<> const&\
    \ benchmarkStats ) override;\n        void benchmarkFailed(std::string const&)\
    \ override;\n#endif // CATCH_CONFIG_ENABLE_BENCHMARKING\n\n        void testRunStarting(\
    \ TestRunInfo const& testRunInfo ) override;\n        void testGroupStarting(\
    \ GroupInfo const& groupInfo ) override;\n        void testCaseStarting( TestCaseInfo\
    \ const& testInfo ) override;\n        void sectionStarting( SectionInfo const&\
    \ sectionInfo ) override;\n        void assertionStarting( AssertionInfo const&\
    \ assertionInfo ) override;\n\n        // The return value indicates if the messages\
    \ buffer should be cleared:\n        bool assertionEnded( AssertionStats const&\
    \ assertionStats ) override;\n        void sectionEnded( SectionStats const& sectionStats\
    \ ) override;\n        void testCaseEnded( TestCaseStats const& testCaseStats\
    \ ) override;\n        void testGroupEnded( TestGroupStats const& testGroupStats\
    \ ) override;\n        void testRunEnded( TestRunStats const& testRunStats ) override;\n\
    \n        void skipTest( TestCaseInfo const& testInfo ) override;\n        bool\
    \ isMulti() const override;\n\n    };\n\n} // end namespace Catch\n\n// end catch_reporter_listening.h\n\
    namespace Catch {\n\n    ReporterConfig::ReporterConfig( IConfigPtr const& _fullConfig\
    \ )\n    :   m_stream( &_fullConfig->stream() ), m_fullConfig( _fullConfig ) {}\n\
    \n    ReporterConfig::ReporterConfig( IConfigPtr const& _fullConfig, std::ostream&\
    \ _stream )\n    :   m_stream( &_stream ), m_fullConfig( _fullConfig ) {}\n\n\
    \    std::ostream& ReporterConfig::stream() const { return *m_stream; }\n    IConfigPtr\
    \ ReporterConfig::fullConfig() const { return m_fullConfig; }\n\n    TestRunInfo::TestRunInfo(\
    \ std::string const& _name ) : name( _name ) {}\n\n    GroupInfo::GroupInfo( \
    \ std::string const& _name,\n                           std::size_t _groupIndex,\n\
    \                           std::size_t _groupsCount )\n    :   name( _name ),\n\
    \        groupIndex( _groupIndex ),\n        groupsCounts( _groupsCount )\n  \
    \  {}\n\n     AssertionStats::AssertionStats( AssertionResult const& _assertionResult,\n\
    \                                     std::vector<MessageInfo> const& _infoMessages,\n\
    \                                     Totals const& _totals )\n    :   assertionResult(\
    \ _assertionResult ),\n        infoMessages( _infoMessages ),\n        totals(\
    \ _totals )\n    {\n        assertionResult.m_resultData.lazyExpression.m_transientExpression\
    \ = _assertionResult.m_resultData.lazyExpression.m_transientExpression;\n\n  \
    \      if( assertionResult.hasMessage() ) {\n            // Copy message into\
    \ messages list.\n            // !TBD This should have been done earlier, somewhere\n\
    \            MessageBuilder builder( assertionResult.getTestMacroName(), assertionResult.getSourceInfo(),\
    \ assertionResult.getResultType() );\n            builder << assertionResult.getMessage();\n\
    \            builder.m_info.message = builder.m_stream.str();\n\n            infoMessages.push_back(\
    \ builder.m_info );\n        }\n    }\n\n     AssertionStats::~AssertionStats()\
    \ = default;\n\n    SectionStats::SectionStats(  SectionInfo const& _sectionInfo,\n\
    \                                 Counts const& _assertions,\n               \
    \                  double _durationInSeconds,\n                              \
    \   bool _missingAssertions )\n    :   sectionInfo( _sectionInfo ),\n        assertions(\
    \ _assertions ),\n        durationInSeconds( _durationInSeconds ),\n        missingAssertions(\
    \ _missingAssertions )\n    {}\n\n    SectionStats::~SectionStats() = default;\n\
    \n    TestCaseStats::TestCaseStats(  TestCaseInfo const& _testInfo,\n        \
    \                           Totals const& _totals,\n                         \
    \          std::string const& _stdOut,\n                                   std::string\
    \ const& _stdErr,\n                                   bool _aborting )\n    :\
    \ testInfo( _testInfo ),\n        totals( _totals ),\n        stdOut( _stdOut\
    \ ),\n        stdErr( _stdErr ),\n        aborting( _aborting )\n    {}\n\n  \
    \  TestCaseStats::~TestCaseStats() = default;\n\n    TestGroupStats::TestGroupStats(\
    \ GroupInfo const& _groupInfo,\n                                    Totals const&\
    \ _totals,\n                                    bool _aborting )\n    :   groupInfo(\
    \ _groupInfo ),\n        totals( _totals ),\n        aborting( _aborting )\n \
    \   {}\n\n    TestGroupStats::TestGroupStats( GroupInfo const& _groupInfo )\n\
    \    :   groupInfo( _groupInfo ),\n        aborting( false )\n    {}\n\n    TestGroupStats::~TestGroupStats()\
    \ = default;\n\n    TestRunStats::TestRunStats(   TestRunInfo const& _runInfo,\n\
    \                    Totals const& _totals,\n                    bool _aborting\
    \ )\n    :   runInfo( _runInfo ),\n        totals( _totals ),\n        aborting(\
    \ _aborting )\n    {}\n\n    TestRunStats::~TestRunStats() = default;\n\n    void\
    \ IStreamingReporter::fatalErrorEncountered( StringRef ) {}\n    bool IStreamingReporter::isMulti()\
    \ const { return false; }\n\n    IReporterFactory::~IReporterFactory() = default;\n\
    \    IReporterRegistry::~IReporterRegistry() = default;\n\n} // end namespace\
    \ Catch\n// end catch_interfaces_reporter.cpp\n// start catch_interfaces_runner.cpp\n\
    \nnamespace Catch {\n    IRunner::~IRunner() = default;\n}\n// end catch_interfaces_runner.cpp\n\
    // start catch_interfaces_testcase.cpp\n\nnamespace Catch {\n    ITestInvoker::~ITestInvoker()\
    \ = default;\n    ITestCaseRegistry::~ITestCaseRegistry() = default;\n}\n// end\
    \ catch_interfaces_testcase.cpp\n// start catch_leak_detector.cpp\n\n#ifdef CATCH_CONFIG_WINDOWS_CRTDBG\n\
    #include <crtdbg.h>\n\nnamespace Catch {\n\n    LeakDetector::LeakDetector() {\n\
    \        int flag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);\n        flag |= _CRTDBG_LEAK_CHECK_DF;\n\
    \        flag |= _CRTDBG_ALLOC_MEM_DF;\n        _CrtSetDbgFlag(flag);\n      \
    \  _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE | _CRTDBG_MODE_DEBUG);\n   \
    \     _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDERR);\n        // Change this\
    \ to leaking allocation's number to break there\n        _CrtSetBreakAlloc(-1);\n\
    \    }\n}\n\n#else\n\n    Catch::LeakDetector::LeakDetector() {}\n\n#endif\n\n\
    Catch::LeakDetector::~LeakDetector() {\n    Catch::cleanUp();\n}\n// end catch_leak_detector.cpp\n\
    // start catch_list.cpp\n\n// start catch_list.h\n\n#include <set>\n\nnamespace\
    \ Catch {\n\n    std::size_t listTests( Config const& config );\n\n    std::size_t\
    \ listTestsNamesOnly( Config const& config );\n\n    struct TagInfo {\n      \
    \  void add( std::string const& spelling );\n        std::string all() const;\n\
    \n        std::set<std::string> spellings;\n        std::size_t count = 0;\n \
    \   };\n\n    std::size_t listTags( Config const& config );\n\n    std::size_t\
    \ listReporters();\n\n    Option<std::size_t> list( std::shared_ptr<Config> const&\
    \ config );\n\n} // end namespace Catch\n\n// end catch_list.h\n// start catch_text.h\n\
    \nnamespace Catch {\n    using namespace clara::TextFlow;\n}\n\n// end catch_text.h\n\
    #include <limits>\n#include <algorithm>\n#include <iomanip>\n\nnamespace Catch\
    \ {\n\n    std::size_t listTests( Config const& config ) {\n        TestSpec const&\
    \ testSpec = config.testSpec();\n        if( config.hasTestFilters() )\n     \
    \       Catch::cout() << \"Matching test cases:\\n\";\n        else {\n      \
    \      Catch::cout() << \"All available test cases:\\n\";\n        }\n\n     \
    \   auto matchedTestCases = filterTests( getAllTestCasesSorted( config ), testSpec,\
    \ config );\n        for( auto const& testCaseInfo : matchedTestCases ) {\n  \
    \          Colour::Code colour = testCaseInfo.isHidden()\n                ? Colour::SecondaryText\n\
    \                : Colour::None;\n            Colour colourGuard( colour );\n\n\
    \            Catch::cout() << Column( testCaseInfo.name ).initialIndent( 2 ).indent(\
    \ 4 ) << \"\\n\";\n            if( config.verbosity() >= Verbosity::High ) {\n\
    \                Catch::cout() << Column( Catch::Detail::stringify( testCaseInfo.lineInfo\
    \ ) ).indent(4) << std::endl;\n                std::string description = testCaseInfo.description;\n\
    \                if( description.empty() )\n                    description =\
    \ \"(NO DESCRIPTION)\";\n                Catch::cout() << Column( description\
    \ ).indent(4) << std::endl;\n            }\n            if( !testCaseInfo.tags.empty()\
    \ )\n                Catch::cout() << Column( testCaseInfo.tagsAsString() ).indent(\
    \ 6 ) << \"\\n\";\n        }\n\n        if( !config.hasTestFilters() )\n     \
    \       Catch::cout() << pluralise( matchedTestCases.size(), \"test case\" ) <<\
    \ '\\n' << std::endl;\n        else\n            Catch::cout() << pluralise( matchedTestCases.size(),\
    \ \"matching test case\" ) << '\\n' << std::endl;\n        return matchedTestCases.size();\n\
    \    }\n\n    std::size_t listTestsNamesOnly( Config const& config ) {\n     \
    \   TestSpec const& testSpec = config.testSpec();\n        std::size_t matchedTests\
    \ = 0;\n        std::vector<TestCase> matchedTestCases = filterTests( getAllTestCasesSorted(\
    \ config ), testSpec, config );\n        for( auto const& testCaseInfo : matchedTestCases\
    \ ) {\n            matchedTests++;\n            if( startsWith( testCaseInfo.name,\
    \ '#' ) )\n               Catch::cout() << '\"' << testCaseInfo.name << '\"';\n\
    \            else\n               Catch::cout() << testCaseInfo.name;\n      \
    \      if ( config.verbosity() >= Verbosity::High )\n                Catch::cout()\
    \ << \"\\t@\" << testCaseInfo.lineInfo;\n            Catch::cout() << std::endl;\n\
    \        }\n        return matchedTests;\n    }\n\n    void TagInfo::add( std::string\
    \ const& spelling ) {\n        ++count;\n        spellings.insert( spelling );\n\
    \    }\n\n    std::string TagInfo::all() const {\n        size_t size = 0;\n \
    \       for (auto const& spelling : spellings) {\n            // Add 2 for the\
    \ brackes\n            size += spelling.size() + 2;\n        }\n\n        std::string\
    \ out; out.reserve(size);\n        for (auto const& spelling : spellings) {\n\
    \            out += '[';\n            out += spelling;\n            out += ']';\n\
    \        }\n        return out;\n    }\n\n    std::size_t listTags( Config const&\
    \ config ) {\n        TestSpec const& testSpec = config.testSpec();\n        if(\
    \ config.hasTestFilters() )\n            Catch::cout() << \"Tags for matching\
    \ test cases:\\n\";\n        else {\n            Catch::cout() << \"All available\
    \ tags:\\n\";\n        }\n\n        std::map<std::string, TagInfo> tagCounts;\n\
    \n        std::vector<TestCase> matchedTestCases = filterTests( getAllTestCasesSorted(\
    \ config ), testSpec, config );\n        for( auto const& testCase : matchedTestCases\
    \ ) {\n            for( auto const& tagName : testCase.getTestCaseInfo().tags\
    \ ) {\n                std::string lcaseTagName = toLower( tagName );\n      \
    \          auto countIt = tagCounts.find( lcaseTagName );\n                if(\
    \ countIt == tagCounts.end() )\n                    countIt = tagCounts.insert(\
    \ std::make_pair( lcaseTagName, TagInfo() ) ).first;\n                countIt->second.add(\
    \ tagName );\n            }\n        }\n\n        for( auto const& tagCount :\
    \ tagCounts ) {\n            ReusableStringStream rss;\n            rss << \"\
    \  \" << std::setw(2) << tagCount.second.count << \"  \";\n            auto str\
    \ = rss.str();\n            auto wrapper = Column( tagCount.second.all() )\n \
    \                                                   .initialIndent( 0 )\n    \
    \                                                .indent( str.size() )\n     \
    \                                               .width( CATCH_CONFIG_CONSOLE_WIDTH-10\
    \ );\n            Catch::cout() << str << wrapper << '\\n';\n        }\n     \
    \   Catch::cout() << pluralise( tagCounts.size(), \"tag\" ) << '\\n' << std::endl;\n\
    \        return tagCounts.size();\n    }\n\n    std::size_t listReporters() {\n\
    \        Catch::cout() << \"Available reporters:\\n\";\n        IReporterRegistry::FactoryMap\
    \ const& factories = getRegistryHub().getReporterRegistry().getFactories();\n\
    \        std::size_t maxNameLen = 0;\n        for( auto const& factoryKvp : factories\
    \ )\n            maxNameLen = (std::max)( maxNameLen, factoryKvp.first.size()\
    \ );\n\n        for( auto const& factoryKvp : factories ) {\n            Catch::cout()\n\
    \                    << Column( factoryKvp.first + \":\" )\n                 \
    \           .indent(2)\n                            .width( 5+maxNameLen )\n \
    \                   +  Column( factoryKvp.second->getDescription() )\n       \
    \                     .initialIndent(0)\n                            .indent(2)\n\
    \                            .width( CATCH_CONFIG_CONSOLE_WIDTH - maxNameLen-8\
    \ )\n                    << \"\\n\";\n        }\n        Catch::cout() << std::endl;\n\
    \        return factories.size();\n    }\n\n    Option<std::size_t> list( std::shared_ptr<Config>\
    \ const& config ) {\n        Option<std::size_t> listedCount;\n        getCurrentMutableContext().setConfig(\
    \ config );\n        if( config->listTests() )\n            listedCount = listedCount.valueOr(0)\
    \ + listTests( *config );\n        if( config->listTestNamesOnly() )\n       \
    \     listedCount = listedCount.valueOr(0) + listTestsNamesOnly( *config );\n\
    \        if( config->listTags() )\n            listedCount = listedCount.valueOr(0)\
    \ + listTags( *config );\n        if( config->listReporters() )\n            listedCount\
    \ = listedCount.valueOr(0) + listReporters();\n        return listedCount;\n \
    \   }\n\n} // end namespace Catch\n// end catch_list.cpp\n// start catch_matchers.cpp\n\
    \nnamespace Catch {\nnamespace Matchers {\n    namespace Impl {\n\n        std::string\
    \ MatcherUntypedBase::toString() const {\n            if( m_cachedToString.empty()\
    \ )\n                m_cachedToString = describe();\n            return m_cachedToString;\n\
    \        }\n\n        MatcherUntypedBase::~MatcherUntypedBase() = default;\n\n\
    \    } // namespace Impl\n} // namespace Matchers\n\nusing namespace Matchers;\n\
    using Matchers::Impl::MatcherBase;\n\n} // namespace Catch\n// end catch_matchers.cpp\n\
    // start catch_matchers_exception.cpp\n\nnamespace Catch {\nnamespace Matchers\
    \ {\nnamespace Exception {\n\nbool ExceptionMessageMatcher::match(std::exception\
    \ const& ex) const {\n    return ex.what() == m_message;\n}\n\nstd::string ExceptionMessageMatcher::describe()\
    \ const {\n    return \"exception message matches \\\"\" + m_message + \"\\\"\"\
    ;\n}\n\n}\nException::ExceptionMessageMatcher Message(std::string const& message)\
    \ {\n    return Exception::ExceptionMessageMatcher(message);\n}\n\n// namespace\
    \ Exception\n} // namespace Matchers\n} // namespace Catch\n// end catch_matchers_exception.cpp\n\
    // start catch_matchers_floating.cpp\n\n// start catch_polyfills.hpp\n\nnamespace\
    \ Catch {\n    bool isnan(float f);\n    bool isnan(double d);\n}\n\n// end catch_polyfills.hpp\n\
    // start catch_to_string.hpp\n\n#include <string>\n\nnamespace Catch {\n    template\
    \ <typename T>\n    std::string to_string(T const& t) {\n#if defined(CATCH_CONFIG_CPP11_TO_STRING)\n\
    \        return std::to_string(t);\n#else\n        ReusableStringStream rss;\n\
    \        rss << t;\n        return rss.str();\n#endif\n    }\n} // end namespace\
    \ Catch\n\n// end catch_to_string.hpp\n#include <algorithm>\n#include <cmath>\n\
    #include <cstdlib>\n#include <cstdint>\n#include <cstring>\n#include <sstream>\n\
    #include <type_traits>\n#include <iomanip>\n#include <limits>\n\nnamespace Catch\
    \ {\nnamespace {\n\n    int32_t convert(float f) {\n        static_assert(sizeof(float)\
    \ == sizeof(int32_t), \"Important ULP matcher assumption violated\");\n      \
    \  int32_t i;\n        std::memcpy(&i, &f, sizeof(f));\n        return i;\n  \
    \  }\n\n    int64_t convert(double d) {\n        static_assert(sizeof(double)\
    \ == sizeof(int64_t), \"Important ULP matcher assumption violated\");\n      \
    \  int64_t i;\n        std::memcpy(&i, &d, sizeof(d));\n        return i;\n  \
    \  }\n\n    template <typename FP>\n    bool almostEqualUlps(FP lhs, FP rhs, uint64_t\
    \ maxUlpDiff) {\n        // Comparison with NaN should always be false.\n    \
    \    // This way we can rule it out before getting into the ugly details\n   \
    \     if (Catch::isnan(lhs) || Catch::isnan(rhs)) {\n            return false;\n\
    \        }\n\n        auto lc = convert(lhs);\n        auto rc = convert(rhs);\n\
    \n        if ((lc < 0) != (rc < 0)) {\n            // Potentially we can have\
    \ +0 and -0\n            return lhs == rhs;\n        }\n\n        auto ulpDiff\
    \ = std::abs(lc - rc);\n        return static_cast<uint64_t>(ulpDiff) <= maxUlpDiff;\n\
    \    }\n\n#if defined(CATCH_CONFIG_GLOBAL_NEXTAFTER)\n\n    float nextafter(float\
    \ x, float y) {\n        return ::nextafterf(x, y);\n    }\n\n    double nextafter(double\
    \ x, double y) {\n        return ::nextafter(x, y);\n    }\n\n#endif // ^^^ CATCH_CONFIG_GLOBAL_NEXTAFTER\
    \ ^^^\n\ntemplate <typename FP>\nFP step(FP start, FP direction, uint64_t steps)\
    \ {\n    for (uint64_t i = 0; i < steps; ++i) {\n#if defined(CATCH_CONFIG_GLOBAL_NEXTAFTER)\n\
    \        start = Catch::nextafter(start, direction);\n#else\n        start = std::nextafter(start,\
    \ direction);\n#endif\n    }\n    return start;\n}\n\n// Performs equivalent check\
    \ of std::fabs(lhs - rhs) <= margin\n// But without the subtraction to allow for\
    \ INFINITY in comparison\nbool marginComparison(double lhs, double rhs, double\
    \ margin) {\n    return (lhs + margin >= rhs) && (rhs + margin >= lhs);\n}\n\n\
    template <typename FloatingPoint>\nvoid write(std::ostream& out, FloatingPoint\
    \ num) {\n    out << std::scientific\n        << std::setprecision(std::numeric_limits<FloatingPoint>::max_digits10\
    \ - 1)\n        << num;\n}\n\n} // end anonymous namespace\n\nnamespace Matchers\
    \ {\nnamespace Floating {\n\n    enum class FloatingPointKind : uint8_t {\n  \
    \      Float,\n        Double\n    };\n\n    WithinAbsMatcher::WithinAbsMatcher(double\
    \ target, double margin)\n        :m_target{ target }, m_margin{ margin } {\n\
    \        CATCH_ENFORCE(margin >= 0, \"Invalid margin: \" << margin << '.'\n  \
    \          << \" Margin has to be non-negative.\");\n    }\n\n    // Performs\
    \ equivalent check of std::fabs(lhs - rhs) <= margin\n    // But without the subtraction\
    \ to allow for INFINITY in comparison\n    bool WithinAbsMatcher::match(double\
    \ const& matchee) const {\n        return (matchee + m_margin >= m_target) &&\
    \ (m_target + m_margin >= matchee);\n    }\n\n    std::string WithinAbsMatcher::describe()\
    \ const {\n        return \"is within \" + ::Catch::Detail::stringify(m_margin)\
    \ + \" of \" + ::Catch::Detail::stringify(m_target);\n    }\n\n    WithinUlpsMatcher::WithinUlpsMatcher(double\
    \ target, uint64_t ulps, FloatingPointKind baseType)\n        :m_target{ target\
    \ }, m_ulps{ ulps }, m_type{ baseType } {\n        CATCH_ENFORCE(m_type == FloatingPointKind::Double\n\
    \                   || m_ulps < (std::numeric_limits<uint32_t>::max)(),\n    \
    \        \"Provided ULP is impossibly large for a float comparison.\");\n    }\n\
    \n#if defined(__clang__)\n#pragma clang diagnostic push\n// Clang <3.5 reports\
    \ on the default branch in the switch below\n#pragma clang diagnostic ignored\
    \ \"-Wunreachable-code\"\n#endif\n\n    bool WithinUlpsMatcher::match(double const&\
    \ matchee) const {\n        switch (m_type) {\n        case FloatingPointKind::Float:\n\
    \            return almostEqualUlps<float>(static_cast<float>(matchee), static_cast<float>(m_target),\
    \ m_ulps);\n        case FloatingPointKind::Double:\n            return almostEqualUlps<double>(matchee,\
    \ m_target, m_ulps);\n        default:\n            CATCH_INTERNAL_ERROR( \"Unknown\
    \ FloatingPointKind value\" );\n        }\n    }\n\n#if defined(__clang__)\n#pragma\
    \ clang diagnostic pop\n#endif\n\n    std::string WithinUlpsMatcher::describe()\
    \ const {\n        std::stringstream ret;\n\n        ret << \"is within \" <<\
    \ m_ulps << \" ULPs of \";\n\n        if (m_type == FloatingPointKind::Float)\
    \ {\n            write(ret, static_cast<float>(m_target));\n            ret <<\
    \ 'f';\n        } else {\n            write(ret, m_target);\n        }\n\n   \
    \     ret << \" ([\";\n        if (m_type == FloatingPointKind::Double) {\n  \
    \          write(ret, step(m_target, static_cast<double>(-INFINITY), m_ulps));\n\
    \            ret << \", \";\n            write(ret, step(m_target, static_cast<double>(\
    \ INFINITY), m_ulps));\n        } else {\n            // We have to cast INFINITY\
    \ to float because of MinGW, see #1782\n            write(ret, step(static_cast<float>(m_target),\
    \ static_cast<float>(-INFINITY), m_ulps));\n            ret << \", \";\n     \
    \       write(ret, step(static_cast<float>(m_target), static_cast<float>( INFINITY),\
    \ m_ulps));\n        }\n        ret << \"])\";\n\n        return ret.str();\n\
    \    }\n\n    WithinRelMatcher::WithinRelMatcher(double target, double epsilon):\n\
    \        m_target(target),\n        m_epsilon(epsilon){\n        CATCH_ENFORCE(m_epsilon\
    \ >= 0., \"Relative comparison with epsilon <  0 does not make sense.\");\n  \
    \      CATCH_ENFORCE(m_epsilon  < 1., \"Relative comparison with epsilon >= 1\
    \ does not make sense.\");\n    }\n\n    bool WithinRelMatcher::match(double const&\
    \ matchee) const {\n        const auto relMargin = m_epsilon * (std::max)(std::fabs(matchee),\
    \ std::fabs(m_target));\n        return marginComparison(matchee, m_target,\n\
    \                                std::isinf(relMargin)? 0 : relMargin);\n    }\n\
    \n    std::string WithinRelMatcher::describe() const {\n        Catch::ReusableStringStream\
    \ sstr;\n        sstr << \"and \" << m_target << \" are within \" << m_epsilon\
    \ * 100. << \"% of each other\";\n        return sstr.str();\n    }\n\n}// namespace\
    \ Floating\n\nFloating::WithinUlpsMatcher WithinULP(double target, uint64_t maxUlpDiff)\
    \ {\n    return Floating::WithinUlpsMatcher(target, maxUlpDiff, Floating::FloatingPointKind::Double);\n\
    }\n\nFloating::WithinUlpsMatcher WithinULP(float target, uint64_t maxUlpDiff)\
    \ {\n    return Floating::WithinUlpsMatcher(target, maxUlpDiff, Floating::FloatingPointKind::Float);\n\
    }\n\nFloating::WithinAbsMatcher WithinAbs(double target, double margin) {\n  \
    \  return Floating::WithinAbsMatcher(target, margin);\n}\n\nFloating::WithinRelMatcher\
    \ WithinRel(double target, double eps) {\n    return Floating::WithinRelMatcher(target,\
    \ eps);\n}\n\nFloating::WithinRelMatcher WithinRel(double target) {\n    return\
    \ Floating::WithinRelMatcher(target, std::numeric_limits<double>::epsilon() *\
    \ 100);\n}\n\nFloating::WithinRelMatcher WithinRel(float target, float eps) {\n\
    \    return Floating::WithinRelMatcher(target, eps);\n}\n\nFloating::WithinRelMatcher\
    \ WithinRel(float target) {\n    return Floating::WithinRelMatcher(target, std::numeric_limits<float>::epsilon()\
    \ * 100);\n}\n\n} // namespace Matchers\n} // namespace Catch\n\n// end catch_matchers_floating.cpp\n\
    // start catch_matchers_generic.cpp\n\nstd::string Catch::Matchers::Generic::Detail::finalizeDescription(const\
    \ std::string& desc) {\n    if (desc.empty()) {\n        return \"matches undescribed\
    \ predicate\";\n    } else {\n        return \"matches predicate: \\\"\" + desc\
    \ + '\"';\n    }\n}\n// end catch_matchers_generic.cpp\n// start catch_matchers_string.cpp\n\
    \n#include <regex>\n\nnamespace Catch {\nnamespace Matchers {\n\n    namespace\
    \ StdString {\n\n        CasedString::CasedString( std::string const& str, CaseSensitive::Choice\
    \ caseSensitivity )\n        :   m_caseSensitivity( caseSensitivity ),\n     \
    \       m_str( adjustString( str ) )\n        {}\n        std::string CasedString::adjustString(\
    \ std::string const& str ) const {\n            return m_caseSensitivity == CaseSensitive::No\n\
    \                   ? toLower( str )\n                   : str;\n        }\n \
    \       std::string CasedString::caseSensitivitySuffix() const {\n           \
    \ return m_caseSensitivity == CaseSensitive::No\n                   ? \" (case\
    \ insensitive)\"\n                   : std::string();\n        }\n\n        StringMatcherBase::StringMatcherBase(\
    \ std::string const& operation, CasedString const& comparator )\n        : m_comparator(\
    \ comparator ),\n          m_operation( operation ) {\n        }\n\n        std::string\
    \ StringMatcherBase::describe() const {\n            std::string description;\n\
    \            description.reserve(5 + m_operation.size() + m_comparator.m_str.size()\
    \ +\n                                        m_comparator.caseSensitivitySuffix().size());\n\
    \            description += m_operation;\n            description += \": \\\"\"\
    ;\n            description += m_comparator.m_str;\n            description +=\
    \ \"\\\"\";\n            description += m_comparator.caseSensitivitySuffix();\n\
    \            return description;\n        }\n\n        EqualsMatcher::EqualsMatcher(\
    \ CasedString const& comparator ) : StringMatcherBase( \"equals\", comparator\
    \ ) {}\n\n        bool EqualsMatcher::match( std::string const& source ) const\
    \ {\n            return m_comparator.adjustString( source ) == m_comparator.m_str;\n\
    \        }\n\n        ContainsMatcher::ContainsMatcher( CasedString const& comparator\
    \ ) : StringMatcherBase( \"contains\", comparator ) {}\n\n        bool ContainsMatcher::match(\
    \ std::string const& source ) const {\n            return contains( m_comparator.adjustString(\
    \ source ), m_comparator.m_str );\n        }\n\n        StartsWithMatcher::StartsWithMatcher(\
    \ CasedString const& comparator ) : StringMatcherBase( \"starts with\", comparator\
    \ ) {}\n\n        bool StartsWithMatcher::match( std::string const& source ) const\
    \ {\n            return startsWith( m_comparator.adjustString( source ), m_comparator.m_str\
    \ );\n        }\n\n        EndsWithMatcher::EndsWithMatcher( CasedString const&\
    \ comparator ) : StringMatcherBase( \"ends with\", comparator ) {}\n\n       \
    \ bool EndsWithMatcher::match( std::string const& source ) const {\n         \
    \   return endsWith( m_comparator.adjustString( source ), m_comparator.m_str );\n\
    \        }\n\n        RegexMatcher::RegexMatcher(std::string regex, CaseSensitive::Choice\
    \ caseSensitivity): m_regex(std::move(regex)), m_caseSensitivity(caseSensitivity)\
    \ {}\n\n        bool RegexMatcher::match(std::string const& matchee) const {\n\
    \            auto flags = std::regex::ECMAScript; // ECMAScript is the default\
    \ syntax option anyway\n            if (m_caseSensitivity == CaseSensitive::Choice::No)\
    \ {\n                flags |= std::regex::icase;\n            }\n            auto\
    \ reg = std::regex(m_regex, flags);\n            return std::regex_match(matchee,\
    \ reg);\n        }\n\n        std::string RegexMatcher::describe() const {\n \
    \           return \"matches \" + ::Catch::Detail::stringify(m_regex) + ((m_caseSensitivity\
    \ == CaseSensitive::Choice::Yes)? \" case sensitively\" : \" case insensitively\"\
    );\n        }\n\n    } // namespace StdString\n\n    StdString::EqualsMatcher\
    \ Equals( std::string const& str, CaseSensitive::Choice caseSensitivity ) {\n\
    \        return StdString::EqualsMatcher( StdString::CasedString( str, caseSensitivity)\
    \ );\n    }\n    StdString::ContainsMatcher Contains( std::string const& str,\
    \ CaseSensitive::Choice caseSensitivity ) {\n        return StdString::ContainsMatcher(\
    \ StdString::CasedString( str, caseSensitivity) );\n    }\n    StdString::EndsWithMatcher\
    \ EndsWith( std::string const& str, CaseSensitive::Choice caseSensitivity ) {\n\
    \        return StdString::EndsWithMatcher( StdString::CasedString( str, caseSensitivity)\
    \ );\n    }\n    StdString::StartsWithMatcher StartsWith( std::string const& str,\
    \ CaseSensitive::Choice caseSensitivity ) {\n        return StdString::StartsWithMatcher(\
    \ StdString::CasedString( str, caseSensitivity) );\n    }\n\n    StdString::RegexMatcher\
    \ Matches(std::string const& regex, CaseSensitive::Choice caseSensitivity) {\n\
    \        return StdString::RegexMatcher(regex, caseSensitivity);\n    }\n\n} //\
    \ namespace Matchers\n} // namespace Catch\n// end catch_matchers_string.cpp\n\
    // start catch_message.cpp\n\n// start catch_uncaught_exceptions.h\n\nnamespace\
    \ Catch {\n    bool uncaught_exceptions();\n} // end namespace Catch\n\n// end\
    \ catch_uncaught_exceptions.h\n#include <cassert>\n#include <stack>\n\nnamespace\
    \ Catch {\n\n    MessageInfo::MessageInfo(   StringRef const& _macroName,\n  \
    \                              SourceLineInfo const& _lineInfo,\n            \
    \                    ResultWas::OfType _type )\n    :   macroName( _macroName\
    \ ),\n        lineInfo( _lineInfo ),\n        type( _type ),\n        sequence(\
    \ ++globalCount )\n    {}\n\n    bool MessageInfo::operator==( MessageInfo const&\
    \ other ) const {\n        return sequence == other.sequence;\n    }\n\n    bool\
    \ MessageInfo::operator<( MessageInfo const& other ) const {\n        return sequence\
    \ < other.sequence;\n    }\n\n    // This may need protecting if threading support\
    \ is added\n    unsigned int MessageInfo::globalCount = 0;\n\n    ////////////////////////////////////////////////////////////////////////////\n\
    \n    Catch::MessageBuilder::MessageBuilder( StringRef const& macroName,\n   \
    \                                        SourceLineInfo const& lineInfo,\n   \
    \                                        ResultWas::OfType type )\n        :m_info(macroName,\
    \ lineInfo, type) {}\n\n    ////////////////////////////////////////////////////////////////////////////\n\
    \n    ScopedMessage::ScopedMessage( MessageBuilder const& builder )\n    : m_info(\
    \ builder.m_info ), m_moved()\n    {\n        m_info.message = builder.m_stream.str();\n\
    \        getResultCapture().pushScopedMessage( m_info );\n    }\n\n    ScopedMessage::ScopedMessage(\
    \ ScopedMessage&& old )\n    : m_info( old.m_info ), m_moved()\n    {\n      \
    \  old.m_moved = true;\n    }\n\n    ScopedMessage::~ScopedMessage() {\n     \
    \   if ( !uncaught_exceptions() && !m_moved ){\n            getResultCapture().popScopedMessage(m_info);\n\
    \        }\n    }\n\n    Capturer::Capturer( StringRef macroName, SourceLineInfo\
    \ const& lineInfo, ResultWas::OfType resultType, StringRef names ) {\n       \
    \ auto trimmed = [&] (size_t start, size_t end) {\n            while (names[start]\
    \ == ',' || isspace(static_cast<unsigned char>(names[start]))) {\n           \
    \     ++start;\n            }\n            while (names[end] == ',' || isspace(static_cast<unsigned\
    \ char>(names[end]))) {\n                --end;\n            }\n            return\
    \ names.substr(start, end - start + 1);\n        };\n        auto skipq = [&]\
    \ (size_t start, char quote) {\n            for (auto i = start + 1; i < names.size()\
    \ ; ++i) {\n                if (names[i] == quote)\n                    return\
    \ i;\n                if (names[i] == '\\\\')\n                    ++i;\n    \
    \        }\n            CATCH_INTERNAL_ERROR(\"CAPTURE parsing encountered unmatched\
    \ quote\");\n        };\n\n        size_t start = 0;\n        std::stack<char>\
    \ openings;\n        for (size_t pos = 0; pos < names.size(); ++pos) {\n     \
    \       char c = names[pos];\n            switch (c) {\n            case '[':\n\
    \            case '{':\n            case '(':\n            // It is basically\
    \ impossible to disambiguate between\n            // comparison and start of template\
    \ args in this context\n//            case '<':\n                openings.push(c);\n\
    \                break;\n            case ']':\n            case '}':\n      \
    \      case ')':\n//           case '>':\n                openings.pop();\n  \
    \              break;\n            case '\"':\n            case '\\'':\n     \
    \           pos = skipq(pos, c);\n                break;\n            case ',':\n\
    \                if (start != pos && openings.empty()) {\n                   \
    \ m_messages.emplace_back(macroName, lineInfo, resultType);\n                \
    \    m_messages.back().message = static_cast<std::string>(trimmed(start, pos));\n\
    \                    m_messages.back().message += \" := \";\n                \
    \    start = pos;\n                }\n            }\n        }\n        assert(openings.empty()\
    \ && \"Mismatched openings\");\n        m_messages.emplace_back(macroName, lineInfo,\
    \ resultType);\n        m_messages.back().message = static_cast<std::string>(trimmed(start,\
    \ names.size() - 1));\n        m_messages.back().message += \" := \";\n    }\n\
    \    Capturer::~Capturer() {\n        if ( !uncaught_exceptions() ){\n       \
    \     assert( m_captured == m_messages.size() );\n            for( size_t i =\
    \ 0; i < m_captured; ++i  )\n                m_resultCapture.popScopedMessage(\
    \ m_messages[i] );\n        }\n    }\n\n    void Capturer::captureValue( size_t\
    \ index, std::string const& value ) {\n        assert( index < m_messages.size()\
    \ );\n        m_messages[index].message += value;\n        m_resultCapture.pushScopedMessage(\
    \ m_messages[index] );\n        m_captured++;\n    }\n\n} // end namespace Catch\n\
    // end catch_message.cpp\n// start catch_output_redirect.cpp\n\n// start catch_output_redirect.h\n\
    #ifndef TWOBLUECUBES_CATCH_OUTPUT_REDIRECT_H\n#define TWOBLUECUBES_CATCH_OUTPUT_REDIRECT_H\n\
    \n#include <cstdio>\n#include <iosfwd>\n#include <string>\n\nnamespace Catch {\n\
    \n    class RedirectedStream {\n        std::ostream& m_originalStream;\n    \
    \    std::ostream& m_redirectionStream;\n        std::streambuf* m_prevBuf;\n\n\
    \    public:\n        RedirectedStream( std::ostream& originalStream, std::ostream&\
    \ redirectionStream );\n        ~RedirectedStream();\n    };\n\n    class RedirectedStdOut\
    \ {\n        ReusableStringStream m_rss;\n        RedirectedStream m_cout;\n \
    \   public:\n        RedirectedStdOut();\n        auto str() const -> std::string;\n\
    \    };\n\n    // StdErr has two constituent streams in C++, std::cerr and std::clog\n\
    \    // This means that we need to redirect 2 streams into 1 to keep proper\n\
    \    // order of writes\n    class RedirectedStdErr {\n        ReusableStringStream\
    \ m_rss;\n        RedirectedStream m_cerr;\n        RedirectedStream m_clog;\n\
    \    public:\n        RedirectedStdErr();\n        auto str() const -> std::string;\n\
    \    };\n\n    class RedirectedStreams {\n    public:\n        RedirectedStreams(RedirectedStreams\
    \ const&) = delete;\n        RedirectedStreams& operator=(RedirectedStreams const&)\
    \ = delete;\n        RedirectedStreams(RedirectedStreams&&) = delete;\n      \
    \  RedirectedStreams& operator=(RedirectedStreams&&) = delete;\n\n        RedirectedStreams(std::string&\
    \ redirectedCout, std::string& redirectedCerr);\n        ~RedirectedStreams();\n\
    \    private:\n        std::string& m_redirectedCout;\n        std::string& m_redirectedCerr;\n\
    \        RedirectedStdOut m_redirectedStdOut;\n        RedirectedStdErr m_redirectedStdErr;\n\
    \    };\n\n#if defined(CATCH_CONFIG_NEW_CAPTURE)\n\n    // Windows's implementation\
    \ of std::tmpfile is terrible (it tries\n    // to create a file inside system\
    \ folder, thus requiring elevated\n    // privileges for the binary), so we have\
    \ to use tmpnam(_s) and\n    // create the file ourselves there.\n    class TempFile\
    \ {\n    public:\n        TempFile(TempFile const&) = delete;\n        TempFile&\
    \ operator=(TempFile const&) = delete;\n        TempFile(TempFile&&) = delete;\n\
    \        TempFile& operator=(TempFile&&) = delete;\n\n        TempFile();\n  \
    \      ~TempFile();\n\n        std::FILE* getFile();\n        std::string getContents();\n\
    \n    private:\n        std::FILE* m_file = nullptr;\n    #if defined(_MSC_VER)\n\
    \        char m_buffer[L_tmpnam] = { 0 };\n    #endif\n    };\n\n    class OutputRedirect\
    \ {\n    public:\n        OutputRedirect(OutputRedirect const&) = delete;\n  \
    \      OutputRedirect& operator=(OutputRedirect const&) = delete;\n        OutputRedirect(OutputRedirect&&)\
    \ = delete;\n        OutputRedirect& operator=(OutputRedirect&&) = delete;\n\n\
    \        OutputRedirect(std::string& stdout_dest, std::string& stderr_dest);\n\
    \        ~OutputRedirect();\n\n    private:\n        int m_originalStdout = -1;\n\
    \        int m_originalStderr = -1;\n        TempFile m_stdoutFile;\n        TempFile\
    \ m_stderrFile;\n        std::string& m_stdoutDest;\n        std::string& m_stderrDest;\n\
    \    };\n\n#endif\n\n} // end namespace Catch\n\n#endif // TWOBLUECUBES_CATCH_OUTPUT_REDIRECT_H\n\
    // end catch_output_redirect.h\n#include <cstdio>\n#include <cstring>\n#include\
    \ <fstream>\n#include <sstream>\n#include <stdexcept>\n\n#if defined(CATCH_CONFIG_NEW_CAPTURE)\n\
    \    #if defined(_MSC_VER)\n    #include <io.h>      //_dup and _dup2\n    #define\
    \ dup _dup\n    #define dup2 _dup2\n    #define fileno _fileno\n    #else\n  \
    \  #include <unistd.h>  // dup and dup2\n    #endif\n#endif\n\nnamespace Catch\
    \ {\n\n    RedirectedStream::RedirectedStream( std::ostream& originalStream, std::ostream&\
    \ redirectionStream )\n    :   m_originalStream( originalStream ),\n        m_redirectionStream(\
    \ redirectionStream ),\n        m_prevBuf( m_originalStream.rdbuf() )\n    {\n\
    \        m_originalStream.rdbuf( m_redirectionStream.rdbuf() );\n    }\n\n   \
    \ RedirectedStream::~RedirectedStream() {\n        m_originalStream.rdbuf( m_prevBuf\
    \ );\n    }\n\n    RedirectedStdOut::RedirectedStdOut() : m_cout( Catch::cout(),\
    \ m_rss.get() ) {}\n    auto RedirectedStdOut::str() const -> std::string { return\
    \ m_rss.str(); }\n\n    RedirectedStdErr::RedirectedStdErr()\n    :   m_cerr(\
    \ Catch::cerr(), m_rss.get() ),\n        m_clog( Catch::clog(), m_rss.get() )\n\
    \    {}\n    auto RedirectedStdErr::str() const -> std::string { return m_rss.str();\
    \ }\n\n    RedirectedStreams::RedirectedStreams(std::string& redirectedCout, std::string&\
    \ redirectedCerr)\n    :   m_redirectedCout(redirectedCout),\n        m_redirectedCerr(redirectedCerr)\n\
    \    {}\n\n    RedirectedStreams::~RedirectedStreams() {\n        m_redirectedCout\
    \ += m_redirectedStdOut.str();\n        m_redirectedCerr += m_redirectedStdErr.str();\n\
    \    }\n\n#if defined(CATCH_CONFIG_NEW_CAPTURE)\n\n#if defined(_MSC_VER)\n   \
    \ TempFile::TempFile() {\n        if (tmpnam_s(m_buffer)) {\n            CATCH_RUNTIME_ERROR(\"\
    Could not get a temp filename\");\n        }\n        if (fopen_s(&m_file, m_buffer,\
    \ \"w+\")) {\n            char buffer[100];\n            if (strerror_s(buffer,\
    \ errno)) {\n                CATCH_RUNTIME_ERROR(\"Could not translate errno to\
    \ a string\");\n            }\n            CATCH_RUNTIME_ERROR(\"Could not open\
    \ the temp file: '\" << m_buffer << \"' because: \" << buffer);\n        }\n \
    \   }\n#else\n    TempFile::TempFile() {\n        m_file = std::tmpfile();\n \
    \       if (!m_file) {\n            CATCH_RUNTIME_ERROR(\"Could not create a temp\
    \ file.\");\n        }\n    }\n\n#endif\n\n    TempFile::~TempFile() {\n     \
    \    // TBD: What to do about errors here?\n         std::fclose(m_file);\n  \
    \       // We manually create the file on Windows only, on Linux\n         //\
    \ it will be autodeleted\n#if defined(_MSC_VER)\n         std::remove(m_buffer);\n\
    #endif\n    }\n\n    FILE* TempFile::getFile() {\n        return m_file;\n   \
    \ }\n\n    std::string TempFile::getContents() {\n        std::stringstream sstr;\n\
    \        char buffer[100] = {};\n        std::rewind(m_file);\n        while (std::fgets(buffer,\
    \ sizeof(buffer), m_file)) {\n            sstr << buffer;\n        }\n       \
    \ return sstr.str();\n    }\n\n    OutputRedirect::OutputRedirect(std::string&\
    \ stdout_dest, std::string& stderr_dest) :\n        m_originalStdout(dup(1)),\n\
    \        m_originalStderr(dup(2)),\n        m_stdoutDest(stdout_dest),\n     \
    \   m_stderrDest(stderr_dest) {\n        dup2(fileno(m_stdoutFile.getFile()),\
    \ 1);\n        dup2(fileno(m_stderrFile.getFile()), 2);\n    }\n\n    OutputRedirect::~OutputRedirect()\
    \ {\n        Catch::cout() << std::flush;\n        fflush(stdout);\n        //\
    \ Since we support overriding these streams, we flush cerr\n        // even though\
    \ std::cerr is unbuffered\n        Catch::cerr() << std::flush;\n        Catch::clog()\
    \ << std::flush;\n        fflush(stderr);\n\n        dup2(m_originalStdout, 1);\n\
    \        dup2(m_originalStderr, 2);\n\n        m_stdoutDest += m_stdoutFile.getContents();\n\
    \        m_stderrDest += m_stderrFile.getContents();\n    }\n\n#endif // CATCH_CONFIG_NEW_CAPTURE\n\
    \n} // namespace Catch\n\n#if defined(CATCH_CONFIG_NEW_CAPTURE)\n    #if defined(_MSC_VER)\n\
    \    #undef dup\n    #undef dup2\n    #undef fileno\n    #endif\n#endif\n// end\
    \ catch_output_redirect.cpp\n// start catch_polyfills.cpp\n\n#include <cmath>\n\
    \nnamespace Catch {\n\n#if !defined(CATCH_CONFIG_POLYFILL_ISNAN)\n    bool isnan(float\
    \ f) {\n        return std::isnan(f);\n    }\n    bool isnan(double d) {\n   \
    \     return std::isnan(d);\n    }\n#else\n    // For now we only use this for\
    \ embarcadero\n    bool isnan(float f) {\n        return std::_isnan(f);\n   \
    \ }\n    bool isnan(double d) {\n        return std::_isnan(d);\n    }\n#endif\n\
    \n} // end namespace Catch\n// end catch_polyfills.cpp\n// start catch_random_number_generator.cpp\n\
    \nnamespace Catch {\n\nnamespace {\n\n#if defined(_MSC_VER)\n#pragma warning(push)\n\
    #pragma warning(disable:4146) // we negate uint32 during the rotate\n#endif\n\
    \        // Safe rotr implementation thanks to John Regehr\n        uint32_t rotate_right(uint32_t\
    \ val, uint32_t count) {\n            const uint32_t mask = 31;\n            count\
    \ &= mask;\n            return (val >> count) | (val << (-count & mask));\n  \
    \      }\n\n#if defined(_MSC_VER)\n#pragma warning(pop)\n#endif\n\n}\n\n    SimplePcg32::SimplePcg32(result_type\
    \ seed_) {\n        seed(seed_);\n    }\n\n    void SimplePcg32::seed(result_type\
    \ seed_) {\n        m_state = 0;\n        (*this)();\n        m_state += seed_;\n\
    \        (*this)();\n    }\n\n    void SimplePcg32::discard(uint64_t skip) {\n\
    \        // We could implement this to run in O(log n) steps, but this\n     \
    \   // should suffice for our use case.\n        for (uint64_t s = 0; s < skip;\
    \ ++s) {\n            static_cast<void>((*this)());\n        }\n    }\n\n    SimplePcg32::result_type\
    \ SimplePcg32::operator()() {\n        // prepare the output value\n        const\
    \ uint32_t xorshifted = static_cast<uint32_t>(((m_state >> 18u) ^ m_state) >>\
    \ 27u);\n        const auto output = rotate_right(xorshifted, m_state >> 59u);\n\
    \n        // advance state\n        m_state = m_state * 6364136223846793005ULL\
    \ + s_inc;\n\n        return output;\n    }\n\n    bool operator==(SimplePcg32\
    \ const& lhs, SimplePcg32 const& rhs) {\n        return lhs.m_state == rhs.m_state;\n\
    \    }\n\n    bool operator!=(SimplePcg32 const& lhs, SimplePcg32 const& rhs)\
    \ {\n        return lhs.m_state != rhs.m_state;\n    }\n}\n// end catch_random_number_generator.cpp\n\
    // start catch_registry_hub.cpp\n\n// start catch_test_case_registry_impl.h\n\n\
    #include <vector>\n#include <set>\n#include <algorithm>\n#include <ios>\n\nnamespace\
    \ Catch {\n\n    class TestCase;\n    struct IConfig;\n\n    std::vector<TestCase>\
    \ sortTests( IConfig const& config, std::vector<TestCase> const& unsortedTestCases\
    \ );\n\n    bool isThrowSafe( TestCase const& testCase, IConfig const& config\
    \ );\n    bool matchTest( TestCase const& testCase, TestSpec const& testSpec,\
    \ IConfig const& config );\n\n    void enforceNoDuplicateTestCases( std::vector<TestCase>\
    \ const& functions );\n\n    std::vector<TestCase> filterTests( std::vector<TestCase>\
    \ const& testCases, TestSpec const& testSpec, IConfig const& config );\n    std::vector<TestCase>\
    \ const& getAllTestCasesSorted( IConfig const& config );\n\n    class TestRegistry\
    \ : public ITestCaseRegistry {\n    public:\n        virtual ~TestRegistry() =\
    \ default;\n\n        virtual void registerTest( TestCase const& testCase );\n\
    \n        std::vector<TestCase> const& getAllTests() const override;\n       \
    \ std::vector<TestCase> const& getAllTestsSorted( IConfig const& config ) const\
    \ override;\n\n    private:\n        std::vector<TestCase> m_functions;\n    \
    \    mutable RunTests::InWhatOrder m_currentSortOrder = RunTests::InDeclarationOrder;\n\
    \        mutable std::vector<TestCase> m_sortedFunctions;\n        std::size_t\
    \ m_unnamedCount = 0;\n        std::ios_base::Init m_ostreamInit; // Forces cout/\
    \ cerr to be initialised\n    };\n\n    ///////////////////////////////////////////////////////////////////////////\n\
    \n    class TestInvokerAsFunction : public ITestInvoker {\n        void(*m_testAsFunction)();\n\
    \    public:\n        TestInvokerAsFunction( void(*testAsFunction)() ) noexcept;\n\
    \n        void invoke() const override;\n    };\n\n    std::string extractClassName(\
    \ StringRef const& classOrQualifiedMethodName );\n\n    ///////////////////////////////////////////////////////////////////////////\n\
    \n} // end namespace Catch\n\n// end catch_test_case_registry_impl.h\n// start\
    \ catch_reporter_registry.h\n\n#include <map>\n\nnamespace Catch {\n\n    class\
    \ ReporterRegistry : public IReporterRegistry {\n\n    public:\n\n        ~ReporterRegistry()\
    \ override;\n\n        IStreamingReporterPtr create( std::string const& name,\
    \ IConfigPtr const& config ) const override;\n\n        void registerReporter(\
    \ std::string const& name, IReporterFactoryPtr const& factory );\n        void\
    \ registerListener( IReporterFactoryPtr const& factory );\n\n        FactoryMap\
    \ const& getFactories() const override;\n        Listeners const& getListeners()\
    \ const override;\n\n    private:\n        FactoryMap m_factories;\n        Listeners\
    \ m_listeners;\n    };\n}\n\n// end catch_reporter_registry.h\n// start catch_tag_alias_registry.h\n\
    \n// start catch_tag_alias.h\n\n#include <string>\n\nnamespace Catch {\n\n   \
    \ struct TagAlias {\n        TagAlias(std::string const& _tag, SourceLineInfo\
    \ _lineInfo);\n\n        std::string tag;\n        SourceLineInfo lineInfo;\n\
    \    };\n\n} // end namespace Catch\n\n// end catch_tag_alias.h\n#include <map>\n\
    \nnamespace Catch {\n\n    class TagAliasRegistry : public ITagAliasRegistry {\n\
    \    public:\n        ~TagAliasRegistry() override;\n        TagAlias const* find(\
    \ std::string const& alias ) const override;\n        std::string expandAliases(\
    \ std::string const& unexpandedTestSpec ) const override;\n        void add( std::string\
    \ const& alias, std::string const& tag, SourceLineInfo const& lineInfo );\n\n\
    \    private:\n        std::map<std::string, TagAlias> m_registry;\n    };\n\n\
    } // end namespace Catch\n\n// end catch_tag_alias_registry.h\n// start catch_startup_exception_registry.h\n\
    \n#include <vector>\n#include <exception>\n\nnamespace Catch {\n\n    class StartupExceptionRegistry\
    \ {\n#if !defined(CATCH_CONFIG_DISABLE_EXCEPTIONS)\n    public:\n        void\
    \ add(std::exception_ptr const& exception) noexcept;\n        std::vector<std::exception_ptr>\
    \ const& getExceptions() const noexcept;\n    private:\n        std::vector<std::exception_ptr>\
    \ m_exceptions;\n#endif\n    };\n\n} // end namespace Catch\n\n// end catch_startup_exception_registry.h\n\
    // start catch_singletons.hpp\n\nnamespace Catch {\n\n    struct ISingleton {\n\
    \        virtual ~ISingleton();\n    };\n\n    void addSingleton( ISingleton*\
    \ singleton );\n    void cleanupSingletons();\n\n    template<typename SingletonImplT,\
    \ typename InterfaceT = SingletonImplT, typename MutableInterfaceT = InterfaceT>\n\
    \    class Singleton : SingletonImplT, public ISingleton {\n\n        static auto\
    \ getInternal() -> Singleton* {\n            static Singleton* s_instance = nullptr;\n\
    \            if( !s_instance ) {\n                s_instance = new Singleton;\n\
    \                addSingleton( s_instance );\n            }\n            return\
    \ s_instance;\n        }\n\n    public:\n        static auto get() -> InterfaceT\
    \ const& {\n            return *getInternal();\n        }\n        static auto\
    \ getMutable() -> MutableInterfaceT& {\n            return *getInternal();\n \
    \       }\n    };\n\n} // namespace Catch\n\n// end catch_singletons.hpp\nnamespace\
    \ Catch {\n\n    namespace {\n\n        class RegistryHub : public IRegistryHub,\
    \ public IMutableRegistryHub,\n                            private NonCopyable\
    \ {\n\n        public: // IRegistryHub\n            RegistryHub() = default;\n\
    \            IReporterRegistry const& getReporterRegistry() const override {\n\
    \                return m_reporterRegistry;\n            }\n            ITestCaseRegistry\
    \ const& getTestCaseRegistry() const override {\n                return m_testCaseRegistry;\n\
    \            }\n            IExceptionTranslatorRegistry const& getExceptionTranslatorRegistry()\
    \ const override {\n                return m_exceptionTranslatorRegistry;\n  \
    \          }\n            ITagAliasRegistry const& getTagAliasRegistry() const\
    \ override {\n                return m_tagAliasRegistry;\n            }\n    \
    \        StartupExceptionRegistry const& getStartupExceptionRegistry() const override\
    \ {\n                return m_exceptionRegistry;\n            }\n\n        public:\
    \ // IMutableRegistryHub\n            void registerReporter( std::string const&\
    \ name, IReporterFactoryPtr const& factory ) override {\n                m_reporterRegistry.registerReporter(\
    \ name, factory );\n            }\n            void registerListener( IReporterFactoryPtr\
    \ const& factory ) override {\n                m_reporterRegistry.registerListener(\
    \ factory );\n            }\n            void registerTest( TestCase const& testInfo\
    \ ) override {\n                m_testCaseRegistry.registerTest( testInfo );\n\
    \            }\n            void registerTranslator( const IExceptionTranslator*\
    \ translator ) override {\n                m_exceptionTranslatorRegistry.registerTranslator(\
    \ translator );\n            }\n            void registerTagAlias( std::string\
    \ const& alias, std::string const& tag, SourceLineInfo const& lineInfo ) override\
    \ {\n                m_tagAliasRegistry.add( alias, tag, lineInfo );\n       \
    \     }\n            void registerStartupException() noexcept override {\n#if\
    \ !defined(CATCH_CONFIG_DISABLE_EXCEPTIONS)\n                m_exceptionRegistry.add(std::current_exception());\n\
    #else\n                CATCH_INTERNAL_ERROR(\"Attempted to register active exception\
    \ under CATCH_CONFIG_DISABLE_EXCEPTIONS!\");\n#endif\n            }\n        \
    \    IMutableEnumValuesRegistry& getMutableEnumValuesRegistry() override {\n \
    \               return m_enumValuesRegistry;\n            }\n\n        private:\n\
    \            TestRegistry m_testCaseRegistry;\n            ReporterRegistry m_reporterRegistry;\n\
    \            ExceptionTranslatorRegistry m_exceptionTranslatorRegistry;\n    \
    \        TagAliasRegistry m_tagAliasRegistry;\n            StartupExceptionRegistry\
    \ m_exceptionRegistry;\n            Detail::EnumValuesRegistry m_enumValuesRegistry;\n\
    \        };\n    }\n\n    using RegistryHubSingleton = Singleton<RegistryHub,\
    \ IRegistryHub, IMutableRegistryHub>;\n\n    IRegistryHub const& getRegistryHub()\
    \ {\n        return RegistryHubSingleton::get();\n    }\n    IMutableRegistryHub&\
    \ getMutableRegistryHub() {\n        return RegistryHubSingleton::getMutable();\n\
    \    }\n    void cleanUp() {\n        cleanupSingletons();\n        cleanUpContext();\n\
    \    }\n    std::string translateActiveException() {\n        return getRegistryHub().getExceptionTranslatorRegistry().translateActiveException();\n\
    \    }\n\n} // end namespace Catch\n// end catch_registry_hub.cpp\n// start catch_reporter_registry.cpp\n\
    \nnamespace Catch {\n\n    ReporterRegistry::~ReporterRegistry() = default;\n\n\
    \    IStreamingReporterPtr ReporterRegistry::create( std::string const& name,\
    \ IConfigPtr const& config ) const {\n        auto it =  m_factories.find( name\
    \ );\n        if( it == m_factories.end() )\n            return nullptr;\n   \
    \     return it->second->create( ReporterConfig( config ) );\n    }\n\n    void\
    \ ReporterRegistry::registerReporter( std::string const& name, IReporterFactoryPtr\
    \ const& factory ) {\n        m_factories.emplace(name, factory);\n    }\n   \
    \ void ReporterRegistry::registerListener( IReporterFactoryPtr const& factory\
    \ ) {\n        m_listeners.push_back( factory );\n    }\n\n    IReporterRegistry::FactoryMap\
    \ const& ReporterRegistry::getFactories() const {\n        return m_factories;\n\
    \    }\n    IReporterRegistry::Listeners const& ReporterRegistry::getListeners()\
    \ const {\n        return m_listeners;\n    }\n\n}\n// end catch_reporter_registry.cpp\n\
    // start catch_result_type.cpp\n\nnamespace Catch {\n\n    bool isOk( ResultWas::OfType\
    \ resultType ) {\n        return ( resultType & ResultWas::FailureBit ) == 0;\n\
    \    }\n    bool isJustInfo( int flags ) {\n        return flags == ResultWas::Info;\n\
    \    }\n\n    ResultDisposition::Flags operator | ( ResultDisposition::Flags lhs,\
    \ ResultDisposition::Flags rhs ) {\n        return static_cast<ResultDisposition::Flags>(\
    \ static_cast<int>( lhs ) | static_cast<int>( rhs ) );\n    }\n\n    bool shouldContinueOnFailure(\
    \ int flags )    { return ( flags & ResultDisposition::ContinueOnFailure ) !=\
    \ 0; }\n    bool shouldSuppressFailure( int flags )      { return ( flags & ResultDisposition::SuppressFail\
    \ ) != 0; }\n\n} // end namespace Catch\n// end catch_result_type.cpp\n// start\
    \ catch_run_context.cpp\n\n#include <cassert>\n#include <algorithm>\n#include\
    \ <sstream>\n\nnamespace Catch {\n\n    namespace Generators {\n        struct\
    \ GeneratorTracker : TestCaseTracking::TrackerBase, IGeneratorTracker {\n    \
    \        GeneratorBasePtr m_generator;\n\n            GeneratorTracker( TestCaseTracking::NameAndLocation\
    \ const& nameAndLocation, TrackerContext& ctx, ITracker* parent )\n          \
    \  :   TrackerBase( nameAndLocation, ctx, parent )\n            {}\n         \
    \   ~GeneratorTracker();\n\n            static GeneratorTracker& acquire( TrackerContext&\
    \ ctx, TestCaseTracking::NameAndLocation const& nameAndLocation ) {\n        \
    \        std::shared_ptr<GeneratorTracker> tracker;\n\n                ITracker&\
    \ currentTracker = ctx.currentTracker();\n                // Under specific circumstances,\
    \ the generator we want\n                // to acquire is also the current tracker.\
    \ If this is\n                // the case, we have to avoid looking through current\n\
    \                // tracker's children, and instead return the current\n     \
    \           // tracker.\n                // A case where this check is important\
    \ is e.g.\n                //     for (int i = 0; i < 5; ++i) {\n            \
    \    //         int n = GENERATE(1, 2);\n                //     }\n          \
    \      //\n                // without it, the code above creates 5 nested generators.\n\
    \                if (currentTracker.nameAndLocation() == nameAndLocation) {\n\
    \                    auto thisTracker = currentTracker.parent().findChild(nameAndLocation);\n\
    \                    assert(thisTracker);\n                    assert(thisTracker->isGeneratorTracker());\n\
    \                    tracker = std::static_pointer_cast<GeneratorTracker>(thisTracker);\n\
    \                } else if ( TestCaseTracking::ITrackerPtr childTracker = currentTracker.findChild(\
    \ nameAndLocation ) ) {\n                    assert( childTracker );\n       \
    \             assert( childTracker->isGeneratorTracker() );\n                \
    \    tracker = std::static_pointer_cast<GeneratorTracker>( childTracker );\n \
    \               } else {\n                    tracker = std::make_shared<GeneratorTracker>(\
    \ nameAndLocation, ctx, &currentTracker );\n                    currentTracker.addChild(\
    \ tracker );\n                }\n\n                if( !tracker->isComplete()\
    \ ) {\n                    tracker->open();\n                }\n\n           \
    \     return *tracker;\n            }\n\n            // TrackerBase interface\n\
    \            bool isGeneratorTracker() const override { return true; }\n     \
    \       auto hasGenerator() const -> bool override {\n                return !!m_generator;\n\
    \            }\n            void close() override {\n                TrackerBase::close();\n\
    \                // If a generator has a child (it is followed by a section)\n\
    \                // and none of its children have started, then we must wait\n\
    \                // until later to start consuming its values.\n             \
    \   // This catches cases where `GENERATE` is placed between two\n           \
    \     // `SECTION`s.\n                // **The check for m_children.empty cannot\
    \ be removed**.\n                // doing so would break `GENERATE` _not_ followed\
    \ by `SECTION`s.\n                const bool should_wait_for_child =\n       \
    \             !m_children.empty() &&\n                    std::find_if( m_children.begin(),\n\
    \                                  m_children.end(),\n                       \
    \           []( TestCaseTracking::ITrackerPtr tracker ) {\n                  \
    \                    return tracker->hasStarted();\n                         \
    \         } ) == m_children.end();\n\n                // This check is a bit tricky,\
    \ because m_generator->next()\n                // has a side-effect, where it\
    \ consumes generator's current\n                // value, but we do not want to\
    \ invoke the side-effect if\n                // this generator is still waiting\
    \ for any child to start.\n                if ( should_wait_for_child ||\n   \
    \                  ( m_runState == CompletedSuccessfully &&\n                \
    \       m_generator->next() ) ) {\n                    m_children.clear();\n \
    \                   m_runState = Executing;\n                }\n            }\n\
    \n            // IGeneratorTracker interface\n            auto getGenerator()\
    \ const -> GeneratorBasePtr const& override {\n                return m_generator;\n\
    \            }\n            void setGenerator( GeneratorBasePtr&& generator )\
    \ override {\n                m_generator = std::move( generator );\n        \
    \    }\n        };\n        GeneratorTracker::~GeneratorTracker() {}\n    }\n\n\
    \    RunContext::RunContext(IConfigPtr const& _config, IStreamingReporterPtr&&\
    \ reporter)\n    :   m_runInfo(_config->name()),\n        m_context(getCurrentMutableContext()),\n\
    \        m_config(_config),\n        m_reporter(std::move(reporter)),\n      \
    \  m_lastAssertionInfo{ StringRef(), SourceLineInfo(\"\",0), StringRef(), ResultDisposition::Normal\
    \ },\n        m_includeSuccessfulResults( m_config->includeSuccessfulResults()\
    \ || m_reporter->getPreferences().shouldReportAllAssertions )\n    {\n       \
    \ m_context.setRunner(this);\n        m_context.setConfig(m_config);\n       \
    \ m_context.setResultCapture(this);\n        m_reporter->testRunStarting(m_runInfo);\n\
    \    }\n\n    RunContext::~RunContext() {\n        m_reporter->testRunEnded(TestRunStats(m_runInfo,\
    \ m_totals, aborting()));\n    }\n\n    void RunContext::testGroupStarting(std::string\
    \ const& testSpec, std::size_t groupIndex, std::size_t groupsCount) {\n      \
    \  m_reporter->testGroupStarting(GroupInfo(testSpec, groupIndex, groupsCount));\n\
    \    }\n\n    void RunContext::testGroupEnded(std::string const& testSpec, Totals\
    \ const& totals, std::size_t groupIndex, std::size_t groupsCount) {\n        m_reporter->testGroupEnded(TestGroupStats(GroupInfo(testSpec,\
    \ groupIndex, groupsCount), totals, aborting()));\n    }\n\n    Totals RunContext::runTest(TestCase\
    \ const& testCase) {\n        Totals prevTotals = m_totals;\n\n        std::string\
    \ redirectedCout;\n        std::string redirectedCerr;\n\n        auto const&\
    \ testInfo = testCase.getTestCaseInfo();\n\n        m_reporter->testCaseStarting(testInfo);\n\
    \n        m_activeTestCase = &testCase;\n\n        ITracker& rootTracker = m_trackerContext.startRun();\n\
    \        assert(rootTracker.isSectionTracker());\n        static_cast<SectionTracker&>(rootTracker).addInitialFilters(m_config->getSectionsToRun());\n\
    \        do {\n            m_trackerContext.startCycle();\n            m_testCaseTracker\
    \ = &SectionTracker::acquire(m_trackerContext, TestCaseTracking::NameAndLocation(testInfo.name,\
    \ testInfo.lineInfo));\n            runCurrentTest(redirectedCout, redirectedCerr);\n\
    \        } while (!m_testCaseTracker->isSuccessfullyCompleted() && !aborting());\n\
    \n        Totals deltaTotals = m_totals.delta(prevTotals);\n        if (testInfo.expectedToFail()\
    \ && deltaTotals.testCases.passed > 0) {\n            deltaTotals.assertions.failed++;\n\
    \            deltaTotals.testCases.passed--;\n            deltaTotals.testCases.failed++;\n\
    \        }\n        m_totals.testCases += deltaTotals.testCases;\n        m_reporter->testCaseEnded(TestCaseStats(testInfo,\n\
    \                                  deltaTotals,\n                            \
    \      redirectedCout,\n                                  redirectedCerr,\n  \
    \                                aborting()));\n\n        m_activeTestCase = nullptr;\n\
    \        m_testCaseTracker = nullptr;\n\n        return deltaTotals;\n    }\n\n\
    \    IConfigPtr RunContext::config() const {\n        return m_config;\n    }\n\
    \n    IStreamingReporter& RunContext::reporter() const {\n        return *m_reporter;\n\
    \    }\n\n    void RunContext::assertionEnded(AssertionResult const & result)\
    \ {\n        if (result.getResultType() == ResultWas::Ok) {\n            m_totals.assertions.passed++;\n\
    \            m_lastAssertionPassed = true;\n        } else if (!result.isOk())\
    \ {\n            m_lastAssertionPassed = false;\n            if( m_activeTestCase->getTestCaseInfo().okToFail()\
    \ )\n                m_totals.assertions.failedButOk++;\n            else\n  \
    \              m_totals.assertions.failed++;\n        }\n        else {\n    \
    \        m_lastAssertionPassed = true;\n        }\n\n        // We have no use\
    \ for the return value (whether messages should be cleared), because messages\
    \ were made scoped\n        // and should be let to clear themselves out.\n  \
    \      static_cast<void>(m_reporter->assertionEnded(AssertionStats(result, m_messages,\
    \ m_totals)));\n\n        if (result.getResultType() != ResultWas::Warning)\n\
    \            m_messageScopes.clear();\n\n        // Reset working state\n    \
    \    resetAssertionInfo();\n        m_lastResult = result;\n    }\n    void RunContext::resetAssertionInfo()\
    \ {\n        m_lastAssertionInfo.macroName = StringRef();\n        m_lastAssertionInfo.capturedExpression\
    \ = \"{Unknown expression after the reported line}\"_sr;\n    }\n\n    bool RunContext::sectionStarted(SectionInfo\
    \ const & sectionInfo, Counts & assertions) {\n        ITracker& sectionTracker\
    \ = SectionTracker::acquire(m_trackerContext, TestCaseTracking::NameAndLocation(sectionInfo.name,\
    \ sectionInfo.lineInfo));\n        if (!sectionTracker.isOpen())\n           \
    \ return false;\n        m_activeSections.push_back(&sectionTracker);\n\n    \
    \    m_lastAssertionInfo.lineInfo = sectionInfo.lineInfo;\n\n        m_reporter->sectionStarting(sectionInfo);\n\
    \n        assertions = m_totals.assertions;\n\n        return true;\n    }\n \
    \   auto RunContext::acquireGeneratorTracker( StringRef generatorName, SourceLineInfo\
    \ const& lineInfo ) -> IGeneratorTracker& {\n        using namespace Generators;\n\
    \        GeneratorTracker& tracker = GeneratorTracker::acquire(m_trackerContext,\n\
    \                                                              TestCaseTracking::NameAndLocation(\
    \ static_cast<std::string>(generatorName), lineInfo ) );\n        m_lastAssertionInfo.lineInfo\
    \ = lineInfo;\n        return tracker;\n    }\n\n    bool RunContext::testForMissingAssertions(Counts&\
    \ assertions) {\n        if (assertions.total() != 0)\n            return false;\n\
    \        if (!m_config->warnAboutMissingAssertions())\n            return false;\n\
    \        if (m_trackerContext.currentTracker().hasChildren())\n            return\
    \ false;\n        m_totals.assertions.failed++;\n        assertions.failed++;\n\
    \        return true;\n    }\n\n    void RunContext::sectionEnded(SectionEndInfo\
    \ const & endInfo) {\n        Counts assertions = m_totals.assertions - endInfo.prevAssertions;\n\
    \        bool missingAssertions = testForMissingAssertions(assertions);\n\n  \
    \      if (!m_activeSections.empty()) {\n            m_activeSections.back()->close();\n\
    \            m_activeSections.pop_back();\n        }\n\n        m_reporter->sectionEnded(SectionStats(endInfo.sectionInfo,\
    \ assertions, endInfo.durationInSeconds, missingAssertions));\n        m_messages.clear();\n\
    \        m_messageScopes.clear();\n    }\n\n    void RunContext::sectionEndedEarly(SectionEndInfo\
    \ const & endInfo) {\n        if (m_unfinishedSections.empty())\n            m_activeSections.back()->fail();\n\
    \        else\n            m_activeSections.back()->close();\n        m_activeSections.pop_back();\n\
    \n        m_unfinishedSections.push_back(endInfo);\n    }\n\n#if defined(CATCH_CONFIG_ENABLE_BENCHMARKING)\n\
    \    void RunContext::benchmarkPreparing(std::string const& name) {\n        m_reporter->benchmarkPreparing(name);\n\
    \    }\n    void RunContext::benchmarkStarting( BenchmarkInfo const& info ) {\n\
    \        m_reporter->benchmarkStarting( info );\n    }\n    void RunContext::benchmarkEnded(\
    \ BenchmarkStats<> const& stats ) {\n        m_reporter->benchmarkEnded( stats\
    \ );\n    }\n    void RunContext::benchmarkFailed(std::string const & error) {\n\
    \        m_reporter->benchmarkFailed(error);\n    }\n#endif // CATCH_CONFIG_ENABLE_BENCHMARKING\n\
    \n    void RunContext::pushScopedMessage(MessageInfo const & message) {\n    \
    \    m_messages.push_back(message);\n    }\n\n    void RunContext::popScopedMessage(MessageInfo\
    \ const & message) {\n        m_messages.erase(std::remove(m_messages.begin(),\
    \ m_messages.end(), message), m_messages.end());\n    }\n\n    void RunContext::emplaceUnscopedMessage(\
    \ MessageBuilder const& builder ) {\n        m_messageScopes.emplace_back( builder\
    \ );\n    }\n\n    std::string RunContext::getCurrentTestName() const {\n    \
    \    return m_activeTestCase\n            ? m_activeTestCase->getTestCaseInfo().name\n\
    \            : std::string();\n    }\n\n    const AssertionResult * RunContext::getLastResult()\
    \ const {\n        return &(*m_lastResult);\n    }\n\n    void RunContext::exceptionEarlyReported()\
    \ {\n        m_shouldReportUnexpected = false;\n    }\n\n    void RunContext::handleFatalErrorCondition(\
    \ StringRef message ) {\n        // First notify reporter that bad things happened\n\
    \        m_reporter->fatalErrorEncountered(message);\n\n        // Don't rebuild\
    \ the result -- the stringification itself can cause more fatal errors\n     \
    \   // Instead, fake a result data.\n        AssertionResultData tempResult( ResultWas::FatalErrorCondition,\
    \ { false } );\n        tempResult.message = static_cast<std::string>(message);\n\
    \        AssertionResult result(m_lastAssertionInfo, tempResult);\n\n        assertionEnded(result);\n\
    \n        handleUnfinishedSections();\n\n        // Recreate section for test\
    \ case (as we will lose the one that was in scope)\n        auto const& testCaseInfo\
    \ = m_activeTestCase->getTestCaseInfo();\n        SectionInfo testCaseSection(testCaseInfo.lineInfo,\
    \ testCaseInfo.name);\n\n        Counts assertions;\n        assertions.failed\
    \ = 1;\n        SectionStats testCaseSectionStats(testCaseSection, assertions,\
    \ 0, false);\n        m_reporter->sectionEnded(testCaseSectionStats);\n\n    \
    \    auto const& testInfo = m_activeTestCase->getTestCaseInfo();\n\n        Totals\
    \ deltaTotals;\n        deltaTotals.testCases.failed = 1;\n        deltaTotals.assertions.failed\
    \ = 1;\n        m_reporter->testCaseEnded(TestCaseStats(testInfo,\n          \
    \                        deltaTotals,\n                                  std::string(),\n\
    \                                  std::string(),\n                          \
    \        false));\n        m_totals.testCases.failed++;\n        testGroupEnded(std::string(),\
    \ m_totals, 1, 1);\n        m_reporter->testRunEnded(TestRunStats(m_runInfo, m_totals,\
    \ false));\n    }\n\n    bool RunContext::lastAssertionPassed() {\n         return\
    \ m_lastAssertionPassed;\n    }\n\n    void RunContext::assertionPassed() {\n\
    \        m_lastAssertionPassed = true;\n        ++m_totals.assertions.passed;\n\
    \        resetAssertionInfo();\n        m_messageScopes.clear();\n    }\n\n  \
    \  bool RunContext::aborting() const {\n        return m_totals.assertions.failed\
    \ >= static_cast<std::size_t>(m_config->abortAfter());\n    }\n\n    void RunContext::runCurrentTest(std::string\
    \ & redirectedCout, std::string & redirectedCerr) {\n        auto const& testCaseInfo\
    \ = m_activeTestCase->getTestCaseInfo();\n        SectionInfo testCaseSection(testCaseInfo.lineInfo,\
    \ testCaseInfo.name);\n        m_reporter->sectionStarting(testCaseSection);\n\
    \        Counts prevAssertions = m_totals.assertions;\n        double duration\
    \ = 0;\n        m_shouldReportUnexpected = true;\n        m_lastAssertionInfo\
    \ = { \"TEST_CASE\"_sr, testCaseInfo.lineInfo, StringRef(), ResultDisposition::Normal\
    \ };\n\n        seedRng(*m_config);\n\n        Timer timer;\n        CATCH_TRY\
    \ {\n            if (m_reporter->getPreferences().shouldRedirectStdOut) {\n#if\
    \ !defined(CATCH_CONFIG_EXPERIMENTAL_REDIRECT)\n                RedirectedStreams\
    \ redirectedStreams(redirectedCout, redirectedCerr);\n\n                timer.start();\n\
    \                invokeActiveTestCase();\n#else\n                OutputRedirect\
    \ r(redirectedCout, redirectedCerr);\n                timer.start();\n       \
    \         invokeActiveTestCase();\n#endif\n            } else {\n            \
    \    timer.start();\n                invokeActiveTestCase();\n            }\n\
    \            duration = timer.getElapsedSeconds();\n        } CATCH_CATCH_ANON\
    \ (TestFailureException&) {\n            // This just means the test was aborted\
    \ due to failure\n        } CATCH_CATCH_ALL {\n            // Under CATCH_CONFIG_FAST_COMPILE,\
    \ unexpected exceptions under REQUIRE assertions\n            // are reported\
    \ without translation at the point of origin.\n            if( m_shouldReportUnexpected\
    \ ) {\n                AssertionReaction dummyReaction;\n                handleUnexpectedInflightException(\
    \ m_lastAssertionInfo, translateActiveException(), dummyReaction );\n        \
    \    }\n        }\n        Counts assertions = m_totals.assertions - prevAssertions;\n\
    \        bool missingAssertions = testForMissingAssertions(assertions);\n\n  \
    \      m_testCaseTracker->close();\n        handleUnfinishedSections();\n    \
    \    m_messages.clear();\n        m_messageScopes.clear();\n\n        SectionStats\
    \ testCaseSectionStats(testCaseSection, assertions, duration, missingAssertions);\n\
    \        m_reporter->sectionEnded(testCaseSectionStats);\n    }\n\n    void RunContext::invokeActiveTestCase()\
    \ {\n        FatalConditionHandler fatalConditionHandler; // Handle signals\n\
    \        m_activeTestCase->invoke();\n        fatalConditionHandler.reset();\n\
    \    }\n\n    void RunContext::handleUnfinishedSections() {\n        // If sections\
    \ ended prematurely due to an exception we stored their\n        // infos here\
    \ so we can tear them down outside the unwind process.\n        for (auto it =\
    \ m_unfinishedSections.rbegin(),\n             itEnd = m_unfinishedSections.rend();\n\
    \             it != itEnd;\n             ++it)\n            sectionEnded(*it);\n\
    \        m_unfinishedSections.clear();\n    }\n\n    void RunContext::handleExpr(\n\
    \        AssertionInfo const& info,\n        ITransientExpression const& expr,\n\
    \        AssertionReaction& reaction\n    ) {\n        m_reporter->assertionStarting(\
    \ info );\n\n        bool negated = isFalseTest( info.resultDisposition );\n \
    \       bool result = expr.getResult() != negated;\n\n        if( result ) {\n\
    \            if (!m_includeSuccessfulResults) {\n                assertionPassed();\n\
    \            }\n            else {\n                reportExpr(info, ResultWas::Ok,\
    \ &expr, negated);\n            }\n        }\n        else {\n            reportExpr(info,\
    \ ResultWas::ExpressionFailed, &expr, negated );\n            populateReaction(\
    \ reaction );\n        }\n    }\n    void RunContext::reportExpr(\n          \
    \  AssertionInfo const &info,\n            ResultWas::OfType resultType,\n   \
    \         ITransientExpression const *expr,\n            bool negated ) {\n\n\
    \        m_lastAssertionInfo = info;\n        AssertionResultData data( resultType,\
    \ LazyExpression( negated ) );\n\n        AssertionResult assertionResult{ info,\
    \ data };\n        assertionResult.m_resultData.lazyExpression.m_transientExpression\
    \ = expr;\n\n        assertionEnded( assertionResult );\n    }\n\n    void RunContext::handleMessage(\n\
    \            AssertionInfo const& info,\n            ResultWas::OfType resultType,\n\
    \            StringRef const& message,\n            AssertionReaction& reaction\n\
    \    ) {\n        m_reporter->assertionStarting( info );\n\n        m_lastAssertionInfo\
    \ = info;\n\n        AssertionResultData data( resultType, LazyExpression( false\
    \ ) );\n        data.message = static_cast<std::string>(message);\n        AssertionResult\
    \ assertionResult{ m_lastAssertionInfo, data };\n        assertionEnded( assertionResult\
    \ );\n        if( !assertionResult.isOk() )\n            populateReaction( reaction\
    \ );\n    }\n    void RunContext::handleUnexpectedExceptionNotThrown(\n      \
    \      AssertionInfo const& info,\n            AssertionReaction& reaction\n \
    \   ) {\n        handleNonExpr(info, Catch::ResultWas::DidntThrowException, reaction);\n\
    \    }\n\n    void RunContext::handleUnexpectedInflightException(\n          \
    \  AssertionInfo const& info,\n            std::string const& message,\n     \
    \       AssertionReaction& reaction\n    ) {\n        m_lastAssertionInfo = info;\n\
    \n        AssertionResultData data( ResultWas::ThrewException, LazyExpression(\
    \ false ) );\n        data.message = message;\n        AssertionResult assertionResult{\
    \ info, data };\n        assertionEnded( assertionResult );\n        populateReaction(\
    \ reaction );\n    }\n\n    void RunContext::populateReaction( AssertionReaction&\
    \ reaction ) {\n        reaction.shouldDebugBreak = m_config->shouldDebugBreak();\n\
    \        reaction.shouldThrow = aborting() || (m_lastAssertionInfo.resultDisposition\
    \ & ResultDisposition::Normal);\n    }\n\n    void RunContext::handleIncomplete(\n\
    \            AssertionInfo const& info\n    ) {\n        m_lastAssertionInfo =\
    \ info;\n\n        AssertionResultData data( ResultWas::ThrewException, LazyExpression(\
    \ false ) );\n        data.message = \"Exception translation was disabled by CATCH_CONFIG_FAST_COMPILE\"\
    ;\n        AssertionResult assertionResult{ info, data };\n        assertionEnded(\
    \ assertionResult );\n    }\n    void RunContext::handleNonExpr(\n           \
    \ AssertionInfo const &info,\n            ResultWas::OfType resultType,\n    \
    \        AssertionReaction &reaction\n    ) {\n        m_lastAssertionInfo = info;\n\
    \n        AssertionResultData data( resultType, LazyExpression( false ) );\n \
    \       AssertionResult assertionResult{ info, data };\n        assertionEnded(\
    \ assertionResult );\n\n        if( !assertionResult.isOk() )\n            populateReaction(\
    \ reaction );\n    }\n\n    IResultCapture& getResultCapture() {\n        if (auto*\
    \ capture = getCurrentContext().getResultCapture())\n            return *capture;\n\
    \        else\n            CATCH_INTERNAL_ERROR(\"No result capture instance\"\
    );\n    }\n\n    void seedRng(IConfig const& config) {\n        if (config.rngSeed()\
    \ != 0) {\n            std::srand(config.rngSeed());\n            rng().seed(config.rngSeed());\n\
    \        }\n    }\n\n    unsigned int rngSeed() {\n        return getCurrentContext().getConfig()->rngSeed();\n\
    \    }\n\n}\n// end catch_run_context.cpp\n// start catch_section.cpp\n\nnamespace\
    \ Catch {\n\n    Section::Section( SectionInfo const& info )\n    :   m_info(\
    \ info ),\n        m_sectionIncluded( getResultCapture().sectionStarted( m_info,\
    \ m_assertions ) )\n    {\n        m_timer.start();\n    }\n\n    Section::~Section()\
    \ {\n        if( m_sectionIncluded ) {\n            SectionEndInfo endInfo{ m_info,\
    \ m_assertions, m_timer.getElapsedSeconds() };\n            if( uncaught_exceptions()\
    \ )\n                getResultCapture().sectionEndedEarly( endInfo );\n      \
    \      else\n                getResultCapture().sectionEnded( endInfo );\n   \
    \     }\n    }\n\n    // This indicates whether the section should be executed\
    \ or not\n    Section::operator bool() const {\n        return m_sectionIncluded;\n\
    \    }\n\n} // end namespace Catch\n// end catch_section.cpp\n// start catch_section_info.cpp\n\
    \nnamespace Catch {\n\n    SectionInfo::SectionInfo\n        (   SourceLineInfo\
    \ const& _lineInfo,\n            std::string const& _name )\n    :   name( _name\
    \ ),\n        lineInfo( _lineInfo )\n    {}\n\n} // end namespace Catch\n// end\
    \ catch_section_info.cpp\n// start catch_session.cpp\n\n// start catch_session.h\n\
    \n#include <memory>\n\nnamespace Catch {\n\n    class Session : NonCopyable {\n\
    \    public:\n\n        Session();\n        ~Session() override;\n\n        void\
    \ showHelp() const;\n        void libIdentify();\n\n        int applyCommandLine(\
    \ int argc, char const * const * argv );\n    #if defined(CATCH_CONFIG_WCHAR)\
    \ && defined(_WIN32) && defined(UNICODE)\n        int applyCommandLine( int argc,\
    \ wchar_t const * const * argv );\n    #endif\n\n        void useConfigData( ConfigData\
    \ const& configData );\n\n        template<typename CharT>\n        int run(int\
    \ argc, CharT const * const argv[]) {\n            if (m_startupExceptions)\n\
    \                return 1;\n            int returnCode = applyCommandLine(argc,\
    \ argv);\n            if (returnCode == 0)\n                returnCode = run();\n\
    \            return returnCode;\n        }\n\n        int run();\n\n        clara::Parser\
    \ const& cli() const;\n        void cli( clara::Parser const& newParser );\n \
    \       ConfigData& configData();\n        Config& config();\n    private:\n \
    \       int runInternal();\n\n        clara::Parser m_cli;\n        ConfigData\
    \ m_configData;\n        std::shared_ptr<Config> m_config;\n        bool m_startupExceptions\
    \ = false;\n    };\n\n} // end namespace Catch\n\n// end catch_session.h\n// start\
    \ catch_version.h\n\n#include <iosfwd>\n\nnamespace Catch {\n\n    // Versioning\
    \ information\n    struct Version {\n        Version( Version const& ) = delete;\n\
    \        Version& operator=( Version const& ) = delete;\n        Version(    unsigned\
    \ int _majorVersion,\n                    unsigned int _minorVersion,\n      \
    \              unsigned int _patchNumber,\n                    char const * const\
    \ _branchName,\n                    unsigned int _buildNumber );\n\n        unsigned\
    \ int const majorVersion;\n        unsigned int const minorVersion;\n        unsigned\
    \ int const patchNumber;\n\n        // buildNumber is only used if branchName\
    \ is not null\n        char const * const branchName;\n        unsigned int const\
    \ buildNumber;\n\n        friend std::ostream& operator << ( std::ostream& os,\
    \ Version const& version );\n    };\n\n    Version const& libraryVersion();\n\
    }\n\n// end catch_version.h\n#include <cstdlib>\n#include <iomanip>\n#include\
    \ <set>\n#include <iterator>\n\nnamespace Catch {\n\n    namespace {\n       \
    \ const int MaxExitCode = 255;\n\n        IStreamingReporterPtr createReporter(std::string\
    \ const& reporterName, IConfigPtr const& config) {\n            auto reporter\
    \ = Catch::getRegistryHub().getReporterRegistry().create(reporterName, config);\n\
    \            CATCH_ENFORCE(reporter, \"No reporter registered with name: '\" <<\
    \ reporterName << \"'\");\n\n            return reporter;\n        }\n\n     \
    \   IStreamingReporterPtr makeReporter(std::shared_ptr<Config> const& config)\
    \ {\n            if (Catch::getRegistryHub().getReporterRegistry().getListeners().empty())\
    \ {\n                return createReporter(config->getReporterName(), config);\n\
    \            }\n\n            // On older platforms, returning std::unique_ptr<ListeningReporter>\n\
    \            // when the return type is std::unique_ptr<IStreamingReporter>\n\
    \            // doesn't compile without a std::move call. However, this causes\n\
    \            // a warning on newer platforms. Thus, we have to work around\n \
    \           // it a bit and downcast the pointer manually.\n            auto ret\
    \ = std::unique_ptr<IStreamingReporter>(new ListeningReporter);\n            auto&\
    \ multi = static_cast<ListeningReporter&>(*ret);\n            auto const& listeners\
    \ = Catch::getRegistryHub().getReporterRegistry().getListeners();\n          \
    \  for (auto const& listener : listeners) {\n                multi.addListener(listener->create(Catch::ReporterConfig(config)));\n\
    \            }\n            multi.addReporter(createReporter(config->getReporterName(),\
    \ config));\n            return ret;\n        }\n\n        class TestGroup {\n\
    \        public:\n            explicit TestGroup(std::shared_ptr<Config> const&\
    \ config)\n            : m_config{config}\n            , m_context{config, makeReporter(config)}\n\
    \            {\n                auto const& allTestCases = getAllTestCasesSorted(*m_config);\n\
    \                m_matches = m_config->testSpec().matchesByFilter(allTestCases,\
    \ *m_config);\n                auto const& invalidArgs = m_config->testSpec().getInvalidArgs();\n\
    \n                if (m_matches.empty() && invalidArgs.empty()) {\n          \
    \          for (auto const& test : allTestCases)\n                        if (!test.isHidden())\n\
    \                            m_tests.emplace(&test);\n                } else {\n\
    \                    for (auto const& match : m_matches)\n                   \
    \     m_tests.insert(match.tests.begin(), match.tests.end());\n              \
    \  }\n            }\n\n            Totals execute() {\n                auto const&\
    \ invalidArgs = m_config->testSpec().getInvalidArgs();\n                Totals\
    \ totals;\n                m_context.testGroupStarting(m_config->name(), 1, 1);\n\
    \                for (auto const& testCase : m_tests) {\n                    if\
    \ (!m_context.aborting())\n                        totals += m_context.runTest(*testCase);\n\
    \                    else\n                        m_context.reporter().skipTest(*testCase);\n\
    \                }\n\n                for (auto const& match : m_matches) {\n\
    \                    if (match.tests.empty()) {\n                        m_context.reporter().noMatchingTestCases(match.name);\n\
    \                        totals.error = -1;\n                    }\n         \
    \       }\n\n                if (!invalidArgs.empty()) {\n                   \
    \ for (auto const& invalidArg: invalidArgs)\n                         m_context.reporter().reportInvalidArguments(invalidArg);\n\
    \                }\n\n                m_context.testGroupEnded(m_config->name(),\
    \ totals, 1, 1);\n                return totals;\n            }\n\n        private:\n\
    \            using Tests = std::set<TestCase const*>;\n\n            std::shared_ptr<Config>\
    \ m_config;\n            RunContext m_context;\n            Tests m_tests;\n \
    \           TestSpec::Matches m_matches;\n        };\n\n        void applyFilenamesAsTags(Catch::IConfig\
    \ const& config) {\n            auto& tests = const_cast<std::vector<TestCase>&>(getAllTestCasesSorted(config));\n\
    \            for (auto& testCase : tests) {\n                auto tags = testCase.tags;\n\
    \n                std::string filename = testCase.lineInfo.file;\n           \
    \     auto lastSlash = filename.find_last_of(\"\\\\/\");\n                if (lastSlash\
    \ != std::string::npos) {\n                    filename.erase(0, lastSlash);\n\
    \                    filename[0] = '#';\n                }\n\n               \
    \ auto lastDot = filename.find_last_of('.');\n                if (lastDot != std::string::npos)\
    \ {\n                    filename.erase(lastDot);\n                }\n\n     \
    \           tags.push_back(std::move(filename));\n                setTags(testCase,\
    \ tags);\n            }\n        }\n\n    } // anon namespace\n\n    Session::Session()\
    \ {\n        static bool alreadyInstantiated = false;\n        if( alreadyInstantiated\
    \ ) {\n            CATCH_TRY { CATCH_INTERNAL_ERROR( \"Only one instance of Catch::Session\
    \ can ever be used\" ); }\n            CATCH_CATCH_ALL { getMutableRegistryHub().registerStartupException();\
    \ }\n        }\n\n        // There cannot be exceptions at startup in no-exception\
    \ mode.\n#if !defined(CATCH_CONFIG_DISABLE_EXCEPTIONS)\n        const auto& exceptions\
    \ = getRegistryHub().getStartupExceptionRegistry().getExceptions();\n        if\
    \ ( !exceptions.empty() ) {\n            config();\n            getCurrentMutableContext().setConfig(m_config);\n\
    \n            m_startupExceptions = true;\n            Colour colourGuard( Colour::Red\
    \ );\n            Catch::cerr() << \"Errors occurred during startup!\" << '\\\
    n';\n            // iterate over all exceptions and notify user\n            for\
    \ ( const auto& ex_ptr : exceptions ) {\n                try {\n             \
    \       std::rethrow_exception(ex_ptr);\n                } catch ( std::exception\
    \ const& ex ) {\n                    Catch::cerr() << Column( ex.what() ).indent(2)\
    \ << '\\n';\n                }\n            }\n        }\n#endif\n\n        alreadyInstantiated\
    \ = true;\n        m_cli = makeCommandLineParser( m_configData );\n    }\n   \
    \ Session::~Session() {\n        Catch::cleanUp();\n    }\n\n    void Session::showHelp()\
    \ const {\n        Catch::cout()\n                << \"\\nCatch v\" << libraryVersion()\
    \ << \"\\n\"\n                << m_cli << std::endl\n                << \"For\
    \ more detailed usage please see the project docs\\n\" << std::endl;\n    }\n\
    \    void Session::libIdentify() {\n        Catch::cout()\n                <<\
    \ std::left << std::setw(16) << \"description: \" << \"A Catch2 test executable\\\
    n\"\n                << std::left << std::setw(16) << \"category: \" << \"testframework\\\
    n\"\n                << std::left << std::setw(16) << \"framework: \" << \"Catch\
    \ Test\\n\"\n                << std::left << std::setw(16) << \"version: \" <<\
    \ libraryVersion() << std::endl;\n    }\n\n    int Session::applyCommandLine(\
    \ int argc, char const * const * argv ) {\n        if( m_startupExceptions )\n\
    \            return 1;\n\n        auto result = m_cli.parse( clara::Args( argc,\
    \ argv ) );\n        if( !result ) {\n            config();\n            getCurrentMutableContext().setConfig(m_config);\n\
    \            Catch::cerr()\n                << Colour( Colour::Red )\n       \
    \         << \"\\nError(s) in input:\\n\"\n                << Column( result.errorMessage()\
    \ ).indent( 2 )\n                << \"\\n\\n\";\n            Catch::cerr() <<\
    \ \"Run with -? for usage\\n\" << std::endl;\n            return MaxExitCode;\n\
    \        }\n\n        if( m_configData.showHelp )\n            showHelp();\n \
    \       if( m_configData.libIdentify )\n            libIdentify();\n        m_config.reset();\n\
    \        return 0;\n    }\n\n#if defined(CATCH_CONFIG_WCHAR) && defined(_WIN32)\
    \ && defined(UNICODE)\n    int Session::applyCommandLine( int argc, wchar_t const\
    \ * const * argv ) {\n\n        char **utf8Argv = new char *[ argc ];\n\n    \
    \    for ( int i = 0; i < argc; ++i ) {\n            int bufSize = WideCharToMultiByte(\
    \ CP_UTF8, 0, argv[i], -1, nullptr, 0, nullptr, nullptr );\n\n            utf8Argv[\
    \ i ] = new char[ bufSize ];\n\n            WideCharToMultiByte( CP_UTF8, 0, argv[i],\
    \ -1, utf8Argv[i], bufSize, nullptr, nullptr );\n        }\n\n        int returnCode\
    \ = applyCommandLine( argc, utf8Argv );\n\n        for ( int i = 0; i < argc;\
    \ ++i )\n            delete [] utf8Argv[ i ];\n\n        delete [] utf8Argv;\n\
    \n        return returnCode;\n    }\n#endif\n\n    void Session::useConfigData(\
    \ ConfigData const& configData ) {\n        m_configData = configData;\n     \
    \   m_config.reset();\n    }\n\n    int Session::run() {\n        if( ( m_configData.waitForKeypress\
    \ & WaitForKeypress::BeforeStart ) != 0 ) {\n            Catch::cout() << \"...waiting\
    \ for enter/ return before starting\" << std::endl;\n            static_cast<void>(std::getchar());\n\
    \        }\n        int exitCode = runInternal();\n        if( ( m_configData.waitForKeypress\
    \ & WaitForKeypress::BeforeExit ) != 0 ) {\n            Catch::cout() << \"...waiting\
    \ for enter/ return before exiting, with code: \" << exitCode << std::endl;\n\
    \            static_cast<void>(std::getchar());\n        }\n        return exitCode;\n\
    \    }\n\n    clara::Parser const& Session::cli() const {\n        return m_cli;\n\
    \    }\n    void Session::cli( clara::Parser const& newParser ) {\n        m_cli\
    \ = newParser;\n    }\n    ConfigData& Session::configData() {\n        return\
    \ m_configData;\n    }\n    Config& Session::config() {\n        if( !m_config\
    \ )\n            m_config = std::make_shared<Config>( m_configData );\n      \
    \  return *m_config;\n    }\n\n    int Session::runInternal() {\n        if( m_startupExceptions\
    \ )\n            return 1;\n\n        if (m_configData.showHelp || m_configData.libIdentify)\
    \ {\n            return 0;\n        }\n\n        CATCH_TRY {\n            config();\
    \ // Force config to be constructed\n\n            seedRng( *m_config );\n\n \
    \           if( m_configData.filenamesAsTags )\n                applyFilenamesAsTags(\
    \ *m_config );\n\n            // Handle list request\n            if( Option<std::size_t>\
    \ listed = list( m_config ) )\n                return static_cast<int>( *listed\
    \ );\n\n            TestGroup tests { m_config };\n            auto const totals\
    \ = tests.execute();\n\n            if( m_config->warnAboutNoTests() && totals.error\
    \ == -1 )\n                return 2;\n\n            // Note that on unices only\
    \ the lower 8 bits are usually used, clamping\n            // the return value\
    \ to 255 prevents false negative when some multiple\n            // of 256 tests\
    \ has failed\n            return (std::min) (MaxExitCode, (std::max) (totals.error,\
    \ static_cast<int>(totals.assertions.failed)));\n        }\n#if !defined(CATCH_CONFIG_DISABLE_EXCEPTIONS)\n\
    \        catch( std::exception& ex ) {\n            Catch::cerr() << ex.what()\
    \ << std::endl;\n            return MaxExitCode;\n        }\n#endif\n    }\n\n\
    } // end namespace Catch\n// end catch_session.cpp\n// start catch_singletons.cpp\n\
    \n#include <vector>\n\nnamespace Catch {\n\n    namespace {\n        static auto\
    \ getSingletons() -> std::vector<ISingleton*>*& {\n            static std::vector<ISingleton*>*\
    \ g_singletons = nullptr;\n            if( !g_singletons )\n                g_singletons\
    \ = new std::vector<ISingleton*>();\n            return g_singletons;\n      \
    \  }\n    }\n\n    ISingleton::~ISingleton() {}\n\n    void addSingleton(ISingleton*\
    \ singleton ) {\n        getSingletons()->push_back( singleton );\n    }\n   \
    \ void cleanupSingletons() {\n        auto& singletons = getSingletons();\n  \
    \      for( auto singleton : *singletons )\n            delete singleton;\n  \
    \      delete singletons;\n        singletons = nullptr;\n    }\n\n} // namespace\
    \ Catch\n// end catch_singletons.cpp\n// start catch_startup_exception_registry.cpp\n\
    \n#if !defined(CATCH_CONFIG_DISABLE_EXCEPTIONS)\nnamespace Catch {\nvoid StartupExceptionRegistry::add(\
    \ std::exception_ptr const& exception ) noexcept {\n        CATCH_TRY {\n    \
    \        m_exceptions.push_back(exception);\n        } CATCH_CATCH_ALL {\n   \
    \         // If we run out of memory during start-up there's really not a lot\
    \ more we can do about it\n            std::terminate();\n        }\n    }\n\n\
    \    std::vector<std::exception_ptr> const& StartupExceptionRegistry::getExceptions()\
    \ const noexcept {\n        return m_exceptions;\n    }\n\n} // end namespace\
    \ Catch\n#endif\n// end catch_startup_exception_registry.cpp\n// start catch_stream.cpp\n\
    \n#include <cstdio>\n#include <iostream>\n#include <fstream>\n#include <sstream>\n\
    #include <vector>\n#include <memory>\n\nnamespace Catch {\n\n    Catch::IStream::~IStream()\
    \ = default;\n\n    namespace Detail { namespace {\n        template<typename\
    \ WriterF, std::size_t bufferSize=256>\n        class StreamBufImpl : public std::streambuf\
    \ {\n            char data[bufferSize];\n            WriterF m_writer;\n\n   \
    \     public:\n            StreamBufImpl() {\n                setp( data, data\
    \ + sizeof(data) );\n            }\n\n            ~StreamBufImpl() noexcept {\n\
    \                StreamBufImpl::sync();\n            }\n\n        private:\n \
    \           int overflow( int c ) override {\n                sync();\n\n    \
    \            if( c != EOF ) {\n                    if( pbase() == epptr() )\n\
    \                        m_writer( std::string( 1, static_cast<char>( c ) ) );\n\
    \                    else\n                        sputc( static_cast<char>( c\
    \ ) );\n                }\n                return 0;\n            }\n\n      \
    \      int sync() override {\n                if( pbase() != pptr() ) {\n    \
    \                m_writer( std::string( pbase(), static_cast<std::string::size_type>(\
    \ pptr() - pbase() ) ) );\n                    setp( pbase(), epptr() );\n   \
    \             }\n                return 0;\n            }\n        };\n\n    \
    \    ///////////////////////////////////////////////////////////////////////////\n\
    \n        struct OutputDebugWriter {\n\n            void operator()( std::string\
    \ const&str ) {\n                writeToDebugConsole( str );\n            }\n\
    \        };\n\n        ///////////////////////////////////////////////////////////////////////////\n\
    \n        class FileStream : public IStream {\n            mutable std::ofstream\
    \ m_ofs;\n        public:\n            FileStream( StringRef filename ) {\n  \
    \              m_ofs.open( filename.c_str() );\n                CATCH_ENFORCE(\
    \ !m_ofs.fail(), \"Unable to open file: '\" << filename << \"'\" );\n        \
    \    }\n            ~FileStream() override = default;\n        public: // IStream\n\
    \            std::ostream& stream() const override {\n                return m_ofs;\n\
    \            }\n        };\n\n        ///////////////////////////////////////////////////////////////////////////\n\
    \n        class CoutStream : public IStream {\n            mutable std::ostream\
    \ m_os;\n        public:\n            // Store the streambuf from cout up-front\
    \ because\n            // cout may get redirected when running tests\n       \
    \     CoutStream() : m_os( Catch::cout().rdbuf() ) {}\n            ~CoutStream()\
    \ override = default;\n\n        public: // IStream\n            std::ostream&\
    \ stream() const override { return m_os; }\n        };\n\n        ///////////////////////////////////////////////////////////////////////////\n\
    \n        class DebugOutStream : public IStream {\n            std::unique_ptr<StreamBufImpl<OutputDebugWriter>>\
    \ m_streamBuf;\n            mutable std::ostream m_os;\n        public:\n    \
    \        DebugOutStream()\n            :   m_streamBuf( new StreamBufImpl<OutputDebugWriter>()\
    \ ),\n                m_os( m_streamBuf.get() )\n            {}\n\n          \
    \  ~DebugOutStream() override = default;\n\n        public: // IStream\n     \
    \       std::ostream& stream() const override { return m_os; }\n        };\n\n\
    \    }} // namespace anon::detail\n\n    ///////////////////////////////////////////////////////////////////////////\n\
    \n    auto makeStream( StringRef const &filename ) -> IStream const* {\n     \
    \   if( filename.empty() )\n            return new Detail::CoutStream();\n   \
    \     else if( filename[0] == '%' ) {\n            if( filename == \"%debug\"\
    \ )\n                return new Detail::DebugOutStream();\n            else\n\
    \                CATCH_ERROR( \"Unrecognised stream: '\" << filename << \"'\"\
    \ );\n        }\n        else\n            return new Detail::FileStream( filename\
    \ );\n    }\n\n    // This class encapsulates the idea of a pool of ostringstreams\
    \ that can be reused.\n    struct StringStreams {\n        std::vector<std::unique_ptr<std::ostringstream>>\
    \ m_streams;\n        std::vector<std::size_t> m_unused;\n        std::ostringstream\
    \ m_referenceStream; // Used for copy state/ flags from\n\n        auto add()\
    \ -> std::size_t {\n            if( m_unused.empty() ) {\n                m_streams.push_back(\
    \ std::unique_ptr<std::ostringstream>( new std::ostringstream ) );\n         \
    \       return m_streams.size()-1;\n            }\n            else {\n      \
    \          auto index = m_unused.back();\n                m_unused.pop_back();\n\
    \                return index;\n            }\n        }\n\n        void release(\
    \ std::size_t index ) {\n            m_streams[index]->copyfmt( m_referenceStream\
    \ ); // Restore initial flags and other state\n            m_unused.push_back(index);\n\
    \        }\n    };\n\n    ReusableStringStream::ReusableStringStream()\n    :\
    \   m_index( Singleton<StringStreams>::getMutable().add() ),\n        m_oss( Singleton<StringStreams>::getMutable().m_streams[m_index].get()\
    \ )\n    {}\n\n    ReusableStringStream::~ReusableStringStream() {\n        static_cast<std::ostringstream*>(\
    \ m_oss )->str(\"\");\n        m_oss->clear();\n        Singleton<StringStreams>::getMutable().release(\
    \ m_index );\n    }\n\n    auto ReusableStringStream::str() const -> std::string\
    \ {\n        return static_cast<std::ostringstream*>( m_oss )->str();\n    }\n\
    \n    ///////////////////////////////////////////////////////////////////////////\n\
    \n#ifndef CATCH_CONFIG_NOSTDOUT // If you #define this you must implement these\
    \ functions\n    std::ostream& cout() { return std::cout; }\n    std::ostream&\
    \ cerr() { return std::cerr; }\n    std::ostream& clog() { return std::clog; }\n\
    #endif\n}\n// end catch_stream.cpp\n// start catch_string_manip.cpp\n\n#include\
    \ <algorithm>\n#include <ostream>\n#include <cstring>\n#include <cctype>\n#include\
    \ <vector>\n\nnamespace Catch {\n\n    namespace {\n        char toLowerCh(char\
    \ c) {\n            return static_cast<char>( std::tolower( static_cast<unsigned\
    \ char>(c) ) );\n        }\n    }\n\n    bool startsWith( std::string const& s,\
    \ std::string const& prefix ) {\n        return s.size() >= prefix.size() && std::equal(prefix.begin(),\
    \ prefix.end(), s.begin());\n    }\n    bool startsWith( std::string const& s,\
    \ char prefix ) {\n        return !s.empty() && s[0] == prefix;\n    }\n    bool\
    \ endsWith( std::string const& s, std::string const& suffix ) {\n        return\
    \ s.size() >= suffix.size() && std::equal(suffix.rbegin(), suffix.rend(), s.rbegin());\n\
    \    }\n    bool endsWith( std::string const& s, char suffix ) {\n        return\
    \ !s.empty() && s[s.size()-1] == suffix;\n    }\n    bool contains( std::string\
    \ const& s, std::string const& infix ) {\n        return s.find( infix ) != std::string::npos;\n\
    \    }\n    void toLowerInPlace( std::string& s ) {\n        std::transform( s.begin(),\
    \ s.end(), s.begin(), toLowerCh );\n    }\n    std::string toLower( std::string\
    \ const& s ) {\n        std::string lc = s;\n        toLowerInPlace( lc );\n \
    \       return lc;\n    }\n    std::string trim( std::string const& str ) {\n\
    \        static char const* whitespaceChars = \"\\n\\r\\t \";\n        std::string::size_type\
    \ start = str.find_first_not_of( whitespaceChars );\n        std::string::size_type\
    \ end = str.find_last_not_of( whitespaceChars );\n\n        return start != std::string::npos\
    \ ? str.substr( start, 1+end-start ) : std::string();\n    }\n\n    StringRef\
    \ trim(StringRef ref) {\n        const auto is_ws = [](char c) {\n           \
    \ return c == ' ' || c == '\\t' || c == '\\n' || c == '\\r';\n        };\n   \
    \     size_t real_begin = 0;\n        while (real_begin < ref.size() && is_ws(ref[real_begin]))\
    \ { ++real_begin; }\n        size_t real_end = ref.size();\n        while (real_end\
    \ > real_begin && is_ws(ref[real_end - 1])) { --real_end; }\n\n        return\
    \ ref.substr(real_begin, real_end - real_begin);\n    }\n\n    bool replaceInPlace(\
    \ std::string& str, std::string const& replaceThis, std::string const& withThis\
    \ ) {\n        bool replaced = false;\n        std::size_t i = str.find( replaceThis\
    \ );\n        while( i != std::string::npos ) {\n            replaced = true;\n\
    \            str = str.substr( 0, i ) + withThis + str.substr( i+replaceThis.size()\
    \ );\n            if( i < str.size()-withThis.size() )\n                i = str.find(\
    \ replaceThis, i+withThis.size() );\n            else\n                i = std::string::npos;\n\
    \        }\n        return replaced;\n    }\n\n    std::vector<StringRef> splitStringRef(\
    \ StringRef str, char delimiter ) {\n        std::vector<StringRef> subStrings;\n\
    \        std::size_t start = 0;\n        for(std::size_t pos = 0; pos < str.size();\
    \ ++pos ) {\n            if( str[pos] == delimiter ) {\n                if( pos\
    \ - start > 1 )\n                    subStrings.push_back( str.substr( start,\
    \ pos-start ) );\n                start = pos+1;\n            }\n        }\n \
    \       if( start < str.size() )\n            subStrings.push_back( str.substr(\
    \ start, str.size()-start ) );\n        return subStrings;\n    }\n\n    pluralise::pluralise(\
    \ std::size_t count, std::string const& label )\n    :   m_count( count ),\n \
    \       m_label( label )\n    {}\n\n    std::ostream& operator << ( std::ostream&\
    \ os, pluralise const& pluraliser ) {\n        os << pluraliser.m_count << ' '\
    \ << pluraliser.m_label;\n        if( pluraliser.m_count != 1 )\n            os\
    \ << 's';\n        return os;\n    }\n\n}\n// end catch_string_manip.cpp\n// start\
    \ catch_stringref.cpp\n\n#include <algorithm>\n#include <ostream>\n#include <cstring>\n\
    #include <cstdint>\n\nnamespace Catch {\n    StringRef::StringRef( char const*\
    \ rawChars ) noexcept\n    : StringRef( rawChars, static_cast<StringRef::size_type>(std::strlen(rawChars)\
    \ ) )\n    {}\n\n    auto StringRef::c_str() const -> char const* {\n        CATCH_ENFORCE(isNullTerminated(),\
    \ \"Called StringRef::c_str() on a non-null-terminated instance\");\n        return\
    \ m_start;\n    }\n    auto StringRef::data() const noexcept -> char const* {\n\
    \        return m_start;\n    }\n\n    auto StringRef::substr( size_type start,\
    \ size_type size ) const noexcept -> StringRef {\n        if (start < m_size)\
    \ {\n            return StringRef(m_start + start, (std::min)(m_size - start,\
    \ size));\n        } else {\n            return StringRef();\n        }\n    }\n\
    \    auto StringRef::operator == ( StringRef const& other ) const noexcept ->\
    \ bool {\n        return m_size == other.m_size\n            && (std::memcmp(\
    \ m_start, other.m_start, m_size ) == 0);\n    }\n\n    auto operator << ( std::ostream&\
    \ os, StringRef const& str ) -> std::ostream& {\n        return os.write(str.data(),\
    \ str.size());\n    }\n\n    auto operator+=( std::string& lhs, StringRef const&\
    \ rhs ) -> std::string& {\n        lhs.append(rhs.data(), rhs.size());\n     \
    \   return lhs;\n    }\n\n} // namespace Catch\n// end catch_stringref.cpp\n//\
    \ start catch_tag_alias.cpp\n\nnamespace Catch {\n    TagAlias::TagAlias(std::string\
    \ const & _tag, SourceLineInfo _lineInfo): tag(_tag), lineInfo(_lineInfo) {}\n\
    }\n// end catch_tag_alias.cpp\n// start catch_tag_alias_autoregistrar.cpp\n\n\
    namespace Catch {\n\n    RegistrarForTagAliases::RegistrarForTagAliases(char const*\
    \ alias, char const* tag, SourceLineInfo const& lineInfo) {\n        CATCH_TRY\
    \ {\n            getMutableRegistryHub().registerTagAlias(alias, tag, lineInfo);\n\
    \        } CATCH_CATCH_ALL {\n            // Do not throw when constructing global\
    \ objects, instead register the exception to be processed later\n            getMutableRegistryHub().registerStartupException();\n\
    \        }\n    }\n\n}\n// end catch_tag_alias_autoregistrar.cpp\n// start catch_tag_alias_registry.cpp\n\
    \n#include <sstream>\n\nnamespace Catch {\n\n    TagAliasRegistry::~TagAliasRegistry()\
    \ {}\n\n    TagAlias const* TagAliasRegistry::find( std::string const& alias )\
    \ const {\n        auto it = m_registry.find( alias );\n        if( it != m_registry.end()\
    \ )\n            return &(it->second);\n        else\n            return nullptr;\n\
    \    }\n\n    std::string TagAliasRegistry::expandAliases( std::string const&\
    \ unexpandedTestSpec ) const {\n        std::string expandedTestSpec = unexpandedTestSpec;\n\
    \        for( auto const& registryKvp : m_registry ) {\n            std::size_t\
    \ pos = expandedTestSpec.find( registryKvp.first );\n            if( pos != std::string::npos\
    \ ) {\n                expandedTestSpec =  expandedTestSpec.substr( 0, pos ) +\n\
    \                                    registryKvp.second.tag +\n              \
    \                      expandedTestSpec.substr( pos + registryKvp.first.size()\
    \ );\n            }\n        }\n        return expandedTestSpec;\n    }\n\n  \
    \  void TagAliasRegistry::add( std::string const& alias, std::string const& tag,\
    \ SourceLineInfo const& lineInfo ) {\n        CATCH_ENFORCE( startsWith(alias,\
    \ \"[@\") && endsWith(alias, ']'),\n                      \"error: tag alias,\
    \ '\" << alias << \"' is not of the form [@alias name].\\n\" << lineInfo );\n\n\
    \        CATCH_ENFORCE( m_registry.insert(std::make_pair(alias, TagAlias(tag,\
    \ lineInfo))).second,\n                      \"error: tag alias, '\" << alias\
    \ << \"' already registered.\\n\"\n                      << \"\\tFirst seen at:\
    \ \" << find(alias)->lineInfo << \"\\n\"\n                      << \"\\tRedefined\
    \ at: \" << lineInfo );\n    }\n\n    ITagAliasRegistry::~ITagAliasRegistry()\
    \ {}\n\n    ITagAliasRegistry const& ITagAliasRegistry::get() {\n        return\
    \ getRegistryHub().getTagAliasRegistry();\n    }\n\n} // end namespace Catch\n\
    // end catch_tag_alias_registry.cpp\n// start catch_test_case_info.cpp\n\n#include\
    \ <cctype>\n#include <exception>\n#include <algorithm>\n#include <sstream>\n\n\
    namespace Catch {\n\n    namespace {\n        TestCaseInfo::SpecialProperties\
    \ parseSpecialTag( std::string const& tag ) {\n            if( startsWith( tag,\
    \ '.' ) ||\n                tag == \"!hide\" )\n                return TestCaseInfo::IsHidden;\n\
    \            else if( tag == \"!throws\" )\n                return TestCaseInfo::Throws;\n\
    \            else if( tag == \"!shouldfail\" )\n                return TestCaseInfo::ShouldFail;\n\
    \            else if( tag == \"!mayfail\" )\n                return TestCaseInfo::MayFail;\n\
    \            else if( tag == \"!nonportable\" )\n                return TestCaseInfo::NonPortable;\n\
    \            else if( tag == \"!benchmark\" )\n                return static_cast<TestCaseInfo::SpecialProperties>(\
    \ TestCaseInfo::Benchmark | TestCaseInfo::IsHidden );\n            else\n    \
    \            return TestCaseInfo::None;\n        }\n        bool isReservedTag(\
    \ std::string const& tag ) {\n            return parseSpecialTag( tag ) == TestCaseInfo::None\
    \ && tag.size() > 0 && !std::isalnum( static_cast<unsigned char>(tag[0]) );\n\
    \        }\n        void enforceNotReservedTag( std::string const& tag, SourceLineInfo\
    \ const& _lineInfo ) {\n            CATCH_ENFORCE( !isReservedTag(tag),\n    \
    \                      \"Tag name: [\" << tag << \"] is not allowed.\\n\"\n  \
    \                        << \"Tag names starting with non alphanumeric characters\
    \ are reserved\\n\"\n                          << _lineInfo );\n        }\n  \
    \  }\n\n    TestCase makeTestCase(  ITestInvoker* _testCase,\n               \
    \             std::string const& _className,\n                            NameAndTags\
    \ const& nameAndTags,\n                            SourceLineInfo const& _lineInfo\
    \ )\n    {\n        bool isHidden = false;\n\n        // Parse out tags\n    \
    \    std::vector<std::string> tags;\n        std::string desc, tag;\n        bool\
    \ inTag = false;\n        for (char c : nameAndTags.tags) {\n            if( !inTag\
    \ ) {\n                if( c == '[' )\n                    inTag = true;\n   \
    \             else\n                    desc += c;\n            }\n          \
    \  else {\n                if( c == ']' ) {\n                    TestCaseInfo::SpecialProperties\
    \ prop = parseSpecialTag( tag );\n                    if( ( prop & TestCaseInfo::IsHidden\
    \ ) != 0 )\n                        isHidden = true;\n                    else\
    \ if( prop == TestCaseInfo::None )\n                        enforceNotReservedTag(\
    \ tag, _lineInfo );\n\n                    // Merged hide tags like `[.approvals]`\
    \ should be added as\n                    // `[.][approvals]`. The `[.]` is added\
    \ at later point, so\n                    // we only strip the prefix\n      \
    \              if (startsWith(tag, '.') && tag.size() > 1) {\n               \
    \         tag.erase(0, 1);\n                    }\n                    tags.push_back(\
    \ tag );\n                    tag.clear();\n                    inTag = false;\n\
    \                }\n                else\n                    tag += c;\n    \
    \        }\n        }\n        if( isHidden ) {\n            // Add all \"hidden\"\
    \ tags to make them behave identically\n            tags.insert( tags.end(), {\
    \ \".\", \"!hide\" } );\n        }\n\n        TestCaseInfo info( static_cast<std::string>(nameAndTags.name),\
    \ _className, desc, tags, _lineInfo );\n        return TestCase( _testCase, std::move(info)\
    \ );\n    }\n\n    void setTags( TestCaseInfo& testCaseInfo, std::vector<std::string>\
    \ tags ) {\n        std::sort(begin(tags), end(tags));\n        tags.erase(std::unique(begin(tags),\
    \ end(tags)), end(tags));\n        testCaseInfo.lcaseTags.clear();\n\n       \
    \ for( auto const& tag : tags ) {\n            std::string lcaseTag = toLower(\
    \ tag );\n            testCaseInfo.properties = static_cast<TestCaseInfo::SpecialProperties>(\
    \ testCaseInfo.properties | parseSpecialTag( lcaseTag ) );\n            testCaseInfo.lcaseTags.push_back(\
    \ lcaseTag );\n        }\n        testCaseInfo.tags = std::move(tags);\n    }\n\
    \n    TestCaseInfo::TestCaseInfo( std::string const& _name,\n                \
    \                std::string const& _className,\n                            \
    \    std::string const& _description,\n                                std::vector<std::string>\
    \ const& _tags,\n                                SourceLineInfo const& _lineInfo\
    \ )\n    :   name( _name ),\n        className( _className ),\n        description(\
    \ _description ),\n        lineInfo( _lineInfo ),\n        properties( None )\n\
    \    {\n        setTags( *this, _tags );\n    }\n\n    bool TestCaseInfo::isHidden()\
    \ const {\n        return ( properties & IsHidden ) != 0;\n    }\n    bool TestCaseInfo::throws()\
    \ const {\n        return ( properties & Throws ) != 0;\n    }\n    bool TestCaseInfo::okToFail()\
    \ const {\n        return ( properties & (ShouldFail | MayFail ) ) != 0;\n   \
    \ }\n    bool TestCaseInfo::expectedToFail() const {\n        return ( properties\
    \ & (ShouldFail ) ) != 0;\n    }\n\n    std::string TestCaseInfo::tagsAsString()\
    \ const {\n        std::string ret;\n        // '[' and ']' per tag\n        std::size_t\
    \ full_size = 2 * tags.size();\n        for (const auto& tag : tags) {\n     \
    \       full_size += tag.size();\n        }\n        ret.reserve(full_size);\n\
    \        for (const auto& tag : tags) {\n            ret.push_back('[');\n   \
    \         ret.append(tag);\n            ret.push_back(']');\n        }\n\n   \
    \     return ret;\n    }\n\n    TestCase::TestCase( ITestInvoker* testCase, TestCaseInfo&&\
    \ info ) : TestCaseInfo( std::move(info) ), test( testCase ) {}\n\n    TestCase\
    \ TestCase::withName( std::string const& _newName ) const {\n        TestCase\
    \ other( *this );\n        other.name = _newName;\n        return other;\n   \
    \ }\n\n    void TestCase::invoke() const {\n        test->invoke();\n    }\n\n\
    \    bool TestCase::operator == ( TestCase const& other ) const {\n        return\
    \  test.get() == other.test.get() &&\n                name == other.name &&\n\
    \                className == other.className;\n    }\n\n    bool TestCase::operator\
    \ < ( TestCase const& other ) const {\n        return name < other.name;\n   \
    \ }\n\n    TestCaseInfo const& TestCase::getTestCaseInfo() const\n    {\n    \
    \    return *this;\n    }\n\n} // end namespace Catch\n// end catch_test_case_info.cpp\n\
    // start catch_test_case_registry_impl.cpp\n\n#include <algorithm>\n#include <sstream>\n\
    \nnamespace Catch {\n\n    namespace {\n        struct TestHasher {\n        \
    \    explicit TestHasher(Catch::SimplePcg32& rng_instance) {\n               \
    \ basis = rng_instance();\n                basis <<= 32;\n                basis\
    \ |= rng_instance();\n            }\n\n            uint64_t basis;\n\n       \
    \     uint64_t operator()(TestCase const& t) const {\n                // Modified\
    \ FNV-1a hash\n                static constexpr uint64_t prime = 1099511628211;\n\
    \                uint64_t hash = basis;\n                for (const char c : t.name)\
    \ {\n                    hash ^= c;\n                    hash *= prime;\n    \
    \            }\n                return hash;\n            }\n        };\n    }\
    \ // end unnamed namespace\n\n    std::vector<TestCase> sortTests( IConfig const&\
    \ config, std::vector<TestCase> const& unsortedTestCases ) {\n        switch(\
    \ config.runOrder() ) {\n            case RunTests::InDeclarationOrder:\n    \
    \            // already in declaration order\n                break;\n\n     \
    \       case RunTests::InLexicographicalOrder: {\n                std::vector<TestCase>\
    \ sorted = unsortedTestCases;\n                std::sort( sorted.begin(), sorted.end()\
    \ );\n                return sorted;\n            }\n\n            case RunTests::InRandomOrder:\
    \ {\n                seedRng( config );\n                TestHasher h( rng() );\n\
    \n                using hashedTest = std::pair<uint64_t, TestCase const*>;\n \
    \               std::vector<hashedTest> indexed_tests;\n                indexed_tests.reserve(\
    \ unsortedTestCases.size() );\n\n                for (auto const& testCase : unsortedTestCases)\
    \ {\n                    indexed_tests.emplace_back(h(testCase), &testCase);\n\
    \                }\n\n                std::sort(indexed_tests.begin(), indexed_tests.end(),\n\
    \                          [](hashedTest const& lhs, hashedTest const& rhs) {\n\
    \                          if (lhs.first == rhs.first) {\n                   \
    \           return lhs.second->name < rhs.second->name;\n                    \
    \      }\n                          return lhs.first < rhs.first;\n          \
    \      });\n\n                std::vector<TestCase> sorted;\n                sorted.reserve(\
    \ indexed_tests.size() );\n\n                for (auto const& hashed : indexed_tests)\
    \ {\n                    sorted.emplace_back(*hashed.second);\n              \
    \  }\n\n                return sorted;\n            }\n        }\n        return\
    \ unsortedTestCases;\n    }\n\n    bool isThrowSafe( TestCase const& testCase,\
    \ IConfig const& config ) {\n        return !testCase.throws() || config.allowThrows();\n\
    \    }\n\n    bool matchTest( TestCase const& testCase, TestSpec const& testSpec,\
    \ IConfig const& config ) {\n        return testSpec.matches( testCase ) && isThrowSafe(\
    \ testCase, config );\n    }\n\n    void enforceNoDuplicateTestCases( std::vector<TestCase>\
    \ const& functions ) {\n        std::set<TestCase> seenFunctions;\n        for(\
    \ auto const& function : functions ) {\n            auto prev = seenFunctions.insert(\
    \ function );\n            CATCH_ENFORCE( prev.second,\n                    \"\
    error: TEST_CASE( \\\"\" << function.name << \"\\\" ) already defined.\\n\"\n\
    \                    << \"\\tFirst seen at \" << prev.first->getTestCaseInfo().lineInfo\
    \ << \"\\n\"\n                    << \"\\tRedefined at \" << function.getTestCaseInfo().lineInfo\
    \ );\n        }\n    }\n\n    std::vector<TestCase> filterTests( std::vector<TestCase>\
    \ const& testCases, TestSpec const& testSpec, IConfig const& config ) {\n    \
    \    std::vector<TestCase> filtered;\n        filtered.reserve( testCases.size()\
    \ );\n        for (auto const& testCase : testCases) {\n            if ((!testSpec.hasFilters()\
    \ && !testCase.isHidden()) ||\n                (testSpec.hasFilters() && matchTest(testCase,\
    \ testSpec, config))) {\n                filtered.push_back(testCase);\n     \
    \       }\n        }\n        return filtered;\n    }\n    std::vector<TestCase>\
    \ const& getAllTestCasesSorted( IConfig const& config ) {\n        return getRegistryHub().getTestCaseRegistry().getAllTestsSorted(\
    \ config );\n    }\n\n    void TestRegistry::registerTest( TestCase const& testCase\
    \ ) {\n        std::string name = testCase.getTestCaseInfo().name;\n        if(\
    \ name.empty() ) {\n            ReusableStringStream rss;\n            rss <<\
    \ \"Anonymous test case \" << ++m_unnamedCount;\n            return registerTest(\
    \ testCase.withName( rss.str() ) );\n        }\n        m_functions.push_back(\
    \ testCase );\n    }\n\n    std::vector<TestCase> const& TestRegistry::getAllTests()\
    \ const {\n        return m_functions;\n    }\n    std::vector<TestCase> const&\
    \ TestRegistry::getAllTestsSorted( IConfig const& config ) const {\n        if(\
    \ m_sortedFunctions.empty() )\n            enforceNoDuplicateTestCases( m_functions\
    \ );\n\n        if(  m_currentSortOrder != config.runOrder() || m_sortedFunctions.empty()\
    \ ) {\n            m_sortedFunctions = sortTests( config, m_functions );\n   \
    \         m_currentSortOrder = config.runOrder();\n        }\n        return m_sortedFunctions;\n\
    \    }\n\n    ///////////////////////////////////////////////////////////////////////////\n\
    \    TestInvokerAsFunction::TestInvokerAsFunction( void(*testAsFunction)() ) noexcept\
    \ : m_testAsFunction( testAsFunction ) {}\n\n    void TestInvokerAsFunction::invoke()\
    \ const {\n        m_testAsFunction();\n    }\n\n    std::string extractClassName(\
    \ StringRef const& classOrQualifiedMethodName ) {\n        std::string className(classOrQualifiedMethodName);\n\
    \        if( startsWith( className, '&' ) )\n        {\n            std::size_t\
    \ lastColons = className.rfind( \"::\" );\n            std::size_t penultimateColons\
    \ = className.rfind( \"::\", lastColons-1 );\n            if( penultimateColons\
    \ == std::string::npos )\n                penultimateColons = 1;\n           \
    \ className = className.substr( penultimateColons, lastColons-penultimateColons\
    \ );\n        }\n        return className;\n    }\n\n} // end namespace Catch\n\
    // end catch_test_case_registry_impl.cpp\n// start catch_test_case_tracker.cpp\n\
    \n#include <algorithm>\n#include <cassert>\n#include <stdexcept>\n#include <memory>\n\
    #include <sstream>\n\n#if defined(__clang__)\n#    pragma clang diagnostic push\n\
    #    pragma clang diagnostic ignored \"-Wexit-time-destructors\"\n#endif\n\nnamespace\
    \ Catch {\nnamespace TestCaseTracking {\n\n    NameAndLocation::NameAndLocation(\
    \ std::string const& _name, SourceLineInfo const& _location )\n    :   name( _name\
    \ ),\n        location( _location )\n    {}\n\n    ITracker::~ITracker() = default;\n\
    \n    ITracker& TrackerContext::startRun() {\n        m_rootTracker = std::make_shared<SectionTracker>(\
    \ NameAndLocation( \"{root}\", CATCH_INTERNAL_LINEINFO ), *this, nullptr );\n\
    \        m_currentTracker = nullptr;\n        m_runState = Executing;\n      \
    \  return *m_rootTracker;\n    }\n\n    void TrackerContext::endRun() {\n    \
    \    m_rootTracker.reset();\n        m_currentTracker = nullptr;\n        m_runState\
    \ = NotStarted;\n    }\n\n    void TrackerContext::startCycle() {\n        m_currentTracker\
    \ = m_rootTracker.get();\n        m_runState = Executing;\n    }\n    void TrackerContext::completeCycle()\
    \ {\n        m_runState = CompletedCycle;\n    }\n\n    bool TrackerContext::completedCycle()\
    \ const {\n        return m_runState == CompletedCycle;\n    }\n    ITracker&\
    \ TrackerContext::currentTracker() {\n        return *m_currentTracker;\n    }\n\
    \    void TrackerContext::setCurrentTracker( ITracker* tracker ) {\n        m_currentTracker\
    \ = tracker;\n    }\n\n    TrackerBase::TrackerBase( NameAndLocation const& nameAndLocation,\
    \ TrackerContext& ctx, ITracker* parent ):\n        ITracker(nameAndLocation),\n\
    \        m_ctx( ctx ),\n        m_parent( parent )\n    {}\n\n    bool TrackerBase::isComplete()\
    \ const {\n        return m_runState == CompletedSuccessfully || m_runState ==\
    \ Failed;\n    }\n    bool TrackerBase::isSuccessfullyCompleted() const {\n  \
    \      return m_runState == CompletedSuccessfully;\n    }\n    bool TrackerBase::isOpen()\
    \ const {\n        return m_runState != NotStarted && !isComplete();\n    }\n\
    \    bool TrackerBase::hasChildren() const {\n        return !m_children.empty();\n\
    \    }\n\n    void TrackerBase::addChild( ITrackerPtr const& child ) {\n     \
    \   m_children.push_back( child );\n    }\n\n    ITrackerPtr TrackerBase::findChild(\
    \ NameAndLocation const& nameAndLocation ) {\n        auto it = std::find_if(\
    \ m_children.begin(), m_children.end(),\n            [&nameAndLocation]( ITrackerPtr\
    \ const& tracker ){\n                return\n                    tracker->nameAndLocation().location\
    \ == nameAndLocation.location &&\n                    tracker->nameAndLocation().name\
    \ == nameAndLocation.name;\n            } );\n        return( it != m_children.end()\
    \ )\n            ? *it\n            : nullptr;\n    }\n    ITracker& TrackerBase::parent()\
    \ {\n        assert( m_parent ); // Should always be non-null except for root\n\
    \        return *m_parent;\n    }\n\n    void TrackerBase::openChild() {\n   \
    \     if( m_runState != ExecutingChildren ) {\n            m_runState = ExecutingChildren;\n\
    \            if( m_parent )\n                m_parent->openChild();\n        }\n\
    \    }\n\n    bool TrackerBase::isSectionTracker() const { return false; }\n \
    \   bool TrackerBase::isGeneratorTracker() const { return false; }\n\n    void\
    \ TrackerBase::open() {\n        m_runState = Executing;\n        moveToThis();\n\
    \        if( m_parent )\n            m_parent->openChild();\n    }\n\n    void\
    \ TrackerBase::close() {\n\n        // Close any still open children (e.g. generators)\n\
    \        while( &m_ctx.currentTracker() != this )\n            m_ctx.currentTracker().close();\n\
    \n        switch( m_runState ) {\n            case NeedsAnotherRun:\n        \
    \        break;\n\n            case Executing:\n                m_runState = CompletedSuccessfully;\n\
    \                break;\n            case ExecutingChildren:\n               \
    \ if( std::all_of(m_children.begin(), m_children.end(), [](ITrackerPtr const&\
    \ t){ return t->isComplete(); }) )\n                    m_runState = CompletedSuccessfully;\n\
    \                break;\n\n            case NotStarted:\n            case CompletedSuccessfully:\n\
    \            case Failed:\n                CATCH_INTERNAL_ERROR( \"Illogical state:\
    \ \" << m_runState );\n\n            default:\n                CATCH_INTERNAL_ERROR(\
    \ \"Unknown state: \" << m_runState );\n        }\n        moveToParent();\n \
    \       m_ctx.completeCycle();\n    }\n    void TrackerBase::fail() {\n      \
    \  m_runState = Failed;\n        if( m_parent )\n            m_parent->markAsNeedingAnotherRun();\n\
    \        moveToParent();\n        m_ctx.completeCycle();\n    }\n    void TrackerBase::markAsNeedingAnotherRun()\
    \ {\n        m_runState = NeedsAnotherRun;\n    }\n\n    void TrackerBase::moveToParent()\
    \ {\n        assert( m_parent );\n        m_ctx.setCurrentTracker( m_parent );\n\
    \    }\n    void TrackerBase::moveToThis() {\n        m_ctx.setCurrentTracker(\
    \ this );\n    }\n\n    SectionTracker::SectionTracker( NameAndLocation const&\
    \ nameAndLocation, TrackerContext& ctx, ITracker* parent )\n    :   TrackerBase(\
    \ nameAndLocation, ctx, parent ),\n        m_trimmed_name(trim(nameAndLocation.name))\n\
    \    {\n        if( parent ) {\n            while( !parent->isSectionTracker()\
    \ )\n                parent = &parent->parent();\n\n            SectionTracker&\
    \ parentSection = static_cast<SectionTracker&>( *parent );\n            addNextFilters(\
    \ parentSection.m_filters );\n        }\n    }\n\n    bool SectionTracker::isComplete()\
    \ const {\n        bool complete = true;\n\n        if (m_filters.empty()\n  \
    \          || m_filters[0] == \"\"\n            || std::find(m_filters.begin(),\
    \ m_filters.end(), m_trimmed_name) != m_filters.end()) {\n            complete\
    \ = TrackerBase::isComplete();\n        }\n        return complete;\n    }\n\n\
    \    bool SectionTracker::isSectionTracker() const { return true; }\n\n    SectionTracker&\
    \ SectionTracker::acquire( TrackerContext& ctx, NameAndLocation const& nameAndLocation\
    \ ) {\n        std::shared_ptr<SectionTracker> section;\n\n        ITracker& currentTracker\
    \ = ctx.currentTracker();\n        if( ITrackerPtr childTracker = currentTracker.findChild(\
    \ nameAndLocation ) ) {\n            assert( childTracker );\n            assert(\
    \ childTracker->isSectionTracker() );\n            section = std::static_pointer_cast<SectionTracker>(\
    \ childTracker );\n        }\n        else {\n            section = std::make_shared<SectionTracker>(\
    \ nameAndLocation, ctx, &currentTracker );\n            currentTracker.addChild(\
    \ section );\n        }\n        if( !ctx.completedCycle() )\n            section->tryOpen();\n\
    \        return *section;\n    }\n\n    void SectionTracker::tryOpen() {\n   \
    \     if( !isComplete() )\n            open();\n    }\n\n    void SectionTracker::addInitialFilters(\
    \ std::vector<std::string> const& filters ) {\n        if( !filters.empty() )\
    \ {\n            m_filters.reserve( m_filters.size() + filters.size() + 2 );\n\
    \            m_filters.emplace_back(\"\"); // Root - should never be consulted\n\
    \            m_filters.emplace_back(\"\"); // Test Case - not a section filter\n\
    \            m_filters.insert( m_filters.end(), filters.begin(), filters.end()\
    \ );\n        }\n    }\n    void SectionTracker::addNextFilters( std::vector<std::string>\
    \ const& filters ) {\n        if( filters.size() > 1 )\n            m_filters.insert(\
    \ m_filters.end(), filters.begin()+1, filters.end() );\n    }\n\n} // namespace\
    \ TestCaseTracking\n\nusing TestCaseTracking::ITracker;\nusing TestCaseTracking::TrackerContext;\n\
    using TestCaseTracking::SectionTracker;\n\n} // namespace Catch\n\n#if defined(__clang__)\n\
    #    pragma clang diagnostic pop\n#endif\n// end catch_test_case_tracker.cpp\n\
    // start catch_test_registry.cpp\n\nnamespace Catch {\n\n    auto makeTestInvoker(\
    \ void(*testAsFunction)() ) noexcept -> ITestInvoker* {\n        return new(std::nothrow)\
    \ TestInvokerAsFunction( testAsFunction );\n    }\n\n    NameAndTags::NameAndTags(\
    \ StringRef const& name_ , StringRef const& tags_ ) noexcept : name( name_ ),\
    \ tags( tags_ ) {}\n\n    AutoReg::AutoReg( ITestInvoker* invoker, SourceLineInfo\
    \ const& lineInfo, StringRef const& classOrMethod, NameAndTags const& nameAndTags\
    \ ) noexcept {\n        CATCH_TRY {\n            getMutableRegistryHub()\n   \
    \                 .registerTest(\n                        makeTestCase(\n    \
    \                        invoker,\n                            extractClassName(\
    \ classOrMethod ),\n                            nameAndTags,\n               \
    \             lineInfo));\n        } CATCH_CATCH_ALL {\n            // Do not\
    \ throw when constructing global objects, instead register the exception to be\
    \ processed later\n            getMutableRegistryHub().registerStartupException();\n\
    \        }\n    }\n\n    AutoReg::~AutoReg() = default;\n}\n// end catch_test_registry.cpp\n\
    // start catch_test_spec.cpp\n\n#include <algorithm>\n#include <string>\n#include\
    \ <vector>\n#include <memory>\n\nnamespace Catch {\n\n    TestSpec::Pattern::Pattern(\
    \ std::string const& name )\n    : m_name( name )\n    {}\n\n    TestSpec::Pattern::~Pattern()\
    \ = default;\n\n    std::string const& TestSpec::Pattern::name() const {\n   \
    \     return m_name;\n    }\n\n    TestSpec::NamePattern::NamePattern( std::string\
    \ const& name, std::string const& filterString )\n    : Pattern( filterString\
    \ )\n    , m_wildcardPattern( toLower( name ), CaseSensitive::No )\n    {}\n\n\
    \    bool TestSpec::NamePattern::matches( TestCaseInfo const& testCase ) const\
    \ {\n        return m_wildcardPattern.matches( testCase.name );\n    }\n\n   \
    \ TestSpec::TagPattern::TagPattern( std::string const& tag, std::string const&\
    \ filterString )\n    : Pattern( filterString )\n    , m_tag( toLower( tag ) )\n\
    \    {}\n\n    bool TestSpec::TagPattern::matches( TestCaseInfo const& testCase\
    \ ) const {\n        return std::find(begin(testCase.lcaseTags),\n           \
    \              end(testCase.lcaseTags),\n                         m_tag) != end(testCase.lcaseTags);\n\
    \    }\n\n    TestSpec::ExcludedPattern::ExcludedPattern( PatternPtr const& underlyingPattern\
    \ )\n    : Pattern( underlyingPattern->name() )\n    , m_underlyingPattern( underlyingPattern\
    \ )\n    {}\n\n    bool TestSpec::ExcludedPattern::matches( TestCaseInfo const&\
    \ testCase ) const {\n        return !m_underlyingPattern->matches( testCase );\n\
    \    }\n\n    bool TestSpec::Filter::matches( TestCaseInfo const& testCase ) const\
    \ {\n        return std::all_of( m_patterns.begin(), m_patterns.end(), [&]( PatternPtr\
    \ const& p ){ return p->matches( testCase ); } );\n    }\n\n    std::string TestSpec::Filter::name()\
    \ const {\n        std::string name;\n        for( auto const& p : m_patterns\
    \ )\n            name += p->name();\n        return name;\n    }\n\n    bool TestSpec::hasFilters()\
    \ const {\n        return !m_filters.empty();\n    }\n\n    bool TestSpec::matches(\
    \ TestCaseInfo const& testCase ) const {\n        return std::any_of( m_filters.begin(),\
    \ m_filters.end(), [&]( Filter const& f ){ return f.matches( testCase ); } );\n\
    \    }\n\n    TestSpec::Matches TestSpec::matchesByFilter( std::vector<TestCase>\
    \ const& testCases, IConfig const& config ) const\n    {\n        Matches matches(\
    \ m_filters.size() );\n        std::transform( m_filters.begin(), m_filters.end(),\
    \ matches.begin(), [&]( Filter const& filter ){\n            std::vector<TestCase\
    \ const*> currentMatches;\n            for( auto const& test : testCases )\n \
    \               if( isThrowSafe( test, config ) && filter.matches( test ) )\n\
    \                    currentMatches.emplace_back( &test );\n            return\
    \ FilterMatch{ filter.name(), currentMatches };\n        } );\n        return\
    \ matches;\n    }\n\n    const TestSpec::vectorStrings& TestSpec::getInvalidArgs()\
    \ const{\n        return  (m_invalidArgs);\n    }\n\n}\n// end catch_test_spec.cpp\n\
    // start catch_test_spec_parser.cpp\n\nnamespace Catch {\n\n    TestSpecParser::TestSpecParser(\
    \ ITagAliasRegistry const& tagAliases ) : m_tagAliases( &tagAliases ) {}\n\n \
    \   TestSpecParser& TestSpecParser::parse( std::string const& arg ) {\n      \
    \  m_mode = None;\n        m_exclusion = false;\n        m_arg = m_tagAliases->expandAliases(\
    \ arg );\n        m_escapeChars.clear();\n        m_substring.reserve(m_arg.size());\n\
    \        m_patternName.reserve(m_arg.size());\n        m_realPatternPos = 0;\n\
    \n        for( m_pos = 0; m_pos < m_arg.size(); ++m_pos )\n          //if visitChar\
    \ fails\n           if( !visitChar( m_arg[m_pos] ) ){\n               m_testSpec.m_invalidArgs.push_back(arg);\n\
    \               break;\n           }\n        endMode();\n        return *this;\n\
    \    }\n    TestSpec TestSpecParser::testSpec() {\n        addFilter();\n    \
    \    return m_testSpec;\n    }\n    bool TestSpecParser::visitChar( char c ) {\n\
    \        if( (m_mode != EscapedName) && (c == '\\\\') ) {\n            escape();\n\
    \            addCharToPattern(c);\n            return true;\n        }else if((m_mode\
    \ != EscapedName) && (c == ',') )  {\n            return separate();\n       \
    \ }\n\n        switch( m_mode ) {\n        case None:\n            if( processNoneChar(\
    \ c ) )\n                return true;\n            break;\n        case Name:\n\
    \            processNameChar( c );\n            break;\n        case EscapedName:\n\
    \            endMode();\n            addCharToPattern(c);\n            return\
    \ true;\n        default:\n        case Tag:\n        case QuotedName:\n     \
    \       if( processOtherChar( c ) )\n                return true;\n          \
    \  break;\n        }\n\n        m_substring += c;\n        if( !isControlChar(\
    \ c ) ) {\n            m_patternName += c;\n            m_realPatternPos++;\n\
    \        }\n        return true;\n    }\n    // Two of the processing methods\
    \ return true to signal the caller to return\n    // without adding the given\
    \ character to the current pattern strings\n    bool TestSpecParser::processNoneChar(\
    \ char c ) {\n        switch( c ) {\n        case ' ':\n            return true;\n\
    \        case '~':\n            m_exclusion = true;\n            return false;\n\
    \        case '[':\n            startNewMode( Tag );\n            return false;\n\
    \        case '\"':\n            startNewMode( QuotedName );\n            return\
    \ false;\n        default:\n            startNewMode( Name );\n            return\
    \ false;\n        }\n    }\n    void TestSpecParser::processNameChar( char c )\
    \ {\n        if( c == '[' ) {\n            if( m_substring == \"exclude:\" )\n\
    \                m_exclusion = true;\n            else\n                endMode();\n\
    \            startNewMode( Tag );\n        }\n    }\n    bool TestSpecParser::processOtherChar(\
    \ char c ) {\n        if( !isControlChar( c ) )\n            return false;\n \
    \       m_substring += c;\n        endMode();\n        return true;\n    }\n \
    \   void TestSpecParser::startNewMode( Mode mode ) {\n        m_mode = mode;\n\
    \    }\n    void TestSpecParser::endMode() {\n        switch( m_mode ) {\n   \
    \     case Name:\n        case QuotedName:\n            return addNamePattern();\n\
    \        case Tag:\n            return addTagPattern();\n        case EscapedName:\n\
    \            revertBackToLastMode();\n            return;\n        case None:\n\
    \        default:\n            return startNewMode( None );\n        }\n    }\n\
    \    void TestSpecParser::escape() {\n        saveLastMode();\n        m_mode\
    \ = EscapedName;\n        m_escapeChars.push_back(m_realPatternPos);\n    }\n\
    \    bool TestSpecParser::isControlChar( char c ) const {\n        switch( m_mode\
    \ ) {\n            default:\n                return false;\n            case None:\n\
    \                return c == '~';\n            case Name:\n                return\
    \ c == '[';\n            case EscapedName:\n                return true;\n   \
    \         case QuotedName:\n                return c == '\"';\n            case\
    \ Tag:\n                return c == '[' || c == ']';\n        }\n    }\n\n   \
    \ void TestSpecParser::addFilter() {\n        if( !m_currentFilter.m_patterns.empty()\
    \ ) {\n            m_testSpec.m_filters.push_back( m_currentFilter );\n      \
    \      m_currentFilter = TestSpec::Filter();\n        }\n    }\n\n    void TestSpecParser::saveLastMode()\
    \ {\n      lastMode = m_mode;\n    }\n\n    void TestSpecParser::revertBackToLastMode()\
    \ {\n      m_mode = lastMode;\n    }\n\n    bool TestSpecParser::separate() {\n\
    \      if( (m_mode==QuotedName) || (m_mode==Tag) ){\n         //invalid argument,\
    \ signal failure to previous scope.\n         m_mode = None;\n         m_pos =\
    \ m_arg.size();\n         m_substring.clear();\n         m_patternName.clear();\n\
    \         m_realPatternPos = 0;\n         return false;\n      }\n      endMode();\n\
    \      addFilter();\n      return true; //success\n    }\n\n    std::string TestSpecParser::preprocessPattern()\
    \ {\n        std::string token = m_patternName;\n        for (std::size_t i =\
    \ 0; i < m_escapeChars.size(); ++i)\n            token = token.substr(0, m_escapeChars[i]\
    \ - i) + token.substr(m_escapeChars[i] - i + 1);\n        m_escapeChars.clear();\n\
    \        if (startsWith(token, \"exclude:\")) {\n            m_exclusion = true;\n\
    \            token = token.substr(8);\n        }\n\n        m_patternName.clear();\n\
    \        m_realPatternPos = 0;\n\n        return token;\n    }\n\n    void TestSpecParser::addNamePattern()\
    \ {\n        auto token = preprocessPattern();\n\n        if (!token.empty())\
    \ {\n            TestSpec::PatternPtr pattern = std::make_shared<TestSpec::NamePattern>(token,\
    \ m_substring);\n            if (m_exclusion)\n                pattern = std::make_shared<TestSpec::ExcludedPattern>(pattern);\n\
    \            m_currentFilter.m_patterns.push_back(pattern);\n        }\n     \
    \   m_substring.clear();\n        m_exclusion = false;\n        m_mode = None;\n\
    \    }\n\n    void TestSpecParser::addTagPattern() {\n        auto token = preprocessPattern();\n\
    \n        if (!token.empty()) {\n            // If the tag pattern is the \"hide\
    \ and tag\" shorthand (e.g. [.foo])\n            // we have to create a separate\
    \ hide tag and shorten the real one\n            if (token.size() > 1 && token[0]\
    \ == '.') {\n                token.erase(token.begin());\n                TestSpec::PatternPtr\
    \ pattern = std::make_shared<TestSpec::TagPattern>(\".\", m_substring);\n    \
    \            if (m_exclusion) {\n                    pattern = std::make_shared<TestSpec::ExcludedPattern>(pattern);\n\
    \                }\n                m_currentFilter.m_patterns.push_back(pattern);\n\
    \            }\n\n            TestSpec::PatternPtr pattern = std::make_shared<TestSpec::TagPattern>(token,\
    \ m_substring);\n\n            if (m_exclusion) {\n                pattern = std::make_shared<TestSpec::ExcludedPattern>(pattern);\n\
    \            }\n            m_currentFilter.m_patterns.push_back(pattern);\n \
    \       }\n        m_substring.clear();\n        m_exclusion = false;\n      \
    \  m_mode = None;\n    }\n\n    TestSpec parseTestSpec( std::string const& arg\
    \ ) {\n        return TestSpecParser( ITagAliasRegistry::get() ).parse( arg ).testSpec();\n\
    \    }\n\n} // namespace Catch\n// end catch_test_spec_parser.cpp\n// start catch_timer.cpp\n\
    \n#include <chrono>\n\nstatic const uint64_t nanosecondsInSecond = 1000000000;\n\
    \nnamespace Catch {\n\n    auto getCurrentNanosecondsSinceEpoch() -> uint64_t\
    \ {\n        return std::chrono::duration_cast<std::chrono::nanoseconds>( std::chrono::high_resolution_clock::now().time_since_epoch()\
    \ ).count();\n    }\n\n    namespace {\n        auto estimateClockResolution()\
    \ -> uint64_t {\n            uint64_t sum = 0;\n            static const uint64_t\
    \ iterations = 1000000;\n\n            auto startTime = getCurrentNanosecondsSinceEpoch();\n\
    \n            for( std::size_t i = 0; i < iterations; ++i ) {\n\n            \
    \    uint64_t ticks;\n                uint64_t baseTicks = getCurrentNanosecondsSinceEpoch();\n\
    \                do {\n                    ticks = getCurrentNanosecondsSinceEpoch();\n\
    \                } while( ticks == baseTicks );\n\n                auto delta\
    \ = ticks - baseTicks;\n                sum += delta;\n\n                // If\
    \ we have been calibrating for over 3 seconds -- the clock\n                //\
    \ is terrible and we should move on.\n                // TBD: How to signal that\
    \ the measured resolution is probably wrong?\n                if (ticks > startTime\
    \ + 3 * nanosecondsInSecond) {\n                    return sum / ( i + 1u );\n\
    \                }\n            }\n\n            // We're just taking the mean,\
    \ here. To do better we could take the std. dev and exclude outliers\n       \
    \     // - and potentially do more iterations if there's a high variance.\n  \
    \          return sum/iterations;\n        }\n    }\n    auto getEstimatedClockResolution()\
    \ -> uint64_t {\n        static auto s_resolution = estimateClockResolution();\n\
    \        return s_resolution;\n    }\n\n    void Timer::start() {\n       m_nanoseconds\
    \ = getCurrentNanosecondsSinceEpoch();\n    }\n    auto Timer::getElapsedNanoseconds()\
    \ const -> uint64_t {\n        return getCurrentNanosecondsSinceEpoch() - m_nanoseconds;\n\
    \    }\n    auto Timer::getElapsedMicroseconds() const -> uint64_t {\n       \
    \ return getElapsedNanoseconds()/1000;\n    }\n    auto Timer::getElapsedMilliseconds()\
    \ const -> unsigned int {\n        return static_cast<unsigned int>(getElapsedMicroseconds()/1000);\n\
    \    }\n    auto Timer::getElapsedSeconds() const -> double {\n        return\
    \ getElapsedMicroseconds()/1000000.0;\n    }\n\n} // namespace Catch\n// end catch_timer.cpp\n\
    // start catch_tostring.cpp\n\n#if defined(__clang__)\n#    pragma clang diagnostic\
    \ push\n#    pragma clang diagnostic ignored \"-Wexit-time-destructors\"\n#  \
    \  pragma clang diagnostic ignored \"-Wglobal-constructors\"\n#endif\n\n// Enable\
    \ specific decls locally\n#if !defined(CATCH_CONFIG_ENABLE_CHRONO_STRINGMAKER)\n\
    #define CATCH_CONFIG_ENABLE_CHRONO_STRINGMAKER\n#endif\n\n#include <cmath>\n#include\
    \ <iomanip>\n\nnamespace Catch {\n\nnamespace Detail {\n\n    const std::string\
    \ unprintableString = \"{?}\";\n\n    namespace {\n        const int hexThreshold\
    \ = 255;\n\n        struct Endianness {\n            enum Arch { Big, Little };\n\
    \n            static Arch which() {\n                int one = 1;\n          \
    \      // If the lowest byte we read is non-zero, we can assume\n            \
    \    // that little endian format is used.\n                auto value = *reinterpret_cast<char*>(&one);\n\
    \                return value ? Little : Big;\n            }\n        };\n   \
    \ }\n\n    std::string rawMemoryToString( const void *object, std::size_t size\
    \ ) {\n        // Reverse order for little endian architectures\n        int i\
    \ = 0, end = static_cast<int>( size ), inc = 1;\n        if( Endianness::which()\
    \ == Endianness::Little ) {\n            i = end-1;\n            end = inc = -1;\n\
    \        }\n\n        unsigned char const *bytes = static_cast<unsigned char const\
    \ *>(object);\n        ReusableStringStream rss;\n        rss << \"0x\" << std::setfill('0')\
    \ << std::hex;\n        for( ; i != end; i += inc )\n             rss << std::setw(2)\
    \ << static_cast<unsigned>(bytes[i]);\n       return rss.str();\n    }\n}\n\n\
    template<typename T>\nstd::string fpToString( T value, int precision ) {\n   \
    \ if (Catch::isnan(value)) {\n        return \"nan\";\n    }\n\n    ReusableStringStream\
    \ rss;\n    rss << std::setprecision( precision )\n        << std::fixed\n   \
    \     << value;\n    std::string d = rss.str();\n    std::size_t i = d.find_last_not_of(\
    \ '0' );\n    if( i != std::string::npos && i != d.size()-1 ) {\n        if( d[i]\
    \ == '.' )\n            i++;\n        d = d.substr( 0, i+1 );\n    }\n    return\
    \ d;\n}\n\n//// ======================================================= ////\n\
    //\n//   Out-of-line defs for full specialization of StringMaker\n//\n//// =======================================================\
    \ ////\n\nstd::string StringMaker<std::string>::convert(const std::string& str)\
    \ {\n    if (!getCurrentContext().getConfig()->showInvisibles()) {\n        return\
    \ '\"' + str + '\"';\n    }\n\n    std::string s(\"\\\"\");\n    for (char c :\
    \ str) {\n        switch (c) {\n        case '\\n':\n            s.append(\"\\\
    \\n\");\n            break;\n        case '\\t':\n            s.append(\"\\\\\
    t\");\n            break;\n        default:\n            s.push_back(c);\n   \
    \         break;\n        }\n    }\n    s.append(\"\\\"\");\n    return s;\n}\n\
    \n#ifdef CATCH_CONFIG_CPP17_STRING_VIEW\nstd::string StringMaker<std::string_view>::convert(std::string_view\
    \ str) {\n    return ::Catch::Detail::stringify(std::string{ str });\n}\n#endif\n\
    \nstd::string StringMaker<char const*>::convert(char const* str) {\n    if (str)\
    \ {\n        return ::Catch::Detail::stringify(std::string{ str });\n    } else\
    \ {\n        return{ \"{null string}\" };\n    }\n}\nstd::string StringMaker<char*>::convert(char*\
    \ str) {\n    if (str) {\n        return ::Catch::Detail::stringify(std::string{\
    \ str });\n    } else {\n        return{ \"{null string}\" };\n    }\n}\n\n#ifdef\
    \ CATCH_CONFIG_WCHAR\nstd::string StringMaker<std::wstring>::convert(const std::wstring&\
    \ wstr) {\n    std::string s;\n    s.reserve(wstr.size());\n    for (auto c :\
    \ wstr) {\n        s += (c <= 0xff) ? static_cast<char>(c) : '?';\n    }\n   \
    \ return ::Catch::Detail::stringify(s);\n}\n\n# ifdef CATCH_CONFIG_CPP17_STRING_VIEW\n\
    std::string StringMaker<std::wstring_view>::convert(std::wstring_view str) {\n\
    \    return StringMaker<std::wstring>::convert(std::wstring(str));\n}\n# endif\n\
    \nstd::string StringMaker<wchar_t const*>::convert(wchar_t const * str) {\n  \
    \  if (str) {\n        return ::Catch::Detail::stringify(std::wstring{ str });\n\
    \    } else {\n        return{ \"{null string}\" };\n    }\n}\nstd::string StringMaker<wchar_t\
    \ *>::convert(wchar_t * str) {\n    if (str) {\n        return ::Catch::Detail::stringify(std::wstring{\
    \ str });\n    } else {\n        return{ \"{null string}\" };\n    }\n}\n#endif\n\
    \n#if defined(CATCH_CONFIG_CPP17_BYTE)\n#include <cstddef>\nstd::string StringMaker<std::byte>::convert(std::byte\
    \ value) {\n    return ::Catch::Detail::stringify(std::to_integer<unsigned long\
    \ long>(value));\n}\n#endif // defined(CATCH_CONFIG_CPP17_BYTE)\n\nstd::string\
    \ StringMaker<int>::convert(int value) {\n    return ::Catch::Detail::stringify(static_cast<long\
    \ long>(value));\n}\nstd::string StringMaker<long>::convert(long value) {\n  \
    \  return ::Catch::Detail::stringify(static_cast<long long>(value));\n}\nstd::string\
    \ StringMaker<long long>::convert(long long value) {\n    ReusableStringStream\
    \ rss;\n    rss << value;\n    if (value > Detail::hexThreshold) {\n        rss\
    \ << \" (0x\" << std::hex << value << ')';\n    }\n    return rss.str();\n}\n\n\
    std::string StringMaker<unsigned int>::convert(unsigned int value) {\n    return\
    \ ::Catch::Detail::stringify(static_cast<unsigned long long>(value));\n}\nstd::string\
    \ StringMaker<unsigned long>::convert(unsigned long value) {\n    return ::Catch::Detail::stringify(static_cast<unsigned\
    \ long long>(value));\n}\nstd::string StringMaker<unsigned long long>::convert(unsigned\
    \ long long value) {\n    ReusableStringStream rss;\n    rss << value;\n    if\
    \ (value > Detail::hexThreshold) {\n        rss << \" (0x\" << std::hex << value\
    \ << ')';\n    }\n    return rss.str();\n}\n\nstd::string StringMaker<bool>::convert(bool\
    \ b) {\n    return b ? \"true\" : \"false\";\n}\n\nstd::string StringMaker<signed\
    \ char>::convert(signed char value) {\n    if (value == '\\r') {\n        return\
    \ \"'\\\\r'\";\n    } else if (value == '\\f') {\n        return \"'\\\\f'\";\n\
    \    } else if (value == '\\n') {\n        return \"'\\\\n'\";\n    } else if\
    \ (value == '\\t') {\n        return \"'\\\\t'\";\n    } else if ('\\0' <= value\
    \ && value < ' ') {\n        return ::Catch::Detail::stringify(static_cast<unsigned\
    \ int>(value));\n    } else {\n        char chstr[] = \"' '\";\n        chstr[1]\
    \ = value;\n        return chstr;\n    }\n}\nstd::string StringMaker<char>::convert(char\
    \ c) {\n    return ::Catch::Detail::stringify(static_cast<signed char>(c));\n\
    }\nstd::string StringMaker<unsigned char>::convert(unsigned char c) {\n    return\
    \ ::Catch::Detail::stringify(static_cast<char>(c));\n}\n\nstd::string StringMaker<std::nullptr_t>::convert(std::nullptr_t)\
    \ {\n    return \"nullptr\";\n}\n\nint StringMaker<float>::precision = 5;\n\n\
    std::string StringMaker<float>::convert(float value) {\n    return fpToString(value,\
    \ precision) + 'f';\n}\n\nint StringMaker<double>::precision = 10;\n\nstd::string\
    \ StringMaker<double>::convert(double value) {\n    return fpToString(value, precision);\n\
    }\n\nstd::string ratio_string<std::atto>::symbol() { return \"a\"; }\nstd::string\
    \ ratio_string<std::femto>::symbol() { return \"f\"; }\nstd::string ratio_string<std::pico>::symbol()\
    \ { return \"p\"; }\nstd::string ratio_string<std::nano>::symbol() { return \"\
    n\"; }\nstd::string ratio_string<std::micro>::symbol() { return \"u\"; }\nstd::string\
    \ ratio_string<std::milli>::symbol() { return \"m\"; }\n\n} // end namespace Catch\n\
    \n#if defined(__clang__)\n#    pragma clang diagnostic pop\n#endif\n\n// end catch_tostring.cpp\n\
    // start catch_totals.cpp\n\nnamespace Catch {\n\n    Counts Counts::operator\
    \ - ( Counts const& other ) const {\n        Counts diff;\n        diff.passed\
    \ = passed - other.passed;\n        diff.failed = failed - other.failed;\n   \
    \     diff.failedButOk = failedButOk - other.failedButOk;\n        return diff;\n\
    \    }\n\n    Counts& Counts::operator += ( Counts const& other ) {\n        passed\
    \ += other.passed;\n        failed += other.failed;\n        failedButOk += other.failedButOk;\n\
    \        return *this;\n    }\n\n    std::size_t Counts::total() const {\n   \
    \     return passed + failed + failedButOk;\n    }\n    bool Counts::allPassed()\
    \ const {\n        return failed == 0 && failedButOk == 0;\n    }\n    bool Counts::allOk()\
    \ const {\n        return failed == 0;\n    }\n\n    Totals Totals::operator -\
    \ ( Totals const& other ) const {\n        Totals diff;\n        diff.assertions\
    \ = assertions - other.assertions;\n        diff.testCases = testCases - other.testCases;\n\
    \        return diff;\n    }\n\n    Totals& Totals::operator += ( Totals const&\
    \ other ) {\n        assertions += other.assertions;\n        testCases += other.testCases;\n\
    \        return *this;\n    }\n\n    Totals Totals::delta( Totals const& prevTotals\
    \ ) const {\n        Totals diff = *this - prevTotals;\n        if( diff.assertions.failed\
    \ > 0 )\n            ++diff.testCases.failed;\n        else if( diff.assertions.failedButOk\
    \ > 0 )\n            ++diff.testCases.failedButOk;\n        else\n           \
    \ ++diff.testCases.passed;\n        return diff;\n    }\n\n}\n// end catch_totals.cpp\n\
    // start catch_uncaught_exceptions.cpp\n\n// start catch_config_uncaught_exceptions.hpp\n\
    \n//              Copyright Catch2 Authors\n// Distributed under the Boost Software\
    \ License, Version 1.0.\n//   (See accompanying file LICENSE_1_0.txt or copy at\n\
    //        https://www.boost.org/LICENSE_1_0.txt)\n\n// SPDX-License-Identifier:\
    \ BSL-1.0\n\n#ifndef CATCH_CONFIG_UNCAUGHT_EXCEPTIONS_HPP\n#define CATCH_CONFIG_UNCAUGHT_EXCEPTIONS_HPP\n\
    \n#if defined(_MSC_VER)\n#  if _MSC_VER >= 1900 // Visual Studio 2015 or newer\n\
    #    define CATCH_INTERNAL_CONFIG_CPP17_UNCAUGHT_EXCEPTIONS\n#  endif\n#endif\n\
    \n#include <exception>\n\n#if defined(__cpp_lib_uncaught_exceptions) \\\n    &&\
    \ !defined(CATCH_INTERNAL_CONFIG_CPP17_UNCAUGHT_EXCEPTIONS)\n\n#  define CATCH_INTERNAL_CONFIG_CPP17_UNCAUGHT_EXCEPTIONS\n\
    #endif // __cpp_lib_uncaught_exceptions\n\n#if defined(CATCH_INTERNAL_CONFIG_CPP17_UNCAUGHT_EXCEPTIONS)\
    \ \\\n    && !defined(CATCH_CONFIG_NO_CPP17_UNCAUGHT_EXCEPTIONS) \\\n    && !defined(CATCH_CONFIG_CPP17_UNCAUGHT_EXCEPTIONS)\n\
    \n#  define CATCH_CONFIG_CPP17_UNCAUGHT_EXCEPTIONS\n#endif\n\n#endif // CATCH_CONFIG_UNCAUGHT_EXCEPTIONS_HPP\n\
    // end catch_config_uncaught_exceptions.hpp\n#include <exception>\n\nnamespace\
    \ Catch {\n    bool uncaught_exceptions() {\n#if defined(CATCH_CONFIG_DISABLE_EXCEPTIONS)\n\
    \        return false;\n#elif defined(CATCH_CONFIG_CPP17_UNCAUGHT_EXCEPTIONS)\n\
    \        return std::uncaught_exceptions() > 0;\n#else\n        return std::uncaught_exception();\n\
    #endif\n  }\n} // end namespace Catch\n// end catch_uncaught_exceptions.cpp\n\
    // start catch_version.cpp\n\n#include <ostream>\n\nnamespace Catch {\n\n    Version::Version\n\
    \        (   unsigned int _majorVersion,\n            unsigned int _minorVersion,\n\
    \            unsigned int _patchNumber,\n            char const * const _branchName,\n\
    \            unsigned int _buildNumber )\n    :   majorVersion( _majorVersion\
    \ ),\n        minorVersion( _minorVersion ),\n        patchNumber( _patchNumber\
    \ ),\n        branchName( _branchName ),\n        buildNumber( _buildNumber )\n\
    \    {}\n\n    std::ostream& operator << ( std::ostream& os, Version const& version\
    \ ) {\n        os  << version.majorVersion << '.'\n            << version.minorVersion\
    \ << '.'\n            << version.patchNumber;\n        // branchName is never\
    \ null -> 0th char is \\0 if it is empty\n        if (version.branchName[0]) {\n\
    \            os << '-' << version.branchName\n               << '.' << version.buildNumber;\n\
    \        }\n        return os;\n    }\n\n    Version const& libraryVersion() {\n\
    \        static Version version( 2, 13, 2, \"\", 0 );\n        return version;\n\
    \    }\n\n}\n// end catch_version.cpp\n// start catch_wildcard_pattern.cpp\n\n\
    namespace Catch {\n\n    WildcardPattern::WildcardPattern( std::string const&\
    \ pattern,\n                                      CaseSensitive::Choice caseSensitivity\
    \ )\n    :   m_caseSensitivity( caseSensitivity ),\n        m_pattern( normaliseString(\
    \ pattern ) )\n    {\n        if( startsWith( m_pattern, '*' ) ) {\n         \
    \   m_pattern = m_pattern.substr( 1 );\n            m_wildcard = WildcardAtStart;\n\
    \        }\n        if( endsWith( m_pattern, '*' ) ) {\n            m_pattern\
    \ = m_pattern.substr( 0, m_pattern.size()-1 );\n            m_wildcard = static_cast<WildcardPosition>(\
    \ m_wildcard | WildcardAtEnd );\n        }\n    }\n\n    bool WildcardPattern::matches(\
    \ std::string const& str ) const {\n        switch( m_wildcard ) {\n         \
    \   case NoWildcard:\n                return m_pattern == normaliseString( str\
    \ );\n            case WildcardAtStart:\n                return endsWith( normaliseString(\
    \ str ), m_pattern );\n            case WildcardAtEnd:\n                return\
    \ startsWith( normaliseString( str ), m_pattern );\n            case WildcardAtBothEnds:\n\
    \                return contains( normaliseString( str ), m_pattern );\n     \
    \       default:\n                CATCH_INTERNAL_ERROR( \"Unknown enum\" );\n\
    \        }\n    }\n\n    std::string WildcardPattern::normaliseString( std::string\
    \ const& str ) const {\n        return trim( m_caseSensitivity == CaseSensitive::No\
    \ ? toLower( str ) : str );\n    }\n}\n// end catch_wildcard_pattern.cpp\n// start\
    \ catch_xmlwriter.cpp\n\n#include <iomanip>\n#include <type_traits>\n\nnamespace\
    \ Catch {\n\nnamespace {\n\n    size_t trailingBytes(unsigned char c) {\n    \
    \    if ((c & 0xE0) == 0xC0) {\n            return 2;\n        }\n        if ((c\
    \ & 0xF0) == 0xE0) {\n            return 3;\n        }\n        if ((c & 0xF8)\
    \ == 0xF0) {\n            return 4;\n        }\n        CATCH_INTERNAL_ERROR(\"\
    Invalid multibyte utf-8 start byte encountered\");\n    }\n\n    uint32_t headerValue(unsigned\
    \ char c) {\n        if ((c & 0xE0) == 0xC0) {\n            return c & 0x1F;\n\
    \        }\n        if ((c & 0xF0) == 0xE0) {\n            return c & 0x0F;\n\
    \        }\n        if ((c & 0xF8) == 0xF0) {\n            return c & 0x07;\n\
    \        }\n        CATCH_INTERNAL_ERROR(\"Invalid multibyte utf-8 start byte\
    \ encountered\");\n    }\n\n    void hexEscapeChar(std::ostream& os, unsigned\
    \ char c) {\n        std::ios_base::fmtflags f(os.flags());\n        os << \"\\\
    \\x\"\n            << std::uppercase << std::hex << std::setfill('0') << std::setw(2)\n\
    \            << static_cast<int>(c);\n        os.flags(f);\n    }\n\n    bool\
    \ shouldNewline(XmlFormatting fmt) {\n        return !!(static_cast<std::underlying_type<XmlFormatting>::type>(fmt\
    \ & XmlFormatting::Newline));\n    }\n\n    bool shouldIndent(XmlFormatting fmt)\
    \ {\n        return !!(static_cast<std::underlying_type<XmlFormatting>::type>(fmt\
    \ & XmlFormatting::Indent));\n    }\n\n} // anonymous namespace\n\n    XmlFormatting\
    \ operator | (XmlFormatting lhs, XmlFormatting rhs) {\n        return static_cast<XmlFormatting>(\n\
    \            static_cast<std::underlying_type<XmlFormatting>::type>(lhs) |\n \
    \           static_cast<std::underlying_type<XmlFormatting>::type>(rhs)\n    \
    \    );\n    }\n\n    XmlFormatting operator & (XmlFormatting lhs, XmlFormatting\
    \ rhs) {\n        return static_cast<XmlFormatting>(\n            static_cast<std::underlying_type<XmlFormatting>::type>(lhs)\
    \ &\n            static_cast<std::underlying_type<XmlFormatting>::type>(rhs)\n\
    \        );\n    }\n\n    XmlEncode::XmlEncode( std::string const& str, ForWhat\
    \ forWhat )\n    :   m_str( str ),\n        m_forWhat( forWhat )\n    {}\n\n \
    \   void XmlEncode::encodeTo( std::ostream& os ) const {\n        // Apostrophe\
    \ escaping not necessary if we always use \" to write attributes\n        // (see:\
    \ http://www.w3.org/TR/xml/#syntax)\n\n        for( std::size_t idx = 0; idx <\
    \ m_str.size(); ++ idx ) {\n            unsigned char c = m_str[idx];\n      \
    \      switch (c) {\n            case '<':   os << \"&lt;\"; break;\n        \
    \    case '&':   os << \"&amp;\"; break;\n\n            case '>':\n          \
    \      // See: http://www.w3.org/TR/xml/#syntax\n                if (idx > 2 &&\
    \ m_str[idx - 1] == ']' && m_str[idx - 2] == ']')\n                    os << \"\
    &gt;\";\n                else\n                    os << c;\n                break;\n\
    \n            case '\\\"':\n                if (m_forWhat == ForAttributes)\n\
    \                    os << \"&quot;\";\n                else\n               \
    \     os << c;\n                break;\n\n            default:\n             \
    \   // Check for control characters and invalid utf-8\n\n                // Escape\
    \ control characters in standard ascii\n                // see http://stackoverflow.com/questions/404107/why-are-control-characters-illegal-in-xml-1-0\n\
    \                if (c < 0x09 || (c > 0x0D && c < 0x20) || c == 0x7F) {\n    \
    \                hexEscapeChar(os, c);\n                    break;\n         \
    \       }\n\n                // Plain ASCII: Write it to stream\n            \
    \    if (c < 0x7F) {\n                    os << c;\n                    break;\n\
    \                }\n\n                // UTF-8 territory\n                // Check\
    \ if the encoding is valid and if it is not, hex escape bytes.\n             \
    \   // Important: We do not check the exact decoded values for validity, only\
    \ the encoding format\n                // First check that this bytes is a valid\
    \ lead byte:\n                // This means that it is not encoded as 1111 1XXX\n\
    \                // Or as 10XX XXXX\n                if (c <  0xC0 ||\n      \
    \              c >= 0xF8) {\n                    hexEscapeChar(os, c);\n     \
    \               break;\n                }\n\n                auto encBytes = trailingBytes(c);\n\
    \                // Are there enough bytes left to avoid accessing out-of-bounds\
    \ memory?\n                if (idx + encBytes - 1 >= m_str.size()) {\n       \
    \             hexEscapeChar(os, c);\n                    break;\n            \
    \    }\n                // The header is valid, check data\n                //\
    \ The next encBytes bytes must together be a valid utf-8\n                // This\
    \ means: bitpattern 10XX XXXX and the extracted value is sane (ish)\n        \
    \        bool valid = true;\n                uint32_t value = headerValue(c);\n\
    \                for (std::size_t n = 1; n < encBytes; ++n) {\n              \
    \      unsigned char nc = m_str[idx + n];\n                    valid &= ((nc &\
    \ 0xC0) == 0x80);\n                    value = (value << 6) | (nc & 0x3F);\n \
    \               }\n\n                if (\n                    // Wrong bit pattern\
    \ of following bytes\n                    (!valid) ||\n                    //\
    \ Overlong encodings\n                    (value < 0x80) ||\n                \
    \    (0x80 <= value && value < 0x800   && encBytes > 2) ||\n                 \
    \   (0x800 < value && value < 0x10000 && encBytes > 3) ||\n                  \
    \  // Encoded value out of range\n                    (value >= 0x110000)\n  \
    \                  ) {\n                    hexEscapeChar(os, c);\n          \
    \          break;\n                }\n\n                // If we got here, this\
    \ is in fact a valid(ish) utf-8 sequence\n                for (std::size_t n =\
    \ 0; n < encBytes; ++n) {\n                    os << m_str[idx + n];\n       \
    \         }\n                idx += encBytes - 1;\n                break;\n  \
    \          }\n        }\n    }\n\n    std::ostream& operator << ( std::ostream&\
    \ os, XmlEncode const& xmlEncode ) {\n        xmlEncode.encodeTo( os );\n    \
    \    return os;\n    }\n\n    XmlWriter::ScopedElement::ScopedElement( XmlWriter*\
    \ writer, XmlFormatting fmt )\n    :   m_writer( writer ),\n        m_fmt(fmt)\n\
    \    {}\n\n    XmlWriter::ScopedElement::ScopedElement( ScopedElement&& other\
    \ ) noexcept\n    :   m_writer( other.m_writer ),\n        m_fmt(other.m_fmt)\n\
    \    {\n        other.m_writer = nullptr;\n        other.m_fmt = XmlFormatting::None;\n\
    \    }\n    XmlWriter::ScopedElement& XmlWriter::ScopedElement::operator=( ScopedElement&&\
    \ other ) noexcept {\n        if ( m_writer ) {\n            m_writer->endElement();\n\
    \        }\n        m_writer = other.m_writer;\n        other.m_writer = nullptr;\n\
    \        m_fmt = other.m_fmt;\n        other.m_fmt = XmlFormatting::None;\n  \
    \      return *this;\n    }\n\n    XmlWriter::ScopedElement::~ScopedElement()\
    \ {\n        if (m_writer) {\n            m_writer->endElement(m_fmt);\n     \
    \   }\n    }\n\n    XmlWriter::ScopedElement& XmlWriter::ScopedElement::writeText(\
    \ std::string const& text, XmlFormatting fmt ) {\n        m_writer->writeText(\
    \ text, fmt );\n        return *this;\n    }\n\n    XmlWriter::XmlWriter( std::ostream&\
    \ os ) : m_os( os )\n    {\n        writeDeclaration();\n    }\n\n    XmlWriter::~XmlWriter()\
    \ {\n        while (!m_tags.empty()) {\n            endElement();\n        }\n\
    \        newlineIfNecessary();\n    }\n\n    XmlWriter& XmlWriter::startElement(\
    \ std::string const& name, XmlFormatting fmt ) {\n        ensureTagClosed();\n\
    \        newlineIfNecessary();\n        if (shouldIndent(fmt)) {\n           \
    \ m_os << m_indent;\n            m_indent += \"  \";\n        }\n        m_os\
    \ << '<' << name;\n        m_tags.push_back( name );\n        m_tagIsOpen = true;\n\
    \        applyFormatting(fmt);\n        return *this;\n    }\n\n    XmlWriter::ScopedElement\
    \ XmlWriter::scopedElement( std::string const& name, XmlFormatting fmt ) {\n \
    \       ScopedElement scoped( this, fmt );\n        startElement( name, fmt );\n\
    \        return scoped;\n    }\n\n    XmlWriter& XmlWriter::endElement(XmlFormatting\
    \ fmt) {\n        m_indent = m_indent.substr(0, m_indent.size() - 2);\n\n    \
    \    if( m_tagIsOpen ) {\n            m_os << \"/>\";\n            m_tagIsOpen\
    \ = false;\n        } else {\n            newlineIfNecessary();\n            if\
    \ (shouldIndent(fmt)) {\n                m_os << m_indent;\n            }\n  \
    \          m_os << \"</\" << m_tags.back() << \">\";\n        }\n        m_os\
    \ << std::flush;\n        applyFormatting(fmt);\n        m_tags.pop_back();\n\
    \        return *this;\n    }\n\n    XmlWriter& XmlWriter::writeAttribute( std::string\
    \ const& name, std::string const& attribute ) {\n        if( !name.empty() &&\
    \ !attribute.empty() )\n            m_os << ' ' << name << \"=\\\"\" << XmlEncode(\
    \ attribute, XmlEncode::ForAttributes ) << '\"';\n        return *this;\n    }\n\
    \n    XmlWriter& XmlWriter::writeAttribute( std::string const& name, bool attribute\
    \ ) {\n        m_os << ' ' << name << \"=\\\"\" << ( attribute ? \"true\" : \"\
    false\" ) << '\"';\n        return *this;\n    }\n\n    XmlWriter& XmlWriter::writeText(\
    \ std::string const& text, XmlFormatting fmt) {\n        if( !text.empty() ){\n\
    \            bool tagWasOpen = m_tagIsOpen;\n            ensureTagClosed();\n\
    \            if (tagWasOpen && shouldIndent(fmt)) {\n                m_os << m_indent;\n\
    \            }\n            m_os << XmlEncode( text );\n            applyFormatting(fmt);\n\
    \        }\n        return *this;\n    }\n\n    XmlWriter& XmlWriter::writeComment(\
    \ std::string const& text, XmlFormatting fmt) {\n        ensureTagClosed();\n\
    \        if (shouldIndent(fmt)) {\n            m_os << m_indent;\n        }\n\
    \        m_os << \"<!--\" << text << \"-->\";\n        applyFormatting(fmt);\n\
    \        return *this;\n    }\n\n    void XmlWriter::writeStylesheetRef( std::string\
    \ const& url ) {\n        m_os << \"<?xml-stylesheet type=\\\"text/xsl\\\" href=\\\
    \"\" << url << \"\\\"?>\\n\";\n    }\n\n    XmlWriter& XmlWriter::writeBlankLine()\
    \ {\n        ensureTagClosed();\n        m_os << '\\n';\n        return *this;\n\
    \    }\n\n    void XmlWriter::ensureTagClosed() {\n        if( m_tagIsOpen ) {\n\
    \            m_os << '>' << std::flush;\n            newlineIfNecessary();\n \
    \           m_tagIsOpen = false;\n        }\n    }\n\n    void XmlWriter::applyFormatting(XmlFormatting\
    \ fmt) {\n        m_needsNewline = shouldNewline(fmt);\n    }\n\n    void XmlWriter::writeDeclaration()\
    \ {\n        m_os << \"<?xml version=\\\"1.0\\\" encoding=\\\"UTF-8\\\"?>\\n\"\
    ;\n    }\n\n    void XmlWriter::newlineIfNecessary() {\n        if( m_needsNewline\
    \ ) {\n            m_os << std::endl;\n            m_needsNewline = false;\n \
    \       }\n    }\n}\n// end catch_xmlwriter.cpp\n// start catch_reporter_bases.cpp\n\
    \n#include <cstring>\n#include <cfloat>\n#include <cstdio>\n#include <cassert>\n\
    #include <memory>\n\nnamespace Catch {\n    void prepareExpandedExpression(AssertionResult&\
    \ result) {\n        result.getExpandedExpression();\n    }\n\n    // Because\
    \ formatting using c++ streams is stateful, drop down to C is required\n    //\
    \ Alternatively we could use stringstream, but its performance is... not good.\n\
    \    std::string getFormattedDuration( double duration ) {\n        // Max exponent\
    \ + 1 is required to represent the whole part\n        // + 1 for decimal point\n\
    \        // + 3 for the 3 decimal places\n        // + 1 for null terminator\n\
    \        const std::size_t maxDoubleSize = DBL_MAX_10_EXP + 1 + 1 + 3 + 1;\n \
    \       char buffer[maxDoubleSize];\n\n        // Save previous errno, to prevent\
    \ sprintf from overwriting it\n        ErrnoGuard guard;\n#ifdef _MSC_VER\n  \
    \      sprintf_s(buffer, \"%.3f\", duration);\n#else\n        std::sprintf(buffer,\
    \ \"%.3f\", duration);\n#endif\n        return std::string(buffer);\n    }\n\n\
    \    bool shouldShowDuration( IConfig const& config, double duration ) {\n   \
    \     if ( config.showDurations() == ShowDurations::Always ) {\n            return\
    \ true;\n        }\n        if ( config.showDurations() == ShowDurations::Never\
    \ ) {\n            return false;\n        }\n        const double min = config.minDuration();\n\
    \        return min >= 0 && duration >= min;\n    }\n\n    std::string serializeFilters(\
    \ std::vector<std::string> const& container ) {\n        ReusableStringStream\
    \ oss;\n        bool first = true;\n        for (auto&& filter : container)\n\
    \        {\n            if (!first)\n                oss << ' ';\n           \
    \ else\n                first = false;\n\n            oss << filter;\n       \
    \ }\n        return oss.str();\n    }\n\n    TestEventListenerBase::TestEventListenerBase(ReporterConfig\
    \ const & _config)\n        :StreamingReporterBase(_config) {}\n\n    std::set<Verbosity>\
    \ TestEventListenerBase::getSupportedVerbosities() {\n        return { Verbosity::Quiet,\
    \ Verbosity::Normal, Verbosity::High };\n    }\n\n    void TestEventListenerBase::assertionStarting(AssertionInfo\
    \ const &) {}\n\n    bool TestEventListenerBase::assertionEnded(AssertionStats\
    \ const &) {\n        return false;\n    }\n\n} // end namespace Catch\n// end\
    \ catch_reporter_bases.cpp\n// start catch_reporter_compact.cpp\n\nnamespace {\n\
    \n#ifdef CATCH_PLATFORM_MAC\n    const char* failedString() { return \"FAILED\"\
    ; }\n    const char* passedString() { return \"PASSED\"; }\n#else\n    const char*\
    \ failedString() { return \"failed\"; }\n    const char* passedString() { return\
    \ \"passed\"; }\n#endif\n\n    // Colour::LightGrey\n    Catch::Colour::Code dimColour()\
    \ { return Catch::Colour::FileName; }\n\n    std::string bothOrAll( std::size_t\
    \ count ) {\n        return count == 1 ? std::string() :\n               count\
    \ == 2 ? \"both \" : \"all \" ;\n    }\n\n} // anon namespace\n\nnamespace Catch\
    \ {\nnamespace {\n// Colour, message variants:\n// - white: No tests ran.\n//\
    \ -   red: Failed [both/all] N test cases, failed [both/all] M assertions.\n//\
    \ - white: Passed [both/all] N test cases (no assertions).\n// -   red: Failed\
    \ N tests cases, failed M assertions.\n// - green: Passed [both/all] N tests cases\
    \ with M assertions.\nvoid printTotals(std::ostream& out, const Totals& totals)\
    \ {\n    if (totals.testCases.total() == 0) {\n        out << \"No tests ran.\"\
    ;\n    } else if (totals.testCases.failed == totals.testCases.total()) {\n   \
    \     Colour colour(Colour::ResultError);\n        const std::string qualify_assertions_failed\
    \ =\n            totals.assertions.failed == totals.assertions.total() ?\n   \
    \         bothOrAll(totals.assertions.failed) : std::string();\n        out <<\n\
    \            \"Failed \" << bothOrAll(totals.testCases.failed)\n            <<\
    \ pluralise(totals.testCases.failed, \"test case\") << \", \"\n            \"\
    failed \" << qualify_assertions_failed <<\n            pluralise(totals.assertions.failed,\
    \ \"assertion\") << '.';\n    } else if (totals.assertions.total() == 0) {\n \
    \       out <<\n            \"Passed \" << bothOrAll(totals.testCases.total())\n\
    \            << pluralise(totals.testCases.total(), \"test case\")\n         \
    \   << \" (no assertions).\";\n    } else if (totals.assertions.failed) {\n  \
    \      Colour colour(Colour::ResultError);\n        out <<\n            \"Failed\
    \ \" << pluralise(totals.testCases.failed, \"test case\") << \", \"\n        \
    \    \"failed \" << pluralise(totals.assertions.failed, \"assertion\") << '.';\n\
    \    } else {\n        Colour colour(Colour::ResultSuccess);\n        out <<\n\
    \            \"Passed \" << bothOrAll(totals.testCases.passed)\n            <<\
    \ pluralise(totals.testCases.passed, \"test case\") <<\n            \" with \"\
    \ << pluralise(totals.assertions.passed, \"assertion\") << '.';\n    }\n}\n\n\
    // Implementation of CompactReporter formatting\nclass AssertionPrinter {\npublic:\n\
    \    AssertionPrinter& operator= (AssertionPrinter const&) = delete;\n    AssertionPrinter(AssertionPrinter\
    \ const&) = delete;\n    AssertionPrinter(std::ostream& _stream, AssertionStats\
    \ const& _stats, bool _printInfoMessages)\n        : stream(_stream)\n       \
    \ , result(_stats.assertionResult)\n        , messages(_stats.infoMessages)\n\
    \        , itMessage(_stats.infoMessages.begin())\n        , printInfoMessages(_printInfoMessages)\
    \ {}\n\n    void print() {\n        printSourceInfo();\n\n        itMessage =\
    \ messages.begin();\n\n        switch (result.getResultType()) {\n        case\
    \ ResultWas::Ok:\n            printResultType(Colour::ResultSuccess, passedString());\n\
    \            printOriginalExpression();\n            printReconstructedExpression();\n\
    \            if (!result.hasExpression())\n                printRemainingMessages(Colour::None);\n\
    \            else\n                printRemainingMessages();\n            break;\n\
    \        case ResultWas::ExpressionFailed:\n            if (result.isOk())\n \
    \               printResultType(Colour::ResultSuccess, failedString() + std::string(\"\
    \ - but was ok\"));\n            else\n                printResultType(Colour::Error,\
    \ failedString());\n            printOriginalExpression();\n            printReconstructedExpression();\n\
    \            printRemainingMessages();\n            break;\n        case ResultWas::ThrewException:\n\
    \            printResultType(Colour::Error, failedString());\n            printIssue(\"\
    unexpected exception with message:\");\n            printMessage();\n        \
    \    printExpressionWas();\n            printRemainingMessages();\n          \
    \  break;\n        case ResultWas::FatalErrorCondition:\n            printResultType(Colour::Error,\
    \ failedString());\n            printIssue(\"fatal error condition with message:\"\
    );\n            printMessage();\n            printExpressionWas();\n         \
    \   printRemainingMessages();\n            break;\n        case ResultWas::DidntThrowException:\n\
    \            printResultType(Colour::Error, failedString());\n            printIssue(\"\
    expected exception, got none\");\n            printExpressionWas();\n        \
    \    printRemainingMessages();\n            break;\n        case ResultWas::Info:\n\
    \            printResultType(Colour::None, \"info\");\n            printMessage();\n\
    \            printRemainingMessages();\n            break;\n        case ResultWas::Warning:\n\
    \            printResultType(Colour::None, \"warning\");\n            printMessage();\n\
    \            printRemainingMessages();\n            break;\n        case ResultWas::ExplicitFailure:\n\
    \            printResultType(Colour::Error, failedString());\n            printIssue(\"\
    explicitly\");\n            printRemainingMessages(Colour::None);\n          \
    \  break;\n            // These cases are here to prevent compiler warnings\n\
    \        case ResultWas::Unknown:\n        case ResultWas::FailureBit:\n     \
    \   case ResultWas::Exception:\n            printResultType(Colour::Error, \"\
    ** internal error **\");\n            break;\n        }\n    }\n\nprivate:\n \
    \   void printSourceInfo() const {\n        Colour colourGuard(Colour::FileName);\n\
    \        stream << result.getSourceInfo() << ':';\n    }\n\n    void printResultType(Colour::Code\
    \ colour, std::string const& passOrFail) const {\n        if (!passOrFail.empty())\
    \ {\n            {\n                Colour colourGuard(colour);\n            \
    \    stream << ' ' << passOrFail;\n            }\n            stream << ':';\n\
    \        }\n    }\n\n    void printIssue(std::string const& issue) const {\n \
    \       stream << ' ' << issue;\n    }\n\n    void printExpressionWas() {\n  \
    \      if (result.hasExpression()) {\n            stream << ';';\n           \
    \ {\n                Colour colour(dimColour());\n                stream << \"\
    \ expression was:\";\n            }\n            printOriginalExpression();\n\
    \        }\n    }\n\n    void printOriginalExpression() const {\n        if (result.hasExpression())\
    \ {\n            stream << ' ' << result.getExpression();\n        }\n    }\n\n\
    \    void printReconstructedExpression() const {\n        if (result.hasExpandedExpression())\
    \ {\n            {\n                Colour colour(dimColour());\n            \
    \    stream << \" for: \";\n            }\n            stream << result.getExpandedExpression();\n\
    \        }\n    }\n\n    void printMessage() {\n        if (itMessage != messages.end())\
    \ {\n            stream << \" '\" << itMessage->message << '\\'';\n          \
    \  ++itMessage;\n        }\n    }\n\n    void printRemainingMessages(Colour::Code\
    \ colour = dimColour()) {\n        if (itMessage == messages.end())\n        \
    \    return;\n\n        const auto itEnd = messages.cend();\n        const auto\
    \ N = static_cast<std::size_t>(std::distance(itMessage, itEnd));\n\n        {\n\
    \            Colour colourGuard(colour);\n            stream << \" with \" <<\
    \ pluralise(N, \"message\") << ':';\n        }\n\n        while (itMessage !=\
    \ itEnd) {\n            // If this assertion is a warning ignore any INFO messages\n\
    \            if (printInfoMessages || itMessage->type != ResultWas::Info) {\n\
    \                printMessage();\n                if (itMessage != itEnd) {\n\
    \                    Colour colourGuard(dimColour());\n                    stream\
    \ << \" and\";\n                }\n                continue;\n            }\n\
    \            ++itMessage;\n        }\n    }\n\nprivate:\n    std::ostream& stream;\n\
    \    AssertionResult const& result;\n    std::vector<MessageInfo> messages;\n\
    \    std::vector<MessageInfo>::const_iterator itMessage;\n    bool printInfoMessages;\n\
    };\n\n} // anon namespace\n\n        std::string CompactReporter::getDescription()\
    \ {\n            return \"Reports test results on a single line, suitable for\
    \ IDEs\";\n        }\n\n        void CompactReporter::noMatchingTestCases( std::string\
    \ const& spec ) {\n            stream << \"No test cases matched '\" << spec <<\
    \ '\\'' << std::endl;\n        }\n\n        void CompactReporter::assertionStarting(\
    \ AssertionInfo const& ) {}\n\n        bool CompactReporter::assertionEnded( AssertionStats\
    \ const& _assertionStats ) {\n            AssertionResult const& result = _assertionStats.assertionResult;\n\
    \n            bool printInfoMessages = true;\n\n            // Drop out if result\
    \ was successful and we're not printing those\n            if( !m_config->includeSuccessfulResults()\
    \ && result.isOk() ) {\n                if( result.getResultType() != ResultWas::Warning\
    \ )\n                    return false;\n                printInfoMessages = false;\n\
    \            }\n\n            AssertionPrinter printer( stream, _assertionStats,\
    \ printInfoMessages );\n            printer.print();\n\n            stream <<\
    \ std::endl;\n            return true;\n        }\n\n        void CompactReporter::sectionEnded(SectionStats\
    \ const& _sectionStats) {\n            double dur = _sectionStats.durationInSeconds;\n\
    \            if ( shouldShowDuration( *m_config, dur ) ) {\n                stream\
    \ << getFormattedDuration( dur ) << \" s: \" << _sectionStats.sectionInfo.name\
    \ << std::endl;\n            }\n        }\n\n        void CompactReporter::testRunEnded(\
    \ TestRunStats const& _testRunStats ) {\n            printTotals( stream, _testRunStats.totals\
    \ );\n            stream << '\\n' << std::endl;\n            StreamingReporterBase::testRunEnded(\
    \ _testRunStats );\n        }\n\n        CompactReporter::~CompactReporter() {}\n\
    \n    CATCH_REGISTER_REPORTER( \"compact\", CompactReporter )\n\n} // end namespace\
    \ Catch\n// end catch_reporter_compact.cpp\n// start catch_reporter_console.cpp\n\
    \n#include <cfloat>\n#include <cstdio>\n\n#if defined(_MSC_VER)\n#pragma warning(push)\n\
    #pragma warning(disable:4061) // Not all labels are EXPLICITLY handled in switch\n\
    \ // Note that 4062 (not all labels are handled and default is missing) is enabled\n\
    #endif\n\n#if defined(__clang__)\n#  pragma clang diagnostic push\n// For simplicity,\
    \ benchmarking-only helpers are always enabled\n#  pragma clang diagnostic ignored\
    \ \"-Wunused-function\"\n#endif\n\nnamespace Catch {\n\nnamespace {\n\n// Formatter\
    \ impl for ConsoleReporter\nclass ConsoleAssertionPrinter {\npublic:\n    ConsoleAssertionPrinter&\
    \ operator= (ConsoleAssertionPrinter const&) = delete;\n    ConsoleAssertionPrinter(ConsoleAssertionPrinter\
    \ const&) = delete;\n    ConsoleAssertionPrinter(std::ostream& _stream, AssertionStats\
    \ const& _stats, bool _printInfoMessages)\n        : stream(_stream),\n      \
    \  stats(_stats),\n        result(_stats.assertionResult),\n        colour(Colour::None),\n\
    \        message(result.getMessage()),\n        messages(_stats.infoMessages),\n\
    \        printInfoMessages(_printInfoMessages) {\n        switch (result.getResultType())\
    \ {\n        case ResultWas::Ok:\n            colour = Colour::Success;\n    \
    \        passOrFail = \"PASSED\";\n            //if( result.hasMessage() )\n \
    \           if (_stats.infoMessages.size() == 1)\n                messageLabel\
    \ = \"with message\";\n            if (_stats.infoMessages.size() > 1)\n     \
    \           messageLabel = \"with messages\";\n            break;\n        case\
    \ ResultWas::ExpressionFailed:\n            if (result.isOk()) {\n           \
    \     colour = Colour::Success;\n                passOrFail = \"FAILED - but was\
    \ ok\";\n            } else {\n                colour = Colour::Error;\n     \
    \           passOrFail = \"FAILED\";\n            }\n            if (_stats.infoMessages.size()\
    \ == 1)\n                messageLabel = \"with message\";\n            if (_stats.infoMessages.size()\
    \ > 1)\n                messageLabel = \"with messages\";\n            break;\n\
    \        case ResultWas::ThrewException:\n            colour = Colour::Error;\n\
    \            passOrFail = \"FAILED\";\n            messageLabel = \"due to unexpected\
    \ exception with \";\n            if (_stats.infoMessages.size() == 1)\n     \
    \           messageLabel += \"message\";\n            if (_stats.infoMessages.size()\
    \ > 1)\n                messageLabel += \"messages\";\n            break;\n  \
    \      case ResultWas::FatalErrorCondition:\n            colour = Colour::Error;\n\
    \            passOrFail = \"FAILED\";\n            messageLabel = \"due to a fatal\
    \ error condition\";\n            break;\n        case ResultWas::DidntThrowException:\n\
    \            colour = Colour::Error;\n            passOrFail = \"FAILED\";\n \
    \           messageLabel = \"because no exception was thrown where one was expected\"\
    ;\n            break;\n        case ResultWas::Info:\n            messageLabel\
    \ = \"info\";\n            break;\n        case ResultWas::Warning:\n        \
    \    messageLabel = \"warning\";\n            break;\n        case ResultWas::ExplicitFailure:\n\
    \            passOrFail = \"FAILED\";\n            colour = Colour::Error;\n \
    \           if (_stats.infoMessages.size() == 1)\n                messageLabel\
    \ = \"explicitly with message\";\n            if (_stats.infoMessages.size() >\
    \ 1)\n                messageLabel = \"explicitly with messages\";\n         \
    \   break;\n            // These cases are here to prevent compiler warnings\n\
    \        case ResultWas::Unknown:\n        case ResultWas::FailureBit:\n     \
    \   case ResultWas::Exception:\n            passOrFail = \"** internal error **\"\
    ;\n            colour = Colour::Error;\n            break;\n        }\n    }\n\
    \n    void print() const {\n        printSourceInfo();\n        if (stats.totals.assertions.total()\
    \ > 0) {\n            printResultType();\n            printOriginalExpression();\n\
    \            printReconstructedExpression();\n        } else {\n            stream\
    \ << '\\n';\n        }\n        printMessage();\n    }\n\nprivate:\n    void printResultType()\
    \ const {\n        if (!passOrFail.empty()) {\n            Colour colourGuard(colour);\n\
    \            stream << passOrFail << \":\\n\";\n        }\n    }\n    void printOriginalExpression()\
    \ const {\n        if (result.hasExpression()) {\n            Colour colourGuard(Colour::OriginalExpression);\n\
    \            stream << \"  \";\n            stream << result.getExpressionInMacro();\n\
    \            stream << '\\n';\n        }\n    }\n    void printReconstructedExpression()\
    \ const {\n        if (result.hasExpandedExpression()) {\n            stream <<\
    \ \"with expansion:\\n\";\n            Colour colourGuard(Colour::ReconstructedExpression);\n\
    \            stream << Column(result.getExpandedExpression()).indent(2) << '\\\
    n';\n        }\n    }\n    void printMessage() const {\n        if (!messageLabel.empty())\n\
    \            stream << messageLabel << ':' << '\\n';\n        for (auto const&\
    \ msg : messages) {\n            // If this assertion is a warning ignore any\
    \ INFO messages\n            if (printInfoMessages || msg.type != ResultWas::Info)\n\
    \                stream << Column(msg.message).indent(2) << '\\n';\n        }\n\
    \    }\n    void printSourceInfo() const {\n        Colour colourGuard(Colour::FileName);\n\
    \        stream << result.getSourceInfo() << \": \";\n    }\n\n    std::ostream&\
    \ stream;\n    AssertionStats const& stats;\n    AssertionResult const& result;\n\
    \    Colour::Code colour;\n    std::string passOrFail;\n    std::string messageLabel;\n\
    \    std::string message;\n    std::vector<MessageInfo> messages;\n    bool printInfoMessages;\n\
    };\n\nstd::size_t makeRatio(std::size_t number, std::size_t total) {\n    std::size_t\
    \ ratio = total > 0 ? CATCH_CONFIG_CONSOLE_WIDTH * number / total : 0;\n    return\
    \ (ratio == 0 && number > 0) ? 1 : ratio;\n}\n\nstd::size_t& findMax(std::size_t&\
    \ i, std::size_t& j, std::size_t& k) {\n    if (i > j && i > k)\n        return\
    \ i;\n    else if (j > k)\n        return j;\n    else\n        return k;\n}\n\
    \nstruct ColumnInfo {\n    enum Justification { Left, Right };\n    std::string\
    \ name;\n    int width;\n    Justification justification;\n};\nstruct ColumnBreak\
    \ {};\nstruct RowBreak {};\n\nclass Duration {\n    enum class Unit {\n      \
    \  Auto,\n        Nanoseconds,\n        Microseconds,\n        Milliseconds,\n\
    \        Seconds,\n        Minutes\n    };\n    static const uint64_t s_nanosecondsInAMicrosecond\
    \ = 1000;\n    static const uint64_t s_nanosecondsInAMillisecond = 1000 * s_nanosecondsInAMicrosecond;\n\
    \    static const uint64_t s_nanosecondsInASecond = 1000 * s_nanosecondsInAMillisecond;\n\
    \    static const uint64_t s_nanosecondsInAMinute = 60 * s_nanosecondsInASecond;\n\
    \n    double m_inNanoseconds;\n    Unit m_units;\n\npublic:\n    explicit Duration(double\
    \ inNanoseconds, Unit units = Unit::Auto)\n        : m_inNanoseconds(inNanoseconds),\n\
    \        m_units(units) {\n        if (m_units == Unit::Auto) {\n            if\
    \ (m_inNanoseconds < s_nanosecondsInAMicrosecond)\n                m_units = Unit::Nanoseconds;\n\
    \            else if (m_inNanoseconds < s_nanosecondsInAMillisecond)\n       \
    \         m_units = Unit::Microseconds;\n            else if (m_inNanoseconds\
    \ < s_nanosecondsInASecond)\n                m_units = Unit::Milliseconds;\n \
    \           else if (m_inNanoseconds < s_nanosecondsInAMinute)\n             \
    \   m_units = Unit::Seconds;\n            else\n                m_units = Unit::Minutes;\n\
    \        }\n\n    }\n\n    auto value() const -> double {\n        switch (m_units)\
    \ {\n        case Unit::Microseconds:\n            return m_inNanoseconds / static_cast<double>(s_nanosecondsInAMicrosecond);\n\
    \        case Unit::Milliseconds:\n            return m_inNanoseconds / static_cast<double>(s_nanosecondsInAMillisecond);\n\
    \        case Unit::Seconds:\n            return m_inNanoseconds / static_cast<double>(s_nanosecondsInASecond);\n\
    \        case Unit::Minutes:\n            return m_inNanoseconds / static_cast<double>(s_nanosecondsInAMinute);\n\
    \        default:\n            return m_inNanoseconds;\n        }\n    }\n   \
    \ auto unitsAsString() const -> std::string {\n        switch (m_units) {\n  \
    \      case Unit::Nanoseconds:\n            return \"ns\";\n        case Unit::Microseconds:\n\
    \            return \"us\";\n        case Unit::Milliseconds:\n            return\
    \ \"ms\";\n        case Unit::Seconds:\n            return \"s\";\n        case\
    \ Unit::Minutes:\n            return \"m\";\n        default:\n            return\
    \ \"** internal error **\";\n        }\n\n    }\n    friend auto operator << (std::ostream&\
    \ os, Duration const& duration) -> std::ostream& {\n        return os << duration.value()\
    \ << ' ' << duration.unitsAsString();\n    }\n};\n} // end anon namespace\n\n\
    class TablePrinter {\n    std::ostream& m_os;\n    std::vector<ColumnInfo> m_columnInfos;\n\
    \    std::ostringstream m_oss;\n    int m_currentColumn = -1;\n    bool m_isOpen\
    \ = false;\n\npublic:\n    TablePrinter( std::ostream& os, std::vector<ColumnInfo>\
    \ columnInfos )\n    :   m_os( os ),\n        m_columnInfos( std::move( columnInfos\
    \ ) ) {}\n\n    auto columnInfos() const -> std::vector<ColumnInfo> const& {\n\
    \        return m_columnInfos;\n    }\n\n    void open() {\n        if (!m_isOpen)\
    \ {\n            m_isOpen = true;\n            *this << RowBreak();\n\n\t\t\t\
    Columns headerCols;\n\t\t\tSpacer spacer(2);\n\t\t\tfor (auto const& info : m_columnInfos)\
    \ {\n\t\t\t\theaderCols += Column(info.name).width(static_cast<std::size_t>(info.width\
    \ - 2));\n\t\t\t\theaderCols += spacer;\n\t\t\t}\n\t\t\tm_os << headerCols <<\
    \ '\\n';\n\n            m_os << Catch::getLineOfChars<'-'>() << '\\n';\n     \
    \   }\n    }\n    void close() {\n        if (m_isOpen) {\n            *this <<\
    \ RowBreak();\n            m_os << std::endl;\n            m_isOpen = false;\n\
    \        }\n    }\n\n    template<typename T>\n    friend TablePrinter& operator\
    \ << (TablePrinter& tp, T const& value) {\n        tp.m_oss << value;\n      \
    \  return tp;\n    }\n\n    friend TablePrinter& operator << (TablePrinter& tp,\
    \ ColumnBreak) {\n        auto colStr = tp.m_oss.str();\n        const auto strSize\
    \ = colStr.size();\n        tp.m_oss.str(\"\");\n        tp.open();\n        if\
    \ (tp.m_currentColumn == static_cast<int>(tp.m_columnInfos.size() - 1)) {\n  \
    \          tp.m_currentColumn = -1;\n            tp.m_os << '\\n';\n        }\n\
    \        tp.m_currentColumn++;\n\n        auto colInfo = tp.m_columnInfos[tp.m_currentColumn];\n\
    \        auto padding = (strSize + 1 < static_cast<std::size_t>(colInfo.width))\n\
    \            ? std::string(colInfo.width - (strSize + 1), ' ')\n            :\
    \ std::string();\n        if (colInfo.justification == ColumnInfo::Left)\n   \
    \         tp.m_os << colStr << padding << ' ';\n        else\n            tp.m_os\
    \ << padding << colStr << ' ';\n        return tp;\n    }\n\n    friend TablePrinter&\
    \ operator << (TablePrinter& tp, RowBreak) {\n        if (tp.m_currentColumn >\
    \ 0) {\n            tp.m_os << '\\n';\n            tp.m_currentColumn = -1;\n\
    \        }\n        return tp;\n    }\n};\n\nConsoleReporter::ConsoleReporter(ReporterConfig\
    \ const& config)\n    : StreamingReporterBase(config),\n    m_tablePrinter(new\
    \ TablePrinter(config.stream(),\n        [&config]() -> std::vector<ColumnInfo>\
    \ {\n        if (config.fullConfig()->benchmarkNoAnalysis())\n        {\n    \
    \        return{\n                { \"benchmark name\", CATCH_CONFIG_CONSOLE_WIDTH\
    \ - 43, ColumnInfo::Left },\n                { \"     samples\", 14, ColumnInfo::Right\
    \ },\n                { \"  iterations\", 14, ColumnInfo::Right },\n         \
    \       { \"        mean\", 14, ColumnInfo::Right }\n            };\n        }\n\
    \        else\n        {\n            return{\n                { \"benchmark name\"\
    , CATCH_CONFIG_CONSOLE_WIDTH - 43, ColumnInfo::Left },\n                { \"samples\
    \      mean       std dev\", 14, ColumnInfo::Right },\n                { \"iterations\
    \   low mean   low std dev\", 14, ColumnInfo::Right },\n                { \"estimated\
    \    high mean  high std dev\", 14, ColumnInfo::Right }\n            };\n    \
    \    }\n    }())) {}\nConsoleReporter::~ConsoleReporter() = default;\n\nstd::string\
    \ ConsoleReporter::getDescription() {\n    return \"Reports test results as plain\
    \ lines of text\";\n}\n\nvoid ConsoleReporter::noMatchingTestCases(std::string\
    \ const& spec) {\n    stream << \"No test cases matched '\" << spec << '\\'' <<\
    \ std::endl;\n}\n\nvoid ConsoleReporter::reportInvalidArguments(std::string const&arg){\n\
    \    stream << \"Invalid Filter: \" << arg << std::endl;\n}\n\nvoid ConsoleReporter::assertionStarting(AssertionInfo\
    \ const&) {}\n\nbool ConsoleReporter::assertionEnded(AssertionStats const& _assertionStats)\
    \ {\n    AssertionResult const& result = _assertionStats.assertionResult;\n\n\
    \    bool includeResults = m_config->includeSuccessfulResults() || !result.isOk();\n\
    \n    // Drop out if result was successful but we're not printing them.\n    if\
    \ (!includeResults && result.getResultType() != ResultWas::Warning)\n        return\
    \ false;\n\n    lazyPrint();\n\n    ConsoleAssertionPrinter printer(stream, _assertionStats,\
    \ includeResults);\n    printer.print();\n    stream << std::endl;\n    return\
    \ true;\n}\n\nvoid ConsoleReporter::sectionStarting(SectionInfo const& _sectionInfo)\
    \ {\n    m_tablePrinter->close();\n    m_headerPrinted = false;\n    StreamingReporterBase::sectionStarting(_sectionInfo);\n\
    }\nvoid ConsoleReporter::sectionEnded(SectionStats const& _sectionStats) {\n \
    \   m_tablePrinter->close();\n    if (_sectionStats.missingAssertions) {\n   \
    \     lazyPrint();\n        Colour colour(Colour::ResultError);\n        if (m_sectionStack.size()\
    \ > 1)\n            stream << \"\\nNo assertions in section\";\n        else\n\
    \            stream << \"\\nNo assertions in test case\";\n        stream << \"\
    \ '\" << _sectionStats.sectionInfo.name << \"'\\n\" << std::endl;\n    }\n   \
    \ double dur = _sectionStats.durationInSeconds;\n    if (shouldShowDuration(*m_config,\
    \ dur)) {\n        stream << getFormattedDuration(dur) << \" s: \" << _sectionStats.sectionInfo.name\
    \ << std::endl;\n    }\n    if (m_headerPrinted) {\n        m_headerPrinted =\
    \ false;\n    }\n    StreamingReporterBase::sectionEnded(_sectionStats);\n}\n\n\
    #if defined(CATCH_CONFIG_ENABLE_BENCHMARKING)\nvoid ConsoleReporter::benchmarkPreparing(std::string\
    \ const& name) {\n\tlazyPrintWithoutClosingBenchmarkTable();\n\n\tauto nameCol\
    \ = Column(name).width(static_cast<std::size_t>(m_tablePrinter->columnInfos()[0].width\
    \ - 2));\n\n\tbool firstLine = true;\n\tfor (auto line : nameCol) {\n\t\tif (!firstLine)\n\
    \t\t\t(*m_tablePrinter) << ColumnBreak() << ColumnBreak() << ColumnBreak();\n\t\
    \telse\n\t\t\tfirstLine = false;\n\n\t\t(*m_tablePrinter) << line << ColumnBreak();\n\
    \t}\n}\n\nvoid ConsoleReporter::benchmarkStarting(BenchmarkInfo const& info) {\n\
    \    (*m_tablePrinter) << info.samples << ColumnBreak()\n        << info.iterations\
    \ << ColumnBreak();\n    if (!m_config->benchmarkNoAnalysis())\n        (*m_tablePrinter)\
    \ << Duration(info.estimatedDuration) << ColumnBreak();\n}\nvoid ConsoleReporter::benchmarkEnded(BenchmarkStats<>\
    \ const& stats) {\n    if (m_config->benchmarkNoAnalysis())\n    {\n        (*m_tablePrinter)\
    \ << Duration(stats.mean.point.count()) << ColumnBreak();\n    }\n    else\n \
    \   {\n        (*m_tablePrinter) << ColumnBreak()\n            << Duration(stats.mean.point.count())\
    \ << ColumnBreak()\n            << Duration(stats.mean.lower_bound.count()) <<\
    \ ColumnBreak()\n            << Duration(stats.mean.upper_bound.count()) << ColumnBreak()\
    \ << ColumnBreak()\n            << Duration(stats.standardDeviation.point.count())\
    \ << ColumnBreak()\n            << Duration(stats.standardDeviation.lower_bound.count())\
    \ << ColumnBreak()\n            << Duration(stats.standardDeviation.upper_bound.count())\
    \ << ColumnBreak() << ColumnBreak() << ColumnBreak() << ColumnBreak() << ColumnBreak();\n\
    \    }\n}\n\nvoid ConsoleReporter::benchmarkFailed(std::string const& error) {\n\
    \tColour colour(Colour::Red);\n    (*m_tablePrinter)\n        << \"Benchmark failed\
    \ (\" << error << ')'\n        << ColumnBreak() << RowBreak();\n}\n#endif // CATCH_CONFIG_ENABLE_BENCHMARKING\n\
    \nvoid ConsoleReporter::testCaseEnded(TestCaseStats const& _testCaseStats) {\n\
    \    m_tablePrinter->close();\n    StreamingReporterBase::testCaseEnded(_testCaseStats);\n\
    \    m_headerPrinted = false;\n}\nvoid ConsoleReporter::testGroupEnded(TestGroupStats\
    \ const& _testGroupStats) {\n    if (currentGroupInfo.used) {\n        printSummaryDivider();\n\
    \        stream << \"Summary for group '\" << _testGroupStats.groupInfo.name <<\
    \ \"':\\n\";\n        printTotals(_testGroupStats.totals);\n        stream <<\
    \ '\\n' << std::endl;\n    }\n    StreamingReporterBase::testGroupEnded(_testGroupStats);\n\
    }\nvoid ConsoleReporter::testRunEnded(TestRunStats const& _testRunStats) {\n \
    \   printTotalsDivider(_testRunStats.totals);\n    printTotals(_testRunStats.totals);\n\
    \    stream << std::endl;\n    StreamingReporterBase::testRunEnded(_testRunStats);\n\
    }\nvoid ConsoleReporter::testRunStarting(TestRunInfo const& _testInfo) {\n   \
    \ StreamingReporterBase::testRunStarting(_testInfo);\n    printTestFilters();\n\
    }\n\nvoid ConsoleReporter::lazyPrint() {\n\n    m_tablePrinter->close();\n   \
    \ lazyPrintWithoutClosingBenchmarkTable();\n}\n\nvoid ConsoleReporter::lazyPrintWithoutClosingBenchmarkTable()\
    \ {\n\n    if (!currentTestRunInfo.used)\n        lazyPrintRunInfo();\n    if\
    \ (!currentGroupInfo.used)\n        lazyPrintGroupInfo();\n\n    if (!m_headerPrinted)\
    \ {\n        printTestCaseAndSectionHeader();\n        m_headerPrinted = true;\n\
    \    }\n}\nvoid ConsoleReporter::lazyPrintRunInfo() {\n    stream << '\\n' <<\
    \ getLineOfChars<'~'>() << '\\n';\n    Colour colour(Colour::SecondaryText);\n\
    \    stream << currentTestRunInfo->name\n        << \" is a Catch v\" << libraryVersion()\
    \ << \" host application.\\n\"\n        << \"Run with -? for options\\n\\n\";\n\
    \n    if (m_config->rngSeed() != 0)\n        stream << \"Randomness seeded to:\
    \ \" << m_config->rngSeed() << \"\\n\\n\";\n\n    currentTestRunInfo.used = true;\n\
    }\nvoid ConsoleReporter::lazyPrintGroupInfo() {\n    if (!currentGroupInfo->name.empty()\
    \ && currentGroupInfo->groupsCounts > 1) {\n        printClosedHeader(\"Group:\
    \ \" + currentGroupInfo->name);\n        currentGroupInfo.used = true;\n    }\n\
    }\nvoid ConsoleReporter::printTestCaseAndSectionHeader() {\n    assert(!m_sectionStack.empty());\n\
    \    printOpenHeader(currentTestCaseInfo->name);\n\n    if (m_sectionStack.size()\
    \ > 1) {\n        Colour colourGuard(Colour::Headers);\n\n        auto\n     \
    \       it = m_sectionStack.begin() + 1, // Skip first section (test case)\n \
    \           itEnd = m_sectionStack.end();\n        for (; it != itEnd; ++it)\n\
    \            printHeaderString(it->name, 2);\n    }\n\n    SourceLineInfo lineInfo\
    \ = m_sectionStack.back().lineInfo;\n\n    stream << getLineOfChars<'-'>() <<\
    \ '\\n';\n    Colour colourGuard(Colour::FileName);\n    stream << lineInfo <<\
    \ '\\n';\n    stream << getLineOfChars<'.'>() << '\\n' << std::endl;\n}\n\nvoid\
    \ ConsoleReporter::printClosedHeader(std::string const& _name) {\n    printOpenHeader(_name);\n\
    \    stream << getLineOfChars<'.'>() << '\\n';\n}\nvoid ConsoleReporter::printOpenHeader(std::string\
    \ const& _name) {\n    stream << getLineOfChars<'-'>() << '\\n';\n    {\n    \
    \    Colour colourGuard(Colour::Headers);\n        printHeaderString(_name);\n\
    \    }\n}\n\n// if string has a : in first line will set indent to follow it on\n\
    // subsequent lines\nvoid ConsoleReporter::printHeaderString(std::string const&\
    \ _string, std::size_t indent) {\n    std::size_t i = _string.find(\": \");\n\
    \    if (i != std::string::npos)\n        i += 2;\n    else\n        i = 0;\n\
    \    stream << Column(_string).indent(indent + i).initialIndent(indent) << '\\\
    n';\n}\n\nstruct SummaryColumn {\n\n    SummaryColumn( std::string _label, Colour::Code\
    \ _colour )\n    :   label( std::move( _label ) ),\n        colour( _colour )\
    \ {}\n    SummaryColumn addRow( std::size_t count ) {\n        ReusableStringStream\
    \ rss;\n        rss << count;\n        std::string row = rss.str();\n        for\
    \ (auto& oldRow : rows) {\n            while (oldRow.size() < row.size())\n  \
    \              oldRow = ' ' + oldRow;\n            while (oldRow.size() > row.size())\n\
    \                row = ' ' + row;\n        }\n        rows.push_back(row);\n \
    \       return *this;\n    }\n\n    std::string label;\n    Colour::Code colour;\n\
    \    std::vector<std::string> rows;\n\n};\n\nvoid ConsoleReporter::printTotals(\
    \ Totals const& totals ) {\n    if (totals.testCases.total() == 0) {\n       \
    \ stream << Colour(Colour::Warning) << \"No tests ran\\n\";\n    } else if (totals.assertions.total()\
    \ > 0 && totals.testCases.allPassed()) {\n        stream << Colour(Colour::ResultSuccess)\
    \ << \"All tests passed\";\n        stream << \" (\"\n            << pluralise(totals.assertions.passed,\
    \ \"assertion\") << \" in \"\n            << pluralise(totals.testCases.passed,\
    \ \"test case\") << ')'\n            << '\\n';\n    } else {\n\n        std::vector<SummaryColumn>\
    \ columns;\n        columns.push_back(SummaryColumn(\"\", Colour::None)\n    \
    \                      .addRow(totals.testCases.total())\n                   \
    \       .addRow(totals.assertions.total()));\n        columns.push_back(SummaryColumn(\"\
    passed\", Colour::Success)\n                          .addRow(totals.testCases.passed)\n\
    \                          .addRow(totals.assertions.passed));\n        columns.push_back(SummaryColumn(\"\
    failed\", Colour::ResultError)\n                          .addRow(totals.testCases.failed)\n\
    \                          .addRow(totals.assertions.failed));\n        columns.push_back(SummaryColumn(\"\
    failed as expected\", Colour::ResultExpectedFailure)\n                       \
    \   .addRow(totals.testCases.failedButOk)\n                          .addRow(totals.assertions.failedButOk));\n\
    \n        printSummaryRow(\"test cases\", columns, 0);\n        printSummaryRow(\"\
    assertions\", columns, 1);\n    }\n}\nvoid ConsoleReporter::printSummaryRow(std::string\
    \ const& label, std::vector<SummaryColumn> const& cols, std::size_t row) {\n \
    \   for (auto col : cols) {\n        std::string value = col.rows[row];\n    \
    \    if (col.label.empty()) {\n            stream << label << \": \";\n      \
    \      if (value != \"0\")\n                stream << value;\n            else\n\
    \                stream << Colour(Colour::Warning) << \"- none -\";\n        }\
    \ else if (value != \"0\") {\n            stream << Colour(Colour::LightGrey)\
    \ << \" | \";\n            stream << Colour(col.colour)\n                << value\
    \ << ' ' << col.label;\n        }\n    }\n    stream << '\\n';\n}\n\nvoid ConsoleReporter::printTotalsDivider(Totals\
    \ const& totals) {\n    if (totals.testCases.total() > 0) {\n        std::size_t\
    \ failedRatio = makeRatio(totals.testCases.failed, totals.testCases.total());\n\
    \        std::size_t failedButOkRatio = makeRatio(totals.testCases.failedButOk,\
    \ totals.testCases.total());\n        std::size_t passedRatio = makeRatio(totals.testCases.passed,\
    \ totals.testCases.total());\n        while (failedRatio + failedButOkRatio +\
    \ passedRatio < CATCH_CONFIG_CONSOLE_WIDTH - 1)\n            findMax(failedRatio,\
    \ failedButOkRatio, passedRatio)++;\n        while (failedRatio + failedButOkRatio\
    \ + passedRatio > CATCH_CONFIG_CONSOLE_WIDTH - 1)\n            findMax(failedRatio,\
    \ failedButOkRatio, passedRatio)--;\n\n        stream << Colour(Colour::Error)\
    \ << std::string(failedRatio, '=');\n        stream << Colour(Colour::ResultExpectedFailure)\
    \ << std::string(failedButOkRatio, '=');\n        if (totals.testCases.allPassed())\n\
    \            stream << Colour(Colour::ResultSuccess) << std::string(passedRatio,\
    \ '=');\n        else\n            stream << Colour(Colour::Success) << std::string(passedRatio,\
    \ '=');\n    } else {\n        stream << Colour(Colour::Warning) << std::string(CATCH_CONFIG_CONSOLE_WIDTH\
    \ - 1, '=');\n    }\n    stream << '\\n';\n}\nvoid ConsoleReporter::printSummaryDivider()\
    \ {\n    stream << getLineOfChars<'-'>() << '\\n';\n}\n\nvoid ConsoleReporter::printTestFilters()\
    \ {\n    if (m_config->testSpec().hasFilters()) {\n        Colour guard(Colour::BrightYellow);\n\
    \        stream << \"Filters: \" << serializeFilters(m_config->getTestsOrTags())\
    \ << '\\n';\n    }\n}\n\nCATCH_REGISTER_REPORTER(\"console\", ConsoleReporter)\n\
    \n} // end namespace Catch\n\n#if defined(_MSC_VER)\n#pragma warning(pop)\n#endif\n\
    \n#if defined(__clang__)\n#  pragma clang diagnostic pop\n#endif\n// end catch_reporter_console.cpp\n\
    // start catch_reporter_junit.cpp\n\n#include <cassert>\n#include <sstream>\n\
    #include <ctime>\n#include <algorithm>\n\nnamespace Catch {\n\n    namespace {\n\
    \        std::string getCurrentTimestamp() {\n            // Beware, this is not\
    \ reentrant because of backward compatibility issues\n            // Also, UTC\
    \ only, again because of backward compatibility (%z is C++11)\n            time_t\
    \ rawtime;\n            std::time(&rawtime);\n            auto const timeStampSize\
    \ = sizeof(\"2017-01-16T17:06:45Z\");\n\n#ifdef _MSC_VER\n            std::tm\
    \ timeInfo = {};\n            gmtime_s(&timeInfo, &rawtime);\n#else\n        \
    \    std::tm* timeInfo;\n            timeInfo = std::gmtime(&rawtime);\n#endif\n\
    \n            char timeStamp[timeStampSize];\n            const char * const fmt\
    \ = \"%Y-%m-%dT%H:%M:%SZ\";\n\n#ifdef _MSC_VER\n            std::strftime(timeStamp,\
    \ timeStampSize, fmt, &timeInfo);\n#else\n            std::strftime(timeStamp,\
    \ timeStampSize, fmt, timeInfo);\n#endif\n            return std::string(timeStamp);\n\
    \        }\n\n        std::string fileNameTag(const std::vector<std::string> &tags)\
    \ {\n            auto it = std::find_if(begin(tags),\n                       \
    \            end(tags),\n                                   [] (std::string const&\
    \ tag) {return tag.front() == '#'; });\n            if (it != tags.end())\n  \
    \              return it->substr(1);\n            return std::string();\n    \
    \    }\n    } // anonymous namespace\n\n    JunitReporter::JunitReporter( ReporterConfig\
    \ const& _config )\n        :   CumulativeReporterBase( _config ),\n         \
    \   xml( _config.stream() )\n        {\n            m_reporterPrefs.shouldRedirectStdOut\
    \ = true;\n            m_reporterPrefs.shouldReportAllAssertions = true;\n   \
    \     }\n\n    JunitReporter::~JunitReporter() {}\n\n    std::string JunitReporter::getDescription()\
    \ {\n        return \"Reports test results in an XML format that looks like Ant's\
    \ junitreport target\";\n    }\n\n    void JunitReporter::noMatchingTestCases(\
    \ std::string const& /*spec*/ ) {}\n\n    void JunitReporter::testRunStarting(\
    \ TestRunInfo const& runInfo )  {\n        CumulativeReporterBase::testRunStarting(\
    \ runInfo );\n        xml.startElement( \"testsuites\" );\n    }\n\n    void JunitReporter::testGroupStarting(\
    \ GroupInfo const& groupInfo ) {\n        suiteTimer.start();\n        stdOutForSuite.clear();\n\
    \        stdErrForSuite.clear();\n        unexpectedExceptions = 0;\n        CumulativeReporterBase::testGroupStarting(\
    \ groupInfo );\n    }\n\n    void JunitReporter::testCaseStarting( TestCaseInfo\
    \ const& testCaseInfo ) {\n        m_okToFail = testCaseInfo.okToFail();\n   \
    \ }\n\n    bool JunitReporter::assertionEnded( AssertionStats const& assertionStats\
    \ ) {\n        if( assertionStats.assertionResult.getResultType() == ResultWas::ThrewException\
    \ && !m_okToFail )\n            unexpectedExceptions++;\n        return CumulativeReporterBase::assertionEnded(\
    \ assertionStats );\n    }\n\n    void JunitReporter::testCaseEnded( TestCaseStats\
    \ const& testCaseStats ) {\n        stdOutForSuite += testCaseStats.stdOut;\n\
    \        stdErrForSuite += testCaseStats.stdErr;\n        CumulativeReporterBase::testCaseEnded(\
    \ testCaseStats );\n    }\n\n    void JunitReporter::testGroupEnded( TestGroupStats\
    \ const& testGroupStats ) {\n        double suiteTime = suiteTimer.getElapsedSeconds();\n\
    \        CumulativeReporterBase::testGroupEnded( testGroupStats );\n        writeGroup(\
    \ *m_testGroups.back(), suiteTime );\n    }\n\n    void JunitReporter::testRunEndedCumulative()\
    \ {\n        xml.endElement();\n    }\n\n    void JunitReporter::writeGroup( TestGroupNode\
    \ const& groupNode, double suiteTime ) {\n        XmlWriter::ScopedElement e =\
    \ xml.scopedElement( \"testsuite\" );\n\n        TestGroupStats const& stats =\
    \ groupNode.value;\n        xml.writeAttribute( \"name\", stats.groupInfo.name\
    \ );\n        xml.writeAttribute( \"errors\", unexpectedExceptions );\n      \
    \  xml.writeAttribute( \"failures\", stats.totals.assertions.failed-unexpectedExceptions\
    \ );\n        xml.writeAttribute( \"tests\", stats.totals.assertions.total() );\n\
    \        xml.writeAttribute( \"hostname\", \"tbd\" ); // !TBD\n        if( m_config->showDurations()\
    \ == ShowDurations::Never )\n            xml.writeAttribute( \"time\", \"\" );\n\
    \        else\n            xml.writeAttribute( \"time\", suiteTime );\n      \
    \  xml.writeAttribute( \"timestamp\", getCurrentTimestamp() );\n\n        // Write\
    \ properties if there are any\n        if (m_config->hasTestFilters() || m_config->rngSeed()\
    \ != 0) {\n            auto properties = xml.scopedElement(\"properties\");\n\
    \            if (m_config->hasTestFilters()) {\n                xml.scopedElement(\"\
    property\")\n                    .writeAttribute(\"name\", \"filters\")\n    \
    \                .writeAttribute(\"value\", serializeFilters(m_config->getTestsOrTags()));\n\
    \            }\n            if (m_config->rngSeed() != 0) {\n                xml.scopedElement(\"\
    property\")\n                    .writeAttribute(\"name\", \"random-seed\")\n\
    \                    .writeAttribute(\"value\", m_config->rngSeed());\n      \
    \      }\n        }\n\n        // Write test cases\n        for( auto const& child\
    \ : groupNode.children )\n            writeTestCase( *child );\n\n        xml.scopedElement(\
    \ \"system-out\" ).writeText( trim( stdOutForSuite ), XmlFormatting::Newline );\n\
    \        xml.scopedElement( \"system-err\" ).writeText( trim( stdErrForSuite ),\
    \ XmlFormatting::Newline );\n    }\n\n    void JunitReporter::writeTestCase( TestCaseNode\
    \ const& testCaseNode ) {\n        TestCaseStats const& stats = testCaseNode.value;\n\
    \n        // All test cases have exactly one section - which represents the\n\
    \        // test case itself. That section may have 0-n nested sections\n    \
    \    assert( testCaseNode.children.size() == 1 );\n        SectionNode const&\
    \ rootSection = *testCaseNode.children.front();\n\n        std::string className\
    \ = stats.testInfo.className;\n\n        if( className.empty() ) {\n         \
    \   className = fileNameTag(stats.testInfo.tags);\n            if ( className.empty()\
    \ )\n                className = \"global\";\n        }\n\n        if ( !m_config->name().empty()\
    \ )\n            className = m_config->name() + \".\" + className;\n\n       \
    \ writeSection( className, \"\", rootSection );\n    }\n\n    void JunitReporter::writeSection(\
    \  std::string const& className,\n                        std::string const& rootName,\n\
    \                        SectionNode const& sectionNode ) {\n        std::string\
    \ name = trim( sectionNode.stats.sectionInfo.name );\n        if( !rootName.empty()\
    \ )\n            name = rootName + '/' + name;\n\n        if( !sectionNode.assertions.empty()\
    \ ||\n            !sectionNode.stdOut.empty() ||\n            !sectionNode.stdErr.empty()\
    \ ) {\n            XmlWriter::ScopedElement e = xml.scopedElement( \"testcase\"\
    \ );\n            if( className.empty() ) {\n                xml.writeAttribute(\
    \ \"classname\", name );\n                xml.writeAttribute( \"name\", \"root\"\
    \ );\n            }\n            else {\n                xml.writeAttribute( \"\
    classname\", className );\n                xml.writeAttribute( \"name\", name\
    \ );\n            }\n            xml.writeAttribute( \"time\", ::Catch::Detail::stringify(\
    \ sectionNode.stats.durationInSeconds ) );\n            // This is not ideal,\
    \ but it should be enough to mimic gtest's\n            // junit output.\n   \
    \         // Ideally the JUnit reporter would also handle `skipTest`\n       \
    \     // events and write those out appropriately.\n            xml.writeAttribute(\
    \ \"status\", \"run\" );\n\n            writeAssertions( sectionNode );\n\n  \
    \          if( !sectionNode.stdOut.empty() )\n                xml.scopedElement(\
    \ \"system-out\" ).writeText( trim( sectionNode.stdOut ), XmlFormatting::Newline\
    \ );\n            if( !sectionNode.stdErr.empty() )\n                xml.scopedElement(\
    \ \"system-err\" ).writeText( trim( sectionNode.stdErr ), XmlFormatting::Newline\
    \ );\n        }\n        for( auto const& childNode : sectionNode.childSections\
    \ )\n            if( className.empty() )\n                writeSection( name,\
    \ \"\", *childNode );\n            else\n                writeSection( className,\
    \ name, *childNode );\n    }\n\n    void JunitReporter::writeAssertions( SectionNode\
    \ const& sectionNode ) {\n        for( auto const& assertion : sectionNode.assertions\
    \ )\n            writeAssertion( assertion );\n    }\n\n    void JunitReporter::writeAssertion(\
    \ AssertionStats const& stats ) {\n        AssertionResult const& result = stats.assertionResult;\n\
    \        if( !result.isOk() ) {\n            std::string elementName;\n      \
    \      switch( result.getResultType() ) {\n                case ResultWas::ThrewException:\n\
    \                case ResultWas::FatalErrorCondition:\n                    elementName\
    \ = \"error\";\n                    break;\n                case ResultWas::ExplicitFailure:\n\
    \                case ResultWas::ExpressionFailed:\n                case ResultWas::DidntThrowException:\n\
    \                    elementName = \"failure\";\n                    break;\n\n\
    \                // We should never see these here:\n                case ResultWas::Info:\n\
    \                case ResultWas::Warning:\n                case ResultWas::Ok:\n\
    \                case ResultWas::Unknown:\n                case ResultWas::FailureBit:\n\
    \                case ResultWas::Exception:\n                    elementName =\
    \ \"internalError\";\n                    break;\n            }\n\n          \
    \  XmlWriter::ScopedElement e = xml.scopedElement( elementName );\n\n        \
    \    xml.writeAttribute( \"message\", result.getExpression() );\n            xml.writeAttribute(\
    \ \"type\", result.getTestMacroName() );\n\n            ReusableStringStream rss;\n\
    \            if (stats.totals.assertions.total() > 0) {\n                rss <<\
    \ \"FAILED\" << \":\\n\";\n                if (result.hasExpression()) {\n   \
    \                 rss << \"  \";\n                    rss << result.getExpressionInMacro();\n\
    \                    rss << '\\n';\n                }\n                if (result.hasExpandedExpression())\
    \ {\n                    rss << \"with expansion:\\n\";\n                    rss\
    \ << Column(result.getExpandedExpression()).indent(2) << '\\n';\n            \
    \    }\n            } else {\n                rss << '\\n';\n            }\n\n\
    \            if( !result.getMessage().empty() )\n                rss << result.getMessage()\
    \ << '\\n';\n            for( auto const& msg : stats.infoMessages )\n       \
    \         if( msg.type == ResultWas::Info )\n                    rss << msg.message\
    \ << '\\n';\n\n            rss << \"at \" << result.getSourceInfo();\n       \
    \     xml.writeText( rss.str(), XmlFormatting::Newline );\n        }\n    }\n\n\
    \    CATCH_REGISTER_REPORTER( \"junit\", JunitReporter )\n\n} // end namespace\
    \ Catch\n// end catch_reporter_junit.cpp\n// start catch_reporter_listening.cpp\n\
    \n#include <cassert>\n\nnamespace Catch {\n\n    ListeningReporter::ListeningReporter()\
    \ {\n        // We will assume that listeners will always want all assertions\n\
    \        m_preferences.shouldReportAllAssertions = true;\n    }\n\n    void ListeningReporter::addListener(\
    \ IStreamingReporterPtr&& listener ) {\n        m_listeners.push_back( std::move(\
    \ listener ) );\n    }\n\n    void ListeningReporter::addReporter(IStreamingReporterPtr&&\
    \ reporter) {\n        assert(!m_reporter && \"Listening reporter can wrap only\
    \ 1 real reporter\");\n        m_reporter = std::move( reporter );\n        m_preferences.shouldRedirectStdOut\
    \ = m_reporter->getPreferences().shouldRedirectStdOut;\n    }\n\n    ReporterPreferences\
    \ ListeningReporter::getPreferences() const {\n        return m_preferences;\n\
    \    }\n\n    std::set<Verbosity> ListeningReporter::getSupportedVerbosities()\
    \ {\n        return std::set<Verbosity>{ };\n    }\n\n    void ListeningReporter::noMatchingTestCases(\
    \ std::string const& spec ) {\n        for ( auto const& listener : m_listeners\
    \ ) {\n            listener->noMatchingTestCases( spec );\n        }\n       \
    \ m_reporter->noMatchingTestCases( spec );\n    }\n\n    void ListeningReporter::reportInvalidArguments(std::string\
    \ const&arg){\n        for ( auto const& listener : m_listeners ) {\n        \
    \    listener->reportInvalidArguments( arg );\n        }\n        m_reporter->reportInvalidArguments(\
    \ arg );\n    }\n\n#if defined(CATCH_CONFIG_ENABLE_BENCHMARKING)\n    void ListeningReporter::benchmarkPreparing(\
    \ std::string const& name ) {\n\t\tfor (auto const& listener : m_listeners) {\n\
    \t\t\tlistener->benchmarkPreparing(name);\n\t\t}\n\t\tm_reporter->benchmarkPreparing(name);\n\
    \t}\n    void ListeningReporter::benchmarkStarting( BenchmarkInfo const& benchmarkInfo\
    \ ) {\n        for ( auto const& listener : m_listeners ) {\n            listener->benchmarkStarting(\
    \ benchmarkInfo );\n        }\n        m_reporter->benchmarkStarting( benchmarkInfo\
    \ );\n    }\n    void ListeningReporter::benchmarkEnded( BenchmarkStats<> const&\
    \ benchmarkStats ) {\n        for ( auto const& listener : m_listeners ) {\n \
    \           listener->benchmarkEnded( benchmarkStats );\n        }\n        m_reporter->benchmarkEnded(\
    \ benchmarkStats );\n    }\n\n\tvoid ListeningReporter::benchmarkFailed( std::string\
    \ const& error ) {\n\t\tfor (auto const& listener : m_listeners) {\n\t\t\tlistener->benchmarkFailed(error);\n\
    \t\t}\n\t\tm_reporter->benchmarkFailed(error);\n\t}\n#endif // CATCH_CONFIG_ENABLE_BENCHMARKING\n\
    \n    void ListeningReporter::testRunStarting( TestRunInfo const& testRunInfo\
    \ ) {\n        for ( auto const& listener : m_listeners ) {\n            listener->testRunStarting(\
    \ testRunInfo );\n        }\n        m_reporter->testRunStarting( testRunInfo\
    \ );\n    }\n\n    void ListeningReporter::testGroupStarting( GroupInfo const&\
    \ groupInfo ) {\n        for ( auto const& listener : m_listeners ) {\n      \
    \      listener->testGroupStarting( groupInfo );\n        }\n        m_reporter->testGroupStarting(\
    \ groupInfo );\n    }\n\n    void ListeningReporter::testCaseStarting( TestCaseInfo\
    \ const& testInfo ) {\n        for ( auto const& listener : m_listeners ) {\n\
    \            listener->testCaseStarting( testInfo );\n        }\n        m_reporter->testCaseStarting(\
    \ testInfo );\n    }\n\n    void ListeningReporter::sectionStarting( SectionInfo\
    \ const& sectionInfo ) {\n        for ( auto const& listener : m_listeners ) {\n\
    \            listener->sectionStarting( sectionInfo );\n        }\n        m_reporter->sectionStarting(\
    \ sectionInfo );\n    }\n\n    void ListeningReporter::assertionStarting( AssertionInfo\
    \ const& assertionInfo ) {\n        for ( auto const& listener : m_listeners )\
    \ {\n            listener->assertionStarting( assertionInfo );\n        }\n  \
    \      m_reporter->assertionStarting( assertionInfo );\n    }\n\n    // The return\
    \ value indicates if the messages buffer should be cleared:\n    bool ListeningReporter::assertionEnded(\
    \ AssertionStats const& assertionStats ) {\n        for( auto const& listener\
    \ : m_listeners ) {\n            static_cast<void>( listener->assertionEnded(\
    \ assertionStats ) );\n        }\n        return m_reporter->assertionEnded( assertionStats\
    \ );\n    }\n\n    void ListeningReporter::sectionEnded( SectionStats const& sectionStats\
    \ ) {\n        for ( auto const& listener : m_listeners ) {\n            listener->sectionEnded(\
    \ sectionStats );\n        }\n        m_reporter->sectionEnded( sectionStats );\n\
    \    }\n\n    void ListeningReporter::testCaseEnded( TestCaseStats const& testCaseStats\
    \ ) {\n        for ( auto const& listener : m_listeners ) {\n            listener->testCaseEnded(\
    \ testCaseStats );\n        }\n        m_reporter->testCaseEnded( testCaseStats\
    \ );\n    }\n\n    void ListeningReporter::testGroupEnded( TestGroupStats const&\
    \ testGroupStats ) {\n        for ( auto const& listener : m_listeners ) {\n \
    \           listener->testGroupEnded( testGroupStats );\n        }\n        m_reporter->testGroupEnded(\
    \ testGroupStats );\n    }\n\n    void ListeningReporter::testRunEnded( TestRunStats\
    \ const& testRunStats ) {\n        for ( auto const& listener : m_listeners )\
    \ {\n            listener->testRunEnded( testRunStats );\n        }\n        m_reporter->testRunEnded(\
    \ testRunStats );\n    }\n\n    void ListeningReporter::skipTest( TestCaseInfo\
    \ const& testInfo ) {\n        for ( auto const& listener : m_listeners ) {\n\
    \            listener->skipTest( testInfo );\n        }\n        m_reporter->skipTest(\
    \ testInfo );\n    }\n\n    bool ListeningReporter::isMulti() const {\n      \
    \  return true;\n    }\n\n} // end namespace Catch\n// end catch_reporter_listening.cpp\n\
    // start catch_reporter_xml.cpp\n\n#if defined(_MSC_VER)\n#pragma warning(push)\n\
    #pragma warning(disable:4061) // Not all labels are EXPLICITLY handled in switch\n\
    \                              // Note that 4062 (not all labels are handled\n\
    \                              // and default is missing) is enabled\n#endif\n\
    \nnamespace Catch {\n    XmlReporter::XmlReporter( ReporterConfig const& _config\
    \ )\n    :   StreamingReporterBase( _config ),\n        m_xml(_config.stream())\n\
    \    {\n        m_reporterPrefs.shouldRedirectStdOut = true;\n        m_reporterPrefs.shouldReportAllAssertions\
    \ = true;\n    }\n\n    XmlReporter::~XmlReporter() = default;\n\n    std::string\
    \ XmlReporter::getDescription() {\n        return \"Reports test results as an\
    \ XML document\";\n    }\n\n    std::string XmlReporter::getStylesheetRef() const\
    \ {\n        return std::string();\n    }\n\n    void XmlReporter::writeSourceInfo(\
    \ SourceLineInfo const& sourceInfo ) {\n        m_xml\n            .writeAttribute(\
    \ \"filename\", sourceInfo.file )\n            .writeAttribute( \"line\", sourceInfo.line\
    \ );\n    }\n\n    void XmlReporter::noMatchingTestCases( std::string const& s\
    \ ) {\n        StreamingReporterBase::noMatchingTestCases( s );\n    }\n\n   \
    \ void XmlReporter::testRunStarting( TestRunInfo const& testInfo ) {\n       \
    \ StreamingReporterBase::testRunStarting( testInfo );\n        std::string stylesheetRef\
    \ = getStylesheetRef();\n        if( !stylesheetRef.empty() )\n            m_xml.writeStylesheetRef(\
    \ stylesheetRef );\n        m_xml.startElement( \"Catch\" );\n        if( !m_config->name().empty()\
    \ )\n            m_xml.writeAttribute( \"name\", m_config->name() );\n       \
    \ if (m_config->testSpec().hasFilters())\n            m_xml.writeAttribute( \"\
    filters\", serializeFilters( m_config->getTestsOrTags() ) );\n        if( m_config->rngSeed()\
    \ != 0 )\n            m_xml.scopedElement( \"Randomness\" )\n                .writeAttribute(\
    \ \"seed\", m_config->rngSeed() );\n    }\n\n    void XmlReporter::testGroupStarting(\
    \ GroupInfo const& groupInfo ) {\n        StreamingReporterBase::testGroupStarting(\
    \ groupInfo );\n        m_xml.startElement( \"Group\" )\n            .writeAttribute(\
    \ \"name\", groupInfo.name );\n    }\n\n    void XmlReporter::testCaseStarting(\
    \ TestCaseInfo const& testInfo ) {\n        StreamingReporterBase::testCaseStarting(testInfo);\n\
    \        m_xml.startElement( \"TestCase\" )\n            .writeAttribute( \"name\"\
    , trim( testInfo.name ) )\n            .writeAttribute( \"description\", testInfo.description\
    \ )\n            .writeAttribute( \"tags\", testInfo.tagsAsString() );\n\n   \
    \     writeSourceInfo( testInfo.lineInfo );\n\n        if ( m_config->showDurations()\
    \ == ShowDurations::Always )\n            m_testCaseTimer.start();\n        m_xml.ensureTagClosed();\n\
    \    }\n\n    void XmlReporter::sectionStarting( SectionInfo const& sectionInfo\
    \ ) {\n        StreamingReporterBase::sectionStarting( sectionInfo );\n      \
    \  if( m_sectionDepth++ > 0 ) {\n            m_xml.startElement( \"Section\" )\n\
    \                .writeAttribute( \"name\", trim( sectionInfo.name ) );\n    \
    \        writeSourceInfo( sectionInfo.lineInfo );\n            m_xml.ensureTagClosed();\n\
    \        }\n    }\n\n    void XmlReporter::assertionStarting( AssertionInfo const&\
    \ ) { }\n\n    bool XmlReporter::assertionEnded( AssertionStats const& assertionStats\
    \ ) {\n\n        AssertionResult const& result = assertionStats.assertionResult;\n\
    \n        bool includeResults = m_config->includeSuccessfulResults() || !result.isOk();\n\
    \n        if( includeResults || result.getResultType() == ResultWas::Warning )\
    \ {\n            // Print any info messages in <Info> tags.\n            for(\
    \ auto const& msg : assertionStats.infoMessages ) {\n                if( msg.type\
    \ == ResultWas::Info && includeResults ) {\n                    m_xml.scopedElement(\
    \ \"Info\" )\n                            .writeText( msg.message );\n       \
    \         } else if ( msg.type == ResultWas::Warning ) {\n                   \
    \ m_xml.scopedElement( \"Warning\" )\n                            .writeText(\
    \ msg.message );\n                }\n            }\n        }\n\n        // Drop\
    \ out if result was successful but we're not printing them.\n        if( !includeResults\
    \ && result.getResultType() != ResultWas::Warning )\n            return true;\n\
    \n        // Print the expression if there is one.\n        if( result.hasExpression()\
    \ ) {\n            m_xml.startElement( \"Expression\" )\n                .writeAttribute(\
    \ \"success\", result.succeeded() )\n                .writeAttribute( \"type\"\
    , result.getTestMacroName() );\n\n            writeSourceInfo( result.getSourceInfo()\
    \ );\n\n            m_xml.scopedElement( \"Original\" )\n                .writeText(\
    \ result.getExpression() );\n            m_xml.scopedElement( \"Expanded\" )\n\
    \                .writeText( result.getExpandedExpression() );\n        }\n\n\
    \        // And... Print a result applicable to each result type.\n        switch(\
    \ result.getResultType() ) {\n            case ResultWas::ThrewException:\n  \
    \              m_xml.startElement( \"Exception\" );\n                writeSourceInfo(\
    \ result.getSourceInfo() );\n                m_xml.writeText( result.getMessage()\
    \ );\n                m_xml.endElement();\n                break;\n          \
    \  case ResultWas::FatalErrorCondition:\n                m_xml.startElement( \"\
    FatalErrorCondition\" );\n                writeSourceInfo( result.getSourceInfo()\
    \ );\n                m_xml.writeText( result.getMessage() );\n              \
    \  m_xml.endElement();\n                break;\n            case ResultWas::Info:\n\
    \                m_xml.scopedElement( \"Info\" )\n                    .writeText(\
    \ result.getMessage() );\n                break;\n            case ResultWas::Warning:\n\
    \                // Warning will already have been written\n                break;\n\
    \            case ResultWas::ExplicitFailure:\n                m_xml.startElement(\
    \ \"Failure\" );\n                writeSourceInfo( result.getSourceInfo() );\n\
    \                m_xml.writeText( result.getMessage() );\n                m_xml.endElement();\n\
    \                break;\n            default:\n                break;\n      \
    \  }\n\n        if( result.hasExpression() )\n            m_xml.endElement();\n\
    \n        return true;\n    }\n\n    void XmlReporter::sectionEnded( SectionStats\
    \ const& sectionStats ) {\n        StreamingReporterBase::sectionEnded( sectionStats\
    \ );\n        if( --m_sectionDepth > 0 ) {\n            XmlWriter::ScopedElement\
    \ e = m_xml.scopedElement( \"OverallResults\" );\n            e.writeAttribute(\
    \ \"successes\", sectionStats.assertions.passed );\n            e.writeAttribute(\
    \ \"failures\", sectionStats.assertions.failed );\n            e.writeAttribute(\
    \ \"expectedFailures\", sectionStats.assertions.failedButOk );\n\n           \
    \ if ( m_config->showDurations() == ShowDurations::Always )\n                e.writeAttribute(\
    \ \"durationInSeconds\", sectionStats.durationInSeconds );\n\n            m_xml.endElement();\n\
    \        }\n    }\n\n    void XmlReporter::testCaseEnded( TestCaseStats const&\
    \ testCaseStats ) {\n        StreamingReporterBase::testCaseEnded( testCaseStats\
    \ );\n        XmlWriter::ScopedElement e = m_xml.scopedElement( \"OverallResult\"\
    \ );\n        e.writeAttribute( \"success\", testCaseStats.totals.assertions.allOk()\
    \ );\n\n        if ( m_config->showDurations() == ShowDurations::Always )\n  \
    \          e.writeAttribute( \"durationInSeconds\", m_testCaseTimer.getElapsedSeconds()\
    \ );\n\n        if( !testCaseStats.stdOut.empty() )\n            m_xml.scopedElement(\
    \ \"StdOut\" ).writeText( trim( testCaseStats.stdOut ), XmlFormatting::Newline\
    \ );\n        if( !testCaseStats.stdErr.empty() )\n            m_xml.scopedElement(\
    \ \"StdErr\" ).writeText( trim( testCaseStats.stdErr ), XmlFormatting::Newline\
    \ );\n\n        m_xml.endElement();\n    }\n\n    void XmlReporter::testGroupEnded(\
    \ TestGroupStats const& testGroupStats ) {\n        StreamingReporterBase::testGroupEnded(\
    \ testGroupStats );\n        // TODO: Check testGroupStats.aborting and act accordingly.\n\
    \        m_xml.scopedElement( \"OverallResults\" )\n            .writeAttribute(\
    \ \"successes\", testGroupStats.totals.assertions.passed )\n            .writeAttribute(\
    \ \"failures\", testGroupStats.totals.assertions.failed )\n            .writeAttribute(\
    \ \"expectedFailures\", testGroupStats.totals.assertions.failedButOk );\n    \
    \    m_xml.scopedElement( \"OverallResultsCases\")\n            .writeAttribute(\
    \ \"successes\", testGroupStats.totals.testCases.passed )\n            .writeAttribute(\
    \ \"failures\", testGroupStats.totals.testCases.failed )\n            .writeAttribute(\
    \ \"expectedFailures\", testGroupStats.totals.testCases.failedButOk );\n     \
    \   m_xml.endElement();\n    }\n\n    void XmlReporter::testRunEnded( TestRunStats\
    \ const& testRunStats ) {\n        StreamingReporterBase::testRunEnded( testRunStats\
    \ );\n        m_xml.scopedElement( \"OverallResults\" )\n            .writeAttribute(\
    \ \"successes\", testRunStats.totals.assertions.passed )\n            .writeAttribute(\
    \ \"failures\", testRunStats.totals.assertions.failed )\n            .writeAttribute(\
    \ \"expectedFailures\", testRunStats.totals.assertions.failedButOk );\n      \
    \  m_xml.scopedElement( \"OverallResultsCases\")\n            .writeAttribute(\
    \ \"successes\", testRunStats.totals.testCases.passed )\n            .writeAttribute(\
    \ \"failures\", testRunStats.totals.testCases.failed )\n            .writeAttribute(\
    \ \"expectedFailures\", testRunStats.totals.testCases.failedButOk );\n       \
    \ m_xml.endElement();\n    }\n\n#if defined(CATCH_CONFIG_ENABLE_BENCHMARKING)\n\
    \    void XmlReporter::benchmarkPreparing(std::string const& name) {\n       \
    \ m_xml.startElement(\"BenchmarkResults\")\n            .writeAttribute(\"name\"\
    , name);\n    }\n\n    void XmlReporter::benchmarkStarting(BenchmarkInfo const\
    \ &info) {\n        m_xml.writeAttribute(\"samples\", info.samples)\n        \
    \    .writeAttribute(\"resamples\", info.resamples)\n            .writeAttribute(\"\
    iterations\", info.iterations)\n            .writeAttribute(\"clockResolution\"\
    , info.clockResolution)\n            .writeAttribute(\"estimatedDuration\", info.estimatedDuration)\n\
    \            .writeComment(\"All values in nano seconds\");\n    }\n\n    void\
    \ XmlReporter::benchmarkEnded(BenchmarkStats<> const& benchmarkStats) {\n    \
    \    m_xml.startElement(\"mean\")\n            .writeAttribute(\"value\", benchmarkStats.mean.point.count())\n\
    \            .writeAttribute(\"lowerBound\", benchmarkStats.mean.lower_bound.count())\n\
    \            .writeAttribute(\"upperBound\", benchmarkStats.mean.upper_bound.count())\n\
    \            .writeAttribute(\"ci\", benchmarkStats.mean.confidence_interval);\n\
    \        m_xml.endElement();\n        m_xml.startElement(\"standardDeviation\"\
    )\n            .writeAttribute(\"value\", benchmarkStats.standardDeviation.point.count())\n\
    \            .writeAttribute(\"lowerBound\", benchmarkStats.standardDeviation.lower_bound.count())\n\
    \            .writeAttribute(\"upperBound\", benchmarkStats.standardDeviation.upper_bound.count())\n\
    \            .writeAttribute(\"ci\", benchmarkStats.standardDeviation.confidence_interval);\n\
    \        m_xml.endElement();\n        m_xml.startElement(\"outliers\")\n     \
    \       .writeAttribute(\"variance\", benchmarkStats.outlierVariance)\n      \
    \      .writeAttribute(\"lowMild\", benchmarkStats.outliers.low_mild)\n      \
    \      .writeAttribute(\"lowSevere\", benchmarkStats.outliers.low_severe)\n  \
    \          .writeAttribute(\"highMild\", benchmarkStats.outliers.high_mild)\n\
    \            .writeAttribute(\"highSevere\", benchmarkStats.outliers.high_severe);\n\
    \        m_xml.endElement();\n        m_xml.endElement();\n    }\n\n    void XmlReporter::benchmarkFailed(std::string\
    \ const &error) {\n        m_xml.scopedElement(\"failed\").\n            writeAttribute(\"\
    message\", error);\n        m_xml.endElement();\n    }\n#endif // CATCH_CONFIG_ENABLE_BENCHMARKING\n\
    \n    CATCH_REGISTER_REPORTER( \"xml\", XmlReporter )\n\n} // end namespace Catch\n\
    \n#if defined(_MSC_VER)\n#pragma warning(pop)\n#endif\n// end catch_reporter_xml.cpp\n\
    \nnamespace Catch {\n    LeakDetector leakDetector;\n}\n\n#ifdef __clang__\n#pragma\
    \ clang diagnostic pop\n#endif\n\n// end catch_impl.hpp\n#endif\n\n#ifdef CATCH_CONFIG_MAIN\n\
    // start catch_default_main.hpp\n\n#ifndef __OBJC__\n\n#if defined(CATCH_CONFIG_WCHAR)\
    \ && defined(CATCH_PLATFORM_WINDOWS) && defined(_UNICODE) && !defined(DO_NOT_USE_WMAIN)\n\
    // Standard C/C++ Win32 Unicode wmain entry point\nextern \"C\" int wmain (int\
    \ argc, wchar_t * argv[], wchar_t * []) {\n#else\n// Standard C/C++ main entry\
    \ point\nint main (int argc, char * argv[]) {\n#endif\n\n    return Catch::Session().run(\
    \ argc, argv );\n}\n\n#else // __OBJC__\n\n// Objective-C entry point\nint main\
    \ (int argc, char * const argv[]) {\n#if !CATCH_ARC_ENABLED\n    NSAutoreleasePool\
    \ * pool = [[NSAutoreleasePool alloc] init];\n#endif\n\n    Catch::registerTestMethods();\n\
    \    int result = Catch::Session().run( argc, (char**)argv );\n\n#if !CATCH_ARC_ENABLED\n\
    \    [pool drain];\n#endif\n\n    return result;\n}\n\n#endif // __OBJC__\n\n\
    // end catch_default_main.hpp\n#endif\n\n#if !defined(CATCH_CONFIG_IMPL_ONLY)\n\
    \n#ifdef CLARA_CONFIG_MAIN_NOT_DEFINED\n#  undef CLARA_CONFIG_MAIN\n#endif\n\n\
    #if !defined(CATCH_CONFIG_DISABLE)\n//////\n// If this config identifier is defined\
    \ then all CATCH macros are prefixed with CATCH_\n#ifdef CATCH_CONFIG_PREFIX_ALL\n\
    \n#define CATCH_REQUIRE( ... ) INTERNAL_CATCH_TEST( \"CATCH_REQUIRE\", Catch::ResultDisposition::Normal,\
    \ __VA_ARGS__ )\n#define CATCH_REQUIRE_FALSE( ... ) INTERNAL_CATCH_TEST( \"CATCH_REQUIRE_FALSE\"\
    , Catch::ResultDisposition::Normal | Catch::ResultDisposition::FalseTest, __VA_ARGS__\
    \ )\n\n#define CATCH_REQUIRE_THROWS( ... ) INTERNAL_CATCH_THROWS( \"CATCH_REQUIRE_THROWS\"\
    , Catch::ResultDisposition::Normal, __VA_ARGS__ )\n#define CATCH_REQUIRE_THROWS_AS(\
    \ expr, exceptionType ) INTERNAL_CATCH_THROWS_AS( \"CATCH_REQUIRE_THROWS_AS\"\
    , exceptionType, Catch::ResultDisposition::Normal, expr )\n#define CATCH_REQUIRE_THROWS_WITH(\
    \ expr, matcher ) INTERNAL_CATCH_THROWS_STR_MATCHES( \"CATCH_REQUIRE_THROWS_WITH\"\
    , Catch::ResultDisposition::Normal, matcher, expr )\n#if !defined(CATCH_CONFIG_DISABLE_MATCHERS)\n\
    #define CATCH_REQUIRE_THROWS_MATCHES( expr, exceptionType, matcher ) INTERNAL_CATCH_THROWS_MATCHES(\
    \ \"CATCH_REQUIRE_THROWS_MATCHES\", exceptionType, Catch::ResultDisposition::Normal,\
    \ matcher, expr )\n#endif// CATCH_CONFIG_DISABLE_MATCHERS\n#define CATCH_REQUIRE_NOTHROW(\
    \ ... ) INTERNAL_CATCH_NO_THROW( \"CATCH_REQUIRE_NOTHROW\", Catch::ResultDisposition::Normal,\
    \ __VA_ARGS__ )\n\n#define CATCH_CHECK( ... ) INTERNAL_CATCH_TEST( \"CATCH_CHECK\"\
    , Catch::ResultDisposition::ContinueOnFailure, __VA_ARGS__ )\n#define CATCH_CHECK_FALSE(\
    \ ... ) INTERNAL_CATCH_TEST( \"CATCH_CHECK_FALSE\", Catch::ResultDisposition::ContinueOnFailure\
    \ | Catch::ResultDisposition::FalseTest, __VA_ARGS__ )\n#define CATCH_CHECKED_IF(\
    \ ... ) INTERNAL_CATCH_IF( \"CATCH_CHECKED_IF\", Catch::ResultDisposition::ContinueOnFailure,\
    \ __VA_ARGS__ )\n#define CATCH_CHECKED_ELSE( ... ) INTERNAL_CATCH_ELSE( \"CATCH_CHECKED_ELSE\"\
    , Catch::ResultDisposition::ContinueOnFailure, __VA_ARGS__ )\n#define CATCH_CHECK_NOFAIL(\
    \ ... ) INTERNAL_CATCH_TEST( \"CATCH_CHECK_NOFAIL\", Catch::ResultDisposition::ContinueOnFailure\
    \ | Catch::ResultDisposition::SuppressFail, __VA_ARGS__ )\n\n#define CATCH_CHECK_THROWS(\
    \ ... )  INTERNAL_CATCH_THROWS( \"CATCH_CHECK_THROWS\", Catch::ResultDisposition::ContinueOnFailure,\
    \ __VA_ARGS__ )\n#define CATCH_CHECK_THROWS_AS( expr, exceptionType ) INTERNAL_CATCH_THROWS_AS(\
    \ \"CATCH_CHECK_THROWS_AS\", exceptionType, Catch::ResultDisposition::ContinueOnFailure,\
    \ expr )\n#define CATCH_CHECK_THROWS_WITH( expr, matcher ) INTERNAL_CATCH_THROWS_STR_MATCHES(\
    \ \"CATCH_CHECK_THROWS_WITH\", Catch::ResultDisposition::ContinueOnFailure, matcher,\
    \ expr )\n#if !defined(CATCH_CONFIG_DISABLE_MATCHERS)\n#define CATCH_CHECK_THROWS_MATCHES(\
    \ expr, exceptionType, matcher ) INTERNAL_CATCH_THROWS_MATCHES( \"CATCH_CHECK_THROWS_MATCHES\"\
    , exceptionType, Catch::ResultDisposition::ContinueOnFailure, matcher, expr )\n\
    #endif // CATCH_CONFIG_DISABLE_MATCHERS\n#define CATCH_CHECK_NOTHROW( ... ) INTERNAL_CATCH_NO_THROW(\
    \ \"CATCH_CHECK_NOTHROW\", Catch::ResultDisposition::ContinueOnFailure, __VA_ARGS__\
    \ )\n\n#if !defined(CATCH_CONFIG_DISABLE_MATCHERS)\n#define CATCH_CHECK_THAT(\
    \ arg, matcher ) INTERNAL_CHECK_THAT( \"CATCH_CHECK_THAT\", matcher, Catch::ResultDisposition::ContinueOnFailure,\
    \ arg )\n\n#define CATCH_REQUIRE_THAT( arg, matcher ) INTERNAL_CHECK_THAT( \"\
    CATCH_REQUIRE_THAT\", matcher, Catch::ResultDisposition::Normal, arg )\n#endif\
    \ // CATCH_CONFIG_DISABLE_MATCHERS\n\n#define CATCH_INFO( msg ) INTERNAL_CATCH_INFO(\
    \ \"CATCH_INFO\", msg )\n#define CATCH_UNSCOPED_INFO( msg ) INTERNAL_CATCH_UNSCOPED_INFO(\
    \ \"CATCH_UNSCOPED_INFO\", msg )\n#define CATCH_WARN( msg ) INTERNAL_CATCH_MSG(\
    \ \"CATCH_WARN\", Catch::ResultWas::Warning, Catch::ResultDisposition::ContinueOnFailure,\
    \ msg )\n#define CATCH_CAPTURE( ... ) INTERNAL_CATCH_CAPTURE( INTERNAL_CATCH_UNIQUE_NAME(capturer),\
    \ \"CATCH_CAPTURE\",__VA_ARGS__ )\n\n#define CATCH_TEST_CASE( ... ) INTERNAL_CATCH_TESTCASE(\
    \ __VA_ARGS__ )\n#define CATCH_TEST_CASE_METHOD( className, ... ) INTERNAL_CATCH_TEST_CASE_METHOD(\
    \ className, __VA_ARGS__ )\n#define CATCH_METHOD_AS_TEST_CASE( method, ... ) INTERNAL_CATCH_METHOD_AS_TEST_CASE(\
    \ method, __VA_ARGS__ )\n#define CATCH_REGISTER_TEST_CASE( Function, ... ) INTERNAL_CATCH_REGISTER_TESTCASE(\
    \ Function, __VA_ARGS__ )\n#define CATCH_SECTION( ... ) INTERNAL_CATCH_SECTION(\
    \ __VA_ARGS__ )\n#define CATCH_DYNAMIC_SECTION( ... ) INTERNAL_CATCH_DYNAMIC_SECTION(\
    \ __VA_ARGS__ )\n#define CATCH_FAIL( ... ) INTERNAL_CATCH_MSG( \"CATCH_FAIL\"\
    , Catch::ResultWas::ExplicitFailure, Catch::ResultDisposition::Normal, __VA_ARGS__\
    \ )\n#define CATCH_FAIL_CHECK( ... ) INTERNAL_CATCH_MSG( \"CATCH_FAIL_CHECK\"\
    , Catch::ResultWas::ExplicitFailure, Catch::ResultDisposition::ContinueOnFailure,\
    \ __VA_ARGS__ )\n#define CATCH_SUCCEED( ... ) INTERNAL_CATCH_MSG( \"CATCH_SUCCEED\"\
    , Catch::ResultWas::Ok, Catch::ResultDisposition::ContinueOnFailure, __VA_ARGS__\
    \ )\n\n#define CATCH_ANON_TEST_CASE() INTERNAL_CATCH_TESTCASE()\n\n#ifndef CATCH_CONFIG_TRADITIONAL_MSVC_PREPROCESSOR\n\
    #define CATCH_TEMPLATE_TEST_CASE( ... ) INTERNAL_CATCH_TEMPLATE_TEST_CASE( __VA_ARGS__\
    \ )\n#define CATCH_TEMPLATE_TEST_CASE_SIG( ... ) INTERNAL_CATCH_TEMPLATE_TEST_CASE_SIG(\
    \ __VA_ARGS__ )\n#define CATCH_TEMPLATE_TEST_CASE_METHOD( className, ... ) INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD(\
    \ className, __VA_ARGS__ )\n#define CATCH_TEMPLATE_TEST_CASE_METHOD_SIG( className,\
    \ ... ) INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD_SIG( className, __VA_ARGS__ )\n\
    #define CATCH_TEMPLATE_PRODUCT_TEST_CASE( ... ) INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE(\
    \ __VA_ARGS__ )\n#define CATCH_TEMPLATE_PRODUCT_TEST_CASE_SIG( ... ) INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE_SIG(\
    \ __VA_ARGS__ )\n#define CATCH_TEMPLATE_PRODUCT_TEST_CASE_METHOD( className, ...\
    \ ) INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE_METHOD( className, __VA_ARGS__ )\n\
    #define CATCH_TEMPLATE_PRODUCT_TEST_CASE_METHOD_SIG( className, ... ) INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE_METHOD_SIG(\
    \ className, __VA_ARGS__ )\n#else\n#define CATCH_TEMPLATE_TEST_CASE( ... ) INTERNAL_CATCH_EXPAND_VARGS(\
    \ INTERNAL_CATCH_TEMPLATE_TEST_CASE( __VA_ARGS__ ) )\n#define CATCH_TEMPLATE_TEST_CASE_SIG(\
    \ ... ) INTERNAL_CATCH_EXPAND_VARGS( INTERNAL_CATCH_TEMPLATE_TEST_CASE_SIG( __VA_ARGS__\
    \ ) )\n#define CATCH_TEMPLATE_TEST_CASE_METHOD( className, ... ) INTERNAL_CATCH_EXPAND_VARGS(\
    \ INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD( className, __VA_ARGS__ ) )\n#define\
    \ CATCH_TEMPLATE_TEST_CASE_METHOD_SIG( className, ... ) INTERNAL_CATCH_EXPAND_VARGS(\
    \ INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD_SIG( className, __VA_ARGS__ ) )\n#define\
    \ CATCH_TEMPLATE_PRODUCT_TEST_CASE( ... ) INTERNAL_CATCH_EXPAND_VARGS( INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE(\
    \ __VA_ARGS__ ) )\n#define CATCH_TEMPLATE_PRODUCT_TEST_CASE_SIG( ... ) INTERNAL_CATCH_EXPAND_VARGS(\
    \ INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE_SIG( __VA_ARGS__ ) )\n#define CATCH_TEMPLATE_PRODUCT_TEST_CASE_METHOD(\
    \ className, ... ) INTERNAL_CATCH_EXPAND_VARGS( INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE_METHOD(\
    \ className, __VA_ARGS__ ) )\n#define CATCH_TEMPLATE_PRODUCT_TEST_CASE_METHOD_SIG(\
    \ className, ... ) INTERNAL_CATCH_EXPAND_VARGS( INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE_METHOD_SIG(\
    \ className, __VA_ARGS__ ) )\n#endif\n\n#if !defined(CATCH_CONFIG_RUNTIME_STATIC_REQUIRE)\n\
    #define CATCH_STATIC_REQUIRE( ... )       static_assert(   __VA_ARGS__ ,     \
    \ #__VA_ARGS__ );     CATCH_SUCCEED( #__VA_ARGS__ )\n#define CATCH_STATIC_REQUIRE_FALSE(\
    \ ... ) static_assert( !(__VA_ARGS__), \"!(\" #__VA_ARGS__ \")\" ); CATCH_SUCCEED(\
    \ #__VA_ARGS__ )\n#else\n#define CATCH_STATIC_REQUIRE( ... )       CATCH_REQUIRE(\
    \ __VA_ARGS__ )\n#define CATCH_STATIC_REQUIRE_FALSE( ... ) CATCH_REQUIRE_FALSE(\
    \ __VA_ARGS__ )\n#endif\n\n// \"BDD-style\" convenience wrappers\n#define CATCH_SCENARIO(\
    \ ... ) CATCH_TEST_CASE( \"Scenario: \" __VA_ARGS__ )\n#define CATCH_SCENARIO_METHOD(\
    \ className, ... ) INTERNAL_CATCH_TEST_CASE_METHOD( className, \"Scenario: \"\
    \ __VA_ARGS__ )\n#define CATCH_GIVEN( desc )     INTERNAL_CATCH_DYNAMIC_SECTION(\
    \ \"    Given: \" << desc )\n#define CATCH_AND_GIVEN( desc ) INTERNAL_CATCH_DYNAMIC_SECTION(\
    \ \"And given: \" << desc )\n#define CATCH_WHEN( desc )      INTERNAL_CATCH_DYNAMIC_SECTION(\
    \ \"     When: \" << desc )\n#define CATCH_AND_WHEN( desc )  INTERNAL_CATCH_DYNAMIC_SECTION(\
    \ \" And when: \" << desc )\n#define CATCH_THEN( desc )      INTERNAL_CATCH_DYNAMIC_SECTION(\
    \ \"     Then: \" << desc )\n#define CATCH_AND_THEN( desc )  INTERNAL_CATCH_DYNAMIC_SECTION(\
    \ \"      And: \" << desc )\n\n#if defined(CATCH_CONFIG_ENABLE_BENCHMARKING)\n\
    #define CATCH_BENCHMARK(...) \\\n    INTERNAL_CATCH_BENCHMARK(INTERNAL_CATCH_UNIQUE_NAME(____C_A_T_C_H____B_E_N_C_H____),\
    \ INTERNAL_CATCH_GET_1_ARG(__VA_ARGS__,,), INTERNAL_CATCH_GET_2_ARG(__VA_ARGS__,,))\n\
    #define CATCH_BENCHMARK_ADVANCED(name) \\\n    INTERNAL_CATCH_BENCHMARK_ADVANCED(INTERNAL_CATCH_UNIQUE_NAME(____C_A_T_C_H____B_E_N_C_H____),\
    \ name)\n#endif // CATCH_CONFIG_ENABLE_BENCHMARKING\n\n// If CATCH_CONFIG_PREFIX_ALL\
    \ is not defined then the CATCH_ prefix is not required\n#else\n\n#define REQUIRE(\
    \ ... ) INTERNAL_CATCH_TEST( \"REQUIRE\", Catch::ResultDisposition::Normal, __VA_ARGS__\
    \  )\n#define REQUIRE_FALSE( ... ) INTERNAL_CATCH_TEST( \"REQUIRE_FALSE\", Catch::ResultDisposition::Normal\
    \ | Catch::ResultDisposition::FalseTest, __VA_ARGS__ )\n\n#define REQUIRE_THROWS(\
    \ ... ) INTERNAL_CATCH_THROWS( \"REQUIRE_THROWS\", Catch::ResultDisposition::Normal,\
    \ __VA_ARGS__ )\n#define REQUIRE_THROWS_AS( expr, exceptionType ) INTERNAL_CATCH_THROWS_AS(\
    \ \"REQUIRE_THROWS_AS\", exceptionType, Catch::ResultDisposition::Normal, expr\
    \ )\n#define REQUIRE_THROWS_WITH( expr, matcher ) INTERNAL_CATCH_THROWS_STR_MATCHES(\
    \ \"REQUIRE_THROWS_WITH\", Catch::ResultDisposition::Normal, matcher, expr )\n\
    #if !defined(CATCH_CONFIG_DISABLE_MATCHERS)\n#define REQUIRE_THROWS_MATCHES( expr,\
    \ exceptionType, matcher ) INTERNAL_CATCH_THROWS_MATCHES( \"REQUIRE_THROWS_MATCHES\"\
    , exceptionType, Catch::ResultDisposition::Normal, matcher, expr )\n#endif //\
    \ CATCH_CONFIG_DISABLE_MATCHERS\n#define REQUIRE_NOTHROW( ... ) INTERNAL_CATCH_NO_THROW(\
    \ \"REQUIRE_NOTHROW\", Catch::ResultDisposition::Normal, __VA_ARGS__ )\n\n#define\
    \ CHECK( ... ) INTERNAL_CATCH_TEST( \"CHECK\", Catch::ResultDisposition::ContinueOnFailure,\
    \ __VA_ARGS__ )\n#define CHECK_FALSE( ... ) INTERNAL_CATCH_TEST( \"CHECK_FALSE\"\
    , Catch::ResultDisposition::ContinueOnFailure | Catch::ResultDisposition::FalseTest,\
    \ __VA_ARGS__ )\n#define CHECKED_IF( ... ) INTERNAL_CATCH_IF( \"CHECKED_IF\",\
    \ Catch::ResultDisposition::ContinueOnFailure, __VA_ARGS__ )\n#define CHECKED_ELSE(\
    \ ... ) INTERNAL_CATCH_ELSE( \"CHECKED_ELSE\", Catch::ResultDisposition::ContinueOnFailure,\
    \ __VA_ARGS__ )\n#define CHECK_NOFAIL( ... ) INTERNAL_CATCH_TEST( \"CHECK_NOFAIL\"\
    , Catch::ResultDisposition::ContinueOnFailure | Catch::ResultDisposition::SuppressFail,\
    \ __VA_ARGS__ )\n\n#define CHECK_THROWS( ... )  INTERNAL_CATCH_THROWS( \"CHECK_THROWS\"\
    , Catch::ResultDisposition::ContinueOnFailure, __VA_ARGS__ )\n#define CHECK_THROWS_AS(\
    \ expr, exceptionType ) INTERNAL_CATCH_THROWS_AS( \"CHECK_THROWS_AS\", exceptionType,\
    \ Catch::ResultDisposition::ContinueOnFailure, expr )\n#define CHECK_THROWS_WITH(\
    \ expr, matcher ) INTERNAL_CATCH_THROWS_STR_MATCHES( \"CHECK_THROWS_WITH\", Catch::ResultDisposition::ContinueOnFailure,\
    \ matcher, expr )\n#if !defined(CATCH_CONFIG_DISABLE_MATCHERS)\n#define CHECK_THROWS_MATCHES(\
    \ expr, exceptionType, matcher ) INTERNAL_CATCH_THROWS_MATCHES( \"CHECK_THROWS_MATCHES\"\
    , exceptionType, Catch::ResultDisposition::ContinueOnFailure, matcher, expr )\n\
    #endif // CATCH_CONFIG_DISABLE_MATCHERS\n#define CHECK_NOTHROW( ... ) INTERNAL_CATCH_NO_THROW(\
    \ \"CHECK_NOTHROW\", Catch::ResultDisposition::ContinueOnFailure, __VA_ARGS__\
    \ )\n\n#if !defined(CATCH_CONFIG_DISABLE_MATCHERS)\n#define CHECK_THAT( arg, matcher\
    \ ) INTERNAL_CHECK_THAT( \"CHECK_THAT\", matcher, Catch::ResultDisposition::ContinueOnFailure,\
    \ arg )\n\n#define REQUIRE_THAT( arg, matcher ) INTERNAL_CHECK_THAT( \"REQUIRE_THAT\"\
    , matcher, Catch::ResultDisposition::Normal, arg )\n#endif // CATCH_CONFIG_DISABLE_MATCHERS\n\
    \n#define INFO( msg ) INTERNAL_CATCH_INFO( \"INFO\", msg )\n#define UNSCOPED_INFO(\
    \ msg ) INTERNAL_CATCH_UNSCOPED_INFO( \"UNSCOPED_INFO\", msg )\n#define WARN(\
    \ msg ) INTERNAL_CATCH_MSG( \"WARN\", Catch::ResultWas::Warning, Catch::ResultDisposition::ContinueOnFailure,\
    \ msg )\n#define CAPTURE( ... ) INTERNAL_CATCH_CAPTURE( INTERNAL_CATCH_UNIQUE_NAME(capturer),\
    \ \"CAPTURE\",__VA_ARGS__ )\n\n#define TEST_CASE( ... ) INTERNAL_CATCH_TESTCASE(\
    \ __VA_ARGS__ )\n#define TEST_CASE_METHOD( className, ... ) INTERNAL_CATCH_TEST_CASE_METHOD(\
    \ className, __VA_ARGS__ )\n#define METHOD_AS_TEST_CASE( method, ... ) INTERNAL_CATCH_METHOD_AS_TEST_CASE(\
    \ method, __VA_ARGS__ )\n#define REGISTER_TEST_CASE( Function, ... ) INTERNAL_CATCH_REGISTER_TESTCASE(\
    \ Function, __VA_ARGS__ )\n#define SECTION( ... ) INTERNAL_CATCH_SECTION( __VA_ARGS__\
    \ )\n#define DYNAMIC_SECTION( ... ) INTERNAL_CATCH_DYNAMIC_SECTION( __VA_ARGS__\
    \ )\n#define FAIL( ... ) INTERNAL_CATCH_MSG( \"FAIL\", Catch::ResultWas::ExplicitFailure,\
    \ Catch::ResultDisposition::Normal, __VA_ARGS__ )\n#define FAIL_CHECK( ... ) INTERNAL_CATCH_MSG(\
    \ \"FAIL_CHECK\", Catch::ResultWas::ExplicitFailure, Catch::ResultDisposition::ContinueOnFailure,\
    \ __VA_ARGS__ )\n#define SUCCEED( ... ) INTERNAL_CATCH_MSG( \"SUCCEED\", Catch::ResultWas::Ok,\
    \ Catch::ResultDisposition::ContinueOnFailure, __VA_ARGS__ )\n#define ANON_TEST_CASE()\
    \ INTERNAL_CATCH_TESTCASE()\n\n#ifndef CATCH_CONFIG_TRADITIONAL_MSVC_PREPROCESSOR\n\
    #define TEMPLATE_TEST_CASE( ... ) INTERNAL_CATCH_TEMPLATE_TEST_CASE( __VA_ARGS__\
    \ )\n#define TEMPLATE_TEST_CASE_SIG( ... ) INTERNAL_CATCH_TEMPLATE_TEST_CASE_SIG(\
    \ __VA_ARGS__ )\n#define TEMPLATE_TEST_CASE_METHOD( className, ... ) INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD(\
    \ className, __VA_ARGS__ )\n#define TEMPLATE_TEST_CASE_METHOD_SIG( className,\
    \ ... ) INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD_SIG( className, __VA_ARGS__ )\n\
    #define TEMPLATE_PRODUCT_TEST_CASE( ... ) INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE(\
    \ __VA_ARGS__ )\n#define TEMPLATE_PRODUCT_TEST_CASE_SIG( ... ) INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE_SIG(\
    \ __VA_ARGS__ )\n#define TEMPLATE_PRODUCT_TEST_CASE_METHOD( className, ... ) INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE_METHOD(\
    \ className, __VA_ARGS__ )\n#define TEMPLATE_PRODUCT_TEST_CASE_METHOD_SIG( className,\
    \ ... ) INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE_METHOD_SIG( className, __VA_ARGS__\
    \ )\n#define TEMPLATE_LIST_TEST_CASE( ... ) INTERNAL_CATCH_TEMPLATE_LIST_TEST_CASE(__VA_ARGS__)\n\
    #define TEMPLATE_LIST_TEST_CASE_METHOD( className, ... ) INTERNAL_CATCH_TEMPLATE_LIST_TEST_CASE_METHOD(\
    \ className, __VA_ARGS__ )\n#else\n#define TEMPLATE_TEST_CASE( ... ) INTERNAL_CATCH_EXPAND_VARGS(\
    \ INTERNAL_CATCH_TEMPLATE_TEST_CASE( __VA_ARGS__ ) )\n#define TEMPLATE_TEST_CASE_SIG(\
    \ ... ) INTERNAL_CATCH_EXPAND_VARGS( INTERNAL_CATCH_TEMPLATE_TEST_CASE_SIG( __VA_ARGS__\
    \ ) )\n#define TEMPLATE_TEST_CASE_METHOD( className, ... ) INTERNAL_CATCH_EXPAND_VARGS(\
    \ INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD( className, __VA_ARGS__ ) )\n#define\
    \ TEMPLATE_TEST_CASE_METHOD_SIG( className, ... ) INTERNAL_CATCH_EXPAND_VARGS(\
    \ INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD_SIG( className, __VA_ARGS__ ) )\n#define\
    \ TEMPLATE_PRODUCT_TEST_CASE( ... ) INTERNAL_CATCH_EXPAND_VARGS( INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE(\
    \ __VA_ARGS__ ) )\n#define TEMPLATE_PRODUCT_TEST_CASE_SIG( ... ) INTERNAL_CATCH_EXPAND_VARGS(\
    \ INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE_SIG( __VA_ARGS__ ) )\n#define TEMPLATE_PRODUCT_TEST_CASE_METHOD(\
    \ className, ... ) INTERNAL_CATCH_EXPAND_VARGS( INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE_METHOD(\
    \ className, __VA_ARGS__ ) )\n#define TEMPLATE_PRODUCT_TEST_CASE_METHOD_SIG( className,\
    \ ... ) INTERNAL_CATCH_EXPAND_VARGS( INTERNAL_CATCH_TEMPLATE_PRODUCT_TEST_CASE_METHOD_SIG(\
    \ className, __VA_ARGS__ ) )\n#define TEMPLATE_LIST_TEST_CASE( ... ) INTERNAL_CATCH_EXPAND_VARGS(\
    \ INTERNAL_CATCH_TEMPLATE_LIST_TEST_CASE( __VA_ARGS__ ) )\n#define TEMPLATE_LIST_TEST_CASE_METHOD(\
    \ className, ... ) INTERNAL_CATCH_EXPAND_VARGS( INTERNAL_CATCH_TEMPLATE_LIST_TEST_CASE_METHOD(\
    \ className, __VA_ARGS__ ) )\n#endif\n\n#if !defined(CATCH_CONFIG_RUNTIME_STATIC_REQUIRE)\n\
    #define STATIC_REQUIRE( ... )       static_assert(   __VA_ARGS__,  #__VA_ARGS__\
    \ ); SUCCEED( #__VA_ARGS__ )\n#define STATIC_REQUIRE_FALSE( ... ) static_assert(\
    \ !(__VA_ARGS__), \"!(\" #__VA_ARGS__ \")\" ); SUCCEED( \"!(\" #__VA_ARGS__ \"\
    )\" )\n#else\n#define STATIC_REQUIRE( ... )       REQUIRE( __VA_ARGS__ )\n#define\
    \ STATIC_REQUIRE_FALSE( ... ) REQUIRE_FALSE( __VA_ARGS__ )\n#endif\n\n#endif\n\
    \n#define CATCH_TRANSLATE_EXCEPTION( signature ) INTERNAL_CATCH_TRANSLATE_EXCEPTION(\
    \ signature )\n\n// \"BDD-style\" convenience wrappers\n#define SCENARIO( ...\
    \ ) TEST_CASE( \"Scenario: \" __VA_ARGS__ )\n#define SCENARIO_METHOD( className,\
    \ ... ) INTERNAL_CATCH_TEST_CASE_METHOD( className, \"Scenario: \" __VA_ARGS__\
    \ )\n\n#define GIVEN( desc )     INTERNAL_CATCH_DYNAMIC_SECTION( \"    Given:\
    \ \" << desc )\n#define AND_GIVEN( desc ) INTERNAL_CATCH_DYNAMIC_SECTION( \"And\
    \ given: \" << desc )\n#define WHEN( desc )      INTERNAL_CATCH_DYNAMIC_SECTION(\
    \ \"     When: \" << desc )\n#define AND_WHEN( desc )  INTERNAL_CATCH_DYNAMIC_SECTION(\
    \ \" And when: \" << desc )\n#define THEN( desc )      INTERNAL_CATCH_DYNAMIC_SECTION(\
    \ \"     Then: \" << desc )\n#define AND_THEN( desc )  INTERNAL_CATCH_DYNAMIC_SECTION(\
    \ \"      And: \" << desc )\n\n#if defined(CATCH_CONFIG_ENABLE_BENCHMARKING)\n\
    #define BENCHMARK(...) \\\n    INTERNAL_CATCH_BENCHMARK(INTERNAL_CATCH_UNIQUE_NAME(____C_A_T_C_H____B_E_N_C_H____),\
    \ INTERNAL_CATCH_GET_1_ARG(__VA_ARGS__,,), INTERNAL_CATCH_GET_2_ARG(__VA_ARGS__,,))\n\
    #define BENCHMARK_ADVANCED(name) \\\n    INTERNAL_CATCH_BENCHMARK_ADVANCED(INTERNAL_CATCH_UNIQUE_NAME(____C_A_T_C_H____B_E_N_C_H____),\
    \ name)\n#endif // CATCH_CONFIG_ENABLE_BENCHMARKING\n\nusing Catch::Detail::Approx;\n\
    \n#else // CATCH_CONFIG_DISABLE\n\n//////\n// If this config identifier is defined\
    \ then all CATCH macros are prefixed with CATCH_\n#ifdef CATCH_CONFIG_PREFIX_ALL\n\
    \n#define CATCH_REQUIRE( ... )        (void)(0)\n#define CATCH_REQUIRE_FALSE(\
    \ ... )  (void)(0)\n\n#define CATCH_REQUIRE_THROWS( ... ) (void)(0)\n#define CATCH_REQUIRE_THROWS_AS(\
    \ expr, exceptionType ) (void)(0)\n#define CATCH_REQUIRE_THROWS_WITH( expr, matcher\
    \ )     (void)(0)\n#if !defined(CATCH_CONFIG_DISABLE_MATCHERS)\n#define CATCH_REQUIRE_THROWS_MATCHES(\
    \ expr, exceptionType, matcher ) (void)(0)\n#endif// CATCH_CONFIG_DISABLE_MATCHERS\n\
    #define CATCH_REQUIRE_NOTHROW( ... ) (void)(0)\n\n#define CATCH_CHECK( ... ) \
    \        (void)(0)\n#define CATCH_CHECK_FALSE( ... )   (void)(0)\n#define CATCH_CHECKED_IF(\
    \ ... )    if (__VA_ARGS__)\n#define CATCH_CHECKED_ELSE( ... )  if (!(__VA_ARGS__))\n\
    #define CATCH_CHECK_NOFAIL( ... )  (void)(0)\n\n#define CATCH_CHECK_THROWS( ...\
    \ )  (void)(0)\n#define CATCH_CHECK_THROWS_AS( expr, exceptionType ) (void)(0)\n\
    #define CATCH_CHECK_THROWS_WITH( expr, matcher )     (void)(0)\n#if !defined(CATCH_CONFIG_DISABLE_MATCHERS)\n\
    #define CATCH_CHECK_THROWS_MATCHES( expr, exceptionType, matcher ) (void)(0)\n\
    #endif // CATCH_CONFIG_DISABLE_MATCHERS\n#define CATCH_CHECK_NOTHROW( ... ) (void)(0)\n\
    \n#if !defined(CATCH_CONFIG_DISABLE_MATCHERS)\n#define CATCH_CHECK_THAT( arg,\
    \ matcher )   (void)(0)\n\n#define CATCH_REQUIRE_THAT( arg, matcher ) (void)(0)\n\
    #endif // CATCH_CONFIG_DISABLE_MATCHERS\n\n#define CATCH_INFO( msg )         \
    \ (void)(0)\n#define CATCH_UNSCOPED_INFO( msg ) (void)(0)\n#define CATCH_WARN(\
    \ msg )          (void)(0)\n#define CATCH_CAPTURE( msg )       (void)(0)\n\n#define\
    \ CATCH_TEST_CASE( ... ) INTERNAL_CATCH_TESTCASE_NO_REGISTRATION(INTERNAL_CATCH_UNIQUE_NAME(\
    \ ____C_A_T_C_H____T_E_S_T____ ))\n#define CATCH_TEST_CASE_METHOD( className,\
    \ ... ) INTERNAL_CATCH_TESTCASE_NO_REGISTRATION(INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_S_T____\
    \ ))\n#define CATCH_METHOD_AS_TEST_CASE( method, ... )\n#define CATCH_REGISTER_TEST_CASE(\
    \ Function, ... ) (void)(0)\n#define CATCH_SECTION( ... )\n#define CATCH_DYNAMIC_SECTION(\
    \ ... )\n#define CATCH_FAIL( ... ) (void)(0)\n#define CATCH_FAIL_CHECK( ... )\
    \ (void)(0)\n#define CATCH_SUCCEED( ... ) (void)(0)\n\n#define CATCH_ANON_TEST_CASE()\
    \ INTERNAL_CATCH_TESTCASE_NO_REGISTRATION(INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_S_T____\
    \ ))\n\n#ifndef CATCH_CONFIG_TRADITIONAL_MSVC_PREPROCESSOR\n#define CATCH_TEMPLATE_TEST_CASE(\
    \ ... ) INTERNAL_CATCH_TEMPLATE_TEST_CASE_NO_REGISTRATION(__VA_ARGS__)\n#define\
    \ CATCH_TEMPLATE_TEST_CASE_SIG( ... ) INTERNAL_CATCH_TEMPLATE_TEST_CASE_SIG_NO_REGISTRATION(__VA_ARGS__)\n\
    #define CATCH_TEMPLATE_TEST_CASE_METHOD( className, ... ) INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD_NO_REGISTRATION(className,\
    \ __VA_ARGS__)\n#define CATCH_TEMPLATE_TEST_CASE_METHOD_SIG( className, ... )\
    \ INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD_SIG_NO_REGISTRATION(className, __VA_ARGS__\
    \ )\n#define CATCH_TEMPLATE_PRODUCT_TEST_CASE( ... ) CATCH_TEMPLATE_TEST_CASE(\
    \ __VA_ARGS__ )\n#define CATCH_TEMPLATE_PRODUCT_TEST_CASE_SIG( ... ) CATCH_TEMPLATE_TEST_CASE(\
    \ __VA_ARGS__ )\n#define CATCH_TEMPLATE_PRODUCT_TEST_CASE_METHOD( className, ...\
    \ ) CATCH_TEMPLATE_TEST_CASE_METHOD( className, __VA_ARGS__ )\n#define CATCH_TEMPLATE_PRODUCT_TEST_CASE_METHOD_SIG(\
    \ className, ... ) CATCH_TEMPLATE_TEST_CASE_METHOD( className, __VA_ARGS__ )\n\
    #else\n#define CATCH_TEMPLATE_TEST_CASE( ... ) INTERNAL_CATCH_EXPAND_VARGS( INTERNAL_CATCH_TEMPLATE_TEST_CASE_NO_REGISTRATION(__VA_ARGS__)\
    \ )\n#define CATCH_TEMPLATE_TEST_CASE_SIG( ... ) INTERNAL_CATCH_EXPAND_VARGS(\
    \ INTERNAL_CATCH_TEMPLATE_TEST_CASE_SIG_NO_REGISTRATION(__VA_ARGS__) )\n#define\
    \ CATCH_TEMPLATE_TEST_CASE_METHOD( className, ... ) INTERNAL_CATCH_EXPAND_VARGS(\
    \ INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD_NO_REGISTRATION(className, __VA_ARGS__\
    \ ) )\n#define CATCH_TEMPLATE_TEST_CASE_METHOD_SIG( className, ... ) INTERNAL_CATCH_EXPAND_VARGS(\
    \ INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD_SIG_NO_REGISTRATION(className, __VA_ARGS__\
    \ ) )\n#define CATCH_TEMPLATE_PRODUCT_TEST_CASE( ... ) CATCH_TEMPLATE_TEST_CASE(\
    \ __VA_ARGS__ )\n#define CATCH_TEMPLATE_PRODUCT_TEST_CASE_SIG( ... ) CATCH_TEMPLATE_TEST_CASE(\
    \ __VA_ARGS__ )\n#define CATCH_TEMPLATE_PRODUCT_TEST_CASE_METHOD( className, ...\
    \ ) CATCH_TEMPLATE_TEST_CASE_METHOD( className, __VA_ARGS__ )\n#define CATCH_TEMPLATE_PRODUCT_TEST_CASE_METHOD_SIG(\
    \ className, ... ) CATCH_TEMPLATE_TEST_CASE_METHOD( className, __VA_ARGS__ )\n\
    #endif\n\n// \"BDD-style\" convenience wrappers\n#define CATCH_SCENARIO( ... )\
    \ INTERNAL_CATCH_TESTCASE_NO_REGISTRATION(INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_S_T____\
    \ ))\n#define CATCH_SCENARIO_METHOD( className, ... ) INTERNAL_CATCH_TESTCASE_METHOD_NO_REGISTRATION(INTERNAL_CATCH_UNIQUE_NAME(\
    \ ____C_A_T_C_H____T_E_S_T____ ), className )\n#define CATCH_GIVEN( desc )\n#define\
    \ CATCH_AND_GIVEN( desc )\n#define CATCH_WHEN( desc )\n#define CATCH_AND_WHEN(\
    \ desc )\n#define CATCH_THEN( desc )\n#define CATCH_AND_THEN( desc )\n\n#define\
    \ CATCH_STATIC_REQUIRE( ... )       (void)(0)\n#define CATCH_STATIC_REQUIRE_FALSE(\
    \ ... ) (void)(0)\n\n// If CATCH_CONFIG_PREFIX_ALL is not defined then the CATCH_\
    \ prefix is not required\n#else\n\n#define REQUIRE( ... )       (void)(0)\n#define\
    \ REQUIRE_FALSE( ... ) (void)(0)\n\n#define REQUIRE_THROWS( ... ) (void)(0)\n\
    #define REQUIRE_THROWS_AS( expr, exceptionType ) (void)(0)\n#define REQUIRE_THROWS_WITH(\
    \ expr, matcher ) (void)(0)\n#if !defined(CATCH_CONFIG_DISABLE_MATCHERS)\n#define\
    \ REQUIRE_THROWS_MATCHES( expr, exceptionType, matcher ) (void)(0)\n#endif //\
    \ CATCH_CONFIG_DISABLE_MATCHERS\n#define REQUIRE_NOTHROW( ... ) (void)(0)\n\n\
    #define CHECK( ... ) (void)(0)\n#define CHECK_FALSE( ... ) (void)(0)\n#define\
    \ CHECKED_IF( ... ) if (__VA_ARGS__)\n#define CHECKED_ELSE( ... ) if (!(__VA_ARGS__))\n\
    #define CHECK_NOFAIL( ... ) (void)(0)\n\n#define CHECK_THROWS( ... )  (void)(0)\n\
    #define CHECK_THROWS_AS( expr, exceptionType ) (void)(0)\n#define CHECK_THROWS_WITH(\
    \ expr, matcher ) (void)(0)\n#if !defined(CATCH_CONFIG_DISABLE_MATCHERS)\n#define\
    \ CHECK_THROWS_MATCHES( expr, exceptionType, matcher ) (void)(0)\n#endif // CATCH_CONFIG_DISABLE_MATCHERS\n\
    #define CHECK_NOTHROW( ... ) (void)(0)\n\n#if !defined(CATCH_CONFIG_DISABLE_MATCHERS)\n\
    #define CHECK_THAT( arg, matcher ) (void)(0)\n\n#define REQUIRE_THAT( arg, matcher\
    \ ) (void)(0)\n#endif // CATCH_CONFIG_DISABLE_MATCHERS\n\n#define INFO( msg )\
    \ (void)(0)\n#define UNSCOPED_INFO( msg ) (void)(0)\n#define WARN( msg ) (void)(0)\n\
    #define CAPTURE( msg ) (void)(0)\n\n#define TEST_CASE( ... )  INTERNAL_CATCH_TESTCASE_NO_REGISTRATION(INTERNAL_CATCH_UNIQUE_NAME(\
    \ ____C_A_T_C_H____T_E_S_T____ ))\n#define TEST_CASE_METHOD( className, ... )\
    \ INTERNAL_CATCH_TESTCASE_NO_REGISTRATION(INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_S_T____\
    \ ))\n#define METHOD_AS_TEST_CASE( method, ... )\n#define REGISTER_TEST_CASE(\
    \ Function, ... ) (void)(0)\n#define SECTION( ... )\n#define DYNAMIC_SECTION(\
    \ ... )\n#define FAIL( ... ) (void)(0)\n#define FAIL_CHECK( ... ) (void)(0)\n\
    #define SUCCEED( ... ) (void)(0)\n#define ANON_TEST_CASE() INTERNAL_CATCH_TESTCASE_NO_REGISTRATION(INTERNAL_CATCH_UNIQUE_NAME(\
    \ ____C_A_T_C_H____T_E_S_T____ ))\n\n#ifndef CATCH_CONFIG_TRADITIONAL_MSVC_PREPROCESSOR\n\
    #define TEMPLATE_TEST_CASE( ... ) INTERNAL_CATCH_TEMPLATE_TEST_CASE_NO_REGISTRATION(__VA_ARGS__)\n\
    #define TEMPLATE_TEST_CASE_SIG( ... ) INTERNAL_CATCH_TEMPLATE_TEST_CASE_SIG_NO_REGISTRATION(__VA_ARGS__)\n\
    #define TEMPLATE_TEST_CASE_METHOD( className, ... ) INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD_NO_REGISTRATION(className,\
    \ __VA_ARGS__)\n#define TEMPLATE_TEST_CASE_METHOD_SIG( className, ... ) INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD_SIG_NO_REGISTRATION(className,\
    \ __VA_ARGS__ )\n#define TEMPLATE_PRODUCT_TEST_CASE( ... ) TEMPLATE_TEST_CASE(\
    \ __VA_ARGS__ )\n#define TEMPLATE_PRODUCT_TEST_CASE_SIG( ... ) TEMPLATE_TEST_CASE(\
    \ __VA_ARGS__ )\n#define TEMPLATE_PRODUCT_TEST_CASE_METHOD( className, ... ) TEMPLATE_TEST_CASE_METHOD(\
    \ className, __VA_ARGS__ )\n#define TEMPLATE_PRODUCT_TEST_CASE_METHOD_SIG( className,\
    \ ... ) TEMPLATE_TEST_CASE_METHOD( className, __VA_ARGS__ )\n#else\n#define TEMPLATE_TEST_CASE(\
    \ ... ) INTERNAL_CATCH_EXPAND_VARGS( INTERNAL_CATCH_TEMPLATE_TEST_CASE_NO_REGISTRATION(__VA_ARGS__)\
    \ )\n#define TEMPLATE_TEST_CASE_SIG( ... ) INTERNAL_CATCH_EXPAND_VARGS( INTERNAL_CATCH_TEMPLATE_TEST_CASE_SIG_NO_REGISTRATION(__VA_ARGS__)\
    \ )\n#define TEMPLATE_TEST_CASE_METHOD( className, ... ) INTERNAL_CATCH_EXPAND_VARGS(\
    \ INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD_NO_REGISTRATION(className, __VA_ARGS__\
    \ ) )\n#define TEMPLATE_TEST_CASE_METHOD_SIG( className, ... ) INTERNAL_CATCH_EXPAND_VARGS(\
    \ INTERNAL_CATCH_TEMPLATE_TEST_CASE_METHOD_SIG_NO_REGISTRATION(className, __VA_ARGS__\
    \ ) )\n#define TEMPLATE_PRODUCT_TEST_CASE( ... ) TEMPLATE_TEST_CASE( __VA_ARGS__\
    \ )\n#define TEMPLATE_PRODUCT_TEST_CASE_SIG( ... ) TEMPLATE_TEST_CASE( __VA_ARGS__\
    \ )\n#define TEMPLATE_PRODUCT_TEST_CASE_METHOD( className, ... ) TEMPLATE_TEST_CASE_METHOD(\
    \ className, __VA_ARGS__ )\n#define TEMPLATE_PRODUCT_TEST_CASE_METHOD_SIG( className,\
    \ ... ) TEMPLATE_TEST_CASE_METHOD( className, __VA_ARGS__ )\n#endif\n\n#define\
    \ STATIC_REQUIRE( ... )       (void)(0)\n#define STATIC_REQUIRE_FALSE( ... ) (void)(0)\n\
    \n#endif\n\n#define CATCH_TRANSLATE_EXCEPTION( signature ) INTERNAL_CATCH_TRANSLATE_EXCEPTION_NO_REG(\
    \ INTERNAL_CATCH_UNIQUE_NAME( catch_internal_ExceptionTranslator ), signature\
    \ )\n\n// \"BDD-style\" convenience wrappers\n#define SCENARIO( ... ) INTERNAL_CATCH_TESTCASE_NO_REGISTRATION(INTERNAL_CATCH_UNIQUE_NAME(\
    \ ____C_A_T_C_H____T_E_S_T____ ) )\n#define SCENARIO_METHOD( className, ... )\
    \ INTERNAL_CATCH_TESTCASE_METHOD_NO_REGISTRATION(INTERNAL_CATCH_UNIQUE_NAME( ____C_A_T_C_H____T_E_S_T____\
    \ ), className )\n\n#define GIVEN( desc )\n#define AND_GIVEN( desc )\n#define\
    \ WHEN( desc )\n#define AND_WHEN( desc )\n#define THEN( desc )\n#define AND_THEN(\
    \ desc )\n\nusing Catch::Detail::Approx;\n\n#endif\n\n#endif // ! CATCH_CONFIG_IMPL_ONLY\n\
    \n// start catch_reenable_warnings.h\n\n\n#ifdef __clang__\n#    ifdef __ICC //\
    \ icpc defines the __clang__ macro\n#        pragma warning(pop)\n#    else\n\
    #        pragma clang diagnostic pop\n#    endif\n#elif defined __GNUC__\n#  \
    \  pragma GCC diagnostic pop\n#endif\n\n// end catch_reenable_warnings.h\n// end\
    \ catch.hpp\n#endif // TWOBLUECUBES_SINGLE_INCLUDE_CATCH_HPP_INCLUDED\n#line 3\
    \ \"tests/unit/Annotation.cpp\"\n\nusing namespace lib;\n\nstruct ToBeNoted {\n\
    \    int x;\n    ToBeNoted(char c) : x(c) {}\n};\n\ntemplate<typename T>\nstruct\
    \ Comparator {\n  bool operator()(const T& a, const T& b) const {\n    return\
    \ a < b;\n  }\n  template <typename Iterator>\n  static void sort(Iterator begin,\
    \ Iterator end) {\n    Comparator<T> cmp;\n    std::sort(begin, end, cmp);\n \
    \ }\n};\n\nTEST_CASE(\"note construction\", \"[note]\") {\n    SECTION(\"default\
    \ constructor\") {\n        Note<std::vector<int>, int> with_note;\n        Note<std::vector<int>>\
    \ without_note;\n\n        REQUIRE(annotation(with_note) == 0);\n    }\n    \n\
    \    SECTION(\"custom constructor\") {\n        Note<ToBeNoted, int> to_be_noted_with_note('a');\n\
    \        Note<ToBeNoted> to_be_noted_without_note('a');\n\n        REQUIRE(to_be_noted_with_note.x\
    \ == 'a');\n        REQUIRE(annotation(to_be_noted_with_note) == 0);\n    }\n\n\
    \    SECTION(\"custom notes\") {\n        Note<ToBeNoted, int> to_be_noted_with_note\
    \ = make_note<ToBeNoted, int>('a', 5);\n\n        REQUIRE(annotation(to_be_noted_with_note)\
    \ == 5);\n\n        annotation(to_be_noted_with_note) = 10;\n\n        REQUIRE(annotation(to_be_noted_with_note)\
    \ == 10);\n    }\n\n    SECTION(\"note assignment\") {\n        Note<ToBeNoted>\
    \ to_be_noted_without_note = ToBeNoted('c');\n        REQUIRE(to_be_noted_without_note.x\
    \ == 'c');\n\n        to_be_noted_without_note = ToBeNoted('d');\n        REQUIRE(to_be_noted_without_note.x\
    \ == 'd');\n    }\n\n    SECTION(\"make_note\") {\n        auto to_be_noted_with_note\
    \ = make_note(ToBeNoted('c'), 5);\n\n        REQUIRE(is_same<decltype(to_be_noted_with_note),\
    \ Note<ToBeNoted, int>>::value == true);\n        REQUIRE(to_be_noted_with_note.x\
    \ == 'c');\n        REQUIRE(annotation(to_be_noted_with_note) == 5);\n    }\n\
    }\n\nTEST_CASE(\"comparator polymorphism\", \"[note]\") {\n    SECTION(\"operator<\"\
    ) {\n        auto note_a = make_note<string, int>(\"abc\", 5);\n        auto note_b\
    \ = make_note<string, int>(\"cde\", 2);\n        Comparator<string> cmp;\n   \
    \     REQUIRE(cmp(note_a, note_b) == true);\n    }\n\n    SECTION(\"sort\") {\n\
    \        vector<Note<string, int>> vs;\n        auto note_a = make_note<string,\
    \ int>(\"abc\", 5);\n        auto note_b = make_note<string, int>(\"cde\", 2);\n\
    \        vs.push_back(note_b);\n        vs.push_back(note_a);\n\n        Comparator<string>::sort(vs.begin(),\
    \ vs.end());\n        REQUIRE(vs[0] == note_a);\n        REQUIRE(vs[1] == note_b);\n\
    \    }\n}\n"
  code: "#include \"../../utils/Annotation.cpp\"\n#include \"../catch.hpp\"\n\nusing\
    \ namespace lib;\n\nstruct ToBeNoted {\n    int x;\n    ToBeNoted(char c) : x(c)\
    \ {}\n};\n\ntemplate<typename T>\nstruct Comparator {\n  bool operator()(const\
    \ T& a, const T& b) const {\n    return a < b;\n  }\n  template <typename Iterator>\n\
    \  static void sort(Iterator begin, Iterator end) {\n    Comparator<T> cmp;\n\
    \    std::sort(begin, end, cmp);\n  }\n};\n\nTEST_CASE(\"note construction\",\
    \ \"[note]\") {\n    SECTION(\"default constructor\") {\n        Note<std::vector<int>,\
    \ int> with_note;\n        Note<std::vector<int>> without_note;\n\n        REQUIRE(annotation(with_note)\
    \ == 0);\n    }\n    \n    SECTION(\"custom constructor\") {\n        Note<ToBeNoted,\
    \ int> to_be_noted_with_note('a');\n        Note<ToBeNoted> to_be_noted_without_note('a');\n\
    \n        REQUIRE(to_be_noted_with_note.x == 'a');\n        REQUIRE(annotation(to_be_noted_with_note)\
    \ == 0);\n    }\n\n    SECTION(\"custom notes\") {\n        Note<ToBeNoted, int>\
    \ to_be_noted_with_note = make_note<ToBeNoted, int>('a', 5);\n\n        REQUIRE(annotation(to_be_noted_with_note)\
    \ == 5);\n\n        annotation(to_be_noted_with_note) = 10;\n\n        REQUIRE(annotation(to_be_noted_with_note)\
    \ == 10);\n    }\n\n    SECTION(\"note assignment\") {\n        Note<ToBeNoted>\
    \ to_be_noted_without_note = ToBeNoted('c');\n        REQUIRE(to_be_noted_without_note.x\
    \ == 'c');\n\n        to_be_noted_without_note = ToBeNoted('d');\n        REQUIRE(to_be_noted_without_note.x\
    \ == 'd');\n    }\n\n    SECTION(\"make_note\") {\n        auto to_be_noted_with_note\
    \ = make_note(ToBeNoted('c'), 5);\n\n        REQUIRE(is_same<decltype(to_be_noted_with_note),\
    \ Note<ToBeNoted, int>>::value == true);\n        REQUIRE(to_be_noted_with_note.x\
    \ == 'c');\n        REQUIRE(annotation(to_be_noted_with_note) == 5);\n    }\n\
    }\n\nTEST_CASE(\"comparator polymorphism\", \"[note]\") {\n    SECTION(\"operator<\"\
    ) {\n        auto note_a = make_note<string, int>(\"abc\", 5);\n        auto note_b\
    \ = make_note<string, int>(\"cde\", 2);\n        Comparator<string> cmp;\n   \
    \     REQUIRE(cmp(note_a, note_b) == true);\n    }\n\n    SECTION(\"sort\") {\n\
    \        vector<Note<string, int>> vs;\n        auto note_a = make_note<string,\
    \ int>(\"abc\", 5);\n        auto note_b = make_note<string, int>(\"cde\", 2);\n\
    \        vs.push_back(note_b);\n        vs.push_back(note_a);\n\n        Comparator<string>::sort(vs.begin(),\
    \ vs.end());\n        REQUIRE(vs[0] == note_a);\n        REQUIRE(vs[1] == note_b);\n\
    \    }\n}"
  dependsOn:
  - utils/Annotation.cpp
  - tests/catch.hpp
  isVerificationFile: false
  path: tests/unit/Annotation.cpp
  requiredBy: []
  timestamp: '2020-10-20 00:40:28-03:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tests/unit/Annotation.cpp
layout: document
redirect_from:
- /library/tests/unit/Annotation.cpp
- /library/tests/unit/Annotation.cpp.html
title: tests/unit/Annotation.cpp
---
