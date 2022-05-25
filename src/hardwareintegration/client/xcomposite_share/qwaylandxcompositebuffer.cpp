/****************************************************************************
**
** Copyright (C) 2022 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
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

#include "qwaylandxcompositebuffer.h"

#include "wayland-xcomposite-client-protocol.h"

QT_BEGIN_NAMESPACE

namespace QtWaylandClient {

QWaylandXCompositeBuffer::QWaylandXCompositeBuffer(qt_xcomposite *xcomposite, uint32_t window, const QSize &size)
    :mSize(size)
{
    mBuffer = qt_xcomposite_create_buffer(xcomposite,
                                              window,
                                              size.width(),
                                              size.height());
}

QSize QWaylandXCompositeBuffer::size() const
{
    return mSize;
}

}

QT_END_NAMESPACE
