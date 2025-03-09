set_targetdir("./")
set_languages("cxx17")

set_toolchains("clang")
add_ldflags("-stdlib=libc++")
add_cxxflags("-std=c++17")
add_cxxflags("-Wall")
add_cxxflags("-Werror")
add_cxxflags("-Wextra")
add_cxxflags("-O3")

includes("Toolbox")

target("Matrix")
    set_kind("static")
    add_files("srcs/**.cpp")
    add_deps("Toolbox")
    add_includedirs("srcs", {public = true})