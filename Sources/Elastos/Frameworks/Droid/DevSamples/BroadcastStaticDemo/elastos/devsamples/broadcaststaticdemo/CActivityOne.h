
#ifndef __Elastos_DevSamples_BroadcastStaticDemo_CActivityOne_H__
#define __Elastos_DevSamples_BroadcastStaticDemo_CActivityOne_H__

#include "_Elastos_DevSamples_BroadcastStaticDemo_CActivityOne.h"
#include <elastos/droid/app/Activity.h>
#include <Elastos.Droid.Content.h>

using Elastos::Droid::App::Activity;
using Elastos::Droid::Content::IBroadcastReceiver;
using Elastos::Droid::View::IViewOnClickListener;

namespace Elastos {
namespace DevSamples {
namespace BroadcastStaticDemo {

CarClass(CActivityOne)
    , public Activity
{
public:
    class MyListener
        : public Object
        , public IViewOnClickListener
    {
    public:
        CAR_INTERFACE_DECL()

        MyListener(
            /* [in] */ CActivityOne* host);

        CARAPI OnClick(
            /* [in] */ IView* v);

    private:
        CActivityOne* mHost;
    };

public:
    CAR_OBJECT_DECL()

    CARAPI constructor();

protected:

    CARAPI OnCreate(
        /* [in] */ IBundle* savedInstanceState);

    CARAPI OnStart();

    CARAPI OnResume();

    CARAPI OnPause();

    CARAPI OnStop();

    CARAPI OnDestroy();

private:
    CARAPI OnActivityResult(
        /* [in] */ Int32 requestCode,
        /* [in] */ Int32 resultCode,
        /* [in] */ IIntent *data);

    CARAPI Register();

    CARAPI Unregister();

    CARAPI Send();
private:
    AutoPtr<IBroadcastReceiver> mReceiverOne;
    AutoPtr<IBroadcastReceiver> mReceiverTwo;
};

} // namespace BroadcastStaticDemo
} // namespace DevSamples
} // namespace Elastos

#endif // __Elastos_DevSamples_BroadcastStaticDemo_CActivityOne_H__