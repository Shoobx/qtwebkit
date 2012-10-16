/*
 * Copyright (C) 2012 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "ScrollingStateNode.h"

#include "ScrollingStateTree.h"

#if ENABLE(THREADED_SCROLLING)

namespace WebCore {

PlatformLayer* ScrollingStateNode::platformScrollLayer() const
{
    return m_platformScrollLayer.get();
}

void ScrollingStateNode::setScrollLayer(PlatformLayer* platformLayer)
{
    m_platformScrollLayer = platformLayer;
}

void ScrollingStateNode::setScrollLayer(const GraphicsLayer* graphicsLayer)
{
    PlatformLayer* platformScrollLayer = graphicsLayer ? graphicsLayer->platformLayer() : nil;

    if (m_platformScrollLayer == platformScrollLayer)
        return;

    m_platformScrollLayer = platformScrollLayer;
    m_scrollLayerDidChange = true;
    m_scrollingStateTree->setHasChangedProperties(true);
}

} // namespace WebCore

#endif // ENABLE(THREADED_SCROLLING)