/****************************************************************************
**
** Copyright (C) 2017 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtWaylandCompositor module of the Qt Toolkit.
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
******************************************************************************/

#ifndef QWAYLANDINPUTMETHODCONTROL_P_H
#define QWAYLANDINPUTMETHODCONTROL_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtWaylandCompositor/qtwaylandcompositorglobal.h>
#include <QtWaylandCompositor/qwaylandinputmethodcontrol.h>

#include <QtCore/private/qobject_p.h>

QT_BEGIN_NAMESPACE

class QWaylandCompositor;
class QWaylandSeat;
class QWaylandSurface;
class QWaylandTextInput;
class QWaylandQtTextInputMethod;

class Q_WAYLAND_COMPOSITOR_EXPORT QWaylandInputMethodControlPrivate : public QObjectPrivate
{
    Q_DECLARE_PUBLIC(QWaylandInputMethodControl)

public:
    explicit QWaylandInputMethodControlPrivate(QWaylandSurface *surface);

    QWaylandTextInput *textInput() const;
    QWaylandQtTextInputMethod *textInputMethod() const;

    QWaylandCompositor *compositor = nullptr;
    QWaylandSeat *seat = nullptr;
    QWaylandSurface *surface = nullptr;
    bool enabled = false;
};

QT_END_NAMESPACE

#endif // QWAYLANDINPUTMETHODCONTROL_P_H
