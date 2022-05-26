//
// Created by Aubrey on 3/23/2022.
//

#ifndef MESSING_WITH_IMGUI_BACKEND_HPP
#define MESSING_WITH_IMGUI_BACKEND_HPP

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#include <GLFW/glfw3.h> // Will drag system OpenGL headers

// [Win32] Our example includes a copy of glfw3.lib pre-compiled with VS2010 to maximize ease of testing and compatibility with old VS compilers.
// To link with VS2010-era libraries, VS2015+ requires linking with legacy_stdio_definitions.lib, which we do using this pragma.
// Your own project should not be affected, as you are likely to link with a newer binary of GLFW that is adequate for your version of Visual Studio.
#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

// ---------- Theme Stuff Here Later ----------

//ImGuiStyle* style = &ImGui::GetStyle();
//
//void aubee() {
//    ImVec4* colors = style->Colors;
//
//    style -> WindowRounding = 0.0f;
//    style -> Colors[ImGuiCol_WindowBg].w = 1.0f;
//}

#endif //MESSING_WITH_IMGUI_BACKEND_HPP
