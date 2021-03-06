// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py. DO NOT MODIFY!

#include "config.h"
#include "V8OESVertexArrayObject.h"

#include "bindings/core/v8/V8WebGLVertexArrayObjectOES.h"
#include "bindings/v8/ExceptionState.h"
#include "bindings/v8/V8DOMConfiguration.h"
#include "bindings/v8/V8HiddenValue.h"
#include "bindings/v8/V8ObjectConstructor.h"
#include "core/dom/ContextFeatures.h"
#include "core/dom/Document.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "platform/TraceEvent.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace WebCore {

static void initializeScriptWrappableForInterface(OESVertexArrayObject* object)
{
    if (ScriptWrappable::wrapperCanBeStoredInObject(object))
        ScriptWrappable::fromObject(object)->setTypeInfo(&V8OESVertexArrayObject::wrapperTypeInfo);
    else
        ASSERT_NOT_REACHED();
}

} // namespace WebCore

void webCoreInitializeScriptWrappableForInterface(WebCore::OESVertexArrayObject* object)
{
    WebCore::initializeScriptWrappableForInterface(object);
}

namespace WebCore {
const WrapperTypeInfo V8OESVertexArrayObject::wrapperTypeInfo = { gin::kEmbedderBlink, V8OESVertexArrayObject::domTemplate, V8OESVertexArrayObject::derefObject, 0, 0, 0, V8OESVertexArrayObject::installPerContextEnabledMethods, 0, WrapperTypeObjectPrototype, RefCountedObject };

namespace OESVertexArrayObjectV8Internal {

template <typename T> void V8_USE(T) { }

static void createVertexArrayOESMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    OESVertexArrayObject* impl = V8OESVertexArrayObject::toNative(info.Holder());
    v8SetReturnValue(info, impl->createVertexArrayOES());
}

static void createVertexArrayOESMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    OESVertexArrayObjectV8Internal::createVertexArrayOESMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void deleteVertexArrayOESMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    OESVertexArrayObject* impl = V8OESVertexArrayObject::toNative(info.Holder());
    WebGLVertexArrayObjectOES* arrayObject;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        if (info.Length() > 0 && !isUndefinedOrNull(info[0]) && !V8WebGLVertexArrayObjectOES::hasInstance(info[0], info.GetIsolate())) {
            throwTypeError(ExceptionMessages::failedToExecute("deleteVertexArrayOES", "OESVertexArrayObject", "parameter 1 is not of type 'WebGLVertexArrayObjectOES'."), info.GetIsolate());
            return;
        }
        TONATIVE_VOID_INTERNAL(arrayObject, V8WebGLVertexArrayObjectOES::toNativeWithTypeCheck(info.GetIsolate(), info[0]));
    }
    impl->deleteVertexArrayOES(arrayObject);
}

static void deleteVertexArrayOESMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    OESVertexArrayObjectV8Internal::deleteVertexArrayOESMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void isVertexArrayOESMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    OESVertexArrayObject* impl = V8OESVertexArrayObject::toNative(info.Holder());
    WebGLVertexArrayObjectOES* arrayObject;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        if (info.Length() > 0 && !isUndefinedOrNull(info[0]) && !V8WebGLVertexArrayObjectOES::hasInstance(info[0], info.GetIsolate())) {
            throwTypeError(ExceptionMessages::failedToExecute("isVertexArrayOES", "OESVertexArrayObject", "parameter 1 is not of type 'WebGLVertexArrayObjectOES'."), info.GetIsolate());
            return;
        }
        TONATIVE_VOID_INTERNAL(arrayObject, V8WebGLVertexArrayObjectOES::toNativeWithTypeCheck(info.GetIsolate(), info[0]));
    }
    v8SetReturnValueBool(info, impl->isVertexArrayOES(arrayObject));
}

static void isVertexArrayOESMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    OESVertexArrayObjectV8Internal::isVertexArrayOESMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

static void bindVertexArrayOESMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    OESVertexArrayObject* impl = V8OESVertexArrayObject::toNative(info.Holder());
    WebGLVertexArrayObjectOES* arrayObject;
    {
        v8::TryCatch block;
        V8RethrowTryCatchScope rethrow(block);
        if (info.Length() > 0 && !isUndefinedOrNull(info[0]) && !V8WebGLVertexArrayObjectOES::hasInstance(info[0], info.GetIsolate())) {
            throwTypeError(ExceptionMessages::failedToExecute("bindVertexArrayOES", "OESVertexArrayObject", "parameter 1 is not of type 'WebGLVertexArrayObjectOES'."), info.GetIsolate());
            return;
        }
        TONATIVE_VOID_INTERNAL(arrayObject, V8WebGLVertexArrayObjectOES::toNativeWithTypeCheck(info.GetIsolate(), info[0]));
    }
    impl->bindVertexArrayOES(arrayObject);
}

