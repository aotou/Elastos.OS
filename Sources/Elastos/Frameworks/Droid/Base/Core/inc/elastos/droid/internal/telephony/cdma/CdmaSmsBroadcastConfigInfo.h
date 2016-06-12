#ifndef __ELASTOS_DROID_INTERNAL_TELEPHONY_CDMA_CDMASMSBROADCASTCONFIGINFO_H__
#define __ELASTOS_DROID_INTERNAL_TELEPHONY_CDMA_CDMASMSBROADCASTCONFIGINFO_H__

#include "elastos/droid/ext/frameworkext.h"
#include "elastos/core/Object.h"

namespace Elastos {
namespace Droid {
namespace Internal {
namespace Telephony {
namespace Cdma {

/**
  * CdmaSmsBroadcastConfigInfo defines one configuration of Cdma Broadcast
  * Message to be received by the ME
  *
  * serviceCategory defines a Broadcast message identifier
  * whose value is 0x0000 - 0xFFFF as defined in C.R1001G 9.3.1 and 9.3.2.
  * All other values can be treated as empty message ID.
  *
  * language defines a language code of Broadcast Message
  * whose value is 0x00 - 0x07 as defined in C.R1001G 9.2.
  * All other values can be treated as empty language code.
  *
  * selected false means message types specified in serviceCategory
  * are not accepted, while true means accepted.
  *
  */
class CdmaSmsBroadcastConfigInfo
    : public Object
    , public ICdmaSmsBroadcastConfigInfo
{
public:
    CAR_INTERFACE_DECL();

    /**
      * Initialize the object from rssi and cid.
      */
    CdmaSmsBroadcastConfigInfo(
        /* [in] */ Int32 fromServiceCategory,
        /* [in] */ Int32 toServiceCategory,
        /* [in] */ Int32 language,
        /* [in] */ Boolean selected);

    /**
      * @return the mFromServiceCategory
      */
    virtual CARAPI GetFromServiceCategory(
        /* [out] */ Int32* result);

    /**
      * @return the mToServiceCategory
      */
    virtual CARAPI GetToServiceCategory(
        /* [out] */ Int32* result);

    /**
      * @return the mLanguage
      */
    virtual CARAPI GetLanguage(
        /* [out] */ Int32* result);

    /**
      * @return the selected
      */
    virtual CARAPI IsSelected(
        /* [out] */ Boolean* result);

    // @Override
    CARAPI ToString(
        /* [out] */ String* result);

private:
    Int32 mFromServiceCategory;
    Int32 mToServiceCategory;
    Int32 mLanguage;
    Boolean mSelected;
};

} // namespace Cdma
} // namespace Telephony
} // namespace Internal
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_INTERNAL_TELEPHONY_CDMA_CDMASMSBROADCASTCONFIGINFO_H__