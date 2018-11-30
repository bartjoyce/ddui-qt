//
//  MainWindow.hpp
//  ddui-qt
//
//  Created by Bartholomew Joyce on 30/11/2018.
//  Copyright © 2018 Bartholomew Joyce All rights reserved.
//

#ifndef MainWindow_hpp
#define MainWindow_hpp

#include <QtGui>
#include <functional>

class MainWindow : public QRasterWindow {
    Q_OBJECT

    public:
        explicit MainWindow(
            int window_width,
            int window_height,
            const char* title,
            std::function<void()> update_proc,
            QWindow* parent = 0
        );

        virtual void render(QPainter *painter);

    public Q_SLOTS:
        void renderLater();
        void renderNow();

    protected:
        bool event(QEvent *event) override;

        void resizeEvent(QResizeEvent *event) override;
        void exposeEvent(QExposeEvent *event) override;
  
        void keyPressEvent(QKeyEvent* event) override;
        void keyReleaseEvent(QKeyEvent* event) override;

    private:
        QBackingStore *m_backing_store;
        std::function<void()> m_update_proc;

};

#endif
