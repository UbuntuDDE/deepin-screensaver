/*
 * Copyright (C) 2017 ~ 2019 Deepin Technology Co., Ltd.
 *
 * Author:     zccrs <zccrs@live.com>
 *
 * Maintainer: zccrs <zhangjide@deepin.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SCREENSAVERWINDOW_H
#define SCREENSAVERWINDOW_H

#include <QWindow>
#include <QEvent>

QT_BEGIN_NAMESPACE
class QScreen;
QT_END_NAMESPACE

class ScreenSaverView;
class ScreenSaverWindow : public QObject
{
    Q_OBJECT

public:
    explicit ScreenSaverWindow(QObject *parent = nullptr);
    ~ScreenSaverWindow();

    bool start(const QString &filePath);
    void stop();

    WId winId() const;
    Qt::WindowFlags flags() const;
    void setFlags(Qt::WindowFlags flags, bool bypassWindowManager);

    QWindow::Visibility visibility() const;
    QScreen *screen() const;

public slots:
    void setGeometry(const QRect &rect);
    void setScreen(QScreen *screen);
    void show();
    void hide();
    void close();

signals:
    void inputEvent(QEvent::Type type);

private:
    ScreenSaverView *m_view;
};

#endif // SCREENSAVERWINDOW_H
