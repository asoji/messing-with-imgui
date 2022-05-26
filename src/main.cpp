//
// Created by Aubrey on 3/27/2022.
//

#include "main.hpp"

#include "imgui.h"

namespace MessingWithImGui {
    void MainWindow() {
        ImGui::Begin("Test window");
        ImGui::Button("hello i am a test button");
        ImGui::End();

        ImGui::ShowDemoWindow();
    }
}