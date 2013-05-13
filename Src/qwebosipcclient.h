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

#ifndef QWEBOSIPCCLIENT_H
#define QWEBOSIPCCLIENT_H

#include <QHash>
#include <PIpcClient.h>
#include <PIpcChannelListener.h>

class BrowserPage;

class QWebOSIpcClient : public PIpcClient,
                        public PIpcChannelListener
{
public:
    QWebOSIpcClient(GMainLoop *loop);

    void addPage(BrowserPage* page);

private:
    virtual void serverConnected(PIpcChannel* channel);
    virtual void serverDisconnected();

    virtual void onMessageReceived(const PIpcMessage& msg);
    virtual void onDisconnected();

    BrowserPage* pageFromId(const char* id);

private:
    QHash<const char*, BrowserPage*> m_pageMap;
};

#endif // QWEBOSIPCCLIENT_H