static void bindVertexArrayOESMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    OESVertexArrayObjectV8Internal::bindVertexArrayOESMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "V8Execution");
}

} // namespace OESVertexArrayObjectV8Internal

static const V8DOMConfiguration::MethodConfiguration V8OESVertexArrayObjectMethods[] = {
    {"createVertexArrayOES", OESVertexArrayObjectV8Internal::createVertexArrayOESMethodCallback, 0, 0},
    {"deleteVertexArrayOES", OESVertexArrayObjectV8Internal::deleteVertexArrayOESMethodCallback, 0, 0},
    {"isVertexArrayOES", OESVertexArrayObjectV8Internal::isVertexArrayOESMethodCallback, 0, 0},
    {"bindVertexArrayOES", OESVertexArrayObjectV8Internal::bindVertexArrayOESMethodCallback, 0, 0},
};

static void configureV8OESVertexArrayObjectTemplate(v8::Handle<v8::FunctionTemplate> functionTemplate, v8::Isolate* isolate)
{
    functionTemplate->ReadOnlyPrototype();

    v8::Local<v8::Signature> defaultSignature;
    defaultSignature = V8DOMConfiguration::installDOMClassTemplate(functionTemplate, "OESVertexArrayObject", v8::Local<v8::FunctionTemplate>(), V8OESVertexArrayObject::internalFieldCount,
        0, 0,
        0, 0,
        V8OESVertexArrayObjectMethods, WTF_ARRAY_LENGTH(V8OESVertexArrayObjectMethods),
        isolate);
    v8::Local<v8::ObjectTemplate> instanceTemplate ALLOW_UNUSED = functionTemplate->InstanceTemplate();
    v8::Local<v8::ObjectTemplate> prototypeTemplate ALLOW_UNUSED = functionTemplate->PrototypeTemplate();
    static const V8DOMConfiguration::ConstantConfiguration V8OESVertexArrayObjectConstants[] = {
        {"VERTEX_ARRAY_BINDING_OES", 0x85B5},
    };
    V8DOMConfiguration::installConstants(functionTemplate, prototypeTemplate, V8OESVertexArrayObjectConstants, WTF_ARRAY_LENGTH(V8OESVertexArrayObjectConstants), isolate);

    // Custom toString template
    functionTemplate->Set(v8AtomicString(isolate, "toString"), V8PerIsolateData::from(isolate)->toStringTemplate());
}

v8::Handle<v8::FunctionTemplate> V8OESVertexArrayObject::domTemplate(v8::Isolate* isolate)
{
    return V8DOMConfiguration::domClassTemplate(isolate, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), configureV8OESVertexArrayObjectTemplate);
}

bool V8OESVertexArrayObject::hasInstance(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Handle<v8::Object> V8OESVertexArrayObject::findInstanceInPrototypeChain(v8::Handle<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

OESVertexArrayObject* V8OESVertexArrayObject::toNativeWithTypeCheck(v8::Isolate* isolate, v8::Handle<v8::Value> value)
{
    return hasInstance(value, isolate) ? fromInternalPointer(v8::Handle<v8::Object>::Cast(value)->GetAlignedPointerFromInternalField(v8DOMWrapperObjectIndex)) : 0;
}

v8::Handle<v8::Object> wrap(OESVertexArrayObject* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8OESVertexArrayObject>(impl, isolate));
    return V8OESVertexArrayObject::createWrapper(impl, creationContext, isolate);
}

v8::Handle<v8::Object> V8OESVertexArrayObject::createWrapper(PassRefPtr<OESVertexArrayObject> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8OESVertexArrayObject>(impl.get(), isolate));
    if (ScriptWrappable::wrapperCanBeStoredInObject(impl.get())) {
        const WrapperTypeInfo* actualInfo = ScriptWrappable::fromObject(impl.get())->typeInfo();
        // Might be a XXXConstructor::wrapperTypeInfo instead of an XXX::wrapperTypeInfo. These will both have
        // the same object de-ref functions, though, so use that as the basis of the check.
        RELEASE_ASSERT_WITH_SECURITY_IMPLICATION(actualInfo->derefObjectFunction == wrapperTypeInfo.derefObjectFunction);
    }

    v8::Handle<v8::Object> wrapper = V8DOMWrapper::createWrapper(creationContext, &wrapperTypeInfo, toInternalPointer(impl.get()), isolate);
    if (UNLIKELY(wrapper.IsEmpty()))
        return wrapper;

    installPerContextEnabledProperties(wrapper, impl.get(), isolate);
    V8DOMWrapper::associateObjectWithWrapper<V8OESVertexArrayObject>(impl, &wrapperTypeInfo, wrapper, isolate, WrapperConfiguration::Independent);
    return wrapper;
}

void V8OESVertexArrayObject::derefObject(void* object)
{
    fromInternalPointer(object)->deref();
}

template<>
v8::Handle<v8::Value> toV8NoInline(OESVertexArrayObject* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    return toV8(impl, creationContext, isolate);
}

} // namespace WebCore
