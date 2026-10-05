# My First Big C++ Game

This is my first big C++ project: a Terraria-like game I'm building while following the
[C++ Gamedev Course for Beginners – Your First Big C++ Game!](https://www.udemy.com/course/gamedev-course-for-beginners/)
by **Low Level Game Dev** on Udemy. I'm following the course loosely, so some parts of
my code are organized differently from the lessons.

## Built With

- **C++26** (ISO standard, compiled with GCC using `-std=c++26`)
- **[raylib](https://www.raylib.com/) 6.0** – graphics, input, and audio
- **[Dear ImGui](https://github.com/ocornut/imgui)** (docking branch) – debug and editor UI
- **[rlImGui](https://github.com/raylib-extras/rlImGui)** – connects ImGui to raylib

## Building

I skipped the course's CMake section for now, so this project uses a
**Code::Blocks** project file with the MinGW-w64 (GCC) compiler on Windows.
The compiler settings, including the C++26 standard, are saved in the `.cbp`
project file, so they're applied automatically when you open the project.

ImGui and rlImGui don't ship with prebuilt `.a` library files, so I compiled
them together into a single static library, `libimgui.a`.

To build it yourself:

1. Install [Code::Blocks](https://www.codeblocks.org/) and a recent MinGW-w64 GCC
   compiler with C++26 support.
2. Download raylib 6.0 (the `win64_mingw-w64` build), Dear ImGui (docking branch),
   and rlImGui.
3. Compile ImGui and rlImGui together into a single static library (`libimgui.a`),
   or add their `.cpp` files directly to the project.
4. Open the `.cbp` project file and go to **Project → Build options → Search directories**.
   Update the **Compiler** paths to point to the `include` folders and the **Linker**
   paths to point to the `lib` folders on your computer.
5. The project links these libraries (already set in the project file):
   `raylib`, `imgui`, `opengl32`, `gdi32`, `winmm`.
6. Build and run.

### Compiler Notes

- The project uses strict ISO C++26 (`-std=c++26`), not the GNU version (`-std=gnu++26`),
  so the code stays portable to other compilers like Clang and MSVC.
- Warnings are enabled with `-Wall`.
- raylib is linked statically, so no `raylib.dll` is needed to run the game.
- Because of ISO mode, `M_PI` isn't available from `<cmath>` with MinGW.
  Use raylib's `PI` or `std::numbers::pi` from `<numbers>` instead.
- GCC's C++26 support is still incomplete, so very new C++26 features may not compile yet.

## Credits

- Course and game design: [Low Level Game Dev](https://www.udemy.com/course/gamedev-course-for-beginners/)
- Libraries: raylib, Dear ImGui, rlImGui

If you want to learn how to make this project yourself, check out the course linked above!
