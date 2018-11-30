//
//  app.cpp
//  ddui
//
//  Created by Bartholomew Joyce on 30/08/2018.
//  Copyright © 2018 Bartholomew Joyce All rights reserved.
//

#include "app.hpp"
#include "core.hpp"
#include <QtGui>
#include "MainWindow.hpp"

namespace ddui {

static QGuiApplication* app;
static MainWindow* window;

bool app_init(
    int argc, const char** argv,
    int window_width, int window_height,
    const char* title,
    std::function<void()> update_proc
) {
    app = new QGuiApplication(argc, const_cast<char**>(argv));
    window = new MainWindow(window_width, window_height, title, std::move(update_proc));
    return true;
}

void app_run() {
    window->show();
    app->exec();
    // while (!glfwWindowShouldClose(window)) {
    //     ddui::update_window(window);
    //     if (ddui::animation::is_animating()) {
    //         glfwPollEvents();
    //     } else {
    //         glfwWaitEvents();
    //     }
    // }
}

}
