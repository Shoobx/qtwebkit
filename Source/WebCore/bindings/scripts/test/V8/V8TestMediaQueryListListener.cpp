/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.
*/

#include "config.h"
#include "V8TestMediaQueryListListener.h"

#include "BindingState.h"
#include "ContextFeatures.h"
#include "ExceptionCode.h"
#include "MediaQueryListListener.h"
#include "RuntimeEnabledFeatures.h"
#include "V8Binding.h"
#include "V8DOMWrapper.h"
#include "V8IsolatedContext.h"
#include "V8Proxy.h"
#include <wtf/UnusedParam.h>

namespace WebCore {

WrapperTypeInfo V8TestMediaQueryListListener::info = { V8TestMediaQueryListListener::GetTemplate, V8TestMediaQueryListListener::derefObject, 0, 0, 0, WrapperTypeObjectPrototype };

namespace TestMediaQueryListListenerV8Internal {

template <typename T> void V8_USE(T) { }

static v8::Handle<v8::Value> methodCallback(const v8::Arguments& args)
{
    INC_STATS("DOM.TestMediaQueryListListener.method");
    if (args.Length() < 1)
        return throwNotEnoughArgumentsError(args.GetIsolate());
    TestMediaQueryListListener* imp = V8TestMediaQueryListListener::toNative(args.Holder());
    EXCEPTION_BLOCK(RefPtr<MediaQueryListListener>, listener, MediaQueryListListener::create(MAYBE_MISSING_PARAMETER(args, 0, DefaultIsUndefined)));
    imp->method(listener);
    return v8Undefined();
}

} // namespace TestMediaQueryListListenerV8Internal

static const V8DOMConfiguration::BatchedCallback TestMediaQueryListListenerCallbacks[] = {
    {"method", TestMediaQueryListListenerV8Internal::methodCallback},
};

static v8::Persistent<v8::FunctionTemplate> ConfigureV8TestMediaQueryListListenerTemplate(v8::Persistent<v8::FunctionTemplate> desc)
{
    desc->ReadOnlyPrototype();

    v8::Local<v8::Signature> defaultSignature;
    defaultSignature = V8DOMConfiguration::configureTemplate(desc, "TestMediaQueryListListener", v8::Persistent<v8::FunctionTemplate>(), V8TestMediaQueryListListener::internalFieldCount,
        0, 0,
        TestMediaQueryListListenerCallbacks, WTF_ARRAY_LENGTH(TestMediaQueryListListenerCallbacks));
    UNUSED_PARAM(defaultSignature); // In some cases, it will not be used.
    v8::Local<v8::ObjectTemplate> instance = desc->InstanceTemplate();
    v8::Local<v8::ObjectTemplate> proto = desc->PrototypeTemplate();
    UNUSED_PARAM(instance); // In some cases, it will not be used.
    UNUSED_PARAM(proto); // In some cases, it will not be used.
    

    // Custom toString template
    desc->Set(v8::String::NewSymbol("toString"), V8PerIsolateData::current()->toStringTemplate());
    return desc;
}

v8::Persistent<v8::FunctionTemplate> V8TestMediaQueryListListener::GetRawTemplate()
{
    V8PerIsolateData* data = V8PerIsolateData::current();
    V8PerIsolateData::TemplateMap::iterator result = data->rawTemplateMap().find(&info);
    if (result != data->rawTemplateMap().end())
        return result->second;

    v8::HandleScope handleScope;
    v8::Persistent<v8::FunctionTemplate> templ = createRawTemplate();
    data->rawTemplateMap().add(&info, templ);
    return templ;
}

v8::Persistent<v8::FunctionTemplate> V8TestMediaQueryListListener::GetTemplate()
{
    V8PerIsolateData* data = V8PerIsolateData::current();
    V8PerIsolateData::TemplateMap::iterator result = data->templateMap().find(&info);
    if (result != data->templateMap().end())
        return result->second;

    v8::HandleScope handleScope;
    v8::Persistent<v8::FunctionTemplate> templ =
        ConfigureV8TestMediaQueryListListenerTemplate(GetRawTemplate());
    data->templateMap().add(&info, templ);
    return templ;
}

bool V8TestMediaQueryListListener::HasInstance(v8::Handle<v8::Value> value)
{
    return GetRawTemplate()->HasInstance(value);
}


v8::Handle<v8::Object> V8TestMediaQueryListListener::wrapSlow(PassRefPtr<TestMediaQueryListListener> impl, v8::Isolate* isolate)
{
    v8::Handle<v8::Object> wrapper;
    V8Proxy* proxy = 0;
    wrapper = V8DOMWrapper::instantiateV8Object(proxy, &info, impl.get());
    if (UNLIKELY(wrapper.IsEmpty()))
        return wrapper;
    v8::Persistent<v8::Object> wrapperHandle = V8DOMWrapper::setJSWrapperForDOMObject(impl, wrapper, isolate);
    if (!hasDependentLifetime)
        wrapperHandle.MarkIndependent();
    return wrapper;
}

void V8TestMediaQueryListListener::derefObject(void* object)
{
    static_cast<TestMediaQueryListListener*>(object)->deref();
}

} // namespace WebCore
