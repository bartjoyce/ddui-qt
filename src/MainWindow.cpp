//
//  MainWindow.cpp
//  ddui-qt
//
//  Created by Bartholomew Joyce on 30/11/2018.
//  Copyright © 2018 Bartholomew Joyce All rights reserved.
//

#include "MainWindow.hpp"
#include <ddui/core>

MainWindow::MainWindow(
    int window_width,
    int window_height,
    const char* title,
    std::function<void()> update_proc,
    QWindow* parent
) : QRasterWindow(parent),
    m_backing_store(new QBackingStore(this)),
    m_update_proc(std::move(update_proc)) {
    
    resize(window_width, window_height);
    setTitle(title);

    ddui::set_post_empty_message_proc([this]() {
        this->renderLater();
    });

}

void MainWindow::render(QPainter* painter) {
    ddui::update(painter, width(), height(), m_update_proc);
}

void MainWindow::renderLater() {
    requestUpdate();
}

void MainWindow::renderNow() {
    if (!isExposed()) {
        return;
    }

    QRect rect(0, 0, width(), height());
    m_backing_store->beginPaint(rect);

    QPaintDevice *device = m_backing_store->paintDevice();
    QPainter painter(device);
    render(&painter);
    painter.end();

    m_backing_store->endPaint();
    m_backing_store->flush(rect);

    if (ddui::animation::is_animating()) {
        renderLater();
    }
}

bool MainWindow::event(QEvent* event) {
    if (event->type() == QEvent::UpdateRequest) {
        renderNow();
        return true;
    }
    return QWindow::event(event);
}

void MainWindow::resizeEvent(QResizeEvent* event) {
    m_backing_store->resize(event->size());
    if (isExposed()) {
        renderNow();
    }
}

void MainWindow::exposeEvent(QExposeEvent* event) {
    if (isExposed()) {
        renderNow();
    }
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    // Keyboard::get()->handleKeyPressEvent(event);
}

void MainWindow::keyReleaseEvent(QKeyEvent* event) {
    // Keyboard::get()->handleKeyReleaseEvent(event);
}
