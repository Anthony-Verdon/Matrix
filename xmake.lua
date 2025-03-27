set_targetdir("./")
set_languages("cxx17")

set_toolchains("clang")
set_warnings("allextra", "error")
set_optimize("fastest")
set_symbols("debug")
add_requires("doctest")

target("Matrix")
    set_kind("headeronly")
    add_includedirs("srcs", {public = true})

target("Tester")
    set_kind("binary")
    add_files("tests/**.cpp")
    add_deps("Matrix")
    add_packages("doctest")
    add_includedirs("tests")
