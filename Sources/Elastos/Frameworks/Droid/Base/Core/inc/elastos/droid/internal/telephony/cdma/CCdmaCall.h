#ifndef __ELASTOS_DROID_INTERNAL_TELEPHONY_CDMA_CCDMACALL_H__
#define __ELASTOS_DROID_INTERNAL_TELEPHONY_CDMA_CCDMACALL_H__

#include "_Elastos_Droid_Internal_Telephony_Cdma_CCdmaCall.h"
#include "elastos/droid/internal/telephony/cdma/CdmaCall.h"

namespace Elastos {
namespace Droid {
namespace Internal {
namespace Telephony {
namespace Cdma {

CarClass(CCdmaCall)
    , public CdmaCall
{
public:
    CAR_OBJECT_DECL()
};

} // namespace Cdma
} // namespace Telephony
} // namespace Internal
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_INTERNAL_TELEPHONY_CDMA_CCDMACALL_H__