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
******************************************************************************/

#include <QtWaylandCompositor/private/qwlclientbufferintegrationplugin_p.h>
#include "xcompositeeglintegration.h"

QT_BEGIN_NAMESPACE

class QWaylandXCompositeEglClientBufferIntegrationPlugin : public QtWayland::ClientBufferIntegrationPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QtWaylandClientBufferIntegrationFactoryInterface_iid FILE "xcomposite-egl.json")
public:
    QtWayland::ClientBufferIntegration *create(const QString&, const QStringList&) override;
};

QtWayland::ClientBufferIntegration *QWaylandXCompositeEglClientBufferIntegrationPlugin::create(const QString& system, const QStringList& paramList)
{
    Q_UNUSED(paramList);
    Q_UNUSED(system);
    return new XCompositeEglClientBufferIntegration();
}

QT_END_NAMESPACE

#include "main.moc"
