/****************************************************************************
**
** Copyright (C) 2018 Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
** Contact: http://www.qt-project.org/legal
**
** This file is part of the plugins of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:COMM$
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** $QT_END_LICENSE$
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
**
******************************************************************************/

#include "qwaylandfullscreenshellv1integration.h"
#include "qwaylandfullscreenshellv1surface.h"

QT_BEGIN_NAMESPACE

namespace QtWaylandClient {

bool QWaylandFullScreenShellV1Integration::initialize(QWaylandDisplay *display)
{
    for (const QWaylandDisplay::RegistryGlobal &global : display->globals()) {
        if (global.interface == QLatin1String("zwp_fullscreen_shell_v1") && !m_shell) {
            m_shell.reset(new QtWayland::zwp_fullscreen_shell_v1(display->wl_registry(), global.id, global.version));
            break;
        }
    }

    if (!m_shell) {
        qCDebug(lcQpaWayland) << "Couldn't find global zwp_fullscreen_shell_v1 for fullscreen-shell";
        return false;
    }

    return QWaylandShellIntegration::initialize(display);
}

QWaylandShellSurface *QWaylandFullScreenShellV1Integration::createShellSurface(QWaylandWindow *window)
{
    return new QWaylandFullScreenShellV1Surface(m_shell.data(), window);
}

} // namespace QtWaylandClient

QT_END_NAMESPACE
