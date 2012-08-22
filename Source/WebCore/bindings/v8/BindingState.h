/*
 * Copyright (C) 2009 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef BindingState_h
#define BindingState_h

#include <wtf/text/WTFString.h>

namespace WebCore {

class DOMWindow;
class Document;
class Frame;

class BindingState {
public:
    // Currently, V8 uses a singleton for it's state.
    // FIXME: Should we use v8::Isolate as the BindingState?
    static BindingState* instance();
};

DOMWindow* activeDOMWindow(BindingState*);
DOMWindow* firstDOMWindow(BindingState*);

Frame* activeFrame(BindingState*);
Frame* firstFrame(BindingState*);

// FIXME: When implementing this function for JSC, we need to understand if there
// are any subtle differences between the currentFrame and the lexicalGlobalObject.
Frame* currentFrame(BindingState*);
Document* currentDocument(BindingState*);

// FIXME: This function is redundant with the copy in JSDOMBinding.cpp.
void printErrorMessageForFrame(Frame*, const String& message);

}

#endif
