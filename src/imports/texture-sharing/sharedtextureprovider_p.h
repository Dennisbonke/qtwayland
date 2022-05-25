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

#ifndef SHAREDTEXTUREPROVIDER_H
#define SHAREDTEXTUREPROVIDER_H

#include <QOpenGLFunctions>
#include <QQuickImageProvider>
#include <QtQuick/QSGTexture>
#include <QScopedPointer>
#include <QHash>

#include <QtWaylandClient/private/qwaylandserverbufferintegration_p.h>

QT_BEGIN_NAMESPACE

class TextureSharingExtension;

class SharedTextureRegistry : public QObject
{
    Q_OBJECT
public:
    SharedTextureRegistry();
    ~SharedTextureRegistry() override;

    const QtWaylandClient::QWaylandServerBuffer *bufferForId(const QString &id) const;
    void requestBuffer(const QString &id);
    void abandonBuffer(const QString &id);

    static bool preinitialize();

public slots:
    void receiveBuffer(QtWaylandClient::QWaylandServerBuffer *buffer, const QString &id);

signals:
    void replyReceived(const QString &id);

private slots:
    void handleExtensionActive();

private:
    TextureSharingExtension *m_extension = nullptr;
    QHash<QString, QtWaylandClient::QWaylandServerBuffer *> m_buffers;
    QStringList m_pendingBuffers;
};

class SharedTextureProvider : public QQuickAsyncImageProvider
{
public:
    SharedTextureProvider();
    ~SharedTextureProvider() override;

    QQuickImageResponse *requestImageResponse(const QString &id, const QSize &requestedSize) override;

private:
    SharedTextureRegistry *m_registry = nullptr;
    bool m_sharingAvailable = false;
};

QT_END_NAMESPACE

#endif // SHAREDTEXTUREPROVIDER_H
