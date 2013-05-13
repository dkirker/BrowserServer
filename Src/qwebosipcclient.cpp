/**
 *  Copyright (c) 2012 Hewlett-Packard Development Company, L.P.
 *                2013 Simon Busch <morphis@gravedo.de>
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#include "qwebosipcclient.h"
#include "BrowserPage.h"

#include <QDebug>

#define MESSAGES_INTERNAL_FILE "SysMgrMessagesInternal.h"
#include <PIpcMessageMacros.h>
#include <PIpcChannel.h>

QT_BEGIN_NAMESPACE

QWebOSIpcClient::QWebOSIpcClient(GMainLoop *loop)
    : PIpcClient("sysmgr", "browserserver-client", loop)
{
    qDebug() << __PRETTY_FUNCTION__;
    g_main_loop_run(mainLoop());
    qDebug() << __PRETTY_FUNCTION__ << "2";
}

void QWebOSIpcClient::serverConnected(PIpcChannel* channel)
{
    qDebug() << __PRETTY_FUNCTION__ << "IPC Server connected";
    g_main_loop_quit(mainLoop());
    setChannel(channel);
}

void QWebOSIpcClient::serverDisconnected()
{
    setChannel(0);
}

void QWebOSIpcClient::onMessageReceived(const PIpcMessage& msg)
{
    /*BrowserPage *page = 0;

    if (!(page = pageFromId(msg.routing_id())))
        return;

    bool msgIsOk;
    IPC_BEGIN_MESSAGE_MAP(QWebOSWindow, msg, msgIsOk)
        IPC_MESSAGE_FORWARD(View_Focus, window, QWebOSWindow::handleFocus)
        IPC_MESSAGE_FORWARD(View_Resize, window, QWebOSWindow::handleResize)
        IPC_MESSAGE_FORWARD(View_FullScreenEnabled, window, QWebOSWindow::handleFullScreenEnabled)
        IPC_MESSAGE_FORWARD(View_FullScreenDisabled, window, QWebOSWindow::handleFullScreenDisabled)
        IPC_MESSAGE_FORWARD(View_Pause, window, QWebOSWindow::handlePause)
        IPC_MESSAGE_FORWARD(View_Resume, window, QWebOSWindow::handleResume)
        IPC_MESSAGE_FORWARD(View_InputEvent, window, QWebOSWindow::handleInputEvent)
        IPC_MESSAGE_FORWARD(View_TouchEvent, window, QWebOSWindow::handleTouchEvent)
        IPC_MESSAGE_FORWARD(View_KeyEvent, window, QWebOSWindow::handleKeyEvent)
    IPC_END_MESSAGE_MAP()*/
}

void QWebOSIpcClient::onDisconnected()
{
}

BrowserPage* QWebOSIpcClient::pageFromId(const char* id)
{
    return m_pageMap.value(id, 0);
}

void QWebOSIpcClient::addPage(BrowserPage* page)
{
    m_pageMap[page->getIdentifier()] = page;
}

QT_END_NAMESPACE
