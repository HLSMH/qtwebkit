/*
 * Copyright (C) 2012 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef WebCompositorIOSurfaceQuad_h
#define WebCompositorIOSurfaceQuad_h

#include "WebCompositorQuad.h"
#include "WebSize.h"
#include <wtf/PassOwnPtr.h>

namespace WebKit {

#pragma pack(push, 4)

class WebCompositorIOSurfaceQuad : public WebCompositorQuad {
public:
#if WEBKIT_IMPLEMENTATION
    enum Orientation {
      Flipped,
      Unflipped
    };

    static PassOwnPtr<WebCompositorIOSurfaceQuad> create(const WebCompositorSharedQuadState*, const WebCore::IntRect&, const WebCore::IntSize& ioSurfaceSize, unsigned ioSurfaceTextureId, Orientation);

    WebCore::IntSize ioSurfaceSize() const { return m_ioSurfaceSize; }
    unsigned ioSurfaceTextureId() const { return m_ioSurfaceTextureId; }
    Orientation orientation() const { return m_orientation; }
#endif

    static const WebCompositorIOSurfaceQuad* materialCast(const WebCompositorQuad*);
private:
#if WEBKIT_IMPLEMENTATION
    WebCompositorIOSurfaceQuad(const WebCompositorSharedQuadState*, const WebCore::IntRect&, const WebCore::IntSize& ioSurfaceSize, unsigned ioSurfaceTextureId, Orientation);
#endif

    WebSize m_ioSurfaceSize;
    unsigned m_ioSurfaceTextureId;
    Orientation m_orientation;
};

#pragma pack(pop)

}

#endif