//=========================================================================
// Copyright (C) 2012 The Elastos Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=========================================================================

#include "elastos/droid/webkit/webview/chromium/native/base/SystemMessageHandler.h"
#include "elastos/droid/webkit/webview/chromium/native/base/api/SystemMessageHandler_dec.h"
#include <elastos/utility/logging/Logger.h>
using Elastos::Utility::Logging::Logger;

namespace Elastos {
namespace Droid {
namespace Webkit {
namespace Webview {
namespace Chromium {
namespace Base {

const Int32 SystemMessageHandler::SCHEDULED_WORK;
const Int32 SystemMessageHandler::DELAYED_SCHEDULED_WORK;

SystemMessageHandler::SystemMessageHandler(
    /* [in] */ Int64 messagePumpDelegateNative)
    : mMessagePumpDelegateNative(messagePumpDelegateNative)
    , mDelayedScheduledTimeTicks(0)
{
}

//@Override
ECode SystemMessageHandler::HandleMessage(
    /* [in] */ IMessage* msg)
{
    VALIDATE_NOT_NULL(msg);
    Int32 what;
    msg->GetWhat(&what);
    if (what == DELAYED_SCHEDULED_WORK) {
        mDelayedScheduledTimeTicks = 0;
    }
    NativeDoRunLoopOnce(mMessagePumpDelegateNative, mDelayedScheduledTimeTicks);

    return NOERROR;
}

//@SuppressWarnings("unused")
//@CalledByNative
void SystemMessageHandler::ScheduleWork()
{
    Boolean res;
    SendEmptyMessage(SCHEDULED_WORK, &res);
}

//@SuppressWarnings("unused")
//@CalledByNative
void SystemMessageHandler::ScheduleDelayedWork(
    /* [in] */ Int64 delayedTimeTicks,
    /* [in] */ Int64 millis)
{
    if (mDelayedScheduledTimeTicks != 0) {
        RemoveMessages(DELAYED_SCHEDULED_WORK);
    }
    mDelayedScheduledTimeTicks = delayedTimeTicks;
    Boolean res;
    SendEmptyMessageDelayed(DELAYED_SCHEDULED_WORK, millis, &res);
}

//@SuppressWarnings("unused")
//@CalledByNative
void SystemMessageHandler::RemoveAllPendingMessages()
{
    RemoveMessages(SCHEDULED_WORK);
    RemoveMessages(DELAYED_SCHEDULED_WORK);
}

//@CalledByNative
AutoPtr<IInterface> SystemMessageHandler::Create(
    /* [in] */ Int64 messagePumpDelegateNative)
{
    AutoPtr<SystemMessageHandler> handler = new SystemMessageHandler(messagePumpDelegateNative);
    return TO_IINTERFACE(handler);
}

void SystemMessageHandler::NativeDoRunLoopOnce(
    /* [in] */ Int64 messagePumpDelegateNative,
    /* [in] */ Int64 delayedScheduledTimeTicks)
{
    Elastos_SystemMessageHandler_nativeDoRunLoopOnce(TO_IINTERFACE(this), messagePumpDelegateNative, delayedScheduledTimeTicks);
}

void SystemMessageHandler::ScheduleWork(
    /* [in] */ IInterface* obj)
{
    AutoPtr<SystemMessageHandler> mObj = (SystemMessageHandler*)(IObject::Probe(obj));
    if (NULL == mObj)
    {
        Logger::E("SystemMessageHandler", "SystemMessageHandler::ScheduleWork, mObj is NULL");
        return;
    }
    mObj->ScheduleWork();
}

void SystemMessageHandler::ScheduleDelayedWork(
    /* [in] */ IInterface* obj,
    /* [in] */ Int64 delayedTimeTicks,
    /* [in] */ Int64 millis)
{
    AutoPtr<SystemMessageHandler> mObj = (SystemMessageHandler*)(IObject::Probe(obj));
    if (NULL == mObj)
    {
        Logger::E("SystemMessageHandler", "SystemMessageHandler::ScheduleDelayedWork, mObj is NULL");
        return;
    }
    mObj->ScheduleDelayedWork(delayedTimeTicks, millis);
}

void SystemMessageHandler::RemoveAllPendingMessages(
    /* [in] */ IInterface* obj)
{
    AutoPtr<SystemMessageHandler> mObj = (SystemMessageHandler*)(IObject::Probe(obj));
    if (NULL == mObj)
    {
        Logger::E("SystemMessageHandler", "SystemMessageHandler::RemoveAllPendingMessages, mObj is NULL");
        return;
    }
    mObj->RemoveAllPendingMessages();
}

} // namespace Base
} // namespace Chromium
} // namespace Webview
} // namespace Webkit
} // namespace Droid
} // namespace Elastos
