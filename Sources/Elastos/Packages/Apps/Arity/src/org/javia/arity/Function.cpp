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

#include "org/javia/arity/Function.h"
#include "org/javia/arity/CDerivative.h"
#include "org/javia/arity/CComplex.h"
#include <elastos/core/Math.h>
#include <elastos/utility/logging/Slogger.h>

using Elastos::Utility::Logging::Slogger;
using Org::Javia::Arity::EIID_IFunction;

namespace Org {
namespace Javia {
namespace Arity {

CAR_INTERFACE_IMPL(Function, Object, IFunction)

ECode Function::GetDerivative(
    /* [out] */ IFunction** func)
{
    VALIDATE_NOT_NULL(func)
    if (mCachedDerivate == NULL) {
        CDerivative::New((IFunction*)this, (IFunction**)&mCachedDerivate);
    }
    *func = mCachedDerivate;
    REFCOUNT_ADD(*func)
    return NOERROR;
}

void Function::SetDerivative(
    /* [in] */ IFunction* deriv)
{
    mCachedDerivate = deriv;
}

ECode Function::Eval(
    /* [out] */ Double* result)
{
    VALIDATE_NOT_NULL(result)
    *result = 0;
    return E_ARITY_EXCEPTION;
}

ECode Function::Eval(
    /* [in] */ Double x,
    /* [out] */ Double* result)
{
    VALIDATE_NOT_NULL(result)
    *result = 0;
    return E_ARITY_EXCEPTION;
}

ECode Function::Eval(
    /* [in] */ Double x,
    /* [in] */ Double y,
    /* [out] */ Double* result)
{
    VALIDATE_NOT_NULL(result)
    *result = 0;
    return E_ARITY_EXCEPTION;
}

ECode Function::Eval(
    /* [in] */ ArrayOf<Double>* args,
    /* [out] */ Double* result)
{
    VALIDATE_NOT_NULL(result)
    *result = 0;
    switch (args->GetLength()) {
        case 0:
            return Eval(result);
        case 1:
            return Eval((*args)[0], result);
        case 2:
            return Eval((*args)[0], (*args)[1], result);
    }
    return E_ARITY_EXCEPTION;
}

ECode Function::EvalComplex(
    /* [out] */ IComplex** complex)
{
    VALIDATE_NOT_NULL(complex)
    *complex = NULL;
    FAIL_RETURN(CheckArity(0))
    Double result;
    Eval(&result);
    return CComplex::New(result, 0, complex);
}

ECode Function::Eval(
    /* [in] */ IComplex* x,
    /* [out] */ IComplex** complex)
{
    VALIDATE_NOT_NULL(complex)
    *complex = NULL;
    FAIL_RETURN(CheckArity(1))
    AutoPtr<CComplex> xObj = (CComplex*)x;
    Double result = Elastos::Core::Math::DOUBLE_NAN;
    if (xObj->mIm == 0) {
        Eval(xObj->mRe, &result);
    }
    return CComplex::New(result, 0, complex);
}

ECode Function::Eval(
    /* [in] */ IComplex* x,
    /* [in] */ IComplex* y,
    /* [out] */ IComplex** complex)
{
    VALIDATE_NOT_NULL(complex)
    *complex = NULL;
    FAIL_RETURN(CheckArity(2))
    AutoPtr<CComplex> xObj = (CComplex*)x;
    AutoPtr<CComplex> yObj = (CComplex*)y;
    Double result = Elastos::Core::Math::DOUBLE_NAN;
    if (xObj->mIm == 0 && yObj->mIm == 0) {
        Eval(xObj->mRe, yObj->mRe, &result);
    }
    return CComplex::New(result, 0, complex);
}

ECode Function::Eval(
    /* [in] */ ArrayOf<IComplex*>* args,
    /* [out] */ IComplex** complex)
{
    VALIDATE_NOT_NULL(complex)
    *complex = NULL;
    switch (args->GetLength()) {
        case 0:
            return EvalComplex(complex);
        case 1:
            return Eval((*args)[0], complex);
        case 2:
            return Eval((*args)[0], (*args)[1], complex);
        default: {
            Int32 len = args->GetLength();
            FAIL_RETURN(CheckArity(len))
            AutoPtr<ArrayOf<Double> > reArgs = ArrayOf<Double>::Alloc(len);
            for (Int32 i = args->GetLength() - 1; i >= 0; --i) {
                AutoPtr<CComplex> obj = (CComplex*)(*args)[i];
                if (obj->mIm != 0) {
                    return CComplex::New(Elastos::Core::Math::DOUBLE_NAN, 0, complex);
                }
                (*reArgs)[i] = obj->mRe;
            }
            Double result;
            Eval(reArgs, &result);
            return CComplex::New(result, 0, complex);
        }
    }
}

ECode Function::CheckArity(
    /* [in] */ Int32 nArgs)
{
    Int32 result;
    if (Arity(&result), result != nArgs) {
        Slogger::E("Function", "Expected %d arguments, got %d", result, nArgs);
        return E_ARITY_EXCEPTION;
    }
    return NOERROR;
}

} // namespace Arity
} // namespace Javia
} // namespace Org